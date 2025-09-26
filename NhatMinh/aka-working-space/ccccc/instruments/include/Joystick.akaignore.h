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
    /** Instrumented function Joystick_(unsigned char= 0x03,unsigned char= 0x04,unsigned char= ,unsigned char= ,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true) */
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
    /* << Aka begin of function  Joystick_(
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
    ) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\Joystick_(unsigned char= 0x03,unsigned char= 0x04,unsigned char= ,unsigned char= ,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true)");AKA_fCall++;
        int AKA_BLOCK_LOOP_2594 = 0;
    AKA_mark("lis===78###sois===2599###eois===2609###lif===24###soif===1284###eoif===1294###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\Joystick_(unsigned char= 0x03,unsigned char= 0x04,unsigned char= ,unsigned char= ,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true)");
for (int i = 0; AKA_mark("lis===78###sois===2610###eois===2615###lif===24###soif===1295###eoif===1300###ifc===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\Joystick_(unsigned char= 0x03,unsigned char= 0x04,unsigned char= ,unsigned char= ,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true)") && (AKA_mark("lis===78###sois===2610###eois===2615###lif===24###soif===1295###eoif===1300###isc===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\Joystick_(unsigned char= 0x03,unsigned char= 0x04,unsigned char= ,unsigned char= ,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true)") && (i < 4)); ({AKA_mark("lis===78###sois===2617###eois===2620###lif===24###soif===1302###eoif===1305###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\Joystick_(unsigned char= 0x03,unsigned char= 0x04,unsigned char= ,unsigned char= ,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true)");i++;})) {
        AKA_BLOCK_LOOP_2594++;
        if (AKA_BLOCK_LOOP_2594 > 1000) {
            //break;
        }
            AKA_mark("lis===79###sois===2637###eois===2682###lif===25###soif===1322###eoif===1367###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\Joystick_(unsigned char= 0x03,unsigned char= 0x04,unsigned char= ,unsigned char= ,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true,bool= true)");_hatSwitches[i] = JOYSTICK_HATSWITCH_RELEASE;
        }
    }
    
    /** Instrumented function begin(bool= true) */
void begin(bool initAutoSendState = true) /* << Aka begin of function void begin(bool initAutoSendState = true) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\begin(bool= true)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.begin.2717.stub"
}
    /** Instrumented function end() */
void end() /* << Aka begin of function void end() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\end()");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.end.2767.stub"
}
    
    // Axis functions
    /** Instrumented function setXAxis(int) */
void setXAxis(int value) /* << Aka begin of function void setXAxis(int value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setXAxis(int)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setXAxis.2815.stub"
 AKA_mark("lis===87###sois===2837###eois===2852###lif===0###soif===27###eoif===42###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setXAxis(int)");_xAxis = value; }
    /** Instrumented function setYAxis(int) */
void setYAxis(int value) /* << Aka begin of function void setYAxis(int value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setYAxis(int)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setYAxis.2865.stub"
 AKA_mark("lis===88###sois===2887###eois===2902###lif===0###soif===27###eoif===42###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setYAxis(int)");_yAxis = value; }
    /** Instrumented function setZAxis(int) */
void setZAxis(int value) /* << Aka begin of function void setZAxis(int value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setZAxis(int)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setZAxis.2915.stub"
 AKA_mark("lis===89###sois===2937###eois===2952###lif===0###soif===27###eoif===42###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setZAxis(int)");_zAxis = value; }
    /** Instrumented function setRxAxis(int) */
void setRxAxis(int value) /* << Aka begin of function void setRxAxis(int value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setRxAxis(int)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setRxAxis.2965.stub"
 AKA_mark("lis===90###sois===2988###eois===3004###lif===0###soif===28###eoif===44###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setRxAxis(int)");_rxAxis = value; }
    /** Instrumented function setRyAxis(int) */
void setRyAxis(int value) /* << Aka begin of function void setRyAxis(int value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setRyAxis(int)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setRyAxis.3017.stub"
 AKA_mark("lis===91###sois===3040###eois===3056###lif===0###soif===28###eoif===44###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setRyAxis(int)");_ryAxis = value; }
    /** Instrumented function setRzAxis(int) */
void setRzAxis(int value) /* << Aka begin of function void setRzAxis(int value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setRzAxis(int)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setRzAxis.3069.stub"
 AKA_mark("lis===92###sois===3092###eois===3108###lif===0###soif===28###eoif===44###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setRzAxis(int)");_rzAxis = value; }
    /** Instrumented function setRudder(int) */
void setRudder(int value) /* << Aka begin of function void setRudder(int value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setRudder(int)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setRudder.3121.stub"
 AKA_mark("lis===93###sois===3144###eois===3160###lif===0###soif===28###eoif===44###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setRudder(int)");_rudder = value; }
    /** Instrumented function setThrottle(int) */
void setThrottle(int value) /* << Aka begin of function void setThrottle(int value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setThrottle(int)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setThrottle.3173.stub"
 AKA_mark("lis===94###sois===3198###eois===3216###lif===0###soif===30###eoif===48###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setThrottle(int)");_throttle = value; }
    /** Instrumented function setAccelerator(int) */
void setAccelerator(int value) /* << Aka begin of function void setAccelerator(int value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setAccelerator(int)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setAccelerator.3229.stub"
 AKA_mark("lis===95###sois===3257###eois===3278###lif===0###soif===33###eoif===54###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setAccelerator(int)");_accelerator = value; }
    /** Instrumented function setBrake(int) */
void setBrake(int value) /* << Aka begin of function void setBrake(int value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setBrake(int)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setBrake.3291.stub"
 AKA_mark("lis===96###sois===3313###eois===3328###lif===0###soif===27###eoif===42###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setBrake(int)");_brake = value; }
    /** Instrumented function setSteering(int) */
void setSteering(int value) /* << Aka begin of function void setSteering(int value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setSteering(int)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setSteering.3341.stub"
 AKA_mark("lis===97###sois===3366###eois===3384###lif===0###soif===30###eoif===48###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setSteering(int)");_steering = value; }
    
    // Button functions
    /** Instrumented function setButton(unsigned char,unsigned char) */
void setButton(unsigned char button, unsigned char value) /* << Aka begin of function void setButton(unsigned char button, unsigned char value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setButton(unsigned char,unsigned char)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setButton.3428.stub"

        if (AKA_mark("lis===101###sois===3496###eois===3506###lif===1###soif===73###eoif===83###ifc===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setButton(unsigned char,unsigned char)") && (AKA_mark("lis===101###sois===3496###eois===3506###lif===1###soif===73###eoif===83###isc===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setButton(unsigned char,unsigned char)") && (value == 0))) {
            AKA_mark("lis===102###sois===3523###eois===3552###lif===2###soif===100###eoif===129###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setButton(unsigned char,unsigned char)");_buttons &= ~(1UL << button);
        } else {
            AKA_mark("lis===104###sois===3584###eois===3612###lif===4###soif===161###eoif===189###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setButton(unsigned char,unsigned char)");_buttons |= (1UL << button);
        }
    }
    /** Instrumented function pressButton(unsigned char) */
void pressButton(unsigned char button) /* << Aka begin of function void pressButton(unsigned char button) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\pressButton(unsigned char)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.pressButton.3641.stub"
 AKA_mark("lis===107###sois===3677###eois===3698###lif===0###soif===41###eoif===62###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\pressButton(unsigned char)");setButton(button, 1); }
    /** Instrumented function releaseButton(unsigned char) */
void releaseButton(unsigned char button) /* << Aka begin of function void releaseButton(unsigned char button) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\releaseButton(unsigned char)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.releaseButton.3711.stub"
 AKA_mark("lis===108###sois===3749###eois===3770###lif===0###soif===43###eoif===64###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\releaseButton(unsigned char)");setButton(button, 0); }
    
    // Hat switch functions
    /** Instrumented function setHatSwitch(int,int) */
void setHatSwitch(int hatSwitchIndex, int value) /* << Aka begin of function void setHatSwitch(int hatSwitchIndex, int value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setHatSwitch(int,int)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setHatSwitch.3818.stub"

        if (AKA_mark("lis===112###sois===3877###eois===3918###lif===1###soif===64###eoif===105###ifc===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setHatSwitch(int,int)") && ((AKA_mark("lis===112###sois===3877###eois===3896###lif===1###soif===64###eoif===83###isc===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setHatSwitch(int,int)") && (hatSwitchIndex >= 0)) && (AKA_mark("lis===112###sois===3900###eois===3918###lif===1###soif===87###eoif===105###isc===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setHatSwitch(int,int)") && (hatSwitchIndex < 4)))) {
            AKA_mark("lis===113###sois===3935###eois===3972###lif===2###soif===122###eoif===159###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setHatSwitch(int,int)");_hatSwitches[hatSwitchIndex] = value;
        }
else {
AKA_mark("lis===-112-###sois===-3877-###eois===-387741-###lif===-1-###soif===-###eoif===-105-###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setHatSwitch(int,int)");
}
    }
    
    // Send state
    /** Instrumented function sendState() */
void sendState() /* << Aka begin of function void sendState() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\sendState()");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.sendState.4026.stub"
}
    
    // Auto send state control
    /** Instrumented function setAutoSendState(bool) */
void setAutoSendState(bool value) /* << Aka begin of function void setAutoSendState(bool value) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\setAutoSendState(bool)");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.setAutoSendState.4089.stub"
}
    /** Instrumented function getAutoSendState() */
bool getAutoSendState() /* << Aka begin of function bool getAutoSendState() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\getAutoSendState()");AKA_fCall++;
	/** Include stub source code */
	#include "Joystick.h.getAutoSendState.4131.stub"
 AKA_mark("lis===122###sois===4152###eois===4164###lif===0###soif===26###eoif===38###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\Joystick.h\\Joystick_\\getAutoSendState()");return true; }
};

#endif // JOYSTICK_H
#endif
