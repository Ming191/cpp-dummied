/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_LVANDEVE_LODEPNG_SRC_LODEPNG_FUZZER_CPP
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_LVANDEVE_LODEPNG_SRC_LODEPNG_FUZZER_CPP
#include <string>
#include <string.h>
#include <vector>
extern "C++" int AKA_mark(char* str);
extern "C++" void AKA_assert(char* actualName, int actualVal, char* expectedName, int expectedVal);
extern "C++" int AKA_assert_double(char* actualName, double actualVal, char* expectedName, double expectedVal);
extern "C++" int AKA_assert_ptr(char* actualName, void* actualVal, char* expectedName, void* expectedVal);
extern "C++" int AKA_fCall;
extern "C++" char* AKA_test_case_name;



/*
LodePNG Fuzzer

Copyright (c) 2005-2019 Lode Vandevenne

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution.
*/

// clang++ -fsanitize=fuzzer lodepng.cpp lodepng_fuzzer.cpp -O3 && ./a.out

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__LODEPNG_H_
#define AKA_INCLUDE__LODEPNG_H_
#include "lodepng.akaignore.h"
#endif


#include <cstdint>

namespace {
// Amount of valid colortype/bidthdepth combinations in the PNG file format.
const size_t num_combinations = 15;

LodePNGColorType colortypes[num_combinations] = {
  LCT_GREY, LCT_GREY, LCT_GREY, LCT_GREY, LCT_GREY, // 1, 2, 4, 8 or 16 bits
  LCT_RGB, LCT_RGB, // 8 or 16 bits
  LCT_PALETTE, LCT_PALETTE, LCT_PALETTE, LCT_PALETTE, // 1, 2, 4 or 8 bits
  LCT_GREY_ALPHA, LCT_GREY_ALPHA, // 8 or 16 bits
  LCT_RGBA, LCT_RGBA, // 8 or 16 bits
};

unsigned bitdepths[num_combinations] = {
  1, 2, 4, 8, 16, // gray
  8, 16, // rgb
  1, 2, 4, 8, // palette
  8, 16, // gray+alpha
  8, 16, // rgb+alpha
};

/** Instrumented function testDecode(lodepng::State&,uint8_t const*,size_t) */
unsigned testDecode(lodepng::State& state, const uint8_t* data, size_t size) /* << Aka begin of function unsigned testDecode(lodepng::State& state, const uint8_t* data, size_t size) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\testDecode(lodepng::State&,uint8_t const*,size_t)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_fuzzer.cpp.testDecode.1695.stub"

  AKA_mark("lis===53###sois===1768###eois===1782###lif===1###soif===82###eoif===96###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\testDecode(lodepng::State&,uint8_t const*,size_t)");unsigned w, h;
  AKA_mark("lis===54###sois===1786###eois===1819###lif===2###soif===100###eoif===133###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\testDecode(lodepng::State&,uint8_t const*,size_t)");std::vector<unsigned char> image;
  AKA_mark("lis===55###sois===1823###eois===1900###lif===3###soif===137###eoif===214###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\testDecode(lodepng::State&,uint8_t const*,size_t)");return lodepng::decode(image, w, h, state, (const unsigned char*)data, size);
}
} // end anonymous namespace

extern "C" /** Instrumented function LLVMFuzzerTestOneInput(uint8_t const*,size_t) */
int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) /* << Aka begin of function int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_fuzzer.cpp.LLVMFuzzerTestOneInput.1952.stub"

  if(AKA_mark("lis===60###sois===2017###eois===2026###lif===1###soif===69###eoif===78###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)") && (AKA_mark("lis===60###sois===2017###eois===2026###lif===1###soif===69###eoif===78###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)") && (size == 0))) {
AKA_mark("lis===60###sois===2028###eois===2037###lif===1###soif===80###eoif===89###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");return 0;
}

else {
AKA_mark("lis===-60-###sois===-2017-###eois===-20179-###lif===-1-###soif===-###eoif===-78-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");
}
  
  // Setting last byte of input as random_color_type
  // Fuzzer will still be able to mutate the data accordingly as
  // last byte of png file can be changed and file will still remain valid.
  AKA_mark("lis===65###sois===2242###eois===2301###lif===6###soif===294###eoif===353###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");size_t random_color_type = data[size-1] % num_combinations;

  AKA_mark("lis===67###sois===2307###eois===2328###lif===8###soif===359###eoif===380###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");lodepng::State state;

  // Make the decoder ignore three types of checksums the PNG/zlib format have
  // built-in, because they are less likely to be correct in the random input
  // data, and if invalid make the decoder return an error before much gets ran.
  AKA_mark("lis===72###sois===2575###eois===2621###lif===13###soif===627###eoif===673###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");state.decoder.zlibsettings.ignore_adler32 = 1;
  AKA_mark("lis===73###sois===2625###eois===2668###lif===14###soif===677###eoif===720###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");state.decoder.zlibsettings.ignore_nlen = 1;
  AKA_mark("lis===74###sois===2672###eois===2701###lif===15###soif===724###eoif===753###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");state.decoder.ignore_crc = 1;
  // Also make decoder attempt to support partial files with missing ending to
  // go further with parsing.
  AKA_mark("lis===77###sois===2816###eois===2845###lif===18###soif===868###eoif===897###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");state.decoder.ignore_end = 1;

  // First test without color conversion (keep color type of the PNG)
  AKA_mark("lis===80###sois===2922###eois===2954###lif===21###soif===974###eoif===1006###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");state.decoder.color_convert = 0;

  AKA_mark("lis===82###sois===2960###eois===3007###lif===23###soif===1012###eoif===1059###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");unsigned error = testDecode(state, data, size);

  // If valid PNG found, try decoding with color conversion to the most common
  // default color type, and to the randomly chosen type.
  if(AKA_mark("lis===86###sois===3155###eois===3165###lif===27###soif===1207###eoif===1217###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)") && (AKA_mark("lis===86###sois===3155###eois===3165###lif===27###soif===1207###eoif===1217###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)") && (error == 0))) {
    AKA_mark("lis===87###sois===3174###eois===3206###lif===28###soif===1226###eoif===1258###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");state.decoder.color_convert = 1;
    AKA_mark("lis===88###sois===3212###eois===3242###lif===29###soif===1264###eoif===1294###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");testDecode(state, data, size);

    AKA_mark("lis===90###sois===3250###eois===3307###lif===31###soif===1302###eoif===1359###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");state.info_raw.colortype = colortypes[random_color_type];
    AKA_mark("lis===91###sois===3313###eois===3368###lif===32###soif===1365###eoif===1420###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");state.info_raw.bitdepth = bitdepths[random_color_type];
    AKA_mark("lis===92###sois===3374###eois===3404###lif===33###soif===1426###eoif===1456###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");testDecode(state, data, size);
  }
else {
AKA_mark("lis===-86-###sois===-3155-###eois===-315510-###lif===-27-###soif===-###eoif===-1217-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");
}

  AKA_mark("lis===95###sois===3415###eois===3424###lif===36###soif===1467###eoif===1476###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_fuzzer.cpp\\LLVMFuzzerTestOneInput(uint8_t const*,size_t)");return 0;
}

#endif
