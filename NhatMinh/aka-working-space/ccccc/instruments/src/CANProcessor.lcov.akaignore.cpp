/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_SRC_CANPROCESSOR_CPP
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_SRC_CANPROCESSOR_CPP
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
#ifndef AKA_INCLUDE__CANPROCESSOR_H_
#define AKA_INCLUDE__CANPROCESSOR_H_
#include <CANProcessor.lcov.akaignore.h>
#endif


void CANProcessor::updateTelemetry(float speed, int rpm) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "CANProcessor.cpp.CANProcessor.updateTelemetry.34.stub"

  _speed = speed;
  _rpm = rpm;
}

void CANProcessor::updateDashboard() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "CANProcessor.cpp.CANProcessor.updateDashboard.133.stub"

  // lastTransmissionFrame.data.byte[4] = _rpm % 256;
  // lastTransmissionFrame.data.byte[5] = _rpm / 256 + 0x80;
  Can0.sendFrame(lastTransmissionFrame);

  union {
    uint16_t convertedSpeed;
    uint8_t bytes[2];
  } speedData;

  // speedData.convertedSpeed = round(_speed / 0.05747);
  // lastBrakeSpeedFrame.data.byte[0] = speedData.bytes[0];
  // lastBrakeSpeedFrame.data.byte[1] = speedData.bytes[1];
  Can0.sendFrame(lastBrakeSpeedFrame);
}

bool CANProcessor::newVehicleData() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "CANProcessor.cpp.CANProcessor.newVehicleData.641.stub"

  bool newData = false;
  newData = newData || checkBus(&Can0);
  newData = newData || checkBus(&Can1);

  return newData;
}

bool CANProcessor::checkBus(CANRaw *bus) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "CANProcessor.cpp.CANProcessor.checkBus.813.stub"

  CAN_FRAME frame;
  if (bus->available() > 0) {
    // digitalWrite(DS2, LOW);

    bus->read(frame);
    return processFrame(frame);
  }
  // digitalWrite(DS2, HIGH);
  return false;
}

bool CANProcessor::processFrame(CAN_FRAME &frame) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "CANProcessor.cpp.CANProcessor.processFrame.1056.stub"

  bool newData = false;
  
  if (frame.id == 0xD0) {
    // steering
    int16_t steering = frame.data.bytes[1] << 8 | frame.data.bytes[0];

    if (steering != pose.steering) {
      newData = true;
      pose.steering = steering;
    }
  }
  else if (frame.id == 0xD1) {
    lastBrakeSpeedFrame = frame;

    // brake pedal pressure
    uint8_t brakes = frame.data.bytes[2];

    if (brakes != pose.brakes) {
      newData = true;
      pose.brakes = brakes;
    }
  }
  else if (frame.id == 0x140) {
    // accelerator pedal position + clutch engaged / not
    uint8_t accelerator = frame.data.bytes[0];
    bool clutch = frame.data.bit[15];

    if (pose.accelerator != accelerator || pose.clutch != clutch)
      newData = true;
    
    pose.accelerator = accelerator;
    pose.clutch = clutch;
  }
  else if (frame.id == 0x141) {
    lastTransmissionFrame = frame;
    bool inGear = frame.data.bytes[5] == 0x80;

    if (pose.inGear != inGear) {
      newData = true;
      pose.inGear = inGear;
      // SerialUSB.print("In gear: ");
      // SerialUSB.println(pose.inGear);
    }
  }
  else if (frame.id == 0x144) {
    // cruise control stalk (used for upshift / downshift)
    uint8_t cruiseControlStalk = frame.data.byte[0];

    bool upshift = cruiseControlStalk == 0xD0;
    bool downshift = cruiseControlStalk == 0xC8;
    // if (pose.upshift != upshift || pose.downshift != downshift) {
    //   pose.upshift = upshift;
    //   pose.downshift = downshift;
    //   newData = true;
    // }
  }
  else if (frame.id == 0x152) {
    // e-brake engaged or not
    bool ebrake = frame.data.bit[51];

    if (pose.ebrake != ebrake)
      newData = true;

    pose.ebrake = ebrake;
  }

  return newData;
}
#endif
