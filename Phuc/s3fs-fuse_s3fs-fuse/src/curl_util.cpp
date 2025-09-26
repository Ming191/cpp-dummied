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

//#include <cstdio>
//#include <cstdlib>
//#include <curl/curl.h>
//#include <string>

#include "common.h"
#include "s3fs_logger.h"
#include "curl_util.h"
#include "string_util.h"
#include "s3fs_auth.h"
#include "s3fs_cred.h"

using namespace std::string_literals;

//-------------------------------------------------------------------
// Utility Functions
//-------------------------------------------------------------------
//
// curl_slist_sort_insert
// This function is like curl_slist_append function, but this adds data by a-sorting.
// Because AWS signature needs sorted header.
//
struct curl_slist* curl_slist_sort_insert(struct curl_slist* list, const char* key, const char* value)
{
}

struct curl_slist* curl_slist_remove(struct curl_slist* list, const char* key)
{
}

std::string get_sorted_header_keys(const struct curl_slist* list)
{
}

std::string get_header_value(const struct curl_slist* list, const std::string &key)
{
}

std::string get_canonical_headers(const struct curl_slist* list, bool only_amz)
{
}

// function for using global values
bool MakeUrlResource(const char* realpath, std::string& resourcepath, std::string& url)
{
    if(!realpath){
        return false;
    }
    resourcepath = urlEncodePath(service_path + S3fsCred::GetBucket() + realpath);
    url          = s3host + resourcepath;
    return true;
}

std::string prepare_url(const char* url)
{
    //S3FS_PRN_DBG("URL is %s", url);

    std::string uri;
    std::string hostname;
    std::string path;
    std::string url_str = url;
    std::string token = "/" + S3fsCred::GetBucket();
    size_t bucket_pos;
    size_t bucket_length = token.size();
    size_t uri_length = 0;

    if(!strncasecmp(url_str.c_str(), "https://", 8)){
        uri_length = 8;
    } else if(!strncasecmp(url_str.c_str(), "http://", 7)) {
        uri_length = 7;
    }
    uri  = url_str.substr(0, uri_length);
    bucket_pos = url_str.find(token, uri_length);

    if(!pathrequeststyle){
        hostname = S3fsCred::GetBucket() + "." + url_str.substr(uri_length, bucket_pos - uri_length);
        path = url_str.substr((bucket_pos + bucket_length));
    }else{
        hostname = url_str.substr(uri_length, bucket_pos - uri_length);
        std::string part = url_str.substr((bucket_pos + bucket_length));
        if('/' != part[0]){
            part = "/" + part;
        }
        path = "/" + S3fsCred::GetBucket() + part;
    }

    url_str = uri + hostname + path;

    //S3FS_PRN_DBG("URL changed is %s", url_str.c_str());

    return url_str;
}

bool make_md5_from_binary(const char* pstr, size_t length, std::string& md5)
{
    if(!pstr || '\0' == pstr[0]){
        //S3FS_PRN_ERR("Parameter is wrong.");
        return false;
    }
}

std::string url_to_host(const std::string &url)
{
    static constexpr char HTTP[] = "http://";
    static constexpr char HTTPS[] = "https://";
    std::string hostname;

    if (is_prefix(url.c_str(), HTTP)) {
        hostname = url.substr(sizeof(HTTP) - 1);
    } else if (is_prefix(url.c_str(), HTTPS)) {
        hostname = url.substr(sizeof(HTTPS) - 1);
    } else {

    }
}

std::string get_bucket_host()
{
    if(!pathrequeststyle){
        return S3fsCred::GetBucket() + "." + url_to_host(s3host);
    }
    return url_to_host(s3host);
}

const char* getCurlDebugHead(curl_infotype type)
{
    const char* unknown = "";
    const char* dataIn  = "BODY <";
    const char* dataOut = "BODY >";
    const char* headIn  = "<";
    const char* headOut = ">";

    switch(type){
        case CURLINFO_DATA_IN:
            return dataIn;
        case CURLINFO_HEADER_IN:
            return headIn;
        case CURLINFO_HEADER_OUT:
            return headOut;
        default:
            break;
    }
    return unknown;
}

//
// compare ETag ignoring quotes and case
//
bool etag_equals(const std::string& s1, const std::string& s2)
{
}

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: expandtab sw=4 ts=4 fdm=marker
* vim<600: expandtab sw=4 ts=4
*/
