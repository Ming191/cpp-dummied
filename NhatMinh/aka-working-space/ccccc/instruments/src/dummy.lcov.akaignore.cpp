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
#include "due_can.lcov.akaignore.h"
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__SPI_H_
#define AKA_INCLUDE__SPI_H_
#include "SPI.lcov.akaignore.h"
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__GEARSENSOR_H_
#define AKA_INCLUDE__GEARSENSOR_H_
#include "GearSensor.lcov.akaignore.h"
#endif

bool CANRaw::sendFrame(CAN_FRAME &frame) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "dummy.cpp.CANRaw.sendFrame.70.stub"
}
bool CANRaw::available() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "dummy.cpp.CANRaw.available.115.stub"
}
bool CANRaw::read(CAN_FRAME &frame) {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "dummy.cpp.CANRaw.read.144.stub"
}

CANRaw Can0(0);
CANRaw Can1(1);
CANRaw::CANRaw(int bus) {
AKA_fCall++; /* LCOV_EXCL_LINE */ }

SPIClass SPI;

void GearSensor::process() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "dummy.cpp.GearSensor.process.267.stub"
}
#endif
