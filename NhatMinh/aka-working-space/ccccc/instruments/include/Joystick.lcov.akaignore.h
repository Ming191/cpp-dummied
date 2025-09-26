/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_JOYSTICK_H
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_JOYSTICK_H
#include <string>
#include <string.h>
#include <vector>
extern "C++" int AKA_mark(char* str);
extern "C++" void AKA_assert(char* actualName, int actualVal, char* expectedName, int expectedVal);
extern "C++" int AKA_assert_double(char* actualName, double actualVal, char* expectedName, double expectedVal);
extern "C++" int AKA_assert_ptr(char* actualName, void* actualVal, char* expectedName, void* expectedVal);
extern "C++" int AKA_fCall;
extern "C++" char* AKA_test_case_name;



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
public:
public:
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
AKA_fCall++; /* LCOV_EXCL_LINE */ 
        for (int i = 0; i < 4; i++) {
            _hatSwitches[i] = JOYSTICK_HATSWITCH_RELEASE;
        }
    }
    
    void begin(bool initAutoSendState = true) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.begin.2717.stub"
}
    void end() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.end.2767.stub"
}
    
    // Axis functions
    void setXAxis(int value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setXAxis.2815.stub"
 _xAxis = value; }
    void setYAxis(int value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setYAxis.2865.stub"
 _yAxis = value; }
    void setZAxis(int value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setZAxis.2915.stub"
 _zAxis = value; }
    void setRxAxis(int value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setRxAxis.2965.stub"
 _rxAxis = value; }
    void setRyAxis(int value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setRyAxis.3017.stub"
 _ryAxis = value; }
    void setRzAxis(int value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setRzAxis.3069.stub"
 _rzAxis = value; }
    void setRudder(int value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setRudder.3121.stub"
 _rudder = value; }
    void setThrottle(int value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setThrottle.3173.stub"
 _throttle = value; }
    void setAccelerator(int value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setAccelerator.3229.stub"
 _accelerator = value; }
    void setBrake(int value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setBrake.3291.stub"
 _brake = value; }
    void setSteering(int value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setSteering.3341.stub"
 _steering = value; }
    
    // Button functions
    void setButton(unsigned char button, unsigned char value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setButton.3428.stub"

        if (value == 0) {
            _buttons &= ~(1UL << button);
        } else {
            _buttons |= (1UL << button);
        }
    }
    void pressButton(unsigned char button) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.pressButton.3641.stub"
 setButton(button, 1); }
    void releaseButton(unsigned char button) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.releaseButton.3711.stub"
 setButton(button, 0); }
    
    // Hat switch functions
    void setHatSwitch(int hatSwitchIndex, int value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setHatSwitch.3818.stub"

        if (hatSwitchIndex >= 0 && hatSwitchIndex < 4) {
            _hatSwitches[hatSwitchIndex] = value;
        }
    }
    
    // Send state
    void sendState() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.sendState.4026.stub"
}
    
    // Auto send state control
    void setAutoSendState(bool value) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.setAutoSendState.4089.stub"
}
    bool getAutoSendState() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "Joystick.h.getAutoSendState.4131.stub"
 return true; }
};

#endif // JOYSTICK_H
#endif
