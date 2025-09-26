#ifndef SRC_HAINTEGRATION
#define SRC_HAINTEGRATION

#include <ArduinoHA.h>

class HAIntegration {
    public:
    static void loop();
    static void configure();
    static void switchHandler(bool state, HASwitch* sender);
};

#endif // SRC_HAINTEGRATION
