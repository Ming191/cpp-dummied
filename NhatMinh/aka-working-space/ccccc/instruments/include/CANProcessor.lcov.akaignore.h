/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_CANPROCESSOR_H
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_CANPROCESSOR_H
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
#include <due_can.lcov.akaignore.h>
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__POSE_H_
#define AKA_INCLUDE__POSE_H_
#include <Pose.lcov.akaignore.h>
#endif


class CANProcessor {
  public:
CAN_FRAME lastBrakeSpeedFrame;
  CAN_FRAME lastTransmissionFrame;
  
  public:
    float _speed;
    int _rpm;
    bool newVehicleData();

    bool checkBus(CANRaw *bus);
    bool processFrame(CAN_FRAME &frame);
    void updateDashboard();
    void updateTelemetry(float speed, int rpm);

    Pose pose;
};
#endif
