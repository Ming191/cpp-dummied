#ifndef ARDUINO_HA_H
#define ARDUINO_HA_H

#include "Arduino.h"
#include "WiFi.h"

// Forward declarations
class HASwitch;
class HADevice;

// Switch handler callback type
typedef void (*SwitchCommandCallback)(bool state, HASwitch* sender);

// HADevice class
class HADevice {
public:
    HADevice() {}
    void setUniqueId(const byte* id, uint16_t length) {}
    void setName(const char* name) {}
    void setSoftwareVersion(const char* version) {}
};

// HAMqtt class
class HAMqtt {
private:
    WiFiClient* client;
    HADevice* device;
    
public:
    HAMqtt(WiFiClient& client, HADevice& device) : client(&client), device(&device) {}

    bool begin(const char* broker, const char* username, const char* password) {
        return true; // Dummy success
    }
    
    bool begin(IPAddress broker, const char* username, const char* password) {
        return true; // Dummy success
    }
    
    void loop() {}
};

// HASwitch class
class HASwitch {
private:
    const char* id;
    SwitchCommandCallback callback;
    
public:
    HASwitch(const char* uniqueId) : id(uniqueId), callback(nullptr) {}
    
    void onCommand(SwitchCommandCallback cb) {
        callback = cb;
    }
    
    void setName(const char* name) {}
    
    void setState(bool state) {}
    
    // Simulate command callback for testing
    void simulateCommand(bool state) {
        if (callback) {
            callback(state, this);
        }
    }
};

#endif // ARDUINO_HA_H