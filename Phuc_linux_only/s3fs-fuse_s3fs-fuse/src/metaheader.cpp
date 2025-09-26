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

//#include <ctime>
//#include <string>
//#include <sys/stat.h>
//#include <unistd.h>

#include "common.h"
#include "metaheader.h"
#include "string_util.h"
#include "s3fs_util.h"

static constexpr struct timespec DEFAULT_TIMESPEC = {-1, 0};

//-------------------------------------------------------------------
// Utility functions for convert
//-------------------------------------------------------------------
static struct timespec cvt_string_to_time(const char *str)
{
    std::string strmtime;
    long nsec = 0;
    if(str && '\0' != *str){
        strmtime = str;
        std::string::size_type pos = strmtime.find('.', 0);
        if(std::string::npos != pos){
            nsec = cvt_strtoofft(strmtime.substr(pos + 1).c_str(), /*base=*/ 10);
            strmtime.erase(pos);
        }
    }
    struct timespec ts = {static_cast<time_t>(cvt_strtoofft(strmtime.c_str(), /*base=*/ 10)), nsec};
    return ts;
}

static struct timespec get_time(const headers_t& meta, const char *header)
{
    headers_t::const_iterator iter;
    if(meta.cend() == (iter = meta.find(header))){
        return DEFAULT_TIMESPEC;
    }
    return cvt_string_to_time((*iter).second.c_str());
}

struct timespec get_mtime(const headers_t& meta, bool overcheck)
{
    struct timespec t = get_time(meta, "x-amz-meta-mtime");
    if(0 < t.tv_sec){
        return t;
    }
    t = get_time(meta, "x-amz-meta-goog-reserved-file-mtime");
    if(0 < t.tv_sec){
        return t;
    }
    if(overcheck){
        struct timespec ts = {get_lastmodified(meta), 0};
        return ts;
    }
    return DEFAULT_TIMESPEC;
}

struct timespec get_ctime(const headers_t& meta, bool overcheck)
{
    struct timespec t = get_time(meta, "x-amz-meta-ctime");
    if(0 < t.tv_sec){
        return t;
    }
    if(overcheck){
        struct timespec ts = {get_lastmodified(meta), 0};
        return ts;
    }
    return DEFAULT_TIMESPEC;
}

struct timespec get_atime(const headers_t& meta, bool overcheck)
{
    struct timespec t = get_time(meta, "x-amz-meta-atime");
    if(0 < t.tv_sec){
        return t;
    }
    if(overcheck){
        struct timespec ts = {get_lastmodified(meta), 0};
        return ts;
    }
    return DEFAULT_TIMESPEC;
}

off_t get_size(const char *s)
{
}

off_t get_size(const headers_t& meta)
{
}

mode_t get_mode(const char *s, int base)
{
}

mode_t get_mode(const headers_t& meta, const std::string& strpath, bool checkdir, bool forcedir)
{}

uid_t get_uid(const char *s)
{
}

uid_t get_uid(const headers_t& meta)
{
}

gid_t get_gid(const char *s)
{
}

gid_t get_gid(const headers_t& meta)
{
}

blkcnt_t get_blocks(off_t size)
{
}

time_t cvtIAMExpireStringToTime(const char* s)
{
    struct tm tm{};
    if(!s){
        return 0L;
    }
}

time_t get_lastmodified(const char* s)
{
    struct tm tm{};
    if(!s){
        return -1;
    }
}

time_t get_lastmodified(const headers_t& meta)
{
    auto iter = meta.find("Last-Modified");
    if(meta.cend() == iter){
        return -1;
    }
}

//
// Returns it whether it is an object with need checking in detail.
// If this function returns true, the object is possible to be directory
// and is needed checking detail(searching sub object).
//
bool is_need_check_obj_detail(const headers_t& meta)
{
}

// [NOTE]
// If add_noexist is false and the key does not exist, it will not be added.
//
bool merge_headers(headers_t& base, const headers_t& additional, bool add_noexist)
{
}

bool convert_header_to_stat(const char* path, const headers_t& meta, struct stat* pst, bool forcedir)
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
