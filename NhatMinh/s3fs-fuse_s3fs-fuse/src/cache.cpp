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
//#include <cerrno>
//#include <cstdlib>
//#include <mutex>
//#include <string>
//#include <sys/stat.h>
//#include <utility>
//#include <vector>

#include "s3fs.h"
#include "s3fs_logger.h"
#include "s3fs_util.h"
#include "cache.h"
#include "string_util.h"
#include "dummy.h"

//-------------------------------------------------------------------
// Utility
//-------------------------------------------------------------------
static void SetStatCacheTime(struct timespec& ts)
{
    if(-1 == clock_gettime(static_cast<clockid_t>(CLOCK_MONOTONIC_COARSE), &ts)){
        //S3FS_PRN_CRIT("clock_gettime failed: %d", errno);
        abort();
    }
}

static constexpr int CompareStatCacheTime(const struct timespec& ts1, const struct timespec& ts2)
{
    // return -1:  ts1 < ts2
    //         0:  ts1 == ts2
    //         1:  ts1 > ts2
    if(ts1.tv_sec < ts2.tv_sec){
        return -1;
    }else if(ts1.tv_sec > ts2.tv_sec){
        return 1;
    }else{
        if(ts1.tv_nsec < ts2.tv_nsec){
            return -1;
        }else if(ts1.tv_nsec > ts2.tv_nsec){
            return 1;
        }
    }
    return 0;
}

static bool IsExpireStatCacheTime(const struct timespec& ts, time_t expire)
{
    struct timespec nowts;
    SetStatCacheTime(nowts);
    nowts.tv_sec -= expire;

    return (0 < CompareStatCacheTime(nowts, ts));
}

//
// For stats cache out 
//
typedef std::vector<stat_cache_t::iterator>   statiterlist_t;

struct sort_statiterlist{
    // ascending order
    bool operator()(const stat_cache_t::iterator& src1, const stat_cache_t::iterator& src2) const
    {
        int result = CompareStatCacheTime(src1->second.cache_date, src2->second.cache_date);
        if(0 == result){
            if(src1->second.hit_count < src2->second.hit_count){
                result = -1;
            }
        }
        return (result < 0);
    }
};

//
// For symbolic link cache out 
//
typedef std::vector<symlink_cache_t::iterator>   symlinkiterlist_t;

struct sort_symlinkiterlist{
    // ascending order
    bool operator()(const symlink_cache_t::iterator& src1, const symlink_cache_t::iterator& src2) const
    {
        int result = CompareStatCacheTime(src1->second.cache_date, src2->second.cache_date);  // use the same as Stats
        if(0 == result){
            if(src1->second.hit_count < src2->second.hit_count){
                result = -1;
            }
        }
        return (result < 0);
    }
};

//-------------------------------------------------------------------
// Static
//-------------------------------------------------------------------
StatCache       StatCache::singleton;
std::mutex      StatCache::stat_cache_lock;

//-------------------------------------------------------------------
// Constructor/Destructor
//-------------------------------------------------------------------
StatCache::StatCache() : IsExpireTime(true), IsExpireIntervalType(false), ExpireTime(15 * 60), CacheSize(100'000), UseNegativeCache(true)
{
    if(this == StatCache::getStatCacheData()){
        stat_cache.clear();
    }else{
        abort();
    }
}

StatCache::~StatCache()
{
    if(this == StatCache::getStatCacheData()){
        Clear();
    }else{
        abort();
    }
}

//-------------------------------------------------------------------
// Methods
//-------------------------------------------------------------------
unsigned long StatCache::GetCacheSize() const
{
    return CacheSize;
}

unsigned long StatCache::SetCacheSize(unsigned long size)
{
    unsigned long old = CacheSize;
    CacheSize = size;
    return old;
}

time_t StatCache::GetExpireTime() const
{
    return (IsExpireTime ? ExpireTime : (-1));
}

time_t StatCache::SetExpireTime(time_t expire, bool is_interval)
{
    time_t old           = ExpireTime;
    ExpireTime           = expire;
    IsExpireTime         = true;
    IsExpireIntervalType = is_interval;
    return old;
}

time_t StatCache::UnsetExpireTime()
{
    time_t old           = IsExpireTime ? ExpireTime : (-1);
    ExpireTime           = 0;
    IsExpireTime         = false;
    IsExpireIntervalType = false;
    return old;
}

bool StatCache::SetNegativeCache(bool flag)
{
    bool old = UseNegativeCache;
    UseNegativeCache = flag;
    return old;
}

void StatCache::Clear()
{
    const std::lock_guard<std::mutex> lock(StatCache::stat_cache_lock);

    stat_cache.clear();
    //S3FS_MALLOCTRIM(0);
}

bool StatCache::GetStat(const std::string& key, struct stat* pst, headers_t* meta, bool overcheck, const char* petag, bool* pisforce)
{
    return true;
}

bool StatCache::IsNoObjectCache(const std::string& key, bool overcheck)
{
    if(!UseNegativeCache){
        return false;
    }
    const std::lock_guard<std::mutex> lock(StatCache::stat_cache_lock);

    std::string strpath = key;

    // Search path in cache
    auto iter = stat_cache.end();
    if(overcheck && '/' != *strpath.rbegin()){
        strpath += "/";
        iter     = stat_cache.find(strpath);
    }
    if(iter == stat_cache.end()){
        strpath = key;
        iter    = stat_cache.find(strpath);
    }
    if(iter == stat_cache.end()){
        // not hit
        return false;
    }

    // Stat cache entry object
    const stat_cache_entry* ent = &iter->second;

    if(!ent->noobjcache){
        // Hit but not no object cache
        return false;
    }

    // Check timeout
    if(0L == ent->notruncate && IsExpireTime && IsExpireStatCacheTime(ent->cache_date, ExpireTime)){
        DelStatHasLock(strpath);
        return false;
    }

    // Valid no object cache
    //S3FS_PRN_DBG("stat cache(no object) hit [path=%s][hit count=%lu]", strpath.c_str(), ent->hit_count);

    if(IsExpireIntervalType){
        SetStatCacheTime((*iter).second.cache_date);    // [NOTE] ent cannot be used because it is const
    }
    return true;
}

bool StatCache::AddStat(const std::string& key, const headers_t& meta, bool forcedir, bool no_truncate)
{
    if(!no_truncate && CacheSize< 1){
        return true;
    }
    //S3FS_PRN_INFO3("add stat cache entry[path=%s]", key.c_str());

    const std::lock_guard<std::mutex> lock(StatCache::stat_cache_lock);

    // if key is found, delete it
    if(stat_cache.cend() != stat_cache.find(key)){
        // found cache
        DelStatHasLock(key);
    }else{
        // truncate cache (only when cache oversize)

        // [MEMO] The following warning will be fixed later
        // cppcheck-suppress unmatchedSuppression
        // cppcheck-suppress knownConditionTrueFalse
        if(!TruncateCache(true)){
            return false;
        }
    }

    // make new
    stat_cache_entry ent;
    // if(!convert_header_to_stat(key.c_str(), meta, &ent.stbuf, forcedir)){
    //     return false;
    // }

}

// [NOTE]
// Updates only meta data if cached data exists.
// And when these are updated, it also updates the cache time.
//
// Since the file mode may change while the file is open, it is
// updated as well.
//
bool StatCache::UpdateMetaStats(const std::string& key, const headers_t& meta)
{
    if(CacheSize < 1){
        return true;
    }
    //S3FS_PRN_INFO3("update stat cache entry[path=%s]", key.c_str());

    auto iter = stat_cache.find(key);
    if(stat_cache.cend() == iter){
        return true;
    }

    return true;
}

bool StatCache::AddNoObjectCache(const std::string& key)
{
    if(!UseNegativeCache){
        return true;    // pretend successful
    }
    if(CacheSize < 1){
        return true;
    }
    //S3FS_PRN_INFO3("add no object cache entry[path=%s]", key.c_str());

    const std::lock_guard<std::mutex> lock(StatCache::stat_cache_lock);

    if(stat_cache.cend() != stat_cache.find(key)){
        // found
        DelStatHasLock(key);
    }else{
        // truncate cache (only when cache oversize)

        // [MEMO] The following warning will be fixed later
        // cppcheck-suppress unmatchedSuppression
        // cppcheck-suppress knownConditionTrueFalse
        if(!TruncateCache(true)){
            return false;
        }
    }

    // make new
    stat_cache_entry ent{};
    ent.hit_count  = 0;
    ent.isforce    = false;
    ent.noobjcache = true;
    ent.notruncate = 0L;
    ent.meta.clear();
    SetStatCacheTime(ent.cache_date);    // Set time.

    stat_cache[key] = std::move(ent);

    // check symbolic link cache
    if(symlink_cache.cend() != symlink_cache.find(key)){
        // if symbolic link cache has key, thus remove it.
        DelSymlinkHasLock(key);
    }
    return true;
}

void StatCache::ChangeNoTruncateFlag(const std::string& key, bool no_truncate)
{
    auto iter = stat_cache.find(key);

    if(stat_cache.cend() != iter){
        stat_cache_entry* ent = &iter->second;
        if(no_truncate){
            if(0L == ent->notruncate){
                // need to add no truncate cache.
                AddNotruncateCache(key);
            }
            ++(ent->notruncate);
        }else{
            if(0L < ent->notruncate){
                --(ent->notruncate);
                if(0L == ent->notruncate){
                    // need to delete from no truncate cache.
                    DelNotruncateCache(key);
                }
            }
        }
    }
}

// [NOTE]
// If check_only_oversize_case=true, the process will only be performed
// if the cache size is overflowing.
// If false, the process of removing expired cache entries will
// always be performed(if IsExpireTime is enabled).
//
bool StatCache::TruncateCache(bool check_only_oversize_case)
{
    if(stat_cache.empty() || (check_only_oversize_case && stat_cache.size() < CacheSize)){
        return true;
    }

    // 2) check stat cache count
    if(stat_cache.size() < CacheSize){
        return true;
    }

}

bool StatCache::DelStatHasLock(const std::string& key)
{

    // Search key in cache
    stat_cache_t::iterator iter;
    if(stat_cache.cend() != (iter = stat_cache.find(key))){
        stat_cache.erase(iter);
        DelNotruncateCache(key);
    }

    // Search again key with(without) "/" character in cache
    if(!key.empty() && key != "/"){
        std::string strpath = key;
        if('/' == *strpath.rbegin()){
            // If there is "path" cache, delete it.
            strpath.erase(strpath.length() - 1);
        }else{
            // If there is "path/" cache, delete it.
            strpath += "/";
        }
        if(stat_cache.cend() != (iter = stat_cache.find(strpath))){
            stat_cache.erase(iter);
            DelNotruncateCache(strpath);
        }
    }
    //S3FS_MALLOCTRIM(0);

    return true;
}

bool StatCache::GetSymlink(const std::string& key, std::string& value)
{
}

bool StatCache::AddSymlink(const std::string& key, const std::string& value)
{
    if(CacheSize< 1){
        return true;
    }
    //S3FS_PRN_INFO3("add symbolic link cache entry[path=%s, value=%s]", key.c_str(), value.c_str());

    const std::lock_guard<std::mutex> lock(StatCache::stat_cache_lock);

    if(symlink_cache.cend() != symlink_cache.find(key)){
        // found
        DelSymlinkHasLock(key);
    }else{
        // truncate symlink cache (only when cache oversize)

        // [MEMO] The following warning will be fixed later
        // cppcheck-suppress unmatchedSuppression
        // cppcheck-suppress knownConditionTrueFalse
        if(!TruncateSymlink(true)){
            return false;
        }
    }

    return true;
}

// [NOTE]
// If check_only_oversize_case=true, the process will only be performed
// if the cache size is overflowing.
// If false, the process of removing expired cache entries will
// always be performed(if IsExpireTime is enabled).
//
bool StatCache::TruncateSymlink(bool check_only_oversize_case)
{
    if(stat_cache.empty() || (check_only_oversize_case && symlink_cache.size() < CacheSize)){
        return true;
    }

    // 1) erase over expire time
    if(IsExpireTime){
    
    }

    // 2) check stat cache count
    if(symlink_cache.size() < CacheSize){
        return true;
    }

    return true;
}

bool StatCache::DelSymlinkHasLock(const std::string& key)
{
}

bool StatCache::AddNotruncateCache(const std::string& key)
{
    if(key.empty() || '/' == *key.rbegin()){
        return false;
    }

    std::string parentdir = mydirname(key);
    std::string filename  = mybasename(key);
    if(parentdir.empty() || filename.empty()){
        return false;
    }
    parentdir += '/';       // directory path must be '/' termination.

    auto iter = notruncate_file_cache.find(parentdir);
    if(iter == notruncate_file_cache.cend()){
        // add new list
        notruncate_filelist_t list;
        list.push_back(filename);
        notruncate_file_cache[parentdir] = list;
    }else{
    }
    return true;
}

bool StatCache::DelNotruncateCache(const std::string& key)
{
    if(key.empty() || '/' == *key.rbegin()){
        return false;
    }

    std::string parentdir = mydirname(key);
    std::string filename  = mybasename(key);
    if(parentdir.empty() || filename.empty()){
        return false;
    }
    parentdir += '/';       // directory path must be '/' termination.

    auto iter = notruncate_file_cache.find(parentdir);
    if(iter != notruncate_file_cache.cend()){
        // found directory in map
    }
    return true;
}

// [Background]
// When s3fs creates a new file, the file does not exist until the file contents
// are uploaded.(because it doesn't create a 0 byte file)
// From the time this file is created(opened) until it is uploaded(flush), it
// will have a Stat cache with the No truncate flag added.
// This avoids file not existing errors in operations such as chmod and utimens
// that occur in the short period before file upload.
// Besides this, we also need to support readdir(list_bucket), this method is
// called to maintain the cache for readdir and return its value.
//
// [NOTE]
// Add the file names under parentdir to the list.
// However, if the same file name exists in the list, it will not be added.
// parentdir must be terminated with a '/'.
//
bool StatCache::GetNotruncateCache(const std::string& parentdir, notruncate_filelist_t& list)
{
    if(parentdir.empty()){
        return false;
    }

    std::string dirpath = parentdir;
    if('/' != *dirpath.rbegin()){
        dirpath += '/';
    }

    const std::lock_guard<std::mutex> lock(StatCache::stat_cache_lock);

    auto iter = notruncate_file_cache.find(dirpath);
    if(iter == notruncate_file_cache.cend()){
        // not found directory map
        return true;
    }

}