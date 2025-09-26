#ifndef _DUMMY_H_
#define _DUMMY_H_

#include <map>
#include <string>
#include <vector>
#include <mutex>
#include <array>
#include <list>
#include <cstring>


typedef int curl_lock_access;
typedef int CURLcode;

typedef int curl_infotype;

typedef int curl_lock_data;

typedef struct {
    int dummy;
} CURL;

typedef struct {
    int dummy;
} CURLSH;

struct etagpair
{
    std::string  etag;        // expected etag value
    int          part_num;    // part number

    explicit etagpair(const char* petag = nullptr, int part = -1) : etag(petag ? petag : ""), part_num(part) {}

    ~etagpair()
    {
      clear();
    }

    void clear()
    {
        etag.clear();
        part_num = -1;
    }
};

typedef std::list<etagpair> etaglist_t;

#define O_RDONLY 0



typedef struct {
    int dummy; // Không quan trọng, chỉ cần struct tồn tại
} regex_t;


namespace std {

template <typename T>
class unique_ptr {
public:
    unique_ptr() : ptr(nullptr) {}
    explicit unique_ptr(T* p) : ptr(p) {}
    ~unique_ptr() {}

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    unique_ptr(unique_ptr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T* get() const { return ptr; }
    T* operator->() const { return ptr; }
    T& operator*() const { return *ptr; }

private:
    T* ptr;
};

template <typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args) {
    return unique_ptr<T>(new T(args...));
}

}

namespace std {
template <typename T>
class enable_shared_from_this {
protected:
    enable_shared_from_this() = default;
    ~enable_shared_from_this() = default;
};
}

// #include <string>
// #include <strings.h>
//#include <sys/stat.h>

//-------------------------------------------------------------------
// headers_t
//-------------------------------------------------------------------
struct header_nocase_cmp
{
    bool operator()(const std::string &strleft, const std::string &strright) const
    {
        return (strcasecmp(strleft.c_str(), strright.c_str()) < 0);
    }
};
typedef std::map<std::string, std::string, header_nocase_cmp> headers_t;


typedef struct {
    int dummy;
} sem_t;

#define UTIME_OMIT -1

typedef int (*fuse_fill_dir_t)(void* buf, const char* name, const struct stat* stbuf, off_t off);



#define CURLINFO_DATA_IN 0
#define CURLINFO_HEADER_IN 1
#define CURLINFO_HEADER_OUT 2

#define CURL_IPRESOLVE_WHATEVER 0
#define CURLE_OK 0
#define CURL_GLOBAL_ALL 0
#define CURLE_ABORTED_BY_CALLBACK 1
#define VERSION "0.0.0"
#define COMMIT_HASH_VAL "0000000"
#define UCHAR_MAX 255
#define CURL_IPRESOLVE_V4 4
#define CURL_IPRESOLVE_V6 6
#define CURLINFO_TEXT 3


#define CURLINFO_SSL_DATA_IN 4
#define CURLINFO_SSL_DATA_OUT 5
#define CURLINFO_END 6
#define CURLINFO_DATA_OUT 7

#define CURLINFO_RESPONSE_CODE 8
#define O_WRONLY 1
#define O_RDWR 2

#define SECSuccess 0

#define CRYPTO_LOCK 1

typedef std::array<unsigned char, 16> md5_t;
typedef std::array<unsigned char, 32> sha256_t;


#define CURLE_OPERATION_TIMEDOUT 28
#define CURLE_PARTIAL_FILE 18
#define SIGHUP 1
#define SIGUSR2 12
#define SIGUSR1 10
#define LLONG_MIN (-9223372036854775807LL - 1)
#define LLONG_MAX 9223372036854775807LL

#define W_OK 2
#define X_OK 1
#define UTIME_NOW -2
#define R_OK 4

typedef struct incomplete_multipart_upload_info
{
    std::string key;
    std::string id;
    std::string date;
}INCOMP_MPU_INFO;

typedef std::vector<INCOMP_MPU_INFO> incomp_mpu_list_t;

#endif