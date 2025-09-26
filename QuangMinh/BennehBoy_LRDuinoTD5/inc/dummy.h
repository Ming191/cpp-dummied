// dummy.h

#ifndef DUMMY_H
#define DUMMY_H

#include <cstdint>
#include <cstdlib>

#include <cstddef>
#include <cstring>
#include <chrono>
// Định nghĩa lại byte nếu cần
#ifndef byte
typedef uint8_t byte;
#endif

// Dummy glyphs (unsigned char*)
static const unsigned char trbBMP[]  = {0x01};
static const unsigned char egtBMP[]  = {0x02};
static const unsigned char tboxBMP[] = {0x03};
static const unsigned char gopBMP[]  = {0x04};
static const unsigned char eopBMP[]  = {0x05};
static const unsigned char eotBMP[]  = {0x06};
static const unsigned char coollev[] = {0x07};
static const unsigned char Gauge[]   = {0x08};

// Dummy constants
#define MASTER 99
#define NOLOWARN -1
#define NOHIWARN -2

// Dummy types
#define BOOST3BAR 1
#define KTYPE     2
#define ERR2081   3
#define CH100PSI  4
#define EARTHSW   5
#define OBD       6

// Dummy pin/pid
#define BOST   10
#define TBXT   11
#define FULP   12
#define GBOP   13
#define GBOT   14
#define OILP   15
#define OILT   16
#define COOL   17
#define OBDCON 18
#define OBDRPM 19
#define OBDINJ 20
#define OBDSPD 21

#define K_OUT 7 
#define K_IN  8 

#define HIGH 1
#define LOW  0
#define OUTPUT 1
#define INPUT  0

inline void digitalWrite(int pin, int value) {
    // Dummy implementation
    // std::cout << "digitalWrite(" << pin << ", " << value << ")\n";
}

inline void pinMode(int pin, int mode) {
    // Dummy implementation
    // std::cout << "pinMode(" << pin << ", " << mode << ")\n";
}

class DummySerial {
public:
    int read() {
        static int counter = 0;
        if (counter++ < 3)
            return -1;  // giả lập chưa đọc được
        return 0x41;    // giả lập đọc thành công
    }

    void write(uint8_t b) {
        // giả lập ghi byte
        // std::cout << "write: " << +b << "\n";
    }

    void begin(int baudrate) {
        // giả lập bắt đầu serial
    }
};
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)

// Global dummy instance
static DummySerial obdSerial;
static long fake_time = 0;

inline long millis() {
    return fake_time += 1;  // giả lập thời gian tăng dần mỗi lần gọi
}


#endif // DUMMY_H
