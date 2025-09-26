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
//#include <unistd.h>
//#include <string>
//#include <sys/file.h>
//#include <sys/stat.h>

#include "s3fs_logger.h"
#include "fdcache_stat.h"
#include "fdcache.h"
#include "s3fs_util.h"
#include "s3fs_cred.h"
#include "string_util.h"

//------------------------------------------------
// CacheFileStat class methods
//------------------------------------------------
std::string CacheFileStat::GetCacheFileStatTopDir()
{
    std::string top_path;
    if(!FdManager::IsCacheDir() || S3fsCred::GetBucket().empty()){
        return top_path;
    }
}

int CacheFileStat::MakeCacheFileStatPath(const char* path, std::string& sfile_path, bool is_create_dir)
{
    std::string top_path = CacheFileStat::GetCacheFileStatTopDir();
    if(top_path.empty()){
        //S3FS_PRN_ERR("The path to cache top dir is empty.");
        return -EIO;
    }

    if(is_create_dir){
      int result;
      if(0 != (result = mkdirp(top_path + mydirname(path), 0777))){
          //S3FS_PRN_ERR("failed to create dir(%s) by errno(%d).", path, result);
          return result;
      }
    }
    if(!path || '\0' == path[0]){
        sfile_path = top_path;
    }else{
        sfile_path = top_path + SAFESTRPTR(path);
    }
    return 0;
}

bool CacheFileStat::CheckCacheFileStatTopDir()
{
    std::string top_path = CacheFileStat::GetCacheFileStatTopDir();
    if(top_path.empty()){
        //S3FS_PRN_INFO("The path to cache top dir is empty, thus not need to check permission.");
        return true;
    }

    return check_exist_dir_permission(top_path.c_str());
}

int CacheFileStat::DeleteCacheFileStat(const char* path)
{
    if(!path || '\0' == path[0]){
        return -EINVAL;
    }
    // stat path
    std::string sfile_path;
    int result;
    if(0 != (result = CacheFileStat::MakeCacheFileStatPath(path, sfile_path, false))){
        //S3FS_PRN_ERR("failed to create cache stat file path(%s)", path);
        return result;
    }
}

// [NOTE]
// If remove stat file directory, it should do before removing
// file cache directory.
//
bool CacheFileStat::DeleteCacheFileStatDirectory()
{
    std::string top_path = CacheFileStat::GetCacheFileStatTopDir();
    if(top_path.empty()){
        //S3FS_PRN_INFO("The path to cache top dir is empty, thus not need to remove it.");
        return true;
    }
    return delete_files_in_dir(top_path.c_str(), true);
}

bool CacheFileStat::RenameCacheFileStat(const char* oldpath, const char* newpath)
{
    if(!oldpath || '\0' == oldpath[0] || !newpath || '\0' == newpath[0]){
        return false;
    }

    // stat path
    std::string old_filestat;
    std::string new_filestat;
    if(0 != CacheFileStat::MakeCacheFileStatPath(oldpath, old_filestat, false) || 0 != CacheFileStat::MakeCacheFileStatPath(newpath, new_filestat, false)){
        return false;
    }
}

//------------------------------------------------
// CacheFileStat methods
//------------------------------------------------
CacheFileStat::CacheFileStat(const char* tpath)
{
    if(tpath && '\0' != tpath[0]){
    }
}

CacheFileStat::~CacheFileStat()
{
}

bool CacheFileStat::SetPath(const char* tpath, bool is_open)
{
    if(!tpath || '\0' == tpath[0]){
        return false;
    }
    if(!Release()){
        // could not close old stat file.
        return false;
    }
    path = tpath;
    if(!is_open){
        return true;
    }
    return Open();
}

bool CacheFileStat::RawOpen(bool readonly)
{
}

bool CacheFileStat::Open()
{
}

bool CacheFileStat::ReadOnlyOpen()
{
}

bool CacheFileStat::Release()
{
    if(-1 == fd){
        // already release
        return true;
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
