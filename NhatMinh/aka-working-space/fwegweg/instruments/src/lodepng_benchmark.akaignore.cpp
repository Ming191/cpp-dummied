/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_LVANDEVE_LODEPNG_SRC_LODEPNG_BENCHMARK_CPP
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_LVANDEVE_LODEPNG_SRC_LODEPNG_BENCHMARK_CPP
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
LodePNG Benchmark

Copyright (c) 2005-2023 Lode Vandevenne

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

//g++ lodepng.cpp lodepng_benchmark.cpp -Wall -Wextra -pedantic -ansi -lSDL -O3
//g++ lodepng.cpp lodepng_benchmark.cpp -Wall -Wextra -pedantic -ansi -lSDL -O3 && ./a.out

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__LODEPNG_H_
#define AKA_INCLUDE__LODEPNG_H_
#include "lodepng.akaignore.h"
#endif


#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include <stdio.h>
#include <stdlib.h>

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__SDL_H_
#define AKA_INCLUDE__SDL_H_
#include <SDL.akaignore.h>
#endif
 //SDL is used for timing.

bool apply_mods = false;

#define NUM_DECODE 5 //decode multiple times to measure better. Must be at least 1.

size_t total_pixels = 0;
size_t total_png_orig_size = 0;
size_t total_raw_orig_size = 0; // This is the uncompressed data in the raw color format in the original input PNGs

double total_dec_time = 0;
size_t total_png_in_size = 0;
size_t total_raw_in_size = 0; // This is the uncompressed data in the raw color format in the input PNGs given to the decoder (not same as orig when using the encoded ones)
size_t total_raw_dec_size = 0; // This is the uncompressed data in the raw color format of raw image buffers output by the decoder

double total_enc_time = 0;
size_t total_raw_enc_size = 0; // This is the uncompressed data in the raw color format of the raw images given to the encoder
size_t total_png_out_size = 0;
size_t total_raw_out_size = 0; // This is the uncompressed data in the raw color format of the encoded PNGs

bool verbose = false;
bool do_decode = false;
bool do_encode = false;
bool decode_encoded = false; // do the decoding benchmark on the encoded images rather than the original inputs

std::string dumpdir;

////////////////////////////////////////////////////////////////////////////////

/** Instrumented function getTime() */
double getTime() /* << Aka begin of function double getTime() >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\getTime()");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_benchmark.cpp.getTime.2581.stub"

  AKA_mark("lis===70###sois===2596###eois===2627###lif===1###soif===22###eoif===53###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\getTime()");return SDL_GetTicks() / 1000.0;
}

template<typename T, typename U>
/** Instrumented function assertEquals(T const&,U const&,std::string const&= "") */
void assertEquals(const T& expected, const U& actual, const std::string& message = "") /* << Aka begin of function void assertEquals(const T& expected, const U& actual, const std::string& message = "") >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertEquals(T const&,U const&,std::string const&= "")");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_benchmark.cpp.assertEquals.2673.stub"

  if(AKA_mark("lis===75###sois===2763###eois===2784###lif===1###soif===95###eoif===116###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertEquals(T const&,U const&,std::string const&= "")") && (AKA_mark("lis===75###sois===2763###eois===2784###lif===1###soif===95###eoif===116###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertEquals(T const&,U const&,std::string const&= "")") && (expected != (T)actual))) {
    AKA_mark("lis===76###sois===2793###eois===2889###lif===2###soif===125###eoif===221###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertEquals(T const&,U const&,std::string const&= "")");std::cout << "Error: Not equal! Expected " << expected << " got " << actual << "." << std::endl;
    AKA_mark("lis===77###sois===2895###eois===2944###lif===3###soif===227###eoif===276###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertEquals(T const&,U const&,std::string const&= "")");std::cout << "Message: " << message << std::endl;
    AKA_mark("lis===78###sois===2950###eois===2963###lif===4###soif===282###eoif===295###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertEquals(T const&,U const&,std::string const&= "")");std::exit(1);
  }
else {
AKA_mark("lis===-75-###sois===-2763-###eois===-276321-###lif===-1-###soif===-###eoif===-116-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertEquals(T const&,U const&,std::string const&= "")");
}
}

/** Instrumented function assertTrue1(bool,std::string const&= "") */
void assertTrue1(bool value, const std::string& message = "") /* << Aka begin of function void assertTrue1(bool value, const std::string& message = "") >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertTrue1(bool,std::string const&= "")");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_benchmark.cpp.assertTrue1.2980.stub"

  if(AKA_mark("lis===83###sois===3045###eois===3051###lif===1###soif===70###eoif===76###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertTrue1(bool,std::string const&= "")") && (AKA_mark("lis===83###sois===3045###eois===3051###lif===1###soif===70###eoif===76###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertTrue1(bool,std::string const&= "")") && (!value))) {
    AKA_mark("lis===84###sois===3060###eois===3110###lif===2###soif===85###eoif===135###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertTrue1(bool,std::string const&= "")");std::cout << "Error: expected true." << std::endl;
    AKA_mark("lis===85###sois===3116###eois===3165###lif===3###soif===141###eoif===190###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertTrue1(bool,std::string const&= "")");std::cout << "Message: " << message << std::endl;
    AKA_mark("lis===86###sois===3171###eois===3184###lif===4###soif===196###eoif===209###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertTrue1(bool,std::string const&= "")");std::exit(1);
  }
else {
AKA_mark("lis===-83-###sois===-3045-###eois===-30456-###lif===-1-###soif===-###eoif===-76-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\assertTrue1(bool,std::string const&= "")");
}
}

//Test image data
struct Image {
  std::vector<unsigned char> data;
  unsigned width;
  unsigned height;
  LodePNGColorType colorType;
  unsigned bitDepth;
  std::string name;
};

//Utility for debug messages
template<typename T>
/** Instrumented function valtostr(T const&) */
std::string valtostr(const T& val) /* << Aka begin of function std::string valtostr(const T& val) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\valtostr(T const&)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_benchmark.cpp.valtostr.3450.stub"

  AKA_mark("lis===103###sois===3478###eois===3505###lif===1###soif===40###eoif===67###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\valtostr(T const&)");std::ostringstream sstream;
  AKA_mark("lis===104###sois===3509###eois===3524###lif===2###soif===71###eoif===86###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\valtostr(T const&)");sstream << val;
  AKA_mark("lis===105###sois===3528###eois===3549###lif===3###soif===90###eoif===111###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\valtostr(T const&)");return sstream.str();
}

template<typename T>
/** Instrumented function printValue(std::string const&,T const&,std::string const&= "") */
void printValue(const std::string& name, const T& value, const std::string& unit = "") /* << Aka begin of function void printValue(const std::string& name, const T& value, const std::string& unit = "") >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\printValue(std::string const&,T const&,std::string const&= "")");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_benchmark.cpp.printValue.3583.stub"

  AKA_mark("lis===110###sois===3670###eois===3726###lif===1###soif===92###eoif===148###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\printValue(std::string const&,T const&,std::string const&= "")");std::cout << name << ": " << value << unit << std::endl;
}

template<typename T, typename U>
/** Instrumented function printValue(std::string const&,T const&,std::string const&,U const&,std::string const&= "") */
void printValue(const std::string& name, const T& value, const std::string& s2, const U& value2, const std::string& unit = "") /* << Aka begin of function void printValue(const std::string& name, const T& value, const std::string& s2, const U& value2, const std::string& unit = "") >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\printValue(std::string const&,T const&,std::string const&,U const&,std::string const&= "")");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_benchmark.cpp.printValue.3772.stub"

  AKA_mark("lis===115###sois===3899###eois===3971###lif===1###soif===132###eoif===204###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\printValue(std::string const&,T const&,std::string const&,U const&,std::string const&= "")");std::cout << name << ": " << value << s2 << value2 << unit << std::endl;
}

//Test LodePNG encoding and decoding the encoded result, using the C interface
/** Instrumented function testEncode(Image&) */
std::vector<unsigned char> testEncode(Image& image) /* << Aka begin of function std::vector<unsigned char> testEncode(Image& image) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_benchmark.cpp.testEncode.4085.stub"

  AKA_mark("lis===120###sois===4115###eois===4142###lif===1###soif===57###eoif===84###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");unsigned char* encoded = 0;
  AKA_mark("lis===121###sois===4146###eois===4170###lif===2###soif===88###eoif===112###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");size_t encoded_size = 0;
  AKA_mark("lis===122###sois===4174###eois===4195###lif===3###soif===116###eoif===137###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");lodepng::State state;
  AKA_mark("lis===123###sois===4199###eois===4242###lif===4###soif===141###eoif===184###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");state.info_raw.colortype = image.colorType;
  AKA_mark("lis===124###sois===4246###eois===4287###lif===5###soif===188###eoif===229###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");state.info_raw.bitdepth = image.bitDepth;

  // Try custom compression settings
  if(AKA_mark("lis===127###sois===4334###eois===4344###lif===8###soif===276###eoif===286###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)") && (AKA_mark("lis===127###sois===4334###eois===4344###lif===8###soif===276###eoif===286###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)") && (apply_mods))) {
    //state.encoder.filter_strategy = LFS_ZERO;
    //state.encoder.filter_strategy = LFS_ENTROPY;
    //state.encoder.filter_strategy = LFS_FOUR;
    //state.encoder.zlibsettings.btype = 0;
    //state.encoder.zlibsettings.btype = 1;
    //state.encoder.auto_convert = 0;
    //state.encoder.zlibsettings.use_lz77 = 0;
    AKA_mark("lis===135###sois===4680###eois===4722###lif===16###soif===622###eoif===664###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");state.encoder.zlibsettings.windowsize = 1;
    //state.encoder.zlibsettings.windowsize = 32768;
  }
else {
AKA_mark("lis===-127-###sois===-4334-###eois===-433410-###lif===-8-###soif===-###eoif===-286-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");
}

  AKA_mark("lis===139###sois===4787###eois===4813###lif===20###soif===729###eoif===755###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");double t_enc0 = getTime();

  AKA_mark("lis===141###sois===4819###eois===4970###lif===22###soif===761###eoif===912###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");unsigned error_enc = lodepng_encode(&encoded, &encoded_size, &image.data[0],
                                      image.width, image.height, &state);

  AKA_mark("lis===144###sois===4976###eois===5002###lif===25###soif===918###eoif===944###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");double t_enc1 = getTime();

  AKA_mark("lis===146###sois===5008###eois===5052###lif===27###soif===950###eoif===994###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");assertEquals(0, error_enc, "encoder error");

  AKA_mark("lis===148###sois===5058###eois===5145###lif===29###soif===1000###eoif===1087###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");total_raw_enc_size += lodepng_get_raw_size(image.width, image.height, &state.info_raw);
  AKA_mark("lis===149###sois===5149###eois===5184###lif===30###soif===1091###eoif===1126###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");total_png_out_size += encoded_size;
  AKA_mark("lis===150###sois===5188###eois===5224###lif===31###soif===1130###eoif===1166###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");total_enc_time += (t_enc1 - t_enc0);

  if(AKA_mark("lis===152###sois===5233###eois===5240###lif===33###soif===1175###eoif===1182###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)") && (AKA_mark("lis===152###sois===5233###eois===5240###lif===33###soif===1175###eoif===1182###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)") && (verbose))) {
    AKA_mark("lis===153###sois===5249###eois===5299###lif===34###soif===1191###eoif===1241###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");printValue("encoding time", t_enc1 - t_enc0, "s");
    AKA_mark("lis===154###sois===5305###eois===5632###lif===35###soif===1247###eoif===1574###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");std::cout << "compression: " << ((double)(encoded_size) / (double)(image.data.size())) * 100 << "%"
              << ", ratio: " << ((double)(image.data.size()) / (double)(encoded_size))
              << ", size: " << encoded_size
              << ", bpp: " << (8.0 * encoded_size / image.width / image.height) << std::endl;
  }
else {
AKA_mark("lis===-152-###sois===-5233-###eois===-52337-###lif===-33-###soif===-###eoif===-1182-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");
}

  if(AKA_mark("lis===160###sois===5646###eois===5662###lif===41###soif===1588###eoif===1604###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)") && (AKA_mark("lis===160###sois===5646###eois===5662###lif===41###soif===1588###eoif===1604###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)") && (!dumpdir.empty()))) {
    AKA_mark("lis===161###sois===5671###eois===5702###lif===42###soif===1613###eoif===1644###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");std::string dumpname = dumpdir;
    if(AKA_mark("lis===162###sois===5711###eois===5747###lif===43###soif===1653###eoif===1689###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)") && (AKA_mark("lis===162###sois===5711###eois===5747###lif===43###soif===1653###eoif===1689###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)") && (dumpname[dumpname.size() - 1] != '/'))) {
AKA_mark("lis===162###sois===5749###eois===5765###lif===43###soif===1691###eoif===1707###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");dumpname += "/";
}

else {
AKA_mark("lis===-162-###sois===-5711-###eois===-571136-###lif===-43-###soif===-###eoif===-1689-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");
}
    AKA_mark("lis===163###sois===5771###eois===5794###lif===44###soif===1713###eoif===1736###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");dumpname += image.name;
    if(AKA_mark("lis===164###sois===5803###eois===5861###lif===45###soif===1745###eoif===1803###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)") && (AKA_mark("lis===164###sois===5803###eois===5861###lif===45###soif===1745###eoif===1803###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)") && (lodepng_save_file(encoded, encoded_size, dumpname.c_str())))) {
      AKA_mark("lis===165###sois===5872###eois===5972###lif===46###soif===1814###eoif===1914###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");std::cout << "WARNING: failed to dump " << dumpname << ". The dir must already exist." << std::endl;
    } else {
if(AKA_mark("lis===166###sois===5988###eois===5995###lif===47###soif===1930###eoif===1937###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)") && (AKA_mark("lis===166###sois===5988###eois===5995###lif===47###soif===1930###eoif===1937###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)") && (verbose))) {
      AKA_mark("lis===167###sois===6006###eois===6057###lif===48###soif===1948###eoif===1999###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");std::cout << "saved to: " << dumpname << std::endl;
    }
else {
AKA_mark("lis===-166-###sois===-5988-###eois===-59887-###lif===-47-###soif===-###eoif===-1937-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");
}
}

  }
else {
AKA_mark("lis===-160-###sois===-5646-###eois===-564616-###lif===-41-###soif===-###eoif===-1604-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");
}

  // output image stats
  {
    AKA_mark("lis===173###sois===6107###eois===6130###lif===54###soif===2049###eoif===2072###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");lodepng::State inspect;
    AKA_mark("lis===174###sois===6136###eois===6150###lif===55###soif===2078###eoif===2092###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");unsigned w, h;
    AKA_mark("lis===175###sois===6156###eois===6213###lif===56###soif===2098###eoif===2155###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");lodepng_inspect(&w, &h, &inspect, encoded, encoded_size);
    AKA_mark("lis===176###sois===6219###eois===6293###lif===57###soif===2161###eoif===2235###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");total_raw_out_size += lodepng_get_raw_size(w, h, &inspect.info_png.color);
  }

  AKA_mark("lis===179###sois===6304###eois===6371###lif===60###soif===2246###eoif===2313###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");std::vector<unsigned char> result(encoded, encoded + encoded_size);
  AKA_mark("lis===180###sois===6375###eois===6389###lif===61###soif===2317###eoif===2331###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");free(encoded);
  AKA_mark("lis===181###sois===6393###eois===6407###lif===62###soif===2335###eoif===2349###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testEncode(Image&)");return result;
}

/** Instrumented function testDecode(std::vector<unsigned char>const&) */
void testDecode(const std::vector<unsigned char>& png) /* << Aka begin of function void testDecode(const std::vector<unsigned char>& png) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_benchmark.cpp.testDecode.6419.stub"

  AKA_mark("lis===185###sois===6474###eois===6495###lif===1###soif===60###eoif===81###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");lodepng::State state;
  AKA_mark("lis===186###sois===6499###eois===6526###lif===2###soif===85###eoif===112###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");unsigned char* decoded = 0;
  AKA_mark("lis===187###sois===6530###eois===6544###lif===3###soif===116###eoif===130###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");unsigned w, h;

  // Try custom decompression settings
  if(AKA_mark("lis===190###sois===6593###eois===6603###lif===6###soif===179###eoif===189###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)") && (AKA_mark("lis===190###sois===6593###eois===6603###lif===6###soif===179###eoif===189###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)") && (apply_mods))) {
    AKA_mark("lis===191###sois===6612###eois===6644###lif===7###soif===198###eoif===230###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");state.decoder.color_convert = 0;
    //state.decoder.ignore_crc = 1;
  }
else {
AKA_mark("lis===-190-###sois===-6593-###eois===-659310-###lif===-6-###soif===-###eoif===-189-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");
}

  AKA_mark("lis===195###sois===6692###eois===6718###lif===11###soif===278###eoif===304###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");double t_dec0 = getTime();
  int AKA_BLOCK_LOOP_6722 = 0;
    AKA_mark("lis===196###sois===6726###eois===6736###lif===12###soif===312###eoif===322###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");
for(int i = 0; AKA_mark("lis===196###sois===6737###eois===6751###lif===12###soif===323###eoif===337###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)") && (AKA_mark("lis===196###sois===6737###eois===6751###lif===12###soif===323###eoif===337###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)") && (i < NUM_DECODE)); ({AKA_mark("lis===196###sois===6753###eois===6756###lif===12###soif===339###eoif===342###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");i++;})) {
        AKA_BLOCK_LOOP_6722++;
        if (AKA_BLOCK_LOOP_6722 > 1000) {
            //break;
        }
    AKA_mark("lis===197###sois===6765###eois===6851###lif===13###soif===351###eoif===437###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");unsigned error_dec = lodepng_decode(&decoded, &w, &h, &state, png.data(), png.size());
    AKA_mark("lis===198###sois===6857###eois===6901###lif===14###soif===443###eoif===487###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");assertEquals(0, error_dec, "decoder error");
  }
  AKA_mark("lis===200###sois===6910###eois===6936###lif===16###soif===496###eoif===522###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");double t_dec1 = getTime();

  AKA_mark("lis===202###sois===6942###eois===6978###lif===18###soif===528###eoif===564###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");total_dec_time += (t_dec1 - t_dec0);

  AKA_mark("lis===204###sois===6984###eois===7050###lif===20###soif===570###eoif===636###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");total_raw_dec_size += lodepng_get_raw_size(w, h, &state.info_raw);

  if(AKA_mark("lis===206###sois===7059###eois===7066###lif===22###soif===645###eoif===652###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)") && (AKA_mark("lis===206###sois===7059###eois===7066###lif===22###soif===645###eoif===652###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)") && (verbose))) {
    AKA_mark("lis===207###sois===7075###eois===7143###lif===23###soif===661###eoif===729###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");printValue("decoding time", t_dec1 - t_dec0, "/", NUM_DECODE, " s");
  }
else {
AKA_mark("lis===-206-###sois===-7059-###eois===-70597-###lif===-22-###soif===-###eoif===-652-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");
}
  AKA_mark("lis===209###sois===7152###eois===7166###lif===25###soif===738###eoif===752###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");free(decoded);

  // input image stats
  {
    AKA_mark("lis===213###sois===7203###eois===7226###lif===29###soif===789###eoif===812###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");lodepng::State inspect;
    AKA_mark("lis===214###sois===7232###eois===7246###lif===30###soif===818###eoif===832###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");unsigned w, h;
    AKA_mark("lis===215###sois===7252###eois===7310###lif===31###soif===838###eoif===896###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");lodepng_inspect(&w, &h, &inspect, png.data(), png.size());
    AKA_mark("lis===216###sois===7316###eois===7389###lif===32###soif===902###eoif===975###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");total_raw_in_size += lodepng_get_raw_size(w, h, &inspect.info_png.color);
    AKA_mark("lis===217###sois===7395###eois===7427###lif===33###soif===981###eoif===1013###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testDecode(std::vector<unsigned char>const&)");total_png_in_size += png.size();
  }
}

/** Instrumented function getFilePart(std::string const&) */
std::string getFilePart(const std::string& path) /* << Aka begin of function std::string getFilePart(const std::string& path) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\getFilePart(std::string const&)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_benchmark.cpp.getFilePart.7451.stub"

  if(AKA_mark("lis===222###sois===7496###eois===7508###lif===1###soif===57###eoif===69###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\getFilePart(std::string const&)") && (AKA_mark("lis===222###sois===7496###eois===7508###lif===1###soif===57###eoif===69###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\getFilePart(std::string const&)") && (path.empty()))) {
AKA_mark("lis===222###sois===7510###eois===7520###lif===1###soif===71###eoif===81###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\getFilePart(std::string const&)");return "";
}

else {
AKA_mark("lis===-222-###sois===-7496-###eois===-749612-###lif===-1-###soif===-###eoif===-69-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\getFilePart(std::string const&)");
}
  AKA_mark("lis===223###sois===7524###eois===7552###lif===2###soif===85###eoif===113###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\getFilePart(std::string const&)");int slash = path.size() - 1;
  int AKA_BLOCK_LOOP_7556 = 0;
    while(AKA_mark("lis===224###sois===7562###eois===7602###lif===3###soif===123###eoif===163###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\getFilePart(std::string const&)") && ((AKA_mark("lis===224###sois===7562###eois===7572###lif===3###soif===123###eoif===133###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\getFilePart(std::string const&)") && (slash >= 0)) && (AKA_mark("lis===224###sois===7576###eois===7602###lif===3###soif===137###eoif===163###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\getFilePart(std::string const&)") && (path[(size_t)slash] != '/')))) {
AKA_mark("lis===224###sois===7604###eois===7612###lif===3###soif===165###eoif===173###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\getFilePart(std::string const&)");slash--;
}

  AKA_mark("lis===225###sois===7616###eois===7656###lif===4###soif===177###eoif===217###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\getFilePart(std::string const&)");return path.substr((size_t)(slash + 1));
}

/** Instrumented function testFile(std::string const&) */
void testFile(const std::string& filename) /* << Aka begin of function void testFile(const std::string& filename) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_benchmark.cpp.testFile.7668.stub"

  if(AKA_mark("lis===229###sois===7714###eois===7721###lif===1###soif===51###eoif===58###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (AKA_mark("lis===229###sois===7714###eois===7721###lif===1###soif===51###eoif===58###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (verbose))) {
AKA_mark("lis===229###sois===7723###eois===7769###lif===1###soif===60###eoif===106###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");std::cout << "file " << filename << std::endl;
}

else {
AKA_mark("lis===-229-###sois===-7714-###eois===-77147-###lif===-1-###soif===-###eoif===-58-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");
}

  AKA_mark("lis===231###sois===7775###eois===7806###lif===3###soif===112###eoif===143###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");std::vector<unsigned char> png;
  if(AKA_mark("lis===232###sois===7813###eois===7846###lif===4###soif===150###eoif===183###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (AKA_mark("lis===232###sois===7813###eois===7846###lif===4###soif===150###eoif===183###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (lodepng::load_file(png, filename)))) {
    AKA_mark("lis===233###sois===7855###eois===7931###lif===5###soif===192###eoif===268###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");std::cout << "\nfailed to load file " << filename << std::endl << std::endl;
    AKA_mark("lis===234###sois===7937###eois===7944###lif===6###soif===274###eoif===281###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");return;
  }
else {
AKA_mark("lis===-232-###sois===-7813-###eois===-781333-###lif===-4-###soif===-###eoif===-183-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");
}

  // input image stats
  {
    AKA_mark("lis===239###sois===7986###eois===8009###lif===11###soif===323###eoif===346###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");lodepng::State inspect;
    AKA_mark("lis===240###sois===8015###eois===8029###lif===12###soif===352###eoif===366###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");unsigned w, h;
    AKA_mark("lis===241###sois===8035###eois===8093###lif===13###soif===372###eoif===430###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");lodepng_inspect(&w, &h, &inspect, png.data(), png.size());
    AKA_mark("lis===242###sois===8099###eois===8123###lif===14###soif===436###eoif===460###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");total_pixels += (w * h);
    AKA_mark("lis===243###sois===8129###eois===8163###lif===15###soif===466###eoif===500###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");total_png_orig_size += png.size();
    AKA_mark("lis===244###sois===8169###eois===8239###lif===16###soif===506###eoif===576###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");size_t raw_size = lodepng_get_raw_size(w, h, &inspect.info_png.color);
    AKA_mark("lis===245###sois===8245###eois===8277###lif===17###soif===582###eoif===614###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");total_raw_orig_size += raw_size;
    if(AKA_mark("lis===246###sois===8286###eois===8293###lif===18###soif===623###eoif===630###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (AKA_mark("lis===246###sois===8286###eois===8293###lif===18###soif===623###eoif===630###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (verbose))) {
AKA_mark("lis===246###sois===8295###eois===8417###lif===18###soif===632###eoif===754###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");std::cout << "orig compressed size: " << png.size() << ", pixels: " << (w * h) << ", raw size: " << raw_size << std::endl;
}

else {
AKA_mark("lis===-246-###sois===-8286-###eois===-82867-###lif===-18-###soif===-###eoif===-630-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");
}
  }

  if(AKA_mark("lis===249###sois===8431###eois===8440###lif===21###soif===768###eoif===777###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (AKA_mark("lis===249###sois===8431###eois===8440###lif===21###soif===768###eoif===777###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (do_encode))) {
    AKA_mark("lis===250###sois===8449###eois===8461###lif===22###soif===786###eoif===798###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");Image image;
    AKA_mark("lis===251###sois===8467###eois===8502###lif===23###soif===804###eoif===839###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");image.name = getFilePart(filename);
    AKA_mark("lis===252###sois===8508###eois===8535###lif===24###soif===845###eoif===872###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");image.colorType = LCT_RGBA;
    AKA_mark("lis===253###sois===8541###eois===8560###lif===25###soif===878###eoif===897###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");image.bitDepth = 8;
    AKA_mark("lis===254###sois===8566###eois===8681###lif===26###soif===903###eoif===1018###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");assertEquals(0, lodepng::decode(image.data, image.width, image.height, filename, image.colorType, image.bitDepth));

    AKA_mark("lis===256###sois===8689###eois===8741###lif===28###soif===1026###eoif===1078###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");std::vector<unsigned char> temp = testEncode(image);
    if(AKA_mark("lis===257###sois===8750###eois===8764###lif===29###soif===1087###eoif===1101###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (AKA_mark("lis===257###sois===8750###eois===8764###lif===29###soif===1087###eoif===1101###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (decode_encoded))) {
AKA_mark("lis===257###sois===8766###eois===8777###lif===29###soif===1103###eoif===1114###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");png = temp;
}

else {
AKA_mark("lis===-257-###sois===-8750-###eois===-875014-###lif===-29-###soif===-###eoif===-1101-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");
}
  }
else {
AKA_mark("lis===-249-###sois===-8431-###eois===-84319-###lif===-21-###soif===-###eoif===-777-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");
}

  if(AKA_mark("lis===260###sois===8791###eois===8800###lif===32###soif===1128###eoif===1137###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (AKA_mark("lis===260###sois===8791###eois===8800###lif===32###soif===1128###eoif===1137###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (do_decode))) {
    AKA_mark("lis===261###sois===8809###eois===8825###lif===33###soif===1146###eoif===1162###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");testDecode(png);
  }
else {
AKA_mark("lis===-260-###sois===-8791-###eois===-87919-###lif===-32-###soif===-###eoif===-1137-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");
}

  if(AKA_mark("lis===264###sois===8839###eois===8846###lif===36###soif===1176###eoif===1183###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (AKA_mark("lis===264###sois===8839###eois===8846###lif===36###soif===1176###eoif===1183###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)") && (verbose))) {
AKA_mark("lis===264###sois===8848###eois===8871###lif===36###soif===1185###eoif===1208###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");std::cout << std::endl;
}

else {
AKA_mark("lis===-264-###sois===-8839-###eois===-88397-###lif===-36-###soif===-###eoif===-1183-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\testFile(std::string const&)");
}
}

/** Instrumented function showHelp(int,char*[]) */
void showHelp(int argc, char *argv[]) /* << Aka begin of function void showHelp(int argc, char *argv[]) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\showHelp(int,char*[])");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_benchmark.cpp.showHelp.8883.stub"

  AKA_mark("lis===268###sois===8921###eois===8932###lif===1###soif===43###eoif===54###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\showHelp(int,char*[])");(void)argc;
  AKA_mark("lis===269###sois===8936###eois===9041###lif===2###soif===58###eoif===163###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\showHelp(int,char*[])");std::cout << "Usage: " << argv[0] << " png_filenames... [OPTIONS...] [--dumpdir directory]" << std::endl;
  AKA_mark("lis===270###sois===9045###eois===9082###lif===3###soif===167###eoif===204###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\showHelp(int,char*[])");std::cout << "Options:" << std::endl;
  AKA_mark("lis===271###sois===9086###eois===9135###lif===4###soif===208###eoif===257###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\showHelp(int,char*[])");std::cout << "  -h: show this help" << std::endl;
  AKA_mark("lis===272###sois===9139###eois===9181###lif===5###soif===261###eoif===303###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\showHelp(int,char*[])");std::cout << "  -v: verbose" << std::endl;
  AKA_mark("lis===273###sois===9185###eois===9231###lif===6###soif===307###eoif===353###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\showHelp(int,char*[])");std::cout << "  -d: decode only" << std::endl;
  AKA_mark("lis===274###sois===9235###eois===9281###lif===7###soif===357###eoif===403###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\showHelp(int,char*[])");std::cout << "  -e: encode only" << std::endl;
  AKA_mark("lis===275###sois===9285###eois===9401###lif===8###soif===407###eoif===523###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\showHelp(int,char*[])");std::cout << "  -o: decode on original images rather than encoded ones (always true if -d without -e)" << std::endl;
  AKA_mark("lis===276###sois===9405###eois===9639###lif===9###soif===527###eoif===761###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_benchmark.cpp\\showHelp(int,char*[])");std::cout << "  -m: apply modifications to encoder and decoder settings, the modification itself must be implemented or changed in the benchmark source code (search for apply_mods in the code, for encode and for decode)" << std::endl;
}

// int main(int argc, char *argv[]) {
//   verbose = false;
//   do_decode = true;
//   do_encode = true;
//   decode_encoded = true;

//   std::vector<std::string> files;

//   for(int i = 1; i < argc; i++) {
//     std::string arg = argv[i];
//     if(arg == "-v") verbose = true;
//     else if(arg == "-h" || arg == "--help") { showHelp(argc, argv); return 0; }
//     else if(arg == "-d") do_decode ? (do_encode = false) : (do_decode = true);
//     else if(arg == "-e") do_encode ? (do_decode = false) : (do_encode = true);
//     else if(arg == "-o") decode_encoded = false;
//     else if(arg == "-m") apply_mods = true;
//     else if(arg == "--dumpdir" && i + 1 < argc) {
//       dumpdir = argv[++i];
//     }
//     else files.push_back(arg);
//   }

//   if(!do_encode) decode_encoded = false;

//   if(files.empty()) {
//     std::cout << "must give .png filenames to benchamrk" << std::endl;
//     showHelp(argc, argv);
//     return 1;
//   }



//   for(size_t i = 0; i < files.size(); i++) {
//     testFile(files[i]);
//   }

//   // test images stats
//   if(verbose) {
//     std::cout << "Final Summary: " << std::endl;
//     std::cout << "input images: " << files.size() << std::endl;
//     std::cout << "total_pixels: " << total_pixels << std::endl;
//     // file size of original PNGs that were given as command line arguments to the tool
//     std::cout << "total_png_orig_size: " << total_png_orig_size << " (" << (8.0 * total_png_orig_size / total_pixels) << " bpp)" << std::endl;
//     // size of the data inside the original PNGs, dependent on color encoding (bit depth used in the PNG)
//     std::cout << "total_raw_orig_size: " << total_raw_orig_size << " (" << (8.0 * total_raw_orig_size / total_pixels) << " bpp)" << std::endl;
//     // size of the pixel data given to the benchmark encoder, dependent on color encoding (bit depth used in the image representation in the benchmark tool, probably 32 bits)
//     if(do_encode) std::cout << "total_raw_enc_size: " << total_raw_enc_size << " (" << (8.0 * total_raw_enc_size / total_pixels) << " bpp)" << std::endl;
//     // file size of PNGs created by the benchmark encoder
//     if(do_encode) std::cout << "total_png_out_size: " << total_png_out_size << " (" << (8.0 * total_png_out_size / total_pixels) << " bpp)" << std::endl;
//     // size of the data inside the PNGs created by the benchmark encoder, dependent on color encoding (bit depth used in the PNG), may differ from total_raw_orig_size since the encoder may choose to use a different color encoding
//     if(do_encode) std::cout << "total_raw_out_size: " << total_raw_out_size << " (" << (8.0 * total_raw_out_size / total_pixels) << " bpp)" << std::endl;
//     // size of file size of the PNGs given to the benchmark decoder, this could either be the original ones or the ones encoded by the benchmark encoder depending on user options
//     if(do_decode) std::cout << "total_png_in_size: " << total_png_in_size << " (" << (8.0 * total_png_in_size / total_pixels) << " bpp)" << std::endl;
//     // size of the data inside the PNGs mentioned at total_png_in_size, dependent on color encoding (bit depth used in the image representation in the benchmark tool, probably 32 bits)
//     if(do_decode) std::cout << "total_raw_in_size: " << total_raw_in_size << " (" << (8.0 * total_raw_in_size / total_pixels) << " bpp)" << std::endl;
//     // size of the pixel data requested from the benchmark decoder, dependent on color encoding requested (bit depth used in the image representation in the benchmark tool, probably 32 bits)
//     if(do_decode) std::cout << "total_raw_dec_size: " << total_raw_dec_size << " (" << (8.0 * total_raw_dec_size / total_pixels) << " bpp)" << std::endl;
//   }

//   // final encoding stats
//   if(do_encode) {
//     std::cout << "encoding time: " << total_enc_time << "s on " << total_pixels << " pixels and " << total_raw_out_size << " raw bytes ("
//               << ((total_raw_enc_size/1024.0/1024.0)/(total_enc_time)) << " MB/s, " << ((total_pixels/1024.0/1024.0)/(total_enc_time)) << " MP/s)" << std::endl;
//     std::cout << "encoded size: " << total_png_out_size << " (" << (100.0 * total_png_out_size / total_raw_out_size) << "%), bpp: "
//               << (8.0 * total_png_out_size / total_pixels) << std::endl;
//   }

//   // final decoding stats
//   if(do_decode) {
//     if(verbose) std::cout << "decoding iterations: " << NUM_DECODE << std::endl;
//     std::cout << "decoding time: " << total_dec_time/NUM_DECODE << "s on " << total_pixels << " pixels and " << total_png_in_size
//               << " compressed bytes (" << ((total_raw_in_size/1024.0/1024.0)/(total_dec_time/NUM_DECODE)) << " MB/s, "
//               << ((total_pixels/1024.0/1024.0)/(total_dec_time/NUM_DECODE)) << " MP/s)" << std::endl;
//   }
// }

#endif
