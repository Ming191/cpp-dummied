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

//#include <sstream>
#include "dummy.h"

#include "common.h"
#include "s3fs.h"
#include "s3fs_threadreqs.h"
#include "threadpoolman.h"
#include "curl_util.h"
#include "s3fs_logger.h"
#include "s3fs_util.h"
#include "s3fs_xml.h"
#include "cache.h"
#include "string_util.h"

//-------------------------------------------------------------------
// Thread Worker functions for MultiThread Request
//-------------------------------------------------------------------
//
// Thread Worker function for head request
//
void* head_req_threadworker(S3fsCurl& s3fscurl, void* arg)
{
}

//
// Thread Worker function for multi head request
//
void* multi_head_req_threadworker(S3fsCurl& s3fscurl, void* arg)
{
}

//
// Thread Worker function for delete request
//
void* delete_req_threadworker(S3fsCurl& s3fscurl, void* arg)
{

}

//
// Thread Worker function for put head request
//
void* put_head_req_threadworker(S3fsCurl& s3fscurl, void* arg)
{

}

//
// Thread Worker function for put request
//
void* put_req_threadworker(S3fsCurl& s3fscurl, void* arg)
{
}

//
// Thread Worker function for list bucket request
//
void* list_bucket_req_threadworker(S3fsCurl& s3fscurl, void* arg)
{
}

//
// Thread Worker function for check service request
//
void* check_service_req_threadworker(S3fsCurl& s3fscurl, void* arg)
{

}

//
// Worker function for pre multipart upload request
//
void* pre_multipart_upload_req_threadworker(S3fsCurl& s3fscurl, void* arg)
{
}

//
// Worker function for pre multipart upload part request
//
void* multipart_upload_part_req_threadworker(S3fsCurl& s3fscurl, void* arg)
{
}

//
// Worker function for complete multipart upload request
//
void* complete_multipart_upload_threadworker(S3fsCurl& s3fscurl, void* arg)
{
}

//
// Worker function for abort multipart upload request
//
void* abort_multipart_upload_req_threadworker(S3fsCurl& s3fscurl, void* arg)
{
}

//
// Thread Worker function for get object request
//
void* get_object_req_threadworker(S3fsCurl& s3fscurl, void* arg)
{
}

//
// Thread Worker function for multipart put head request
//
void* multipart_put_head_req_threadworker(S3fsCurl& s3fscurl, void* arg)
{
}

//
// Thread Worker function for parallel get object request
//
void* parallel_get_object_req_threadworker(S3fsCurl& s3fscurl, void* arg)
{
}

//-------------------------------------------------------------------
// Utility functions
//-------------------------------------------------------------------
//
// Calls S3fsCurl::HeadRequest via head_req_threadworker
//
int head_request(const std::string& strpath, headers_t& header)
{

    return 0;
}

//
// Calls S3fsCurl::HeadRequest via multi_head_req_threadworker
//
int multi_head_request(const std::string& strpath, SyncFiller& syncfiller, std::mutex& thparam_lock, int& retrycount, s3obj_list_t& notfound_list, bool use_wtf8, int& result, Semaphore& sem)
{

    return 0;
}

//
// Calls S3fsCurl::DeleteRequest via delete_req_threadworker
//
int delete_request(const std::string& strpath)
{
    return 0;
}

//
// Calls S3fsCurl::PutHeadRequest via put_head_req_threadworker
//
int put_head_request(const std::string& strpath, const headers_t& meta, bool is_copy)
{

    return 0;
}

//
// Calls S3fsCurl::PutRequest via put_req_threadworker
//
int put_request(const std::string& strpath, const headers_t& meta, int fd, bool ahbe)
{

    return 0;
}

//
// Calls S3fsCurl::ListBucketRequest via list_bucket_req_threadworker
//
int list_bucket_request(const std::string& strpath, const std::string& query, std::string& responseBody)
{

    return 0;
}

//
// Calls S3fsCurl::CheckBucket via check_service_req_threadworker
//
int check_service_request(const std::string& strpath, bool forceNoSSE, bool support_compat_dir, long& responseCode, std::string& responseBody)
{

    return 0;
}

//
// Calls S3fsCurl::PreMultipartUploadRequest via pre_multipart_upload_req_threadworker
//
// [NOTE]
// If the request is successful, sets upload_id.
//
int pre_multipart_upload_request(const std::string& path, const headers_t& meta, std::string& upload_id)
{

    return 0;
}

//
// Calls S3fsCurl::MultipartUploadPartRequest via multipart_upload_part_req_threadworker
//
int multipart_upload_part_request(const std::string& path, int upload_fd, off_t start, off_t size, int part_num, const std::string& upload_id, etagpair* petag, bool is_copy, Semaphore* psem, std::mutex* pthparam_lock, int* req_result)
{

    return 0;
}

//
// Calls and Await S3fsCurl::MultipartUploadPartRequest via multipart_upload_part_req_threadworker
//
int await_multipart_upload_part_request(const std::string& path, int upload_fd, off_t start, off_t size, int part_num, const std::string& upload_id, etagpair* petag, bool is_copy)
{

    return 0;
}

//
// Complete sequence of Multipart Upload Requests processing
//
// Call the following function:
//      pre_multipart_upload_request()
//      multipart_upload_part_request()
//      abort_multipart_upload_request()
//      complete_multipart_upload_request()
//
int multipart_upload_request(const std::string& path, const headers_t& meta, int upload_fd)
{
    return 0;
}

//
// Complete sequence of Mix Multipart Upload Requests processing
//
// Call the following function:
//      pre_multipart_upload_request()
//      multipart_upload_part_request()
//      abort_multipart_upload_request()
//      complete_multipart_upload_request()
//
int mix_multipart_upload_request(const std::string& path, headers_t& meta, int upload_fd, const fdpage_list_t& mixuppages)
{
}

//
// Calls S3fsCurl::MultipartUploadComplete via complete_multipart_upload_threadworker
//
int complete_multipart_upload_request(const std::string& path, const std::string& upload_id, const etaglist_t& parts)
{

    return 0;
}

//
// Calls S3fsCurl::AbortMultipartUpload via abort_multipart_upload_req_threadworker
//
int abort_multipart_upload_request(const std::string& path, const std::string& upload_id)
{

    return 0;
}

//
// Calls S3fsCurl::MultipartPutHeadRequest via multipart_put_head_req_threadworker
//
int multipart_put_head_request(const std::string& strfrom, const std::string& strto, off_t size, const headers_t& meta)
{
    return 0;
}

//
// Calls S3fsCurl::ParallelGetObjectRequest via parallel_get_object_req_threadworker
//
int parallel_get_object_request(const std::string& path, int fd, off_t start, off_t size)
{
    return 0;
}

//
// Calls S3fsCurl::GetObjectRequest via get_object_req_threadworker
//
int get_object_request(const std::string& path, int fd, off_t start, off_t size)
{
    return 0;
}

//-------------------------------------------------------------------
// Direct Call Utility Functions
//-------------------------------------------------------------------
// These functions (mainly IAM token-related) are not called from
// a thread.
//
// [NOTE]
// The request for IAM token calls are called from S3fsCurl::RequestPerform
// method if the IAM token needs to be updated during each request
// processing. (NOTE: Each request is already executed in a thread.)
// If the number of threads has reached the limit when these functions
// are called, they will block until a thread that can execute this
// process is found.
// This may result in all processing being blocked.
// Therefore, the following functions(IAM token requests) will not be
// processed by a thread worker, but will process the request directly.
//
// If it is a different request called from within a thread worker,
// please process it like this.
//

//
// Directly calls S3fsCurl::GetIAMv2ApiToken
//
int get_iamv2api_token_request(const std::string& strurl, int tokenttl, const std::string& strttlhdr, std::string& token)
{

}

//
// Directly calls S3fsCurl::GetIAMRoleFromMetaData
//
int get_iamrole_request(const std::string& strurl, const std::string& striamtoken, std::string& token)
{
}

//
// Directly calls S3fsCurl::GetIAMCredentials
//
int get_iamcred_request(const std::string& strurl, const std::string& striamtoken, const std::string& stribmsecret, std::string& cred)
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
