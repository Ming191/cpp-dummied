#include "dummy.h"
namespace {
    static uint8_t dummy_buf[10] = {0};
    static camera_fb_t fb = {dummy_buf, sizeof(dummy_buf)};
    unsigned long fake_time = 0;  
}

camera_fb_t* esp_camera_fb_get() {
    return &fb;
}

void esp_camera_fb_return(camera_fb_t* fb) {
    // Do nothing
}


unsigned long millis() {
    fake_time += 100;
    return fake_time;
}