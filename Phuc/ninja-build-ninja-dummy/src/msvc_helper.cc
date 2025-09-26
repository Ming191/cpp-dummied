#ifndef _WIN32  // Nếu không phải Windows, tự định nghĩa các hàm tương ứng
#include <fcntl.h>
#include "unistd.h"
#include <sys/wait.h>
#include <cstring>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "msvc_helper.h"
#include "dummy.h"

#include "unistd.h"

// Giả lập HANDLE bằng int
#define INVALID_HANDLE_VALUE -1

static inline void Win32Fatal(const char* msg) {
  //perror(msg);
  //// exit(1);
}

static HANDLE CreateFileA(const char* path, int access, int share_mode,
                          void* security_attrs, int creation_disposition,
                          int flags, void* template_file) {
  (void)share_mode;
  (void)security_attrs;
  (void)template_file;
  int flags_conv = 0;

  if (access == O_RDONLY)
    flags_conv = O_RDONLY;
  else if (access == O_WRONLY)
    flags_conv = O_WRONLY;
  else
    flags_conv = O_RDWR;

  if (creation_disposition == 0)  // OPEN_EXISTING
    flags_conv |= 0;

  return open(path, flags_conv);
}

static bool CreatePipe(HANDLE* read_end, HANDLE* write_end, void* sa, size_t size) {
  (void)sa;
  (void)size;
  int pipefd[2];
  if (pipe(pipefd) != 0)
    return false;
  *read_end = pipefd[0];
  *write_end = pipefd[1];
  return true;
}

static bool SetHandleInformation(HANDLE h, int flag, int value) {
  // (void)h;
  // (void)flag;
  // (void)value;
  return true;
}

static HANDLE GetStdHandle(int which) {
  return which;  // STDOUT_FILENO, etc.
}

#define STD_ERROR_HANDLE 2
#define STARTF_USESTDHANDLES 1

struct PROCESS_INFORMATION {
  pid_t hProcess;
  pid_t hThread;
};

struct STARTUPINFOA {
  size_t cb;
  int dwFlags;
  HANDLE hStdInput;
  HANDLE hStdOutput;
  HANDLE hStdError;
};

static bool CreateProcessA(const char*, char* cmdline,
                           void*, void*, bool,
                           int, void*,
                           void*, STARTUPINFOA* si,
                           PROCESS_INFORMATION* pi) {
  (void)si;
  int pid = fork();
  if (pid == -1)
    return false;
  if (pid == 0) {
    // dup2(si->hStdInput, STDIN_FILENO);
    // dup2(si->hStdOutput, STDOUT_FILENO);
    // dup2(si->hStdError, STDERR_FILENO);
    // execl("/bin/sh", "sh", "-c", cmdline, (char*)NULL);
    // _exit(127);
  }
  pi->hProcess = pid;
  pi->hThread = 0;
  return true;
}

static int WaitForSingleObject(pid_t pid, int timeout) {
  (void)timeout;
  int status = 0;
  return waitpid(pid, &status, 0);
}



static bool GetExitCodeProcess(pid_t pid, unsigned long* code) {
  int status = 0;
  if (waitpid(pid, &status, 0) < 0)
    return false;
  if (WIFEXITED(status))
    *code = WEXITSTATUS(status);
  else
    *code = 1;
  return true;
}

static bool ReadFile(HANDLE h, void* buf, size_t len, unsigned long* read_len, void* overlap) {
  (void)overlap;
  ssize_t n = read(h, buf, len);
  if (n < 0)
    return false;
  *read_len = static_cast<unsigned long>(n);
  return true;
}

#define ERROR_BROKEN_PIPE EPIPE

#endif  // !_WIN32
