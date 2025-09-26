/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_DUE_CAN_H
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_DUE_CAN_H
#include <string>
#include <string.h>
#include <vector>
extern "C++" int AKA_mark(char* str);
extern "C++" void AKA_assert(char* actualName, int actualVal, char* expectedName, int expectedVal);
extern "C++" int AKA_assert_double(char* actualName, double actualVal, char* expectedName, double expectedVal);
extern "C++" int AKA_assert_ptr(char* actualName, void* actualVal, char* expectedName, void* expectedVal);
extern "C++" int AKA_fCall;
extern "C++" char* AKA_test_case_name;



#ifndef DUE_CAN_H
#define DUE_CAN_H

// Basic types if not already defined
#ifndef uint8_t
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
#endif

// CAN Frame data union for flexible access
typedef union {
    unsigned char byte[8];      // Byte access
    unsigned char bytes[8];     // Alternative byte access
    unsigned short word[4];     // Word access
    unsigned int dword[2];      // Double word access
    unsigned long long qword;   // Quad word access
    
    // Bit field access (dummy implementation)
    struct {
        unsigned int bit0:1, bit1:1, bit2:1, bit3:1, bit4:1, bit5:1, bit6:1, bit7:1;
        unsigned int bit8:1, bit9:1, bit10:1, bit11:1, bit12:1, bit13:1, bit14:1, bit15:1;
        unsigned int bit16:1, bit17:1, bit18:1, bit19:1, bit20:1, bit21:1, bit22:1, bit23:1;
        unsigned int bit24:1, bit25:1, bit26:1, bit27:1, bit28:1, bit29:1, bit30:1, bit31:1;
        unsigned int bit32:1, bit33:1, bit34:1, bit35:1, bit36:1, bit37:1, bit38:1, bit39:1;
        unsigned int bit40:1, bit41:1, bit42:1, bit43:1, bit44:1, bit45:1, bit46:1, bit47:1;
        unsigned int bit48:1, bit49:1, bit50:1, bit51:1, bit52:1, bit53:1, bit54:1, bit55:1;
        unsigned int bit56:1, bit57:1, bit58:1, bit59:1, bit60:1, bit61:1, bit62:1, bit63:1;
    };
    
    // Array access for bits (alternative approach)
    bool bit[64];
} CAN_FRAME_DATA;

// CAN Frame structure
typedef struct {
    unsigned int id;           // CAN ID
    unsigned char length;      // Data length (0-8 bytes)
    CAN_FRAME_DATA data;      // Data bytes with multiple access methods
    bool extended;             // Extended frame format
    bool rtr;                  // Remote transmission request
    unsigned int timestamp;    // Frame timestamp
} CAN_FRAME;

// CAN Bus speeds
#define CAN_BPS_125K    125000
#define CAN_BPS_250K    250000
#define CAN_BPS_500K    500000
#define CAN_BPS_1000K   1000000

// CAN Bus numbers
#define CAN0    0
#define CAN1    1

// Forward declaration
class CANRaw;

// Main CAN class
class CANRaw {
public:
public:
    int busNumber;
    unsigned int baudRate;
    bool initialized;
    
public:
    CANRaw(int bus);
    
    // Initialization
    bool begin();
    bool begin(unsigned int baudrate);
    bool begin(unsigned int baudrate, unsigned char enable_pins);
    
    // Frame operations
    bool available();
    bool read(CAN_FRAME &frame);
    bool sendFrame(CAN_FRAME &frame);
    
    // Filter operations
    bool setFilter(unsigned int id, unsigned int mask, bool extended = false);
    bool setFilterRange(unsigned int idLow, unsigned int idHigh, bool extended = false);
    bool setRXFilter(int filterNum, unsigned int id, unsigned int mask, bool extended = false);
    void clearFilters();
    
    // Status and control
    void enable();
    void disable();
    bool isEnabled();
    unsigned int getBaudRate();
    
    // Statistics
    unsigned int getRxCount();
    unsigned int getTxCount();
    unsigned int getErrorCount();
    
    // Callback support
    void setCallback(int mailbox, void (*callback)(CAN_FRAME*));
    void attachCANInterrupt(void (*callback)(CAN_FRAME*));
    void detachCANInterrupt();
};

// Global CAN instances
extern CANRaw Can0;
extern CANRaw Can1;

// Utility functions
void canInit(int bus, unsigned int baudrate);
void canSetMode(int bus, int mode);
bool canSend(int bus, CAN_FRAME &frame);
bool canReceive(int bus, CAN_FRAME &frame);

// Helper macros
#define CAN_FRAME_INIT {0, 0, {0}, false, false, 0}

// Error codes
#define CAN_OK          0
#define CAN_ERROR       -1
#define CAN_TIMEOUT     -2
#define CAN_BUSY        -3

#endif // DUE_CAN_H
#endif
