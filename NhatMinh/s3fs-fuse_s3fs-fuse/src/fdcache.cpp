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

//#include <cstdio>
//#include <cstdlib>
//#include <cerrno>
//#include <climits>
//#include <unistd.h>
//#include <dirent.h>
//#include <mutex>
//#include <string>
//#include <sys/stat.h>
//#include <sys/statvfs.h>
//#include <utility>

#include "fdcache.h"
#include "fdcache_stat.h"
#include "s3fs_util.h"
#include "s3fs_logger.h"
#include "s3fs_cred.h"
#include "string_util.h"

//
// The following symbols are used by FdManager::RawCheckAllCache().
//
// These must be #defines due to string literal concatenation.
#define CACHEDBG_FMT_HEAD       "---------------------------------------------------------------------------\n" \
                                "Check cache file and its stats file consistency at %s\n"                       \
                                "---------------------------------------------------------------------------"
#define CACHEDBG_FMT_FOOT       "---------------------------------------------------------------------------\n" \
                                "Summary - Total files:                %d\n" \
                                "          Detected error files:       %d\n" \
                                "          Detected error directories: %d\n" \
                                "---------------------------------------------------------------------------"
#define CACHEDBG_FMT_FILE_OK    "File:      %s%s    -> [OK] no problem"
#define CACHEDBG_FMT_FILE_PROB  "File:      %s%s"
#define CACHEDBG_FMT_DIR_PROB   "Directory: %s"
#define CACHEDBG_FMT_ERR_HEAD   "           -> [E] there is a mark that data exists in stats, but there is no data in the cache file."
#define CACHEDBG_FMT_WARN_HEAD  "           -> [W] These show no data in stats, but there is evidence of data in the cache file(no problem)."
#define CACHEDBG_FMT_WARN_OPEN  "\n           -> [W] This file is currently open and may not provide accurate analysis results."
#define CACHEDBG_FMT_CRIT_HEAD  "           -> [C] %s"
#define CACHEDBG_FMT_CRIT_HEAD2 "           -> [C] "
#define CACHEDBG_FMT_PROB_BLOCK "                  0x%016zx(0x%016zx bytes)"

// [NOTE]
// NOCACHE_PATH_PREFIX symbol needs for not using cache mode.
// Now s3fs I/F functions in s3fs.cpp has left the processing
// to FdManager and FdEntity class. FdManager class manages
// the list of local file stat and file descriptor in conjunction
// with the FdEntity class.
// When s3fs is not using local cache, it means FdManager must
// return new temporary file descriptor at each opening it.
// Then FdManager caches fd by key which is dummy file path
// instead of real file path.
// This process may not be complete, but it is easy way can
// be realized.
//
static constexpr char NOCACHE_PATH_PREFIX_FORM[] = " __S3FS_UNEXISTED_PATH_%lx__ / ";  // important space words for simply

//------------------------------------------------
// FdManager class variable
//------------------------------------------------
FdManager       FdManager::singleton;
std::mutex      FdManager::fd_manager_lock;
std::mutex      FdManager::cache_cleanup_lock;
std::mutex      FdManager::reserved_diskspace_lock;
std::mutex      FdManager::except_entmap_lock;
std::string     FdManager::cache_dir;
bool            FdManager::check_cache_dir_exist(false);
off_t           FdManager::free_disk_space = 0;
off_t           FdManager::fake_used_disk_space = 0;
std::string     FdManager::check_cache_output;
bool            FdManager::checked_lseek(false);
bool            FdManager::have_lseek_hole(false);
std::string     FdManager::tmp_dir = "/tmp";

//------------------------------------------------
// FdManager class methods
//------------------------------------------------
bool FdManager::SetCacheDir(const char* dir)
{
    if(!dir || '\0' == dir[0]){
        cache_dir = "";
    }else{
        cache_dir = dir;
    }
    return true;
}

bool FdManager::SetCacheCheckOutput(const char* path)
{
    if(!path || '\0' == path[0]){
        check_cache_output.clear();
    }else{
        check_cache_output = path;
    }
    return true;
}

bool FdManager::DeleteCacheDirectory()
{
    if(FdManager::cache_dir.empty()){
        return true;
    }

    std::string cache_path;
    if(!FdManager::MakeCachePath(nullptr, cache_path, false)){
        return false;
    }
    if(!delete_files_in_dir(cache_path.c_str(), true)){
        return false;
    }

    std::string mirror_path = FdManager::cache_dir + "/." + S3fsCred::GetBucket() + ".mirror";
    if(!delete_files_in_dir(mirror_path.c_str(), true)){
        return false;
    }

    return true;
}

int FdManager::DeleteCacheFile(const char* path)
{
    //S3FS_PRN_INFO3("[path=%s]", SAFESTRPTR(path));

    if(!path){
        return -EIO;
    }
    if(FdManager::cache_dir.empty()){
        return 0;
    }
    std::string cache_path;
    if(!FdManager::MakeCachePath(path, cache_path, false)){
        return 0;
    }
}

bool FdManager::MakeCachePath(const char* path, std::string& cache_path, bool is_create_dir, bool is_mirror_path)
{
    if(FdManager::cache_dir.empty()){
        cache_path = "";
        return true;
    }

    std::string resolved_path(FdManager::cache_dir);
    if(!is_mirror_path){
        resolved_path += "/";
        resolved_path += S3fsCred::GetBucket();
    }else{
        resolved_path += "/.";
        resolved_path += S3fsCred::GetBucket();
        resolved_path += ".mirror";
    }

    if(is_create_dir){
        int result;
        if(0 != (result = mkdirp(resolved_path + mydirname(path), 0777))){
            //S3FS_PRN_ERR("failed to create dir(%s) by errno(%d).", path, result);
            return false;
        }
    }
    if(!path || '\0' == path[0]){
        cache_path = resolved_path;
    }else{
        cache_path = resolved_path + SAFESTRPTR(path);
    }
    return true;
}

bool FdManager::CheckCacheTopDir()
{
    if(FdManager::cache_dir.empty()){
        return true;
    }
    std::string toppath(FdManager::cache_dir + "/" + S3fsCred::GetBucket());

    return check_exist_dir_permission(toppath.c_str());
}

bool FdManager::MakeRandomTempPath(const char* path, std::string& tmppath)
{
    char szBuff[64];

    //snprintf(szBuff, sizeof(szBuff), NOCACHE_PATH_PREFIX_FORM, random());   // worry for performance, but maybe don't worry.
    szBuff[sizeof(szBuff) - 1] = '\0';                                      // for safety
    tmppath  = szBuff;
    tmppath += path ? path : "";
    return true;
}

bool FdManager::SetCheckCacheDirExist(bool is_check)
{
    bool old = FdManager::check_cache_dir_exist;
    FdManager::check_cache_dir_exist = is_check;
    return old;
}

bool FdManager::CheckCacheDirExist()
{
    if(!FdManager::check_cache_dir_exist){
        return true;
    }
    if(FdManager::cache_dir.empty()){
        return true;
    }
    return IsDir(cache_dir);
}

off_t FdManager::GetEnsureFreeDiskSpaceHasLock()
{
    return FdManager::free_disk_space;
}

off_t FdManager::SetEnsureFreeDiskSpace(off_t size)
{
    const std::lock_guard<std::mutex> lock(FdManager::reserved_diskspace_lock);
    off_t old = FdManager::free_disk_space;
    FdManager::free_disk_space = size;
    return old;
}

bool FdManager::InitFakeUsedDiskSize(off_t fake_freesize)
{
    const std::lock_guard<std::mutex> lock(FdManager::reserved_diskspace_lock);

    FdManager::fake_used_disk_space = 0;    // At first, clear this value because this value is used in GetFreeDiskSpaceHasLock.

    off_t actual_freesize = FdManager::GetFreeDiskSpaceHasLock(nullptr);

    if(fake_freesize < actual_freesize){
        FdManager::fake_used_disk_space = actual_freesize - fake_freesize;
    }else{
        FdManager::fake_used_disk_space = 0;
    }
    return true;
}

off_t FdManager::GetTotalDiskSpaceByRatio(int ratio)
{
    return FdManager::GetTotalDiskSpace(nullptr) * ratio / 100;
}

off_t FdManager::GetTotalDiskSpace(const char* path)
{

}

off_t FdManager::GetFreeDiskSpaceHasLock(const char* path)
{
}

int FdManager::GetVfsStat(const char* path, struct statvfs* vfsbuf){
}

bool FdManager::IsSafeDiskSpace(const char* path, off_t size, bool withmsg)
{
    // const std::lock_guard<std::mutex> lock(FdManager::reserved_diskspace_lock);

    off_t fsize = FdManager::GetFreeDiskSpaceHasLock(path);
    off_t needsize = size + FdManager::GetEnsureFreeDiskSpaceHasLock();

    if(fsize < needsize){
        if(withmsg){
            // //S3FS_PRN_EXIT("There is no enough disk space for used as cache(or temporary) directory by s3fs. Requires %.3f MB, already has %.3f MB.", static_cast<double>(needsize) / 1024 / 1024, static_cast<double>(fsize) / 1024 / 1024);
        }
        return false;
    }
    return true;
}

bool FdManager::HaveLseekHole()
{
}

bool FdManager::SetTmpDir(const char *dir)
{
    if(!dir || '\0' == dir[0]){
        tmp_dir = "/tmp";
    }else{
        tmp_dir = dir;
    }
    return true;
}

bool FdManager::IsDir(const std::string& dir)
{
    // check the directory
}

bool FdManager::CheckTmpDirExist()
{
    if(FdManager::tmp_dir.empty()){
        return true;
    }
    return IsDir(tmp_dir);
}


bool FdManager::HasOpenEntityFd(const char* path)
{
    const std::lock_guard<std::mutex> lock(FdManager::fd_manager_lock);

    const FdEntity* ent;
    int         fd = -1;
    if(nullptr == (ent = FdManager::singleton.GetFdEntityHasLock(path, fd, false))){
        return false;
    }
    return (0 < ent->GetOpenCount());
}

// [NOTE]
// Returns the number of open pseudo fd.
//
int FdManager::GetOpenFdCount(const char* path)
{
}

//------------------------------------------------
// FdManager methods
//------------------------------------------------
FdManager::FdManager()
{
    if(this != FdManager::get()){
        abort();
    }
}

FdManager::~FdManager()
{
}

FdEntity* FdManager::GetFdEntityHasLock(const char* path, int& existfd, bool newfd)
{
    return nullptr;
}

FdEntity* FdManager::Open(int& fd, const char* path, const headers_t* pmeta, off_t size, const struct timespec& ts_mctime, int flags, bool force_tmpfile, bool is_create, bool ignore_modify)
{
}

// [NOTE]
// This method does not create a new pseudo fd.
// It just finds existfd and returns the corresponding entity.
//
FdEntity* FdManager::GetExistFdEntity(const char* path, int existfd)
{
    return nullptr;
}

FdEntity* FdManager::OpenExistFdEntity(const char* path, int& fd, int flags)
{
}

void FdManager::Rename(const std::string &from, const std::string &to)
{
}

bool FdManager::Close(FdEntity* ent, int fd)
{
    return false;
}

bool FdManager::UpdateEntityToTempPath()
{
    return true;
}

void FdManager::CleanupCacheDir()
{
    ////S3FS_PRN_DBG("cache cleanup requested");

    if(!FdManager::IsCacheDir()){
        return;
    }

    if(FdManager::cache_cleanup_lock.try_lock()){
        ////S3FS_PRN_DBG("cache cleanup started");
        CleanupCacheDirInternal("");
        ////S3FS_PRN_DBG("cache cleanup ended");
    }else{
        // wait for other thread to finish cache cleanup
        FdManager::cache_cleanup_lock.lock();
    }
    FdManager::cache_cleanup_lock.unlock();
}

void FdManager::CleanupCacheDirInternal(const std::string &path)
{
}

bool FdManager::ReserveDiskSpace(off_t size)
{
    if(IsSafeDiskSpace(nullptr, size)){
        const std::lock_guard<std::mutex> lock(FdManager::reserved_diskspace_lock);
        FdManager::free_disk_space += size;
        return true;
    }
    return false;
}

void FdManager::FreeReservedDiskSpace(off_t size)
{
    const std::lock_guard<std::mutex> lock(FdManager::reserved_diskspace_lock);
    FdManager::free_disk_space -= size;
}

//
// Inspect all files for stats file for cache file
// 
// [NOTE]
// The minimum sub_path parameter is "/".
// The sub_path is a directory path starting from "/" and ending with "/".
//
// This method produces the following output.
//
// * Header
//    ------------------------------------------------------------
//    Check cache file and its stats file consistency
//    ------------------------------------------------------------
// * When the cache file and its stats information match
//    File path: <file path> -> [OK] no problem
//
// * If there is a problem with the cache file and its stats information
//    File path: <file path>
//      -> [P] <If the problem is that parsing is not possible in the first place, the message is output here with this prefix.>
//      -> [E] there is a mark that data exists in stats, but there is no data in the cache file.
//             <offset address>(bytes)
//                 ...
//                 ...
//      -> [W] These show no data in stats, but there is evidence of data in the cache file.(no problem.)
//             <offset address>(bytes)
//                 ...
//                 ...
//
bool FdManager::RawCheckAllCache(FILE* fp, const char* cache_stat_top_dir, const char* sub_path, int& total_file_cnt, int& err_file_cnt, int& err_dir_cnt)
{
    return true;
}

bool FdManager::CheckAllCache()
{
    if(!FdManager::HaveLseekHole()){
        //S3FS_PRN_ERR("lseek does not support SEEK_DATA/SEEK_HOLE, then could not check cache.");
        return false;
    }
}

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: expandtab sw=4 ts=4 fdm=marker
* vim<600: expandtab sw=4 ts=4
*/
