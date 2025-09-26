/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_SRC_MAIN_CPP
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_SRC_MAIN_CPP
#include <string>
#include <string.h>
#include <vector>
extern "C++" int AKA_mark(char* str);
extern "C++" void AKA_assert(char* actualName, int actualVal, char* expectedName, int expectedVal);
extern "C++" int AKA_assert_double(char* actualName, double actualVal, char* expectedName, double expectedVal);
extern "C++" int AKA_assert_ptr(char* actualName, void* actualVal, char* expectedName, void* expectedVal);
extern "C++" int AKA_fCall;
extern "C++" char* AKA_test_case_name;



/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__MAIN_H_
#define AKA_INCLUDE__MAIN_H_
#include <main.lcov.akaignore.h>
#endif


void setup() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "main.cpp.setup.26.stub"


}

void loop() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "main.cpp.loop.49.stub"

  gearSensor.process();
  Gear gear = gearSensor.getGear();

  // if we have any new CAN bus data
  if (can.newVehicleData() || gear != lastGear) {
    Pose pose = can.pose;
    pose.gear = gearSensor.getGear();

    updatePose(pose);
    lastPose = pose;
  }

  // if we have any telemetry updates to make
  // if (SerialUSB.available())
    // processTelemetry(SerialUSB.readStringUntil('\n').c_str());

  // can.updateDashboard();
}

void setupLightsAndButtons() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "main.cpp.setupLightsAndButtons.520.stub"


}

void setupJoystick() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "main.cpp.setupJoystick.559.stub"


}

void setupPotentiometers() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "main.cpp.setupPotentiometers.590.stub"

  SPI.begin();
}

void setupCAN() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "main.cpp.setupCAN.641.stub"

}

void updatePose(Pose pose) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "main.cpp.updatePose.665.stub"

  float scaledAccel, scaledBrakes;

  switch (mode) {
    case EmulationMode::Xbox:
      break;
    case EmulationMode::PC:
      // steering, accelerator, and brakes
      joystick->setXAxis(pose.steering);
      joystick->setYAxis(ACCEL_MAX - pose.accelerator);
      joystick->setZAxis(pose.brakes);

      // gear
      uint8_t button = buttonForGear(pose.gear);
      if (pose.gear != lastGear) {
        joystick->releaseButton(buttonForGear(lastGear));
        // press and store new gear
        joystick->pressButton(button);
        lastGear = pose.gear;
      }

      // upshift pressed
      // pose.upshift ? joystick->pressButton(0) : joystick->releaseButton(0);

      // downshift pressed
      // pose.downshift ? joystick->pressButton(1) : joystick->releaseButton(1);

      // clutch
      pose.clutch ? joystick->pressButton(8) : joystick->releaseButton(8);

      // e-brake
      pose.ebrake ? joystick->pressButton(9) : joystick->releaseButton(9);
      
      break;
  }

  // update joystick state
  joystick->sendState();
}

void toggleEmulationMode() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "main.cpp.toggleEmulationMode.1787.stub"

  switch (mode) {
    case EmulationMode::Xbox:
      mode = EmulationMode::PC;
      break;
    case EmulationMode::PC:
      mode = EmulationMode::Xbox;
      break;
  }
}

void processTelemetry(std::string data) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "main.cpp.processTelemetry.2002.stub"

}

uint8_t buttonForGear(Gear gear) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "main.cpp.buttonForGear.2053.stub"

  return gear == gear == Gear::Reverse ? 8 : gear;
}
#endif
