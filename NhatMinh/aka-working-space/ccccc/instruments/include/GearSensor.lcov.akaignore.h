/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_GEARSENSOR_H
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_GEARSENSOR_H
#include <string>
#include <string.h>
#include <vector>
extern "C++" int AKA_mark(char* str);
extern "C++" void AKA_assert(char* actualName, int actualVal, char* expectedName, int expectedVal);
extern "C++" int AKA_assert_double(char* actualName, double actualVal, char* expectedName, double expectedVal);
extern "C++" int AKA_assert_ptr(char* actualName, void* actualVal, char* expectedName, void* expectedVal);
extern "C++" int AKA_fCall;
extern "C++" char* AKA_test_case_name;



#pragma once
/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__POSE_H_
#define AKA_INCLUDE__POSE_H_
#include <Pose.lcov.akaignore.h>
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__GEAR_H_
#define AKA_INCLUDE__GEAR_H_
#include <Gear.lcov.akaignore.h>
#endif

// #define LOCAL_SENSOR

#if defined(LOCAL_SENSOR)
  #include <Adafruit_FXOS8700.h>
#endif;

#define NUM_GEAR_UPDATES 3

class GearSensor {
  public:
char buffer;
  Gear gear = Gear::Neutral;

#if defined(LOCAL_SENSOR)
  Adafruit_FXOS8700 fxos = Adafruit_FXOS8700(0x8700A, 0x8700B);
  Adafruit_Sensor *accelerometer;
  sensors_event_t gravity;
  float _alpha = 0.05;

  uint8_t index = 0;
  Gear updates[NUM_GEAR_UPDATES];
#endif

  public:
    bool setup();
    void process();

    Gear getGear() {
AKA_fCall++; /* LCOV_EXCL_LINE */ 
	/** Include stub source code */
	#include "GearSensor.h.getGear.559.stub"
 return gear; }
};
#endif
