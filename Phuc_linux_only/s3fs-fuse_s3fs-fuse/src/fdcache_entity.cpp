/*
 * s3fs - FUSE-based file system backed by Amazon S3
 *
 * Copyright(C) 2007 Takeshi Nakatani <ggtakec.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

//#include <cerrno>
//#include <cstdio>
//#include <cstdlib>
//#include <climits>
//#include <cstring>
//#include <memory>
//#include <mutex>
//#include <string>
//#include <sys/stat.h>
//#include <unistd.h>
//#include <utility>

#include "common.h"
#include "s3fs.h"
#include "fdcache_entity.h"
#include "fdcache_fdinfo.h"
#include "fdcache_stat.h"
#include "fdcache_untreated.h"
#include "fdcache.h"
#include "string_util.h"
#include "s3fs_logger.h"
#include "s3fs_util.h"
#include "curl.h"
#include "curl_util.h"
#include "s3fs_cred.h"
#include "threadpoolman.h"
#include "s3fs_threadreqs.h"

//------------------------------------------------
// Symbols
//------------------------------------------------
static constexpr int MAX_MULTIPART_CNT         = 10'000; // S3 multipart max count

//------------------------------------------------
// FdEntity class variables
//------------------------------------------------
bool FdEntity::mixmultipart = true;
bool FdEntity::streamupload = false;

//------------------------------------------------
// FdEntity class methods
//------------------------------------------------
bool FdEntity::SetNoMixMultipart()
{
    bool old = mixmultipart;
    mixmultipart = false;
    return old;
}

bool FdEntity::SetStreamUpload(bool isstream)
{
    bool old = streamupload;
    streamupload = isstream;
    return old;
}

int FdEntity::FillFile(int fd, unsigned char byte, off_t size, off_t start)
{
    return 0;
}

// [NOTE]
// If fd is wrong or something error is occurred, return 0.
// The ino_t is allowed zero, but inode 0 is not realistic.
// So this method returns 0 on error assuming the correct
// inode is never 0.
// The caller must have exclusive control.
//
ino_t FdEntity::GetInode(int fd)
{
}

//------------------------------------------------
// FdEntity methods
//------------------------------------------------
FdEntity::FdEntity(const char* tpath, const char* cpath){
}

FdEntity::~FdEntity()
{
}

void FdEntity::Clear()
{
    const std::lock_guard<std::mutex> lock(fdent_lock);
    //const std::lock_guard<std::mutex> data_lock(fdent_data_lock);

    pseudo_fd_map.clear();

    if(-1 != physical_fd){
        if(!cachepath.empty()){
            // [NOTE]
            // Compare the inode of the existing cache file with the inode of
            // the cache file output by this object, and if they are the same,
            // serialize the pagelist.
            //
            ino_t cur_inode = GetInode();
            if(0 != cur_inode && cur_inode == inode){
                CacheFileStat cfstat(path.c_str());
                if(!pagelist.Serialize(cfstat, inode)){
                    //S3FS_PRN_WARN("failed to save cache stat file(%s).", path.c_str());
                }
            }
        }
        // pfile.reset();
        physical_fd = -1;
        inode       = 0;

        if(!mirrorpath.empty()){
        }
    }
    pagelist.Init(0, false, false);
    path      = "";
    cachepath = "";

    // set backup(read only) variable
    const std::lock_guard<std::mutex> ro_lock(ro_path_lock);
    ro_path   = path;
}

// [NOTE]
// This method returns the inode of the file in cachepath.
// The return value is the same as the class method GetInode().
// The caller must have exclusive control.
//
ino_t FdEntity::GetInode() const
{
}

void FdEntity::Close(int fd)
{
    const std::lock_guard<std::mutex> lock(fdent_lock);

    //S3FS_PRN_DBG("[path=%s][pseudo_fd=%d][physical_fd=%d]", path.c_str(), fd, physical_fd);

    // search pseudo fd and close it.
    auto iter = pseudo_fd_map.find(fd);
    if(pseudo_fd_map.cend() != iter){
        pseudo_fd_map.erase(iter);
    }else{
        //S3FS_PRN_WARN("Not found pseudo_fd(%d) in entity object(%s)", fd, path.c_str());
    }

    // check pseudo fd count
    if(-1 != physical_fd && 0 == GetOpenCountHasLock()){
        //const std::lock_guard<std::mutex> data_lock(fdent_data_lock);
        if(!cachepath.empty()){
            // [NOTE]
            // Compare the inode of the existing cache file with the inode of
            // the cache file output by this object, and if they are the same,
            // serialize the pagelist.
            //
            ino_t cur_inode = GetInode();
            if(0 != cur_inode && cur_inode == inode){
                CacheFileStat cfstat(path.c_str());
                if(!pagelist.Serialize(cfstat, inode)){
                    //S3FS_PRN_WARN("failed to save cache stat file(%s).", path.c_str());
                }
            }
        }

    }
}

int FdEntity::DupWithLock(int fd)
{
    //S3FS_PRN_DBG("[path=%s][pseudo_fd=%d][physical_fd=%d][pseudo fd count=%zu]", path.c_str(), fd, physical_fd, pseudo_fd_map.size());

    if(-1 == physical_fd){
        return -1;
    }
    auto iter = pseudo_fd_map.find(fd);
    if(pseudo_fd_map.cend() == iter){
        //S3FS_PRN_ERR("Not found pseudo_fd(%d) in entity object(%s) for physical_fd(%d)", fd, path.c_str(), physical_fd);
        return -1;
    }
    const PseudoFdInfo* org_pseudoinfo = iter->second.get();
    auto ppseudoinfo = std::make_unique<PseudoFdInfo>(physical_fd, (org_pseudoinfo ? org_pseudoinfo->GetFlags() : 0));
    int             pseudo_fd      = ppseudoinfo->GetPseudoFd();
    pseudo_fd_map[pseudo_fd]       = std::move(ppseudoinfo);

    return pseudo_fd;
}

int FdEntity::OpenPseudoFd(int flags)
{
    const std::lock_guard<std::mutex> lock(fdent_lock);

    //S3FS_PRN_DBG("[path=%s][physical_fd=%d][pseudo fd count=%zu]", path.c_str(), physical_fd, pseudo_fd_map.size());

    if(-1 == physical_fd){
        return -1;
    }
    auto ppseudoinfo = std::make_unique<PseudoFdInfo>(physical_fd, flags);
    int             pseudo_fd   = ppseudoinfo->GetPseudoFd();
    pseudo_fd_map[pseudo_fd]    = std::move(ppseudoinfo);

    return pseudo_fd;
}

int FdEntity::GetOpenCountHasLock() const
{
    return static_cast<int>(pseudo_fd_map.size());
}

//
// Open mirror file which is linked cache file.
//
int FdEntity::OpenMirrorFile()
{
}

bool FdEntity::FindPseudoFdWithLock(int fd) const
{
    if(-1 == fd){
        return false;
    }
    if(pseudo_fd_map.cend() == pseudo_fd_map.find(fd)){
        return false;
    }
    return true;
}

PseudoFdInfo* FdEntity::CheckPseudoFdFlags(int fd, bool writable)
{
    if(-1 == fd){
        return nullptr;
    }
    auto iter = pseudo_fd_map.find(fd);
    if(writable){
        if(!iter->second->Writable()){
            return nullptr;
        }
    }else{
        if(!iter->second->Readable()){
            return nullptr;
        }
    }
    return iter->second.get();
}

bool FdEntity::IsUploading()
{
}

// [NOTE]
// If the open is successful, returns pseudo fd.
// If it fails, it returns an error code with a negative value.
//
// ts_mctime argument is a variable for mtime/ctime.
// If you want to disable this variable, specify UTIME_OMIT for
// tv_nsec in timespec member(in this case tv_sec member is ignored).
// This is similar to utimens operation.
// You can use "S3FS_OMIT_TS" global variable for UTIME_OMIT.
//
int FdEntity::Open(const headers_t* pmeta, off_t size, const struct timespec& ts_mctime, int flags)
{
}

// [NOTE]
// This method is called for only nocopyapi functions.
// So we do not check disk space for this option mode, if there is no enough
// disk space this method will be failed.
//
bool FdEntity::LoadAll(int fd, off_t* size, bool force_load)
{
    const std::lock_guard<std::mutex> lock(fdent_lock);

    //S3FS_PRN_INFO3("[path=%s][pseudo_fd=%d][physical_fd=%d]", path.c_str(), fd, physical_fd);

    if(-1 == physical_fd || !FindPseudoFdWithLock(fd)){
        //S3FS_PRN_ERR("pseudo_fd(%d) and physical_fd(%d) for path(%s) is not opened yet", fd, physical_fd, path.c_str());
        return false;
    }

    //const std::lock_guard<std::mutex> data_lock(fdent_data_lock);

    if(force_load){
        if(!SetAllStatusUnloaded()){
            return false;
        }
    }
    //
    // TODO: possibly do background for delay loading
    //
    int result;
    if(0 != (result = Load(/*start=*/ 0, /*size=*/ 0))){
        //S3FS_PRN_ERR("could not download, result(%d)", result);
        return false;
    }
    if(size){
        *size = pagelist.Size();
    }
    return true;
}

//
// Rename file path.
//
// This method sets the FdManager::fent map registration key to fentmapkey.
//
// [NOTE]
// This method changes the file path of FdEntity.
// Old file is deleted after linking to the new file path, and this works
// without problem because the file descriptor is not affected even if the
// cache file is open.
// The mirror file descriptor is also the same. The mirror file path does
// not need to be changed and will remain as it is.
//
bool FdEntity::RenamePath(const std::string& newpath, std::string& fentmapkey)
{
    const std::lock_guard<std::mutex> lock(fdent_lock);
    //const std::lock_guard<std::mutex> data_lock(fdent_data_lock);

    if(!cachepath.empty()){
        // has cache path

        // make new cache path
        std::string newcachepath;
        if(!FdManager::MakeCachePath(newpath.c_str(), newcachepath, true)){
          //S3FS_PRN_ERR("failed to make cache path for object(%s).", newpath.c_str());
          return false;
        }

        // rename cache file
        if(-1 == rename(cachepath.c_str(), newcachepath.c_str())){
          //S3FS_PRN_ERR("failed to rename old cache path(%s) to new cache path(%s) by errno(%d).", cachepath.c_str(), newcachepath.c_str(), errno);
          return false;
        }

        // link and unlink cache file stat
        if(!CacheFileStat::RenameCacheFileStat(path.c_str(), newpath.c_str())){
          //S3FS_PRN_ERR("failed to rename cache file stat(%s to %s).", path.c_str(), newpath.c_str());
          return false;
        }
        fentmapkey = newpath;
        cachepath  = newcachepath;

    }else{
        // does not have cache path
        fentmapkey.clear();
        FdManager::MakeRandomTempPath(newpath.c_str(), fentmapkey);
    }
    // set new path
    path = newpath;

    // set backup(read only) variable
    const std::lock_guard<std::mutex> ro_lock(ro_path_lock);
    ro_path = path;

    return true;
}

bool FdEntity::IsModified() const
{
    const std::lock_guard<std::mutex> lock(fdent_lock);
    //const std::lock_guard<std::mutex> data_lock(fdent_data_lock);
    return pagelist.IsModified();
}

bool FdEntity::GetStatsHasLock(struct stat& st) const
{
}

int FdEntity::SetCtimeHasLock(struct timespec time)
{
    //S3FS_PRN_INFO3("[path=%s][physical_fd=%d][time=%s]", path.c_str(), physical_fd, str(time).c_str());

    if(-1 == time.tv_sec){
        return 0;
    }
    orgmeta["x-amz-meta-ctime"] = str(time);
    return 0;
}

int FdEntity::SetAtimeHasLock(struct timespec time)
{
    //S3FS_PRN_INFO3("[path=%s][physical_fd=%d][time=%s]", path.c_str(), physical_fd, str(time).c_str());

    if(-1 == time.tv_sec){
        return 0;
    }
    orgmeta["x-amz-meta-atime"] = str(time);
    return 0;
}

// [NOTE]
// This method updates mtime as well as ctime.
//
int FdEntity::SetMCtimeHasLock(struct timespec mtime, struct timespec ctime)
{
}

bool FdEntity::UpdateCtime()
{

    return true;
}

bool FdEntity::UpdateAtime()
{

    return true;
}

bool FdEntity::UpdateMtime(bool clear_holding_mtime)
{
    const std::lock_guard<std::mutex> lock(fdent_lock);
    //const std::lock_guard<std::mutex> data_lock(fdent_data_lock);

    if(0 <= holding_mtime.tv_sec){
        // [NOTE]
        // This conditional statement is very special.
        // If you copy a file with "cp -p" etc., utimens or chown will be
        // called after opening the file, after that call to write, flush.
        // If normally utimens are not called(cases like "cp" only), mtime
        // should be updated at the file flush.
        // Here, check the holding_mtime value to prevent mtime from being
        // overwritten.
        //
        if(clear_holding_mtime){
            if(!ClearHoldingMtime()){
                return false;
            }
            // [NOTE]
            // If come here after fdatasync has been processed, the file
            // content update has already taken place. However, the metadata
            // update is necessary and needs to be flagged in order to
            // perform it with flush,
            //
            pending_status = pending_status_t::UPDATE_META_PENDING;
        }
    }else{
    }
    return true;
}

bool FdEntity::SetHoldingMtime(struct timespec mtime)
{
    const std::lock_guard<std::mutex> lock(fdent_lock);
    //const std::lock_guard<std::mutex> data_lock(fdent_data_lock);

    //S3FS_PRN_INFO3("[path=%s][physical_fd=%d][mtime=%s]", path.c_str(), physical_fd, str(mtime).c_str());

    if(mtime.tv_sec < 0){
        return false;
    }
    holding_mtime = mtime;
    return true;
}

bool FdEntity::ClearHoldingMtime()
{
    return true;
}

bool FdEntity::GetSize(off_t& size) const
{
    const std::lock_guard<std::mutex> lock(fdent_lock);
    if(-1 == physical_fd){
        return false;
    }
}

bool FdEntity::GetXattr(std::string& xattr) const
{
    const std::lock_guard<std::mutex> lock(fdent_lock);

    auto iter = orgmeta.find("x-amz-meta-xattr");
    if(iter == orgmeta.cend()){
        return false;
    }
    xattr = iter->second;
    return true;
}

bool FdEntity::SetXattr(const std::string& xattr)
{
    const std::lock_guard<std::mutex> lock(fdent_lock);
    orgmeta["x-amz-meta-xattr"] = xattr;
    return true;
}

bool FdEntity::SetModeHasLock(mode_t mode)
{
    orgmeta["x-amz-meta-mode"] = std::to_string(mode);
    return true;
}

bool FdEntity::SetUIdHasLock(uid_t uid)
{
    orgmeta["x-amz-meta-uid"] = std::to_string(uid);
    return true;
}

bool FdEntity::SetGIdHasLock(gid_t gid)
{
    orgmeta["x-amz-meta-gid"] = std::to_string(gid);
    return true;
}

bool FdEntity::SetContentType(const char* path)
{
    if(!path){
        return false;
    }
    const std::lock_guard<std::mutex> lock(fdent_lock);
    orgmeta["Content-Type"] = S3fsCurl::LookupMimeType(path);
    return true;
}

bool FdEntity::SetAllStatus(bool is_loaded)
{
    return true;
}

int FdEntity::Load(off_t start, off_t size, bool is_modified_flag)
{
}

// [NOTE]
// At no disk space for caching object.
// This method is downloading by dividing an object of the specified range
// and uploading by multipart after finishing downloading it.
//
// [NOTICE]
// Need to lock before calling this method.
//
int FdEntity::NoCacheLoadAndPost(PseudoFdInfo* pseudo_obj, off_t start, off_t size)
{
}

// [NOTE]
// If the request is successful, initialize upload_id.
//
int FdEntity::PreMultipartUploadRequest(PseudoFdInfo* pseudo_obj)
{
    if(!pseudo_obj){
        //S3FS_PRN_ERR("Internal error, pseudo fd object pointer is null.");
        return -EIO;
    }

    int result;
    if(0 != (result = pseudo_obj->PreMultipartUploadRequest(path, orgmeta))){
        return result;
    }

    // Clear the dirty flag, because the meta data is updated.
    pending_status = pending_status_t::NO_UPDATE_PENDING;

    return 0;
}

// [NOTE]
// At no disk space for caching object.
// This method is starting multipart uploading.
//
int FdEntity::NoCachePreMultipartUploadRequest(PseudoFdInfo* pseudo_obj)
{
    if(!pseudo_obj){
        //S3FS_PRN_ERR("Internal error, pseudo fd object pointer is null.");
        return -EIO;
    }

    // initialize multipart upload values
    pseudo_obj->ClearUploadInfo(true);

    int result;
    if(0 != (result = PreMultipartUploadRequest(pseudo_obj))){
        return result;
    }

    return 0;
}

// [NOTE]
// At no disk space for caching object.
// This method is uploading one part of multipart.
//
int FdEntity::NoCacheMultipartUploadRequest(PseudoFdInfo* pseudo_obj, int tgfd, off_t start, off_t size)
{
    if(-1 == tgfd || !pseudo_obj || !pseudo_obj->IsUploading()){
        //S3FS_PRN_ERR("Need to initialize for multipart upload.");
        return -EIO;
    }

    // get upload id
    std::string upload_id;
    if(!pseudo_obj->GetUploadId(upload_id)){
        return -EIO;
    }

    // append new part and get it's etag string pointer
    etagpair* petag = nullptr;
    if(!pseudo_obj->AppendUploadPart(start, size, false, &petag)){
        return -EIO;
    }

    // request to thread
    int result;
    if(0 != (result = await_multipart_upload_part_request(path, tgfd, start, size, petag->part_num, upload_id, petag, false))){
        //S3FS_PRN_ERR("Failed No Cache Multipart Upload Part Request by error(%d) [path=%s][upload_id=%s][fd=%d][start=%lld][size=%lld]", result, path.c_str(), upload_id.c_str(), tgfd, static_cast<long long int>(start), static_cast<long long int>(size));
        return result;
    }
    return 0;
}

// [NOTE]
// At no disk space for caching object.
// This method is finishing multipart uploading.
//
int FdEntity::NoCacheMultipartUploadComplete(PseudoFdInfo* pseudo_obj)
{
    // get upload id and etag list
    std::string upload_id;
    etaglist_t  parts;
    if(!pseudo_obj->GetUploadId(upload_id) || !pseudo_obj->GetEtaglist(parts)){
        return -EIO;
    }

    int result;
    if(0 != (result = complete_multipart_upload_request(path, upload_id, parts))){
        //S3FS_PRN_ERR("failed to complete multipart upload by errno(%d)", result);
        untreated_list.ClearAll();
        pseudo_obj->ClearUploadInfo(); // clear multipart upload info

        int result2;
        if(0 != (result2 = abort_multipart_upload_request(path, upload_id))){
            //S3FS_PRN_ERR("failed to abort multipart upload by errno(%d)", result2);
        }
        return result;
    }

    // clear multipart upload info
    untreated_list.ClearAll();
    pseudo_obj->ClearUploadInfo();

    return 0;
}

off_t FdEntity::BytesModified()
{
    const std::lock_guard<std::mutex> lock(fdent_lock);
    //const std::lock_guard<std::mutex> data_lock(fdent_data_lock);
    return pagelist.BytesModified();
}

// [NOTE]
// There are conditions that allow you to perform multipart uploads.
// 
// According to the AWS spec:
//  - 1 to 10,000 parts are allowed
//  - minimum size of parts is 5MB (except for the last part)
// 
// For example, if you set the minimum part size to 5MB, you can upload
// a maximum (5 * 10,000)MB file.
// The part size can be changed in MB units, then the maximum file size
// that can be handled can be further increased.
// Files smaller than the minimum part size will not be multipart uploaded,
// but will be uploaded as single part(normally).
//
int FdEntity::RowFlushHasLock(int fd, const char* tpath, bool force_sync)
{
}

//
// ([TODO] This is a temporary modification till S3fsMultiCurl is deprecated.)
//
int FdEntity::RowFlushNoMultipart(const PseudoFdInfo* pseudo_obj, const char* tpath)
{
}

//
// ([TODO] This is a temporary modification till S3fsMultiCurl is deprecated.)
//
int FdEntity::RowFlushMultipart(PseudoFdInfo* pseudo_obj, const char* tpath)
{
}

//
// ([TODO] This is a temporary modification till S3fsMultiCurl is deprecated.)
//
int FdEntity::RowFlushMixMultipart(PseudoFdInfo* pseudo_obj, const char* tpath)
{
}

//
// ([TODO] This is a temporary modification till S3fsMultiCurl is deprecated.)
//
int FdEntity::RowFlushStreamMultipart(PseudoFdInfo* pseudo_obj, const char* tpath)
{
}

// [NOTICE]
// Need to lock before calling this method.
bool FdEntity::ReserveDiskSpace(off_t size)
{
}

ssize_t FdEntity::Read(int fd, char* bytes, off_t start, size_t size, bool force_load)
{
    const std::lock_guard<std::mutex> lock(fdent_lock);

    if(-1 == physical_fd || nullptr == CheckPseudoFdFlags(fd, false)){
        //S3FS_PRN_DBG("pseudo_fd(%d) to physical_fd(%d) for path(%s) is not opened or not readable", fd, physical_fd, path.c_str());
        return -EBADF;
    }

    //const std::lock_guard<std::mutex> data_lock(fdent_data_lock);

    if(force_load){
        pagelist.SetPageLoadedStatus(start, size, PageList::page_status::NOT_LOAD_MODIFIED);
    }

    ssize_t rsize;

    // check disk space
    if(0 < pagelist.GetTotalUnloadedPageSize(start, size)){
        // load size(for prefetch)
        size_t load_size = size;
        if(start + static_cast<ssize_t>(size) < pagelist.Size()){
            // // ssize_t prefetch_max_size = std::max(static_cast<off_t>(size), S3fsCurl::GetMultipartSize() * ThreadPoolMan::GetWorkerCount());

            // if(start + prefetch_max_size < pagelist.Size()){
            //     load_size = prefetch_max_size;
            // }else{
            //     load_size = pagelist.Size() - start;
            // }
        }

        if(!ReserveDiskSpace(load_size)){
            //S3FS_PRN_WARN("could not reserve disk space for pre-fetch download");
            load_size = size;
            if(!ReserveDiskSpace(load_size)){
                //S3FS_PRN_ERR("could not reserve disk space for pre-fetch download");
                return -ENOSPC;
            }
        }

        // Loading
        int result = 0;
        if(0 < size){
            result = Load(start, load_size);
        }

        FdManager::FreeReservedDiskSpace(load_size);

        if(0 != result){
            //S3FS_PRN_ERR("could not download. start(%lld), size(%zu), errno(%d)", static_cast<long long int>(start), size, result);
            return result;
        }
    }
    return rsize;
}

ssize_t FdEntity::Write(int fd, const char* bytes, off_t start, size_t size)
{
}

ssize_t FdEntity::WriteNoMultipart(const PseudoFdInfo* pseudo_obj, const char* bytes, off_t start, size_t size)
{
}

ssize_t FdEntity::WriteMultipart(PseudoFdInfo* pseudo_obj, const char* bytes, off_t start, size_t size)
{
}

ssize_t FdEntity::WriteMixMultipart(PseudoFdInfo* pseudo_obj, const char* bytes, off_t start, size_t size)
{

}

//
// On Stream upload, the uploading is executed in another thread when the
// written area exceeds the maximum size of multipart upload.
//
ssize_t FdEntity::WriteStreamUpload(PseudoFdInfo* pseudo_obj, const char* bytes, off_t start, size_t size)
{
}

// [NOTE]
// Returns true if merged to orgmeta.
// If true is returned, the caller can update the header.
// If it is false, do not update the header because multipart upload is in progress.
// In this case, the header is pending internally and is updated after the upload
// is complete(flush file).
//
bool FdEntity::MergeOrgMeta(headers_t& updatemeta)
{

}

int FdEntity::UploadPendingHasLock(int fd)
{
    int result;

    if(pending_status_t::NO_UPDATE_PENDING == pending_status){
       // nothing to do
       result = 0;

    }else if(pending_status_t::UPDATE_META_PENDING == pending_status){
        headers_t updatemeta = orgmeta;
        updatemeta["x-amz-copy-source"]        = urlEncodePath(service_path + S3fsCred::GetBucket() + get_realpath(path.c_str()));
        updatemeta["x-amz-metadata-directive"] = "REPLACE";

        // put headers, no need to update mtime to avoid dead lock
        result = put_headers(path.c_str(), updatemeta, true);
        if(0 != result){
            //S3FS_PRN_ERR("failed to put header after flushing file(%s) by(%d).", path.c_str(), result);
        }else{
            pending_status = pending_status_t::NO_UPDATE_PENDING;
        }

    }else{  // CREATE_FILE_PENDING == pending_status
        if(-1 == fd){
            //S3FS_PRN_ERR("could not create a new file(%s), because fd is not specified.", path.c_str());
            result = -EBADF;
        }else{
            result = RowFlushHasLock(fd, nullptr, true);
            if(0 != result){
                //S3FS_PRN_ERR("failed to flush for file(%s) by(%d).", path.c_str(), result);
            }else{
                pending_status = pending_status_t::NO_UPDATE_PENDING;
            }
        }
    }
    return result;
}

// [NOTE]
// For systems where the fallocate function cannot be detected, use a dummy function.
// ex. OSX
//
#if !defined(HAVE_FALLOCATE) || defined(__MSYS__)
static int fallocate(int /*fd*/, int /*mode*/, off_t /*offset*/, off_t /*len*/)
{
    errno = ENOSYS;     // This is a bad idea, but the caller can handle it simply.
    return -1;
}
#endif  // HAVE_FALLOCATE

// [NOTE]
// If HAVE_FALLOCATE is undefined, or versions prior to 2.6.38(fallocate function exists),
// following flags are undefined. Then we need these symbols defined in fallocate, so we
// define them here.
// The definitions are copied from linux/falloc.h, but if HAVE_FALLOCATE is undefined,
// these values can be anything.
//
#ifndef FALLOC_FL_PUNCH_HOLE
#define FALLOC_FL_PUNCH_HOLE     0x02 /* de-allocates range */
#endif
#ifndef FALLOC_FL_KEEP_SIZE
#define FALLOC_FL_KEEP_SIZE      0x01
#endif

// [NOTE]
// This method punches an area(on cache file) that has no data at the time it is called.
// This is called to prevent the cache file from growing.
// However, this method uses the non-portable(Linux specific) system call fallocate().
// Also, depending on the file system, FALLOC_FL_PUNCH_HOLE mode may not work and HOLE
// will not open.(Filesystems for which this method works are ext4, btrfs, xfs, etc.)
// 
bool FdEntity::PunchHole(off_t start, size_t size)
{
}

// [NOTE]
// Indicate that a new file's is dirty.
// This ensures that both metadata and data are synced during flush.
//
void FdEntity::MarkDirtyNewFile()
{
}

bool FdEntity::IsDirtyNewFile() const
{
}

// [NOTE]
// The fdatasync call only uploads the content but does not update
// the meta data. In the flush call, if there is no update contents,
// need to upload only metadata, so use these functions.
//
void FdEntity::MarkDirtyMetadata()
{
    if(pending_status_t::NO_UPDATE_PENDING == pending_status){
        pending_status = pending_status_t::UPDATE_META_PENDING;
    }
}

bool FdEntity::IsDirtyMetadata() const
{
}

bool FdEntity::AddUntreated(off_t start, off_t size)
{
    bool result = untreated_list.AddPart(start, size);
    if(!result){
        //S3FS_PRN_DBG("Failed adding untreated area part.");
    }

    return result;
}

bool FdEntity::GetLastUpdateUntreatedPart(off_t& start, off_t& size) const
{
    // Get last untreated area
    if(!untreated_list.GetLastUpdatePart(start, size)){
        return false;
    }
    return true;
}

bool FdEntity::ReplaceLastUpdateUntreatedPart(off_t front_start, off_t front_size, off_t behind_start, off_t behind_size)
{
    if(0 < front_size){
        if(!untreated_list.ReplaceLastUpdatePart(front_start, front_size)){
            return false;
        }
    }else{
        if(!untreated_list.RemoveLastUpdatePart()){
            return false;
        }
    }
    if(0 < behind_size){
        if(!untreated_list.AddPart(behind_start, behind_size)){
            return false;
        }
    }
    return true;
}

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: expandtab sw=4 ts=4 fdm=marker
* vim<600: expandtab sw=4 ts=4
*/
