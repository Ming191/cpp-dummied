/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_LVANDEVE_LODEPNG_INC_SDL_H
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_LVANDEVE_LODEPNG_INC_SDL_H
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

/** Instrumented function SDL_GetTicks() */
static inline int SDL_GetTicks() /* << Aka begin of function int SDL_GetTicks() >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\inc\\SDL.h\\SDL_GetTicks()");AKA_fCall++;
	/** Include stub source code */
	#include "SDL.h.SDL_GetTicks.34.stub"
}
#endif
