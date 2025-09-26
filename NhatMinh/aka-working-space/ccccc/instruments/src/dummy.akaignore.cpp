/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_SRC_DUMMY_CPP
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_SRC_DUMMY_CPP
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
#ifndef AKA_INCLUDE__DUE_CAN_H_
#define AKA_INCLUDE__DUE_CAN_H_
#include "due_can.akaignore.h"
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__SPI_H_
#define AKA_INCLUDE__SPI_H_
#include "SPI.akaignore.h"
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__GEARSENSOR_H_
#define AKA_INCLUDE__GEARSENSOR_H_
#include "GearSensor.akaignore.h"
#endif

/** Instrumented function CANRaw::sendFrame(CAN_FRAME&) */
bool CANRaw::sendFrame(CAN_FRAME &frame) /* << Aka begin of function bool CANRaw::sendFrame(CAN_FRAME &frame) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\dummy.cpp\\CANRaw::sendFrame(CAN_FRAME&)");AKA_fCall++;
	/** Include stub source code */
	#include "dummy.cpp.CANRaw.sendFrame.70.stub"
}
/** Instrumented function CANRaw::available() */
bool CANRaw::available() /* << Aka begin of function bool CANRaw::available() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\dummy.cpp\\CANRaw::available()");AKA_fCall++;
	/** Include stub source code */
	#include "dummy.cpp.CANRaw.available.115.stub"
}
/** Instrumented function CANRaw::read(CAN_FRAME&) */
bool CANRaw::read(CAN_FRAME &frame) /* << Aka begin of function bool CANRaw::read(CAN_FRAME &frame) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\dummy.cpp\\CANRaw::read(CAN_FRAME&)");AKA_fCall++;
	/** Include stub source code */
	#include "dummy.cpp.CANRaw.read.144.stub"
}

CANRaw Can0(0);
CANRaw Can1(1);
/** Instrumented function CANRaw::CANRaw(int) */
CANRaw::CANRaw(int bus) /* << Aka begin of function  CANRaw::CANRaw(int bus) >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\dummy.cpp\\CANRaw::CANRaw(int)");AKA_fCall++;}

SPIClass SPI;

/** Instrumented function GearSensor::process() */
void GearSensor::process() /* << Aka begin of function void GearSensor::process() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\src\\dummy.cpp\\GearSensor::process()");AKA_fCall++;
	/** Include stub source code */
	#include "dummy.cpp.GearSensor.process.267.stub"
}
#endif
