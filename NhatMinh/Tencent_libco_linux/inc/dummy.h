#ifndef DUMMY_H
#define DUMMY_H

#ifdef _WIN32

#include <stdint.h>  // Cho uint32_t, uint64_t
#include <signal.h>

struct in_addr {
    uint32_t s_addr;
};

// ==== sys/poll.h ====

typedef unsigned int nfds_t;

#define POLLIN     0x001
#define POLLOUT    0x004
#define POLLERR    0x008
#define POLLHUP    0x010
#define POLLNVAL   0x020

struct pollfd {
    int fd;
    short events;
    short revents;
};

int poll(struct pollfd *fds, unsigned int nfds, int timeout);
int fcntl(int fd, int cmd, ...);

// ==== sys/epoll.h ====

#define EPOLLIN     0x001
#define EPOLLOUT    0x004
#define EPOLLERR    0x008
#define EPOLLHUP    0x010
#define EPOLLRDHUP  0x2000
#define EPOLLPRI    0x002
#define EPOLLET     (1u << 31)
#define EPOLLONESHOT (1u << 30)

#define EPOLL_CTL_ADD 1
#define EPOLL_CTL_DEL 2
#define EPOLL_CTL_MOD 3

typedef union epoll_data {
    void    *ptr;
    int      fd;
    uint32_t u32;
    uint64_t u64;
} epoll_data_t;

struct epoll_event {
    uint32_t events;
    epoll_data_t data;
};

static inline int epoll_create(int size) {
    (void)size; return -1;
}

static inline int epoll_create1(int flags) {
    (void)flags; return -1;
}

static inline int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event) {
    (void)epfd; (void)op; (void)fd; (void)event;
    return -1;
}

static inline int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout) {
    (void)epfd; (void)events; (void)maxevents; (void)timeout;
    return -1;
}

// ==== sys/socket.h ====

#define AF_INET     2
#define AF_INET6    10
#define AF_UNIX     1

#define SOCK_STREAM 1
#define SOCK_DGRAM  2
#define SOCK_RAW    3

#define IPPROTO_TCP 6
#define IPPROTO_UDP 17

typedef int socklen_t;

struct sockaddr {
    uint16_t sa_family;
    char sa_data[14];
};

struct sockaddr_in {
    short sin_family;
    unsigned short sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
};

// static inline int socket(int domain, int type, int protocol) {
//     (void)domain; (void)type; (void)protocol;
//     return -1;
// }

// static inline int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
//     (void)sockfd; (void)addr; (void)addrlen;
//     return -1;
// }

static inline int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    (void)sockfd; (void)addr; (void)addrlen;
    return -1;
}

static inline int listen(int sockfd, int backlog) {
    (void)sockfd; (void)backlog;
    return -1;
}

static inline int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    (void)sockfd; (void)addr; (void)addrlen;
    return -1;
}

static inline int closesocket(int sockfd) {
    (void)sockfd;
    return -1;
}

static inline int shutdown(int sockfd, int how) {
    (void)sockfd; (void)how;
    return -1;
}

// ==== sys/syscall.h (dummy) ====

#define __NR_read      0
#define __NR_write     1
#define __NR_open      2
#define __NR_close     3
#define __NR_exit      60

static inline long syscall(long number, ...) {
    (void)number;
    return -1; 
}

#define NETDB_INTERNAL -1
#define NETDB_SUCCESS 0
#define HOST_NOT_FOUND 1
#define TRY_AGAIN 2
#define NO_RECOVERY 3
#define NO_DATA 4
#define NO_ADDRESS NO_DATA

struct hostent {
    char *h_name;       // Official name of host
    char **h_aliases;   // Alias list
    int h_addrtype;     // Host address type (e.g., AF_INET)
    int h_length;       // Length of address
    char **h_addr_list; // List of addresses
};

#define h_addr h_addr_list[0]

// File control options
#define F_DUPFD        0
#define F_GETFD        1
#define F_SETFD        2
#define F_GETFL        3
#define F_SETFL        4
#define F_SETLK        6
#define F_SETLKW       7
#define F_GETLK        5
#define F_GETOWN       8
#define F_SETOWN       9

// File status flags
#define O_RDONLY       0x0000
#define O_WRONLY       0x0001
#define O_RDWR         0x0002
#define O_NONBLOCK     0x0004
#define O_APPEND       0x0008
#define O_CREAT        0x0100
#define O_TRUNC        0x0200
#define O_EXCL         0x0400
#define O_NOCTTY       0x0800
#define O_CLOEXEC      0x1000
#define O_NDELAY       0x8000  

// FD flags
#define FD_CLOEXEC     1

// static inline int setsockopt(int sockfd, int level, int optname,
//                              const void *optval, socklen_t optlen) {
//     (void)sockfd;
//     (void)level;
//     (void)optname;
//     (void)optval;
//     (void)optlen;
//     return 0; // giả lập thành công
// }

static inline int wait(int *status) {
    (void)status;
    // Không có fork/child process, nên chỉ giả lập thành công
    return 0;
}

// static inline int fcntl(int fd, int cmd, ...) {
//     (void)fd;
//     (void)cmd;
//     return -1; // Always fail in dummy
// }

typedef void* dlhandle_t;

// Dummy dlsym
static inline void* dlsym(dlhandle_t handle, const char* symbol) {
    (void)handle;
    (void)symbol;
    return NULL;
}

// Dummy dlopen
static inline dlhandle_t dlopen(const char* filename, int flag) {
    (void)filename;
    (void)flag;
    return NULL;
}

// Dummy dlclose
static inline int dlclose(dlhandle_t handle) {
    (void)handle;
    return 0;
}

// Dummy dlerror
static inline const char* dlerror(void) {
    return "dlerror: not supported on Windows (dummy)";
}

// Dummy RTLD flags
#define RTLD_LAZY   0x0001
#define RTLD_NOW    0x0002
#define RTLD_GLOBAL 0x0100
#define RTLD_LOCAL  0x0000

#define RTLD_NEXT ((void*)-1)

#define AF_INET 2
#define AF_INET6 10

// Port/address types
typedef uint16_t in_port_t;
typedef uint32_t in_addr_t;

#define SOL_SOCKET 0xffff
#define SO_REUSEADDR    0x0004
#define SO_KEEPALIVE    0x0008
#define SO_BROADCAST    0x0020
#define SO_LINGER       0x0080
#define SO_RCVBUF       0x1002
#define SO_SNDBUF       0x1001
#define SO_RCVTIMEO     0x1006
#define SO_SNDTIMEO     0x1005
#define SO_ERROR        0x1007
#define SO_TYPE         0x1008

typedef int socklen_t;

static inline int getsockopt(int sockfd, int level, int optname,
                             void *optval, void *optlen) {
    if (optval && optlen) {
        *(int *)optval = 0; 
        return 0;
    }
    return -1;
}

struct __res_state {
    int dummy;
};
typedef struct __res_state res_state;

#define POLLIN      0x0001  // Có dữ liệu để đọc
#define POLLPRI     0x0002  // Dữ liệu ưu tiên
#define POLLOUT     0x0004  // Có thể ghi
#define POLLERR     0x0008  // Lỗi I/O
#define POLLHUP     0x0010  // Ngắt kết nối
#define POLLNVAL    0x0020  // Mô tả không hợp lệ

#define POLLRDNORM  0x0040  // Có thể đọc dữ liệu "bình thường"
#define POLLRDBAND  0x0080  // Có thể đọc dữ liệu ưu tiên (band)
#define POLLWRNORM  0x0100  // Có thể ghi dữ liệu "bình thường"
#define POLLWRBAND  0x0200  // Có thể ghi dữ liệu ưu tiên (band)

#define POLLMSG     0x0400  // POSIX XPG4.2: có tin nhắn đến (IPC)
#define POLLREMOVE  0x1000  // Linux: xóa khỏi epoll
#define POLLRDHUP   0x2000  // Linux: đóng một chiều

#define EPOLLWRNORM 0x0100
#define EPOLLRDNORM 0x0040

#define bzero(ptr, size) memset((ptr), 0, (size))

static inline uint16_t htons(uint16_t x) {
    return (uint16_t)(((x & 0x00FF) << 8) | ((x & 0xFF00) >> 8));
}

static inline uint32_t htonl(uint32_t x) {
    return ((x & 0x000000FFU) << 24) |
           ((x & 0x0000FF00U) << 8)  |
           ((x & 0x00FF0000U) >> 8)  |
           ((x & 0xFF000000U) >> 24);
}

static inline uint32_t inet_addr(const char *cp) {
    // Very simple dummy: always return 127.0.0.1
    (void)cp;
    return 0x7F000001;  // 127.0.0.1 in hex (network byte order)
}

#define INADDR_ANY 0x00000000
#define PF_INET AF_INET


typedef void (*sighandler_t)(int);
typedef unsigned int sigset_t;

struct sigaction {
    sighandler_t sa_handler;
    unsigned long sa_flags;
    void (*sa_restorer)(void);
    sigset_t sa_mask;
};

static inline int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact) {
    (void)signum;
    (void)act;
    (void)oldact;
    return 0;
}

#define SIGPIPE 13

static inline int fork(void) {
    return -1; // Not supported on Windows
}

#include <cstdlib>
// static inline int setenv(const char *name, const char *value, int overwrite) {
//     if (!overwrite) {
//         size_t requiredSize = 0;
//         if (getenv(name) != NULL) return 0;
//     }
//     return _putenv_s(name, value);
// }

int setenv(const char *n, const char *value, int overwrite);
int socket(int domain, int type, int protocol);
int connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen);
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);


#endif // _WIN32

#endif // DUMMY_H