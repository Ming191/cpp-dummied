#ifndef _DUMMY__H_
#define _DUMMY__H_

typedef void* PVOID;

typedef int HANDLE;

#define INFINITE 9999999

#define WAIT_FAILED -1


typedef unsigned long ULONG;
typedef unsigned long DWORD;

#define _MAX_PATH 260

#ifndef WAIT_OBJECT_0
#define WAIT_OBJECT_0 0
#endif


  typedef int BOOL;
  #define TRUE 1
  #define FALSE 0

  typedef struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    void* lpSecurityDescriptor;
    BOOL bInheritHandle;
  } SECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

  // Constants
  #define FILE_SHARE_READ     0x00000001
  #define FILE_SHARE_WRITE    0x00000002
  #define FILE_SHARE_DELETE   0x00000004

  #define GENERIC_READ        0x80000000
  #define GENERIC_WRITE       0x40000000

  #define OPEN_EXISTING       3

  #ifndef WIN_SEMAPHORE_CONSTANTS_H
#define WIN_SEMAPHORE_CONSTANTS_H

// Access rights for semaphore (Windows compatibility)
#define SEMAPHORE_MODIFY_STATE     0x0002
#define SEMAPHORE_ALL_ACCESS       0x001F0003

// Synchronization access right
#define SYNCHRONIZE                0x00100000L

// Standard access rights
#define DELETE                     0x00010000L
#define READ_CONTROL               0x00020000L
#define WRITE_DAC                  0x00040000L
#define WRITE_OWNER                0x00080000L

// Generic access rights (optional, but often used)
#define GENERIC_READ               0x80000000L
#define GENERIC_WRITE              0x40000000L
#define GENERIC_EXECUTE            0x20000000L
#define GENERIC_ALL                0x10000000L

#ifndef _MAX_DRIVE
#define _MAX_DRIVE 3
#endif

#ifndef _MAX_DIR
#define _MAX_DIR 256
#endif

#ifndef _MAX_FNAME
#define _MAX_FNAME 256
#endif

#ifndef _MAX_EXT
#define _MAX_EXT 256
#endif

#endif // WIN_SEMAPHORE_CONSTANTS_H

#ifndef HANDLE_FLAG_INHERIT
#define HANDLE_FLAG_INHERIT 0x00000001
#endif

#ifndef HANDLE_FLAG_PROTECT_FROM_CLOSE
#define HANDLE_FLAG_PROTECT_FROM_CLOSE 0x00000002
#endif


#ifndef WIN_FILETIME_COMPAT_H
#define WIN_FILETIME_COMPAT_H

#include <stdint.h>

typedef struct _FILETIME {
    uint32_t dwLowDateTime;
    uint32_t dwHighDateTime;
} FILETIME;

#endif // WIN_FILETIME_COMPAT_H


#ifdef _WIN64
  typedef unsigned __int64 ULONG_PTR;
#else
  typedef unsigned long ULONG_PTR;
#endif

HANDLE OpenSemaphoreA(unsigned long, int, const char*) {
    return (HANDLE)1; // dummy non-null pointer
}

typedef struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union {
      struct {
        DWORD Offset;
        DWORD OffsetHigh;
      };
      PVOID Pointer;
    };
    HANDLE hEvent;
} OVERLAPPED, *LPOVERLAPPED;

bool CloseHandle(HANDLE hello) { return true; }

#endif
