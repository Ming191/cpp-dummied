#ifndef JOYSTICK_H
#define JOYSTICK_H

// Joystick button count constants
#define JOYSTICK_DEFAULT_BUTTON_COUNT 32
#define JOYSTICK_DEFAULT_AXIS_COUNT 8
#define JOYSTICK_DEFAULT_HATSWITCH_COUNT 2
#define JOYSTICK_DEFAULT_REPORT_ID 0x03
#define JOYSTICK_TYPE_GAMEPAD 0x05

// Hat switch directions
#define JOYSTICK_HATSWITCH_RELEASE -1
#define JOYSTICK_HATSWITCH_N 0
#define JOYSTICK_HATSWITCH_NE 45
#define JOYSTICK_HATSWITCH_E 90
#define JOYSTICK_HATSWITCH_SE 135
#define JOYSTICK_HATSWITCH_S 180
#define JOYSTICK_HATSWITCH_SW 225
#define JOYSTICK_HATSWITCH_W 270
#define JOYSTICK_HATSWITCH_NW 315

class Joystick_ {
private:
    unsigned char _buttonCount;
    unsigned char _hatSwitchCount;
    bool _includeXAxis;
    bool _includeYAxis;
    bool _includeZAxis;
    bool _includeRxAxis;
    bool _includeRyAxis;
    bool _includeRzAxis;
    bool _includeRudder;
    bool _includeThrottle;
    bool _includeAccelerator;
    bool _includeBrake;
    bool _includeSteering;
    
    // Current state
    int _xAxis;
    int _yAxis;
    int _zAxis;
    int _rxAxis;
    int _ryAxis;
    int _rzAxis;
    int _rudder;
    int _throttle;
    int _accelerator;
    int _brake;
    int _steering;
    unsigned long _buttons;
    int _hatSwitches[4];
    
public:
    Joystick_(
        unsigned char hidReportId = 0x03,
        unsigned char joystickType = 0x04,
        unsigned char buttonCount = JOYSTICK_DEFAULT_BUTTON_COUNT,
        unsigned char hatSwitchCount = JOYSTICK_DEFAULT_HATSWITCH_COUNT,
        bool includeXAxis = true,
        bool includeYAxis = true,
        bool includeZAxis = true,
        bool includeRxAxis = true,
        bool includeRyAxis = true,
        bool includeRzAxis = true,
        bool includeRudder = true,
        bool includeThrottle = true,
        bool includeAccelerator = true,
        bool includeBrake = true,
        bool includeSteering = true
    ) : _buttonCount(buttonCount), _hatSwitchCount(hatSwitchCount),
        _includeXAxis(includeXAxis), _includeYAxis(includeYAxis), _includeZAxis(includeZAxis),
        _includeRxAxis(includeRxAxis), _includeRyAxis(includeRyAxis), _includeRzAxis(includeRzAxis),
        _includeRudder(includeRudder), _includeThrottle(includeThrottle),
        _includeAccelerator(includeAccelerator), _includeBrake(includeBrake), _includeSteering(includeSteering),
        _xAxis(0), _yAxis(0), _zAxis(0), _rxAxis(0), _ryAxis(0), _rzAxis(0),
        _rudder(0), _throttle(0), _accelerator(0), _brake(0), _steering(0), _buttons(0)
    {
        for (int i = 0; i < 4; i++) {
            _hatSwitches[i] = JOYSTICK_HATSWITCH_RELEASE;
        }
    }
    
    void begin(bool initAutoSendState = true) {}
    void end() {}
    
    // Axis functions
    void setXAxis(int value) { _xAxis = value; }
    void setYAxis(int value) { _yAxis = value; }
    void setZAxis(int value) { _zAxis = value; }
    void setRxAxis(int value) { _rxAxis = value; }
    void setRyAxis(int value) { _ryAxis = value; }
    void setRzAxis(int value) { _rzAxis = value; }
    void setRudder(int value) { _rudder = value; }
    void setThrottle(int value) { _throttle = value; }
    void setAccelerator(int value) { _accelerator = value; }
    void setBrake(int value) { _brake = value; }
    void setSteering(int value) { _steering = value; }
    
    // Button functions
    void setButton(unsigned char button, unsigned char value) {
        if (value == 0) {
            _buttons &= ~(1UL << button);
        } else {
            _buttons |= (1UL << button);
        }
    }
    void pressButton(unsigned char button) { setButton(button, 1); }
    void releaseButton(unsigned char button) { setButton(button, 0); }
    
    // Hat switch functions
    void setHatSwitch(int hatSwitchIndex, int value) {
        if (hatSwitchIndex >= 0 && hatSwitchIndex < 4) {
            _hatSwitches[hatSwitchIndex] = value;
        }
    }
    
    // Send state
    void sendState() {}
    
    // Auto send state control
    void setAutoSendState(bool value) {}
    bool getAutoSendState() { return true; }
};

#endif // JOYSTICK_H