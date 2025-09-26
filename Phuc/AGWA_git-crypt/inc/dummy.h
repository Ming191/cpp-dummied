#ifndef _DUMMY_H
#define _DUMMY_H
// Windows API Stub Functions
// Cross-platform stubs using only standard C++ libraries

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <vector>

// Define nullptr for older C++ standards
#ifndef nullptr
#define nullptr NULL
#endif

// Windows types stubs
typedef int HANDLE;
typedef unsigned long DWORD;
typedef char* LPTSTR;
typedef const char* LPCTSTR;
typedef struct {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME;

typedef struct {
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
} SYSTEMTIME;

typedef struct {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
} WIN32_FIND_DATAA;

// Windows constants
#define MAX_PATH 260
#define INVALID_HANDLE_VALUE (-1)
#define INVALID_FILE_ATTRIBUTES ((DWORD)-1)
#define ERROR_FILE_NOT_FOUND 2
#define ERROR_BUFFER_OVERFLOW 111
#define ERROR_NO_MORE_FILES 18
#define FILE_WRITE_ATTRIBUTES 0x0100
#define FILE_SHARE_READ 0x00000001
#define OPEN_EXISTING 3
#define TEXT(x) x
#define _O_BINARY 0x8000

// Global variables for simulation
static DWORD g_last_error = 0;
static int g_temp_counter = 1;

// Helper function to check if file exists (cross-platform)
bool file_exists(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}

// GetTempPath stub
DWORD GetTempPath(DWORD nBufferLength, char* lpBuffer) {
    const char* temp_path;
    
    // Try to get temp path from environment variables
    temp_path = std::getenv("TEMP");
    if (!temp_path) temp_path = std::getenv("TMP");
    if (!temp_path) temp_path = std::getenv("TMPDIR");
    if (!temp_path) temp_path = "/tmp";
    
    size_t len = strlen(temp_path);
    
    if (nBufferLength == 0) {
        return len + 1;
    }
    
    if (nBufferLength < len + 1) {
        return len + 1;
    }
    
    strcpy(lpBuffer, temp_path);
    // Ensure path ends with separator
    if (len > 0 && lpBuffer[len-1] != '/' && lpBuffer[len-1] != '\\') {
        strcat(lpBuffer, "/");
        len++;
    }
    
    return len;
}

// GetTempFileName stub
DWORD GetTempFileName(const char* lpPathName, const char* lpPrefixString, 
                     DWORD uUnique, char* lpTempFileName) {
    if (uUnique == 0) {
        uUnique = g_temp_counter++;
    }
    
    snprintf(lpTempFileName, MAX_PATH, "%s%s%d.tmp", 
             lpPathName, lpPrefixString, uUnique);
    
    return uUnique;
}

// GetLastError stub
DWORD GetLastError() {
    return g_last_error;
}

// DeleteFile stub
int DeleteFile(const char* lpFileName) {
    if (std::remove(lpFileName) == 0) {
        g_last_error = 0;
        return 1;
    }
    g_last_error = ERROR_FILE_NOT_FOUND;
    return 0;
}

// GetFileAttributes stub
DWORD GetFileAttributes(const char* lpFileName) {
    if (file_exists(lpFileName)) {
        return 0; // FILE_ATTRIBUTE_NORMAL
    }
    g_last_error = ERROR_FILE_NOT_FOUND;
    return INVALID_FILE_ATTRIBUTES;
}

// CreateDirectory stub (simplified - just return success)
int CreateDirectory(const char* lpPathName, void* lpSecurityAttributes) {
    // Simplified stub - assume success
    g_last_error = 0;
    return 1;
}

// GetModuleFileNameA stub
DWORD GetModuleFileNameA(void* hModule, char* lpFilename, DWORD nSize) {
    // Simple stub - returns a fake executable path
    const char* fake_path = "git-crypt.exe";
    size_t len = strlen(fake_path);
    
    if (nSize <= len) {
        return nSize;
    }
    
    strcpy(lpFilename, fake_path);
    return len;
}

// CreateFileA stub
HANDLE CreateFileA(const char* lpFileName, DWORD dwDesiredAccess,
                   DWORD dwShareMode, void* lpSecurityAttributes,
                   DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes,
                   HANDLE hTemplateFile) {
    if (file_exists(lpFileName)) {
        g_last_error = 0;
        return 1; // Return a fake valid handle
    }
    g_last_error = ERROR_FILE_NOT_FOUND;
    return INVALID_HANDLE_VALUE;
}

// GetSystemTime stub
void GetSystemTime(SYSTEMTIME* lpSystemTime) {
    std::time_t now = std::time(nullptr);
    std::tm* utc_tm = std::gmtime(&now);
    
    lpSystemTime->wYear = utc_tm->tm_year + 1900;
    lpSystemTime->wMonth = utc_tm->tm_mon + 1;
    lpSystemTime->wDayOfWeek = utc_tm->tm_wday;
    lpSystemTime->wDay = utc_tm->tm_mday;
    lpSystemTime->wHour = utc_tm->tm_hour;
    lpSystemTime->wMinute = utc_tm->tm_min;
    lpSystemTime->wSecond = utc_tm->tm_sec;
    lpSystemTime->wMilliseconds = 0;
}

// SystemTimeToFileTime stub
int SystemTimeToFileTime(const SYSTEMTIME* lpSystemTime, FILETIME* lpFileTime) {
    // Simple conversion - just set to current time
    std::time_t now = std::time(nullptr);
    lpFileTime->dwLowDateTime = (DWORD)now;
    lpFileTime->dwHighDateTime = (DWORD)(now >> 32);
    return 1;
}

// SetFileTime stub
int SetFileTime(HANDLE hFile, const FILETIME* lpCreationTime,
                const FILETIME* lpLastAccessTime, const FILETIME* lpLastWriteTime) {
    // Stub - always return success
    g_last_error = 0;
    return 1;
}

// CloseHandle stub
int CloseHandle(HANDLE hObject) {
    // Stub - always return success
    g_last_error = 0;
    return 1;
}

// DeleteFileA stub (same as DeleteFile but explicit A suffix)
int DeleteFileA(const char* lpFileName) {
    return DeleteFile(lpFileName);
}

// Simple directory listing simulation
static std::string g_current_search_dir;
static int g_current_file_index = 0;
static std::vector<std::string> g_fake_files = {"file1.txt", "file2.txt", "subdir"};

// FindFirstFileA stub
HANDLE FindFirstFileA(const char* lpFileName, WIN32_FIND_DATAA* lpFindFileData) {
    // Extract directory path from pattern
    std::string pattern(lpFileName);
    size_t last_slash = pattern.find_last_of("/\\");
    
    if (last_slash != std::string::npos) {
        g_current_search_dir = pattern.substr(0, last_slash);
    } else {
        g_current_search_dir = ".";
    }
    
    g_current_file_index = 0;
    
    if (g_current_file_index < g_fake_files.size()) {
        // Fill in the find data
        strncpy(lpFindFileData->cFileName, g_fake_files[g_current_file_index].c_str(), 
                sizeof(lpFindFileData->cFileName) - 1);
        lpFindFileData->cFileName[sizeof(lpFindFileData->cFileName) - 1] = '\0';
        lpFindFileData->dwFileAttributes = 0;
        
        g_current_file_index++;
        return 1; // Return a fake valid handle
    }
    
    g_last_error = ERROR_FILE_NOT_FOUND;
    return INVALID_HANDLE_VALUE;
}

// FindNextFileA stub
int FindNextFileA(HANDLE hFindFile, WIN32_FIND_DATAA* lpFindFileData) {
    if (g_current_file_index < g_fake_files.size()) {
        // Fill in the find data
        strncpy(lpFindFileData->cFileName, g_fake_files[g_current_file_index].c_str(), 
                sizeof(lpFindFileData->cFileName) - 1);
        lpFindFileData->cFileName[sizeof(lpFindFileData->cFileName) - 1] = '\0';
        lpFindFileData->dwFileAttributes = 0;
        
        g_current_file_index++;
        return 1; // Success
    }
    
    g_last_error = ERROR_NO_MORE_FILES;
    return 0; // No more files
}

// FindClose stub
int FindClose(HANDLE hFindFile) {
    g_current_file_index = 0;
    g_last_error = 0;
    return 1;
}

// _setmode stub (for binary mode)
int _setmode(int fd, int mode) {
    // Stub - return success
    return 0;
}

// _fileno stub
int _fileno(FILE* stream) {
    // Simple stub - return fake file descriptor
    if (stream == stdin) return 0;
    if (stream == stdout) return 1;
    if (stream == stderr) return 2;
    return 3;
}



#endif


// Dummy dirent.h implementation for cross-platform compatibility
// Uses only standard C/C++ libraries

#ifndef DIRENT_H_DUMMY
#define DIRENT_H_DUMMY

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

// Define nullptr for older C++ standards
#ifndef nullptr
#define nullptr NULL
#endif

// dirent.h types and constants
#define DT_UNKNOWN 0
#define DT_REG 1     // Regular file
#define DT_DIR 2     // Directory
#define DT_LNK 3     // Symbolic link

// struct dirent equivalent
struct dirent {
    long d_ino;              // inode number
    unsigned short d_reclen; // record length
    unsigned char d_type;    // file type
    char d_name[256];        // filename
};

// DIR structure equivalent
struct DIR {
    std::string path;
    std::vector<std::string> files;
    size_t current_index;
    struct dirent current_entry;
    bool is_valid;
};

// Global variables for simulation
static std::vector<std::string> g_fake_directory_contents = {
    ".",
    "..",
    "file1.txt",
    "file2.cpp",
    "subdir",
    "readme.md",
    "config.ini"
};

// Helper function to check if file exists (cross-platform)
static bool file_exists_dirent(const char* filename) {

}

// Helper function to determine file type (simplified)
static unsigned char get_file_type(const char* filename) {

}

// opendir implementation
DIR* opendir(const char* dirname) {
}

// readdir implementation
struct dirent* readdir(DIR* dirp) {

}

// closedir implementation
int closedir(DIR* dirp) {

}

// rewinddir implementation
void rewinddir(DIR* dirp) {

}

// telldir implementation (returns current position)
long telldir(DIR* dirp) {

}

// seekdir implementation (seeks to position)
void seekdir(DIR* dirp, long pos) {

}

// scandir implementation (simplified version)
int scandir(const char* dirname, struct dirent*** namelist,
            int (*filter)(const struct dirent*),
            int (*compare)(const struct dirent**, const struct dirent**)) {

}

// alphasort implementation (for use with scandir)
int alphasort(const struct dirent** a, const struct dirent** b) {
    // return strcmp((*a)->d_name, (*b)->d_name);
}

// versionsort implementation (for use with scandir)
int versionsort(const struct dirent** a, const struct dirent** b) {
    // Simplified version - just use alphasort
    // return alphasort(a, b);
}

#endif // DIRENT_H_DUMMY