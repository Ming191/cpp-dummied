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

//#include <algorithm>
//#include <cerrno>
//#include <cstdio>
//#include <cstdlib>
//#include <memory>
//#include <mutex>
//#include <string>
//#include <sys/stat.h>
//#include <unistd.h>

#include "common.h"
#include "s3fs.h"
#include "s3fs_logger.h"
#include "s3fs_util.h"
#include "fdcache_fdinfo.h"
#include "fdcache_pseudofd.h"
#include "fdcache_entity.h"
#include "curl.h"
#include "string_util.h"
#include "threadpoolman.h"
#include "s3fs_threadreqs.h"

//------------------------------------------------
// PseudoFdInfo methods
//------------------------------------------------
PseudoFdInfo::PseudoFdInfo(int fd, int open_flags) : pseudo_fd(-1), physical_fd(fd), flags(0), upload_fd(-1), instruct_count(0), last_result(0), uploaded_sem(0)
{
    if(-1 != physical_fd){
        pseudo_fd = PseudoFdManager::Get();
        flags     = open_flags;
    }
}

PseudoFdInfo::~PseudoFdInfo()
{
    Clear();        // call before destroying the mutex
}

bool PseudoFdInfo::Clear()
{
    // cppcheck-suppress unmatchedSuppression
    // cppcheck-suppress knownConditionTrueFalse
    if(!CancelAllThreads()){
        return false;
    }
    {
        const std::lock_guard<std::mutex> lock(upload_list_lock);
        // cppcheck-suppress unmatchedSuppression
        // cppcheck-suppress knownConditionTrueFalse
        if(!ResetUploadInfo()){
            return false;
        }
    }
    CloseUploadFd();

    if(-1 != pseudo_fd){
        PseudoFdManager::Release(pseudo_fd);
    }
    pseudo_fd   = -1;
    physical_fd = -1;

    return true;
}

bool PseudoFdInfo::IsUploadingHasLock() const
{
    return !upload_id.empty();
}

bool PseudoFdInfo::IsUploading() const
{
    const std::lock_guard<std::mutex> lock(upload_list_lock);
    return IsUploadingHasLock();
}

void PseudoFdInfo::CloseUploadFd()
{
    const std::lock_guard<std::mutex> lock(upload_list_lock);

    if(-1 != upload_fd){
    }
}

bool PseudoFdInfo::OpenUploadFd()
{
}

bool PseudoFdInfo::Set(int fd, int open_flags)
{
    if(-1 == fd){
        return false;
    }
    Clear();
    physical_fd = fd;
    pseudo_fd   = PseudoFdManager::Get();
    flags       = open_flags;

    return true;
}

bool PseudoFdInfo::Writable() const
{
    if(-1 == pseudo_fd){
        return false;
    }
    if(0 == (flags & (O_WRONLY | O_RDWR))){
        return false;
    }
    return true;
}

bool PseudoFdInfo::Readable() const
{
    if(-1 == pseudo_fd){
        return false;
    }
    // O_RDONLY is 0x00, it means any pattern is readable.
    return true;
}

bool PseudoFdInfo::ClearUploadInfo(bool is_cancel_mp)
{
    if(is_cancel_mp){
        // cppcheck-suppress unmatchedSuppression
        // cppcheck-suppress knownConditionTrueFalse
        if(!CancelAllThreads()){
            return false;
        }
    }

    const std::lock_guard<std::mutex> lock(upload_list_lock);
    return ResetUploadInfo();
}

bool PseudoFdInfo::ResetUploadInfo()
{
    upload_id.clear();
    upload_list.clear();
    instruct_count  = 0;
    last_result     = 0;

    return true;
}

bool PseudoFdInfo::RowInitialUploadInfo(const std::string& id, bool is_cancel_mp)
{
    if(is_cancel_mp){
        // cppcheck-suppress unmatchedSuppression
        // cppcheck-suppress knownConditionTrueFalse
        if(!ClearUploadInfo(is_cancel_mp)){
            return false;
        }
    }else{
        const std::lock_guard<std::mutex> lock(upload_list_lock);
        // cppcheck-suppress unmatchedSuppression
        // cppcheck-suppress knownConditionTrueFalse
        if(!ResetUploadInfo()){
            return false;
        }
    }

    const std::lock_guard<std::mutex> lock(upload_list_lock);
    upload_id = id;
    return true;
}

void PseudoFdInfo::IncreaseInstructionCount()
{
    const std::lock_guard<std::mutex> lock(upload_list_lock);
    ++instruct_count;
}

bool PseudoFdInfo::GetUploadInfo(std::string& id, int& fd) const
{
    const std::lock_guard<std::mutex> lock(upload_list_lock);

    if(!IsUploadingHasLock()){
        //S3FS_PRN_ERR("Multipart Upload has not started yet.");
        return false;
    }
    id = upload_id;
    fd = upload_fd;
    return true;
}

bool PseudoFdInfo::GetUploadId(std::string& id) const
{
    int fd = -1;
    return GetUploadInfo(id, fd);
}

bool PseudoFdInfo::GetEtaglist(etaglist_t& list) const
{
    const std::lock_guard<std::mutex> lock(upload_list_lock);

    if(!IsUploadingHasLock()){
        //S3FS_PRN_ERR("Multipart Upload has not started yet.");
        return false;
    }

}

// [NOTE]
// This method adds a part for a multipart upload.
// The added new part must be an area that is exactly continuous with the
// immediately preceding part.
// An error will occur if it is discontinuous or if it overlaps with an
// existing area.
//
bool PseudoFdInfo::AppendUploadPart(off_t start, off_t size, bool is_copy, etagpair** ppetag)
{
    const std::lock_guard<std::mutex> lock(upload_list_lock);

    if(!IsUploadingHasLock()){
        //S3FS_PRN_ERR("Multipart Upload has not started yet.");
        return false;
    }

    off_t    next_start_pos = 0;
    if(!upload_list.empty()){
        next_start_pos = upload_list.back().startpos + upload_list.back().size;
    }
    if(start != next_start_pos){
        //S3FS_PRN_ERR("The expected starting position for the next part is %lld, but %lld was specified.", static_cast<long long int>(next_start_pos), static_cast<long long int>(start));
        return false;
    }

    // make part number
    int partnumber = static_cast<int>(upload_list.size()) + 1;

    // add new part
    etagpair*   petag_entity = etag_entities.add(etagpair(nullptr, partnumber));              // [NOTE] Create the etag entity and register it in the list.
    upload_list.emplace_back(false, physical_fd, start, size, is_copy, petag_entity);

    // set etag pointer
    if(ppetag){
        *ppetag = petag_entity;
    }

    return true;
}

//
// Utility for sorting upload list
//
static bool filepart_partnum_compare(const filepart& src1, const filepart& src2)
{
}

bool PseudoFdInfo::InsertUploadPart(off_t start, off_t size, int part_num, bool is_copy, etagpair** ppetag)
{   ////S3FS_PRN_DBG("[start=%lld][size=%lld][part_num=%d][is_copy=%s]", static_cast<long long int>(start), static_cast<long long int>(size), part_num, (is_copy ? "true" : "false"));

    if(!IsUploadingHasLock()){
        //S3FS_PRN_ERR("Multipart Upload has not started yet.");
        return false;
    }
    if(start < 0 || size <= 0 || part_num < 0 || !ppetag){
        //S3FS_PRN_ERR("Parameters are wrong.");
        return false;
    }

    return true;
}

bool PseudoFdInfo::ParallelMultipartUpload(const char* path, const mp_part_list_t& mplist, bool is_copy)
{
    ////S3FS_PRN_DBG("[path=%s][mplist(%zu)]", SAFESTRPTR(path), mplist.size());

    if(mplist.empty()){
        // nothing to do
        return true;
    }
    if(!OpenUploadFd()){
        return false;
    }

    // Get upload id/fd before loop
    std::string tmp_upload_id;
    int         tmp_upload_fd = -1;
    if(!GetUploadInfo(tmp_upload_id, tmp_upload_fd)){
        return false;
    }

    std::string strpath = SAFESTRPTR(path);

    return true;
}

bool PseudoFdInfo::ParallelMultipartUploadAll(const char* path, const mp_part_list_t& to_upload_list, const mp_part_list_t& copy_list, int& result)
{
    //S3FS_PRN_DBG("[path=%s][to_upload_list(%zu)][copy_list(%zu)]", SAFESTRPTR(path), to_upload_list.size(), copy_list.size());

    result = 0;

    if(!OpenUploadFd()){
        return false;
    }
    if(!ParallelMultipartUpload(path, to_upload_list, false) || !ParallelMultipartUpload(path, copy_list, true)){
        //S3FS_PRN_ERR("Failed setup instruction for uploading(path=%s, to_upload_list=%zu, copy_list=%zu).", SAFESTRPTR(path), to_upload_list.size(), copy_list.size());
        return false;
    }

    // Wait for all thread exiting
    result = WaitAllThreadsExit();

    return true;
}

//
// Common method that calls S3fsCurl::PreMultipartUploadRequest via pre_multipart_upload_request
//
// [NOTE]
// If the request is successful, initialize upload_id.
//
int PseudoFdInfo::PreMultipartUploadRequest(const std::string& strpath, const headers_t& meta)
{
    // get upload_id
    std::string new_upload_id;
    int         result;
    if(0 != (result = pre_multipart_upload_request(strpath, meta, new_upload_id))){
        return result;
    }

    // reset upload_id
    if(!RowInitialUploadInfo(new_upload_id, false/* not need to cancel */)){
        //S3FS_PRN_ERR("failed to setup multipart upload(set upload id to object)");
        return -EIO;
    }
    //S3FS_PRN_DBG("succeed to setup multipart upload(set upload id to object)");

    return 0;
}

//
// Upload the last updated Untreated area
//
// [Overview]
// Uploads untreated areas with the maximum multipart upload size as the
// boundary.
//
// * The starting position of the untreated area is aligned with the maximum
//   multipart upload size as the boundary.
// * If there is an uploaded area that overlaps with the aligned untreated
//   area, that uploaded area is canceled and absorbed by the untreated area.
// * Upload only when the aligned untreated area exceeds the maximum multipart
//   upload size.
// * When the start position of the untreated area is changed to boundary
//   alignment(to backward), and if that gap area is remained, that area is
//   rest to untreated area.
//
ssize_t PseudoFdInfo::UploadBoundaryLastUntreatedArea(const char* path, headers_t& meta, FdEntity* pfdent)
{
    //S3FS_PRN_DBG("[path=%s][pseudo_fd=%d][physical_fd=%d]", SAFESTRPTR(path), pseudo_fd, physical_fd);

    if(!path || -1 == physical_fd || -1 == pseudo_fd || !pfdent){
        //S3FS_PRN_ERR("pseudo_fd(%d) to physical_fd(%d) for path(%s) is not opened or not writable, or pfdent is nullptr.", pseudo_fd, physical_fd, path);
        return -EBADF;
    }

    //
    // Get last update untreated area
    //
    off_t last_untreated_start = 0;
    off_t last_untreated_size  = 0;
    if(!pfdent->GetLastUpdateUntreatedPart(last_untreated_start, last_untreated_size) || last_untreated_start < 0 || last_untreated_size <= 0){
        //S3FS_PRN_WARN("Not found last update untreated area or it is empty, thus return without any error.");
        return 0;
    }

    //
    // Aligns the start position of the last updated raw area with the boundary
    //
    // * Align the last updated raw space with the maximum upload size boundary.
    // * The remaining size of the part before the boundary is will not be uploaded.
    //
    off_t max_mp_size     = S3fsCurl::GetMultipartSize();
    off_t aligned_start   = ((last_untreated_start / max_mp_size) + (0 < (last_untreated_start % max_mp_size) ? 1 : 0)) * max_mp_size;
    if((last_untreated_start + last_untreated_size) <= aligned_start){
        //S3FS_PRN_INFO("After the untreated area(start=%lld, size=%lld) is aligned with the boundary, the aligned start(%lld) exceeds the untreated area, so there is nothing to do.", static_cast<long long int>(last_untreated_start), static_cast<long long int>(last_untreated_size), static_cast<long long int>(aligned_start));
        return 0;
    }

    off_t aligned_size    = (((last_untreated_start + last_untreated_size) - aligned_start) / max_mp_size) * max_mp_size;
    if(0 == aligned_size){
        //S3FS_PRN_DBG("After the untreated area(start=%lld, size=%lld) is aligned with the boundary(start is %lld), the aligned size is empty, so nothing to do.", static_cast<long long int>(last_untreated_start), static_cast<long long int>(last_untreated_size), static_cast<long long int>(aligned_start));
        return 0;
    }

    off_t front_rem_start = last_untreated_start;                       // start of the remainder untreated area in front of the boundary
    off_t front_rem_size  = aligned_start - last_untreated_start;       // size of the remainder untreated area in front of the boundary

    //
    // Get the area for uploading, if last update treated area can be uploaded.
    //
    // [NOTE]
    // * Create the updoad area list, if the untreated area aligned with the boundary
    //   exceeds the maximum upload size.
    // * If it overlaps with an area that has already been uploaded(unloaded list),
    //   that area is added to the cancellation list and included in the untreated area.
    //
    mp_part_list_t  to_upload_list;
    filepart_list_t cancel_uploaded_list;
    if(!ExtractUploadPartsFromUntreatedArea(aligned_start, aligned_size, to_upload_list, cancel_uploaded_list, S3fsCurl::GetMultipartSize())){
        //S3FS_PRN_ERR("Failed to extract upload parts from last untreated area.");
        return -EIO;
    }
    if(to_upload_list.empty()){
        //S3FS_PRN_INFO("There is nothing to upload. In most cases, the untreated area does not meet the upload size.");
        return 0;
    }

    //
    // Has multipart uploading already started?
    //
    if(!IsUploading()){
        std::string strpath = SAFESTRPTR(path);
        int         result;
        if(0 != (result = PreMultipartUploadRequest(strpath, meta))){
            return result;
        }
    }

    //
    // Output debug level information
    //
    // When canceling(overwriting) a part that has already been uploaded, output it.
    //

    //
    // Upload Multipart parts
    //
    if(!ParallelMultipartUpload(path, to_upload_list, false)){
        //S3FS_PRN_ERR("Failed to upload multipart parts.");
        return -EIO;
    }

    //
    // Exclude the uploaded Untreated area and update the last Untreated area.
    //
    off_t behind_rem_start = aligned_start + aligned_size;
    off_t behind_rem_size  = (last_untreated_start + last_untreated_size) - behind_rem_start;

    if(!pfdent->ReplaceLastUpdateUntreatedPart(front_rem_start, front_rem_size, behind_rem_start, behind_rem_size)){
        //S3FS_PRN_WARN("The last untreated area could not be detected and the uploaded area could not be excluded from it, but continue because it does not affect the overall processing.");
    }

    return 0;
}

int PseudoFdInfo::WaitAllThreadsExit()
{
}

bool PseudoFdInfo::CancelAllThreads()
{
    bool need_cancel = false;
    {
        if(0 < instruct_count){
            //S3FS_PRN_INFO("The upload thread is running, so cancel them and wait for the end.");
            need_cancel = true;
            last_result = -ECANCELED;   // to stop thread running
        }
    }
    if(need_cancel){
    }
    return true;
}

//
// Extract the list for multipart upload from the Unteated Area
//
// The untreated_start parameter must be set aligning it with the boundaries
// of the maximum multipart upload size. This method expects it to be bounded.
//
// This method creates the upload area aligned from the untreated area by
// maximum size and creates the required list.
// If it overlaps with an area that has already been uploaded, the overlapped
// upload area will be canceled and absorbed by the untreated area.
// If the list creation process is complete and areas smaller than the maximum
// size remain, those area will be reset to untreated_start and untreated_size
// and returned to the caller.
// If the called untreated area is smaller than the maximum size of the
// multipart upload, no list will be created.
//
// [NOTE]
// Maximum multipart upload size must be uploading boundary.
//
bool PseudoFdInfo::ExtractUploadPartsFromUntreatedArea(off_t untreated_start, off_t untreated_size, mp_part_list_t& to_upload_list, filepart_list_t& cancel_upload_list, off_t max_mp_size)
{
    return true;
}

//
// Extract the area lists to be uploaded/downloaded for the entire file.
//
// [Parameters]
// to_upload_list       : A list of areas to upload in multipart upload.
// to_copy_list         : A list of areas for copy upload in multipart upload.
// to_download_list     : A list of areas that must be downloaded before multipart upload.
// cancel_upload_list   : A list of areas that have already been uploaded and will be canceled(overwritten).
// wait_upload_complete : If cancellation areas exist, this flag is set to true when it is necessary to wait until the upload of those cancellation areas is complete.
// file_size            : The size of the upload file.
// use_copy             : Specify true if copy multipart upload is available.
//
// [NOTE]
// The untreated_list in fdentity does not change, but upload_list is changed.
// (If you want to restore it, you can use cancel_upload_list.)
//
bool PseudoFdInfo::ExtractUploadPartsFromAllArea(UntreatedParts& untreated_list, mp_part_list_t& to_upload_list, mp_part_list_t& to_copy_list, mp_part_list_t& to_download_list, filepart_list_t& cancel_upload_list, bool& wait_upload_complete, off_t max_mp_size, off_t file_size, bool use_copy)
{
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
