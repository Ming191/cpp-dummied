#ifndef _DUMMY_H
#define _DUMMY_H

#include <cstdint>
#include <cstring>
#include <string>

#define TASK_STACK_SIZE 2048  // Đơn vị: byte

#define IPPROTO_UDP 17  // Standard protocol number for UDP

typedef unsigned char boolean;

typedef unsigned int UINT;
typedef uint64_t FSIZE_t;  // supports large files
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef unsigned long long QWORD;
typedef uint64_t u64;
#define FRAME_BUFFER_SIZE 1024  // Kích thước tùy theo ứng dụng
typedef unsigned long long LONGLONG;
typedef unsigned long long ULONGLONG;

typedef BYTE DSTATUS;
// typedef BYTE TCHAR;

typedef DWORD LBA_t;    // or uint32_t / uint64_t
// typedef DWORD FSIZE_t; // or uint32_t / uint64_t

typedef enum {
    RES_OK = 0,     // 0: Successful
    RES_ERROR,      // 1: R/W Error
    RES_WRPRT,      // 2: Write Protected
    RES_NOTRDY,     // 3: Not Ready
    RES_PARERR      // 4: Invalid Parameter
} DRESULT;


// ===== circle/net/ipaddress.h stubs =====

class CIPAddress {
public:
    // Constants
    static const unsigned ADDR_SIZE = 4;
    
    // Constructors
    CIPAddress() {}
    CIPAddress(uint32_t nAddress) {}
    CIPAddress(uint8_t nAddress0, uint8_t nAddress1, uint8_t nAddress2, uint8_t nAddress3) {}
    CIPAddress(const char* pString) {}
    CIPAddress(const CIPAddress& rAddress) {}
    
    // Operators
    CIPAddress& operator=(const CIPAddress& rAddress) { return *this; }
    CIPAddress& operator=(uint32_t nAddress) { return *this; }
    bool operator==(const CIPAddress& rAddress) const { return false; }
    bool operator!=(const CIPAddress& rAddress) const { return false; }
    
    // Methods
    uint32_t Get() const { return 0; }
    void Set(uint32_t nAddress) {}
    void Set(uint8_t nAddress0, uint8_t nAddress1, uint8_t nAddress2, uint8_t nAddress3) {}
    void Set(const char* pString) {}
    uint8_t operator[](unsigned nIndex) const { return 0; }
    void CopyTo(uint8_t* pBuffer) const {}
    void Format(char* pBuffer, unsigned nBufSize) const {}
    bool IsNull() const { return true; }
    bool IsValid() const { return false; }
    bool IsBroadcast() const { return false; }
    bool IsMulticast() const { return false; }
    
private:
    uint8_t m_nAddress[ADDR_SIZE];
};

// ===== fatfs/ff.h stubs =====

// FatFs Types
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef unsigned long long QWORD;
typedef WORD WCHAR;
typedef BYTE TCHAR;

// FatFs Constants
#define FF_VOLUMES          1
#define FF_STR_VOLUME_ID    0
#define FF_VOLUME_STRS      "RAM","NAND","CF","SD","SD2","USB","USB2","USB3"
#define FF_MULTI_PARTITION  0
#define FF_MIN_SS           512
#define FF_MAX_SS           4096
#define FF_LBA64            0
#define FF_MIN_GPT          0x10000000
#define FF_USE_TRIM         0
#define FF_FS_NOFSINFO      0
#define FF_FS_READONLY      0
#define FF_FS_MINIMIZE      0
#define FF_USE_STRFUNC      0
#define FF_PRINT_LLI        0
#define FF_PRINT_FLOAT      0
#define FF_STRF_ENCODE      0
#define FF_USE_FIND         0
#define FF_USE_MKFS         0
#define FF_USE_FASTSEEK     0
#define FF_USE_EXPAND       0
#define FF_USE_CHMOD        0
#define FF_USE_LABEL        0
#define FF_USE_FORWARD      0
#define FF_USE_STRFUNC      0
#define FF_CODE_PAGE        437
#define FF_USE_LFN          0
#define FF_MAX_LFN          255
#define FF_LFN_UNICODE      0
#define FF_LFN_BUF          255
#define FF_SFN_BUF          12
#define FF_FS_RPATH         0
#define FF_FS_LOCK          0
#define FF_FS_REENTRANT     0
#define FF_FS_TIMEOUT       1000
#define FF_SYNC_t           void*

// File access mode and open method flags
#define FA_READ             0x01
#define FA_WRITE            0x02
#define FA_OPEN_EXISTING    0x00
#define FA_CREATE_NEW       0x04
#define FA_CREATE_ALWAYS    0x08
#define FA_OPEN_ALWAYS      0x10
#define FA_OPEN_APPEND      0x30

// Fast seek controls
#define CREATE_LINKMAP      ((DWORD)0x00000001)

// Format options
#define FM_FAT              0x01
#define FM_FAT32            0x02
#define FM_EXFAT            0x04
#define FM_ANY              0x07
#define FM_SFD              0x08

// Filesystem type
#define FS_FAT12            1
#define FS_FAT16            2
#define FS_FAT32            3
#define FS_EXFAT            4

// File attributes
#define AM_RDO              0x01
#define AM_HID              0x02
#define AM_SYS              0x04
#define AM_DIR              0x10
#define AM_ARC              0x20

// FatFs Result Codes
typedef enum {
    FR_OK = 0,
    FR_DISK_ERR,
    FR_INT_ERR,
    FR_NOT_READY,
    FR_NO_FILE,
    FR_NO_PATH,
    FR_INVALID_NAME,
    FR_DENIED,
    FR_EXIST,
    FR_INVALID_OBJECT,
    FR_WRITE_PROTECTED,
    FR_INVALID_DRIVE,
    FR_NOT_ENABLED,
    FR_NO_FILESYSTEM,
    FR_MKFS_ABORTED,
    FR_TIMEOUT,
    FR_LOCKED,
    FR_NOT_ENOUGH_CORE,
    FR_TOO_MANY_OPEN_FILES,
    FR_INVALID_PARAMETER
} FRESULT;

// File objects
typedef struct {
    void* fs;
    WORD id;
    BYTE attr;
    BYTE stat;
    DWORD sclust;
    DWORD clust;
    DWORD sect;
    DWORD dir_sect;
    BYTE* dir_ptr;
    DWORD* cltbl;
    DWORD fsize;
    DWORD fptr;
    DWORD dsect;
    DWORD csect;
} FIL;

// Directory objects
typedef struct {
    void* fs;
    WORD id;
    WORD attr;
    WORD lfnidx;
    BYTE stat;
    DWORD sclust;
    DWORD clust;
    DWORD sect;
    BYTE* dir;
    BYTE* fn;
    DWORD blk_ofs;
    const TCHAR* pat;
} DIR;

// File information
typedef struct {
    DWORD fsize;
    WORD fdate;
    WORD ftime;
    BYTE fattrib;
    TCHAR altname[13];
    TCHAR fname[FF_MAX_LFN + 1];
} FILINFO;

// Filesystem information
typedef struct {
    BYTE fs_type;
    BYTE n_fats;
    WORD n_rootdir;
    DWORD n_fatent;
    DWORD fsize;
    DWORD volbase;
    DWORD fatbase;
    DWORD dirbase;
    DWORD database;
    DWORD winsect;
    BYTE win[FF_MAX_SS];
} FATFS;

// Format parameter structure
typedef struct {
    BYTE fmt;
    BYTE n_fat;
    WORD align;
    WORD n_root;
    DWORD au_size;
} MKFS_PARM;

// FatFs Function Stubs
FRESULT f_open(FIL* fp, const TCHAR* path, BYTE mode) { return FR_OK; }
FRESULT f_close(FIL* fp) { return FR_OK; }
FRESULT f_read(FIL* fp, void* buff, UINT btr, UINT* br) { return FR_OK; }
FRESULT f_write(FIL* fp, const void* buff, UINT btw, UINT* bw) { return FR_OK; }
FRESULT f_lseek(FIL* fp, FSIZE_t ofs) { return FR_OK; }
FRESULT f_truncate(FIL* fp) { return FR_OK; }
FRESULT f_sync(FIL* fp) { return FR_OK; }
FRESULT f_opendir(DIR* dp, const TCHAR* path) { return FR_OK; }
FRESULT f_closedir(DIR* dp) { return FR_OK; }
FRESULT f_readdir(DIR* dp, FILINFO* fno) { return FR_OK; }
FRESULT f_findfirst(DIR* dp, FILINFO* fno, const TCHAR* path, const TCHAR* pattern) { return FR_OK; }
FRESULT f_findnext(DIR* dp, FILINFO* fno) { return FR_OK; }
FRESULT f_mkdir(const TCHAR* path) { return FR_OK; }
FRESULT f_unlink(const TCHAR* path) { return FR_OK; }
FRESULT f_rename(const TCHAR* path_old, const TCHAR* path_new) { return FR_OK; }
FRESULT f_stat(const TCHAR* path, FILINFO* fno) { return FR_OK; }
FRESULT f_chmod(const TCHAR* path, BYTE attr, BYTE mask) { return FR_OK; }
FRESULT f_utime(const TCHAR* path, const FILINFO* fno) { return FR_OK; }
FRESULT f_chdir(const TCHAR* path) { return FR_OK; }
FRESULT f_chdrive(const TCHAR* path) { return FR_OK; }
FRESULT f_getcwd(TCHAR* buff, UINT len) { return FR_OK; }
FRESULT f_getfree(const TCHAR* path, DWORD* nclst, FATFS** fatfs) { return FR_OK; }
FRESULT f_getlabel(const TCHAR* path, TCHAR* label, DWORD* vsn) { return FR_OK; }
FRESULT f_setlabel(const TCHAR* label) { return FR_OK; }
FRESULT f_forward(FIL* fp, UINT(*func)(const BYTE*,UINT), UINT btf, UINT* bf) { return FR_OK; }
FRESULT f_expand(FIL* fp, FSIZE_t fsz, BYTE opt) { return FR_OK; }
FRESULT f_mount(FATFS* fs, const TCHAR* path, BYTE opt) { return FR_OK; }
FRESULT f_mkfs(const TCHAR* path, const MKFS_PARM* opt, void* work, UINT len) { return FR_OK; }
FRESULT f_fdisk(BYTE pdrv, const DWORD* szt, void* work) { return FR_OK; }
FRESULT f_setcp(WORD cp) { return FR_OK; }
int f_putc(TCHAR c, FIL* fp) { return 0; }
int f_puts(const TCHAR* str, FIL* fp) { return 0; }
int f_printf(FIL* fp, const TCHAR* str, ...) { return 0; }
TCHAR* f_gets(TCHAR* buff, int len, FIL* fp) { return nullptr; }

// Disk I/O Functions
DSTATUS disk_initialize(BYTE pdrv) { return 0; }
DSTATUS disk_status(BYTE pdrv) { return 0; }
DRESULT disk_read(BYTE pdrv, BYTE* buff, LBA_t sector, UINT count) { return RES_OK; }
DRESULT disk_write(BYTE pdrv, const BYTE* buff, LBA_t sector, UINT count) { return RES_OK; }
DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void* buff) { return RES_OK; }
DWORD get_fattime(void) { return 0; }

// ===== Properties/propertiesfatfsfile.h stubs =====

class CPropertiesFatFsFile {
public:
    // Constructors
    CPropertiesFatFsFile() {}
    CPropertiesFatFsFile(const char* pFileName, const char* pMode) {}
    CPropertiesFatFsFile(FIL* pFile) {}
    
    // Destructor
    ~CPropertiesFatFsFile() {}
    
    // Methods
    bool Open(const char* pFileName, const char* pMode) { return false; }
    bool IsOpen() const { return false; }
    void Close() {}
    char* GetLine(char* pBuffer, unsigned nBufSize) { return nullptr; }
    bool WriteLine(const char* pLine) { return false; }
    bool Flush() { return false; }
    unsigned GetSize() const { return 0; }
    bool SetPosition(unsigned nPosition) { return false; }
    unsigned GetPosition() const { return 0; }
    bool Read(void* pBuffer, unsigned nCount) { return false; }
    bool Write(const void* pBuffer, unsigned nCount) { return false; }
    
private:
    FIL* m_pFile;
    bool m_bOwnFile;
};

// ===== circle/sysconfig.h stubs =====

// System Configuration Constants
#define KERNEL_MAX_SIZE                 (2 * 1024 * 1024)
#define KERNEL_DEFAULT_SIZE             (1 * 1024 * 1024)
#define STACK_SIZE                      0x20000
#define EXCEPTION_STACK_SIZE            0x8000
#define PAGE_SIZE                       0x1000
#define MEGABYTE                        0x100000
#define GIGABYTE                        0x40000000UL

// ARM specific
#define ARM_STRICT_ALIGNMENT            1
#define ARM_ALLOW_MULTI_CORE            1

// Memory configuration
#define MEM_SIZE                        (512 * MEGABYTE)
#define GPU_MEM_SIZE                    (64 * MEGABYTE)
#define ARM_MEM_SIZE                    (MEM_SIZE - GPU_MEM_SIZE)

// Peripheral addresses
#define ARM_IO_BASE                     0x3F000000
#define ARM_IO_SIZE                     0x01000000

// Interrupt configuration
#define ARM_MAX_MULTI_CORE              4
#define IRQ_LINES                       72
#define ARM_IRQS_PER_REG                32

// Timer configuration
#define CLOCKHZ                         1000000
#define HZ                              100

// USB configuration
#define USE_USB_SOF_INTR                1
#define USE_USB_FIQ                     1

// Debug configuration
#define USE_SERIAL_GPIO14_15            1
#define USE_QEMU_USB_FIX                0

// System configuration functions
class CSysConfig {
public:
    static CSysConfig* Get() { return &s_Instance; }
    
    // Memory configuration
    unsigned GetMemSize() const { return MEM_SIZE; }
    unsigned GetArmMemSize() const { return ARM_MEM_SIZE; }
    unsigned GetGpuMemSize() const { return GPU_MEM_SIZE; }
    
    // Board configuration
    unsigned GetMachineType() const { return 0; }
    unsigned GetBoardRevision() const { return 0; }
    
    // Clock configuration
    unsigned GetClockRate(unsigned nClockId) const { return 0; }
    bool SetClockRate(unsigned nClockId, unsigned nRate) { return false; }
    
    // CPU configuration
    unsigned GetCpuCores() const { return 4; }
    unsigned GetCpuTemperature() const { return 0; }
    
    // Power configuration
    unsigned GetPowerState(unsigned nDeviceId) const { return 0; }
    bool SetPowerState(unsigned nDeviceId, unsigned nState) { return false; }
    
private:
    static CSysConfig s_Instance;
    
    CSysConfig() {}
};

CSysConfig CSysConfig::s_Instance;

// Additional system configuration constants
#define SYSTEM_CALL_STACK_SIZE          0x4000
#define EXCEPTION_STACK_SIZE            0x8000
#define ABORT_STACK_SIZE                0x1000
#define IRQ_STACK_SIZE                  0x8000
#define FIQ_STACK_SIZE                  0x4000

// Memory mapping constants
#define COHERENT_SLOT_SIZE              (16 * MEGABYTE)
#define NUM_COHERENT_SLOTS              16

// Boot configuration
#define BOOT_DELAY                      0
#define BOOT_PARTITION                  0

// Network configuration
#define NET_MAX_FRAME_SIZE              1518
#define NET_FRAME_BUFFER_SIZE           1600

// File system configuration
#define FS_SIMULTANEOUS_OPEN_FILES      10
#define FS_SECTOR_BUF_SIZE              512



// ----------------------
// Dummy class: CTask
// ----------------------
// Dummy task base class
class CTask {
public:
    CTask() = default;
    virtual ~CTask() = default;

    // Entry point for derived classes
    virtual void Run() = 0;  // Pure virtual — must override

    void Start() {
        Run();  // Call overridden method
    }
};

// ----------------------
// Dummy class: CBcmRandomNumberGenerator
// ----------------------
class CBcmRandomNumberGenerator {
public:
    CBcmRandomNumberGenerator() {
    }

    u64 generate() {
        return 42;  // Dummy value
    }
};

// ----------------------------
// CSocket stub
// ----------------------------
class CSocket {
public:
    CSocket() {}
    ~CSocket() {}

    bool Bind(uint16_t port, int protocol = IPPROTO_UDP) {
        //std::cout << "[CSocket] Binding to port " << port << " with protocol " << protocol << "\n";
        return true;
    }

    int ReceiveFrom(char* buffer, int bufferSize, std::string& remoteAddr, uint16_t& remotePort) {
        //std::cout << "[CSocket] Receiving data from remote\n";
        // Dummy return values
        remoteAddr = "192.168.0.100";
        remotePort = 12345;
        return 0;
    }

};

#include <cstring>

class CString {
public:
    CString() {}
    CString(const char* s) {}
    CString(const CString& other) {}

    ~CString() {}

    int Compare(const CString& str) const {
        return 0; // stub
    }

    CString& operator=(const CString& other) { return *this; }
    CString& operator=(const char* s) { return *this; }

    bool operator==(const CString& other) const { return false; }
    bool operator!=(const CString& other) const { return true; }
    CString operator+(const CString& other) const { return CString(); }
    CString& operator+=(const CString& other) { return *this; }

    int GetLength() const { return 0; }
    bool IsEmpty() const { return true; }

    void Format(const char* fmt, ...) {}
    void MakeUpper() {}
    void MakeLower() {}
    void Trim() {}

    CString Left(int count) const { return CString(); }
    CString Right(int count) const { return CString(); }
    CString Mid(int pos, int count = -1) const { return CString(); }

    int Replace(const char* oldStr, const char* newStr) { return 0; }

    const char* GetString() const { return ""; }
    operator const char*() const { return ""; }
};



// ----------------------------
// CNetSubSystem stub (singleton)
// ----------------------------
class CNetSubSystem {
public:
    static CNetSubSystem& Get() {
        static CNetSubSystem instance;
        return instance;
    }

    void Init() {
        //std::cout << "[CNetSubSystem] Initialized\n";
    }

private:
    CNetSubSystem() {}
    ~CNetSubSystem() {}
    CNetSubSystem(const CNetSubSystem&) = delete;
    CNetSubSystem& operator=(const CNetSubSystem&) = delete;
};


class CPtrList {
public:
    CPtrList() {}
    ~CPtrList() {}

    void AddHead(void* ptr) {}
    void AddTail(void* ptr) {}
    void* RemoveHead() { return nullptr; }
    void* RemoveTail() { return nullptr; }
    void RemoveAll() {}

    size_t GetCount() const { return 0; }
    bool IsEmpty() const { return true; }

    // You can add iterator support if needed
};

class CMutex {
public:
    CMutex() {}
    ~CMutex() {}

    void Lock() {}
    void Unlock() {}
    bool TryLock() { return true; }
};

class CSynchronizationEvent {
public:
    CSynchronizationEvent() {}
    ~CSynchronizationEvent() {}

    void SetEvent() {}
    void ResetEvent() {}
    void Wait() {}
    bool WaitTimeout(int milliseconds) { return true; }
};

#include <functional>

class CTimer {
public:
    CTimer() {}
    ~CTimer() {}

    // Thiết lập timer
    void Start(uint32_t milliseconds, bool repeat = false) {}

    // Dừng timer
    void Stop() {}

    // Kiểm tra trạng thái
    bool IsRunning() const { return false; }

    // Gán callback khi timeout (không thực thi trong stub)
    void SetCallback(std::function<void()> callback) {}

    // Trả về thời gian đã trôi qua (stub: luôn 0)
    uint32_t Elapsed() const { return 0; }
};

#include <iostream>
#include <string>
#include <cstdint>
#include <map>

// ----------------------------
// IPPROTO_UDP stub
// ----------------------------



// ----------------------------
// CScheduler stub
// ----------------------------
class CScheduler {
public:
    CScheduler() {}
    ~CScheduler() {}

    void ScheduleTask(const std::string& name, void(*func)(), int intervalMs) {
        //std::cout << "[CScheduler] Scheduled task: " << name << " every " << intervalMs << " ms\n";
    }
};



#endif