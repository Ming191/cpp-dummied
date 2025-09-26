#ifndef SRC_ARDUINO_H_
#define SRC_ARDUINO_H_

#include <cstring>
#include <cstdlib>
#include <string>

// DUMMY Serial implementation
class DummySerialClass {
public:
  void begin(int);
  void print(const char* s);
  void print(unsigned int n);
  void print(float f, int = 2);
  void println();
  void println(const char* s);
  void println(unsigned int n);
  void println(float f, int = 2);
  void println(std::string s);
};

extern DummySerialClass Serial;

// DUMMY WiFi and related constants/types
class DummyWiFiClass {
public:
  std::string macAddress();
  bool getAutoConnect();
  int status();
  void disconnect(bool);
  void begin(const char*, const char*);
};

extern DummyWiFiClass WiFi;

typedef int wl_status_t;
#define WL_NO_SHIELD 0
#define WL_IDLE_STATUS 1
#define WL_NO_SSID_AVAIL 2
#define WL_SCAN_COMPLETED 3
#define WL_CONNECTED 4
#define WL_CONNECT_FAILED 5
#define WL_CONNECTION_LOST 6
#define WL_DISCONNECTED 7

// DUMMY TR_PRINT_LONG macro
#define TR_PRINT_LONG(port, level, value) ((void)0)

#endif // SRC_ARDUINO_H_ 