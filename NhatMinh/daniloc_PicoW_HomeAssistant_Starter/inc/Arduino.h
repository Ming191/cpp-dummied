#ifndef ARDUINO_H
#define ARDUINO_H

// Basic Arduino constants
#define HIGH 1
#define LOW 0
#define INPUT 0
#define OUTPUT 1
#define LED_BUILTIN 13

// Basic types
typedef unsigned char byte;
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

// Dummy Arduino functions
void pinMode(int pin, int mode); 
void digitalWrite(int pin, int value);
int digitalRead(int pin);
void delay(unsigned long ms);

// Serial class dummy
class SerialClass {
public:
    void begin(unsigned long baud) {}
    void print(const char* str) {}
    void println(const char* str) {}
    void print(int val) {}
    void println(int val) {}
};

extern SerialClass Serial;

#endif // ARDUINO_H