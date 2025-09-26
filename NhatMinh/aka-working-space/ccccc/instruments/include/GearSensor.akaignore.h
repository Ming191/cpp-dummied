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
#include <Pose.akaignore.h>
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__GEAR_H_
#define AKA_INCLUDE__GEAR_H_
#include <Gear.akaignore.h>
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

    /** Instrumented function getGear() */
Gear getGear() /* << Aka begin of function Gear getGear() >> */
{AKA_mark("Calling: .\\outlandnish_fw-ghost-drive\\include\\GearSensor.h\\GearSensor\\getGear()");AKA_fCall++;
	/** Include stub source code */
	#include "GearSensor.h.getGear.559.stub"
 AKA_mark("lis===30###sois===571###eois===583###lif===0###soif===17###eoif===29###ins===true###function===.\\outlandnish_fw-ghost-drive\\include\\GearSensor.h\\GearSensor\\getGear()");return gear; }
};
#endif
