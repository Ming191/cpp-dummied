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
#include <SPI.lcov.akaignore.h>
#endif

// #include <McpDigitalPot.h>
/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__CANPROCESSOR_H_
#define AKA_INCLUDE__CANPROCESSOR_H_
#include <CANProcessor.lcov.akaignore.h>
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__JOYSTICK_H_
#define AKA_INCLUDE__JOYSTICK_H_
#include <Joystick.lcov.akaignore.h>
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__POSE_H_
#define AKA_INCLUDE__POSE_H_
#include <Pose.lcov.akaignore.h>
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__XBOXBUTTONS_H_
#define AKA_INCLUDE__XBOXBUTTONS_H_
#include <XboxButtons.lcov.akaignore.h>
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__EMULATIONMODE_H_
#define AKA_INCLUDE__EMULATIONMODE_H_
#include <EmulationMode.lcov.akaignore.h>
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__GEARSENSOR_H_
#define AKA_INCLUDE__GEARSENSOR_H_
#include <GearSensor.lcov.akaignore.h>
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

void tokenize(const std::string& s, const char delim, std::vector<std::string>& out)
{
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "main.h.tokenize.1093.stub"

	std::string::size_type beg = 0;
	for (auto end = 0; (end = s.find(delim, end)) != std::string::npos; ++end)
	{
		out.push_back(s.substr(beg, end - beg));
		beg = end + 1;
	}

	out.push_back(s.substr(beg));
}
#endif
