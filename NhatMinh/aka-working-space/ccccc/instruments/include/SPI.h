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
    unsigned long clock;
    unsigned char bitOrder;
    unsigned char dataMode;
    
    SPISettings(unsigned long clockFreq, unsigned char bitOrder, unsigned char dataMode) 
        : clock(clockFreq), bitOrder(bitOrder), dataMode(dataMode) {}
    SPISettings() : clock(4000000), bitOrder(MSBFIRST), dataMode(SPI_MODE0) {}
};

class SPIClass {
public:
    void begin() {}
    void end() {}
    
    void beginTransaction(SPISettings settings) {}
    void endTransaction() {}
    
    unsigned char transfer(unsigned char data) { return 0; }
    unsigned short transfer16(unsigned short data) { return 0; }
    void transfer(void* buf, size_t count) {}
    
    void setBitOrder(unsigned char bitOrder) {}
    void setDataMode(unsigned char dataMode) {}
    void setClockDivider(unsigned char clockDiv) {}
    
    // Legacy functions
    void attachInterrupt() {}
    void detachInterrupt() {}
};

extern SPIClass SPI;

// Additional SPI instances for boards with multiple SPI
extern SPIClass SPI1;
extern SPIClass SPI2;

#endif // SPI_H