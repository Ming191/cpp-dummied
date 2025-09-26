#ifndef _DUMMY_H_
#define _DUMMY_H_

// Dummy stubs for OpenSSL SSL functions and constants used in slowsocket.cc

typedef struct SSL_CTX SSL_CTX;
typedef struct SSL SSL;
typedef struct SSL_METHOD SSL_METHOD;

#define SSL_FILETYPE_PEM 1
#define SSL_ERROR_WANT_READ 2
#define SSL_ERROR_WANT_WRITE 3

// Stubs for SSL initialization and context
static inline int SSL_library_init(void) { return 1; }
static inline int OPENSSL_init_ssl(unsigned long opts, const void* settings) { return 1; }
static inline const SSL_METHOD* TLS_client_method(void) { return (const SSL_METHOD*)1; }
static inline SSL_METHOD* SSLv23_client_method(void) { return (SSL_METHOD*)1; }
static inline SSL_CTX* SSL_CTX_new(const SSL_METHOD* method) { return (SSL_CTX*)1; }
static inline void SSL_CTX_free(SSL_CTX* ctx) {}

// Stubs for certificate/key
static inline int SSL_CTX_use_certificate_file(SSL_CTX* ctx, const char* file, int type) { return 1; }
static inline int SSL_CTX_use_PrivateKey_file(SSL_CTX* ctx, const char* file, int type) { return 1; }

// Stubs for SSL object
static inline SSL* SSL_new(SSL_CTX* ctx) { return (SSL*)1; }
static inline void SSL_free(SSL* ssl) {}
static inline int SSL_set_fd(SSL* ssl, int fd) { return 1; }
static inline int SSL_connect(SSL* ssl) { return 1; }
static inline int SSL_do_handshake(SSL* ssl) { return 1; }
static inline int SSL_read(SSL* ssl, void* buf, int num) { return num; }
static inline int SSL_write(SSL* ssl, const void* buf, int num) { return num; }
static inline int SSL_is_init_finished(SSL* ssl) { return 1; }
static inline int SSL_get_error(const SSL* ssl, int ret_code) { return 0; }
static inline long SSL_ctrl(SSL* ssl, int cmd, long larg, void* parg) { return 1; }
static inline const char* SSL_get_cipher(const SSL* ssl) { return "DUMMY-CIPHER"; }
static inline void SSL_set_tlsext_host_name(SSL* ssl, const char* name) {}

// ...existing code...

// Stubs and constants for <sys/resource.h>
typedef unsigned long rlim_t;
typedef struct rlimit {
    rlim_t rlim_cur;
    rlim_t rlim_max;
} rlimit;

#define RLIM_INFINITY (~(rlim_t)0)
#define RLIMIT_NOFILE 7

static inline int getrlimit(int resource, struct rlimit *rlim) { 
    if (rlim) {
        rlim->rlim_cur = 1024;
        rlim->rlim_max = 4096;
    }
    return 0; 
}
static inline int setrlimit(int resource, const struct rlimit *rlim) { return 0; }

// ...existing

#endif // _DUMMY_H_