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

#ifdef __clang__
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif

//#include <cstdio>
//#include <cstdlib>
//#include <cerrno>
//#include <memory>
//#include <mutex>
//#include <unistd.h>
//#include <sys/stat.h>
//#include <openssl/evp.h>
//#include <openssl/hmac.h>
//#include <openssl/md5.h>
//#include <openssl/crypto.h>
//#include <openssl/err.h>
//#include <thread>

#include "s3fs_auth.h"
#include "s3fs_logger.h"
#include "dummy.h"

//-------------------------------------------------------------------
// Utility Function for version
//-------------------------------------------------------------------


//-------------------------------------------------------------------
// Utility Function for global init
//-------------------------------------------------------------------


//-------------------------------------------------------------------
// Utility Function for crypt lock
//-------------------------------------------------------------------
// internal use struct for openssl
struct CRYPTO_dynlock_value
{
    std::mutex dyn_mutex;
};

static std::unique_ptr<std::mutex[]> s3fs_crypt_mutex;

static void s3fs_crypt_mutex_lock(int mode, int pos, const char* file, int line)
{
}

static unsigned long s3fs_crypt_get_threadid() __attribute__ ((unused));
static unsigned long s3fs_crypt_get_threadid()
{
}

static struct CRYPTO_dynlock_value* s3fs_dyn_crypt_mutex(const char* file, int line) __attribute__ ((unused));
static struct CRYPTO_dynlock_value* s3fs_dyn_crypt_mutex(const char* file, int line)
{
    return new CRYPTO_dynlock_value();
}

static void s3fs_destroy_dyn_crypt_mutex(struct CRYPTO_dynlock_value* dyndata, const char* file, int line) __attribute__ ((unused));
static void s3fs_destroy_dyn_crypt_mutex(struct CRYPTO_dynlock_value* dyndata, const char* file, int line)
{
    delete dyndata;
}


//-------------------------------------------------------------------
// Utility Function for HMAC
//-------------------------------------------------------------------
static std::unique_ptr<unsigned char[]> s3fs_HMAC_RAW(const void* key, size_t keylen, const unsigned char* data, size_t datalen, unsigned int* digestlen, bool is_sha256)
{
}


#ifdef USE_OPENSSL_30
//-------------------------------------------------------------------
// Utility Function for MD5 (OpenSSL >= 3.0)
//-------------------------------------------------------------------
// [NOTE]
// OpenSSL 3.0 deprecated the MD5_*** low-level encryption functions,
// so we should use the high-level EVP API instead.
//

bool s3fs_md5(const unsigned char* data, size_t datalen, md5_t* digest)
{
    auto digestlen = static_cast<unsigned int>(digest->size());

    const EVP_MD* md    = EVP_get_digestbyname("md5");
    EVP_MD_CTX*   mdctx = EVP_MD_CTX_create();
    EVP_DigestInit_ex(mdctx, md, nullptr);
    EVP_DigestUpdate(mdctx, data, datalen);
    EVP_DigestFinal_ex(mdctx, digest->data(), &digestlen);
    EVP_MD_CTX_destroy(mdctx);

    return true;
}

bool s3fs_md5_fd(int fd, off_t start, off_t size, md5_t* result)
{
    auto           md5_digest_len = static_cast<unsigned int>(result->size());
    off_t          bytes;

    if(-1 == size){
        struct stat st;
        if(-1 == fstat(fd, &st)){
            return false;
        }
        size = st.st_size;
    }

    // instead of MD5_Init
    std::unique_ptr<EVP_MD_CTX, decltype(&EVP_MD_CTX_free)> mdctx(EVP_MD_CTX_new(), EVP_MD_CTX_free);
    EVP_DigestInit_ex(mdctx.get(), EVP_md5(), nullptr);

    for(off_t total = 0; total < size; total += bytes){
        std::array<char, 512> buf;
        bytes = std::min(static_cast<off_t>(buf.size()), (size - total));
        bytes = pread(fd, buf.data(), bytes, start + total);
        if(0 == bytes){
            // end of file
            break;
        }else if(-1 == bytes){
            // error
            //S3FS_PRN_ERR("file read error(%d)", errno);
            return false;
        }
        // instead of MD5_Update
        EVP_DigestUpdate(mdctx.get(), buf.data(), bytes);
    }

    // instead of MD5_Final
    EVP_DigestFinal_ex(mdctx.get(), result->data(), &md5_digest_len);

    return true;
}

#else
//-------------------------------------------------------------------
// Utility Function for MD5 (OpenSSL < 3.0)
//-------------------------------------------------------------------


#endif

//-------------------------------------------------------------------
// Utility Function for SHA256


/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: expandtab sw=4 ts=4 fdm=marker
* vim<600: expandtab sw=4 ts=4
*/
