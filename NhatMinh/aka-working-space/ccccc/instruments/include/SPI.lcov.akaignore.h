/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_SPI_H
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_SPI_H
#include <string>
#include <string.h>
#include <vector>
extern "C++" int AKA_mark(char* str);
extern "C++" void AKA_assert(char* actualName, int actualVal, char* expectedName, int expectedVal);
extern "C++" int AKA_assert_double(char* actualName, double actualVal, char* expectedName, double expectedVal);
extern "C++" int AKA_assert_ptr(char* actualName, void* actualVal, char* expectedName, void* expectedVal);
extern "C++" int AKA_fCall;
extern "C++" char* AKA_test_case_name;



#ifndef SPI_H
#define SPI_H
#include <cstddef>  // for size_t

// SPI modes
#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

// SPI bit order
#define MSBFIRST 1
#define LSBFIRST 0

// SPI clock dividers
#define SPI_CLOCK_DIV4 0x00
#define SPI_CLOCK_DIV16 0x01
#define SPI_CLOCK_DIV64 0x02
#define SPI_CLOCK_DIV128 0x03
#define SPI_CLOCK_DIV2 0x04
#define SPI_CLOCK_DIV8 0x05
#define SPI_CLOCK_DIV32 0x06

// Chip select pins (common definitions)
#define SPI0_CS0 10
#define SPI0_CS1 4
#define SPI1_CS0 52
#define SPI1_CS1 53

class SPISettings {
public:
public:
    unsigned long clock;
    unsigned char bitOrder;
    unsigned char dataMode;
    
    SPISettings(unsigned long clockFreq, unsigned char bitOrder, unsigned char dataMode) 
        : clock(clockFreq), bitOrder(bitOrder), dataMode(dataMode) {
AKA_fCall++; /* LCOV_EXCL_LINE */ }
    SPISettings() : clock(4000000), bitOrder(MSBFIRST), dataMode(SPI_MODE0) {
AKA_fCall++; /* LCOV_EXCL_LINE */ }
};

class SPIClass {
public:
public:
    void begin() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "SPI.h.begin.1003.stub"
}
    void end() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "SPI.h.end.1024.stub"
}
    
    void beginTransaction(SPISettings settings) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "SPI.h.beginTransaction.1049.stub"
}
    void endTransaction() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "SPI.h.endTransaction.1101.stub"
}
    
    unsigned char transfer(unsigned char data) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "SPI.h.transfer.1146.stub"
 return 0; }
    unsigned short transfer16(unsigned short data) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "SPI.h.transfer16.1209.stub"
 return 0; }
    void transfer(void* buf, size_t count) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "SPI.h.transfer.1265.stub"
}
    
    void setBitOrder(unsigned char bitOrder) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "SPI.h.setBitOrder.1318.stub"
}
    void setDataMode(unsigned char dataMode) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "SPI.h.setDataMode.1367.stub"
}
    void setClockDivider(unsigned char clockDiv) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "SPI.h.setClockDivider.1416.stub"
}
    
    // Legacy functions
    void attachInterrupt() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "SPI.h.attachInterrupt.1500.stub"
}
    void detachInterrupt() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "SPI.h.detachInterrupt.1531.stub"
}
};

extern SPIClass SPI;

// Additional SPI instances for boards with multiple SPI
extern SPIClass SPI1;
extern SPIClass SPI2;

#endif // SPI_H
#endif
