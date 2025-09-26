#ifndef DUMMY_BLUEPAD32_H
#define DUMMY_BLUEPAD32_H

#include <string>
#include <cstdint>
#include <iostream>

#define BP32_MAX_GAMEPADS 4  // Giới hạn số gamepad kết nối cùng lúc

// Dummy map function (Arduino-like)
inline int map(int x, int in_min, int in_max, int out_min, int out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// Dummy struct mô phỏng properties của controller
struct ControllerProperties {
    std::string product_id = "0000";
    std::string vendor_id = "0000";

    std::string getModelName() const {
        return "DummyGamepad";
    }
};

// Dummy class Controller
class Controller {
public:
    ControllerProperties getProperties() const {
        return ControllerProperties();
    }

    // Dummy trục điều khiển
    int axisY() const { return 100; }
    int axisRX() const { return -100; }
    bool hasData() const { return true; }
    // Dummy button input
    bool a() const { return true; }
    bool b() const { return true; }
    bool x() const { return true; }

    // Dummy LED functions
    void setColorLED(uint8_t r, uint8_t g, uint8_t b) {
        std::cout << "Setting LED color: R=" << (int)r << ", G=" << (int)g << ", B=" << (int)b << "\n";
    }

    void setPlayerLEDs(uint8_t leds) {
        std::cout << "Setting Player LEDs: " << std::hex << (int)leds << "\n";
    }

    // Dummy rumble
    void playDualRumble(uint32_t delayedStartMs, uint32_t durationMs, uint8_t weakMagnitude, uint8_t strongMagnitude) {
        std::cout << "Rumble: delay=" << delayedStartMs << "ms, duration=" << durationMs
                  << "ms, weak=" << (int)weakMagnitude << ", strong=" << (int)strongMagnitude << "\n";
    }

    bool isConnected() const { return true; }
    bool isGamepad() const { return true; }
};

typedef Controller* ControllerPtr;

// Dummy BP32 singleton-like object
struct {
    bool isReady() const { return true; }

    void setup(void (*onConnect)(ControllerPtr), void (*onDisconnect)(ControllerPtr)) {
        std::cout << "BP32 setup done with callbacks.\n";
    }

    void forgetBluetoothKeys() {
        std::cout << "Bluetooth keys forgotten.\n";
    }

    bool update() {
        std::cout << "BP32 updated.\n";
        return true;
    }

    const uint8_t* localBdAddress() const {
        static uint8_t addr[6] = {0xAA, 0xBB, 0xCC, 0x11, 0x22, 0x33};
        return addr;
    }

    const char* firmwareVersion() const {
        return "DummyFirmware 1.0";
    }

} BP32;


// Dummy Servo class (giả lập từ ESP32Servo)
class Servo {
public:
    void attach(int pin) {
        std::cout << "Servo attached to pin " << pin << "\n";
    }

    void write(int value) {
        std::cout << "Servo write: " << value << "\n";
    }
};
class String {
    std::string data;
public:
    String() = default;
    String(const char* str) : data(str) {}
    String(const std::string& str) : data(str) {}

    const char* c_str() const { return data.c_str(); }

    bool startsWith(const std::string& prefix) const {
        return data.rfind(prefix, 0) == 0;
    }

    String substring(size_t start, size_t end = std::string::npos) const {
        return data.substr(start, end - start);
    }

    int indexOf(const std::string& needle) const {
        auto pos = data.find(needle);
        return (pos == std::string::npos) ? -1 : static_cast<int>(pos);
    }

    int toInt() const {
        return std::stoi(data);
    }
};

typedef struct {
    uint8_t *buf;
    size_t len;
} camera_fb_t;

camera_fb_t* esp_camera_fb_get();
void esp_camera_fb_return(camera_fb_t* fb);

// DUMMY CHO WebsocketsMessage
// class WebsocketsMessage {
// public:
//     bool isText() const { return true; }
//     std::string data() const { return "dummy"; }
// };

// DUMMY CHO WebsocketsClient
// namespace websockets {
// class WebsocketsClient {
// public:
//     bool available() { return true; }
//     void sendBinary(const char* data, size_t len) {
//         printf("Dummy sendBinary called: %zu bytes\n", len);
//     }
//     void poll() {
//         printf("Dummy poll called\n");
//     }
// };

// // Dummy Websockets namespace and classes
// namespace websockets {

// class WebsocketsClient {
// public:
//     void onMessage(void (*callback)(String)) {
//         std::cout << "[WebsocketsClient] Message callback set.\n";
//     }

//     void poll() {
//         std::cout << "[WebsocketsClient] Polling...\n";
//     }

//     void send(const std::string& msg) {
//         std::cout << "[WebsocketsClient] Sending: " << msg << "\n";
//     }
// };

// // Simulated message received from WebSocket
// struct WebsocketsMessage {
//     std::string _data = "CONTROL:100:90";
//     const char* data() const {
//         return _data.c_str();
//     }
// };

// }  // namespace websockets
struct WebsocketsMessage {
    std::string _content = "dummy";

    std::string data() const {
        return _content;
    }

    const char* c_str() const {
        return _content.c_str();
    }

    size_t length() const {
        return _content.length();
    }

    // Bạn có thể thêm bất kỳ hàm nào mà code thật của bạn đang gọi từ WebsocketsMessage
};

// Dummy millis function (Arduino)
unsigned long millis();

// Dummy constrain function (Arduino)
template<typename T>
T constrain(T x, T minVal, T maxVal) {
    return std::min(std::max(x, minVal), maxVal);
}

// Dummy esp_err_t
typedef int esp_err_t;

// Dummy camera config
typedef struct {
    int ledc_channel;
    int ledc_timer;
    int pin_d0;
    int pin_d1;
    int pin_d2;
    int pin_d3;
    int pin_d4;
    int pin_d5;
    int pin_d6;
    int pin_d7;
    int pin_xclk;
    int pin_pclk;
    int pin_vsync;
    int pin_href;
    int pin_sscb_sda;
    int pin_sscb_scl;
    int pin_pwdn;
    int pin_reset;
    int xclk_freq_hz;
    int pixel_format;
} camera_config_t;

#define LEDC_CHANNEL_0 0
#define LEDC_TIMER_0 0
#define Y2_GPIO_NUM 2
#define Y3_GPIO_NUM 3
#define Y4_GPIO_NUM 4
#define Y5_GPIO_NUM 5
#define Y6_GPIO_NUM 6
#define Y7_GPIO_NUM 7
#define Y8_GPIO_NUM 8
#define Y9_GPIO_NUM 9
#define XCLK_GPIO_NUM 21
#define PCLK_GPIO_NUM 22
#define VSYNC_GPIO_NUM 23
#define HREF_GPIO_NUM 24
#define SIOD_GPIO_NUM 25
#define SIOC_GPIO_NUM 26
#define PWDN_GPIO_NUM 27
#define RESET_GPIO_NUM 28
#define PIXFORMAT_JPEG 1

// Dummy WebsocketsEvent enum
enum WebsocketsEvent {
    ConnectionOpened,
    ConnectionClosed,
    GotPing,
    GotPong
};

// Dummy ESP constants
#define FRAMESIZE_QVGA 3
#define ESP_OK 0

// Dummy esp_camera_init
inline esp_err_t esp_camera_init(void* config) {
    std::cout << "[Dummy] esp_camera_init called.\n";
    return ESP_OK;
}

// Dummy WiFi handling
#define WIFI_SSID "dummy_ssid"
#define WIFI_PASSWORD "dummy_pass"
#define WL_CONNECTED 3

class WiFiClass {
public:
    void begin(const char* ssid, const char* pass) {
        std::cout << "WiFi.begin(\"" << ssid << "\", \"" << pass << "\")\n";
    }

    int status() {
        static int attempts = 0;
        if (++attempts < 3) return 0;
        return WL_CONNECTED;
    }
};

extern WiFiClass WiFi;

inline void delay(int ms) {
    std::cout << "delay(" << ms << " ms)\n";
}

// Extend WebsocketsClient
namespace websockets {
class WebsocketsClient {
public:
    void onMessage(void (*callback)(String)) {
        std::cout << "[WebsocketsClient] Message callback set.\n";
    }

    void onEvent(void (*callback)(WebsocketsEvent, String)) {
        std::cout << "[WebsocketsClient] Event callback set.\n";
    }

    void poll() {
        std::cout << "[WebsocketsClient] Polling...\n";
    }

    void send(const std::string& msg) {
        std::cout << "[WebsocketsClient] Sending: " << msg << "\n";
    }

    bool connect(const char* url) {
        std::cout << "[WebsocketsClient] Connecting to: " << url << "\n";
        return true;
    }
    bool available() { return true; }
    void sendBinary(const char* data, size_t len) {
        printf("Dummy sendBinary called: %zu bytes\n", len);
    }
};
}


#endif // DUMMY_BLUEPAD32_H
