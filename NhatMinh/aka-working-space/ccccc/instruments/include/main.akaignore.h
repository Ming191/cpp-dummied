/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_MAIN_H
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_MAIN_H
#include <string>
#include <string.h>
#include <vector>
extern "C++" int AKA_mark(char* str);
extern "C++" void AKA_assert(char* actualName, int actualVal, char* expectedName, int expectedVal);
extern "C++" int AKA_assert_double(char* actualName, double actualVal, char* expectedName, double expectedVal);
extern "C++" int AKA_assert_ptr(char* actualName, void* actualVal, char* expectedName, void* expectedVal);
extern "C++" int AKA_fCall;
extern "C++" char* AKA_test_case_name;



#undef min
#undef max
/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__SPI_H_
#define AKA_INCLUDE__SPI_H_
#include <SPI.akaignore.h>
#endif

// #include <McpDigitalPot.h>
/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__CANPROCESSOR_H_
#define AKA_INCLUDE__CANPROCESSOR_H_
#include <CANProcessor.akaignore.h>
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__JOYSTICK_H_
#define AKA_INCLUDE__JOYSTICK_H_
#include <Joystick.akaignore.h>
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__POSE_H_
#define AKA_INCLUDE__POSE_H_
#include <Pose.akaignore.h>
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__XBOXBUTTONS_H_
#define AKA_INCLUDE__XBOXBUTTONS_H_
#include <XboxButtons.akaignore.h>
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__EMULATIONMODE_H_
#define AKA_INCLUDE__EMULATIONMODE_H_
#include <EmulationMode.akaignore.h>
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__GEARSENSOR_H_
#define AKA_INCLUDE__GEARSENSOR_H_
#include <GearSensor.akaignore.h>
#endif

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define STEERING_RANGE 720
#define BRAKE_MAX 100
#define ACCEL_MAX 255

// digital potentiometer
float resistance = 9760.0; // 9.76 kohm - needs to be calibrated for each digital pot
float accelScaler = 255.0 / (float)ACCEL_MAX;
float brakeScaler = 255.0 / (float)BRAKE_MAX;

// CAN interfaces
CANProcessor can;

// Gear sensing
GearSensor gearSensor;

// Joystick
Joystick_* joystick;

EmulationMode mode = EmulationMode::Xbox;

// Gear
Gear lastGear = Gear::Neutral;

void setupLightsAndButtons();
void setupPotentiometers();
void setupCAN();
void setupJoystick();

void updatePose(Pose pose);
void processTelemetry(std::string data);
void toggleEmulationMode();
uint8_t buttonForGear(Gear gear);

Pose lastPose;
bool shouldReleaseGear = false;

/** Instrumented function tokenize(std::string const&,char const,std::vector<std::string>&) */
inline void tokenize(const std::string& s, const char delim, std::vector<std::string>& out)
/* << Aka begin of function void tokenize(const std::string& s, const char delim, std::vector<std::string>& out) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\main.h\\tokenize(std::string const&,char const,std::vector<std::string>&)");AKA_fCall++;
	/** Include stub source code */
	#include "main.h.tokenize.1093.stub"

	AKA_mark("lis===54###sois===1178###eois===1209###lif===2###soif===90###eoif===121###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\main.h\\tokenize(std::string const&,char const,std::vector<std::string>&)");std::string::size_type beg = 0;
	int AKA_BLOCK_LOOP_1212 = 0;
    AKA_mark("lis===55###sois===1217###eois===1230###lif===3###soif===129###eoif===142###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\main.h\\tokenize(std::string const&,char const,std::vector<std::string>&)");
for (auto end = 0; AKA_mark("lis===55###sois===1231###eois===1278###lif===3###soif===143###eoif===190###ifc===true###function===.\\outlandnish_fw-ghost-drive\\include\\main.h\\tokenize(std::string const&,char const,std::vector<std::string>&)") && (AKA_mark("lis===55###sois===1231###eois===1278###lif===3###soif===143###eoif===190###isc===true###function===.\\outlandnish_fw-ghost-drive\\include\\main.h\\tokenize(std::string const&,char const,std::vector<std::string>&)") && ((end = s.find(delim, end)) != std::string::npos)); ({AKA_mark("lis===55###sois===1280###eois===1285###lif===3###soif===192###eoif===197###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\main.h\\tokenize(std::string const&,char const,std::vector<std::string>&)");++end;}))
	{
        AKA_BLOCK_LOOP_1212++;
        if (AKA_BLOCK_LOOP_1212 > 1000) {
            //break;
        }
		AKA_mark("lis===57###sois===1294###eois===1334###lif===5###soif===206###eoif===246###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\main.h\\tokenize(std::string const&,char const,std::vector<std::string>&)");out.push_back(s.substr(beg, end - beg));
		AKA_mark("lis===58###sois===1338###eois===1352###lif===6###soif===250###eoif===264###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\main.h\\tokenize(std::string const&,char const,std::vector<std::string>&)");beg = end + 1;
	}

	AKA_mark("lis===61###sois===1361###eois===1390###lif===9###soif===273###eoif===302###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\main.h\\tokenize(std::string const&,char const,std::vector<std::string>&)");out.push_back(s.substr(beg));
}
#endif
