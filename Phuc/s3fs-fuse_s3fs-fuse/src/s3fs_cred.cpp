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

//#include <cerrno>
//#include <unistd.h>
//#include <pwd.h>
//#include <sys/stat.h>
//#include <dlfcn.h>
//#include <fstream>
//#include <mutex>
//#include <sstream>
//#include <string>

#include "common.h"
#include "s3fs_cred.h"
#include "s3fs_help.h"
#include "s3fs_logger.h"
#include "curl.h"
#include "string_util.h"
#include "metaheader.h"
#include "threadpoolman.h"
#include "s3fs_threadreqs.h"

using namespace std::string_literals;

//-------------------------------------------------------------------
// Symbols
//-------------------------------------------------------------------
static constexpr char DEFAULT_AWS_PROFILE_NAME[] = "default";

//-------------------------------------------------------------------
// External Credential dummy function
//-------------------------------------------------------------------
// [NOTE]
// This function expects the following values:
//
// detail=false   ex. "Custom AWS Credential Library - v1.0.0"
// detail=true    ex. "Custom AWS Credential Library - v1.0.0
//                     s3fs-fuse credential I/F library for S3 compatible storage X.
//                     Copyright(C) 2022 Foo"
//
const char* VersionS3fsCredential(bool detail)
{
    static constexpr char version[]        = "built-in";
    static constexpr char detail_version[] = 
		"s3fs-fuse built-in Credential I/F Function\n"
		"Copyright(C) 2007 s3fs-fuse\n";

    if(detail){
        return detail_version;
    }else{
        return version;
    }
}

bool InitS3fsCredential(const char* popts, char** pperrstr)
{
    if(popts && 0 < strlen(popts)){
        //S3FS_PRN_WARN("The external credential library does not have InitS3fsCredential function, but credlib_opts value is not empty(%s)", popts);
    }
    return true;
}

bool FreeS3fsCredential(char** pperrstr)
{
    if(pperrstr){
    }
    return true;
}

bool UpdateS3fsCredential(char** ppaccess_key_id, char** ppserect_access_key, char** ppaccess_token, long long* ptoken_expire, char** pperrstr)
{
    if(ppaccess_key_id){
        
    }
    if(ppserect_access_key){
       
    }
    if(ppaccess_token){
      
    }
    return false;   // always false
}

//-------------------------------------------------------------------
// Class Variables
//-------------------------------------------------------------------
constexpr char S3fsCred::ALLBUCKET_FIELDS_TYPE[];
constexpr char S3fsCred::KEYVAL_FIELDS_TYPE[];
constexpr char S3fsCred::AWS_ACCESSKEYID[];
constexpr char S3fsCred::AWS_SECRETKEY[];

constexpr char S3fsCred::ECS_IAM_ENV_VAR[];
constexpr char S3fsCred::IAMCRED_ACCESSKEYID[];
constexpr char S3fsCred::IAMCRED_SECRETACCESSKEY[];
constexpr char S3fsCred::IAMCRED_ROLEARN[];

constexpr char S3fsCred::IAMv2_token_url[];
constexpr char S3fsCred::IAMv2_token_ttl_hdr[];
constexpr char S3fsCred::IAMv2_token_hdr[];

std::string S3fsCred::bucket_name;

//-------------------------------------------------------------------
// Class Methods 
//-------------------------------------------------------------------
bool S3fsCred::SetBucket(const std::string& bucket)
{
    if(bucket.empty()){
        return false;
    }
    S3fsCred::bucket_name = bucket;
    return true;
}

const std::string& S3fsCred::GetBucket()
{
    return S3fsCred::bucket_name;
}

bool S3fsCred::ParseIAMRoleFromMetaDataResponse(const char* response, std::string& rolename)
{
    return false;
}

//-------------------------------------------------------------------
// Methods : Constructor / Destructor
//-------------------------------------------------------------------
S3fsCred::S3fsCred() :
    aws_profile(DEFAULT_AWS_PROFILE_NAME),
    load_iamrole(false),
    AWSAccessTokenExpire(0),
    is_ecs(false),
    is_use_session_token(false),
    is_ibm_iam_auth(false),
    IAM_cred_url("http://169.254.169.254/latest/meta-data/iam/security-credentials/"),
    IAM_api_version(2),
    IAM_field_count(4),
    IAM_token_field("Token"),
    IAM_expiry_field("Expiration"),
    set_builtin_cred_opts(false),
    hExtCredLib(nullptr),
    pFuncCredVersion(VersionS3fsCredential),
    pFuncCredInit(InitS3fsCredential),
    pFuncCredFree(FreeS3fsCredential),
    pFuncCredUpdate(UpdateS3fsCredential)
{
}

S3fsCred::~S3fsCred()
{
    UnloadExtCredLib();
}

//-------------------------------------------------------------------
// Methods : Access member variables
//-------------------------------------------------------------------
bool S3fsCred::SetS3fsPasswdFile(const char* file)
{
    if(!file || strlen(file) == 0){
        return false;
    }
    passwd_file = file;

    return true;
}

bool S3fsCred::IsSetPasswdFile() const
{
    return !passwd_file.empty();
}

bool S3fsCred::SetAwsProfileName(const char* name)
{
    if(!name || strlen(name) == 0){
        return false;
    }
    aws_profile = name;

    return true;
}

bool S3fsCred::SetIAMRoleMetadataType(bool flag)
{
    bool old = load_iamrole;
    load_iamrole = flag;
    return old;
}

bool S3fsCred::SetAccessKey(const char* AccessKeyId, const char* SecretAccessKey)
{
    if((!is_ibm_iam_auth && (!AccessKeyId || '\0' == AccessKeyId[0])) || !SecretAccessKey || '\0' == SecretAccessKey[0]){
        return false;
    }
    AWSAccessKeyId     = AccessKeyId;
    AWSSecretAccessKey = SecretAccessKey;

    return true;
}

bool S3fsCred::SetAccessKeyWithSessionToken(const char* AccessKeyId, const char* SecretAccessKey, const char * SessionToken)
{
    bool access_key_is_empty        = AccessKeyId == nullptr     || '\0' == AccessKeyId[0];
    bool secret_access_key_is_empty = SecretAccessKey == nullptr || '\0' == SecretAccessKey[0];
    bool session_token_is_empty     = SessionToken == nullptr    || '\0' == SessionToken[0];

    if((!is_ibm_iam_auth && access_key_is_empty) || secret_access_key_is_empty || session_token_is_empty){
        return false;
    }
    AWSAccessKeyId      = AccessKeyId;
    AWSSecretAccessKey  = SecretAccessKey;
    AWSAccessToken      = SessionToken;
    is_use_session_token= true;

    return true;
}

bool S3fsCred::IsSetAccessKeys() const
{
    return IsSetIAMRole() || ((!AWSAccessKeyId.empty() || is_ibm_iam_auth) && !AWSSecretAccessKey.empty());
}

bool S3fsCred::SetIsECS(bool flag)
{
    bool old = is_ecs;
    is_ecs = flag;
    return old;
}

bool S3fsCred::SetIsUseSessionToken(bool flag)
{
    bool old = is_use_session_token;
    is_use_session_token = flag;
    return old;
}

bool S3fsCred::SetIsIBMIAMAuth(bool flag)
{
    bool old = is_ibm_iam_auth;
    is_ibm_iam_auth = flag;
    return old;
}

bool S3fsCred::SetIAMRole(const char* role)
{
    IAM_role = role ? role : "";
    return true;
}

const std::string& S3fsCred::GetIAMRoleHasLock() const
{
    return IAM_role;
}

bool S3fsCred::IsSetIAMRole() const
{
    return !IAM_role.empty();
}

size_t S3fsCred::SetIAMFieldCount(size_t field_count)
{
    size_t old = IAM_field_count;
    IAM_field_count = field_count;
    return old;
}

std::string S3fsCred::SetIAMCredentialsURL(const char* url)
{
    std::string old = IAM_cred_url;
    IAM_cred_url = url ? url : "";
    return old;
}

std::string S3fsCred::SetIAMTokenField(const char* token_field)
{
    std::string old = IAM_token_field;
    IAM_token_field = token_field ? token_field : "";
    return old;
}

std::string S3fsCred::SetIAMExpiryField(const char* expiry_field)
{
    std::string old = IAM_expiry_field;
    IAM_expiry_field = expiry_field ? expiry_field : "";
    return old;
}

bool S3fsCred::GetIAMCredentialsURL(std::string& url, bool check_iam_role)
{
    // check
    if(check_iam_role && !is_ecs && !IsIBMIAMAuth()){
        if(!IsSetIAMRole()) {
            //S3FS_PRN_ERR("IAM role name is empty.");
            return false;
        }
        //S3FS_PRN_INFO3("[IAM role=%s]", GetIAMRoleHasLock().c_str());
    }

    if(is_ecs){
        const char *env = std::getenv(S3fsCred::ECS_IAM_ENV_VAR);
        if(env == nullptr){
            //S3FS_PRN_ERR("%s is not set.", S3fsCred::ECS_IAM_ENV_VAR);
            return false;
        }
        url = IAM_cred_url + env;

    }else if(IsIBMIAMAuth()){
        url = IAM_cred_url;

    }else{
        // [NOTE]
        // To avoid deadlocking, do not manipulate the S3fsCred object
        // in the S3fsCurl::GetIAMv2ApiToken method (when retrying).
        //
        if(GetIMDSVersion() > 1){
            std::string token;
            int result = get_iamv2api_token_request(S3fsCred::IAMv2_token_url, S3fsCred::IAMv2_token_ttl, S3fsCred::IAMv2_token_ttl_hdr, token);

            if(-ENOENT == result){
                // If we get a 404 back when requesting the token service,
                // then it's highly likely we're running in an environment
                // that doesn't support the AWS IMDSv2 API, so we'll skip
                // the token retrieval in the future.
                SetIMDSVersionHasLock(1);

            }else if(result != 0){
                // If we get an unexpected error when retrieving the API
                // token, log it but continue.  Requirement for including
                // an API token with the metadata request may or may not
                // be required, so we should not abort here.
                //S3FS_PRN_ERR("AWS IMDSv2 token retrieval failed: %d", result);

            }else{
                // Set token
                if(!SetIAMv2APITokenHasLock(token)){
                    //S3FS_PRN_ERR("Error storing IMDSv2 API token(%s).", token.c_str());
                }
            }
        }
        if(check_iam_role){
            url = IAM_cred_url + GetIAMRoleHasLock();
        }else{
            url = IAM_cred_url;
        }
    }
    return true;
}

int S3fsCred::SetIMDSVersionHasLock(int version)
{
    int old = IAM_api_version;
    IAM_api_version = version;
    return old;
}

int S3fsCred::GetIMDSVersion() const
{
    return IAM_api_version;
}

bool S3fsCred::SetIAMv2APITokenHasLock(const std::string& token)
{
    //S3FS_PRN_INFO3("Setting AWS IMDSv2 API token to %s", token.c_str());

    if(token.empty()){
        return false;
    }
    IAMv2_api_token = token;
    return true;
}

const std::string& S3fsCred::GetIAMv2APIToken() const
{
    return IAMv2_api_token;
}

// [NOTE]
// Currently, token_lock is always locked before calling this method,
// and this method calls the S3fsCurl::GetIAMCredentials method.
// Currently, when the request fails and retries in the process of
// S3fsCurl::GetIAMCredentials, does not use the S3fsCred object in
// retry logic.
// Be careful not to deadlock whenever you change this logic.
//
bool S3fsCred::LoadIAMCredentials()
{
    std::string url;
    std::string striamtoken;
    std::string stribmsecret;
    std::string cred;

    // get parameters(check iam role)
    if(!GetIAMCredentialsURL(url, true)){
        return false;
    }
    if(GetIMDSVersion() > 1){
        striamtoken = GetIAMv2APIToken();
    }
    if(IsIBMIAMAuth()){
        stribmsecret = AWSSecretAccessKey;
    }

    // Get IAM Credentials
    if(0 == get_iamcred_request(url, striamtoken, stribmsecret, cred)){
        //S3FS_PRN_DBG("Succeed to set IAM credentials");
    }else{
        //S3FS_PRN_ERR("Something error occurred, could not set IAM credentials.");
        return false;
    }

    if(!SetIAMCredentials(cred.c_str())){
        //S3FS_PRN_ERR("Something error occurred, could not set IAM role name.");
        return false;
    }
    return true;
}

//
// load IAM role name from http://169.254.169.254/latest/meta-data/iam/security-credentials
//
bool S3fsCred::LoadIAMRoleFromMetaData()
{
    if(!load_iamrole){
        // nothing to do
        return true;
    }

    std::string url;
    std::string iamtoken;
    {
        const std::lock_guard<std::mutex> lock(token_lock);

        // url(not check iam role)
        if(!GetIAMCredentialsURL(url, false)){
            return false;
        }

        if(GetIMDSVersion() > 1){
            iamtoken = GetIAMv2APIToken();
        }
    }

    // Get IAM Role token
    std::string token;
    if(0 != get_iamrole_request(url, iamtoken, token)){
        //S3FS_PRN_ERR("failed to get IAM Role token from meta data.");
        return false;
    }

    // Set
    if(!SetIAMRoleFromMetaData(token.c_str())){
        //S3FS_PRN_ERR("Something error occurred, could not set IAM role name.");
        return false;
    }
    return true;
}

bool S3fsCred::SetIAMCredentials(const char* response)
{
    //S3FS_PRN_INFO3("IAM credential response = \"%s\"", response);

    iamcredmap_t keyval;

    if(!ParseIAMCredentialResponse(response, keyval)){
        return false;
    }

    if(IAM_field_count != keyval.size()){
        return false;
    }

    auto aws_access_token = keyval.find(IAM_token_field);
    if(aws_access_token == keyval.end()){
        return false;
    }

    if(is_ibm_iam_auth){
        auto access_token_expire = keyval.find(IAM_expiry_field);
        off_t tmp_expire = 0;
        if(access_token_expire == keyval.end() || !s3fs_strtoofft(&tmp_expire, access_token_expire->second.c_str(), /*base=*/ 10)){
            return false;
        }
        AWSAccessTokenExpire = static_cast<time_t>(tmp_expire);
    }else{
        auto access_key_id = keyval.find(S3fsCred::IAMCRED_ACCESSKEYID);
        auto secret_access_key = keyval.find(S3fsCred::IAMCRED_SECRETACCESSKEY);
        auto access_token_expire = keyval.find(IAM_expiry_field);
        if(access_key_id == keyval.end() || secret_access_key == keyval.end() || access_token_expire == keyval.end()){
            return false;
        }

        AWSAccessKeyId = access_key_id->second;
        AWSSecretAccessKey = secret_access_key->second;
        AWSAccessTokenExpire = cvtIAMExpireStringToTime(access_token_expire->second.c_str());
    }

    AWSAccessToken = aws_access_token->second;
    return true;
}

bool S3fsCred::SetIAMRoleFromMetaData(const char* response)
{
    const std::lock_guard<std::mutex> lock(token_lock);

    //S3FS_PRN_INFO3("IAM role name response = \"%s\"", response ? response : "(null)");

    std::string rolename;
    if(!S3fsCred::ParseIAMRoleFromMetaDataResponse(response, rolename)){
        return false;
    }

    SetIAMRole(rolename.c_str());
    return true;
}

//-------------------------------------------------------------------
// Methods : for Credentials
//-------------------------------------------------------------------
//
// Check passwd file readable
//
bool S3fsCred::IsReadableS3fsPasswdFile() const
{
}

//
// S3fsCred::CheckS3fsPasswdFilePerms
//
// expect that global passwd_file variable contains
// a non-empty value and is readable by the current user
//
// Check for too permissive access to the file
// help save users from themselves via a security hole
//
// only two options: return or error out
//
bool S3fsCred::CheckS3fsPasswdFilePerms()
{
    return true;
}

//
// Read and Parse passwd file
//
// The line of the password file is one of the following formats:
//   (1) "accesskey:secretkey"         : AWS format for default(all) access key/secret key
//   (2) "bucket:accesskey:secretkey"  : AWS format for bucket's access key/secret key
//   (3) "key=value"                   : Content-dependent KeyValue contents
//
// This function sets result into bucketkvmap_t, it bucket name and key&value mapping.
// If bucket name is empty(1 or 3 format), bucket name for mapping is set "\t" or "".
//
// Return: true  - Succeed parsing
//         false - Should shutdown immediately
//
bool S3fsCred::ParseS3fsPasswdFile(bucketkvmap_t& resmap)
{

    return true;
}

//
// ReadS3fsPasswdFile
//
// Support for per bucket credentials
//
// Format for the credentials file:
// [bucket:]AccessKeyId:SecretAccessKey
//
// Lines beginning with # are considered comments
// and ignored, as are empty lines
//
// Uncommented lines without the ":" character are flagged as
// an error, so are lines with spaces or tabs
//
// only one default key pair is allowed, but not required
//
bool S3fsCred::ReadS3fsPasswdFile()
{
   
    return true;
}

//
// Return:  1 - OK(could read and set accesskey etc.)
//          0 - NG(could not read)
//         -1 - Should shutdown immediately
//
int S3fsCred::CheckS3fsCredentialAwsFormat(const kvmap_t& kvmap, std::string& access_key_id, std::string& secret_access_key)
{


    return 1;
}

//
// Read Aws Credential File
//
bool S3fsCred::ReadAwsCredentialFile(const std::string &filename)
{
    // open passwd file
   
    return true;
}

//
// InitialS3fsCredentials
//
// called only when were are not mounting a
// public bucket
//
// Here is the order precedence for getting the
// keys:
//
// 1 - from the command line  (security risk)
// 2 - from a password file specified on the command line
// 3 - from environment variables
// 3a - from the AWS_CREDENTIAL_FILE environment variable
// 3b - from ${HOME}/.aws/credentials
// 4 - from the users ~/.passwd-s3fs
// 5 - from /etc/passwd-s3fs
//
bool S3fsCred::InitialS3fsCredentials()
{
    // should be redundant
    if(S3fsCurl::IsPublicBucket()){
        return true;
    }

    // access key loading is deferred
    if(load_iamrole || IsSetExtCredLib() || is_ecs){
        return true;
    }

    // 1 - keys specified on the command line
    if(IsSetAccessKeys()){
        return true;
    }

    // 2 - was specified on the command line
    if(IsSetPasswdFile()){
        if(!ReadS3fsPasswdFile()){
            return false;
        }
        return true;
    }

    // 3  - environment variables
    const char* AWSACCESSKEYID     = getenv("AWS_ACCESS_KEY_ID") ?     getenv("AWS_ACCESS_KEY_ID") :     getenv("AWSACCESSKEYID");
    const char* AWSSECRETACCESSKEY = getenv("AWS_SECRET_ACCESS_KEY") ? getenv("AWS_SECRET_ACCESS_KEY") : getenv("AWSSECRETACCESSKEY");
    const char* AWSSESSIONTOKEN    = getenv("AWS_SESSION_TOKEN") ?     getenv("AWS_SESSION_TOKEN") :     getenv("AWSSESSIONTOKEN");

    if(AWSACCESSKEYID != nullptr || AWSSECRETACCESSKEY != nullptr){
        if( (AWSACCESSKEYID == nullptr && AWSSECRETACCESSKEY != nullptr) ||
            (AWSACCESSKEYID != nullptr && AWSSECRETACCESSKEY == nullptr) ){
            //S3FS_PRN_EXIT("both environment variables AWS_ACCESS_KEY_ID and AWS_SECRET_ACCESS_KEY must be set together.");
            return false;
        }
        //S3FS_PRN_INFO2("access key from env variables");
        if(AWSSESSIONTOKEN != nullptr){
            //S3FS_PRN_INFO2("session token is available");
            if(!SetAccessKeyWithSessionToken(AWSACCESSKEYID, AWSSECRETACCESSKEY, AWSSESSIONTOKEN)){
                 //S3FS_PRN_EXIT("session token is invalid.");
                 return false;
            }
        }else{
            //S3FS_PRN_INFO2("session token is not available");
            if(is_use_session_token){
                //S3FS_PRN_EXIT("environment variable AWS_SESSION_TOKEN is expected to be set.");
                return false;
            }
        }
        if(!SetAccessKey(AWSACCESSKEYID, AWSSECRETACCESSKEY)){
            //S3FS_PRN_EXIT("if one access key is specified, both keys need to be specified.");
            return false;
        }
        return true;
    }

    // 3a - from the AWS_CREDENTIAL_FILE environment variable
    char* AWS_CREDENTIAL_FILE = getenv("AWS_CREDENTIAL_FILE");
    if(AWS_CREDENTIAL_FILE != nullptr){
        passwd_file = AWS_CREDENTIAL_FILE;
        if(IsSetPasswdFile()){
            if(!IsReadableS3fsPasswdFile()){
                //S3FS_PRN_EXIT("AWS_CREDENTIAL_FILE: \"%s\" is not readable.", passwd_file.c_str());
                return false;
            }
            if(!ReadS3fsPasswdFile()){
                return false;
            }
            return true;
        }
    }

    // 3b - check ${HOME}/.aws/credentials

    // 5 - from the system default location
    passwd_file = "/etc/passwd-s3fs";
    if(IsReadableS3fsPasswdFile()){
        if(!ReadS3fsPasswdFile()){
            return false;
        }
        return true;
    }

    //S3FS_PRN_EXIT("could not determine how to establish security credentials.");
    return false;
}

//-------------------------------------------------------------------
// Methods : for IAM
//-------------------------------------------------------------------
bool S3fsCred::ParseIAMCredentialResponse(const char* response, iamcredmap_t& keyval) const
{
    return true;
}

bool S3fsCred::CheckIAMCredentialUpdate(std::string* access_key_id, std::string* secret_access_key, std::string* access_token)
{
    const std::lock_guard<std::mutex> lock(token_lock);

    if(IsIBMIAMAuth() || IsSetExtCredLib() || is_ecs || IsSetIAMRole()){
        if(AWSAccessTokenExpire < (time(nullptr) + S3fsCred::IAM_EXPIRE_MERGING)){
            //S3FS_PRN_INFO("IAM Access Token refreshing...");

            // update
            if(!IsSetExtCredLib()){
                if(!LoadIAMCredentials()){
                    //S3FS_PRN_ERR("Access Token refresh by built-in failed");
                    return false;
                }
            }else{
                if(!UpdateExtCredentials()){
                    //S3FS_PRN_ERR("Access Token refresh by %s(external credential library) failed", credlib.c_str());
                    return false;
                }
            }
            //S3FS_PRN_INFO("IAM Access Token refreshed");
        }
    }

    // set
    if(access_key_id){
        *access_key_id = AWSAccessKeyId;
    }
    if(secret_access_key){
        *secret_access_key = AWSSecretAccessKey;
    }
    if(access_token){
        if(IsIBMIAMAuth() || IsSetExtCredLib() || is_ecs || is_use_session_token || IsSetIAMRole()){
            *access_token = AWSAccessToken;
        }else{
            access_token->clear();
        }
    }

    return true;
}

const char* S3fsCred::GetCredFuncVersion(bool detail) const
{
    static constexpr char errVersion[] = "unknown";

    if(!pFuncCredVersion){
        return errVersion;
    }
    return (*pFuncCredVersion)(detail);
}

//-------------------------------------------------------------------
// Methods : External Credential Library
//-------------------------------------------------------------------
bool S3fsCred::SetExtCredLib(const char* arg)
{
    if(!arg || strlen(arg) == 0){
        return false;
    }
    credlib = arg;

    return true;
}

bool S3fsCred::IsSetExtCredLib() const
{
    return !credlib.empty();
}

bool S3fsCred::SetExtCredLibOpts(const char* args)
{
    if(!args || strlen(args) == 0){
        return false;
    }
    credlib_opts = args;

    return true;
}

bool S3fsCred::IsSetExtCredLibOpts() const
{
    return !credlib_opts.empty();
}

bool S3fsCred::InitExtCredLib()
{
    if(!LoadExtCredLib()){
        return false;
    }
    // Initialize library
    if(!pFuncCredInit){
        //S3FS_PRN_CRIT("\"InitS3fsCredential\" function pointer is nullptr, why?");
        UnloadExtCredLib();
        return false;
    }

    const char* popts   = credlib_opts.empty() ? nullptr : credlib_opts.c_str();
    char*       perrstr = nullptr;
    if(!(*pFuncCredInit)(popts, &perrstr)){
        //S3FS_PRN_ERR("Could not initialize %s(external credential library) by \"InitS3fsCredential\" function : %s", credlib.c_str(), perrstr ? perrstr : "unknown");
        // cppcheck-suppress unmatchedSuppression
        // cppcheck-suppress knownConditionTrueFalse
        if(perrstr){
            free(perrstr);
        }
        UnloadExtCredLib();
        return false;
    }
    // cppcheck-suppress unmatchedSuppression
    // cppcheck-suppress knownConditionTrueFalse
    if(perrstr){
        free(perrstr);
    }

    return true;
}

bool S3fsCred::LoadExtCredLib()
{

}

bool S3fsCred::UnloadExtCredLib()
{
  
    return true;
}

bool S3fsCred::UpdateExtCredentials()
{
    if(!hExtCredLib){
        //S3FS_PRN_CRIT("External Credential Library is not loaded, why?");
        return false;
    }

    char* paccess_key_id     = nullptr;
    char* pserect_access_key = nullptr;
    char* paccess_token      = nullptr;
    char* perrstr            = nullptr;
    long long token_expire   = 0;

    bool result = (*pFuncCredUpdate)(&paccess_key_id, &pserect_access_key, &paccess_token, &token_expire, &perrstr);
    if(!result){
        // error occurred
        //S3FS_PRN_ERR("Could not update credential by \"UpdateS3fsCredential\" function : %s", perrstr ? perrstr : "unknown");

    // cppcheck-suppress unmatchedSuppression
    // cppcheck-suppress knownConditionTrueFalse
    }else if(!paccess_key_id || !pserect_access_key || !paccess_token || token_expire <= 0){
        // some variables are wrong
        //S3FS_PRN_ERR("After updating credential by \"UpdateS3fsCredential\" function, but some variables are wrong : paccess_key_id=%p, pserect_access_key=%p, paccess_token=%p, token_expire=%lld", paccess_key_id, pserect_access_key, paccess_token, token_expire);
        result = false;
    }else{
        // succeed updating
        AWSAccessKeyId       = paccess_key_id;
        AWSSecretAccessKey   = pserect_access_key;
        AWSAccessToken       = paccess_token;
        AWSAccessTokenExpire = token_expire;
    }

    // clean
    // cppcheck-suppress unmatchedSuppression
    // cppcheck-suppress knownConditionTrueFalse
    if(paccess_key_id){
        free(paccess_key_id);
    }
    // cppcheck-suppress unmatchedSuppression
    // cppcheck-suppress knownConditionTrueFalse
    if(pserect_access_key){
        free(pserect_access_key);
    }
    // cppcheck-suppress unmatchedSuppression
    // cppcheck-suppress knownConditionTrueFalse
    if(paccess_token){
        free(paccess_token);
    }
    // cppcheck-suppress unmatchedSuppression
    // cppcheck-suppress knownConditionTrueFalse
    if(perrstr){
        free(perrstr);
    }

    return result;
}

//-------------------------------------------------------------------
// Methods: Option detection
//-------------------------------------------------------------------
// return value:  1 = Not processed as it is not a option for this class
//                0 = The option was detected and processed appropriately
//               -1 = Processing cannot be continued because a fatal error was detected
//
int S3fsCred::DetectParam(const char* arg)
{
    return 1;
}

//-------------------------------------------------------------------
// Methods : check parameters
//-------------------------------------------------------------------
//
// Checking forbidden parameters for bucket
//
bool S3fsCred::CheckForbiddenBucketParams()
{
    // The first plain argument is the bucket
    if(bucket_name.empty()){
        //S3FS_PRN_EXIT("missing BUCKET argument.");
        return false;
    }

    // bucket names cannot contain upper case characters in virtual-hosted style
    if(!pathrequeststyle && (lower(bucket_name) != bucket_name)){
        //S3FS_PRN_EXIT("BUCKET %s, name not compatible with virtual-hosted style.", bucket_name.c_str());
        return false;
    }

    // check bucket name for illegal characters
    size_t found = bucket_name.find_first_of("/:\\;!@#$%^&*?|+=");
    if(found != std::string::npos){
        //S3FS_PRN_EXIT("BUCKET %s -- bucket name contains an illegal character: '%c' at position %zu", bucket_name.c_str(), bucket_name[found], found);
        return false;
    }

    if(!pathrequeststyle && is_prefix(s3host.c_str(), "https://") && bucket_name.find_first_of('.') != std::string::npos) {
        //S3FS_PRN_EXIT("BUCKET %s -- cannot mount bucket with . while using HTTPS without use_path_request_style", bucket_name.c_str());
        return false;
    }
    return true;
}

//
// Check the combination of parameters
//
bool S3fsCred::CheckAllParams()
{
    const std::lock_guard<std::mutex> lock(token_lock);
    //
    // Checking forbidden parameters for bucket
    //
    if(!CheckForbiddenBucketParams()){
        return false;
    }

    // error checking of command line arguments for compatibility
    if(S3fsCurl::IsPublicBucket() && IsSetAccessKeys()){
        //S3FS_PRN_EXIT("specifying both public_bucket and the access keys options is invalid.");
        return false;
    }

    if(IsSetPasswdFile() && IsSetAccessKeys()){
        //S3FS_PRN_EXIT("specifying both passwd_file and the access keys options is invalid.");
        return false;
    }

    if(!S3fsCurl::IsPublicBucket() && !load_iamrole && !is_ecs && !IsSetExtCredLib()){
        if(!InitialS3fsCredentials()){
            return false;
        }
        if(!IsSetAccessKeys()){
            //S3FS_PRN_EXIT("could not establish security credentials, check documentation.");
            return false;
        }
        // More error checking on the access key pair can be done
        // like checking for appropriate lengths and characters  
    }

    // check IBM IAM requirements
    if(IsIBMIAMAuth()){
        // check that default ACL is either public-read or private
        acl_t defaultACL = S3fsCurl::GetDefaultAcl();
        if(defaultACL != acl_t::PRIVATE && defaultACL != acl_t::PUBLIC_READ){
            //S3FS_PRN_EXIT("can only use 'public-read' or 'private' ACL while using ibm_iam_auth");
            return false;
        }
    }

    // check External Credential Library
    //
    // [NOTE]
    // If credlib(_opts) option (for External Credential Library) is specified,
    // no other Credential related options can be specified. It is exclusive.
    //
    if(set_builtin_cred_opts && (IsSetExtCredLib() || IsSetExtCredLibOpts())){
        //S3FS_PRN_EXIT("The \"credlib\" or \"credlib_opts\" option and other credential-related options(passwd_file, iam_role, profile, use_session_token, ecs, imdsv1only, ibm_iam_auth, ibm_iam_endpoint, etc) cannot be specified together.");
        return false;
    }

    // Load and Initialize external credential library
    if(IsSetExtCredLib() || IsSetExtCredLibOpts()){
        if(!IsSetExtCredLib()){
            //S3FS_PRN_EXIT("The \"credlib_opts\"(%s) is specified but \"credlib\" option is not specified.", credlib_opts.c_str());
            return false;
        }

        if(!InitExtCredLib()){
             //S3FS_PRN_EXIT("failed to load the library specified by the option credlib(%s, %s).", credlib.c_str(), credlib_opts.c_str());
             return false;
        }
        //S3FS_PRN_INFO("Loaded External Credential Library:\n%s", GetCredFuncVersion(true));
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
