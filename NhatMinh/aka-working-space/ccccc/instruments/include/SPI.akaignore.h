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
    
    /** Instrumented function SPISettings(unsigned long,unsigned char,unsigned char) */
SPISettings(unsigned long clockFreq, unsigned char bitOrder, unsigned char dataMode) 
        : clock(clockFreq), bitOrder(bitOrder), dataMode(dataMode) /* << Aka begin of function  SPISettings(unsigned long clockFreq, unsigned char bitOrder, unsigned char dataMode) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPISettings\\SPISettings(unsigned long,unsigned char,unsigned char)");AKA_fCall++;}
    /** Instrumented function SPISettings() */
SPISettings() : clock(4000000), bitOrder(MSBFIRST), dataMode(SPI_MODE0) /* << Aka begin of function  SPISettings() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPISettings\\SPISettings()");AKA_fCall++;}
};

class SPIClass {
public:
public:
    /** Instrumented function begin() */
void begin() /* << Aka begin of function void begin() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\begin()");AKA_fCall++;
	/** Include stub source code */
	#include "SPI.h.begin.1003.stub"
}
    /** Instrumented function end() */
void end() /* << Aka begin of function void end() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\end()");AKA_fCall++;
	/** Include stub source code */
	#include "SPI.h.end.1024.stub"
}
    
    /** Instrumented function beginTransaction(SPISettings) */
void beginTransaction(SPISettings settings) /* << Aka begin of function void beginTransaction(SPISettings settings) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\beginTransaction(SPISettings)");AKA_fCall++;
	/** Include stub source code */
	#include "SPI.h.beginTransaction.1049.stub"
}
    /** Instrumented function endTransaction() */
void endTransaction() /* << Aka begin of function void endTransaction() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\endTransaction()");AKA_fCall++;
	/** Include stub source code */
	#include "SPI.h.endTransaction.1101.stub"
}
    
    /** Instrumented function transfer(unsigned char) */
unsigned char transfer(unsigned char data) /* << Aka begin of function unsigned char transfer(unsigned char data) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\transfer(unsigned char)");AKA_fCall++;
	/** Include stub source code */
	#include "SPI.h.transfer.1146.stub"
 AKA_mark("lis===49###sois===1177###eois===1186###lif===0###soif===45###eoif===54###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\transfer(unsigned char)");return 0; }
    /** Instrumented function transfer16(unsigned short) */
unsigned short transfer16(unsigned short data) /* << Aka begin of function unsigned short transfer16(unsigned short data) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\transfer16(unsigned short)");AKA_fCall++;
	/** Include stub source code */
	#include "SPI.h.transfer16.1209.stub"
 AKA_mark("lis===50###sois===1243###eois===1252###lif===0###soif===49###eoif===58###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\transfer16(unsigned short)");return 0; }
    /** Instrumented function transfer(void*,size_t) */
void transfer(void* buf, size_t count) /* << Aka begin of function void transfer(void* buf, size_t count) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\transfer(void*,size_t)");AKA_fCall++;
	/** Include stub source code */
	#include "SPI.h.transfer.1265.stub"
}
    
    /** Instrumented function setBitOrder(unsigned char) */
void setBitOrder(unsigned char bitOrder) /* << Aka begin of function void setBitOrder(unsigned char bitOrder) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\setBitOrder(unsigned char)");AKA_fCall++;
	/** Include stub source code */
	#include "SPI.h.setBitOrder.1318.stub"
}
    /** Instrumented function setDataMode(unsigned char) */
void setDataMode(unsigned char dataMode) /* << Aka begin of function void setDataMode(unsigned char dataMode) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\setDataMode(unsigned char)");AKA_fCall++;
	/** Include stub source code */
	#include "SPI.h.setDataMode.1367.stub"
}
    /** Instrumented function setClockDivider(unsigned char) */
void setClockDivider(unsigned char clockDiv) /* << Aka begin of function void setClockDivider(unsigned char clockDiv) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\setClockDivider(unsigned char)");AKA_fCall++;
	/** Include stub source code */
	#include "SPI.h.setClockDivider.1416.stub"
}
    
    // Legacy functions
    /** Instrumented function attachInterrupt() */
void attachInterrupt() /* << Aka begin of function void attachInterrupt() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\attachInterrupt()");AKA_fCall++;
	/** Include stub source code */
	#include "SPI.h.attachInterrupt.1500.stub"
}
    /** Instrumented function detachInterrupt() */
void detachInterrupt() /* << Aka begin of function void detachInterrupt() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\SPI.h\\SPIClass\\detachInterrupt()");AKA_fCall++;
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
