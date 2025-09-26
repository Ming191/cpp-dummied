/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_XBOXBUTTONS_H
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_OUTLANDNISH_FW_GHOST_DRIVE_INCLUDE_XBOXBUTTONS_H
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
#include <stdint.h>

enum XboxButtons : uint8_t {
  LEFT_X1 = 0,
  LEFT_X2,
  LEFT_THUMBSTICK,
  LEFT_BUMPER,
  A,
  B,
  LEFT_VIEW,
  LEFT_MENU,

  RIGHT_SELECT = 0,
  RIGHT_VIEW,
  RIGHT_THUMBSTICK,
  RIGHT_BUMPER,
  X,
  Y,
  RIGHT_X1,
  RIGHT_X2
};
#endif
