/*
 * s3fs - FUSE-based file system backed by Amazon S3
 *
 * Copyright(C) 2007 Randy Rizun <rrizun@gmail.com>
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
//#include <atomic>
//#include <cerrno>
//#include <cstdio>
//#include <cstdlib>
//#include <limits>
//#include <memory>
//#include <mutex>
//#include <set>
//#include <string>
//#include <unistd.h>
//#include <utility>
//#include <dirent.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//#include <getopt.h>

#include "common.h"
#include "s3fs.h"
#include "s3fs_logger.h"
#include "metaheader.h"
#include "fdcache.h"
#include "fdcache_auto.h"
#include "fdcache_stat.h"
#include "curl.h"
#include "curl_share.h"
#include "curl_util.h"
#include "s3objlist.h"
#include "cache.h"
#include "addhead.h"
#include "sighandlers.h"
#include "s3fs_xml.h"
#include "string_util.h"
#include "s3fs_auth.h"
#include "s3fs_cred.h"
#include "s3fs_help.h"
#include "s3fs_util.h"
#include "s3fs_threadreqs.h"
#include "mpu_util.h"
#include "threadpoolman.h"

//-------------------------------------------------------------------
// Symbols
//-------------------------------------------------------------------
#if !defined(ENOATTR)
#define ENOATTR                   ENODATA
#endif

enum class dirtype : int8_t {
    UNKNOWN = -1,
    NEW = 0,
    OLD = 1,
    FOLDER = 2,
    NOOBJ = 3,
};

//-------------------------------------------------------------------
// Static variables
//-------------------------------------------------------------------
static uid_t mp_uid               = 0;    // owner of mount point(only not specified uid opt)
static gid_t mp_gid               = 0;    // group of mount point(only not specified gid opt)
static mode_t mp_mode             = 0;    // mode of mount point
static mode_t mp_umask            = 0;    // umask for mount point
static bool is_mp_umask           = false;// default does not set.
static std::string mountpoint;
static std::unique_ptr<S3fsCred> ps3fscred; // using only in this file
static std::string mimetype_file;
static bool nocopyapi             = false;
static bool norenameapi           = false;
static bool nonempty              = false;
static bool allow_other           = false;
static uid_t s3fs_uid             = 0;
static gid_t s3fs_gid             = 0;
static mode_t s3fs_umask          = 0;
static bool is_s3fs_uid           = false;// default does not set.
static bool is_s3fs_gid           = false;// default does not set.
static bool is_s3fs_umask         = false;// default does not set.
static bool is_remove_cache       = false;
static bool is_use_xattr          = false;
static off_t multipart_threshold  = 25 * 1024 * 1024;
static int64_t singlepart_copy_limit = 512 * 1024 * 1024;
static bool is_region_specified   = false;
static int s3fs_init_deferred_exit_status = 0;
static bool support_compat_dir    = false;// default does not support compatibility directory type
static int max_keys_list_object   = 1000;// default is 1000
static off_t max_dirty_data       = 5LL * 1024LL * 1024LL * 1024LL;
static bool use_wtf8              = false;
static off_t fake_diskfree_size   = -1; // default is not set(-1)
static bool update_parent_dir_stat= false;  // default not updating parent directory stats
static fsblkcnt_t bucket_block_count;                       // advertised block count of the bucket
static unsigned long s3fs_block_size = 16 * 1024 * 1024;    // s3fs block size is 16MB

//-------------------------------------------------------------------
// Static functions : prototype
//-------------------------------------------------------------------
static bool is_special_name_folder_object(const char* path);
static int chk_dir_object_type(const char* path, std::string& newpath, std::string& nowpath, std::string& nowcache, headers_t* pmeta = nullptr, dirtype* pDirType = nullptr);
static int remove_old_type_dir(const std::string& path, dirtype type);
static int get_object_attribute(const char* path, struct stat* pstbuf, headers_t* pmeta = nullptr, bool overcheck = true, bool* pisforce = nullptr, bool add_no_truncate_cache = false);
static int check_object_access(const char* path, int mask, struct stat* pstbuf);
static int check_object_owner(const char* path, struct stat* pstbuf);
static int check_parent_object_access(const char* path, int mask);
static int get_local_fent(AutoFdEntity& autoent, FdEntity **entity, const char* path, int flags = O_RDONLY, bool is_load = false);
static int readdir_multi_head(const char* path, const S3ObjList& head, void* buf, fuse_fill_dir_t filler);
static int list_bucket(const char* path, S3ObjList& head, const char* delimiter, bool check_content_only = false);
static int directory_empty(const char* path);
static int rename_large_object(const char* from, const char* to);
static int create_file_object(const char* path, mode_t mode, uid_t uid, gid_t gid);
static int create_directory_object(const char* path, mode_t mode, const struct timespec& ts_atime, const struct timespec& ts_mtime, const struct timespec& ts_ctime, uid_t uid, gid_t gid, const char* pxattrvalue);
static int rename_object(const char* from, const char* to, bool update_ctime);
static int rename_object_nocopy(const char* from, const char* to, bool update_ctime);
static int clone_directory_object(const char* from, const char* to, bool update_ctime, const char* pxattrvalue);
static int rename_directory(const char* from, const char* to);
static int update_mctime_parent_directory(const char* _path);
static int remote_mountpath_exists(const char* path, bool compat_dir);
static bool get_meta_xattr_value(const char* path, std::string& rawvalue);
static bool get_parent_meta_xattr_value(const char* path, std::string& rawvalue);
static bool get_xattr_posix_key_value(const char* path, std::string& xattrvalue, bool default_key);
static bool build_inherited_xattr_value(const char* path, std::string& xattrvalue);
static bool parse_xattr_keyval(const std::string& xattrpair, std::string& key, std::string* pval);
static size_t parse_xattrs(const std::string& strxattrs, xattrs_t& xattrs);
static std::string raw_build_xattrs(const xattrs_t& xattrs);
static std::string build_xattrs(const xattrs_t& xattrs);
static int s3fs_check_service();
static bool set_mountpoint_attribute(struct stat& mpst);
static int set_bucket(const std::string& arg);
static int my_fuse_opt_proc(void* data, const char* arg, int key, struct fuse_args* outargs);
static fsblkcnt_t parse_bucket_size(std::string max_size);
static bool is_cmd_exists(const std::string& command);
static int print_umount_message(const std::string& mp, bool force) __attribute__ ((unused));

//-------------------------------------------------------------------
// fuse interface functions
//-------------------------------------------------------------------
static int s3fs_getattr(const char* path, struct stat* stbuf);
static int s3fs_readlink(const char* path, char* buf, size_t size);
static int s3fs_mknod(const char* path, mode_t mode, dev_t rdev);
static int s3fs_mkdir(const char* path, mode_t mode);
static int s3fs_unlink(const char* path);
static int s3fs_rmdir(const char* path);
static int s3fs_symlink(const char* from, const char* to);
static int s3fs_rename(const char* from, const char* to);
static int s3fs_link(const char* from, const char* to);
static int s3fs_chmod(const char* path, mode_t mode);
static int s3fs_chmod_nocopy(const char* path, mode_t mode);
static int s3fs_chown(const char* path, uid_t uid, gid_t gid);
static int s3fs_chown_nocopy(const char* path, uid_t uid, gid_t gid);
static int s3fs_utimens(const char* path, const struct timespec ts[2]);
static int s3fs_utimens_nocopy(const char* path, const struct timespec ts[2]);
static int s3fs_truncate(const char* path, off_t size);
static int s3fs_create(const char* path, mode_t mode, struct fuse_file_info* fi);
static int s3fs_open(const char* path, struct fuse_file_info* fi);
static int s3fs_read(const char* path, char* buf, size_t size, off_t offset, struct fuse_file_info* fi);
static int s3fs_write(const char* path, const char* buf, size_t size, off_t offset, struct fuse_file_info* fi);
static int s3fs_statfs(const char* path, struct statvfs* stbuf);
static int s3fs_flush(const char* path, struct fuse_file_info* fi);
static int s3fs_fsync(const char* path, int datasync, struct fuse_file_info* fi);
static int s3fs_release(const char* path, struct fuse_file_info* fi);
static int s3fs_opendir(const char* path, struct fuse_file_info* fi);
static int s3fs_readdir(const char* path, void* buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info* fi);
static int s3fs_access(const char* path, int mask);
static void* s3fs_init(struct fuse_conn_info* conn);
static void s3fs_destroy(void*);
#if defined(__APPLE__)
static int s3fs_setxattr(const char* path, const char* name, const char* value, size_t size, int flags, uint32_t position);
static int s3fs_getxattr(const char* path, const char* name, char* value, size_t size, uint32_t position);
#else
static int s3fs_setxattr(const char* path, const char* name, const char* value, size_t size, int flags);
static int s3fs_getxattr(const char* path, const char* name, char* value, size_t size);
#endif
static int s3fs_listxattr(const char* path, char* list, size_t size);
static int s3fs_removexattr(const char* path, const char* name);

//-------------------------------------------------------------------
// Classes
//-------------------------------------------------------------------
//
// A flag indicating whether the mount point has a stat
//
// [NOTE]
// The flag is accessed from child threads, so std::atomic is used for exclusive control of flags.
static std::atomic<bool> has_mp_stat;

//-------------------------------------------------------------------
// Functions
//-------------------------------------------------------------------
static constexpr bool IS_REPLACEDIR(dirtype type)
{
    return dirtype::OLD == type || dirtype::FOLDER == type || dirtype::NOOBJ == type;
}

static constexpr bool IS_RMTYPEDIR(dirtype type)
{
    return dirtype::OLD == type || dirtype::FOLDER == type;
}

static constexpr bool IS_CREATE_MP_STAT(const char* path)
{
    // [NOTE] has_mp_stat is set in get_object_attribute()
    return (path != nullptr && 0 == strcmp(path, "/") && !has_mp_stat);
}

static bool is_special_name_folder_object(const char* path)
{
    if(!support_compat_dir){
        // s3fs does not support compatibility directory type("_$folder$" etc) now,
        // thus always returns false.
        return false;
    }

    if(!path || '\0' == path[0]){
        return false;
    }
    if(0 == strcmp(path, "/") && mount_prefix.empty()){
        // the path is the mount point which is the bucket root
        return false;
    }

    std::string strpath = path;
    headers_t   header;

    if(std::string::npos == strpath.find("_$folder$", 0)){
        if('/' == *strpath.rbegin()){
            strpath.erase(strpath.length() - 1);
        }
        strpath += "_$folder$";
    }

    // send request
    if(0 != head_request(strpath, header)){
        return false;
    }

    header.clear();
    //S3FS_MALLOCTRIM(0);

    return true;
}

// [Detail]
// This function is complicated for checking directory object type.
// Arguments is used for deleting cache/path, and remake directory object.
// Please see the codes which calls this function.
//
// path:      target path
// newpath:   should be object path for making/putting/getting after checking
// nowpath:   now object name for deleting after checking
// nowcache:  now cache path for deleting after checking
// pmeta:     headers map
// pDirType:  directory object type
//
static int chk_dir_object_type(const char* path, std::string& newpath, std::string& nowpath, std::string& nowcache, headers_t* pmeta, dirtype* pDirType)
{
    dirtype TypeTmp = dirtype::UNKNOWN;
    int  result  = -1;
    bool isforce = false;
    dirtype* pType = pDirType ? pDirType : &TypeTmp;

    // Normalize new path.
    newpath = path;
    if('/' != *newpath.rbegin()){
        std::string::size_type Pos;
        if(std::string::npos != (Pos = newpath.find("_$folder$", 0))){
            newpath.erase(Pos);
        }
        newpath += "/";
    }

    // Always check "dir/" at first.
    if(0 == (result = get_object_attribute(newpath.c_str(), nullptr, pmeta, false, &isforce))){
        // Found "dir/" cache --> Check for "_$folder$", "no dir object"
        nowcache = newpath;
        if(is_special_name_folder_object(newpath.c_str())){     // check support_compat_dir in this function
            // "_$folder$" type.
            (*pType) = dirtype::FOLDER;
            nowpath.erase(newpath.length() - 1);
            nowpath += "_$folder$"; // cut and add
        }else if(isforce){
            // "no dir object" type.
            (*pType) = dirtype::NOOBJ;
            nowpath  = "";
        }else{
            nowpath = newpath;
            if(!nowpath.empty() && '/' == *nowpath.rbegin()){
                // "dir/" type
                (*pType) = dirtype::NEW;
            }else{
                // "dir" type
                (*pType) = dirtype::OLD;
            }
        }
    }else if(support_compat_dir){
        // Check "dir" when support_compat_dir is enabled
        nowpath.erase(newpath.length() - 1);
        if(0 == (result = get_object_attribute(nowpath.c_str(), nullptr, pmeta, false, &isforce))){
            // Found "dir" cache --> this case is only "dir" type.
            // Because, if object is "_$folder$" or "no dir object", the cache is "dir/" type.
            // (But "no dir object" is checked here.)
            nowcache = nowpath;
            if(isforce){
                (*pType) = dirtype::NOOBJ;
                nowpath  = "";
            }else{
                (*pType) = dirtype::OLD;
            }
        }else{
            // Not found cache --> check for "_$folder$" and "no dir object".
            // (come here is that support_compat_dir is enabled)
            nowcache = "";  // This case is no cache.
            nowpath += "_$folder$";
            if(is_special_name_folder_object(nowpath.c_str())){
                // "_$folder$" type.
                (*pType) = dirtype::FOLDER;
                result   = 0;             // result is OK.
            }else if(-ENOTEMPTY == directory_empty(newpath.c_str())){
                // "no dir object" type.
                (*pType) = dirtype::NOOBJ;
                nowpath  = "";            // now path.
                result   = 0;             // result is OK.
            }else{
                // Error: Unknown type.
                (*pType) = dirtype::UNKNOWN;
                newpath = "";
                nowpath = "";
            }
        }
    }
    return result;
}

static int remove_old_type_dir(const std::string& path, dirtype type)
{
    if(IS_RMTYPEDIR(type)){
        int result;
        if(0 != (result = delete_request(path))){
            return result;
        }
        // succeed removing or not found the directory
    }else{
        // nothing to do
    }
    return 0;
}

//
// Get object attributes with stat cache.
// This function is base for s3fs_getattr().
//
// [NOTICE]
// Checking order is changed following list because of reducing the number of the requests.
// 1) "dir"
// 2) "dir/"
// 3) "dir_$folder$"
//
// Special two case of the mount point directory:
//  [Case 1] the mount point is the root of the bucket:
//           1) "/"
//
//  [Case 2] the mount point is a directory path(ex. foo) below the bucket:
//           1) "foo"
//           2) "foo/"
//           3) "foo_$folder$"
//
static int get_object_attribute(const char* path, struct stat* pstbuf, headers_t* pmeta, bool overcheck, bool* pisforce, bool add_no_truncate_cache)
{
    return 0;
}

//
// Check the object uid and gid for write/read/execute.
// The param "mask" is as same as access() function.
// If there is not a target file, this function returns -ENOENT.
// If the target file can be accessed, the result always is 0.
//
// path:   the target object path
// mask:   bit field(F_OK, R_OK, W_OK, X_OK) like access().
// stat:   nullptr or the pointer of struct stat.
//
static int check_object_access(const char* path, int mask, struct stat* pstbuf)
{

}

static int check_object_owner(const char* path, struct stat* pstbuf)
{

}

//
// Check accessing the parent directories of the object by uid and gid.
//
static int check_parent_object_access(const char* path, int mask)
{
 
}

//
// ssevalue is MD5 for SSE-C type, or KMS id for SSE-KMS
//
bool get_object_sse_type(const char* path, sse_type_t& ssetype, std::string& ssevalue)
{
    if(!path){
        return false;
    }

    headers_t meta;
    if(0 != get_object_attribute(path, nullptr, &meta)){
        //S3FS_PRN_ERR("Failed to get object(%s) headers", path);
        return false;
    }

}

static int get_local_fent(AutoFdEntity& autoent, FdEntity **entity, const char* path, int flags, bool is_load)
{

    return 0;
}

//
// create or update s3 meta
// @return fuse return code
//
int put_headers(const char* path, const headers_t& meta, bool is_copy, bool use_st_size)
{

    return 0;
}

static int s3fs_getattr(const char* _path, struct stat* stbuf)
{

}

static int s3fs_readlink(const char* _path, char* buf, size_t size)
{
    if(!_path || !buf || 0 == size){
        return 0;
    }
    return 0;
}

// common function for creation of a plain object
static int create_file_object(const char* path, mode_t mode, uid_t uid, gid_t gid)
{
    //S3FS_PRN_INFO2("[path=%s][mode=%04o]", path, mode);

    std::string strnow = s3fs_str_realtime();
    headers_t   meta;
    meta["Content-Type"]     = S3fsCurl::LookupMimeType(path);
    meta["x-amz-meta-uid"]   = std::to_string(uid);
    meta["x-amz-meta-gid"]   = std::to_string(gid);
    meta["x-amz-meta-mode"]  = std::to_string(mode);
    meta["x-amz-meta-atime"] = strnow;
    meta["x-amz-meta-ctime"] = strnow;
    meta["x-amz-meta-mtime"] = strnow;

    int result;
    if(0 != (result = put_request(SAFESTRPTR(path), meta, -1, true/* ahbe */))){
        return result;
    }
    return 0;
}

static int s3fs_mknod(const char *_path, mode_t mode, dev_t rdev)
{
}

static int s3fs_create(const char* _path, mode_t mode, struct fuse_file_info* fi)
{
    WTF8_ENCODE(path)
    int result;
    const struct fuse_context* pcxt;

    //FUSE_CTX_INFO("[path=%s][mode=%04o][flags=0x%x]", path, mode, fi->flags);

    // check parent directory attribute.
    if(0 != (result = check_parent_object_access(path, X_OK))){
        return result;
    }
    result = check_object_access(path, W_OK, nullptr);
    if(-ENOENT == result){
        if(0 != (result = check_parent_object_access(path, W_OK))){
            return result;
        }
    }else if(0 != result){
        return result;
    }

    return 0;
}

static int create_directory_object(const char* path, mode_t mode, const struct timespec& ts_atime, const struct timespec& ts_mtime, const struct timespec& ts_ctime, uid_t uid, gid_t gid, const char* pxattrvalue)
{

    if(!path || '\0' == path[0]){
        return -EINVAL;
    }
    std::string tpath = path;
    if('/' != *tpath.rbegin()){
        tpath += "/";
    }else if("/" == tpath && mount_prefix.empty()){
        tpath = "//";       // for the mount point that is bucket root, change "/" to "//".
    }

    headers_t meta;

    if(pxattrvalue){
        //S3FS_PRN_DBG("Set xattrs = %s", urlDecode(pxattrvalue).c_str());
        meta["x-amz-meta-xattr"] = pxattrvalue;
    }

    int result;
    if(0 != (result = put_request(tpath, meta, -1, false/* ahbe */))){
        return result;
    }
    return 0;
}

static int s3fs_mkdir(const char* _path, mode_t mode)
{

}

static int s3fs_unlink(const char* _path)
{
    WTF8_ENCODE(path)
    int result;

    //FUSE_CTX_INFO("[path=%s]", path);

    if(0 != (result = check_parent_object_access(path, W_OK | X_OK))){
        return result;
    }

    if(0 != (result = delete_request(SAFESTRPTR(path)))){
        return result;
    }

    StatCache::getStatCacheData()->DelStat(path);
    StatCache::getStatCacheData()->DelSymlink(path);
    FdManager::DeleteCacheFile(path);

    // update parent directory timestamp
    int update_result;
    if(0 != (update_result = update_mctime_parent_directory(path))){
        //S3FS_PRN_ERR("succeed to remove the file(%s), but could not update timestamp of its parent directory(result=%d).", path, update_result);
    }

    //S3FS_MALLOCTRIM(0);

    return result;
}

static int directory_empty(const char* path)
{
    int result;
    S3ObjList head;

    if((result = list_bucket(path, head, "/", true)) != 0){
        //S3FS_PRN_ERR("list_bucket returns error.");
        return result;
    }
    if(!head.IsEmpty()){
        return -ENOTEMPTY;
    }
    return 0;
}

static int s3fs_rmdir(const char* _path)
{
}

static int s3fs_symlink(const char* _from, const char* _to)
{
}

static int rename_object(const char* from, const char* to, bool update_ctime)
{

}

static int rename_object_nocopy(const char* from, const char* to, bool update_ctime)
{
    int result;

    if(0 != (result = check_parent_object_access(to, W_OK | X_OK))){
        // not permit writing "to" object parent dir.
        return result;
    }
    if(0 != (result = check_parent_object_access(from, W_OK | X_OK))){
        // not permit removing "from" object parent dir.
        return result;
    }

    // open & load
    {   // scope for AutoFdEntity
        AutoFdEntity autoent;
        FdEntity*    ent;
        if(0 != (result = get_local_fent(autoent, &ent, from, O_RDWR, true))){
            //S3FS_PRN_ERR("could not open and read file(%s)", from);
            return result;
        }

        // Set header
        if(!ent->SetContentType(to)){
            //S3FS_PRN_ERR("could not set content-type for %s", to);
            return -EIO;
        }

        // update ctime
        if(update_ctime){
            struct timespec ts;
            s3fs_realtime(ts);
            ent->SetCtime(ts);
        }

        // upload
        if(0 != (result = ent->RowFlush(autoent.GetPseudoFd(), to, true))){
            //S3FS_PRN_ERR("could not upload file(%s): result=%d", to, result);
            return result;
        }
    }
    FdManager::get()->Rename(from, to);

    // Remove file
    result = s3fs_unlink(from);

    // Stats
    StatCache::getStatCacheData()->DelStat(to);

    return result;
}

static int rename_large_object(const char* from, const char* to)
{
    int         result;
    struct stat buf;
    headers_t   meta;


    if(0 != (result = check_parent_object_access(to, W_OK | X_OK))){
        // not permit writing "to" object parent dir.
        return result;
    }
    if(0 != (result = check_parent_object_access(from, W_OK | X_OK))){
        // not permit removing "from" object parent dir.
        return result;
    }
    if(0 != (result = get_object_attribute(from, &buf, &meta, false))){
        return result;
    }


    // Rename cache file
    FdManager::get()->Rename(from, to);

    // Remove file
    result = s3fs_unlink(from);

    // Stats
    StatCache::getStatCacheData()->DelStat(to);

    return result;
}

static int clone_directory_object(const char* from, const char* to, bool update_ctime, const char* pxattrvalue)
{
}

static int rename_directory(const char* from, const char* to)
{
}

static int s3fs_rename(const char* _from, const char* _to)
{
}

static int s3fs_link(const char* _from, const char* _to)
{
    WTF8_ENCODE(from)
    WTF8_ENCODE(to)
    //FUSE_CTX_INFO("[from=%s][to=%s]", from, to);
    return -ENOTSUP;
}

static int s3fs_chmod(const char* _path, mode_t mode)
{
   
}

static int s3fs_chmod_nocopy(const char* _path, mode_t mode)
{
}

static int s3fs_chown(const char* _path, uid_t uid, gid_t gid)
{

    return 0;
}

static int s3fs_chown_nocopy(const char* _path, uid_t uid, gid_t gid)
{

}

static timespec handle_utimens_special_values(timespec ts, timespec now, timespec orig)
{
    if(ts.tv_nsec == UTIME_NOW){
        return now;
    }else if(ts.tv_nsec == UTIME_OMIT){
        return orig;
    }else{
        return ts;
    }
}

static int update_mctime_parent_directory(const char* _path)
{

}

static int s3fs_utimens(const char* _path, const struct timespec ts[2])
{
}

static int s3fs_utimens_nocopy(const char* _path, const struct timespec ts[2])
{
}

static int s3fs_truncate(const char* _path, off_t size)
{
   
}

static int s3fs_open(const char* _path, struct fuse_file_info* fi)
{

    return 0;
}

static int s3fs_read(const char* _path, char* buf, size_t size, off_t offset, struct fuse_file_info* fi)
{
  
}

static int s3fs_write(const char* _path, const char* buf, size_t size, off_t offset, struct fuse_file_info* fi)
{

}

static int s3fs_statfs(const char* _path, struct statvfs* stbuf)
{
}

static int s3fs_flush(const char* _path, struct fuse_file_info* fi)
{
}

// [NOTICE]
// Assumption is a valid fd.
//
static int s3fs_fsync(const char* _path, int datasync, struct fuse_file_info* fi)
{
}

static int s3fs_release(const char* _path, struct fuse_file_info* fi)
{


    return 0;
}

static int s3fs_opendir(const char* _path, struct fuse_file_info* fi)
{
}

static int readdir_multi_head(const char* path, const S3ObjList& head, void* buf, fuse_fill_dir_t filler)
{
}

static int s3fs_readdir(const char* _path, void* buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info* fi)
{
    WTF8_ENCODE(path)
    S3ObjList head;
    int result;

    //FUSE_CTX_INFO("[path=%s]", path);

    if(0 != (result = check_object_access(path, R_OK, nullptr))){
        return result;
    }

    // get a list of all the objects
    if((result = list_bucket(path, head, "/")) != 0){
        //S3FS_PRN_ERR("list_bucket returns error(%d).", result);
        return result;
    }

    // force to add "." and ".." name.
    filler(buf, ".", nullptr, 0);
    filler(buf, "..", nullptr, 0);
    if(head.IsEmpty()){
        return 0;
    }

    // Send multi head request for stats caching.
    std::string strpath = path;
    if(strcmp(path, "/") != 0){
        strpath += "/";
    }
    if(0 != (result = readdir_multi_head(strpath.c_str(), head, buf, filler))){
        //S3FS_PRN_ERR("readdir_multi_head returns error(%d).", result);
    }
    //S3FS_MALLOCTRIM(0);

    return result;
}

static int list_bucket(const char* path, S3ObjList& head, const char* delimiter, bool check_content_only)
{
}

static int remote_mountpath_exists(const char* path, bool compat_dir)
{
    struct stat stbuf;
    int result;

    // getattr will prefix the path with the remote mountpoint
    if(0 != (result = get_object_attribute(path, &stbuf, nullptr))){
        return result;
    }

    // [NOTE]
    // If there is no mount point(directory object) that s3fs can recognize,
    // an error will occur.
    // A mount point with a directory path(ex. "<bucket>/<directory>...")
    // requires that directory object.
    // If the directory or object is created by a client other than s3fs,
    // s3fs may not be able to recognize it. If you specify such a directory
    // as a mount point, you can avoid the error by starting with "compat_dir"
    // specified.
    //
    if(!compat_dir && !has_mp_stat){
        return -ENOENT;
    }
    return 0;
}

static bool get_meta_xattr_value(const char* path, std::string& rawvalue)
{
    if(!path || '\0' == path[0]){
        //S3FS_PRN_ERR("path is empty.");
        return false;
    }
    //S3FS_PRN_DBG("[path=%s]", path);

    rawvalue.clear();

    headers_t meta;
    if(0 != get_object_attribute(path, nullptr, &meta)){
        //S3FS_PRN_ERR("Failed to get object(%s) headers", path);
        return false;
    }

    headers_t::const_iterator iter;
    if(meta.cend() == (iter = meta.find("x-amz-meta-xattr"))){
        return false;
    }
    rawvalue = iter->second;
    return true;
}

static bool get_parent_meta_xattr_value(const char* path, std::string& rawvalue)
{
    if(0 == strcmp(path, "/") || 0 == strcmp(path, ".")){
        // path is mount point, thus does not have parent.
        return false;
    }

    std::string parent = mydirname(path);
    if(parent.empty()){
        //S3FS_PRN_ERR("Could not get parent path for %s.", path);
        return false;
    }
    return get_meta_xattr_value(parent.c_str(), rawvalue);
}

static bool get_xattr_posix_key_value(const char* path, std::string& xattrvalue, bool default_key)
{
    xattrvalue.clear();

    std::string rawvalue;
    if(!get_meta_xattr_value(path, rawvalue)){
        return false;
    }

    xattrs_t xattrs;
    if(0 == parse_xattrs(rawvalue, xattrs)){
        return false;
    }

    std::string targetkey;
    if(default_key){
        targetkey = "system.posix_acl_default";
    }else{
        targetkey = "system.posix_acl_access";
    }

    xattrs_t::iterator iter;
    if(xattrs.cend() == (iter = xattrs.find(targetkey))){
        return false;
    }

    // convert value by base64
    xattrvalue = s3fs_base64(reinterpret_cast<const unsigned char*>(iter->second.c_str()), iter->second.length());

    return true;
}

// [NOTE]
// Converts and returns the POSIX ACL default(system.posix_acl_default) value of
// the parent directory as a POSIX ACL(system.posix_acl_access) value.
// Returns false if the parent directory has no POSIX ACL defaults.
//
static bool build_inherited_xattr_value(const char* path, std::string& xattrvalue)
{
    //S3FS_PRN_DBG("[path=%s]", path);

    xattrvalue.clear();

    if(0 == strcmp(path, "/") || 0 == strcmp(path, ".")){
        // path is mount point, thus does not have parent.
        return false;
    }

    std::string parent = mydirname(path);
    if(parent.empty()){
        //S3FS_PRN_ERR("Could not get parent path for %s.", path);
        return false;
    }

    // get parent's "system.posix_acl_default" value(base64'd).
    std::string parent_default_value;
    if(!get_xattr_posix_key_value(parent.c_str(), parent_default_value, true)){
        return false;
    }
    return true;
}

static bool parse_xattr_keyval(const std::string& xattrpair, std::string& key, std::string* pval)
{
    // parse key and value
    size_t pos;
    std::string tmpval;
    if(std::string::npos == (pos = xattrpair.find_first_of(':'))){
        //S3FS_PRN_ERR("one of xattr pair(%s) is wrong format.", xattrpair.c_str());
        return false;
    }
    key    = xattrpair.substr(0, pos);
    tmpval = xattrpair.substr(pos + 1);

    if(!takeout_str_dquart(key) || !takeout_str_dquart(tmpval)){
        //S3FS_PRN_ERR("one of xattr pair(%s) is wrong format.", xattrpair.c_str());
        return false;
    }

    *pval = s3fs_decode64(tmpval.c_str(), tmpval.size());

    return true;
}

static size_t parse_xattrs(const std::string& strxattrs, xattrs_t& xattrs)
{

}

static std::string raw_build_xattrs(const xattrs_t& xattrs)
{
}

static std::string build_xattrs(const xattrs_t& xattrs)
{
}

static int set_xattrs_to_header(headers_t& meta, const char* name, const char* value, size_t size, int flags)
{
}

#if defined(__APPLE__)
static int s3fs_getxattr(const char* path, const char* name, char* value, size_t size, uint32_t position)
#else
static int s3fs_getxattr(const char* path, const char* name, char* value, size_t size)
#endif
{
}

static int s3fs_listxattr(const char* path, char* list, size_t size)
{
}

static int s3fs_removexattr(const char* path, const char* name)
{
}
   
// s3fs_init calls this function to exit cleanly from the fuse event loop.
//
// There's no way to pass an exit status to the high-level event loop API, so 
// this function stores the exit value in a global for main()
static void s3fs_exit_fuseloop(int exit_status)
{
}

static void* s3fs_init(struct fuse_conn_info* conn)
{

}

static void s3fs_destroy(void*)
{

    // Signal object
    if(!S3fsSignals::Destroy()){
        //S3FS_PRN_WARN("Failed to clean up signal object.");
    }

    // cache(remove at last)
    if(is_remove_cache && (!CacheFileStat::DeleteCacheFileStatDirectory() || !FdManager::DeleteCacheDirectory())){
        //S3FS_PRN_WARN("Could not remove cache directory.");
    }
}

static int s3fs_access(const char* path, int mask)
{
}

//
// If calling with wrong region, s3fs gets following error body as 400 error code.
// "<Error>
//    <Code>AuthorizationHeaderMalformed</Code>
//    <Message>The authorization header is malformed; the region 'us-east-1' is wrong; expecting 'ap-northeast-1'</Message>
//    <Region>ap-northeast-1</Region>
//    <RequestId>...</RequestId>
//    <HostId>...</HostId>
//  </Error>"
//
// So this is cheap code but s3fs should get correct region automatically.
//
static bool check_region_error(const char* pbody, size_t len, std::string& expectregion)
{
    if(!pbody){
        return false;
    }

    return true;
}

static bool check_endpoint_error(const char* pbody, size_t len, std::string& expectendpoint)
{
}

static bool check_invalid_sse_arg_error(const char* pbody, size_t len)
{
}

static bool check_error_message(const char* pbody, size_t len, std::string& message)
{
}

// [NOTE]
// This function checks if the bucket is accessible when s3fs starts.
//
// The following patterns for mount points are supported by s3fs:
// (1) Mount the bucket top
// (2) Mount to a directory(folder) under the bucket. In this case:
//     (2A) Directories created by clients other than s3fs
//     (2B) Directory created by s3fs
//
// Both case of (1) and (2) check access permissions to the mount point
// path(directory).
// In the case of (2A), if the directory(object) for the mount point does
// not exist, the check fails. However, launching s3fs with the "compat_dir"
// option avoids this error and the check succeeds. If you do not specify
// the "compat_dir" option in case (2A), please create a directory(object)
// for the mount point before launching s3fs.
//
static int s3fs_check_service()
{
}

//
// Check & Set attributes for mount point.
//
static bool set_mountpoint_attribute(struct stat& mpst)
{
}

//
// Set bucket and mount_prefix based on passed bucket name.
//
static int set_bucket(const std::string& arg)
{
}

//
// Utility function for parse "--bucket_size" option
//
// max_size: A string like 20000000, 30GiB, 20TB etc
// return:   An integer of type fsblkcnt_t corresponding to the number
//           of blocks with max_size calculated with the s3fs block size,
//           or 0 on error
//
static fsblkcnt_t parse_bucket_size(std::string max_size)
{
}

static bool is_cmd_exists(const std::string& command)
{
}

static int print_umount_message(const std::string& mp, bool force)
{
    std::string cmd;
    if (is_cmd_exists("fusermount")){
        if (force){
            cmd = "fusermount -uz " + mp;
        } else {
            cmd = "fusermount -u " + mp;
        }
    }else{
        if (force){
            cmd = "umount -l " + mp;
        } else {
            cmd = "umount " + mp;
        }
    }


    return 0;
}

// This is repeatedly called by the fuse option parser
// if the key is equal to FUSE_OPT_KEY_OPT, it's an option passed in prefixed by 
// '-' or '--' e.g.: -f -d -ousecache=/tmp
//
// if the key is equal to FUSE_OPT_KEY_NONOPT, it's either the bucket name 
//  or the mountpoint. The bucket name will always come before the mountpoint
//
static int my_fuse_opt_proc(void* data, const char* arg, int key, struct fuse_args* outargs)
{
    return 1;
}


/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: expandtab sw=4 ts=4 fdm=marker
* vim<600: expandtab sw=4 ts=4
*/
