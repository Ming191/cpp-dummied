#ifndef DUMMY_H_
#define DUMMY_H_

#define VERSION "0.1.0"
typedef int sigset_t;

inline int sigemptyset(sigset_t* set) { *set = 0; return 0; }
inline int sigaddset(sigset_t* set, int signo) { *set |= (1 << signo); return 0; }
inline int sigdelset(sigset_t* set, int signo) { *set &= ~(1 << signo); return 0; }
inline int sigismember(const sigset_t* set, int signo) { return (*set & (1 << signo)) != 0; }

#define SIGPIPE 13   // hoặc giá trị bất kỳ (không có tác dụng)
#define SIGHUP  1
#define SIGUSR1 10

inline int fork() {} 
inline int setsid() {}
inline int socketpair() {}

#endif
