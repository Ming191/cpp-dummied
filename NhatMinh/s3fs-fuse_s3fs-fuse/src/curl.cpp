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
//#include <cstdio>
//#include <cstdlib>
//#include <ctime>
//#include <fstream>
//#include <memory>
//#include <mutex>
//#include <sstream>
//#include <string>
//#include <unistd.h>
//#include <utility>
#include "dummy.h"
#include "common.h"
#include "s3fs.h"
#include "s3fs_logger.h"
#include "curl.h"
#include "curl_share.h"
#include "curl_util.h"
#include "s3fs_auth.h"
#include "s3fs_cred.h"
#include "s3fs_util.h"
#include "string_util.h"
#include "addhead.h"
#include "s3fs_threadreqs.h"
#include "s3fs_xml.h"

//-------------------------------------------------------------------
// Symbols
//-------------------------------------------------------------------
static constexpr char EMPTY_PAYLOAD_HASH[]              = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";
static constexpr char EMPTY_MD5_BASE64_HASH[]           = "1B2M2Y8AsgTpgAmY7PhCfg==";

//-------------------------------------------------------------------
// Class S3fsCurl
//-------------------------------------------------------------------
static constexpr int MULTIPART_SIZE                     = 10 * 1024 * 1024;
static constexpr int GET_OBJECT_RESPONSE_LIMIT          = 1024;

// [NOTE] about default mime.types file
// If no mime.types file is specified in the mime option, s3fs
// will look for /etc/mime.types on all operating systems and
// load mime information.
// However, in the case of macOS, when this file does not exist,
// it tries to detect the /etc/apache2/mime.types file.
// The reason for this is that apache2 is preinstalled on macOS,
// and the mime.types file is expected to exist in this path.
// If the mime.types file is not found, s3fs will exit with an
// error.
//
static constexpr char DEFAULT_MIME_FILE[]               = "/etc/mime.types";
static constexpr char SPECIAL_DARWIN_MIME_FILE[]        = "/etc/apache2/mime.types";

// [NOTICE]
// This symbol is for libcurl under 7.23.0
#ifndef CURLSHE_NOT_BUILT_IN
#define CURLSHE_NOT_BUILT_IN                        5
#endif

#if LIBCURL_VERSION_NUM >= 0x073100
#define S3FS_CURLOPT_XFERINFOFUNCTION   CURLOPT_XFERINFOFUNCTION
#else
#define S3FS_CURLOPT_XFERINFOFUNCTION   CURLOPT_PROGRESSFUNCTION
#endif

// Wrappers to pass std::unique_ptr to raw pointer functions.  Undefine curl_easy_setopt to work around curl variadic argument macro.
#undef curl_easy_setopt
// template<typename Arg> CURLcode curl_easy_setopt(const CurlUniquePtr& handle, CURLoption option, Arg arg) {
//     return curl_easy_setopt(handle.get(), option, arg);
// }

// template<typename Arg> CURLcode curl_easy_getinfo(const CurlUniquePtr& handle, CURLINFO info, Arg arg) {
//     return curl_easy_getinfo(handle.get(), info, arg);
// }

//-------------------------------------------------------------------
// Class S3fsCurl
//-------------------------------------------------------------------
constexpr char   S3fsCurl::S3FS_SSL_PRIVKEY_PASSWORD[];
std::mutex       S3fsCurl::curl_handles_lock;
S3fsCurl::callback_locks_t S3fsCurl::callback_locks;
bool             S3fsCurl::is_initglobal_done  = false;
bool             S3fsCurl::is_cert_check       = true; // default
long             S3fsCurl::connect_timeout     = 300;  // default
time_t           S3fsCurl::readwrite_timeout   = 120;  // default
int              S3fsCurl::retries             = 5;    // default
bool             S3fsCurl::is_public_bucket    = false;
acl_t            S3fsCurl::default_acl         = acl_t::PRIVATE;
std::string      S3fsCurl::storage_class       = "STANDARD";
sseckeylist_t    S3fsCurl::sseckeys;
std::string      S3fsCurl::ssekmsid;
sse_type_t       S3fsCurl::ssetype             = sse_type_t::SSE_DISABLE;
bool             S3fsCurl::is_content_md5      = false;
bool             S3fsCurl::is_verbose          = false;
bool             S3fsCurl::is_dump_body        = false;
S3fsCred*        S3fsCurl::ps3fscred           = nullptr;
long             S3fsCurl::ssl_verify_hostname = 1;    // default(original code...)
// SSL client cert options
std::string      S3fsCurl::client_cert;
std::string      S3fsCurl::client_cert_type;
std::string      S3fsCurl::client_priv_key;
std::string      S3fsCurl::client_priv_key_type;
std::string      S3fsCurl::client_key_password;

std::atomic<bool> S3fsCurl::curl_warnings_once(false);

// protected by curl_handles_lock
std::map<const CURL*, curlprogress> S3fsCurl::curl_progress;

std::string      S3fsCurl::curl_ca_bundle;
mimes_t          S3fsCurl::mimeTypes;
std::string      S3fsCurl::userAgent;
off_t            S3fsCurl::multipart_size      = MULTIPART_SIZE; // default
off_t            S3fsCurl::multipart_copy_size = 512 * 1024 * 1024;  // default
signature_type_t S3fsCurl::signature_type      = signature_type_t::V2_OR_V4;       // default
bool             S3fsCurl::is_unsigned_payload = false;          // default
bool             S3fsCurl::is_ua               = true;           // default
bool             S3fsCurl::listobjectsv2       = false;          // default
bool             S3fsCurl::requester_pays      = false;          // default
std::string      S3fsCurl::proxy_url;
bool             S3fsCurl::proxy_http          = false;
std::string      S3fsCurl::proxy_userpwd;
long             S3fsCurl::ipresolve_type      = CURL_IPRESOLVE_WHATEVER;

//-------------------------------------------------------------------
// Class methods for S3fsCurl
//-------------------------------------------------------------------
bool S3fsCurl::InitS3fsCurl()
{
    if(!S3fsCurl::InitGlobalCurl()){
        return false;
    }
    if(!S3fsCurl::InitCryptMutex()){
        return false;
    }
    return true;
}

bool S3fsCurl::DestroyS3fsCurl()
{
    bool result = true;

    if(!S3fsCurl::DestroyCryptMutex()){
        result = false;
    }
    if(!S3fsCurl::DestroyGlobalCurl()){
        result = false;
    }
    return result;
}

bool S3fsCurl::InitGlobalCurl()
{
    if(S3fsCurl::is_initglobal_done){
        return false;
    }
}

bool S3fsCurl::DestroyGlobalCurl()
{
    if(!S3fsCurl::is_initglobal_done){
        return false;
    }
    // curl_global_cleanup();
    S3fsCurl::is_initglobal_done = false;
    return true;
}

bool S3fsCurl::InitCryptMutex()
{
}

bool S3fsCurl::DestroyCryptMutex()
{
}

// homegrown timeout mechanism
int S3fsCurl::CurlProgress(void *clientp, double dltotal, double dlnow, double ultotal, double ulnow)
{
    CURL*      curl = static_cast<CURL*>(clientp);
    time_t     now = time(nullptr);

    const std::lock_guard<std::mutex> lock(S3fsCurl::curl_handles_lock);

    // any progress?
    auto& value = S3fsCurl::curl_progress[curl];
    if(value.dl_progress != dlnow || value.ul_progress != ulnow){
        // yes!
        value = {now, dlnow, ulnow};
    }else{
        // timeout?
        if(now - value.time > readwrite_timeout){
            //S3FS_PRN_ERR("timeout now: %lld, curl_times[curl]: %lld, readwrite_timeout: %lld",
            return CURLE_ABORTED_BY_CALLBACK;
        }
    }
    return 0;
}

bool S3fsCurl::InitCredentialObject(S3fsCred* pcredobj)
{
    // Set the only Credential object
    if(!pcredobj || S3fsCurl::ps3fscred){
        //S3FS_PRN_ERR("Unable to set the only Credential object.");
        return false;
    }
    S3fsCurl::ps3fscred = pcredobj;

    return true;
}

bool S3fsCurl::InitMimeType(const std::string& strFile)
{
    std::string MimeFile;
    if(!strFile.empty()){
        MimeFile = strFile;
    }else{
        if(MimeFile.empty()){
            //S3FS_PRN_WARN("Could not find mime.types files, you have to create file(%s) or specify mime option for existing mime.types file.", errPaths.c_str());
            return false;
        }
    }
    //S3FS_PRN_DBG("Try to load mime types from %s file.", MimeFile.c_str());
    return true;
}

void S3fsCurl::InitUserAgent()
{
    if(S3fsCurl::userAgent.empty()){
    }
}

//
// @param s e.g., "index.html"
// @return e.g., "text/html"
//
std::string S3fsCurl::LookupMimeType(const std::string& name)
{
    if(!name.empty() && name[name.size() - 1] == '/'){
        return "application/x-directory";
    }

    std::string            result("application/octet-stream");
    std::string::size_type last_pos  = name.find_last_of('.');
    std::string::size_type first_pos = name.find_first_of('.');
    std::string            prefix, ext, ext2;

    // No dots in name, just return
    if(last_pos == std::string::npos){
        return result;
    }
    // extract the last extension
    ext = name.substr(1+last_pos, std::string::npos);

    if (last_pos != std::string::npos) {
        // one dot was found, now look for another
        if (first_pos != std::string::npos && first_pos < last_pos) {
            prefix = name.substr(0, last_pos);
            // Now get the second to last file extension
            std::string::size_type next_pos = prefix.find_last_of('.');
            if (next_pos != std::string::npos) {
                ext2 = prefix.substr(1+next_pos, std::string::npos);
            }
        }
    }

    // if we get here, then we have an extension (ext)
    auto iter = S3fsCurl::mimeTypes.find(ext);
    // if the last extension matches a mimeType, then return
    // that mime type
    if (iter != S3fsCurl::mimeTypes.cend()) {
        result = (*iter).second;
        return result;
    }

    // return with the default result if there isn't a second extension
    if(first_pos == last_pos){
        return result;
    }

    // Didn't find a mime-type for the first extension
    // Look for second extension in mimeTypes, return if found
    iter = S3fsCurl::mimeTypes.find(ext2);
    if (iter != S3fsCurl::mimeTypes.cend()) {
        result = (*iter).second;
        return result;
    }

    // neither the last extension nor the second-to-last extension
    // matched a mimeType, return the default mime type 
    return result;
}

bool S3fsCurl::LocateBundle()
{
    // See if environment variable CURL_CA_BUNDLE is set

    // not set via environment variable, look in likely locations

    ///////////////////////////////////////////
    // following comment from curl's (7.21.2) acinclude.m4 file
    ///////////////////////////////////////////
    // dnl CURL_CHECK_CA_BUNDLE
    // dnl -------------------------------------------------
    // dnl Check if a default ca-bundle should be used
    // dnl
    // dnl regarding the paths this will scan:
    // dnl /etc/ssl/certs/ca-certificates.crt Debian systems
    // dnl /etc/pki/tls/certs/ca-bundle.crt Redhat and Mandriva
    // dnl /usr/share/ssl/certs/ca-bundle.crt old(er) Redhat
    // dnl /usr/local/share/certs/ca-root.crt FreeBSD
    // dnl /etc/ssl/cert.pem OpenBSD
    // dnl /etc/ssl/certs/ (ca path) SUSE
    ///////////////////////////////////////////
    // Within CURL the above path should have been checked
    // according to the OS. Thus, although we do not need
    // to check files here, we will only examine some files.
    //
    return true;
}

size_t S3fsCurl::WriteMemoryCallback(void* ptr, size_t blockSize, size_t numBlocks, void* data)
{
    auto* body  = static_cast<std::string*>(data);
    body->append(static_cast<const char*>(ptr), blockSize * numBlocks);
    return (blockSize * numBlocks);
}

size_t S3fsCurl::ReadCallback(void* ptr, size_t size, size_t nmemb, void* userp)
{
    auto* pCurl = static_cast<S3fsCurl*>(userp);

    if(1 > (size * nmemb)){
        return 0;
    }
    if(0 >= pCurl->postdata_remaining){
        return 0;
    }
}

size_t S3fsCurl::HeaderCallback(void* data, size_t blockSize, size_t numBlocks, void* userPtr)
{
}

size_t S3fsCurl::UploadReadCallback(void* ptr, size_t size, size_t nmemb, void* userp)
{
}

size_t S3fsCurl::DownloadWriteCallback(void* ptr, size_t size, size_t nmemb, void* userp)
{
}

bool S3fsCurl::SetCheckCertificate(bool isCertCheck)
{
}

void S3fsCurl::ResetOffset(S3fsCurl* pCurl)
{
}

long S3fsCurl::SetConnectTimeout(long timeout)
{
}

time_t S3fsCurl::SetReadwriteTimeout(time_t timeout)
{
}

int S3fsCurl::SetRetries(int count)
{
}

int S3fsCurl::GetRetries()
{
}

bool S3fsCurl::SetPublicBucket(bool flag)
{
}

acl_t S3fsCurl::SetDefaultAcl(acl_t acl)
{
}

acl_t S3fsCurl::GetDefaultAcl()
{
}

std::string S3fsCurl::SetStorageClass(const std::string& storage_class)
{
}

bool S3fsCurl::PushbackSseKeys(const std::string& input)
{
    std::string onekey = trim(input);
    if(onekey.empty()){
        return false;
    }
    if('#' == onekey[0]){
        return false;
    }
    // make base64 if the key is short enough, otherwise assume it is already so
    std::string base64_key;
    std::string raw_key;
    if(onekey.length() > 256 / 8){
        std::string p_key(s3fs_decode64(onekey.c_str(), onekey.size()));
        raw_key = p_key;
        base64_key = onekey;
    } else {
        base64_key = s3fs_base64(reinterpret_cast<const unsigned char*>(onekey.c_str()), onekey.length());
        raw_key = onekey;
    }

    // make MD5
    std::string strMd5;
    if(!make_md5_from_binary(raw_key.c_str(), raw_key.length(), strMd5)){
        //S3FS_PRN_ERR("Could not make MD5 from SSE-C keys(%s).", raw_key.c_str());
        return false;
    }

    return true;
}

sse_type_t S3fsCurl::SetSseType(sse_type_t type)
{
}

bool S3fsCurl::SetSseCKeys(const char* filepath)
{
    if(!filepath){
        return false;
    }
}

bool S3fsCurl::SetSseKmsid(const char* kmsid)
{
    if(!kmsid || '\0' == kmsid[0]){
    }
}

// [NOTE]
// Because SSE is set by some options and environment, 
// this function check the integrity of the SSE data finally.
bool S3fsCurl::FinalCheckSse()
{
    switch(S3fsCurl::ssetype){
        case sse_type_t::SSE_DISABLE:
            S3fsCurl::ssekmsid.clear();
            return true;
        case sse_type_t::SSE_S3:
            S3fsCurl::ssekmsid.clear();
            return true;
        case sse_type_t::SSE_C:
            if(S3fsCurl::sseckeys.empty()){
                //S3FS_PRN_ERR("sse type is SSE-C, but there is no custom key.");
                return false;
            }
            S3fsCurl::ssekmsid.clear();
            return true;
        case sse_type_t::SSE_KMS:
            if(S3fsCurl::ssekmsid.empty()){
                //S3FS_PRN_ERR("sse type is SSE-KMS, but there is no specified kms id.");
                return false;
            }
            if(S3fsCurl::GetSignatureType() == signature_type_t::V2_ONLY){
                //S3FS_PRN_ERR("sse type is SSE-KMS, but signature type is not v4. SSE-KMS require signature v4.");
                return false;
            }

            // SSL/TLS is required for KMS
            //
            if(!is_prefix(s3host.c_str(), "https://")){
                //S3FS_PRN_ERR("The sse type is SSE-KMS, but it is not configured to use SSL/TLS. SSE-KMS requires SSL/TLS communication.");
                return false;
            }
            return true;
    }
    //S3FS_PRN_ERR("sse type is unknown(%d).", static_cast<int>(S3fsCurl::ssetype));

    return false;
}
                                                                                                                                                   
bool S3fsCurl::LoadEnvSseCKeys()
{
}

bool S3fsCurl::LoadEnvSseKmsid()
{

}

//
// If md5 is empty, returns first(current) sse key.
//
bool S3fsCurl::GetSseKey(std::string& md5, std::string& ssekey)
{
}

bool S3fsCurl::GetSseKeyMd5(size_t pos, std::string& md5)
{
}

size_t S3fsCurl::GetSseKeyCount()
{
}

bool S3fsCurl::SetContentMd5(bool flag)
{
    bool old = S3fsCurl::is_content_md5;
    S3fsCurl::is_content_md5 = flag;
    return old;
}

bool S3fsCurl::SetVerbose(bool flag)
{
    bool old = S3fsCurl::is_verbose;
    S3fsCurl::is_verbose = flag;
    return old;
}

bool S3fsCurl::SetDumpBody(bool flag)
{
    bool old = S3fsCurl::is_dump_body;
    S3fsCurl::is_dump_body = flag;
    return old;
}

long S3fsCurl::SetSslVerifyHostname(long value)
{
    if(0 != value && 1 != value){
        return -1;
    }
    long old = S3fsCurl::ssl_verify_hostname;
    S3fsCurl::ssl_verify_hostname = value;
    return old;
}

bool S3fsCurl::SetSSLClientCertOptions(const std::string& values)
{
    return true;
}

bool S3fsCurl::SetMultipartSize(off_t size)
{
    size = size * 1024 * 1024;
    if(size < MIN_MULTIPART_SIZE){
        return false;
    }
    S3fsCurl::multipart_size = size;
    return true;
}

bool S3fsCurl::SetMultipartCopySize(off_t size)
{
    size = size * 1024 * 1024;
    if(size < MIN_MULTIPART_SIZE){
        return false;
    }
    S3fsCurl::multipart_copy_size = size;
    return true;
}

// [NOTE]
// This proxy setting is as same as the "--proxy" option of the curl command,
// and equivalent to the "CURLOPT_PROXY" option of the curl_easy_setopt()
// function.
// However, currently s3fs does not provide another option to set the schema
// and port, so you need to specify these it in this function. (Other than
// this function, there is no means of specifying the schema and port.)
// Therefore, it should be specified "url" as "[<schema>://]<fqdn>[:<port>]".
// s3fs passes this string to curl_easy_setopt() function with "CURLOPT_PROXY".
// If no "schema" is specified, "http" will be used as default, and if no port
// is specified, "443" will be used for "HTTPS" and "1080" otherwise.
// (See the description of "CURLOPT_PROXY" in libcurl document.)
//
bool S3fsCurl::SetProxy(const char* url)
{
    if(!url || '\0' == url[0]){
        return false;
    }
    std::string tmpurl = url;

    // check schema
    bool   is_http = true;
    size_t pos = 0;
    if(std::string::npos != (pos = tmpurl.find("://", pos))){
        if(0 == pos){
            // no schema string before "://"
            return false;
        }
        pos += strlen("://");

        // Check if it is other than "http://"
        if(0 != tmpurl.find("http://", 0)){
            is_http = false;
        }
    }else{
        // not have schema string
        pos = 0;
    }
}

// [NOTE]
// This function loads proxy credentials(username and  passphrase)
// from a file.
// The loaded values is set to "CURLOPT_PROXYUSERPWD" in the
// curl_easy_setopt() function. (But only used if the proxy is HTTP
// schema.)
//
// The file is expected to contain only one valid line:
//     ------------------------
//     # comment line
//     <username>:<passphrase>
//     ------------------------
// Lines starting with a '#' character are treated as comments.
// Lines with only space characters and blank lines are ignored.
// If the user name contains spaces, it must be url encoded(ex. %20).
//
bool S3fsCurl::SetProxyUserPwd(const char* file)
{
    if(!file || '\0' == file[0]){
        return false;
    }
    std::string filepath = file;

}

bool S3fsCurl::SetIPResolveType(const char* value)
{
    if(!value){
        return false;
    }
    if(0 == strcasecmp(value, "ipv4")){
        S3fsCurl::ipresolve_type = CURL_IPRESOLVE_V4;
    }else if(0 == strcasecmp(value, "ipv6")){
        S3fsCurl::ipresolve_type = CURL_IPRESOLVE_V6;
    }else if(0 == strcasecmp(value, "whatever")){       // = default type
        S3fsCurl::ipresolve_type = CURL_IPRESOLVE_WHATEVER;
    }else{
        return false;
    }
    return true;
}

int S3fsCurl::MapPutErrorResponse(int result) const
{
    if(result != 0){
        return result;
    }
    // PUT returns 200 status code with something error, thus
    // we need to check body.
    //
    // example error body:
    //     <?xml version="1.0" encoding="UTF-8"?>
    //     <Error>
    //       <Code>AccessDenied</Code>
    //       <Message>Access Denied</Message>
    //       <RequestId>E4CA6F6767D6685C</RequestId>
    //       <HostId>BHzLOATeDuvN8Es1wI8IcERq4kl4dc2A9tOB8Yqr39Ys6fl7N4EJ8sjGiVvu6wLP</HostId>
    //     </Error>
    //
}

bool S3fsCurl::MultipartUploadPartSetCurlOpts(S3fsCurl* s3fscurl)
{
}

bool S3fsCurl::CopyMultipartUploadSetCurlOpts(S3fsCurl* s3fscurl)
{
}

bool S3fsCurl::PreGetObjectRequestSetCurlOpts(S3fsCurl* s3fscurl)
{
}

bool S3fsCurl::PreHeadRequestSetCurlOpts(S3fsCurl* s3fscurl)
{
}

// bool S3fsCurl::AddUserAgent(const CurlUniquePtr& hCurl)
// {
//     if(!hCurl){
//         return false;
//     }
//     if(S3fsCurl::IsUserAgentFlag()){
//         if(CURLE_OK != curl_easy_setopt(hCurl, CURLOPT_USERAGENT, S3fsCurl::userAgent.c_str())){
//             return false;
//         }
//     }
//     return true;
// }

int S3fsCurl::CurlDebugFunc(const CURL* hcurl, curl_infotype type, char* data, size_t size, void* userptr)
{
    return S3fsCurl::RawCurlDebugFunc(hcurl, type, data, size, userptr, CURLINFO_END);
}

int S3fsCurl::CurlDebugBodyInFunc(const CURL* hcurl, curl_infotype type, char* data, size_t size, void* userptr)
{
    return S3fsCurl::RawCurlDebugFunc(hcurl, type, data, size, userptr, CURLINFO_DATA_IN);
}

int S3fsCurl::CurlDebugBodyOutFunc(const CURL* hcurl, curl_infotype type, char* data, size_t size, void* userptr)
{
    return S3fsCurl::RawCurlDebugFunc(hcurl, type, data, size, userptr, CURLINFO_DATA_OUT);
}

int S3fsCurl::RawCurlDebugFunc(const CURL* hcurl, curl_infotype type, char* data, size_t size, void* userptr, curl_infotype datatype)
{
}

//-------------------------------------------------------------------
// Methods for S3fsCurl
//-------------------------------------------------------------------
S3fsCurl::S3fsCurl(bool ahbe)
{
    if(!S3fsCurl::ps3fscred){

    }
}

S3fsCurl::~S3fsCurl()
{
    DestroyCurlHandle();
}

bool S3fsCurl::ResetHandle()
{
    return true;
}

bool S3fsCurl::CreateCurlHandle(bool remake)
{
    return true;
}

bool S3fsCurl::DestroyCurlHandle(bool clear_internal_data)
{
    const std::lock_guard<std::mutex> lock(S3fsCurl::curl_handles_lock);
    return DestroyCurlHandleHasLock(clear_internal_data);
}

bool S3fsCurl::DestroyCurlHandleHasLock(bool clear_internal_data)
{
    // [NOTE]
    // If type is REQTYPE::IAMCRED or REQTYPE::IAMROLE, do not clear type.
    // Because that type only uses HTTP protocol, then the special
    // logic in ResetHandle function.
    //
    if(type != REQTYPE::IAMCRED && type != REQTYPE::IAMROLE){
        type = REQTYPE::UNSET;
    }

    if(clear_internal_data){
        ClearInternalData();
    }
}

bool S3fsCurl::ClearInternalData()
{
}

bool S3fsCurl::SetUseAhbe(bool ahbe)
{
}

bool S3fsCurl::GetResponseCode(long& responseCode, bool from_curl_handle) const
{
}

//
// Reset all options for retrying
//
bool S3fsCurl::RemakeHandle()
{

}

//
// returns curl return code
//
int S3fsCurl::RequestPerform(bool dontAddAuthHeaders /*=false*/)
{
}

//
// Returns the Amazon AWS signature for the given parameters.
//
// @param method e.g., "GET"
// @param content_type e.g., "application/x-directory"
// @param date e.g., get_date_rfc850()
// @param resource e.g., "/pub"
//
std::string S3fsCurl::CalcSignatureV2(const std::string& method, const std::string& strMD5, const std::string& content_type, const std::string& date, const std::string& resource, const std::string& secret_access_key, const std::string& access_token)
{
    if(!access_token.empty()){
    }
}

std::string S3fsCurl::CalcSignature(const std::string& method, const std::string& canonical_uri, const std::string& query_string, const std::string& strdate, const std::string& payload_hash, const std::string& date8601, const std::string& secret_access_key, const std::string& access_token)
{
    std::string StringCQ, StringToSign;
    std::string uriencode;

    if(!access_token.empty()){
        requestHeaders = curl_slist_sort_insert(requestHeaders, "x-amz-security-token", access_token.c_str());
    }

    uriencode = urlEncodePath(canonical_uri);
    StringCQ  = method + "\n";
    if(method == "HEAD" || method == "PUT" || method == "DELETE"){
        StringCQ += uriencode + "\n";
    }else if(method == "GET" && uriencode.empty()){
        StringCQ +="/\n";
    }else if(method == "GET" && is_prefix(uriencode.c_str(), "/")){
        StringCQ += uriencode +"\n";
    }else if(method == "GET" && !is_prefix(uriencode.c_str(), "/")){
        StringCQ += "/\n" + urlEncodeQuery(canonical_uri) +"\n";
    }else if(method == "POST"){
        StringCQ += uriencode + "\n";
    }

}

std::string S3fsCurl::extractURI(const std::string& url) {
    // If the URL is empty, return "/"
    if (url.empty()) {
        return "/";
    }

    // Find the position of "://"
    std::size_t protocol_pos = url.find("://");
    if (protocol_pos == std::string::npos) {
        // If "://" is not found, return "/"
        return "/";
    }

    // Find the position of the first "/" after "://"
    std::size_t uri_pos = url.find('/', protocol_pos + 3);
    if (uri_pos == std::string::npos) {
        // If no "/" is found after the domain, return "/"
        return "/";
    }

    // Extract the URI
    std::string uri = url.substr(uri_pos);

    // Ensure the URI ends with "/"
    if (uri.back() != '/') {
        uri += '/';
    }

    return uri;
}

bool S3fsCurl::insertV4Headers(const std::string& access_key_id, const std::string& secret_access_key, const std::string& access_token)
{
    std::string server_path = type == REQTYPE::LISTBUCKET ? "/" : path;
    std::string payload_hash;
    switch (type) {
        case REQTYPE::PUT:
            if(GetUnsignedPayload()){
                payload_hash = "UNSIGNED-PAYLOAD";
            }else{
            }
            break;

        case REQTYPE::COMPLETEMULTIPOST:
            {
            }

        case REQTYPE::UPLOADMULTIPOST:
            if(GetUnsignedPayload()){
                payload_hash = "UNSIGNED-PAYLOAD";
            }else{
                payload_hash = s3fs_sha256_hex_fd(partdata.fd, partdata.startpos, partdata.size);
            }
            break;
        default:
            break;
    }


    //S3FS_PRN_DBG("computing signature [%s] [%s] [%s] [%s]", op.c_str(), server_path.c_str(), query_string.c_str(), payload_hash.c_str());
    std::string strdate;
    std::string date8601;
    get_date_sigv3(strdate, date8601);

    std::string contentSHA256 = payload_hash.empty() ? EMPTY_PAYLOAD_HASH : payload_hash;
    const std::string realpath = pathrequeststyle ? S3fsCurl::extractURI(s3host) + S3fsCred::GetBucket() + server_path : server_path;

    //string canonical_headers, signed_headers;
    requestHeaders = curl_slist_sort_insert(requestHeaders, "host", get_bucket_host().c_str());
    requestHeaders = curl_slist_sort_insert(requestHeaders, "x-amz-content-sha256", contentSHA256.c_str());
    requestHeaders = curl_slist_sort_insert(requestHeaders, "x-amz-date", date8601.c_str());

    if (S3fsCurl::IsRequesterPays()) {
        requestHeaders = curl_slist_sort_insert(requestHeaders, "x-amz-request-payer", "requester");
    }

    if(!S3fsCurl::IsPublicBucket()){
        std::string Signature = CalcSignature(op, realpath, query_string + (type == REQTYPE::PREMULTIPOST || type == REQTYPE::MULTILIST ? "=" : ""), strdate, contentSHA256, date8601, secret_access_key, access_token);
        std::string auth = "AWS4-HMAC-SHA256 Credential=" + access_key_id + "/" + strdate + "/" + region + "/s3/aws4_request, SignedHeaders=" + get_sorted_header_keys(requestHeaders) + ", Signature=" + Signature;
        requestHeaders = curl_slist_sort_insert(requestHeaders, "Authorization", auth.c_str());
    }

    return true;
}

void S3fsCurl::insertV2Headers(const std::string& access_key_id, const std::string& secret_access_key, const std::string& access_token)
{
    std::string resource;
    std::string turl;
    std::string server_path = type == REQTYPE::LISTBUCKET ? "/" : path;
    MakeUrlResource(server_path.c_str(), resource, turl);
    if(!query_string.empty() && type != REQTYPE::CHKBUCKET && type != REQTYPE::LISTBUCKET){
        resource += "?" + query_string;
    }

    std::string date = get_date_rfc850();
    requestHeaders = curl_slist_sort_insert(requestHeaders, "Date", date.c_str());
    if(op != "PUT" && op != "POST"){
        requestHeaders = curl_slist_sort_insert(requestHeaders, "Content-Type", nullptr);
    }

    if(!S3fsCurl::IsPublicBucket()){
        std::string Signature = CalcSignatureV2(op, get_header_value(requestHeaders, "Content-MD5"), get_header_value(requestHeaders, "Content-Type"), date, resource, secret_access_key, access_token);
        requestHeaders   = curl_slist_sort_insert(requestHeaders, "Authorization", ("AWS " + access_key_id + ":" + Signature).c_str());
    }
}

void S3fsCurl::insertIBMIAMHeaders(const std::string& access_key_id, const std::string& access_token)
{
    requestHeaders = curl_slist_sort_insert(requestHeaders, "Authorization", ("Bearer " + access_token).c_str());

    if(op == "PUT" && path == mount_prefix + "/"){
        // ibm-service-instance-id header is required for bucket creation requests
        requestHeaders = curl_slist_sort_insert(requestHeaders, "ibm-service-instance-id", access_key_id.c_str());
    }
}

bool S3fsCurl::insertAuthHeaders()
{
    std::string access_key_id;
    std::string secret_access_key;
    std::string access_token;

    // check and get credential variables
    if(!S3fsCurl::ps3fscred->CheckIAMCredentialUpdate(&access_key_id, &secret_access_key, &access_token)){
        //S3FS_PRN_ERR("An error occurred in checking IAM credential.");
        return false; // do not insert auth headers on error
    }

    if(S3fsCurl::ps3fscred->IsIBMIAMAuth()){
        insertIBMIAMHeaders(access_key_id, access_token);
    }else if(S3fsCurl::signature_type == signature_type_t::V2_ONLY){
        insertV2Headers(access_key_id, secret_access_key, access_token);
    }else{
        if(!insertV4Headers(access_key_id, secret_access_key, access_token)){
            return false;
        }
    }
    return true;
}

int S3fsCurl::DeleteRequest(const char* tpath)
{
    //S3FS_PRN_INFO3("[tpath=%s]", SAFESTRPTR(tpath));

    if(!tpath){
        return -EINVAL;
    }
    if(!CreateCurlHandle()){
        return -EIO;
    }

    return RequestPerform();
}

int S3fsCurl::GetIAMv2ApiToken(const char* token_url, int token_ttl, const char* token_ttl_hdr, std::string& response)
{
    if(!token_url || !token_ttl_hdr){
        //S3FS_PRN_ERR("IAMv2 token url(%s) or ttl_hdr(%s) parameter are wrong.", token_url ? token_url : "null", token_ttl_hdr ? token_ttl_hdr : "null");
        return -EIO;
    }
    response.clear();
    url = token_url;
    if(!CreateCurlHandle()){
        return -EIO;
    }
}

//
// Get AccessKeyId/SecretAccessKey/AccessToken/Expiration by IAM role,
// and Set these value to class variable.
//
bool S3fsCurl::GetIAMCredentials(const char* cred_url, const char* iam_v2_token, const char* ibm_secret_access_key, std::string& response)
{
    if(!cred_url){
        //S3FS_PRN_ERR("url is null.");
        return false;
    }
    url = cred_url;
    response.clear();

    // at first set type for handle
    type = REQTYPE::IAMCRED;

    if(!CreateCurlHandle()){
        return false;
    }
}

//
// Get IAM role name automatically.
//
bool S3fsCurl::GetIAMRoleFromMetaData(const char* cred_url, const char* iam_v2_token, std::string& token)
{
    if(!cred_url){
        //S3FS_PRN_ERR("url is null.");
        return false;
    }
    url = cred_url;
    token.clear();

    //S3FS_PRN_INFO3("Get IAM Role name");

    // at first set type for handle
    type = REQTYPE::IAMROLE;

    if(!CreateCurlHandle()){
        return false;
    }
    requestHeaders  = nullptr;
    responseHeaders.clear();
    bodydata.clear();

    if(iam_v2_token){
        requestHeaders = curl_slist_sort_insert(requestHeaders, S3fsCred::IAMv2_token_hdr, iam_v2_token);
    }

}

bool S3fsCurl::AddSseRequestHead(sse_type_t ssetype, const std::string& input, bool is_copy)
{
    std::string ssevalue = input;
    switch(ssetype){
        case sse_type_t::SSE_DISABLE:
            return true;
        case sse_type_t::SSE_S3:
            if(!is_copy){
                requestHeaders = curl_slist_sort_insert(requestHeaders, "x-amz-server-side-encryption", "AES256");
            }
            return true;
        case sse_type_t::SSE_C:
        case sse_type_t::SSE_KMS:
            return true;
    }
    //S3FS_PRN_ERR("sse type is unknown(%d).", static_cast<int>(S3fsCurl::ssetype));

    return false;
}

//
// tpath :      target path for head request
// ssekey_pos : -1    means "not" SSE-C type
//              0 - X means SSE-C type and position for SSE-C key(0 is latest key)
//
bool S3fsCurl::PreHeadRequest(const char* tpath, size_t ssekey_pos)
{
    //S3FS_PRN_INFO3("[tpath=%s][sseckeypos=%zu]", SAFESTRPTR(tpath), ssekey_pos);

    if(!tpath){
        return false;
    }
    std::string resource;
    std::string turl;
    MakeUrlResource(get_realpath(tpath).c_str(), resource, turl);

    // libcurl 7.17 does deep copy of url, deep copy "stable" url
    url             = prepare_url(turl.c_str());
    path            = get_realpath(tpath);
    requestHeaders  = nullptr;
    responseHeaders.clear();

    // requestHeaders(SSE-C)
    if(0 <= static_cast<ssize_t>(ssekey_pos) && ssekey_pos < S3fsCurl::sseckeys.size()){
        std::string md5;
        if(!S3fsCurl::GetSseKeyMd5(ssekey_pos, md5) || !AddSseRequestHead(sse_type_t::SSE_C, md5, false)){
            //S3FS_PRN_ERR("Failed to set SSE-C headers for sse-c key pos(%zu)(=md5(%s)).", ssekey_pos, md5.c_str());
            return false;
        }
    }

    op = "HEAD";
    type = REQTYPE::HEAD;

    // set lazy function
    fpLazySetup = PreHeadRequestSetCurlOpts;

    return true;
}

int S3fsCurl::HeadRequest(const char* tpath, headers_t& meta)
{
}

int S3fsCurl::PutHeadRequest(const char* tpath, const headers_t& meta, bool is_copy)
{
}

int S3fsCurl::PutRequest(const char* tpath, headers_t& meta, int fd)
{
}

int S3fsCurl::PreGetObjectRequest(const char* tpath, int fd, off_t start, off_t size, sse_type_t ssetype, const std::string& ssevalue)
{
    //S3FS_PRN_INFO3("[tpath=%s][start=%lld][size=%lld]", SAFESTRPTR(tpath), static_cast<long long>(start), static_cast<long long>(size));

    if(!tpath || -1 == fd || 0 > start || 0 > size){
        return -EINVAL;
    }

    std::string resource;
    std::string turl;
    MakeUrlResource(get_realpath(tpath).c_str(), resource, turl);

    url             = prepare_url(turl.c_str());
    path            = get_realpath(tpath);
    requestHeaders  = nullptr;
    responseHeaders.clear();

    if(0 < size){
        std::string range = "bytes=";
        range       += std::to_string(start);
        range       += "-";
        range       += std::to_string(start + size - 1);
        requestHeaders = curl_slist_sort_insert(requestHeaders, "Range", range.c_str());
    }
    // SSE-C
    if(sse_type_t::SSE_C == ssetype){
        if(!AddSseRequestHead(ssetype, ssevalue, false)){
            //S3FS_PRN_WARN("Failed to set SSE header, but continue...");
        }
    }
}

int S3fsCurl::GetObjectRequest(const char* tpath, int fd, off_t start, off_t size, sse_type_t ssetype, const std::string& ssevalue)
{
    int result;

    //S3FS_PRN_INFO3("[tpath=%s][start=%lld][size=%lld][ssetype=%u][ssevalue=%s]", SAFESTRPTR(tpath), static_cast<long long>(start), static_cast<long long>(size), static_cast<uint8_t>(ssetype), ssevalue.c_str());

    if(!tpath){
        return -EINVAL;
    }

    if(0 != (result = PreGetObjectRequest(tpath, fd, start, size, ssetype, ssevalue))){
        return result;
    }
    if(!fpLazySetup || !fpLazySetup(this)){
        //S3FS_PRN_ERR("Failed to lazy setup in single get object request.");
        return -EIO;
    }
}

int S3fsCurl::CheckBucket(const char* check_path, bool compat_dir, bool force_no_sse)
{
}

int S3fsCurl::ListBucketRequest(const char* tpath, const char* query)
{
}

//
// Initialize multipart upload
//
// Example :
//   POST /example-object?uploads HTTP/1.1
//   Host: example-bucket.s3.amazonaws.com
//   Date: Mon, 1 Nov 2010 20:34:56 GMT
//   Authorization: AWS VGhpcyBtZXNzYWdlIHNpZ25lZCBieSBlbHZpbmc=
//
int S3fsCurl::PreMultipartUploadRequest(const char* tpath, const headers_t& meta, std::string& upload_id)
{
}

int S3fsCurl::MultipartUploadPartSetup(const char* tpath, int upload_fd, off_t start, off_t size, int part_num, const std::string& upload_id, etagpair* petag, bool is_copy)
{
    // duplicate upload_fd
    if(!tpath || start < 0 || size <= 0 || !petag || (!is_copy && -1 == upload_fd)){
        //S3FS_PRN_ERR("Parameters are wrong: path(%s), upload_fd(%d), start(%lld), size(%lld), petag(%s), is_copy(%s)", SAFESTRPTR(tpath), upload_fd, static_cast<long long int>(start), static_cast<long long int>(size), (petag ? "not null" : "null"), (is_copy ? "true" : "false"));
        return -EIO;
    }
    
}

int S3fsCurl::MultipartUploadComplete(const char* tpath, const std::string& upload_id, const etaglist_t& parts)
{
}

int S3fsCurl::MultipartListRequest(std::string& body)
{
}

int S3fsCurl::AbortMultipartUpload(const char* tpath, const std::string& upload_id)
{
}

//
// PUT /ObjectName?partNumber=PartNumber&uploadId=UploadId HTTP/1.1
// Host: BucketName.s3.amazonaws.com
// Date: date
// Content-Length: Size
// Authorization: Signature
//
// PUT /my-movie.m2ts?partNumber=1&uploadId=VCVsb2FkIElEIGZvciBlbZZpbmcncyBteS1tb3ZpZS5tMnRzIHVwbG9hZR HTTP/1.1
// Host: example-bucket.s3.amazonaws.com
// Date:  Mon, 1 Nov 2010 20:34:56 GMT
// Content-Length: 10485760
// Content-MD5: pUNXr/BjKK5G2UKvaRRrOA==
// Authorization: AWS VGhpcyBtZXNzYWdlIHNpZ25lZGGieSRlbHZpbmc=
//
int S3fsCurl::MultipartUploadContentPartSetup(const char* tpath, int part_num, const std::string& upload_id)
{
    //S3FS_PRN_INFO3("[tpath=%s][start=%lld][size=%lld][part=%d]", SAFESTRPTR(tpath), static_cast<long long int>(partdata.startpos), static_cast<long long int>(partdata.size), part_num);

    if(-1 == partdata.fd || -1 == partdata.startpos || -1 == partdata.size){
        return -EINVAL;
    }

    requestHeaders = nullptr;

    // make md5 and file pointer
    if(S3fsCurl::is_content_md5){
        md5_t md5raw;
        partdata.etag = s3fs_hex_lower(md5raw.data(), md5raw.size());
        std::string md5base64 = s3fs_base64(md5raw.data(), md5raw.size());
        requestHeaders = curl_slist_sort_insert(requestHeaders, "Content-MD5", md5base64.c_str());
    }

    // make request
    //
    // [NOTE]
    // Encode the upload_id here.
    // In compatible S3 servers(Cloudflare, etc), there are cases where characters that require URL encoding are included.
    //
    query_string        = "partNumber=" + std::to_string(part_num) + "&uploadId=" + urlEncodeGeneral(upload_id);
    std::string urlargs = "?" + query_string;
    std::string resource;
    std::string turl;
    MakeUrlResource(get_realpath(tpath).c_str(), resource, turl);

    turl              += urlargs;
    url                = prepare_url(turl.c_str());
    path               = get_realpath(tpath);
    bodydata.clear();
    headdata.clear();
    responseHeaders.clear();

    // SSE-C
    if(sse_type_t::SSE_C == S3fsCurl::GetSseType()){
        std::string ssevalue;
        if(!AddSseRequestHead(S3fsCurl::GetSseType(), ssevalue, false)){
            //S3FS_PRN_WARN("Failed to set SSE header, but continue...");
        }
    }
}

int S3fsCurl::MultipartUploadCopyPartSetup(const char* from, const char* to, int part_num, const std::string& upload_id, const headers_t& meta)
{

    return 0;
}

bool S3fsCurl::MultipartUploadContentPartComplete()
{
    auto it = responseHeaders.find("ETag");
    if (it == responseHeaders.cend()) {
        return false;
    }
    std::string etag = peeloff(it->second);

    // check etag(md5);
    //
    // The ETAG when using SSE_C and SSE_KMS does not reflect the MD5 we sent  
    // SSE_C: https://docs.aws.amazon.com/AmazonS3/latest/API/RESTObjectPUT.html
    // SSE_KMS is ignored in the above, but in the following it states the same in the highlights:  
    // https://docs.aws.amazon.com/AmazonS3/latest/dev/UsingKMSEncryption.html
    //
    if(S3fsCurl::is_content_md5 && sse_type_t::SSE_C != S3fsCurl::GetSseType() && sse_type_t::SSE_KMS != S3fsCurl::GetSseType()){
        if(!etag_equals(etag, partdata.etag)){
            return false;
        }
    }
    partdata.petag->etag = etag;
    partdata.uploaded    = true;

    return true;
}

bool S3fsCurl::MultipartUploadCopyPartComplete()
{
}

bool S3fsCurl::MultipartUploadPartComplete()
{
    bool result;
    if(-1 == partdata.fd){
        result = MultipartUploadCopyPartComplete();
    }else{
        result = MultipartUploadContentPartComplete();
    }

    bodydata.clear();
    headdata.clear();

    return result;
}

int S3fsCurl::MultipartPutHeadRequest(const std::string& from, const std::string& to, int part_number, const std::string& upload_id, const headers_t& meta)
{
    //S3FS_PRN_INFO3("[from=%s][to=%s][part_number=%d][upload_id=%s]", from.c_str(), to.c_str(), part_number, upload_id.c_str());

    int result;

    // setup
    if(0 != (result = MultipartUploadCopyPartSetup(from.c_str(), to.c_str(), part_number, upload_id, meta))){
        //S3FS_PRN_ERR("failed multipart put head request setup(from=%s, to=%s, part_number=%d, upload_id=%s) : %d", from.c_str(), to.c_str(), part_number, upload_id.c_str(), result);
        return result;
    }
    if(!fpLazySetup || !fpLazySetup(this)){
        //S3FS_PRN_ERR("failed multipart put head request lazysetup(from=%s, to=%s, part_number=%d, upload_id=%s)", from.c_str(), to.c_str(), part_number, upload_id.c_str());
        return -EIO;
    }

    // request
    if(0 != (result = RequestPerform())){
        return result;
    }

    return 0;
}

int S3fsCurl::MultipartUploadPartRequest(const char* tpath, int upload_fd, off_t start, off_t size, int part_num, const std::string& upload_id, etagpair* petag, bool is_copy)
{
    //S3FS_PRN_INFO3("Multipart Upload Part [tpath=%s][upload_fd=%d][start=%lld][size=%lld][part_num=%d][upload_id=%s][is_copy=%s]", SAFESTRPTR(tpath), upload_fd, static_cast<long long int>(start), static_cast<long long int>(size), part_num, upload_id.c_str(), (is_copy ? "true" : "false"));

    //
    // Setup
    //
    int   result;
    if(0 != (result = MultipartUploadPartSetup(tpath, upload_fd, start, size, part_num, upload_id, petag, is_copy))){
        //S3FS_PRN_ERR("Failed pre-setup for Multipart Upload Part [tpath=%s][upload_fd=%d][start=%lld][size=%lld][part_num=%d][upload_id=%s][is_copy=%s]", SAFESTRPTR(tpath), upload_fd, static_cast<long long int>(start), static_cast<long long int>(size), part_num, upload_id.c_str(), (is_copy ? "true" : "false"));
        return result;
    }

    //
    // Send request
    //
    if(0 == (result = RequestPerform())){
        //S3FS_PRN_DBG("Succeed Multipart Upload Part [tpath=%s][upload_fd=%d][start=%lld][size=%lld][part_num=%d][upload_id=%s][is_copy=%s]", SAFESTRPTR(tpath), upload_fd, static_cast<long long int>(start), static_cast<long long int>(size), part_num, upload_id.c_str(), (is_copy ? "true" : "false"));

        if(!MultipartUploadPartComplete()){
            //S3FS_PRN_ERR("Failed completion for Multipart Upload Part [tpath=%s][upload_fd=%d][start=%lld][size=%lld][part_num=%d][upload_id=%s][is_copy=%s]", SAFESTRPTR(tpath), upload_fd, static_cast<long long int>(start), static_cast<long long int>(size), part_num, upload_id.c_str(), (is_copy ? "true" : "false"));
            result = -EIO;
        }
    }else{
        //S3FS_PRN_ERR("Failed Multipart Upload Part with error(%d) [tpath=%s][upload_fd=%d][start=%lld][size=%lld][part_num=%d][upload_id=%s][is_copy=%s]", result, SAFESTRPTR(tpath), upload_fd, static_cast<long long int>(start), static_cast<long long int>(size), part_num, upload_id.c_str(), (is_copy ? "true" : "false"));
    }

    return result;
}

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: expandtab sw=4 ts=4 fdm=marker
* vim<600: expandtab sw=4 ts=4
*/
