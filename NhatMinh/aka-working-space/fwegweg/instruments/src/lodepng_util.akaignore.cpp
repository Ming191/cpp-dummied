/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_LVANDEVE_LODEPNG_SRC_LODEPNG_UTIL_CPP
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_LVANDEVE_LODEPNG_SRC_LODEPNG_UTIL_CPP
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
LodePNG Utils

Copyright (c) 2005-2024 Lode Vandevenne

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

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__LODEPNG_UTIL_H_
#define AKA_INCLUDE__LODEPNG_UTIL_H_
#include "lodepng_util.akaignore.h"
#endif

#include <stdlib.h> /* allocations */

namespace lodepng {

/** Instrumented function getPNGHeaderInfo(std::vector<unsigned char>const&) */
LodePNGInfo getPNGHeaderInfo(const std::vector<unsigned char>& png) /* << Aka begin of function LodePNGInfo getPNGHeaderInfo(const std::vector<unsigned char>& png) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPNGHeaderInfo(std::vector<unsigned char>const&)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.getPNGHeaderInfo.1031.stub"

  AKA_mark("lis===32###sois===1092###eois===1106###lif===1###soif===73###eoif===87###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPNGHeaderInfo(std::vector<unsigned char>const&)");unsigned w, h;
  AKA_mark("lis===33###sois===1110###eois===1131###lif===2###soif===91###eoif===112###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPNGHeaderInfo(std::vector<unsigned char>const&)");lodepng::State state;
  AKA_mark("lis===34###sois===1135###eois===1209###lif===3###soif===116###eoif===190###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPNGHeaderInfo(std::vector<unsigned char>const&)");lodepng_inspect(&w, &h, &state, png.empty() ? NULL : &png[0], png.size());
  AKA_mark("lis===35###sois===1213###eois===1235###lif===4###soif===194###eoif===216###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPNGHeaderInfo(std::vector<unsigned char>const&)");return state.info_png;
}

/** Instrumented function getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&) */
unsigned getChunkInfo(std::vector<std::string>& names, std::vector<size_t>& sizes,
                      const std::vector<unsigned char>& png) /* << Aka begin of function unsigned getChunkInfo(std::vector<std::string>& names, std::vector<size_t>& sizes,
                      const std::vector<unsigned char>& png) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.getChunkInfo.1251.stub"

  // Listing chunks is based on the original file, not the decoded png info.
  AKA_mark("lis===41###sois===1470###eois===1503###lif===3###soif===228###eoif===261###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)");const unsigned char *chunk, *end;
  AKA_mark("lis===42###sois===1507###eois===1529###lif===4###soif===265###eoif===287###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)");end = &png.back() + 1;
  AKA_mark("lis===43###sois===1533###eois===1558###lif===5###soif===291###eoif===316###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)");chunk = &png.front() + 8;

  int AKA_BLOCK_LOOP_1564 = 0;
    while(AKA_mark("lis===45###sois===1570###eois===1601###lif===7###soif===328###eoif===359###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)") && ((AKA_mark("lis===45###sois===1570###eois===1581###lif===7###soif===328###eoif===339###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)") && (chunk < end)) && (AKA_mark("lis===45###sois===1585###eois===1601###lif===7###soif===343###eoif===359###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)") && (end - chunk >= 8)))) {
        AKA_BLOCK_LOOP_1564++;
        if (AKA_BLOCK_LOOP_1564 > 1000) {
            //break;
        }
    AKA_mark("lis===46###sois===1610###eois===1623###lif===8###soif===368###eoif===381###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)");char type[5];
    AKA_mark("lis===47###sois===1629###eois===1661###lif===9###soif===387###eoif===419###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)");lodepng_chunk_type(type, chunk);
    if(AKA_mark("lis===48###sois===1670###eois===1699###lif===10###soif===428###eoif===457###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)") && (AKA_mark("lis===48###sois===1670###eois===1699###lif===10###soif===428###eoif===457###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)") && (std::string(type).size() != 4))) {
AKA_mark("lis===48###sois===1701###eois===1710###lif===10###soif===459###eoif===468###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)");return 1;
}

else {
AKA_mark("lis===-48-###sois===-1670-###eois===-167029-###lif===-10-###soif===-###eoif===-457-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)");
}

    AKA_mark("lis===50###sois===1718###eois===1764###lif===12###soif===476###eoif===522###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)");unsigned length = lodepng_chunk_length(chunk);
    AKA_mark("lis===51###sois===1770###eois===1792###lif===13###soif===528###eoif===550###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)");names.push_back(type);
    AKA_mark("lis===52###sois===1798###eois===1822###lif===14###soif===556###eoif===580###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)");sizes.push_back(length);
    AKA_mark("lis===53###sois===1828###eois===1873###lif===15###soif===586###eoif===631###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)");chunk = lodepng_chunk_next_const(chunk, end);
  }
  AKA_mark("lis===55###sois===1882###eois===1891###lif===17###soif===640###eoif===649###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunkInfo(std::vector<std::string>&,std::vector<size_t>&,std::vector<unsigned char>const&)");return 0;
}

/** Instrumented function getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&) */
unsigned getChunks(std::vector<std::string> names[3],
                   std::vector<std::vector<unsigned char> > chunks[3],
                   const std::vector<unsigned char>& png) /* << Aka begin of function unsigned getChunks(std::vector<std::string> names[3],
                   std::vector<std::vector<unsigned char> > chunks[3],
                   const std::vector<unsigned char>& png) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.getChunks.1907.stub"

  AKA_mark("lis===61###sois===2088###eois===2128###lif===3###soif===190###eoif===230###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");const unsigned char *chunk, *next, *end;
  AKA_mark("lis===62###sois===2132###eois===2154###lif===4###soif===234###eoif===256###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");end = &png.back() + 1;
  AKA_mark("lis===63###sois===2158###eois===2183###lif===5###soif===260###eoif===285###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");chunk = &png.front() + 8;

  AKA_mark("lis===65###sois===2189###eois===2206###lif===7###soif===291###eoif===308###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");int location = 0;

  int AKA_BLOCK_LOOP_2212 = 0;
    while(AKA_mark("lis===67###sois===2218###eois===2249###lif===9###soif===320###eoif===351###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && ((AKA_mark("lis===67###sois===2218###eois===2229###lif===9###soif===320###eoif===331###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (chunk < end)) && (AKA_mark("lis===67###sois===2233###eois===2249###lif===9###soif===335###eoif===351###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (end - chunk >= 8)))) {
        AKA_BLOCK_LOOP_2212++;
        if (AKA_BLOCK_LOOP_2212 > 1000) {
            //break;
        }
    AKA_mark("lis===68###sois===2258###eois===2271###lif===10###soif===360###eoif===373###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");char type[5];
    AKA_mark("lis===69###sois===2277###eois===2309###lif===11###soif===379###eoif===411###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");lodepng_chunk_type(type, chunk);
    AKA_mark("lis===70###sois===2315###eois===2338###lif===12###soif===417###eoif===440###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");std::string name(type);
    if(AKA_mark("lis===71###sois===2347###eois===2363###lif===13###soif===449###eoif===465###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (AKA_mark("lis===71###sois===2347###eois===2363###lif===13###soif===449###eoif===465###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (name.size() != 4))) {
AKA_mark("lis===71###sois===2365###eois===2374###lif===13###soif===467###eoif===476###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");return 1;
}

else {
AKA_mark("lis===-71-###sois===-2347-###eois===-234716-###lif===-13-###soif===-###eoif===-465-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");
}

    AKA_mark("lis===73###sois===2382###eois===2426###lif===15###soif===484###eoif===528###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");next = lodepng_chunk_next_const(chunk, end);

    if(AKA_mark("lis===75###sois===2437###eois===2451###lif===17###soif===539###eoif===553###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (AKA_mark("lis===75###sois===2437###eois===2451###lif===17###soif===539###eoif===553###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (name == "IHDR"))) {
      AKA_mark("lis===76###sois===2462###eois===2475###lif===18###soif===564###eoif===577###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");location = 0;
    } else {
if(AKA_mark("lis===77###sois===2491###eois===2505###lif===19###soif===593###eoif===607###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (AKA_mark("lis===77###sois===2491###eois===2505###lif===19###soif===593###eoif===607###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (name == "PLTE"))) {
      AKA_mark("lis===78###sois===2516###eois===2529###lif===20###soif===618###eoif===631###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");location = 1;
    } else {
if(AKA_mark("lis===79###sois===2545###eois===2559###lif===21###soif===647###eoif===661###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (AKA_mark("lis===79###sois===2545###eois===2559###lif===21###soif===647###eoif===661###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (name == "IDAT"))) {
      AKA_mark("lis===80###sois===2570###eois===2583###lif===22###soif===672###eoif===685###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");location = 2;
    } else {
if(AKA_mark("lis===81###sois===2599###eois===2613###lif===23###soif===701###eoif===715###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (AKA_mark("lis===81###sois===2599###eois===2613###lif===23###soif===701###eoif===715###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (name == "IEND"))) {
      AKA_mark("lis===82###sois===2624###eois===2630###lif===24###soif===726###eoif===732###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");break; // anything after IEND is not part of the PNG or the 3 groups here.
    } else {
      if(AKA_mark("lis===84###sois===2723###eois===2734###lif===26###soif===825###eoif===836###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (AKA_mark("lis===84###sois===2723###eois===2734###lif===26###soif===825###eoif===836###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)") && (next >= end))) {
AKA_mark("lis===84###sois===2736###eois===2745###lif===26###soif===838###eoif===847###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");return 1;
}

else {
AKA_mark("lis===-84-###sois===-2723-###eois===-272311-###lif===-26-###soif===-###eoif===-836-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");
} // invalid chunk, content too far
      AKA_mark("lis===85###sois===2787###eois===2819###lif===27###soif===889###eoif===921###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");names[location].push_back(name);
      AKA_mark("lis===86###sois===2827###eois===2895###lif===28###soif===929###eoif===997###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");chunks[location].push_back(std::vector<unsigned char>(chunk, next));
    }
}

}

}


    AKA_mark("lis===89###sois===2910###eois===2923###lif===31###soif===1012###eoif===1025###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");chunk = next;
  }
  AKA_mark("lis===91###sois===2932###eois===2941###lif===33###soif===1034###eoif===1043###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChunks(std::vector<std::string>[3],std::vector<std::vector<unsigned char>>[3],std::vector<unsigned char>const&)");return 0;
}


/** Instrumented function insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3]) */
unsigned insertChunks(std::vector<unsigned char>& png,
                      const std::vector<std::vector<unsigned char> > chunks[3]) /* << Aka begin of function unsigned insertChunks(std::vector<unsigned char>& png,
                      const std::vector<std::vector<unsigned char> > chunks[3]) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.insertChunks.2959.stub"

  AKA_mark("lis===97###sois===3091###eois===3132###lif===2###soif===141###eoif===182###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");const unsigned char *chunk, *begin, *end;
  AKA_mark("lis===98###sois===3136###eois===3158###lif===3###soif===186###eoif===208###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");end = &png.back() + 1;
  AKA_mark("lis===99###sois===3162###eois===3195###lif===4###soif===212###eoif===245###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");begin = chunk = &png.front() + 8;

  AKA_mark("lis===101###sois===3201###eois===3213###lif===6###soif===251###eoif===263###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");long l0 = 0; //location 0: IHDR-l0-PLTE (or IHDR-l0-l1-IDAT)
  AKA_mark("lis===102###sois===3265###eois===3277###lif===7###soif===315###eoif===327###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");long l1 = 0; //location 1: PLTE-l1-IDAT (or IHDR-l0-l1-IDAT)
  AKA_mark("lis===103###sois===3329###eois===3341###lif===8###soif===379###eoif===391###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");long l2 = 0; //location 2: IDAT-l2-IEND

  int AKA_BLOCK_LOOP_3374 = 0;
    while(AKA_mark("lis===105###sois===3380###eois===3411###lif===10###soif===430###eoif===461###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && ((AKA_mark("lis===105###sois===3380###eois===3391###lif===10###soif===430###eoif===441###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (chunk < end)) && (AKA_mark("lis===105###sois===3395###eois===3411###lif===10###soif===445###eoif===461###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (end - chunk >= 8)))) {
        AKA_BLOCK_LOOP_3374++;
        if (AKA_BLOCK_LOOP_3374 > 1000) {
            //break;
        }
    AKA_mark("lis===106###sois===3420###eois===3433###lif===11###soif===470###eoif===483###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");char type[5];
    AKA_mark("lis===107###sois===3439###eois===3471###lif===12###soif===489###eoif===521###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");lodepng_chunk_type(type, chunk);
    AKA_mark("lis===108###sois===3477###eois===3500###lif===13###soif===527###eoif===550###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");std::string name(type);
    if(AKA_mark("lis===109###sois===3509###eois===3525###lif===14###soif===559###eoif===575###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (AKA_mark("lis===109###sois===3509###eois===3525###lif===14###soif===559###eoif===575###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (name.size() != 4))) {
AKA_mark("lis===109###sois===3527###eois===3536###lif===14###soif===577###eoif===586###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");return 1;
}

else {
AKA_mark("lis===-109-###sois===-3509-###eois===-350916-###lif===-14-###soif===-###eoif===-575-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");
}

    if(AKA_mark("lis===111###sois===3547###eois===3561###lif===16###soif===597###eoif===611###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (AKA_mark("lis===111###sois===3547###eois===3561###lif===16###soif===597###eoif===611###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (name == "PLTE"))) {
      if(AKA_mark("lis===112###sois===3575###eois===3582###lif===17###soif===625###eoif===632###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (AKA_mark("lis===112###sois===3575###eois===3582###lif===17###soif===625###eoif===632###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (l0 == 0))) {
AKA_mark("lis===112###sois===3584###eois===3607###lif===17###soif===634###eoif===657###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");l0 = chunk - begin + 8;
}

else {
AKA_mark("lis===-112-###sois===-3575-###eois===-35757-###lif===-17-###soif===-###eoif===-632-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");
}
    } else {
if(AKA_mark("lis===113###sois===3623###eois===3637###lif===18###soif===673###eoif===687###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (AKA_mark("lis===113###sois===3623###eois===3637###lif===18###soif===673###eoif===687###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (name == "IDAT"))) {
      if(AKA_mark("lis===114###sois===3651###eois===3658###lif===19###soif===701###eoif===708###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (AKA_mark("lis===114###sois===3651###eois===3658###lif===19###soif===701###eoif===708###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (l0 == 0))) {
AKA_mark("lis===114###sois===3660###eois===3683###lif===19###soif===710###eoif===733###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");l0 = chunk - begin + 8;
}

else {
AKA_mark("lis===-114-###sois===-3651-###eois===-36517-###lif===-19-###soif===-###eoif===-708-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");
}
      if(AKA_mark("lis===115###sois===3694###eois===3701###lif===20###soif===744###eoif===751###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (AKA_mark("lis===115###sois===3694###eois===3701###lif===20###soif===744###eoif===751###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (l1 == 0))) {
AKA_mark("lis===115###sois===3703###eois===3726###lif===20###soif===753###eoif===776###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");l1 = chunk - begin + 8;
}

else {
AKA_mark("lis===-115-###sois===-3694-###eois===-36947-###lif===-20-###soif===-###eoif===-751-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");
}
    } else {
if(AKA_mark("lis===116###sois===3742###eois===3756###lif===21###soif===792###eoif===806###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (AKA_mark("lis===116###sois===3742###eois===3756###lif===21###soif===792###eoif===806###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (name == "IEND"))) {
      if(AKA_mark("lis===117###sois===3770###eois===3777###lif===22###soif===820###eoif===827###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (AKA_mark("lis===117###sois===3770###eois===3777###lif===22###soif===820###eoif===827###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (l2 == 0))) {
AKA_mark("lis===117###sois===3779###eois===3802###lif===22###soif===829###eoif===852###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");l2 = chunk - begin + 8;
}

else {
AKA_mark("lis===-117-###sois===-3770-###eois===-37707-###lif===-22-###soif===-###eoif===-827-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");
}
    }
else {
AKA_mark("lis===-116-###sois===-3742-###eois===-374214-###lif===-21-###soif===-###eoif===-806-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");
}
}

}


    AKA_mark("lis===120###sois===3817###eois===3862###lif===25###soif===867###eoif===912###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");chunk = lodepng_chunk_next_const(chunk, end);
  }

  AKA_mark("lis===123###sois===3873###eois===3907###lif===28###soif===923###eoif===957###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");std::vector<unsigned char> result;
  AKA_mark("lis===124###sois===3911###eois===3970###lif===29###soif===961###eoif===1020###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");result.insert(result.end(), png.begin(), png.begin() + l0);
  int AKA_BLOCK_LOOP_3974 = 0;
    AKA_mark("lis===125###sois===3978###eois===3991###lif===30###soif===1028###eoif===1041###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");
for(size_t i = 0; AKA_mark("lis===125###sois===3992###eois===4012###lif===30###soif===1042###eoif===1062###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (AKA_mark("lis===125###sois===3992###eois===4012###lif===30###soif===1042###eoif===1062###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (i < chunks[0].size())); ({AKA_mark("lis===125###sois===4014###eois===4017###lif===30###soif===1064###eoif===1067###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");i++;})) {
AKA_mark("lis===125###sois===4019###eois===4089###lif===30###soif===1069###eoif===1139###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");result.insert(result.end(), chunks[0][i].begin(), chunks[0][i].end());
}

  AKA_mark("lis===126###sois===4093###eois===4157###lif===31###soif===1143###eoif===1207###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");result.insert(result.end(), png.begin() + l0, png.begin() + l1);
  int AKA_BLOCK_LOOP_4161 = 0;
    AKA_mark("lis===127###sois===4165###eois===4178###lif===32###soif===1215###eoif===1228###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");
for(size_t i = 0; AKA_mark("lis===127###sois===4179###eois===4199###lif===32###soif===1229###eoif===1249###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (AKA_mark("lis===127###sois===4179###eois===4199###lif===32###soif===1229###eoif===1249###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (i < chunks[1].size())); ({AKA_mark("lis===127###sois===4201###eois===4204###lif===32###soif===1251###eoif===1254###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");i++;})) {
AKA_mark("lis===127###sois===4206###eois===4276###lif===32###soif===1256###eoif===1326###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");result.insert(result.end(), chunks[1][i].begin(), chunks[1][i].end());
}

  AKA_mark("lis===128###sois===4280###eois===4344###lif===33###soif===1330###eoif===1394###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");result.insert(result.end(), png.begin() + l1, png.begin() + l2);
  int AKA_BLOCK_LOOP_4348 = 0;
    AKA_mark("lis===129###sois===4352###eois===4365###lif===34###soif===1402###eoif===1415###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");
for(size_t i = 0; AKA_mark("lis===129###sois===4366###eois===4386###lif===34###soif===1416###eoif===1436###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (AKA_mark("lis===129###sois===4366###eois===4386###lif===34###soif===1416###eoif===1436###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])") && (i < chunks[2].size())); ({AKA_mark("lis===129###sois===4388###eois===4391###lif===34###soif===1438###eoif===1441###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");i++;})) {
AKA_mark("lis===129###sois===4393###eois===4463###lif===34###soif===1443###eoif===1513###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");result.insert(result.end(), chunks[2][i].begin(), chunks[2][i].end());
}

  AKA_mark("lis===130###sois===4467###eois===4524###lif===35###soif===1517###eoif===1574###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");result.insert(result.end(), png.begin() + l2, png.end());

  AKA_mark("lis===132###sois===4530###eois===4543###lif===37###soif===1580###eoif===1593###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");png = result;
  AKA_mark("lis===133###sois===4547###eois===4556###lif===38###soif===1597###eoif===1606###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\insertChunks(std::vector<unsigned char>&,std::vector<std::vector<unsigned char>>const[3])");return 0;
}

/** Instrumented function getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&) */
unsigned getFilterTypesInterlaced(std::vector<std::vector<unsigned char> >& filterTypes,
                                  const std::vector<unsigned char>& png) /* << Aka begin of function unsigned getFilterTypesInterlaced(std::vector<std::vector<unsigned char> >& filterTypes,
                                  const std::vector<unsigned char>& png) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.getFilterTypesInterlaced.4572.stub"

  //Get color type and interlace type
  AKA_mark("lis===139###sois===4770###eois===4791###lif===3###soif===207###eoif===228###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");lodepng::State state;
  AKA_mark("lis===140###sois===4795###eois===4809###lif===4###soif===232###eoif===246###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");unsigned w, h;
  AKA_mark("lis===141###sois===4813###eois===4828###lif===5###soif===250###eoif===265###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");unsigned error;
  AKA_mark("lis===142###sois===4832###eois===4914###lif===6###soif===269###eoif===351###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");error = lodepng_inspect(&w, &h, &state, png.empty() ? NULL : &png[0], png.size());

  if(AKA_mark("lis===144###sois===4923###eois===4928###lif===8###soif===360###eoif===365###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (AKA_mark("lis===144###sois===4923###eois===4928###lif===8###soif===360###eoif===365###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (error))) {
AKA_mark("lis===144###sois===4930###eois===4939###lif===8###soif===367###eoif===376###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");return 1;
}

else {
AKA_mark("lis===-144-###sois===-4923-###eois===-49235-###lif===-8-###soif===-###eoif===-365-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");
}

  //Read literal data from all IDAT chunks
  AKA_mark("lis===147###sois===4989###eois===5030###lif===11###soif===426###eoif===467###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");const unsigned char *chunk, *begin, *end;
  AKA_mark("lis===148###sois===5034###eois===5056###lif===12###soif===471###eoif===493###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");end = &png.back() + 1;
  AKA_mark("lis===149###sois===5060###eois===5093###lif===13###soif===497###eoif===530###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");begin = chunk = &png.front() + 8;

  AKA_mark("lis===151###sois===5099###eois===5132###lif===15###soif===536###eoif===569###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");std::vector<unsigned char> zdata;

  int AKA_BLOCK_LOOP_5138 = 0;
    while(AKA_mark("lis===153###sois===5144###eois===5175###lif===17###soif===581###eoif===612###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && ((AKA_mark("lis===153###sois===5144###eois===5155###lif===17###soif===581###eoif===592###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (chunk < end)) && (AKA_mark("lis===153###sois===5159###eois===5175###lif===17###soif===596###eoif===612###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (end - chunk >= 8)))) {
        AKA_BLOCK_LOOP_5138++;
        if (AKA_BLOCK_LOOP_5138 > 1000) {
            //break;
        }
    AKA_mark("lis===154###sois===5184###eois===5197###lif===18###soif===621###eoif===634###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");char type[5];
    AKA_mark("lis===155###sois===5203###eois===5235###lif===19###soif===640###eoif===672###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");lodepng_chunk_type(type, chunk);
    if(AKA_mark("lis===156###sois===5244###eois===5273###lif===20###soif===681###eoif===710###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (AKA_mark("lis===156###sois===5244###eois===5273###lif===20###soif===681###eoif===710###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (std::string(type).size() != 4))) {
AKA_mark("lis===156###sois===5275###eois===5284###lif===20###soif===712###eoif===721###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");return 1;
}

else {
AKA_mark("lis===-156-###sois===-5244-###eois===-524429-###lif===-20-###soif===-###eoif===-710-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");
} //Probably not a PNG file

    if(AKA_mark("lis===158###sois===5321###eois===5348###lif===22###soif===758###eoif===785###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (AKA_mark("lis===158###sois===5321###eois===5348###lif===22###soif===758###eoif===785###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (std::string(type) == "IDAT"))) {
      AKA_mark("lis===159###sois===5359###eois===5420###lif===23###soif===796###eoif===857###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");const unsigned char* cdata = lodepng_chunk_data_const(chunk);
      AKA_mark("lis===160###sois===5428###eois===5475###lif===24###soif===865###eoif===912###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");unsigned clength = lodepng_chunk_length(chunk);
      if(AKA_mark("lis===161###sois===5486###eois===5568###lif===25###soif===923###eoif===1005###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (((AKA_mark("lis===161###sois===5486###eois===5512###lif===25###soif===923###eoif===949###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (chunk + clength + 12 > end)) || (AKA_mark("lis===161###sois===5516###eois===5536###lif===25###soif===953###eoif===973###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (clength > png.size()))) || (AKA_mark("lis===161###sois===5540###eois===5568###lif===25###soif===977###eoif===1005###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (chunk + clength + 12 < begin)))) {
        AKA_mark("lis===162###sois===5581###eois===5590###lif===26###soif===1018###eoif===1027###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");return 1; // corrupt chunk length
      }
else {
AKA_mark("lis===-161-###sois===-5486-###eois===-548682-###lif===-25-###soif===-###eoif===-1005-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");
}
      AKA_mark("lis===164###sois===5631###eois===5681###lif===28###soif===1068###eoif===1118###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");zdata.insert(zdata.end(), cdata, cdata + clength);
    }
else {
AKA_mark("lis===-158-###sois===-5321-###eois===-532127-###lif===-22-###soif===-###eoif===-785-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");
}

    AKA_mark("lis===167###sois===5696###eois===5741###lif===31###soif===1133###eoif===1178###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");chunk = lodepng_chunk_next_const(chunk, end);
  }

  //Decompress all IDAT data
  AKA_mark("lis===171###sois===5782###eois===5814###lif===35###soif===1219###eoif===1251###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");std::vector<unsigned char> data;
  AKA_mark("lis===172###sois===5818###eois===5900###lif===36###soif===1255###eoif===1337###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");error = lodepng::decompress(data, zdata.empty() ? NULL : &zdata[0], zdata.size());

  if(AKA_mark("lis===174###sois===5909###eois===5914###lif===38###soif===1346###eoif===1351###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (AKA_mark("lis===174###sois===5909###eois===5914###lif===38###soif===1346###eoif===1351###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (error))) {
AKA_mark("lis===174###sois===5916###eois===5925###lif===38###soif===1353###eoif===1362###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");return 1;
}

else {
AKA_mark("lis===-174-###sois===-5909-###eois===-59095-###lif===-38-###soif===-###eoif===-1351-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");
}

  if(AKA_mark("lis===176###sois===5934###eois===5970###lif===40###soif===1371###eoif===1407###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (AKA_mark("lis===176###sois===5934###eois===5970###lif===40###soif===1371###eoif===1407###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (state.info_png.interlace_method == 0))) {
    AKA_mark("lis===177###sois===5979###eois===6001###lif===41###soif===1416###eoif===1438###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");filterTypes.resize(1);

    //A line is 1 filter byte + all pixels
    AKA_mark("lis===180###sois===6053###eois===6126###lif===44###soif===1490###eoif===1563###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");size_t linebytes = 1 + lodepng_get_raw_size(w, 1, &state.info_png.color);

    int AKA_BLOCK_LOOP_6134 = 0;
    AKA_mark("lis===182###sois===6138###eois===6151###lif===46###soif===1575###eoif===1588###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");
for(size_t i = 0; AKA_mark("lis===182###sois===6152###eois===6167###lif===46###soif===1589###eoif===1604###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (AKA_mark("lis===182###sois===6152###eois===6167###lif===46###soif===1589###eoif===1604###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (i < data.size())); ({AKA_mark("lis===182###sois===6169###eois===6183###lif===46###soif===1606###eoif===1620###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");i += linebytes;})) {
        AKA_BLOCK_LOOP_6134++;
        if (AKA_BLOCK_LOOP_6134 > 1000) {
            //break;
        }
      AKA_mark("lis===183###sois===6194###eois===6228###lif===47###soif===1631###eoif===1665###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");filterTypes[0].push_back(data[i]);
    }
  } else {
    //Interlaced
    AKA_mark("lis===187###sois===6271###eois===6293###lif===51###soif===1708###eoif===1730###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");filterTypes.resize(7);
    AKA_mark("lis===188###sois===6299###eois===6359###lif===52###soif===1736###eoif===1796###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");static const unsigned ADAM7_IX[7] = { 0, 4, 0, 2, 0, 1, 0 }; /*x start values*/
    AKA_mark("lis===189###sois===6384###eois===6444###lif===53###soif===1821###eoif===1881###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");static const unsigned ADAM7_IY[7] = { 0, 0, 4, 0, 2, 0, 1 }; /*y start values*/
    AKA_mark("lis===190###sois===6469###eois===6529###lif===54###soif===1906###eoif===1966###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");static const unsigned ADAM7_DX[7] = { 8, 8, 4, 4, 2, 2, 1 }; /*x delta values*/
    AKA_mark("lis===191###sois===6554###eois===6614###lif===55###soif===1991###eoif===2051###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");static const unsigned ADAM7_DY[7] = { 8, 8, 8, 4, 4, 2, 2 }; /*y delta values*/
    AKA_mark("lis===192###sois===6639###eois===6654###lif===56###soif===2076###eoif===2091###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");size_t pos = 0;
    int AKA_BLOCK_LOOP_6660 = 0;
    AKA_mark("lis===193###sois===6664###eois===6677###lif===57###soif===2101###eoif===2114###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");
for(size_t j = 0; AKA_mark("lis===193###sois===6678###eois===6683###lif===57###soif===2115###eoif===2120###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (AKA_mark("lis===193###sois===6678###eois===6683###lif===57###soif===2115###eoif===2120###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (j < 7)); ({AKA_mark("lis===193###sois===6685###eois===6688###lif===57###soif===2122###eoif===2125###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");j++;})) {
        AKA_BLOCK_LOOP_6660++;
        if (AKA_BLOCK_LOOP_6660 > 1000) {
            //break;
        }
      AKA_mark("lis===194###sois===6699###eois===6763###lif===58###soif===2136###eoif===2200###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");unsigned w2 = (w - ADAM7_IX[j] + ADAM7_DX[j] - 1) / ADAM7_DX[j];
      AKA_mark("lis===195###sois===6771###eois===6835###lif===59###soif===2208###eoif===2272###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");unsigned h2 = (h - ADAM7_IY[j] + ADAM7_DY[j] - 1) / ADAM7_DY[j];
      if(AKA_mark("lis===196###sois===6846###eois===6882###lif===60###soif===2283###eoif===2319###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && ((AKA_mark("lis===196###sois===6846###eois===6862###lif===60###soif===2283###eoif===2299###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (ADAM7_IX[j] >= w)) || (AKA_mark("lis===196###sois===6866###eois===6882###lif===60###soif===2303###eoif===2319###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (ADAM7_IY[j] >= h)))) {
AKA_mark("lis===196###sois===6884###eois===6893###lif===60###soif===2321###eoif===2330###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");continue;
}

else {
AKA_mark("lis===-196-###sois===-6846-###eois===-684636-###lif===-60-###soif===-###eoif===-2319-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");
}
      AKA_mark("lis===197###sois===6901###eois===6975###lif===61###soif===2338###eoif===2412###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");size_t linebytes = 1 + lodepng_get_raw_size(w2, 1, &state.info_png.color);
      int AKA_BLOCK_LOOP_6983 = 0;
    AKA_mark("lis===198###sois===6987###eois===7000###lif===62###soif===2424###eoif===2437###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");
for(size_t i = 0; AKA_mark("lis===198###sois===7001###eois===7007###lif===62###soif===2438###eoif===2444###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (AKA_mark("lis===198###sois===7001###eois===7007###lif===62###soif===2438###eoif===2444###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)") && (i < h2)); ({AKA_mark("lis===198###sois===7009###eois===7012###lif===62###soif===2446###eoif===2449###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");i++;})) {
        AKA_BLOCK_LOOP_6983++;
        if (AKA_BLOCK_LOOP_6983 > 1000) {
            //break;
        }
        AKA_mark("lis===199###sois===7025###eois===7061###lif===63###soif===2462###eoif===2498###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");filterTypes[j].push_back(data[pos]);
        AKA_mark("lis===200###sois===7071###eois===7088###lif===64###soif===2508###eoif===2525###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");pos += linebytes;
      }
    }
  }
  AKA_mark("lis===204###sois===7113###eois===7122###lif===68###soif===2550###eoif===2559###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypesInterlaced(std::vector<std::vector<unsigned char>>&,std::vector<unsigned char>const&)");return 0; /* OK */
}


/** Instrumented function getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&) */
unsigned getFilterTypes(std::vector<unsigned char>& filterTypes, const std::vector<unsigned char>& png) /* << Aka begin of function unsigned getFilterTypes(std::vector<unsigned char>& filterTypes, const std::vector<unsigned char>& png) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.getFilterTypes.7149.stub"

  AKA_mark("lis===209###sois===7249###eois===7297###lif===1###soif===109###eoif===157###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");std::vector<std::vector<unsigned char> > passes;
  AKA_mark("lis===210###sois===7301###eois===7356###lif===2###soif===161###eoif===216###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");unsigned error = getFilterTypesInterlaced(passes, png);
  if(AKA_mark("lis===211###sois===7363###eois===7368###lif===3###soif===223###eoif===228###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)") && (AKA_mark("lis===211###sois===7363###eois===7368###lif===3###soif===223###eoif===228###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)") && (error))) {
AKA_mark("lis===211###sois===7370###eois===7383###lif===3###soif===230###eoif===243###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");return error;
}

else {
AKA_mark("lis===-211-###sois===-7363-###eois===-73635-###lif===-3-###soif===-###eoif===-228-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");
}

  if(AKA_mark("lis===213###sois===7392###eois===7410###lif===5###soif===252###eoif===270###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)") && (AKA_mark("lis===213###sois===7392###eois===7410###lif===5###soif===252###eoif===270###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)") && (passes.size() == 1))) {
    AKA_mark("lis===214###sois===7419###eois===7447###lif===6###soif===279###eoif===307###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");filterTypes.swap(passes[0]);
  } else {
    // Simplify interlaced filter types to get a single filter value per scanline:
    // put pass 6 and 7 alternating in the one vector, these filters
    // correspond to the closest to what it would be for non-interlaced
    // image. If the image is only 1 pixel wide, pass 6 doesn't exist so the
    // alternative values column0 are used. The shift values are to match
    // the y position in the interlaced sub-images.
    // NOTE: the values 0-6 match Adam7's passes 1-7.
    AKA_mark("lis===223###sois===7953###eois===8006###lif===15###soif===813###eoif===866###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");const unsigned column0[8] = {0, 6, 4, 6, 2, 6, 4, 6};
    AKA_mark("lis===224###sois===8012###eois===8065###lif===16###soif===872###eoif===925###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");const unsigned column1[8] = {5, 6, 5, 6, 5, 6, 5, 6};
    AKA_mark("lis===225###sois===8071###eois===8123###lif===17###soif===931###eoif===983###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");const unsigned shift0[8] = {3, 1, 2, 1, 3, 1, 2, 1};
    AKA_mark("lis===226###sois===8129###eois===8181###lif===18###soif===989###eoif===1041###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");const unsigned shift1[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    AKA_mark("lis===227###sois===8187###eois===8208###lif===19###soif===1047###eoif===1068###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");lodepng::State state;
    AKA_mark("lis===228###sois===8214###eois===8228###lif===20###soif===1074###eoif===1088###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");unsigned w, h;
    AKA_mark("lis===229###sois===8234###eois===8308###lif===21###soif===1094###eoif===1168###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");lodepng_inspect(&w, &h, &state, png.empty() ? NULL : &png[0], png.size());
    AKA_mark("lis===230###sois===8314###eois===8365###lif===22###soif===1174###eoif===1225###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");const unsigned* column = w > 1 ? column1 : column0;
    AKA_mark("lis===231###sois===8371###eois===8419###lif===23###soif===1231###eoif===1279###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");const unsigned* shift = w > 1 ? shift1 : shift0;
    int AKA_BLOCK_LOOP_8425 = 0;
    AKA_mark("lis===232###sois===8429###eois===8442###lif===24###soif===1289###eoif===1302###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");
for(size_t i = 0; AKA_mark("lis===232###sois===8443###eois===8448###lif===24###soif===1303###eoif===1308###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)") && (AKA_mark("lis===232###sois===8443###eois===8448###lif===24###soif===1303###eoif===1308###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)") && (i < h)); ({AKA_mark("lis===232###sois===8450###eois===8453###lif===24###soif===1310###eoif===1313###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");i++;})) {
        AKA_BLOCK_LOOP_8425++;
        if (AKA_BLOCK_LOOP_8425 > 1000) {
            //break;
        }
      AKA_mark("lis===233###sois===8464###eois===8530###lif===25###soif===1324###eoif===1390###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");filterTypes.push_back(passes[column[i & 7u]][i >> shift[i & 7u]]);
    }
  }
  AKA_mark("lis===236###sois===8546###eois===8555###lif===28###soif===1406###eoif===1415###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getFilterTypes(std::vector<unsigned char>&,std::vector<unsigned char>const&)");return 0; /* OK */
}

/** Instrumented function getPaletteValue(unsigned char const*,size_t,int) */
int getPaletteValue(const unsigned char* data, size_t i, int bits) /* << Aka begin of function int getPaletteValue(const unsigned char* data, size_t i, int bits) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.getPaletteValue.8575.stub"

  if(AKA_mark("lis===240###sois===8646###eois===8655###lif===1###soif===75###eoif===84###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)") && (AKA_mark("lis===240###sois===8646###eois===8655###lif===1###soif===75###eoif===84###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)") && (bits == 8))) {
AKA_mark("lis===240###sois===8657###eois===8672###lif===1###soif===86###eoif===101###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)");return data[i];
}

  else {
if(AKA_mark("lis===241###sois===8684###eois===8693###lif===2###soif===113###eoif===122###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)") && (AKA_mark("lis===241###sois===8684###eois===8693###lif===2###soif===113###eoif===122###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)") && (bits == 4))) {
AKA_mark("lis===241###sois===8695###eois===8738###lif===2###soif===124###eoif===167###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)");return (data[i / 2] >> ((i % 2) * 4)) & 15;
}

  else {
if(AKA_mark("lis===242###sois===8750###eois===8759###lif===3###soif===179###eoif===188###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)") && (AKA_mark("lis===242###sois===8750###eois===8759###lif===3###soif===179###eoif===188###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)") && (bits == 2))) {
AKA_mark("lis===242###sois===8761###eois===8803###lif===3###soif===190###eoif===232###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)");return (data[i / 4] >> ((i % 4) * 2)) & 3;
}

  else {
if(AKA_mark("lis===243###sois===8815###eois===8824###lif===4###soif===244###eoif===253###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)") && (AKA_mark("lis===243###sois===8815###eois===8824###lif===4###soif===244###eoif===253###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)") && (bits == 1))) {
AKA_mark("lis===243###sois===8826###eois===8862###lif===4###soif===255###eoif===291###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)");return (data[i / 8] >> (i % 8)) & 1;
}

  else {
AKA_mark("lis===244###sois===8871###eois===8880###lif===5###soif===300###eoif===309###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getPaletteValue(unsigned char const*,size_t,int)");return 0;
}

}

}

}

}


////////////////////////////////////////////////////////////////////////////////

#ifdef LODEPNG_COMPILE_ANCILLARY_CHUNKS


// Only temporarily here until this is integrated into lodepng.c(pp)
#define LODEPNG_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define LODEPNG_MIN(a, b) (((a) < (b)) ? (a) : (b))
/* Safely check if multiplying two integers will overflow (no undefined
behavior, compiler removing the code, etc...) and output result. */
/** Instrumented function lodepng_mulofl(size_t,size_t,size_t*) */
static int lodepng_mulofl(size_t a, size_t b, size_t* result) /* << Aka begin of function int lodepng_mulofl(size_t a, size_t b, size_t* result) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_mulofl(size_t,size_t,size_t*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.lodepng_mulofl.9347.stub"

  AKA_mark("lis===259###sois===9403###eois===9419###lif===1###soif===67###eoif===83###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_mulofl(size_t,size_t,size_t*)");*result = a * b; /* Unsigned multiplication is well defined and safe in C90 */
  AKA_mark("lis===260###sois===9485###eois===9521###lif===2###soif===149###eoif===185###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_mulofl(size_t,size_t,size_t*)");return (a != 0 && *result / a != b);
}

// Only temporarily here until this is integrated into lodepng.c(pp)
#ifdef LODEPNG_COMPILE_ALLOCATORS
/** Instrumented function lodepng_malloc(size_t) */
static void* lodepng_malloc(size_t size) /* << Aka begin of function void * lodepng_malloc(size_t size) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_malloc(size_t)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.lodepng_malloc.9644.stub"

  AKA_mark("lis===266###sois===9679###eois===9699###lif===1###soif===46###eoif===66###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_malloc(size_t)");return malloc(size);
}
/** Instrumented function lodepng_free(void*) */
static void lodepng_free(void* ptr) /* << Aka begin of function void lodepng_free(void* ptr) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_free(void*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.lodepng_free.9716.stub"

  AKA_mark("lis===269###sois===9745###eois===9755###lif===1###soif===41###eoif===51###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_free(void*)");free(ptr);
}
#else /*LODEPNG_COMPILE_ALLOCATORS*/
void* lodepng_malloc(size_t size);
void lodepng_free(void* ptr);
#endif /*LODEPNG_COMPILE_ALLOCATORS*/

/* define infinity and NaN in a way compatible with ANSI C90 (no INFINITY or NAN macros) yet also with visual studio */
/* visual studio doesn't allow division through a zero literal, but allows it through public non-const variable set to zero */
float lodepng_flt_zero_ = 0.0f;
static const float lodepng_flt_inf = 1.0f / lodepng_flt_zero_; /* infinity */
static const float lodepng_flt_nan = 0.0f / lodepng_flt_zero_; /* not a number */
static const float lodepng_flt_max = 3.40282346638528859811704183484516925e38f; /* avoid needing <float.h> for FLT_MAX. This assumes IEEE 32-bit float. */

/* powf polyfill, 5-6 digits accurate, 33-80% slower than powf, assumes IEEE
32-bit float, but other than that multiplatform and no math lib needed
(note: powf also isn't in ISO C90, and pow is slower). */
/** Instrumented function lodepng_powf(float,float) */
static float lodepng_powf(float x, float y) /* << Aka begin of function float lodepng_powf(float x, float y) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.lodepng_powf.10730.stub"

  AKA_mark("lis===287###sois===10766###eois===10785###lif===1###soif===49###eoif===68###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");float j, t0, t1, l;
  AKA_mark("lis===288###sois===10789###eois===10799###lif===2###soif===72###eoif===82###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");int i = 0;
  /* handle all the special floating point rules */
  if(AKA_mark("lis===290###sois===10859###eois===10875###lif===4###soif===142###eoif===158###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && ((AKA_mark("lis===290###sois===10859###eois===10865###lif===4###soif===142###eoif===148###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (x == 1)) || (AKA_mark("lis===290###sois===10869###eois===10875###lif===4###soif===152###eoif===158###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (y == 0)))) {
AKA_mark("lis===290###sois===10877###eois===10886###lif===4###soif===160###eoif===169###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");return 1;
}

else {
AKA_mark("lis===-290-###sois===-10859-###eois===-1085916-###lif===-4-###soif===-###eoif===-158-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");
} /*these cases return 1 even if the other value is NaN, as specified*/
  if(AKA_mark("lis===291###sois===10963###eois===10969###lif===5###soif===246###eoif===252###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===291###sois===10963###eois===10969###lif===5###soif===246###eoif===252###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (y == 1))) {
AKA_mark("lis===291###sois===10971###eois===10980###lif===5###soif===254###eoif===263###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");return x;
}

else {
AKA_mark("lis===-291-###sois===-10963-###eois===-109636-###lif===-5-###soif===-###eoif===-252-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");
} /* preserves negative-0 */
  if(AKA_mark("lis===292###sois===11014###eois===11095###lif===6###soif===297###eoif===378###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===292###sois===11014###eois===11095###lif===6###soif===297###eoif===378###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (!(x > 0 && x <= lodepng_flt_max && y >= -lodepng_flt_max && y <= lodepng_flt_max)))) { /*all special cases*/
    if(AKA_mark("lis===293###sois===11129###eois===11145###lif===7###soif===412###eoif===428###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && ((AKA_mark("lis===293###sois===11129###eois===11135###lif===7###soif===412###eoif===418###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (x != x)) || (AKA_mark("lis===293###sois===11139###eois===11145###lif===7###soif===422###eoif===428###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (y != y)))) {
AKA_mark("lis===293###sois===11147###eois===11160###lif===7###soif===430###eoif===443###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");return x + y;
}

else {
AKA_mark("lis===-293-###sois===-11129-###eois===-1112916-###lif===-7-###soif===-###eoif===-428-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");
} /* nan */
    if(AKA_mark("lis===294###sois===11179###eois===11184###lif===8###soif===462###eoif===467###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===294###sois===11179###eois===11184###lif===8###soif===462###eoif===467###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (x > 0))) {
      if(AKA_mark("lis===295###sois===11198###eois===11217###lif===9###soif===481###eoif===500###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===295###sois===11198###eois===11217###lif===9###soif===481###eoif===500###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (x > lodepng_flt_max))) {
AKA_mark("lis===295###sois===11219###eois===11256###lif===9###soif===502###eoif===539###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");return y <= 0 ? (y == 0 ? 1 : 0) : x;
}

else {
AKA_mark("lis===-295-###sois===-11198-###eois===-1119819-###lif===-9-###soif===-###eoif===-500-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");
} /* x = +infinity */
    } else {
      if(AKA_mark("lis===297###sois===11301###eois===11343###lif===11###soif===584###eoif===626###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===297###sois===11301###eois===11343###lif===11###soif===584###eoif===626###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (!(y < -1073741824.0f || y > 1073741824.0f)))) { /* large y always even integer, but cast would overflow */
        AKA_mark("lis===298###sois===11415###eois===11426###lif===12###soif===698###eoif===709###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");i = (int)y; /* not using floor: not using math lib */
        if(AKA_mark("lis===299###sois===11481###eois===11487###lif===13###soif===764###eoif===770###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===299###sois===11481###eois===11487###lif===13###soif===764###eoif===770###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (i != y))) {
          AKA_mark("lis===300###sois===11502###eois===11640###lif===14###soif===785###eoif===923###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");return (x < -lodepng_flt_max) ? (y < 0 ? 0 : lodepng_flt_inf) :
              (x == 0 ? (y < 0 ? lodepng_flt_inf : 0) : lodepng_flt_nan);
        }
else {
AKA_mark("lis===-299-###sois===-11481-###eois===-114816-###lif===-13-###soif===-###eoif===-770-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");
}
        if(AKA_mark("lis===303###sois===11664###eois===11669###lif===17###soif===947###eoif===952###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===303###sois===11664###eois===11669###lif===17###soif===947###eoif===952###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (i & 1))) {
AKA_mark("lis===303###sois===11671###eois===11732###lif===17###soif===954###eoif===1015###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");return x == 0 ? (y < 0 ? (1 / x) : x) : -lodepng_powf(-x, y);
}

else {
AKA_mark("lis===-303-###sois===-11664-###eois===-116645-###lif===-17-###soif===-###eoif===-952-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");
}
      }
else {
AKA_mark("lis===-297-###sois===-11301-###eois===-1130142-###lif===-11-###soif===-###eoif===-626-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");
}
      if(AKA_mark("lis===305###sois===11752###eois===11758###lif===19###soif===1035###eoif===1041###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===305###sois===11752###eois===11758###lif===19###soif===1035###eoif===1041###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (x == 0))) {
AKA_mark("lis===305###sois===11760###eois===11796###lif===19###soif===1043###eoif===1079###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");return y <= 0 ? lodepng_flt_inf : 0;
}

else {
AKA_mark("lis===-305-###sois===-11752-###eois===-117526-###lif===-19-###soif===-###eoif===-1041-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");
}
      if(AKA_mark("lis===306###sois===11807###eois===11827###lif===20###soif===1090###eoif===1110###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===306###sois===11807###eois===11827###lif===20###soif===1090###eoif===1110###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (x < -lodepng_flt_max))) { /* x == -infinity */
        AKA_mark("lis===307###sois===11861###eois===11956###lif===21###soif===1144###eoif===1239###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");return y <= 0 ? (y == 0 ? 1 : 0) : ((i & 1) ?
            -lodepng_flt_inf : lodepng_flt_inf);
      }
else {
AKA_mark("lis===-306-###sois===-11807-###eois===-1180720-###lif===-20-###soif===-###eoif===-1110-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");
}
      AKA_mark("lis===310###sois===11973###eois===11980###lif===24###soif===1256###eoif===1263###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");x = -x;
      if(AKA_mark("lis===311###sois===11991###eois===11997###lif===25###soif===1274###eoif===1280###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===311###sois===11991###eois===11997###lif===25###soif===1274###eoif===1280###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (x == 1))) {
AKA_mark("lis===311###sois===11999###eois===12008###lif===25###soif===1282###eoif===1291###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");return 1;
}

else {
AKA_mark("lis===-311-###sois===-11991-###eois===-119916-###lif===-25-###soif===-###eoif===-1280-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");
} /* under the C++ rules, pow(-1, +/- infinity) also returns 1 */
    }
    if(AKA_mark("lis===313###sois===12088###eois===12131###lif===27###soif===1371###eoif===1414###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && ((AKA_mark("lis===313###sois===12088###eois===12108###lif===27###soif===1371###eoif===1391###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (y < -lodepng_flt_max)) || (AKA_mark("lis===313###sois===12112###eois===12131###lif===27###soif===1395###eoif===1414###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (y > lodepng_flt_max)))) {
AKA_mark("lis===313###sois===12133###eois===12184###lif===27###soif===1416###eoif===1467###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");return ((x < 1) != (y > 0)) ? (y < 0 ? -y : y) : 0;
}

else {
AKA_mark("lis===-313-###sois===-12088-###eois===-1208843-###lif===-27-###soif===-###eoif===-1414-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");
}
  }
else {
AKA_mark("lis===-292-###sois===-11014-###eois===-1101481-###lif===-6-###soif===-###eoif===-378-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");
}

  AKA_mark("lis===316###sois===12195###eois===12201###lif===30###soif===1478###eoif===1484###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");l = x;
  AKA_mark("lis===317###sois===12205###eois===12211###lif===31###soif===1488###eoif===1494###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");j = 0;
  int AKA_BLOCK_LOOP_12215 = 0;
    while(AKA_mark("lis===318###sois===12221###eois===12239###lif===32###soif===1504###eoif===1522###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===318###sois===12221###eois===12239###lif===32###soif===1504###eoif===1522###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (l < (1.0f / 65536)))) {
        AKA_BLOCK_LOOP_12215++;
        if (AKA_BLOCK_LOOP_12215 > 1000) {
            //break;
        } AKA_mark("lis===318###sois===12243###eois===12251###lif===32###soif===1526###eoif===1534###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");j -= 16; AKA_mark("lis===318###sois===12252###eois===12266###lif===32###soif===1535###eoif===1549###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");l *= 65536.0f; }
  int AKA_BLOCK_LOOP_12272 = 0;
    while(AKA_mark("lis===319###sois===12278###eois===12287###lif===33###soif===1561###eoif===1570###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===319###sois===12278###eois===12287###lif===33###soif===1561###eoif===1570###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (l > 65536))) {
        AKA_BLOCK_LOOP_12272++;
        if (AKA_BLOCK_LOOP_12272 > 1000) {
            //break;
        } AKA_mark("lis===319###sois===12291###eois===12299###lif===33###soif===1574###eoif===1582###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");j += 16; AKA_mark("lis===319###sois===12300###eois===12320###lif===33###soif===1583###eoif===1603###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");l *= (1.0f / 65536); }
  int AKA_BLOCK_LOOP_12326 = 0;
    while(AKA_mark("lis===320###sois===12332###eois===12337###lif===34###soif===1615###eoif===1620###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===320###sois===12332###eois===12337###lif===34###soif===1615###eoif===1620###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (l < 1))) {
        AKA_BLOCK_LOOP_12326++;
        if (AKA_BLOCK_LOOP_12326 > 1000) {
            //break;
        } AKA_mark("lis===320###sois===12341###eois===12345###lif===34###soif===1624###eoif===1628###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");j--; AKA_mark("lis===320###sois===12346###eois===12356###lif===34###soif===1629###eoif===1639###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");l *= 2.0f; }
  int AKA_BLOCK_LOOP_12362 = 0;
    while(AKA_mark("lis===321###sois===12368###eois===12373###lif===35###soif===1651###eoif===1656###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===321###sois===12368###eois===12373###lif===35###soif===1651###eoif===1656###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (l > 2))) {
        AKA_BLOCK_LOOP_12362++;
        if (AKA_BLOCK_LOOP_12362 > 1000) {
            //break;
        } AKA_mark("lis===321###sois===12377###eois===12381###lif===35###soif===1660###eoif===1664###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");j++; AKA_mark("lis===321###sois===12382###eois===12392###lif===35###soif===1665###eoif===1675###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");l *= 0.5f; }
  /* polynomial to approximate log2(x) with x in range 1..2 */
  AKA_mark("lis===323###sois===12462###eois===12569###lif===37###soif===1745###eoif===1852###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");t0 = -0.393118410458557f + l * (-0.0883639468229365f + l * (0.466142650227994f + l * 0.0153397331014276f));
  AKA_mark("lis===324###sois===12573###eois===12650###lif===38###soif===1856###eoif===1933###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");t1 = 0.0907447971403586f + l * (0.388892024755479f + l * 0.137228280305862f);
  AKA_mark("lis===325###sois===12654###eois===12670###lif===39###soif===1937###eoif===1953###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");l = t0 / t1 + j;

  AKA_mark("lis===327###sois===12676###eois===12683###lif===41###soif===1959###eoif===1966###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");l *= y; /* using the formula exp2(y * log2(x)) */

  /* prevent int shift overflow, 0 or inf result are ok to return since exp will be taken, 127 is max float exponent */
  if(AKA_mark("lis===330###sois===12855###eois===12882###lif===44###soif===2138###eoif===2165###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && ((AKA_mark("lis===330###sois===12855###eois===12867###lif===44###soif===2138###eoif===2150###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (l <= -128.0f)) || (AKA_mark("lis===330###sois===12871###eois===12882###lif===44###soif===2154###eoif===2165###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (l >= 128.0f)))) {
AKA_mark("lis===330###sois===12884###eois===12934###lif===44###soif===2167###eoif===2217###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");return ((x > 1) == (y > 0)) ? lodepng_flt_inf : 0;
}

else {
AKA_mark("lis===-330-###sois===-12855-###eois===-1285527-###lif===-44-###soif===-###eoif===-2165-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");
}
  AKA_mark("lis===331###sois===12938###eois===12949###lif===45###soif===2221###eoif===2232###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");i = (int)l;
  AKA_mark("lis===332###sois===12953###eois===12960###lif===46###soif===2236###eoif===2243###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");l -= i;
  /* polynomial to approximate exp2(x) with x in range -1..1 */
  AKA_mark("lis===334###sois===13029###eois===13124###lif===48###soif===2312###eoif===2407###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");t0 = 1.0f + l * (0.41777833582744256f + l * (0.0728482595347711f + l * 0.005635023478609625f));
  AKA_mark("lis===335###sois===13128###eois===13196###lif===49###soif===2411###eoif===2479###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");t1 = 1.0f + l * (-0.27537016151408167f + l * 0.023501446055084033f);
  int AKA_BLOCK_LOOP_13200 = 0;
    while(AKA_mark("lis===336###sois===13206###eois===13214###lif===50###soif===2489###eoif===2497###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===336###sois===13206###eois===13214###lif===50###soif===2489###eoif===2497###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (i <= -31))) {
        AKA_BLOCK_LOOP_13200++;
        if (AKA_BLOCK_LOOP_13200 > 1000) {
            //break;
        } AKA_mark("lis===336###sois===13218###eois===13247###lif===50###soif===2501###eoif===2530###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");t0 *= (1.0f / 2147483648.0f); AKA_mark("lis===336###sois===13248###eois===13256###lif===50###soif===2531###eoif===2539###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");i += 31; }
  int AKA_BLOCK_LOOP_13262 = 0;
    while(AKA_mark("lis===337###sois===13268###eois===13275###lif===51###soif===2551###eoif===2558###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (AKA_mark("lis===337###sois===13268###eois===13275###lif===51###soif===2551###eoif===2558###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)") && (i >= 31))) {
        AKA_BLOCK_LOOP_13262++;
        if (AKA_BLOCK_LOOP_13262 > 1000) {
            //break;
        } AKA_mark("lis===337###sois===13279###eois===13299###lif===51###soif===2562###eoif===2582###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");t0 *= 2147483648.0f; AKA_mark("lis===337###sois===13300###eois===13308###lif===51###soif===2583###eoif===2591###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");i -= 31; }
  AKA_mark("lis===338###sois===13314###eois===13380###lif===52###soif===2597###eoif===2663###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_powf(float,float)");return (i < 0) ? (t0 / (t1 * (1 << -i))) : ((t0 * (1 << i)) / t1);
}

/* Parameters of a tone reproduction curve, either with a power law formula or with a lookup table. */
typedef struct {
  unsigned type; /* 0=linear, 1=lut, 2 = simple gamma, 3-6 = parametric (matches ICC parametric types 1-4) */
  float* lut; /* for type 1 */
  size_t lut_size;
  float gamma; /* for type 2 and more */
  float a, b, c, d, e, f; /* parameters for type 3-6 */
} LodePNGICCCurve;

/** Instrumented function lodepng_icc_curve_init(LodePNGICCCurve*) */
void lodepng_icc_curve_init(LodePNGICCCurve* curve) /* << Aka begin of function void lodepng_icc_curve_init(LodePNGICCCurve* curve) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_icc_curve_init(LodePNGICCCurve*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.lodepng_icc_curve_init.13798.stub"

  AKA_mark("lis===351###sois===13850###eois===13865###lif===1###soif===57###eoif===72###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_icc_curve_init(LodePNGICCCurve*)");curve->lut = 0;
  AKA_mark("lis===352###sois===13869###eois===13889###lif===2###soif===76###eoif===96###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_icc_curve_init(LodePNGICCCurve*)");curve->lut_size = 0;
}

/** Instrumented function lodepng_icc_curve_cleanup(LodePNGICCCurve*) */
void lodepng_icc_curve_cleanup(LodePNGICCCurve* curve) /* << Aka begin of function void lodepng_icc_curve_cleanup(LodePNGICCCurve* curve) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_icc_curve_cleanup(LodePNGICCCurve*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.lodepng_icc_curve_cleanup.13901.stub"

  AKA_mark("lis===356###sois===13956###eois===13981###lif===1###soif===60###eoif===85###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_icc_curve_cleanup(LodePNGICCCurve*)");lodepng_free(curve->lut);
}

/* Values parsed from ICC profile, see parseICC for more information about this subset.*/
typedef struct {
  /* 0 = color model not supported by PNG (CMYK, Lab, ...), 1 = gray, 2 = RGB */
  int inputspace;
  int version_major;
  int version_minor;
  int version_bugfix;

  /* The whitepoint of the profile connection space (PCS). Should always be D50, but parsed and used anyway.
  (to be clear, whitepoint and illuminant are synonyms in practice, but here field "illuminant" is ICC's
  "global" whitepoint that is always D50, and the field "white" below allows deriving the whitepoint of
  the particular RGB space represented here) */
  float illuminant[3];

  /* if true, has chromatic adaptation matrix that must be used. If false, you must compute a chromatic adaptation
  matrix yourself from "illuminant" and "white". */
  unsigned has_chad;
  float chad[9]; /* chromatic adaptation matrix, if given */

  /* The whitepoint of the RGB color space as stored in the ICC file. If has_chad, must be adapted with the
  chad matrix to become the one we need to go to absolute XYZ (in fact ICC implies it should then be
  exactly D50 in the file, redundantly, before this transformation with chad), else use as-is (then its
  values can actually be something else than D50, and are the ones we need). */
  unsigned has_whitepoint;
  float white[3];
  /* Chromaticities of the RGB space in XYZ color space, but given such that you must still
  whitepoint adapt them from D50 to the RGB space whitepoint to go to absolute XYZ (if has_chad,
  with chad, else with bradford adaptation matrix from illuminant to white). */
  unsigned has_chromaticity;
  float red[3];
  float green[3];
  float blue[3];

  unsigned has_trc; /* TRC = tone reproduction curve (aka "gamma correction") */

  /* TRC's for the three channels (only first one used if grayscale) */
  LodePNGICCCurve trc[3];
} LodePNGICC;

/** Instrumented function lodepng_icc_init(LodePNGICC*) */
void lodepng_icc_init(LodePNGICC* icc) /* << Aka begin of function void lodepng_icc_init(LodePNGICC* icc) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_icc_init(LodePNGICC*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.lodepng_icc_init.15926.stub"

  AKA_mark("lis===399###sois===15965###eois===16002###lif===1###soif===44###eoif===81###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_icc_init(LodePNGICC*)");lodepng_icc_curve_init(&icc->trc[0]);
  AKA_mark("lis===400###sois===16006###eois===16043###lif===2###soif===85###eoif===122###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_icc_init(LodePNGICC*)");lodepng_icc_curve_init(&icc->trc[1]);
  AKA_mark("lis===401###sois===16047###eois===16084###lif===3###soif===126###eoif===163###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_icc_init(LodePNGICC*)");lodepng_icc_curve_init(&icc->trc[2]);
}

/** Instrumented function lodepng_icc_cleanup(LodePNGICC*) */
void lodepng_icc_cleanup(LodePNGICC* icc) /* << Aka begin of function void lodepng_icc_cleanup(LodePNGICC* icc) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_icc_cleanup(LodePNGICC*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.lodepng_icc_cleanup.16096.stub"

  AKA_mark("lis===405###sois===16138###eois===16178###lif===1###soif===47###eoif===87###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_icc_cleanup(LodePNGICC*)");lodepng_icc_curve_cleanup(&icc->trc[0]);
  AKA_mark("lis===406###sois===16182###eois===16222###lif===2###soif===91###eoif===131###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_icc_cleanup(LodePNGICC*)");lodepng_icc_curve_cleanup(&icc->trc[1]);
  AKA_mark("lis===407###sois===16226###eois===16266###lif===3###soif===135###eoif===175###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\lodepng_icc_cleanup(LodePNGICC*)");lodepng_icc_curve_cleanup(&icc->trc[2]);
}

/* ICC tone response curve, nonlinear (encoded) to linear.
Input and output in range 0-1. If color was integer 0-255, multiply with (1.0f/255)
to get the correct floating point behavior.
Outside of range 0-1, will not clip but either return x itself, or in cases
where it makes sense, a value defined by the same function.
NOTE: ICC requires clipping, but we do that only later when converting float to integer.*/
/** Instrumented function iccForwardTRC(LodePNGICCCurve const*,float) */
static float iccForwardTRC(const LodePNGICCCurve* curve, float x) /* << Aka begin of function float iccForwardTRC(const LodePNGICCCurve* curve, float x) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.iccForwardTRC.16706.stub"

  if(AKA_mark("lis===417###sois===16767###eois===16783###lif===1###soif===74###eoif===90###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===417###sois===16767###eois===16783###lif===1###soif===74###eoif===90###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 0))) {
    AKA_mark("lis===418###sois===16792###eois===16801###lif===2###soif===99###eoif===108###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");return x;
  }
else {
AKA_mark("lis===-417-###sois===-16767-###eois===-1676716-###lif===-1-###soif===-###eoif===-90-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");
}
  if(AKA_mark("lis===420###sois===16813###eois===16829###lif===4###soif===120###eoif===136###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===420###sois===16813###eois===16829###lif===4###soif===120###eoif===136###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 1))) { /* Lookup table */
    AKA_mark("lis===421###sois===16857###eois===16880###lif===5###soif===164###eoif===187###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");float v0, v1, fraction;
    AKA_mark("lis===422###sois===16886###eois===16899###lif===6###soif===193###eoif===206###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");size_t index;
    if(AKA_mark("lis===423###sois===16908###eois===16919###lif===7###soif===215###eoif===226###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===423###sois===16908###eois===16919###lif===7###soif===215###eoif===226###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (!curve->lut))) {
AKA_mark("lis===423###sois===16921###eois===16930###lif===7###soif===228###eoif===237###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");return 0;
}

else {
AKA_mark("lis===-423-###sois===-16908-###eois===-1690811-###lif===-7-###soif===-###eoif===-226-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");
} /* error */
    if(AKA_mark("lis===424###sois===16951###eois===16956###lif===8###soif===258###eoif===263###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===424###sois===16951###eois===16956###lif===8###soif===258###eoif===263###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (x < 0))) {
AKA_mark("lis===424###sois===16958###eois===16967###lif===8###soif===265###eoif===274###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");return x;
}

else {
AKA_mark("lis===-424-###sois===-16951-###eois===-169515-###lif===-8-###soif===-###eoif===-263-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");
}
    AKA_mark("lis===425###sois===16973###eois===17017###lif===9###soif===280###eoif===324###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");index = (size_t)(x * (curve->lut_size - 1));
    if(AKA_mark("lis===426###sois===17026###eois===17050###lif===10###soif===333###eoif===357###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===426###sois===17026###eois===17050###lif===10###soif===333###eoif===357###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (index >= curve->lut_size))) {
AKA_mark("lis===426###sois===17052###eois===17061###lif===10###soif===359###eoif===368###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");return x;
}

else {
AKA_mark("lis===-426-###sois===-17026-###eois===-1702624-###lif===-10-###soif===-###eoif===-357-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");
}

    /* LERP */
    AKA_mark("lis===429###sois===17085###eois===17108###lif===13###soif===392###eoif===415###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");v0 = curve->lut[index];
    AKA_mark("lis===430###sois===17114###eois===17180###lif===14###soif===421###eoif===487###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");v1 = (index + 1 < curve->lut_size) ? curve->lut[index + 1] : 1.0f;
    AKA_mark("lis===431###sois===17186###eois===17233###lif===15###soif===493###eoif===540###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");fraction = (x * (curve->lut_size - 1)) - index;
    AKA_mark("lis===432###sois===17239###eois===17282###lif===16###soif===546###eoif===589###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");return v0 * (1 - fraction) + v1 * fraction;
  }
else {
AKA_mark("lis===-420-###sois===-16813-###eois===-1681316-###lif===-4-###soif===-###eoif===-136-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");
}
  if(AKA_mark("lis===434###sois===17294###eois===17310###lif===18###soif===601###eoif===617###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===434###sois===17294###eois===17310###lif===18###soif===601###eoif===617###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 2))) {
    /* Gamma expansion */
    AKA_mark("lis===436###sois===17346###eois===17397###lif===20###soif===653###eoif===704###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");return (x > 0) ? lodepng_powf(x, curve->gamma) : x;
  }
else {
AKA_mark("lis===-434-###sois===-17294-###eois===-1729416-###lif===-18-###soif===-###eoif===-617-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");
}
  /* TODO: all the ones below are untested */
  if(AKA_mark("lis===439###sois===17456###eois===17472###lif===23###soif===763###eoif===779###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===439###sois===17456###eois===17472###lif===23###soif===763###eoif===779###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 3))) {
    if(AKA_mark("lis===440###sois===17484###eois===17489###lif===24###soif===791###eoif===796###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===440###sois===17484###eois===17489###lif===24###soif===791###eoif===796###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (x < 0))) {
AKA_mark("lis===440###sois===17491###eois===17500###lif===24###soif===798###eoif===807###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");return x;
}

else {
AKA_mark("lis===-440-###sois===-17484-###eois===-174845-###lif===-24-###soif===-###eoif===-796-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");
}
    AKA_mark("lis===441###sois===17506###eois===17612###lif===25###soif===813###eoif===919###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");return x >= (-curve->b / curve->a) ? (lodepng_powf(curve->a * x + curve->b, curve->gamma) + curve->c) : 0;
  }
else {
AKA_mark("lis===-439-###sois===-17456-###eois===-1745616-###lif===-23-###soif===-###eoif===-779-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");
}
  if(AKA_mark("lis===443###sois===17624###eois===17640###lif===27###soif===931###eoif===947###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===443###sois===17624###eois===17640###lif===27###soif===931###eoif===947###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 4))) {
    if(AKA_mark("lis===444###sois===17652###eois===17657###lif===28###soif===959###eoif===964###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===444###sois===17652###eois===17657###lif===28###soif===959###eoif===964###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (x < 0))) {
AKA_mark("lis===444###sois===17659###eois===17668###lif===28###soif===966###eoif===975###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");return x;
}

else {
AKA_mark("lis===-444-###sois===-17652-###eois===-176525-###lif===-28-###soif===-###eoif===-964-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");
}
    AKA_mark("lis===445###sois===17674###eois===17787###lif===29###soif===981###eoif===1094###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");return x >= (-curve->b / curve->a) ? (lodepng_powf(curve->a * x + curve->b, curve->gamma) + curve->c) : curve->c;
  }
else {
AKA_mark("lis===-443-###sois===-17624-###eois===-1762416-###lif===-27-###soif===-###eoif===-947-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");
}
  if(AKA_mark("lis===447###sois===17799###eois===17815###lif===31###soif===1106###eoif===1122###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===447###sois===17799###eois===17815###lif===31###soif===1106###eoif===1122###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 5))) {
    AKA_mark("lis===448###sois===17824###eois===17918###lif===32###soif===1131###eoif===1225###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");return x >= curve->d ? (lodepng_powf(curve->a * x + curve->b, curve->gamma)) : (curve->c * x);
  }
else {
AKA_mark("lis===-447-###sois===-17799-###eois===-1779916-###lif===-31-###soif===-###eoif===-1122-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");
}
  if(AKA_mark("lis===450###sois===17930###eois===17946###lif===34###soif===1237###eoif===1253###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===450###sois===17930###eois===17946###lif===34###soif===1237###eoif===1253###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 6))) {
    AKA_mark("lis===451###sois===17955###eois===18071###lif===35###soif===1262###eoif===1378###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");return x >= curve->d ? (lodepng_powf(curve->a * x + curve->b, curve->gamma) + curve->c) : (curve->c * x + curve->f);
  }
else {
AKA_mark("lis===-450-###sois===-17930-###eois===-1793016-###lif===-34-###soif===-###eoif===-1253-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");
}
  AKA_mark("lis===453###sois===18080###eois===18089###lif===37###soif===1387###eoif===1396###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccForwardTRC(LodePNGICCCurve const*,float)");return 0;
}

/* ICC tone response curve, linear to nonlinear (encoded).
Input and output in range 0-1. Outside of that range, will not clip but either
return x itself, or in cases where it makes sense, a value defined by the same function.
NOTE: ICC requires clipping, but we do that only later when converting float to integer.*/
/** Instrumented function iccBackwardTRC(LodePNGICCCurve const*,float) */
static float iccBackwardTRC(const LodePNGICCCurve* curve, float x) /* << Aka begin of function float iccBackwardTRC(const LodePNGICCCurve* curve, float x) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.iccBackwardTRC.18431.stub"

  if(AKA_mark("lis===461###sois===18493###eois===18509###lif===1###soif===75###eoif===91###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===461###sois===18493###eois===18509###lif===1###soif===75###eoif===91###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 0))) {
    AKA_mark("lis===462###sois===18518###eois===18527###lif===2###soif===100###eoif===109###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return x;
  }
else {
AKA_mark("lis===-461-###sois===-18493-###eois===-1849316-###lif===-1-###soif===-###eoif===-91-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
  if(AKA_mark("lis===464###sois===18539###eois===18555###lif===4###soif===121###eoif===137###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===464###sois===18539###eois===18555###lif===4###soif===121###eoif===137###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 1))) {
    AKA_mark("lis===465###sois===18564###eois===18579###lif===5###soif===146###eoif===161###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");size_t a, b, m;
    AKA_mark("lis===466###sois===18585###eois===18593###lif===6###soif===167###eoif===175###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");float v;
    if(AKA_mark("lis===467###sois===18602###eois===18608###lif===7###soif===184###eoif===190###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===467###sois===18602###eois===18608###lif===7###soif===184###eoif===190###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (x <= 0))) {
AKA_mark("lis===467###sois===18610###eois===18619###lif===7###soif===192###eoif===201###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return x;
}

else {
AKA_mark("lis===-467-###sois===-18602-###eois===-186026-###lif===-7-###soif===-###eoif===-190-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
    if(AKA_mark("lis===468###sois===18628###eois===18634###lif===8###soif===210###eoif===216###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===468###sois===18628###eois===18634###lif===8###soif===210###eoif===216###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (x >= 1))) {
AKA_mark("lis===468###sois===18636###eois===18645###lif===8###soif===218###eoif===227###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return x;
}

else {
AKA_mark("lis===-468-###sois===-18628-###eois===-186286-###lif===-8-###soif===-###eoif===-216-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
    /* binary search in the table */
    /* TODO: use faster way of inverting the lookup table */
    AKA_mark("lis===471###sois===18751###eois===18757###lif===11###soif===333###eoif===339###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");a = 0;
    AKA_mark("lis===472###sois===18763###eois===18783###lif===12###soif===345###eoif===365###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");b = curve->lut_size;
    int AKA_BLOCK_LOOP_18789 = 0;
    for(;;) {
        AKA_BLOCK_LOOP_18789++;
        if (AKA_BLOCK_LOOP_18789 > 1000) {
            //break;
        }
      if(AKA_mark("lis===474###sois===18809###eois===18815###lif===14###soif===391###eoif===397###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===474###sois===18809###eois===18815###lif===14###soif===391###eoif===397###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (a == b))) {
AKA_mark("lis===474###sois===18817###eois===18838###lif===14###soif===399###eoif===420###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return curve->lut[a];
}

else {
AKA_mark("lis===-474-###sois===-18809-###eois===-188096-###lif===-14-###soif===-###eoif===-397-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
      if(AKA_mark("lis===475###sois===18849###eois===18859###lif===15###soif===431###eoif===441###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===475###sois===18849###eois===18859###lif===15###soif===431###eoif===441###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (a + 1 == b))) {
        /* LERP */
        AKA_mark("lis===477###sois===18892###eois===18917###lif===17###soif===474###eoif===499###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");float v0 = curve->lut[a];
        AKA_mark("lis===478###sois===18927###eois===18952###lif===18###soif===509###eoif===534###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");float v1 = curve->lut[b];
        AKA_mark("lis===479###sois===18962###eois===18977###lif===19###soif===544###eoif===559###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");float fraction;
        if(AKA_mark("lis===480###sois===18990###eois===18998###lif===20###soif===572###eoif===580###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===480###sois===18990###eois===18998###lif===20###soif===572###eoif===580###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (v0 == v1))) {
AKA_mark("lis===480###sois===19000###eois===19010###lif===20###soif===582###eoif===592###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return v0;
}

else {
AKA_mark("lis===-480-###sois===-18990-###eois===-189908-###lif===-20-###soif===-###eoif===-580-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
        AKA_mark("lis===481###sois===19020###eois===19052###lif===21###soif===602###eoif===634###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");fraction = (x - v0) / (v1 - v0);
        AKA_mark("lis===482###sois===19062###eois===19105###lif===22###soif===644###eoif===687###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return v0 * (1 - fraction) + v1 * fraction;
      }
else {
AKA_mark("lis===-475-###sois===-18849-###eois===-1884910-###lif===-15-###soif===-###eoif===-441-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
      AKA_mark("lis===484###sois===19122###eois===19139###lif===24###soif===704###eoif===721###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");m = (a + b) / 2u;
      AKA_mark("lis===485###sois===19147###eois===19165###lif===25###soif===729###eoif===747###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");v = curve->lut[m];
      if(AKA_mark("lis===486###sois===19176###eois===19181###lif===26###soif===758###eoif===763###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===486###sois===19176###eois===19181###lif===26###soif===758###eoif===763###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (v > x))) {
        AKA_mark("lis===487###sois===19194###eois===19200###lif===27###soif===776###eoif===782###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");b = m;
      } else {
        AKA_mark("lis===489###sois===19226###eois===19232###lif===29###soif===808###eoif===814###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");a = m;
      }
    }
  }
else {
AKA_mark("lis===-464-###sois===-18539-###eois===-1853916-###lif===-4-###soif===-###eoif===-137-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
  if(AKA_mark("lis===493###sois===19260###eois===19276###lif===33###soif===842###eoif===858###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===493###sois===19260###eois===19276###lif===33###soif===842###eoif===858###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 2))) {
    /* Gamma compression */
    AKA_mark("lis===495###sois===19314###eois===19372###lif===35###soif===896###eoif===954###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return (x > 0) ? lodepng_powf(x, 1.0f / curve->gamma) : x;
  }
else {
AKA_mark("lis===-493-###sois===-19260-###eois===-1926016-###lif===-33-###soif===-###eoif===-858-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
  /* TODO: all the ones below are untested  */
  if(AKA_mark("lis===498###sois===19432###eois===19448###lif===38###soif===1014###eoif===1030###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===498###sois===19432###eois===19448###lif===38###soif===1014###eoif===1030###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 3))) {
    if(AKA_mark("lis===499###sois===19460###eois===19465###lif===39###soif===1042###eoif===1047###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===499###sois===19460###eois===19465###lif===39###soif===1042###eoif===1047###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (x < 0))) {
AKA_mark("lis===499###sois===19467###eois===19476###lif===39###soif===1049###eoif===1058###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return x;
}

else {
AKA_mark("lis===-499-###sois===-19460-###eois===-194605-###lif===-39-###soif===-###eoif===-1047-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
    AKA_mark("lis===500###sois===19482###eois===19585###lif===40###soif===1064###eoif===1167###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return x > 0 ? ((lodepng_powf(x, 1.0f / curve->gamma) - curve->b) / curve->a) : (-curve->b / curve->a);
  }
else {
AKA_mark("lis===-498-###sois===-19432-###eois===-1943216-###lif===-38-###soif===-###eoif===-1030-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
  if(AKA_mark("lis===502###sois===19597###eois===19613###lif===42###soif===1179###eoif===1195###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===502###sois===19597###eois===19613###lif===42###soif===1179###eoif===1195###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 4))) {
    if(AKA_mark("lis===503###sois===19625###eois===19630###lif===43###soif===1207###eoif===1212###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===503###sois===19625###eois===19630###lif===43###soif===1207###eoif===1212###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (x < 0))) {
AKA_mark("lis===503###sois===19632###eois===19641###lif===43###soif===1214###eoif===1223###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return x;
}

else {
AKA_mark("lis===-503-###sois===-19625-###eois===-196255-###lif===-43-###soif===-###eoif===-1212-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
    AKA_mark("lis===504###sois===19647###eois===19786###lif===44###soif===1229###eoif===1368###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return x > curve->c ?
        ((lodepng_powf(x - curve->c, 1.0f / curve->gamma) - curve->b) / curve->a) :
        (-curve->b / curve->a);
  }
else {
AKA_mark("lis===-502-###sois===-19597-###eois===-1959716-###lif===-42-###soif===-###eoif===-1195-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
  if(AKA_mark("lis===508###sois===19798###eois===19814###lif===48###soif===1380###eoif===1396###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===508###sois===19798###eois===19814###lif===48###soif===1380###eoif===1396###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 5))) {
    AKA_mark("lis===509###sois===19823###eois===19956###lif===49###soif===1405###eoif===1538###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return x > (curve->c * curve->d) ?
        ((lodepng_powf(x, 1.0f / curve->gamma) - curve->b) / curve->a) :
        (x / curve->c);
  }
else {
AKA_mark("lis===-508-###sois===-19798-###eois===-1979816-###lif===-48-###soif===-###eoif===-1396-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
  if(AKA_mark("lis===513###sois===19968###eois===19984###lif===53###soif===1550###eoif===1566###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (AKA_mark("lis===513###sois===19968###eois===19984###lif===53###soif===1550###eoif===1566###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)") && (curve->type == 6))) {
    AKA_mark("lis===514###sois===19993###eois===20161###lif===54###soif===1575###eoif===1743###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return x > (curve->c * curve->d + curve->f) ?
        ((lodepng_powf(x - curve->c, 1.0f / curve->gamma) - curve->b) / curve->a) :
        ((x - curve->f) / curve->c);
  }
else {
AKA_mark("lis===-513-###sois===-19968-###eois===-1996816-###lif===-53-###soif===-###eoif===-1566-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");
}
  AKA_mark("lis===518###sois===20170###eois===20179###lif===58###soif===1752###eoif===1761###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\iccBackwardTRC(LodePNGICCCurve const*,float)");return 0;
}

/** Instrumented function decodeICCUint16(unsigned char const*,size_t,size_t*) */
static unsigned decodeICCUint16(const unsigned char* data, size_t size, size_t* pos) /* << Aka begin of function unsigned decodeICCUint16(const unsigned char* data, size_t size, size_t* pos) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint16(unsigned char const*,size_t,size_t*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.decodeICCUint16.20202.stub"

  AKA_mark("lis===522###sois===20276###eois===20286###lif===1###soif===90###eoif===100###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint16(unsigned char const*,size_t,size_t*)");*pos += 2;
  if (AKA_mark("lis===523###sois===20294###eois===20305###lif===2###soif===108###eoif===119###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint16(unsigned char const*,size_t,size_t*)") && (AKA_mark("lis===523###sois===20294###eois===20305###lif===2###soif===108###eoif===119###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint16(unsigned char const*,size_t,size_t*)") && (*pos > size))) {
AKA_mark("lis===523###sois===20307###eois===20316###lif===2###soif===121###eoif===130###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint16(unsigned char const*,size_t,size_t*)");return 0;
}

else {
AKA_mark("lis===-523-###sois===-20294-###eois===-2029411-###lif===-2-###soif===-###eoif===-119-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint16(unsigned char const*,size_t,size_t*)");
}
  AKA_mark("lis===524###sois===20320###eois===20380###lif===3###soif===134###eoif===194###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint16(unsigned char const*,size_t,size_t*)");return (unsigned)((data[*pos - 2] << 8) | (data[*pos - 1]));
}

/** Instrumented function decodeICCUint32(unsigned char const*,size_t,size_t*) */
static unsigned decodeICCUint32(const unsigned char* data, size_t size, size_t* pos) /* << Aka begin of function unsigned decodeICCUint32(const unsigned char* data, size_t size, size_t* pos) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint32(unsigned char const*,size_t,size_t*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.decodeICCUint32.20403.stub"

  AKA_mark("lis===528###sois===20477###eois===20487###lif===1###soif===90###eoif===100###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint32(unsigned char const*,size_t,size_t*)");*pos += 4;
  if (AKA_mark("lis===529###sois===20495###eois===20506###lif===2###soif===108###eoif===119###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint32(unsigned char const*,size_t,size_t*)") && (AKA_mark("lis===529###sois===20495###eois===20506###lif===2###soif===108###eoif===119###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint32(unsigned char const*,size_t,size_t*)") && (*pos > size))) {
AKA_mark("lis===529###sois===20508###eois===20517###lif===2###soif===121###eoif===130###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint32(unsigned char const*,size_t,size_t*)");return 0;
}

else {
AKA_mark("lis===-529-###sois===-20495-###eois===-2049511-###lif===-2-###soif===-###eoif===-119-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint32(unsigned char const*,size_t,size_t*)");
}
  AKA_mark("lis===530###sois===20521###eois===20636###lif===3###soif===134###eoif===249###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCUint32(unsigned char const*,size_t,size_t*)");return (unsigned)((data[*pos - 4] << 24) | (data[*pos - 3] << 16) | (data[*pos - 2] << 8) | (data[*pos - 1] << 0));
}

/** Instrumented function decodeICCInt32(unsigned char const*,size_t,size_t*) */
static int decodeICCInt32(const unsigned char* data, size_t size, size_t* pos) /* << Aka begin of function int decodeICCInt32(const unsigned char* data, size_t size, size_t* pos) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCInt32(unsigned char const*,size_t,size_t*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.decodeICCInt32.20654.stub"

  AKA_mark("lis===534###sois===20727###eois===20737###lif===1###soif===84###eoif===94###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCInt32(unsigned char const*,size_t,size_t*)");*pos += 4;
  if (AKA_mark("lis===535###sois===20745###eois===20756###lif===2###soif===102###eoif===113###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCInt32(unsigned char const*,size_t,size_t*)") && (AKA_mark("lis===535###sois===20745###eois===20756###lif===2###soif===102###eoif===113###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCInt32(unsigned char const*,size_t,size_t*)") && (*pos > size))) {
AKA_mark("lis===535###sois===20758###eois===20767###lif===2###soif===115###eoif===124###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCInt32(unsigned char const*,size_t,size_t*)");return 0;
}

else {
AKA_mark("lis===-535-###sois===-20745-###eois===-2074511-###lif===-2-###soif===-###eoif===-113-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCInt32(unsigned char const*,size_t,size_t*)");
}
  /*TODO: this is incorrect if sizeof(int) != 4*/
  AKA_mark("lis===537###sois===20822###eois===20925###lif===4###soif===179###eoif===282###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICCInt32(unsigned char const*,size_t,size_t*)");return (data[*pos - 4] << 24) | (data[*pos - 3] << 16) | (data[*pos - 2] << 8) | (data[*pos - 1] << 0);
}

/** Instrumented function decodeICC15Fixed16(unsigned char const*,size_t,size_t*) */
static float decodeICC15Fixed16(const unsigned char* data, size_t size, size_t* pos) /* << Aka begin of function float decodeICC15Fixed16(const unsigned char* data, size_t size, size_t* pos) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICC15Fixed16(unsigned char const*,size_t,size_t*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.decodeICC15Fixed16.20945.stub"

  AKA_mark("lis===541###sois===21022###eois===21072###lif===1###soif===90###eoif===140###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\decodeICC15Fixed16(unsigned char const*,size_t,size_t*)");return decodeICCInt32(data, size, pos) / 65536.0f;
}

/** Instrumented function isICCword(unsigned char const*,size_t,size_t,char const*) */
static unsigned isICCword(const unsigned char* data, size_t size, size_t pos, const char* word) /* << Aka begin of function unsigned isICCword(const unsigned char* data, size_t size, size_t pos, const char* word) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isICCword(unsigned char const*,size_t,size_t,char const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.isICCword.21095.stub"

  if(AKA_mark("lis===545###sois===21183###eois===21197###lif===1###soif===104###eoif===118###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isICCword(unsigned char const*,size_t,size_t,char const*)") && (AKA_mark("lis===545###sois===21183###eois===21197###lif===1###soif===104###eoif===118###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isICCword(unsigned char const*,size_t,size_t,char const*)") && (pos + 4 > size))) {
AKA_mark("lis===545###sois===21199###eois===21208###lif===1###soif===120###eoif===129###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isICCword(unsigned char const*,size_t,size_t,char const*)");return 0;
}

else {
AKA_mark("lis===-545-###sois===-21183-###eois===-2118314-###lif===-1-###soif===-###eoif===-118-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isICCword(unsigned char const*,size_t,size_t,char const*)");
}
  AKA_mark("lis===546###sois===21212###eois===21418###lif===2###soif===133###eoif===339###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isICCword(unsigned char const*,size_t,size_t,char const*)");return data[pos + 0] == (unsigned char)word[0] &&
         data[pos + 1] == (unsigned char)word[1] &&
         data[pos + 2] == (unsigned char)word[2] &&
         data[pos + 3] == (unsigned char)word[3];
}

/* Parses a subset of the ICC profile, supporting the necessary mix of ICC v2
and ICC v4 required to correctly convert the RGB color space to XYZ.
Does not parse values not related to this specific PNG-related purpose, and
does not support non-RGB profiles or lookup-table based chroma (but it
supports lookup tables for TRC aka "gamma"). */
/** Instrumented function parseICC(LodePNGICC*,unsigned char const*,size_t) */
static unsigned parseICC(LodePNGICC* icc, const unsigned char* data, size_t size) /* << Aka begin of function unsigned parseICC(LodePNGICC* icc, const unsigned char* data, size_t size) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.parseICC.21788.stub"

  AKA_mark("lis===558###sois===21859###eois===21871###lif===1###soif===87###eoif===99###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");size_t i, j;
  AKA_mark("lis===559###sois===21875###eois===21890###lif===2###soif===103###eoif===118###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");size_t pos = 0;
  AKA_mark("lis===560###sois===21894###eois===21911###lif===3###soif===122###eoif===139###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");unsigned version;
  AKA_mark("lis===561###sois===21915###eois===21935###lif===4###soif===143###eoif===163###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");unsigned inputspace;
  AKA_mark("lis===562###sois===21939###eois===21954###lif===5###soif===167###eoif===182###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");size_t numtags;

  if(AKA_mark("lis===564###sois===21963###eois===21973###lif===7###soif===191###eoif===201###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===564###sois===21963###eois===21973###lif===7###soif===191###eoif===201###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (size < 132))) {
AKA_mark("lis===564###sois===21975###eois===21984###lif===7###soif===203###eoif===212###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");return 1;
}

else {
AKA_mark("lis===-564-###sois===-21963-###eois===-2196310-###lif===-7-###soif===-###eoif===-201-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
} /* Too small to be a valid icc profile. */

  AKA_mark("lis===566###sois===22033###eois===22059###lif===9###soif===261###eoif===287###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->has_chromaticity = 0;
  AKA_mark("lis===567###sois===22063###eois===22087###lif===10###soif===291###eoif===315###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->has_whitepoint = 0;
  AKA_mark("lis===568###sois===22091###eois===22108###lif===11###soif===319###eoif===336###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->has_trc = 0;
  AKA_mark("lis===569###sois===22112###eois===22130###lif===12###soif===340###eoif===358###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->has_chad = 0;

  AKA_mark("lis===571###sois===22136###eois===22195###lif===14###soif===364###eoif===423###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->trc[0].type = icc->trc[1].type = icc->trc[2].type = 0;
  AKA_mark("lis===572###sois===22199###eois===22249###lif===15###soif===427###eoif===477###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->white[0] = icc->white[1] = icc->white[2] = 0;
  AKA_mark("lis===573###sois===22253###eois===22297###lif===16###soif===481###eoif===525###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->red[0] = icc->red[1] = icc->red[2] = 0;
  AKA_mark("lis===574###sois===22301###eois===22351###lif===17###soif===529###eoif===579###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->green[0] = icc->green[1] = icc->green[2] = 0;
  AKA_mark("lis===575###sois===22355###eois===22402###lif===18###soif===583###eoif===630###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->blue[0] = icc->blue[1] = icc->blue[2] = 0;

  AKA_mark("lis===577###sois===22408###eois===22416###lif===20###soif===636###eoif===644###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");pos = 8;
  AKA_mark("lis===578###sois===22420###eois===22464###lif===21###soif===648###eoif===692###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");version = decodeICCUint32(data, size, &pos);
  if(AKA_mark("lis===579###sois===22471###eois===22482###lif===22###soif===699###eoif===710###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===579###sois===22471###eois===22482###lif===22###soif===699###eoif===710###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (pos >= size))) {
AKA_mark("lis===579###sois===22484###eois===22493###lif===22###soif===712###eoif===721###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");return 1;
}

else {
AKA_mark("lis===-579-###sois===-22471-###eois===-2247111-###lif===-22-###soif===-###eoif===-710-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}
  AKA_mark("lis===580###sois===22497###eois===22547###lif===23###soif===725###eoif===775###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->version_major = (int)((version >> 24) & 255);
  AKA_mark("lis===581###sois===22551###eois===22600###lif===24###soif===779###eoif===828###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->version_minor = (int)((version >> 20) & 15);
  AKA_mark("lis===582###sois===22604###eois===22654###lif===25###soif===832###eoif===882###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->version_bugfix = (int)((version >> 16) & 15);

  AKA_mark("lis===584###sois===22660###eois===22669###lif===27###soif===888###eoif===897###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");pos = 16;
  AKA_mark("lis===585###sois===22673###eois===22720###lif===28###soif===901###eoif===948###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");inputspace = decodeICCUint32(data, size, &pos);
  if(AKA_mark("lis===586###sois===22727###eois===22738###lif===29###soif===955###eoif===966###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===586###sois===22727###eois===22738###lif===29###soif===955###eoif===966###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (pos >= size))) {
AKA_mark("lis===586###sois===22740###eois===22749###lif===29###soif===968###eoif===977###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");return 1;
}

else {
AKA_mark("lis===-586-###sois===-22727-###eois===-2272711-###lif===-29-###soif===-###eoif===-966-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}
  if(AKA_mark("lis===587###sois===22756###eois===22780###lif===30###soif===984###eoif===1008###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===587###sois===22756###eois===22780###lif===30###soif===984###eoif===1008###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (inputspace == 0x47524159))) {
    /* The string  "GRAY" as unsigned 32-bit int. */
    AKA_mark("lis===589###sois===22843###eois===22863###lif===32###soif===1071###eoif===1091###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->inputspace = 1;
  } else {
if(AKA_mark("lis===590###sois===22877###eois===22901###lif===33###soif===1105###eoif===1129###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===590###sois===22877###eois===22901###lif===33###soif===1105###eoif===1129###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (inputspace == 0x52474220))) {
    /* The string  "RGB " as unsigned 32-bit int. */
    AKA_mark("lis===592###sois===22964###eois===22984###lif===35###soif===1192###eoif===1212###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->inputspace = 2;
  } else {
    /* unsupported by PNG (CMYK, YCbCr, Lab, HSV, ...) */
    AKA_mark("lis===595###sois===23061###eois===23081###lif===38###soif===1289###eoif===1309###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->inputspace = 0;
  }
}


  /* Should always be 0.9642, 1.0, 0.8249 */
  AKA_mark("lis===599###sois===23138###eois===23147###lif===42###soif===1366###eoif===1375###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");pos = 68;
  AKA_mark("lis===600###sois===23151###eois===23209###lif===43###soif===1379###eoif===1437###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->illuminant[0] = decodeICC15Fixed16(data, size, &pos);
  AKA_mark("lis===601###sois===23213###eois===23271###lif===44###soif===1441###eoif===1499###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->illuminant[1] = decodeICC15Fixed16(data, size, &pos);
  AKA_mark("lis===602###sois===23275###eois===23333###lif===45###soif===1503###eoif===1561###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->illuminant[2] = decodeICC15Fixed16(data, size, &pos);

  AKA_mark("lis===604###sois===23339###eois===23349###lif===47###soif===1567###eoif===1577###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");pos = 128;
  AKA_mark("lis===605###sois===23353###eois===23397###lif===48###soif===1581###eoif===1625###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");numtags = decodeICCUint32(data, size, &pos);
  if(AKA_mark("lis===606###sois===23404###eois===23415###lif===49###soif===1632###eoif===1643###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===606###sois===23404###eois===23415###lif===49###soif===1632###eoif===1643###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (pos >= size))) {
AKA_mark("lis===606###sois===23417###eois===23426###lif===49###soif===1645###eoif===1654###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");return 1;
}

else {
AKA_mark("lis===-606-###sois===-23404-###eois===-2340411-###lif===-49-###soif===-###eoif===-1643-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}
  /* scan for tags we want to handle */
  int AKA_BLOCK_LOOP_23471 = 0;
    AKA_mark("lis===608###sois===23475###eois===23481###lif===51###soif===1703###eoif===1709###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
for(i = 0; AKA_mark("lis===608###sois===23482###eois===23493###lif===51###soif===1710###eoif===1721###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===608###sois===23482###eois===23493###lif===51###soif===1710###eoif===1721###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (i < numtags)); ({AKA_mark("lis===608###sois===23495###eois===23498###lif===51###soif===1723###eoif===1726###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");i++;})) {
        AKA_BLOCK_LOOP_23471++;
        if (AKA_BLOCK_LOOP_23471 > 1000) {
            //break;
        }
    AKA_mark("lis===609###sois===23507###eois===23521###lif===52###soif===1735###eoif===1749###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");size_t offset;
    AKA_mark("lis===610###sois===23527###eois===23544###lif===53###soif===1755###eoif===1772###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");unsigned tagsize;
    AKA_mark("lis===611###sois===23550###eois===23571###lif===54###soif===1778###eoif===1799###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");size_t namepos = pos;
    AKA_mark("lis===612###sois===23577###eois===23586###lif===55###soif===1805###eoif===1814###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");pos += 4;
    AKA_mark("lis===613###sois===23592###eois===23635###lif===56###soif===1820###eoif===1863###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");offset = decodeICCUint32(data, size, &pos);
    AKA_mark("lis===614###sois===23641###eois===23685###lif===57###soif===1869###eoif===1913###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");tagsize = decodeICCUint32(data, size, &pos);
    if(AKA_mark("lis===615###sois===23694###eois===23723###lif===58###soif===1922###eoif===1951###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && ((AKA_mark("lis===615###sois===23694###eois===23705###lif===58###soif===1922###eoif===1933###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (pos >= size)) || (AKA_mark("lis===615###sois===23709###eois===23723###lif===58###soif===1937###eoif===1951###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (offset >= size)))) {
AKA_mark("lis===615###sois===23725###eois===23734###lif===58###soif===1953###eoif===1962###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");return 1;
}

else {
AKA_mark("lis===-615-###sois===-23694-###eois===-2369429-###lif===-58-###soif===-###eoif===-1951-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}
    if(AKA_mark("lis===616###sois===23743###eois===23766###lif===59###soif===1971###eoif===1994###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===616###sois===23743###eois===23766###lif===59###soif===1971###eoif===1994###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (offset + tagsize > size))) {
AKA_mark("lis===616###sois===23768###eois===23777###lif===59###soif===1996###eoif===2005###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");return 1;
}

else {
AKA_mark("lis===-616-###sois===-23743-###eois===-2374323-###lif===-59-###soif===-###eoif===-1994-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}
    if(AKA_mark("lis===617###sois===23786###eois===23797###lif===60###soif===2014###eoif===2025###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===617###sois===23786###eois===23797###lif===60###soif===2014###eoif===2025###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (tagsize < 8))) {
AKA_mark("lis===617###sois===23799###eois===23808###lif===60###soif===2027###eoif===2036###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");return 1;
}

else {
AKA_mark("lis===-617-###sois===-23786-###eois===-2378611-###lif===-60-###soif===-###eoif===-2025-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}

    if(AKA_mark("lis===619###sois===23819###eois===23857###lif===62###soif===2047###eoif===2085###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===619###sois===23819###eois===23857###lif===62###soif===2047###eoif===2085###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (isICCword(data, size, namepos, "wtpt")))) {
      AKA_mark("lis===620###sois===23868###eois===23880###lif===63###soif===2096###eoif===2108###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");offset += 8; /* skip tag and reserved */
      AKA_mark("lis===621###sois===23916###eois===23972###lif===64###soif===2144###eoif===2200###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->white[0] = decodeICC15Fixed16(data, size, &offset);
      AKA_mark("lis===622###sois===23980###eois===24036###lif===65###soif===2208###eoif===2264###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->white[1] = decodeICC15Fixed16(data, size, &offset);
      AKA_mark("lis===623###sois===24044###eois===24100###lif===66###soif===2272###eoif===2328###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->white[2] = decodeICC15Fixed16(data, size, &offset);
      AKA_mark("lis===624###sois===24108###eois===24132###lif===67###soif===2336###eoif===2360###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->has_whitepoint = 1;
    } else {
if(AKA_mark("lis===625###sois===24148###eois===24186###lif===68###soif===2376###eoif===2414###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===625###sois===24148###eois===24186###lif===68###soif===2376###eoif===2414###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (isICCword(data, size, namepos, "rXYZ")))) {
      AKA_mark("lis===626###sois===24197###eois===24209###lif===69###soif===2425###eoif===2437###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");offset += 8; /* skip tag and reserved */
      AKA_mark("lis===627###sois===24245###eois===24299###lif===70###soif===2473###eoif===2527###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->red[0] = decodeICC15Fixed16(data, size, &offset);
      AKA_mark("lis===628###sois===24307###eois===24361###lif===71###soif===2535###eoif===2589###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->red[1] = decodeICC15Fixed16(data, size, &offset);
      AKA_mark("lis===629###sois===24369###eois===24423###lif===72###soif===2597###eoif===2651###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->red[2] = decodeICC15Fixed16(data, size, &offset);
      AKA_mark("lis===630###sois===24431###eois===24457###lif===73###soif===2659###eoif===2685###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->has_chromaticity = 1;
    } else {
if(AKA_mark("lis===631###sois===24473###eois===24511###lif===74###soif===2701###eoif===2739###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===631###sois===24473###eois===24511###lif===74###soif===2701###eoif===2739###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (isICCword(data, size, namepos, "gXYZ")))) {
      AKA_mark("lis===632###sois===24522###eois===24534###lif===75###soif===2750###eoif===2762###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");offset += 8; /* skip tag and reserved */
      AKA_mark("lis===633###sois===24570###eois===24626###lif===76###soif===2798###eoif===2854###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->green[0] = decodeICC15Fixed16(data, size, &offset);
      AKA_mark("lis===634###sois===24634###eois===24690###lif===77###soif===2862###eoif===2918###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->green[1] = decodeICC15Fixed16(data, size, &offset);
      AKA_mark("lis===635###sois===24698###eois===24754###lif===78###soif===2926###eoif===2982###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->green[2] = decodeICC15Fixed16(data, size, &offset);
      AKA_mark("lis===636###sois===24762###eois===24788###lif===79###soif===2990###eoif===3016###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->has_chromaticity = 1;
    } else {
if(AKA_mark("lis===637###sois===24804###eois===24842###lif===80###soif===3032###eoif===3070###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===637###sois===24804###eois===24842###lif===80###soif===3032###eoif===3070###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (isICCword(data, size, namepos, "bXYZ")))) {
      AKA_mark("lis===638###sois===24853###eois===24865###lif===81###soif===3081###eoif===3093###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");offset += 8; /* skip tag and reserved */
      AKA_mark("lis===639###sois===24901###eois===24956###lif===82###soif===3129###eoif===3184###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->blue[0] = decodeICC15Fixed16(data, size, &offset);
      AKA_mark("lis===640###sois===24964###eois===25019###lif===83###soif===3192###eoif===3247###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->blue[1] = decodeICC15Fixed16(data, size, &offset);
      AKA_mark("lis===641###sois===25027###eois===25082###lif===84###soif===3255###eoif===3310###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->blue[2] = decodeICC15Fixed16(data, size, &offset);
      AKA_mark("lis===642###sois===25090###eois===25116###lif===85###soif===3318###eoif===3344###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->has_chromaticity = 1;
    } else {
if(AKA_mark("lis===643###sois===25132###eois===25170###lif===86###soif===3360###eoif===3398###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===643###sois===25132###eois===25170###lif===86###soif===3360###eoif===3398###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (isICCword(data, size, namepos, "chad")))) {
      AKA_mark("lis===644###sois===25181###eois===25193###lif===87###soif===3409###eoif===3421###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");offset += 8; /* skip datatype keyword "sf32" and reserved */
      int AKA_BLOCK_LOOP_25249 = 0;
    AKA_mark("lis===645###sois===25253###eois===25259###lif===88###soif===3481###eoif===3487###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
for(j = 0; AKA_mark("lis===645###sois===25260###eois===25265###lif===88###soif===3488###eoif===3493###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===645###sois===25260###eois===25265###lif===88###soif===3488###eoif===3493###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (j < 9)); ({AKA_mark("lis===645###sois===25267###eois===25270###lif===88###soif===3495###eoif===3498###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");j++;})) {
        AKA_BLOCK_LOOP_25249++;
        if (AKA_BLOCK_LOOP_25249 > 1000) {
            //break;
        }
        AKA_mark("lis===646###sois===25283###eois===25338###lif===89###soif===3511###eoif===3566###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->chad[j] = decodeICC15Fixed16(data, size, &offset);
      }
      AKA_mark("lis===648###sois===25355###eois===25373###lif===91###soif===3583###eoif===3601###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->has_chad = 1;
    } else {
if(AKA_mark("lis===649###sois===25389###eois===25598###lif===92###soif===3617###eoif===3826###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && ((((AKA_mark("lis===649###sois===25389###eois===25427###lif===92###soif===3617###eoif===3655###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (isICCword(data, size, namepos, "rTRC"))) ||
              (AKA_mark("lis===650###sois===25446###eois===25484###lif===93###soif===3674###eoif===3712###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (isICCword(data, size, namepos, "gTRC")))) ||
              (AKA_mark("lis===651###sois===25503###eois===25541###lif===94###soif===3731###eoif===3769###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (isICCword(data, size, namepos, "bTRC")))) ||
              (AKA_mark("lis===652###sois===25560###eois===25598###lif===95###soif===3788###eoif===3826###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (isICCword(data, size, namepos, "kTRC"))))) {
      AKA_mark("lis===653###sois===25609###eois===25638###lif===96###soif===3837###eoif===3866###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");char c = (char)data[namepos];
      /* both 'k' and 'r' are stored in channel 0 */
      AKA_mark("lis===655###sois===25700###eois===25750###lif===98###soif===3928###eoif===3978###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");int channel = (c == 'b') ? 2 : (c == 'g' ? 1 : 0);
      /* "curv": linear, gamma power or LUT */
      if(AKA_mark("lis===657###sois===25809###eois===25846###lif===100###soif===4037###eoif===4074###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===657###sois===25809###eois===25846###lif===100###soif===4037###eoif===4074###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (isICCword(data, size, offset, "curv")))) {
        AKA_mark("lis===658###sois===25859###eois===25872###lif===101###soif===4087###eoif===4100###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");size_t count;
        AKA_mark("lis===659###sois===25882###eois===25924###lif===102###soif===4110###eoif===4152###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");LodePNGICCCurve* trc = &icc->trc[channel];
        AKA_mark("lis===660###sois===25934###eois===25951###lif===103###soif===4162###eoif===4179###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->has_trc = 1;
        AKA_mark("lis===661###sois===25961###eois===25973###lif===104###soif===4189###eoif===4201###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");offset += 8; /* skip tag "curv" and reserved */
        AKA_mark("lis===662###sois===26018###eois===26063###lif===105###soif===4246###eoif===4291###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");count = decodeICCUint32(data, size, &offset);
        if(AKA_mark("lis===663###sois===26076###eois===26086###lif===106###soif===4304###eoif===4314###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===663###sois===26076###eois===26086###lif===106###soif===4304###eoif===4314###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (count == 0))) {
          AKA_mark("lis===664###sois===26101###eois===26115###lif===107###soif===4329###eoif===4343###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->type = 0; /* linear */
        } else {
if(AKA_mark("lis===665###sois===26148###eois===26158###lif===108###soif===4376###eoif===4386###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===665###sois===26148###eois===26158###lif===108###soif===4376###eoif===4386###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (count == 1))) {
          AKA_mark("lis===666###sois===26173###eois===26187###lif===109###soif===4401###eoif===4415###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->type = 2; /* gamma */
          AKA_mark("lis===667###sois===26211###eois===26270###lif===110###soif===4439###eoif===4498###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->gamma = decodeICCUint16(data, size, &offset) / 256.0f;
        } else {
          AKA_mark("lis===669###sois===26300###eois===26314###lif===112###soif===4528###eoif===4542###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->type = 1; /* LUT */
          if(AKA_mark("lis===670###sois===26339###eois===26384###lif===113###soif===4567###eoif===4612###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && ((AKA_mark("lis===670###sois===26339###eois===26364###lif===113###soif===4567###eoif===4592###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (offset + count * 2 > size)) || (AKA_mark("lis===670###sois===26368###eois===26384###lif===113###soif===4596###eoif===4612###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (count > 16777216)))) {
AKA_mark("lis===670###sois===26386###eois===26395###lif===113###soif===4614###eoif===4623###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");return 1;
}

else {
AKA_mark("lis===-670-###sois===-26339-###eois===-2633945-###lif===-113-###soif===-###eoif===-4612-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
} /* also avoid crazy count */
          AKA_mark("lis===671###sois===26436###eois===26458###lif===114###soif===4664###eoif===4686###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->lut_size = count;
          AKA_mark("lis===672###sois===26470###eois===26527###lif===115###soif===4698###eoif===4755###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->lut = (float*)lodepng_malloc(count * sizeof(float));
          int AKA_BLOCK_LOOP_26539 = 0;
    AKA_mark("lis===673###sois===26543###eois===26549###lif===116###soif===4771###eoif===4777###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
for(j = 0; AKA_mark("lis===673###sois===26550###eois===26559###lif===116###soif===4778###eoif===4787###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===673###sois===26550###eois===26559###lif===116###soif===4778###eoif===4787###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (j < count)); ({AKA_mark("lis===673###sois===26561###eois===26564###lif===116###soif===4789###eoif===4792###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");j++;})) {
        AKA_BLOCK_LOOP_26539++;
        if (AKA_BLOCK_LOOP_26539 > 1000) {
            //break;
        }
            AKA_mark("lis===674###sois===26581###eois===26652###lif===117###soif===4809###eoif===4880###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->lut[j] = decodeICCUint16(data, size, &offset) * (1.0f / 65535.0f);
          }
        }
}

      }
else {
AKA_mark("lis===-657-###sois===-25809-###eois===-2580937-###lif===-100-###soif===-###eoif===-4074-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}
      /* "para": parametric formula with gamma power, multipliers, biases and comparison point */
      /* TODO: test this on a realistic sample */
      if(AKA_mark("lis===680###sois===26846###eois===26883###lif===123###soif===5074###eoif===5111###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===680###sois===26846###eois===26883###lif===123###soif===5074###eoif===5111###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (isICCword(data, size, offset, "para")))) {
        AKA_mark("lis===681###sois===26896###eois===26910###lif===124###soif===5124###eoif===5138###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");unsigned type;
        AKA_mark("lis===682###sois===26920###eois===26962###lif===125###soif===5148###eoif===5190###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");LodePNGICCCurve* trc = &icc->trc[channel];
        AKA_mark("lis===683###sois===26972###eois===26989###lif===126###soif===5200###eoif===5217###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");icc->has_trc = 1;
        AKA_mark("lis===684###sois===26999###eois===27011###lif===127###soif===5227###eoif===5239###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");offset += 8; /* skip tag "para" and reserved */
        AKA_mark("lis===685###sois===27056###eois===27100###lif===128###soif===5284###eoif===5328###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");type = decodeICCUint16(data, size, &offset);
        AKA_mark("lis===686###sois===27110###eois===27122###lif===129###soif===5338###eoif===5350###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");offset += 2;
        if(AKA_mark("lis===687###sois===27135###eois===27143###lif===130###soif===5363###eoif===5371###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===687###sois===27135###eois===27143###lif===130###soif===5363###eoif===5371###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (type > 4))) {
AKA_mark("lis===687###sois===27145###eois===27154###lif===130###soif===5373###eoif===5382###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");return 1;
}

else {
AKA_mark("lis===-687-###sois===-27135-###eois===-271358-###lif===-130-###soif===-###eoif===-5371-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
} /* unknown parametric curve type */
        AKA_mark("lis===688###sois===27200###eois===27221###lif===131###soif===5428###eoif===5449###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->type = type + 2;
        AKA_mark("lis===689###sois===27231###eois===27284###lif===132###soif===5459###eoif===5512###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->gamma = decodeICC15Fixed16(data, size, &offset);
        if(AKA_mark("lis===690###sois===27297###eois===27306###lif===133###soif===5525###eoif===5534###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===690###sois===27297###eois===27306###lif===133###soif===5525###eoif===5534###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (type >= 1))) {
          AKA_mark("lis===691###sois===27321###eois===27370###lif===134###soif===5549###eoif===5598###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->a = decodeICC15Fixed16(data, size, &offset);
          AKA_mark("lis===692###sois===27382###eois===27431###lif===135###soif===5610###eoif===5659###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->b = decodeICC15Fixed16(data, size, &offset);
        }
else {
AKA_mark("lis===-690-###sois===-27297-###eois===-272979-###lif===-133-###soif===-###eoif===-5534-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}
        if(AKA_mark("lis===694###sois===27455###eois===27464###lif===137###soif===5683###eoif===5692###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===694###sois===27455###eois===27464###lif===137###soif===5683###eoif===5692###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (type >= 2))) {
          AKA_mark("lis===695###sois===27479###eois===27528###lif===138###soif===5707###eoif===5756###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->c = decodeICC15Fixed16(data, size, &offset);
        }
else {
AKA_mark("lis===-694-###sois===-27455-###eois===-274559-###lif===-137-###soif===-###eoif===-5692-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}
        if(AKA_mark("lis===697###sois===27552###eois===27561###lif===140###soif===5780###eoif===5789###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===697###sois===27552###eois===27561###lif===140###soif===5780###eoif===5789###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (type >= 3))) {
          AKA_mark("lis===698###sois===27576###eois===27625###lif===141###soif===5804###eoif===5853###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->d = decodeICC15Fixed16(data, size, &offset);
        }
else {
AKA_mark("lis===-697-###sois===-27552-###eois===-275529-###lif===-140-###soif===-###eoif===-5789-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}
        if(AKA_mark("lis===700###sois===27649###eois===27658###lif===143###soif===5877###eoif===5886###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===700###sois===27649###eois===27658###lif===143###soif===5877###eoif===5886###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (type == 4))) {
          AKA_mark("lis===701###sois===27673###eois===27722###lif===144###soif===5901###eoif===5950###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->e = decodeICC15Fixed16(data, size, &offset);
          AKA_mark("lis===702###sois===27734###eois===27783###lif===145###soif===5962###eoif===6011###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");trc->f = decodeICC15Fixed16(data, size, &offset);
        }
else {
AKA_mark("lis===-700-###sois===-27649-###eois===-276499-###lif===-143-###soif===-###eoif===-5886-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}
      }
else {
AKA_mark("lis===-680-###sois===-26846-###eois===-2684637-###lif===-123-###soif===-###eoif===-5111-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}
      /* TODO: verify: does the "chrm" tag participate in computation so should be parsed? */
    }
else {
AKA_mark("lis===-649-###sois===-25389-###eois===-25389209-###lif===-92-###soif===-###eoif===-3826-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}
}

}

}

}

}

    /* Return error if any parse went beyond the filesize. Note that the
    parsing itself was always safe since it bound-checks inside. */
    if(AKA_mark("lis===709###sois===28057###eois===28070###lif===152###soif===6285###eoif===6298###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (AKA_mark("lis===709###sois===28057###eois===28070###lif===152###soif===6285###eoif===6298###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)") && (offset > size))) {
AKA_mark("lis===709###sois===28072###eois===28081###lif===152###soif===6300###eoif===6309###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");return 1;
}

else {
AKA_mark("lis===-709-###sois===-28057-###eois===-2805713-###lif===-152-###soif===-###eoif===-6298-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");
}
  }

  AKA_mark("lis===712###sois===28092###eois===28101###lif===155###soif===6320###eoif===6329###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\parseICC(LodePNGICC*,unsigned char const*,size_t)");return 0;
}

/* Multiplies 3 vector values with 3x3 matrix */
/** Instrumented function mulMatrix(float*,float*,float*,float const*,double,double,double) */
static void mulMatrix(float* x2, float* y2, float* z2, const float* m, double x, double y, double z) /* << Aka begin of function void mulMatrix(float* x2, float* y2, float* z2, const float* m, double x, double y, double z) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrix(float*,float*,float*,float const*,double,double,double)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.mulMatrix.28170.stub"

  /* double used as inputs even though in general the images are float, so the sums happen in
  double precision, because float can give numerical problems for nearby values */
  AKA_mark("lis===719###sois===28443###eois===28489###lif===3###soif===285###eoif===331###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrix(float*,float*,float*,float const*,double,double,double)");*x2 = (float)(x * m[0] + y * m[1] + z * m[2]);
  AKA_mark("lis===720###sois===28493###eois===28539###lif===4###soif===335###eoif===381###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrix(float*,float*,float*,float const*,double,double,double)");*y2 = (float)(x * m[3] + y * m[4] + z * m[5]);
  AKA_mark("lis===721###sois===28543###eois===28589###lif===5###soif===385###eoif===431###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrix(float*,float*,float*,float const*,double,double,double)");*z2 = (float)(x * m[6] + y * m[7] + z * m[8]);
}

/** Instrumented function mulMatrixMatrix(float*,float const*,float const*) */
static void mulMatrixMatrix(float* result, const float* a, const float* b) /* << Aka begin of function void mulMatrixMatrix(float* result, const float* a, const float* b) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrixMatrix(float*,float const*,float const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.mulMatrixMatrix.28608.stub"

  AKA_mark("lis===725###sois===28676###eois===28682###lif===1###soif===80###eoif===86###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrixMatrix(float*,float const*,float const*)");int i;
  AKA_mark("lis===726###sois===28686###eois===28700###lif===2###soif===90###eoif===104###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrixMatrix(float*,float const*,float const*)");float temp[9]; /* temp is to allow result and a or b to be the same */
  AKA_mark("lis===727###sois===28760###eois===28821###lif===3###soif===164###eoif===225###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrixMatrix(float*,float const*,float const*)");mulMatrix(&temp[0], &temp[3], &temp[6], a, b[0], b[3], b[6]);
  AKA_mark("lis===728###sois===28825###eois===28886###lif===4###soif===229###eoif===290###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrixMatrix(float*,float const*,float const*)");mulMatrix(&temp[1], &temp[4], &temp[7], a, b[1], b[4], b[7]);
  AKA_mark("lis===729###sois===28890###eois===28951###lif===5###soif===294###eoif===355###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrixMatrix(float*,float const*,float const*)");mulMatrix(&temp[2], &temp[5], &temp[8], a, b[2], b[5], b[8]);
  int AKA_BLOCK_LOOP_28955 = 0;
    AKA_mark("lis===730###sois===28959###eois===28965###lif===6###soif===363###eoif===369###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrixMatrix(float*,float const*,float const*)");
for(i = 0; AKA_mark("lis===730###sois===28966###eois===28971###lif===6###soif===370###eoif===375###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrixMatrix(float*,float const*,float const*)") && (AKA_mark("lis===730###sois===28966###eois===28971###lif===6###soif===370###eoif===375###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrixMatrix(float*,float const*,float const*)") && (i < 9)); ({AKA_mark("lis===730###sois===28973###eois===28976###lif===6###soif===377###eoif===380###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrixMatrix(float*,float const*,float const*)");i++;})) {
AKA_mark("lis===730###sois===28978###eois===28998###lif===6###soif===382###eoif===402###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\mulMatrixMatrix(float*,float const*,float const*)");result[i] = temp[i];
}

}

/* Inverts 3x3 matrix in place */
/** Instrumented function invMatrix(float*) */
static unsigned invMatrix(float* m) /* << Aka begin of function unsigned invMatrix(float* m) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.invMatrix.29056.stub"

  AKA_mark("lis===735###sois===29081###eois===29087###lif===1###soif===41###eoif===47###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");int i;
  /* double used instead of float for intermediate computations to avoid
  intermediate numerical precision issues */
  AKA_mark("lis===738###sois===29211###eois===29265###lif===4###soif===171###eoif===225###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");double e0 = (double)m[4] * m[8] - (double)m[5] * m[7];
  AKA_mark("lis===739###sois===29269###eois===29323###lif===5###soif===229###eoif===283###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");double e3 = (double)m[5] * m[6] - (double)m[3] * m[8];
  AKA_mark("lis===740###sois===29327###eois===29381###lif===6###soif===287###eoif===341###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");double e6 = (double)m[3] * m[7] - (double)m[4] * m[6];
  /* inverse determinant */
  AKA_mark("lis===742###sois===29414###eois===29467###lif===8###soif===374###eoif===427###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");double d = 1.0 / (m[0] * e0 + m[1] * e3 + m[2] * e6);
  AKA_mark("lis===743###sois===29471###eois===29488###lif===9###soif===431###eoif===448###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");double result[9];
  if(AKA_mark("lis===744###sois===29495###eois===29518###lif===10###soif===455###eoif===478###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)") && (AKA_mark("lis===744###sois===29495###eois===29518###lif===10###soif===455###eoif===478###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)") && ((d > 0 ? d : -d) > 1e15))) {
AKA_mark("lis===744###sois===29520###eois===29529###lif===10###soif===480###eoif===489###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");return 1;
}

else {
AKA_mark("lis===-744-###sois===-29495-###eois===-2949523-###lif===-10-###soif===-###eoif===-478-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");
} /* error, likely not invertible */
  AKA_mark("lis===745###sois===29568###eois===29587###lif===11###soif===528###eoif===547###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");result[0] = e0 * d;
  AKA_mark("lis===746###sois===29591###eois===29651###lif===12###soif===551###eoif===611###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");result[1] = ((double)m[2] * m[7] - (double)m[1] * m[8]) * d;
  AKA_mark("lis===747###sois===29655###eois===29715###lif===13###soif===615###eoif===675###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");result[2] = ((double)m[1] * m[5] - (double)m[2] * m[4]) * d;
  AKA_mark("lis===748###sois===29719###eois===29738###lif===14###soif===679###eoif===698###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");result[3] = e3 * d;
  AKA_mark("lis===749###sois===29742###eois===29802###lif===15###soif===702###eoif===762###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");result[4] = ((double)m[0] * m[8] - (double)m[2] * m[6]) * d;
  AKA_mark("lis===750###sois===29806###eois===29866###lif===16###soif===766###eoif===826###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");result[5] = ((double)m[3] * m[2] - (double)m[0] * m[5]) * d;
  AKA_mark("lis===751###sois===29870###eois===29889###lif===17###soif===830###eoif===849###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");result[6] = e6 * d;
  AKA_mark("lis===752###sois===29893###eois===29953###lif===18###soif===853###eoif===913###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");result[7] = ((double)m[6] * m[1] - (double)m[0] * m[7]) * d;
  AKA_mark("lis===753###sois===29957###eois===30017###lif===19###soif===917###eoif===977###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");result[8] = ((double)m[0] * m[4] - (double)m[3] * m[1]) * d;
  int AKA_BLOCK_LOOP_30021 = 0;
    AKA_mark("lis===754###sois===30025###eois===30031###lif===20###soif===985###eoif===991###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");
for(i = 0; AKA_mark("lis===754###sois===30032###eois===30037###lif===20###soif===992###eoif===997###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)") && (AKA_mark("lis===754###sois===30032###eois===30037###lif===20###soif===992###eoif===997###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)") && (i < 9)); ({AKA_mark("lis===754###sois===30039###eois===30042###lif===20###soif===999###eoif===1002###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");i++;})) {
AKA_mark("lis===754###sois===30044###eois===30068###lif===20###soif===1004###eoif===1028###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");m[i] = (float)result[i];
}

  AKA_mark("lis===755###sois===30072###eois===30081###lif===21###soif===1032###eoif===1041###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\invMatrix(float*)");return 0; /* ok */
}

/* Get the matrix to go from linear RGB to XYZ given the RGB whitepoint and chromaticities in XYZ colorspace */
/** Instrumented function getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float) */
static unsigned getChrmMatrixXYZ(float* m,
                                 float wX, float wY, float wZ,
                                 float rX, float rY, float rZ,
                                 float gX, float gY, float gZ,
                                 float bX, float bY, float bZ) /* << Aka begin of function unsigned getChrmMatrixXYZ(float* m,
                                 float wX, float wY, float wZ,
                                 float rX, float rY, float rZ,
                                 float gX, float gY, float gZ,
                                 float bX, float bY, float bZ) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.getChrmMatrixXYZ.30226.stub"

  AKA_mark("lis===764###sois===30514###eois===30525###lif===5###soif===304###eoif===315###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");float t[9];
  AKA_mark("lis===765###sois===30529###eois===30546###lif===6###soif===319###eoif===336###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");float rs, gs, bs;
  AKA_mark("lis===766###sois===30550###eois===30560###lif===7###soif===340###eoif===350###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");t[0] = rX; AKA_mark("lis===766###sois===30561###eois===30571###lif===7###soif===351###eoif===361###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");t[1] = gX; AKA_mark("lis===766###sois===30572###eois===30582###lif===7###soif===362###eoif===372###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");t[2] = bX;
  AKA_mark("lis===767###sois===30586###eois===30596###lif===8###soif===376###eoif===386###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");t[3] = rY; AKA_mark("lis===767###sois===30597###eois===30607###lif===8###soif===387###eoif===397###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");t[4] = gY; AKA_mark("lis===767###sois===30608###eois===30618###lif===8###soif===398###eoif===408###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");t[5] = bY;
  AKA_mark("lis===768###sois===30622###eois===30632###lif===9###soif===412###eoif===422###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");t[6] = rZ; AKA_mark("lis===768###sois===30633###eois===30643###lif===9###soif===423###eoif===433###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");t[7] = gZ; AKA_mark("lis===768###sois===30644###eois===30654###lif===9###soif===434###eoif===444###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");t[8] = bZ;
  if(AKA_mark("lis===769###sois===30661###eois===30673###lif===10###soif===451###eoif===463###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)") && (AKA_mark("lis===769###sois===30661###eois===30673###lif===10###soif===451###eoif===463###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)") && (invMatrix(t)))) {
AKA_mark("lis===769###sois===30675###eois===30684###lif===10###soif===465###eoif===474###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");return 1;
}

else {
AKA_mark("lis===-769-###sois===-30661-###eois===-3066112-###lif===-10-###soif===-###eoif===-463-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");
} /* error, not invertible */
  AKA_mark("lis===770###sois===30716###eois===30756###lif===11###soif===506###eoif===546###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");mulMatrix(&rs, &gs, &bs, t, wX, wY, wZ);
  AKA_mark("lis===771###sois===30760###eois===30775###lif===12###soif===550###eoif===565###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");m[0] = rs * rX; AKA_mark("lis===771###sois===30776###eois===30791###lif===12###soif===566###eoif===581###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");m[1] = gs * gX; AKA_mark("lis===771###sois===30792###eois===30807###lif===12###soif===582###eoif===597###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");m[2] = bs * bX;
  AKA_mark("lis===772###sois===30811###eois===30826###lif===13###soif===601###eoif===616###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");m[3] = rs * rY; AKA_mark("lis===772###sois===30827###eois===30842###lif===13###soif===617###eoif===632###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");m[4] = gs * gY; AKA_mark("lis===772###sois===30843###eois===30858###lif===13###soif===633###eoif===648###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");m[5] = bs * bY;
  AKA_mark("lis===773###sois===30862###eois===30877###lif===14###soif===652###eoif===667###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");m[6] = rs * rZ; AKA_mark("lis===773###sois===30878###eois===30893###lif===14###soif===668###eoif===683###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");m[7] = gs * gZ; AKA_mark("lis===773###sois===30894###eois===30909###lif===14###soif===684###eoif===699###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");m[8] = bs * bZ;
  AKA_mark("lis===774###sois===30913###eois===30922###lif===15###soif===703###eoif===712###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXYZ(float*,float,float,float,float,float,float,float,float,float,float,float,float)");return 0;
}

/* Get the matrix to go from linear RGB to XYZ given the RGB whitepoint and chromaticities in xy colorspace */
/** Instrumented function getChrmMatrixXY(float*,float,float,float,float,float,float,float,float) */
static unsigned getChrmMatrixXY(float* m,
                                float wx, float wy,
                                float rx, float ry,
                                float gx, float gy,
                                float bx, float by) /* << Aka begin of function unsigned getChrmMatrixXY(float* m,
                                float wx, float wy,
                                float rx, float ry,
                                float gx, float gy,
                                float bx, float by) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXY(float*,float,float,float,float,float,float,float,float)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.getChrmMatrixXY.31057.stub"

  if(AKA_mark("lis===783###sois===31303###eois===31343###lif===5###soif===262###eoif===302###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXY(float*,float,float,float,float,float,float,float,float)") && ((((AKA_mark("lis===783###sois===31303###eois===31310###lif===5###soif===262###eoif===269###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXY(float*,float,float,float,float,float,float,float,float)") && (wy == 0)) || (AKA_mark("lis===783###sois===31314###eois===31321###lif===5###soif===273###eoif===280###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXY(float*,float,float,float,float,float,float,float,float)") && (ry == 0))) || (AKA_mark("lis===783###sois===31325###eois===31332###lif===5###soif===284###eoif===291###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXY(float*,float,float,float,float,float,float,float,float)") && (gy == 0))) || (AKA_mark("lis===783###sois===31336###eois===31343###lif===5###soif===295###eoif===302###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXY(float*,float,float,float,float,float,float,float,float)") && (by == 0)))) {
    AKA_mark("lis===784###sois===31352###eois===31361###lif===6###soif===311###eoif===320###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXY(float*,float,float,float,float,float,float,float,float)");return 1; /* error, division through zero */
  } else {
    AKA_mark("lis===786###sois===31414###eois===31466###lif===8###soif===373###eoif===425###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXY(float*,float,float,float,float,float,float,float,float)");float wX = wx / wy, wY = 1, wZ = (1 - wx - wy) / wy;
    AKA_mark("lis===787###sois===31472###eois===31524###lif===9###soif===431###eoif===483###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXY(float*,float,float,float,float,float,float,float,float)");float rX = rx / ry, rY = 1, rZ = (1 - rx - ry) / ry;
    AKA_mark("lis===788###sois===31530###eois===31582###lif===10###soif===489###eoif===541###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXY(float*,float,float,float,float,float,float,float,float)");float gX = gx / gy, gY = 1, gZ = (1 - gx - gy) / gy;
    AKA_mark("lis===789###sois===31588###eois===31640###lif===11###soif===547###eoif===599###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXY(float*,float,float,float,float,float,float,float,float)");float bX = bx / by, bY = 1, bZ = (1 - bx - by) / by;
    AKA_mark("lis===790###sois===31646###eois===31721###lif===12###soif===605###eoif===680###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrmMatrixXY(float*,float,float,float,float,float,float,float,float)");return getChrmMatrixXYZ(m, wX, wY, wZ, rX, rY, rZ, gX, gY, gZ, bX, bY, bZ);
  }
}

/* Returns matrix that adapts from source whitepoint 0 to destination whitepoint 1.
Types: 0=XYZ scaling, 1=Bradford, 2=Vonkries */
/** Instrumented function getAdaptationMatrix(float*,int,float,float,float,float,float,float) */
static unsigned getAdaptationMatrix(float* m, int type,
                                    float wx0, float wy0, float wz0,
                                    float wx1, float wy1, float wz1) /* << Aka begin of function unsigned getAdaptationMatrix(float* m, int type,
                                    float wx0, float wy0, float wz0,
                                    float wx1, float wy1, float wz1) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.getAdaptationMatrix.31883.stub"

  AKA_mark("lis===799###sois===32068###eois===32074###lif===3###soif===201###eoif===207###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");int i;
  AKA_mark("lis===800###sois===32078###eois===32216###lif===4###soif===211###eoif===349###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");static const float bradford[9] = {
    0.8951f, 0.2664f, -0.1614f,
    -0.7502f, 1.7135f, 0.0367f,
    0.0389f, -0.0685f, 1.0296f
  };
  AKA_mark("lis===805###sois===32220###eois===32386###lif===9###soif===353###eoif===519###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");static const float bradfordinv[9] = {
    0.9869929f, -0.1470543f, 0.1599627f,
    0.4323053f, 0.5183603f, 0.0492912f,
   -0.0085287f, 0.0400428f, 0.9684867f
  };
  AKA_mark("lis===810###sois===32390###eois===32537###lif===14###soif===523###eoif===670###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");static const float vonkries[9] = {
    0.40024f, 0.70760f, -0.08081f,
    -0.22630f, 1.16532f, 0.04570f,
    0.00000f, 0.00000f, 0.91822f,
  };
  AKA_mark("lis===815###sois===32541###eois===32707###lif===19###soif===674###eoif===840###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");static const float vonkriesinv[9] = {
    1.8599364f, -1.1293816f, 0.2198974f,
    0.3611914f, 0.6388125f, -0.0000064f,
   0.0000000f, 0.0000000f, 1.0890636f
  };
  if(AKA_mark("lis===820###sois===32714###eois===32723###lif===24###soif===847###eoif===856###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)") && (AKA_mark("lis===820###sois===32714###eois===32723###lif===24###soif===847###eoif===856###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)") && (type == 0))) {
    int AKA_BLOCK_LOOP_32732 = 0;
    AKA_mark("lis===821###sois===32736###eois===32742###lif===25###soif===869###eoif===875###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");
for(i = 0; AKA_mark("lis===821###sois===32743###eois===32748###lif===25###soif===876###eoif===881###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)") && (AKA_mark("lis===821###sois===32743###eois===32748###lif===25###soif===876###eoif===881###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)") && (i < 9)); ({AKA_mark("lis===821###sois===32750###eois===32753###lif===25###soif===883###eoif===886###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");i++;})) {
AKA_mark("lis===821###sois===32755###eois===32764###lif===25###soif===888###eoif===897###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");m[i] = 0;
}

    AKA_mark("lis===822###sois===32770###eois===32787###lif===26###soif===903###eoif===920###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");m[0] = wx1 / wx0;
    AKA_mark("lis===823###sois===32793###eois===32810###lif===27###soif===926###eoif===943###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");m[4] = wy1 / wy0;
    AKA_mark("lis===824###sois===32816###eois===32833###lif===28###soif===949###eoif===966###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");m[8] = wz1 / wz0;
  } else {
    AKA_mark("lis===826###sois===32851###eois===32904###lif===30###soif===984###eoif===1037###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");const float* cat = (type == 1) ? bradford : vonkries;
    AKA_mark("lis===827###sois===32910###eois===32969###lif===31###soif===1043###eoif===1102###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");const float* inv = (type == 1) ? bradfordinv : vonkriesinv;
    AKA_mark("lis===828###sois===32975###eois===33034###lif===32###soif===1108###eoif===1167###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");float rho0, gam0, bet0, rho1, gam1, bet1, rho2, gam2, bet2;
    AKA_mark("lis===829###sois===33040###eois===33091###lif===33###soif===1173###eoif===1224###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");mulMatrix(&rho0, &gam0, &bet0, cat, wx0, wy0, wz0);
    AKA_mark("lis===830###sois===33097###eois===33148###lif===34###soif===1230###eoif===1281###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");mulMatrix(&rho1, &gam1, &bet1, cat, wx1, wy1, wz1);
    AKA_mark("lis===831###sois===33154###eois===33173###lif===35###soif===1287###eoif===1306###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");rho2 = rho1 / rho0;
    AKA_mark("lis===832###sois===33179###eois===33198###lif===36###soif===1312###eoif===1331###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");gam2 = gam1 / gam0;
    AKA_mark("lis===833###sois===33204###eois===33223###lif===37###soif===1337###eoif===1356###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");bet2 = bet1 / bet0;
    /* Multiply diagonal matrix with cat */
    int AKA_BLOCK_LOOP_33274 = 0;
    AKA_mark("lis===835###sois===33278###eois===33284###lif===39###soif===1411###eoif===1417###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");
for(i = 0; AKA_mark("lis===835###sois===33285###eois===33290###lif===39###soif===1418###eoif===1423###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)") && (AKA_mark("lis===835###sois===33285###eois===33290###lif===39###soif===1418###eoif===1423###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)") && (i < 3)); ({AKA_mark("lis===835###sois===33292###eois===33295###lif===39###soif===1425###eoif===1428###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");i++;})) {
        AKA_BLOCK_LOOP_33274++;
        if (AKA_BLOCK_LOOP_33274 > 1000) {
            //break;
        }
      AKA_mark("lis===836###sois===33306###eois===33335###lif===40###soif===1439###eoif===1468###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");m[i + 0] = rho2 * cat[i + 0];
      AKA_mark("lis===837###sois===33343###eois===33372###lif===41###soif===1476###eoif===1505###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");m[i + 3] = gam2 * cat[i + 3];
      AKA_mark("lis===838###sois===33380###eois===33409###lif===42###soif===1513###eoif===1542###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");m[i + 6] = bet2 * cat[i + 6];
    }
    AKA_mark("lis===840###sois===33422###eois===33449###lif===44###soif===1555###eoif===1582###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");mulMatrixMatrix(m, inv, m);
  }
  AKA_mark("lis===842###sois===33458###eois===33467###lif===46###soif===1591###eoif===1600###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getAdaptationMatrix(float*,int,float,float,float,float,float,float)");return 0; /* ok */
}

/* validate whether the ICC profile is supported here for PNG */
/** Instrumented function validateICC(LodePNGICC const*) */
static unsigned validateICC(const LodePNGICC* icc) /* << Aka begin of function unsigned validateICC(const LodePNGICC* icc) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.validateICC.33565.stub"

  /* disable for unsupported things in the icc profile */
  if(AKA_mark("lis===848###sois===33667###eois===33687###lif===2###soif===118###eoif===138###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)") && (AKA_mark("lis===848###sois===33667###eois===33687###lif===2###soif===118###eoif===138###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)") && (icc->inputspace == 0))) {
AKA_mark("lis===848###sois===33689###eois===33698###lif===2###soif===140###eoif===149###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)");return 0;
}

else {
AKA_mark("lis===-848-###sois===-33667-###eois===-3366720-###lif===-2-###soif===-###eoif===-138-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)");
}
  /* if we didn't recognize both chrm and trc, then maybe the ICC uses data
  types not supported here yet, so fall back to not using it. */
  if(AKA_mark("lis===851###sois===33848###eois===33868###lif===5###soif===299###eoif===319###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)") && (AKA_mark("lis===851###sois===33848###eois===33868###lif===5###soif===299###eoif===319###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)") && (icc->inputspace == 2))) {
    /* RGB profile should have chromaticities */
    if(AKA_mark("lis===853###sois===33930###eois===33952###lif===7###soif===381###eoif===403###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)") && (AKA_mark("lis===853###sois===33930###eois===33952###lif===7###soif===381###eoif===403###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)") && (!icc->has_chromaticity))) {
AKA_mark("lis===853###sois===33954###eois===33963###lif===7###soif===405###eoif===414###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)");return 0;
}

else {
AKA_mark("lis===-853-###sois===-33930-###eois===-3393022-###lif===-7-###soif===-###eoif===-403-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)");
}
  }
else {
AKA_mark("lis===-851-###sois===-33848-###eois===-3384820-###lif===-5-###soif===-###eoif===-319-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)");
}
  /* An ICC profile without whitepoint is invalid for the kind of profiles used here. */
  if(AKA_mark("lis===856###sois===34065###eois===34085###lif===10###soif===516###eoif===536###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)") && (AKA_mark("lis===856###sois===34065###eois===34085###lif===10###soif===516###eoif===536###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)") && (!icc->has_whitepoint))) {
AKA_mark("lis===856###sois===34087###eois===34096###lif===10###soif===538###eoif===547###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)");return 0;
}

else {
AKA_mark("lis===-856-###sois===-34065-###eois===-3406520-###lif===-10-###soif===-###eoif===-536-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)");
}
  if(AKA_mark("lis===857###sois===34103###eois===34116###lif===11###soif===554###eoif===567###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)") && (AKA_mark("lis===857###sois===34103###eois===34116###lif===11###soif===554###eoif===567###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)") && (!icc->has_trc))) {
AKA_mark("lis===857###sois===34118###eois===34127###lif===11###soif===569###eoif===578###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)");return 0;
}

else {
AKA_mark("lis===-857-###sois===-34103-###eois===-3410313-###lif===-11-###soif===-###eoif===-567-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)");
}
  AKA_mark("lis===858###sois===34131###eois===34140###lif===12###soif===582###eoif===591###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\validateICC(LodePNGICC const*)");return 1; /* ok */
}

/* Returns chromaticity matrix for given ICC profile, adapted from ICC's
global illuminant as necessary.
Also returns the profile's whitepoint.
In case of a gray profile (icc->inputspace == 1), the identity matrix will be returned
so in that case you could skip the transform. */
/** Instrumented function getICCChrm(float[9],float[3],LodePNGICC const*) */
static unsigned getICCChrm(float m[9], float whitepoint[3], const LodePNGICC* icc) /* << Aka begin of function unsigned getICCChrm(float m[9], float whitepoint[3], const LodePNGICC* icc) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.getICCChrm.34457.stub"

  AKA_mark("lis===867###sois===34529###eois===34538###lif===1###soif===88###eoif===97###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");size_t i;
  if(AKA_mark("lis===868###sois===34545###eois===34565###lif===2###soif===104###eoif===124###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (AKA_mark("lis===868###sois===34545###eois===34565###lif===2###soif===104###eoif===124###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (icc->inputspace == 2))) { /* RGB profile */
    AKA_mark("lis===869###sois===34592###eois===34624###lif===3###soif===151###eoif===183###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");float red[3], green[3], blue[3];
    AKA_mark("lis===870###sois===34630###eois===34645###lif===4###soif===189###eoif===204###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");float white[3]; /* the whitepoint of the RGB color space (absolute) */
    /* Adaptation matrix a.
    This is an adaptation needed for ICC's file format (due to it using
    an internal global illuminant unrelated to the actual images) */
    AKA_mark("lis===874###sois===34878###eois===34913###lif===8###soif===437###eoif===472###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");float a[9] = {1,0,0, 0,1,0, 0,0,1};
    /* If the profile has chromatic adaptation matrix "chad", use that one,
    else compute it from the illuminant and whitepoint. */
    if(AKA_mark("lis===877###sois===35059###eois===35072###lif===11###soif===618###eoif===631###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (AKA_mark("lis===877###sois===35059###eois===35072###lif===11###soif===618###eoif===631###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (icc->has_chad))) {
      int AKA_BLOCK_LOOP_35083 = 0;
    AKA_mark("lis===878###sois===35087###eois===35093###lif===12###soif===646###eoif===652###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");
for(i = 0; AKA_mark("lis===878###sois===35094###eois===35099###lif===12###soif===653###eoif===658###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (AKA_mark("lis===878###sois===35094###eois===35099###lif===12###soif===653###eoif===658###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (i < 9)); ({AKA_mark("lis===878###sois===35101###eois===35104###lif===12###soif===660###eoif===663###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");i++;})) {
AKA_mark("lis===878###sois===35106###eois===35126###lif===12###soif===665###eoif===685###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");a[i] = icc->chad[i];
}

      AKA_mark("lis===879###sois===35134###eois===35147###lif===13###soif===693###eoif===706###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");invMatrix(a);
    } else {
      if(AKA_mark("lis===881###sois===35172###eois===35332###lif===15###soif===731###eoif===891###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (AKA_mark("lis===881###sois===35172###eois===35332###lif===15###soif===731###eoif===891###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (getAdaptationMatrix(a, 1, icc->illuminant[0], icc->illuminant[1], icc->illuminant[2],
                             icc->white[0], icc->white[1], icc->white[2])))) {
        AKA_mark("lis===883###sois===35345###eois===35354###lif===17###soif===904###eoif===913###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");return 1; /* error computing matrix */
      }
else {
AKA_mark("lis===-881-###sois===-35172-###eois===-35172160-###lif===-15-###soif===-###eoif===-891-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");
}
    }
    /* If the profile has a chad, then also the RGB's whitepoint must also be adapted from it (and the one
    given is normally D50). If it did not have a chad, then the whitepoint given is already the adapted one. */
    if(AKA_mark("lis===888###sois===35629###eois===35642###lif===22###soif===1188###eoif===1201###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (AKA_mark("lis===888###sois===35629###eois===35642###lif===22###soif===1188###eoif===1201###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (icc->has_chad))) {
      AKA_mark("lis===889###sois===35653###eois===35744###lif===23###soif===1212###eoif===1303###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");mulMatrix(&white[0], &white[1], &white[2], a, icc->white[0], icc->white[1], icc->white[2]);
    } else {
      int AKA_BLOCK_LOOP_35766 = 0;
    AKA_mark("lis===891###sois===35770###eois===35776###lif===25###soif===1329###eoif===1335###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");
for(i = 0; AKA_mark("lis===891###sois===35777###eois===35782###lif===25###soif===1336###eoif===1341###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (AKA_mark("lis===891###sois===35777###eois===35782###lif===25###soif===1336###eoif===1341###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (i < 3)); ({AKA_mark("lis===891###sois===35784###eois===35787###lif===25###soif===1343###eoif===1346###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");i++;})) {
AKA_mark("lis===891###sois===35789###eois===35814###lif===25###soif===1348###eoif===1373###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");white[i] = icc->white[i];
}

    }

    AKA_mark("lis===894###sois===35829###eois===35908###lif===28###soif===1388###eoif===1467###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");mulMatrix(&red[0], &red[1], &red[2], a, icc->red[0], icc->red[1], icc->red[2]);
    AKA_mark("lis===895###sois===35914###eois===36005###lif===29###soif===1473###eoif===1564###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");mulMatrix(&green[0], &green[1], &green[2], a, icc->green[0], icc->green[1], icc->green[2]);
    AKA_mark("lis===896###sois===36011###eois===36096###lif===30###soif===1570###eoif===1655###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");mulMatrix(&blue[0], &blue[1], &blue[2], a, icc->blue[0], icc->blue[1], icc->blue[2]);

    if(AKA_mark("lis===898###sois===36107###eois===36262###lif===32###soif===1666###eoif===1821###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (AKA_mark("lis===898###sois===36107###eois===36262###lif===32###soif===1666###eoif===1821###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)") && (getChrmMatrixXYZ(m, white[0], white[1], white[2], red[0], red[1], red[2],
                        green[0], green[1], green[2], blue[0], blue[1], blue[2])))) {
      AKA_mark("lis===900###sois===36273###eois===36282###lif===34###soif===1832###eoif===1841###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");return 1; /* error computing matrix */
    }
else {
AKA_mark("lis===-898-###sois===-36107-###eois===-36107155-###lif===-32-###soif===-###eoif===-1821-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");
}
    /* output absolute whitepoint of the original RGB model */
    AKA_mark("lis===903###sois===36388###eois===36413###lif===37###soif===1947###eoif===1972###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");whitepoint[0] = white[0];
    AKA_mark("lis===904###sois===36419###eois===36444###lif===38###soif===1978###eoif===2003###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");whitepoint[1] = white[1];
    AKA_mark("lis===905###sois===36450###eois===36475###lif===39###soif===2009###eoif===2034###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");whitepoint[2] = white[2];
  } else {
    /* output the unity matrix, for doing no transform */
    AKA_mark("lis===908###sois===36552###eois===36575###lif===42###soif===2111###eoif===2134###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");m[0] = m[4] = m[8] = 1;
    AKA_mark("lis===909###sois===36581###eois===36625###lif===43###soif===2140###eoif===2184###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");m[1] = m[2] = m[3] = m[5] = m[6] = m[7] = 0;
    /* grayscale, don't do anything. That means we are implicitely using equal energy whitepoint "E", indicate
    this to the output. */
    AKA_mark("lis===912###sois===36771###eois===36821###lif===46###soif===2330###eoif===2380###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");whitepoint[0] = whitepoint[1] = whitepoint[2] = 1;
  }
  AKA_mark("lis===914###sois===36830###eois===36839###lif===48###soif===2389###eoif===2398###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getICCChrm(float[9],float[3],LodePNGICC const*)");return 0; /* success */
}

/* Outputs whitepoint and matrix to go from the icc or info profile (depending on what was in the PNG) to XYZ,
without applying any (rendering intent related) whitepoint adaptation */
/** Instrumented function getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*) */
static unsigned getChrm(float m[9], float whitepoint[3], unsigned use_icc,
                        const LodePNGICC* icc, const LodePNGInfo* info) /* << Aka begin of function unsigned getChrm(float m[9], float whitepoint[3], unsigned use_icc,
                        const LodePNGICC* icc, const LodePNGInfo* info) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.getChrm.37062.stub"

  AKA_mark("lis===921###sois===37199###eois===37208###lif===2###soif===153###eoif===162###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");size_t i;
  if(AKA_mark("lis===922###sois===37215###eois===37222###lif===3###soif===169###eoif===176###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)") && (AKA_mark("lis===922###sois===37215###eois===37222###lif===3###soif===169###eoif===176###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)") && (use_icc))) {
    if(AKA_mark("lis===923###sois===37234###eois===37264###lif===4###soif===188###eoif===218###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)") && (AKA_mark("lis===923###sois===37234###eois===37264###lif===4###soif===188###eoif===218###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)") && (getICCChrm(m, whitepoint, icc)))) {
AKA_mark("lis===923###sois===37266###eois===37275###lif===4###soif===220###eoif===229###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");return 1;
}

else {
AKA_mark("lis===-923-###sois===-37234-###eois===-3723430-###lif===-4-###soif===-###eoif===-218-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");
}  /* error in the matrix computations */
  } else {
if(AKA_mark("lis===924###sois===37329###eois===37370###lif===5###soif===283###eoif===324###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)") && ((AKA_mark("lis===924###sois===37329###eois===37347###lif===5###soif===283###eoif===301###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)") && (info->chrm_defined)) && (AKA_mark("lis===924###sois===37351###eois===37370###lif===5###soif===305###eoif===324###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)") && (!info->srgb_defined)))) {
    AKA_mark("lis===925###sois===37379###eois===37458###lif===6###soif===333###eoif===412###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");float wx = info->chrm_white_x / 100000.0f, wy = info->chrm_white_y / 100000.0f;
    AKA_mark("lis===926###sois===37464###eois===37539###lif===7###soif===418###eoif===493###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");float rx = info->chrm_red_x / 100000.0f, ry = info->chrm_red_y / 100000.0f;
    AKA_mark("lis===927###sois===37545###eois===37624###lif===8###soif===499###eoif===578###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");float gx = info->chrm_green_x / 100000.0f, gy = info->chrm_green_y / 100000.0f;
    AKA_mark("lis===928###sois===37630###eois===37707###lif===9###soif===584###eoif===661###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");float bx = info->chrm_blue_x / 100000.0f, by = info->chrm_blue_y / 100000.0f;
    if(AKA_mark("lis===929###sois===37716###eois===37766###lif===10###soif===670###eoif===720###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)") && (AKA_mark("lis===929###sois===37716###eois===37766###lif===10###soif===670###eoif===720###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)") && (getChrmMatrixXY(m, wx, wy, rx, ry, gx, gy, bx, by)))) {
AKA_mark("lis===929###sois===37768###eois===37777###lif===10###soif===722###eoif===731###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");return 1;
}

else {
AKA_mark("lis===-929-###sois===-37716-###eois===-3771650-###lif===-10-###soif===-###eoif===-720-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");
} /* returns if error */
    /* Output whitepoint, xyY to XYZ: */
    AKA_mark("lis===931###sois===37848###eois===37872###lif===12###soif===802###eoif===826###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");whitepoint[0] = wx / wy;
    AKA_mark("lis===932###sois===37878###eois===37896###lif===13###soif===832###eoif===850###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");whitepoint[1] = 1;
    AKA_mark("lis===933###sois===37902###eois===37937###lif===14###soif===856###eoif===891###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");whitepoint[2] = (1 - wx - wy) / wy;
  } else {
    /* the standard linear sRGB to XYZ matrix */
    AKA_mark("lis===936###sois===38005###eois===38177###lif===17###soif===959###eoif===1131###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");static const float srgb[9] = {
        0.4124564f, 0.3575761f, 0.1804375f,
        0.2126729f, 0.7151522f, 0.0721750f,
        0.0193339f, 0.1191920f, 0.9503041f
    };
    int AKA_BLOCK_LOOP_38183 = 0;
    AKA_mark("lis===941###sois===38187###eois===38193###lif===22###soif===1141###eoif===1147###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");
for(i = 0; AKA_mark("lis===941###sois===38194###eois===38199###lif===22###soif===1148###eoif===1153###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)") && (AKA_mark("lis===941###sois===38194###eois===38199###lif===22###soif===1148###eoif===1153###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)") && (i < 9)); ({AKA_mark("lis===941###sois===38201###eois===38204###lif===22###soif===1155###eoif===1158###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");i++;})) {
AKA_mark("lis===941###sois===38206###eois===38221###lif===22###soif===1160###eoif===1175###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");m[i] = srgb[i];
}

    /* sRGB's whitepoint xyY "0.3127,0.3290,1" in XYZ: */
    AKA_mark("lis===943###sois===38286###eois===38322###lif===24###soif===1240###eoif===1276###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");whitepoint[0] = 0.9504559270516716f;
    AKA_mark("lis===944###sois===38328###eois===38346###lif===25###soif===1282###eoif===1300###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");whitepoint[1] = 1;
    AKA_mark("lis===945###sois===38352###eois===38388###lif===26###soif===1306###eoif===1342###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");whitepoint[2] = 1.0890577507598784f;
  }
}

  AKA_mark("lis===947###sois===38397###eois===38406###lif===28###soif===1351###eoif===1360###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\getChrm(float[9],float[3],unsigned,LodePNGICC const*,LodePNGInfo const*)");return 0;
}

/* Returns whether the color chunks in info represent the default PNG sRGB,
which is when either no colorometry fields are present at all, or an srgb
field or chrm/gama field with default values are present.
ICC chunks representing sRGB are currently considered not the same. */
/** Instrumented function isSRGB(LodePNGInfo const*) */
static unsigned isSRGB(const LodePNGInfo* info) /* << Aka begin of function unsigned isSRGB(const LodePNGInfo* info) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.isSRGB.38712.stub"

  if(AKA_mark("lis===955###sois===38752###eois===38757###lif===1###soif===56###eoif===61###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (AKA_mark("lis===955###sois===38752###eois===38757###lif===1###soif===56###eoif===61###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (!info))) {
AKA_mark("lis===955###sois===38759###eois===38768###lif===1###soif===63###eoif===72###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");return 1;
}

else {
AKA_mark("lis===-955-###sois===-38752-###eois===-387525-###lif===-1-###soif===-###eoif===-61-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");
} /* the default is considered sRGB. */

  /* TODO: support some ICC profiles that represent sRGB too. Tricky due to
  possible slight deviations and many ways of representing its gamma function. */
  if(AKA_mark("lis===959###sois===38975###eois===38993###lif===5###soif===279###eoif===297###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (AKA_mark("lis===959###sois===38975###eois===38993###lif===5###soif===279###eoif===297###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (info->iccp_defined))) {
AKA_mark("lis===959###sois===38995###eois===39004###lif===5###soif===299###eoif===308###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");return 0;
}

else {
AKA_mark("lis===-959-###sois===-38975-###eois===-3897518-###lif===-5-###soif===-###eoif===-297-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");
}

  if(AKA_mark("lis===961###sois===39013###eois===39031###lif===7###soif===317###eoif===335###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (AKA_mark("lis===961###sois===39013###eois===39031###lif===7###soif===317###eoif===335###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (info->srgb_defined))) {
AKA_mark("lis===961###sois===39033###eois===39042###lif===7###soif===337###eoif===346###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");return 1;
}

else {
AKA_mark("lis===-961-###sois===-39013-###eois===-3901318-###lif===-7-###soif===-###eoif===-335-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");
}

  /* The gamma chunk is unable to represent sRGB's two-part gamma, so cannot
  be sRGB, even if it's the default 45455. */
  if(AKA_mark("lis===965###sois===39176###eois===39194###lif===11###soif===480###eoif===498###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (AKA_mark("lis===965###sois===39176###eois===39194###lif===11###soif===480###eoif===498###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (info->gama_defined))) {
AKA_mark("lis===965###sois===39196###eois===39205###lif===11###soif===500###eoif===509###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");return 0;
}

else {
AKA_mark("lis===-965-###sois===-39176-###eois===-3917618-###lif===-11-###soif===-###eoif===-498-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");
}

  if(AKA_mark("lis===967###sois===39214###eois===39232###lif===13###soif===518###eoif===536###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (AKA_mark("lis===967###sois===39214###eois===39232###lif===13###soif===518###eoif===536###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (info->chrm_defined))) {
    if(AKA_mark("lis===968###sois===39244###eois===39302###lif===14###soif===548###eoif===606###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && ((AKA_mark("lis===968###sois===39244###eois===39271###lif===14###soif===548###eoif===575###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (info->chrm_white_x != 31270)) || (AKA_mark("lis===968###sois===39275###eois===39302###lif===14###soif===579###eoif===606###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (info->chrm_white_y != 32900)))) {
AKA_mark("lis===968###sois===39304###eois===39313###lif===14###soif===608###eoif===617###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");return 0;
}

else {
AKA_mark("lis===-968-###sois===-39244-###eois===-3924458-###lif===-14-###soif===-###eoif===-606-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");
}
    if(AKA_mark("lis===969###sois===39322###eois===39376###lif===15###soif===626###eoif===680###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && ((AKA_mark("lis===969###sois===39322###eois===39347###lif===15###soif===626###eoif===651###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (info->chrm_red_x != 64000)) || (AKA_mark("lis===969###sois===39351###eois===39376###lif===15###soif===655###eoif===680###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (info->chrm_red_y != 33000)))) {
AKA_mark("lis===969###sois===39378###eois===39387###lif===15###soif===682###eoif===691###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");return 0;
}

else {
AKA_mark("lis===-969-###sois===-39322-###eois===-3932254-###lif===-15-###soif===-###eoif===-680-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");
}
    if(AKA_mark("lis===970###sois===39396###eois===39454###lif===16###soif===700###eoif===758###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && ((AKA_mark("lis===970###sois===39396###eois===39423###lif===16###soif===700###eoif===727###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (info->chrm_green_x != 30000)) || (AKA_mark("lis===970###sois===39427###eois===39454###lif===16###soif===731###eoif===758###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (info->chrm_green_y != 60000)))) {
AKA_mark("lis===970###sois===39456###eois===39465###lif===16###soif===760###eoif===769###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");return 0;
}

else {
AKA_mark("lis===-970-###sois===-39396-###eois===-3939658-###lif===-16-###soif===-###eoif===-758-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");
}
    if(AKA_mark("lis===971###sois===39474###eois===39529###lif===17###soif===778###eoif===833###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && ((AKA_mark("lis===971###sois===39474###eois===39500###lif===17###soif===778###eoif===804###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (info->chrm_blue_x != 15000)) || (AKA_mark("lis===971###sois===39504###eois===39529###lif===17###soif===808###eoif===833###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)") && (info->chrm_blue_y != 6000)))) {
AKA_mark("lis===971###sois===39531###eois===39540###lif===17###soif===835###eoif===844###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");return 0;
}

else {
AKA_mark("lis===-971-###sois===-39474-###eois===-3947455-###lif===-17-###soif===-###eoif===-833-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");
}
  }
else {
AKA_mark("lis===-967-###sois===-39214-###eois===-3921418-###lif===-13-###soif===-###eoif===-536-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");
}

  AKA_mark("lis===974###sois===39551###eois===39560###lif===20###soif===855###eoif===864###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\isSRGB(LodePNGInfo const*)");return 1;
}

/* Checks whether the RGB models are equal (chromaticities, ...). The raw byte
format is allowed to be different. Input pointers are allowed to be null,
they then represent the default PNG sRGB (same as having no color model
chunks at all or an srgb chunk in the PNG) */
/** Instrumented function modelsEqual(LodePNGState const*,LodePNGState const*) */
static unsigned modelsEqual(const LodePNGState* state_a,
                            const LodePNGState* state_b) /* << Aka begin of function unsigned modelsEqual(const LodePNGState* state_a,
                            const LodePNGState* state_b) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.modelsEqual.39858.stub"

  AKA_mark("lis===983###sois===39962###eois===39971###lif===2###soif===120###eoif===129###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");size_t i;
  AKA_mark("lis===984###sois===39975###eois===40031###lif===3###soif===133###eoif===189###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");const LodePNGInfo* a = state_a ? &state_a->info_png : 0;
  AKA_mark("lis===985###sois===40035###eois===40091###lif===4###soif===193###eoif===249###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");const LodePNGInfo* b = state_b ? &state_b->info_png : 0;
  AKA_mark("lis===986###sois===40095###eois===40123###lif===5###soif===253###eoif===281###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");unsigned a_srgb = isSRGB(a);
  AKA_mark("lis===987###sois===40127###eois===40155###lif===6###soif===285###eoif===313###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");unsigned b_srgb = isSRGB(b);
  if(AKA_mark("lis===988###sois===40162###eois===40178###lif===7###soif===320###eoif===336###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===988###sois===40162###eois===40178###lif===7###soif===320###eoif===336###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a_srgb != b_srgb))) {
AKA_mark("lis===988###sois===40180###eois===40189###lif===7###soif===338###eoif===347###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-988-###sois===-40162-###eois===-4016216-###lif===-7-###soif===-###eoif===-336-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
  if(AKA_mark("lis===989###sois===40196###eois===40212###lif===8###soif===354###eoif===370###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && ((AKA_mark("lis===989###sois===40196###eois===40202###lif===8###soif===354###eoif===360###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a_srgb)) && (AKA_mark("lis===989###sois===40206###eois===40212###lif===8###soif===364###eoif===370###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (b_srgb)))) {
AKA_mark("lis===989###sois===40214###eois===40223###lif===8###soif===372###eoif===381###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 1;
}

else {
AKA_mark("lis===-989-###sois===-40196-###eois===-4019616-###lif===-8-###soif===-###eoif===-370-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
  /* now a and b are both non-sRGB, and both guaranteed to be non-NULL: only
  non-NULL can represent a different color model than sRGB. */
  if(AKA_mark("lis===992###sois===40372###eois===40406###lif===11###soif===530###eoif===564###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===992###sois===40372###eois===40406###lif===11###soif===530###eoif===564###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->iccp_defined != b->iccp_defined))) {
AKA_mark("lis===992###sois===40408###eois===40417###lif===11###soif===566###eoif===575###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-992-###sois===-40372-###eois===-4037234-###lif===-11-###soif===-###eoif===-564-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
  if(AKA_mark("lis===993###sois===40424###eois===40439###lif===12###soif===582###eoif===597###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===993###sois===40424###eois===40439###lif===12###soif===582###eoif===597###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->iccp_defined))) {
    if(AKA_mark("lis===994###sois===40451###eois===40495###lif===13###soif===609###eoif===653###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===994###sois===40451###eois===40495###lif===13###soif===609###eoif===653###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->iccp_profile_size != b->iccp_profile_size))) {
AKA_mark("lis===994###sois===40497###eois===40506###lif===13###soif===655###eoif===664###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-994-###sois===-40451-###eois===-4045144-###lif===-13-###soif===-###eoif===-653-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
    /* TODO: return equal in more cases, such as when two ICC profiles that are
    not byte-for-byte equal, but represent the same color model. */
    int AKA_BLOCK_LOOP_40662 = 0;
    AKA_mark("lis===997###sois===40666###eois===40672###lif===16###soif===824###eoif===830###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
for(i = 0; AKA_mark("lis===997###sois===40673###eois===40697###lif===16###soif===831###eoif===855###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===997###sois===40673###eois===40697###lif===16###soif===831###eoif===855###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (i < a->iccp_profile_size)); ({AKA_mark("lis===997###sois===40699###eois===40702###lif===16###soif===857###eoif===860###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");i++;})) {
        AKA_BLOCK_LOOP_40662++;
        if (AKA_BLOCK_LOOP_40662 > 1000) {
            //break;
        }
      if(AKA_mark("lis===998###sois===40716###eois===40756###lif===17###soif===874###eoif===914###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===998###sois===40716###eois===40756###lif===17###soif===874###eoif===914###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->iccp_profile[i] != b->iccp_profile[i]))) {
AKA_mark("lis===998###sois===40758###eois===40767###lif===17###soif===916###eoif===925###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-998-###sois===-40716-###eois===-4071640-###lif===-17-###soif===-###eoif===-914-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
    }
    /* since the ICC model overrides gamma and chrm, those can be ignored. */
    /* TODO: this doesn't cover the case where the ICC profile is invalid */
    AKA_mark("lis===1002###sois===40937###eois===40946###lif===21###soif===1095###eoif===1104###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 1;
  }
else {
AKA_mark("lis===-993-###sois===-40424-###eois===-4042415-###lif===-12-###soif===-###eoif===-597-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}

  if(AKA_mark("lis===1005###sois===40960###eois===40994###lif===24###soif===1118###eoif===1152###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1005###sois===40960###eois===40994###lif===24###soif===1118###eoif===1152###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->srgb_defined != b->srgb_defined))) {
AKA_mark("lis===1005###sois===40996###eois===41005###lif===24###soif===1154###eoif===1163###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-1005-###sois===-40960-###eois===-4096034-###lif===-24-###soif===-###eoif===-1152-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
  if(AKA_mark("lis===1006###sois===41012###eois===41027###lif===25###soif===1170###eoif===1185###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1006###sois===41012###eois===41027###lif===25###soif===1170###eoif===1185###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->srgb_defined))) {
    /* since the sRGB model overrides gamma and chrm, those can be ignored.
    srgb_intent not checked since the conversion ignores it */
    AKA_mark("lis===1009###sois===41177###eois===41186###lif===28###soif===1335###eoif===1344###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 1;
  }
else {
AKA_mark("lis===-1006-###sois===-41012-###eois===-4101215-###lif===-25-###soif===-###eoif===-1185-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}

  if(AKA_mark("lis===1012###sois===41200###eois===41234###lif===31###soif===1358###eoif===1392###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1012###sois===41200###eois===41234###lif===31###soif===1358###eoif===1392###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->gama_defined != b->gama_defined))) {
AKA_mark("lis===1012###sois===41236###eois===41245###lif===31###soif===1394###eoif===1403###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-1012-###sois===-41200-###eois===-4120034-###lif===-31-###soif===-###eoif===-1392-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
  if(AKA_mark("lis===1013###sois===41252###eois===41267###lif===32###soif===1410###eoif===1425###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1013###sois===41252###eois===41267###lif===32###soif===1410###eoif===1425###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->gama_defined))) {
    if(AKA_mark("lis===1014###sois===41279###eois===41309###lif===33###soif===1437###eoif===1467###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1014###sois===41279###eois===41309###lif===33###soif===1437###eoif===1467###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->gama_gamma != b->gama_gamma))) {
AKA_mark("lis===1014###sois===41311###eois===41320###lif===33###soif===1469###eoif===1478###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-1014-###sois===-41279-###eois===-4127930-###lif===-33-###soif===-###eoif===-1467-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
  }
else {
AKA_mark("lis===-1013-###sois===-41252-###eois===-4125215-###lif===-32-###soif===-###eoif===-1425-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}

  if(AKA_mark("lis===1017###sois===41334###eois===41368###lif===36###soif===1492###eoif===1526###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1017###sois===41334###eois===41368###lif===36###soif===1492###eoif===1526###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->chrm_defined != b->chrm_defined))) {
AKA_mark("lis===1017###sois===41370###eois===41379###lif===36###soif===1528###eoif===1537###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-1017-###sois===-41334-###eois===-4133434-###lif===-36-###soif===-###eoif===-1526-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
  if(AKA_mark("lis===1018###sois===41386###eois===41401###lif===37###soif===1544###eoif===1559###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1018###sois===41386###eois===41401###lif===37###soif===1544###eoif===1559###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->chrm_defined))) {
    if(AKA_mark("lis===1019###sois===41413###eois===41447###lif===38###soif===1571###eoif===1605###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1019###sois===41413###eois===41447###lif===38###soif===1571###eoif===1605###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->chrm_white_x != b->chrm_white_x))) {
AKA_mark("lis===1019###sois===41449###eois===41458###lif===38###soif===1607###eoif===1616###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-1019-###sois===-41413-###eois===-4141334-###lif===-38-###soif===-###eoif===-1605-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
    if(AKA_mark("lis===1020###sois===41467###eois===41501###lif===39###soif===1625###eoif===1659###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1020###sois===41467###eois===41501###lif===39###soif===1625###eoif===1659###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->chrm_white_y != b->chrm_white_y))) {
AKA_mark("lis===1020###sois===41503###eois===41512###lif===39###soif===1661###eoif===1670###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-1020-###sois===-41467-###eois===-4146734-###lif===-39-###soif===-###eoif===-1659-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
    if(AKA_mark("lis===1021###sois===41521###eois===41551###lif===40###soif===1679###eoif===1709###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1021###sois===41521###eois===41551###lif===40###soif===1679###eoif===1709###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->chrm_red_x != b->chrm_red_x))) {
AKA_mark("lis===1021###sois===41553###eois===41562###lif===40###soif===1711###eoif===1720###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-1021-###sois===-41521-###eois===-4152130-###lif===-40-###soif===-###eoif===-1709-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
    if(AKA_mark("lis===1022###sois===41571###eois===41601###lif===41###soif===1729###eoif===1759###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1022###sois===41571###eois===41601###lif===41###soif===1729###eoif===1759###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->chrm_red_y != b->chrm_red_y))) {
AKA_mark("lis===1022###sois===41603###eois===41612###lif===41###soif===1761###eoif===1770###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-1022-###sois===-41571-###eois===-4157130-###lif===-41-###soif===-###eoif===-1759-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
    if(AKA_mark("lis===1023###sois===41621###eois===41655###lif===42###soif===1779###eoif===1813###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1023###sois===41621###eois===41655###lif===42###soif===1779###eoif===1813###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->chrm_green_x != b->chrm_green_x))) {
AKA_mark("lis===1023###sois===41657###eois===41666###lif===42###soif===1815###eoif===1824###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-1023-###sois===-41621-###eois===-4162134-###lif===-42-###soif===-###eoif===-1813-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
    if(AKA_mark("lis===1024###sois===41675###eois===41709###lif===43###soif===1833###eoif===1867###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1024###sois===41675###eois===41709###lif===43###soif===1833###eoif===1867###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->chrm_green_y != b->chrm_green_y))) {
AKA_mark("lis===1024###sois===41711###eois===41720###lif===43###soif===1869###eoif===1878###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-1024-###sois===-41675-###eois===-4167534-###lif===-43-###soif===-###eoif===-1867-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
    if(AKA_mark("lis===1025###sois===41729###eois===41761###lif===44###soif===1887###eoif===1919###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1025###sois===41729###eois===41761###lif===44###soif===1887###eoif===1919###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->chrm_blue_x != b->chrm_blue_x))) {
AKA_mark("lis===1025###sois===41763###eois===41772###lif===44###soif===1921###eoif===1930###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-1025-###sois===-41729-###eois===-4172932-###lif===-44-###soif===-###eoif===-1919-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
    if(AKA_mark("lis===1026###sois===41781###eois===41813###lif===45###soif===1939###eoif===1971###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (AKA_mark("lis===1026###sois===41781###eois===41813###lif===45###soif===1939###eoif===1971###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)") && (a->chrm_blue_y != b->chrm_blue_y))) {
AKA_mark("lis===1026###sois===41815###eois===41824###lif===45###soif===1973###eoif===1982###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 0;
}

else {
AKA_mark("lis===-1026-###sois===-41781-###eois===-4178132-###lif===-45-###soif===-###eoif===-1971-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}
  }
else {
AKA_mark("lis===-1018-###sois===-41386-###eois===-4138615-###lif===-37-###soif===-###eoif===-1559-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");
}

  AKA_mark("lis===1029###sois===41835###eois===41844###lif===48###soif===1993###eoif===2002###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\modelsEqual(LodePNGState const*,LodePNGState const*)");return 1;
}

/* Converts in-place. Does not clamp. Do not use for integer input, make table instead there. */
/** Instrumented function convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*) */
static unsigned convertToXYZ_gamma(float* out, const float* in, unsigned w, unsigned h,
                                  const LodePNGInfo* info, unsigned use_icc, const LodePNGICC* icc) /* << Aka begin of function unsigned convertToXYZ_gamma(float* out, const float* in, unsigned w, unsigned h,
                                  const LodePNGInfo* info, unsigned use_icc, const LodePNGICC* icc) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.convertToXYZ_gamma.41965.stub"

  AKA_mark("lis===1035###sois===42143###eois===42158###lif===2###soif===194###eoif===209###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");size_t i, c, n;
  if(AKA_mark("lis===1036###sois===42165###eois===42205###lif===3###soif===216###eoif===256###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1036###sois===42165###eois===42205###lif===3###soif===216###eoif===256###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (lodepng_mulofl((size_t)w, (size_t)h, &n)))) {
AKA_mark("lis===1036###sois===42207###eois===42217###lif===3###soif===258###eoif===268###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");return 92;
}

else {
AKA_mark("lis===-1036-###sois===-42165-###eois===-4216540-###lif===-3-###soif===-###eoif===-256-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
}
  int AKA_BLOCK_LOOP_42221 = 0;
    AKA_mark("lis===1037###sois===42225###eois===42231###lif===4###soif===276###eoif===282###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(i = 0; AKA_mark("lis===1037###sois===42232###eois===42241###lif===4###soif===283###eoif===292###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1037###sois===42232###eois===42241###lif===4###soif===283###eoif===292###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (i < n * 4)); ({AKA_mark("lis===1037###sois===42243###eois===42246###lif===4###soif===294###eoif===297###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");i++;})) {
        AKA_BLOCK_LOOP_42221++;
        if (AKA_BLOCK_LOOP_42221 > 1000) {
            //break;
        }
    AKA_mark("lis===1038###sois===42255###eois===42270###lif===5###soif===306###eoif===321###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");out[i] = in[i];
  }
  if(AKA_mark("lis===1040###sois===42282###eois===42289###lif===7###soif===333###eoif===340###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1040###sois===42282###eois===42289###lif===7###soif===333###eoif===340###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (use_icc))) {
    int AKA_BLOCK_LOOP_42298 = 0;
    AKA_mark("lis===1041###sois===42302###eois===42308###lif===8###soif===353###eoif===359###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(i = 0; AKA_mark("lis===1041###sois===42309###eois===42314###lif===8###soif===360###eoif===365###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1041###sois===42309###eois===42314###lif===8###soif===360###eoif===365###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (i < n)); ({AKA_mark("lis===1041###sois===42316###eois===42319###lif===8###soif===367###eoif===370###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");i++;})) {
        AKA_BLOCK_LOOP_42298++;
        if (AKA_BLOCK_LOOP_42298 > 1000) {
            //break;
        }
      int AKA_BLOCK_LOOP_42330 = 0;
    AKA_mark("lis===1042###sois===42334###eois===42340###lif===9###soif===385###eoif===391###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(c = 0; AKA_mark("lis===1042###sois===42341###eois===42346###lif===9###soif===392###eoif===397###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1042###sois===42341###eois===42346###lif===9###soif===392###eoif===397###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (c < 3)); ({AKA_mark("lis===1042###sois===42348###eois===42351###lif===9###soif===399###eoif===402###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");c++;})) {
        AKA_BLOCK_LOOP_42330++;
        if (AKA_BLOCK_LOOP_42330 > 1000) {
            //break;
        }
        /* TODO: this is likely very slow */
        AKA_mark("lis===1044###sois===42410###eois===42470###lif===11###soif===461###eoif===521###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");out[i * 4 + c] = iccForwardTRC(&icc->trc[c], in[i * 4 + c]);
      }
    }
  } else {
if(AKA_mark("lis===1047###sois===42500###eois===42541###lif===14###soif===551###eoif===592###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && ((AKA_mark("lis===1047###sois===42500###eois===42518###lif===14###soif===551###eoif===569###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (info->gama_defined)) && (AKA_mark("lis===1047###sois===42522###eois===42541###lif===14###soif===573###eoif===592###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (!info->srgb_defined)))) {
    /* nothing to do if gamma is 1 */
    if(AKA_mark("lis===1049###sois===42592###eois===42618###lif===16###soif===643###eoif===669###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1049###sois===42592###eois===42618###lif===16###soif===643###eoif===669###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (info->gama_gamma != 100000))) {
      AKA_mark("lis===1050###sois===42629###eois===42672###lif===17###soif===680###eoif===723###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");float gamma = 100000.0f / info->gama_gamma;
      int AKA_BLOCK_LOOP_42680 = 0;
    AKA_mark("lis===1051###sois===42684###eois===42690###lif===18###soif===735###eoif===741###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(i = 0; AKA_mark("lis===1051###sois===42691###eois===42696###lif===18###soif===742###eoif===747###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1051###sois===42691###eois===42696###lif===18###soif===742###eoif===747###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (i < n)); ({AKA_mark("lis===1051###sois===42698###eois===42701###lif===18###soif===749###eoif===752###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");i++;})) {
        AKA_BLOCK_LOOP_42680++;
        if (AKA_BLOCK_LOOP_42680 > 1000) {
            //break;
        }
        int AKA_BLOCK_LOOP_42714 = 0;
    AKA_mark("lis===1052###sois===42718###eois===42724###lif===19###soif===769###eoif===775###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(c = 0; AKA_mark("lis===1052###sois===42725###eois===42730###lif===19###soif===776###eoif===781###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1052###sois===42725###eois===42730###lif===19###soif===776###eoif===781###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (c < 3)); ({AKA_mark("lis===1052###sois===42732###eois===42735###lif===19###soif===783###eoif===786###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");c++;})) {
        AKA_BLOCK_LOOP_42714++;
        if (AKA_BLOCK_LOOP_42714 > 1000) {
            //break;
        }
          AKA_mark("lis===1053###sois===42750###eois===42774###lif===20###soif===801###eoif===825###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");float v = in[i * 4 + c];
          AKA_mark("lis===1054###sois===42786###eois===42841###lif===21###soif===837###eoif===892###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");out[i * 4 + c] = (v <= 0) ? v : lodepng_powf(v, gamma);
        }
      }
    }
else {
AKA_mark("lis===-1049-###sois===-42592-###eois===-4259226-###lif===-16-###soif===-###eoif===-669-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
}
  } else {
    int AKA_BLOCK_LOOP_42886 = 0;
    AKA_mark("lis===1059###sois===42890###eois===42896###lif===26###soif===941###eoif===947###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(i = 0; AKA_mark("lis===1059###sois===42897###eois===42902###lif===26###soif===948###eoif===953###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1059###sois===42897###eois===42902###lif===26###soif===948###eoif===953###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (i < n)); ({AKA_mark("lis===1059###sois===42904###eois===42907###lif===26###soif===955###eoif===958###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");i++;})) {
        AKA_BLOCK_LOOP_42886++;
        if (AKA_BLOCK_LOOP_42886 > 1000) {
            //break;
        }
      int AKA_BLOCK_LOOP_42918 = 0;
    AKA_mark("lis===1060###sois===42922###eois===42928###lif===27###soif===973###eoif===979###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(c = 0; AKA_mark("lis===1060###sois===42929###eois===42934###lif===27###soif===980###eoif===985###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1060###sois===42929###eois===42934###lif===27###soif===980###eoif===985###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (c < 3)); ({AKA_mark("lis===1060###sois===42936###eois===42939###lif===27###soif===987###eoif===990###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");c++;})) {
        AKA_BLOCK_LOOP_42918++;
        if (AKA_BLOCK_LOOP_42918 > 1000) {
            //break;
        }
        /* sRGB gamma expand */
        AKA_mark("lis===1062###sois===42985###eois===43009###lif===29###soif===1036###eoif===1060###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");float v = in[i * 4 + c];
        AKA_mark("lis===1063###sois===43019###eois===43110###lif===30###soif===1070###eoif===1161###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");out[i * 4 + c] = (v < 0.04045f) ? (v / 12.92f) : lodepng_powf((v + 0.055f) / 1.055f, 2.4f);
      }
    }
  }
}

  AKA_mark("lis===1067###sois===43135###eois===43144###lif===34###soif===1186###eoif===1195###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");return 0; /* no error */
}

/* Same as convertToXYZ_gamma, but creates a lookup table rather than operating on an image */
/** Instrumented function convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*) */
static void convertToXYZ_gamma_table(float* out, size_t n, size_t c,
                                     const LodePNGInfo* info, unsigned use_icc, const LodePNGICC* icc) /* << Aka begin of function void convertToXYZ_gamma_table(float* out, size_t n, size_t c,
                                     const LodePNGInfo* info, unsigned use_icc, const LodePNGICC* icc) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.convertToXYZ_gamma_table.43274.stub"

  AKA_mark("lis===1073###sois===43440###eois===43449###lif===2###soif===178###eoif===187###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");size_t i;
  AKA_mark("lis===1074###sois===43453###eois===43480###lif===3###soif===191###eoif===218###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");float mul = 1.0f / (n - 1);
  if(AKA_mark("lis===1075###sois===43487###eois===43494###lif===4###soif===225###eoif===232###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1075###sois===43487###eois===43494###lif===4###soif===225###eoif===232###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (use_icc))) {
    int AKA_BLOCK_LOOP_43503 = 0;
    AKA_mark("lis===1076###sois===43507###eois===43513###lif===5###soif===245###eoif===251###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(i = 0; AKA_mark("lis===1076###sois===43514###eois===43519###lif===5###soif===252###eoif===257###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1076###sois===43514###eois===43519###lif===5###soif===252###eoif===257###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (i < n)); ({AKA_mark("lis===1076###sois===43521###eois===43524###lif===5###soif===259###eoif===262###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");i++;})) {
        AKA_BLOCK_LOOP_43503++;
        if (AKA_BLOCK_LOOP_43503 > 1000) {
            //break;
        }
      AKA_mark("lis===1077###sois===43535###eois===43553###lif===6###soif===273###eoif===291###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");float v = i * mul;
      AKA_mark("lis===1078###sois===43561###eois===43601###lif===7###soif===299###eoif===339###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");out[i] = iccForwardTRC(&icc->trc[c], v);
    }
  } else {
if(AKA_mark("lis===1080###sois===43622###eois===43663###lif===9###soif===360###eoif===401###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && ((AKA_mark("lis===1080###sois===43622###eois===43640###lif===9###soif===360###eoif===378###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (info->gama_defined)) && (AKA_mark("lis===1080###sois===43644###eois===43663###lif===9###soif===382###eoif===401###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (!info->srgb_defined)))) {
    /* no power needed if gamma is 1 */
    if(AKA_mark("lis===1082###sois===43716###eois===43742###lif===11###soif===454###eoif===480###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1082###sois===43716###eois===43742###lif===11###soif===454###eoif===480###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (info->gama_gamma == 100000))) {
      int AKA_BLOCK_LOOP_43753 = 0;
    AKA_mark("lis===1083###sois===43757###eois===43763###lif===12###soif===495###eoif===501###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(i = 0; AKA_mark("lis===1083###sois===43764###eois===43769###lif===12###soif===502###eoif===507###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1083###sois===43764###eois===43769###lif===12###soif===502###eoif===507###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (i < n)); ({AKA_mark("lis===1083###sois===43771###eois===43774###lif===12###soif===509###eoif===512###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");i++;})) {
        AKA_BLOCK_LOOP_43753++;
        if (AKA_BLOCK_LOOP_43753 > 1000) {
            //break;
        }
        AKA_mark("lis===1084###sois===43787###eois===43804###lif===13###soif===525###eoif===542###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");out[i] = i * mul;
      }
    } else {
      AKA_mark("lis===1087###sois===43835###eois===43878###lif===16###soif===573###eoif===616###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");float gamma = 100000.0f / info->gama_gamma;
      int AKA_BLOCK_LOOP_43886 = 0;
    AKA_mark("lis===1088###sois===43890###eois===43896###lif===17###soif===628###eoif===634###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(i = 0; AKA_mark("lis===1088###sois===43897###eois===43902###lif===17###soif===635###eoif===640###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1088###sois===43897###eois===43902###lif===17###soif===635###eoif===640###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (i < n)); ({AKA_mark("lis===1088###sois===43904###eois===43907###lif===17###soif===642###eoif===645###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");i++;})) {
        AKA_BLOCK_LOOP_43886++;
        if (AKA_BLOCK_LOOP_43886 > 1000) {
            //break;
        }
        AKA_mark("lis===1089###sois===43920###eois===43938###lif===18###soif===658###eoif===676###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");float v = i * mul;
        AKA_mark("lis===1090###sois===43948###eois===43980###lif===19###soif===686###eoif===718###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");out[i] = lodepng_powf(v, gamma);
      }
    }
  } else {
    int AKA_BLOCK_LOOP_44014 = 0;
    AKA_mark("lis===1094###sois===44018###eois===44024###lif===23###soif===756###eoif===762###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(i = 0; AKA_mark("lis===1094###sois===44025###eois===44030###lif===23###soif===763###eoif===768###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1094###sois===44025###eois===44030###lif===23###soif===763###eoif===768###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (i < n)); ({AKA_mark("lis===1094###sois===44032###eois===44035###lif===23###soif===770###eoif===773###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");i++;})) {
        AKA_BLOCK_LOOP_44014++;
        if (AKA_BLOCK_LOOP_44014 > 1000) {
            //break;
        }
      /* sRGB gamma expand */
      AKA_mark("lis===1096###sois===44077###eois===44095###lif===25###soif===815###eoif===833###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");float v = i * mul;
      AKA_mark("lis===1097###sois===44103###eois===44186###lif===26###soif===841###eoif===924###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_gamma_table(float*,size_t,size_t,LodePNGInfo const*,unsigned,LodePNGICC const*)");out[i] = (v < 0.04045f) ? (v / 12.92f) : lodepng_powf((v + 0.055f) / 1.055f, 2.4f);
    }
  }
}

}

/* In-place */
/** Instrumented function convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3]) */
static unsigned convertToXYZ_chrm(float* im, unsigned w, unsigned h,
                                  const LodePNGInfo* info, unsigned use_icc, const LodePNGICC* icc,
                                  float whitepoint[3]) /* << Aka begin of function unsigned convertToXYZ_chrm(float* im, unsigned w, unsigned h,
                                  const LodePNGInfo* info, unsigned use_icc, const LodePNGICC* icc,
                                  float whitepoint[3]) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.convertToXYZ_chrm.44237.stub"

  AKA_mark("lis===1106###sois===44452###eois===44471###lif===3###soif===231###eoif===250###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");unsigned error = 0;
  AKA_mark("lis===1107###sois===44475###eois===44487###lif===4###soif===254###eoif===266###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");size_t i, n;
  AKA_mark("lis===1108###sois===44491###eois===44502###lif===5###soif===270###eoif===281###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");float m[9]; /* XYZ to linear RGB matrix */
  if(AKA_mark("lis===1109###sois===44540###eois===44580###lif===6###soif===319###eoif===359###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])") && (AKA_mark("lis===1109###sois===44540###eois===44580###lif===6###soif===319###eoif===359###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])") && (lodepng_mulofl((size_t)w, (size_t)h, &n)))) {
AKA_mark("lis===1109###sois===44582###eois===44592###lif===6###soif===361###eoif===371###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");return 92;
}

else {
AKA_mark("lis===-1109-###sois===-44540-###eois===-4454040-###lif===-6-###soif===-###eoif===-359-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");
}

  /* Must be called even for grayscale, to get the correct whitepoint to output */
  AKA_mark("lis===1112###sois===44682###eois===44733###lif===9###soif===461###eoif===512###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");error = getChrm(m, whitepoint, use_icc, icc, info);
  if(AKA_mark("lis===1113###sois===44740###eois===44745###lif===10###soif===519###eoif===524###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])") && (AKA_mark("lis===1113###sois===44740###eois===44745###lif===10###soif===519###eoif===524###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])") && (error))) {
AKA_mark("lis===1113###sois===44747###eois===44760###lif===10###soif===526###eoif===539###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");return error;
}

else {
AKA_mark("lis===-1113-###sois===-44740-###eois===-447405-###lif===-10-###soif===-###eoif===-524-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");
}

  /* Note: no whitepoint adaptation done to m here, because we only do the
  adaptation in convertFromXYZ (we only whitepoint adapt when going to the
  target RGB space, but here we're going from the source RGB space to XYZ) */

  /* Apply the above computed linear-RGB-to-XYZ matrix to the pixels.
  Skip the transform if it's the unit matrix (which is the case if grayscale profile) */
  if(AKA_mark("lis===1121###sois===45163###eois===45195###lif===18###soif===942###eoif===974###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])") && ((AKA_mark("lis===1121###sois===45163###eois===45171###lif===18###soif===942###eoif===950###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])") && (!use_icc)) || (AKA_mark("lis===1121###sois===45175###eois===45195###lif===18###soif===954###eoif===974###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])") && (icc->inputspace == 2)))) {
    int AKA_BLOCK_LOOP_45204 = 0;
    AKA_mark("lis===1122###sois===45208###eois===45214###lif===19###soif===987###eoif===993###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");
for(i = 0; AKA_mark("lis===1122###sois===45215###eois===45220###lif===19###soif===994###eoif===999###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])") && (AKA_mark("lis===1122###sois===45215###eois===45220###lif===19###soif===994###eoif===999###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])") && (i < n)); ({AKA_mark("lis===1122###sois===45222###eois===45225###lif===19###soif===1001###eoif===1004###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");i++;})) {
        AKA_BLOCK_LOOP_45204++;
        if (AKA_BLOCK_LOOP_45204 > 1000) {
            //break;
        }
      AKA_mark("lis===1123###sois===45236###eois===45253###lif===20###soif===1015###eoif===1032###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");size_t j = i * 4;
      AKA_mark("lis===1124###sois===45261###eois===45343###lif===21###soif===1040###eoif===1122###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");mulMatrix(&im[j + 0], &im[j + 1], &im[j + 2], m, im[j + 0], im[j + 1], im[j + 2]);
    }
  }
else {
AKA_mark("lis===-1121-###sois===-45163-###eois===-4516332-###lif===-18-###soif===-###eoif===-974-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");
}

  AKA_mark("lis===1128###sois===45361###eois===45370###lif===25###soif===1140###eoif===1149###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ_chrm(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float[3])");return 0;
}

/** Instrumented function convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*) */
unsigned convertToXYZ(float* out, float whitepoint[3], const unsigned char* in,
                      unsigned w, unsigned h, const LodePNGState* state) /* << Aka begin of function unsigned convertToXYZ(float* out, float whitepoint[3], const unsigned char* in,
                      unsigned w, unsigned h, const LodePNGState* state) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.convertToXYZ.45386.stub"

  AKA_mark("lis===1133###sois===45536###eois===45555###lif===2###soif===159###eoif===178###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");unsigned error = 0;
  AKA_mark("lis===1134###sois===45559###eois===45578###lif===3###soif===182###eoif===201###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");size_t i, n, bytes;
  AKA_mark("lis===1135###sois===45582###eois===45633###lif===4###soif===205###eoif===256###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");const LodePNGColorMode* mode_in = &state->info_raw;
  AKA_mark("lis===1136###sois===45637###eois===45680###lif===5###soif===260###eoif===303###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");const LodePNGInfo* info = &state->info_png;
  AKA_mark("lis===1137###sois===45684###eois===45708###lif===6###soif===307###eoif===331###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");unsigned char* data = 0;
  AKA_mark("lis===1138###sois===45712###eois===45734###lif===7###soif===335###eoif===357###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");float* gammatable = 0;
  AKA_mark("lis===1139###sois===45738###eois===45772###lif===8###soif===361###eoif===395###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");int bit16 = mode_in->bitdepth > 8;
  AKA_mark("lis===1140###sois===45776###eois===45809###lif===9###soif===399###eoif===432###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");size_t num = bit16 ? 65536 : 256;
  AKA_mark("lis===1141###sois===45813###eois===45891###lif===10###soif===436###eoif===514###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");LodePNGColorMode tempmode = lodepng_color_mode_make(LCT_RGBA, bit16 ? 16 : 8);

  AKA_mark("lis===1143###sois===45897###eois===45918###lif===12###soif===520###eoif===541###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");unsigned use_icc = 0;
  AKA_mark("lis===1144###sois===45922###eois===45937###lif===13###soif===545###eoif===560###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");LodePNGICC icc;
  AKA_mark("lis===1145###sois===45941###eois===45964###lif===14###soif===564###eoif===587###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");lodepng_icc_init(&icc);
  if(AKA_mark("lis===1146###sois===45971###eois===45989###lif===15###soif===594###eoif===612###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1146###sois===45971###eois===45989###lif===15###soif===594###eoif===612###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (info->iccp_defined))) {
    AKA_mark("lis===1147###sois===45998###eois===46066###lif===16###soif===621###eoif===689###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");error = parseICC(&icc, info->iccp_profile, info->iccp_profile_size);
    if(AKA_mark("lis===1148###sois===46075###eois===46080###lif===17###soif===698###eoif===703###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1148###sois===46075###eois===46080###lif===17###soif===698###eoif===703###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (error))) {
AKA_mark("lis===1148###sois===46082###eois===46095###lif===17###soif===705###eoif===718###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");goto cleanup;
}

else {
AKA_mark("lis===-1148-###sois===-46075-###eois===-460755-###lif===-17-###soif===-###eoif===-703-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");
} /* corrupted ICC profile */
    AKA_mark("lis===1149###sois===46129###eois===46157###lif===18###soif===752###eoif===780###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");use_icc = validateICC(&icc);
  }
else {
AKA_mark("lis===-1146-###sois===-45971-###eois===-4597118-###lif===-15-###soif===-###eoif===-612-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");
}

  if(AKA_mark("lis===1152###sois===46171###eois===46211###lif===21###soif===794###eoif===834###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1152###sois===46171###eois===46211###lif===21###soif===794###eoif===834###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (lodepng_mulofl((size_t)w, (size_t)h, &n)))) {
AKA_mark("lis===1152###sois===46213###eois===46224###lif===21###soif===836###eoif===847###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");error = 92;
}

else {
AKA_mark("lis===-1152-###sois===-46171-###eois===-4617140-###lif===-21-###soif===-###eoif===-834-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");
}
  if(AKA_mark("lis===1153###sois===46231###eois===46236###lif===22###soif===854###eoif===859###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1153###sois===46231###eois===46236###lif===22###soif===854###eoif===859###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (error))) {
AKA_mark("lis===1153###sois===46238###eois===46251###lif===22###soif===861###eoif===874###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");goto cleanup;
}

else {
AKA_mark("lis===-1153-###sois===-46231-###eois===-462315-###lif===-22-###soif===-###eoif===-859-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");
}
  if(AKA_mark("lis===1154###sois===46258###eois===46298###lif===23###soif===881###eoif===921###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1154###sois===46258###eois===46298###lif===23###soif===881###eoif===921###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (lodepng_mulofl(n, bit16 ? 8 : 4, &bytes)))) {
AKA_mark("lis===1154###sois===46300###eois===46311###lif===23###soif===923###eoif===934###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");error = 92;
}

else {
AKA_mark("lis===-1154-###sois===-46258-###eois===-4625840-###lif===-23-###soif===-###eoif===-921-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");
}
  if(AKA_mark("lis===1155###sois===46318###eois===46323###lif===24###soif===941###eoif===946###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1155###sois===46318###eois===46323###lif===24###soif===941###eoif===946###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (error))) {
AKA_mark("lis===1155###sois===46325###eois===46338###lif===24###soif===948###eoif===961###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");goto cleanup;
}

else {
AKA_mark("lis===-1155-###sois===-46318-###eois===-463185-###lif===-24-###soif===-###eoif===-946-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");
}

  AKA_mark("lis===1157###sois===46344###eois===46389###lif===26###soif===967###eoif===1012###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");data = (unsigned char*)lodepng_malloc(bytes);
  AKA_mark("lis===1158###sois===46393###eois===46453###lif===27###soif===1016###eoif===1076###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");error = lodepng_convert(data, in, &tempmode, mode_in, w, h);
  if(AKA_mark("lis===1159###sois===46460###eois===46465###lif===28###soif===1083###eoif===1088###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1159###sois===46460###eois===46465###lif===28###soif===1083###eoif===1088###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (error))) {
AKA_mark("lis===1159###sois===46467###eois===46480###lif===28###soif===1090###eoif===1103###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");goto cleanup;
}

else {
AKA_mark("lis===-1159-###sois===-46460-###eois===-464605-###lif===-28-###soif===-###eoif===-1088-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");
}

  /* Handle transfer function */
  {
    AKA_mark("lis===1163###sois===46527###eois===46547###lif===32###soif===1150###eoif===1170###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");float* gammatable_r;
    AKA_mark("lis===1164###sois===46553###eois===46573###lif===33###soif===1176###eoif===1196###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");float* gammatable_g;
    AKA_mark("lis===1165###sois===46579###eois===46599###lif===34###soif===1202###eoif===1222###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");float* gammatable_b;

    /* RGB ICC, can have three different transfer functions */
    if(AKA_mark("lis===1168###sois===46674###eois===46704###lif===37###soif===1297###eoif===1327###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && ((AKA_mark("lis===1168###sois===46674###eois===46681###lif===37###soif===1297###eoif===1304###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (use_icc)) && (AKA_mark("lis===1168###sois===46685###eois===46704###lif===37###soif===1308###eoif===1327###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (icc.inputspace == 2)))) {
      AKA_mark("lis===1169###sois===46715###eois===46776###lif===38###soif===1338###eoif===1399###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");gammatable = (float*)lodepng_malloc(num * 3 * sizeof(float));
      AKA_mark("lis===1170###sois===46784###eois===46820###lif===39###soif===1407###eoif===1443###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");gammatable_r = &gammatable[num * 0];
      AKA_mark("lis===1171###sois===46828###eois===46864###lif===40###soif===1451###eoif===1487###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");gammatable_g = &gammatable[num * 1];
      AKA_mark("lis===1172###sois===46872###eois===46908###lif===41###soif===1495###eoif===1531###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");gammatable_b = &gammatable[num * 2];
      AKA_mark("lis===1173###sois===46916###eois===46984###lif===42###soif===1539###eoif===1607###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");convertToXYZ_gamma_table(gammatable_r, num, 0, info, use_icc, &icc);
      AKA_mark("lis===1174###sois===46992###eois===47060###lif===43###soif===1615###eoif===1683###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");convertToXYZ_gamma_table(gammatable_g, num, 1, info, use_icc, &icc);
      AKA_mark("lis===1175###sois===47068###eois===47136###lif===44###soif===1691###eoif===1759###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");convertToXYZ_gamma_table(gammatable_b, num, 2, info, use_icc, &icc);
    } else {
      AKA_mark("lis===1177###sois===47158###eois===47215###lif===46###soif===1781###eoif===1838###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");gammatable = (float*)lodepng_malloc(num * sizeof(float));
      AKA_mark("lis===1178###sois===47223###eois===47279###lif===47###soif===1846###eoif===1902###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");gammatable_r = gammatable_g = gammatable_b = gammatable;
      AKA_mark("lis===1179###sois===47287###eois===47353###lif===48###soif===1910###eoif===1976###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");convertToXYZ_gamma_table(gammatable, num, 0, info, use_icc, &icc);
    }

    if(AKA_mark("lis===1182###sois===47371###eois===47376###lif===51###soif===1994###eoif===1999###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1182###sois===47371###eois===47376###lif===51###soif===1994###eoif===1999###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (bit16))) {
      int AKA_BLOCK_LOOP_47387 = 0;
    AKA_mark("lis===1183###sois===47391###eois===47397###lif===52###soif===2014###eoif===2020###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");
for(i = 0; AKA_mark("lis===1183###sois===47398###eois===47403###lif===52###soif===2021###eoif===2026###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1183###sois===47398###eois===47403###lif===52###soif===2021###eoif===2026###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (i < n)); ({AKA_mark("lis===1183###sois===47405###eois===47408###lif===52###soif===2028###eoif===2031###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");i++;})) {
        AKA_BLOCK_LOOP_47387++;
        if (AKA_BLOCK_LOOP_47387 > 1000) {
            //break;
        }
        AKA_mark("lis===1184###sois===47421###eois===47493###lif===53###soif===2044###eoif===2116###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");out[i * 4 + 0] = gammatable_r[data[i * 8 + 0] * 256u + data[i * 8 + 1]];
        AKA_mark("lis===1185###sois===47503###eois===47575###lif===54###soif===2126###eoif===2198###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");out[i * 4 + 1] = gammatable_g[data[i * 8 + 2] * 256u + data[i * 8 + 3]];
        AKA_mark("lis===1186###sois===47585###eois===47657###lif===55###soif===2208###eoif===2280###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");out[i * 4 + 2] = gammatable_b[data[i * 8 + 4] * 256u + data[i * 8 + 5]];
        AKA_mark("lis===1187###sois===47667###eois===47743###lif===56###soif===2290###eoif===2366###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");out[i * 4 + 3] = (data[i * 8 + 6] * 256 + data[i * 8 + 7]) * (1 / 65535.0f);
      }
    } else {
      int AKA_BLOCK_LOOP_47774 = 0;
    AKA_mark("lis===1190###sois===47778###eois===47784###lif===59###soif===2401###eoif===2407###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");
for(i = 0; AKA_mark("lis===1190###sois===47785###eois===47790###lif===59###soif===2408###eoif===2413###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1190###sois===47785###eois===47790###lif===59###soif===2408###eoif===2413###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (i < n)); ({AKA_mark("lis===1190###sois===47792###eois===47795###lif===59###soif===2415###eoif===2418###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");i++;})) {
        AKA_BLOCK_LOOP_47774++;
        if (AKA_BLOCK_LOOP_47774 > 1000) {
            //break;
        }
        AKA_mark("lis===1191###sois===47808###eois===47855###lif===60###soif===2431###eoif===2478###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");out[i * 4 + 0] = gammatable_r[data[i * 4 + 0]];
        AKA_mark("lis===1192###sois===47865###eois===47912###lif===61###soif===2488###eoif===2535###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");out[i * 4 + 1] = gammatable_g[data[i * 4 + 1]];
        AKA_mark("lis===1193###sois===47922###eois===47969###lif===62###soif===2545###eoif===2592###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");out[i * 4 + 2] = gammatable_b[data[i * 4 + 2]];
        AKA_mark("lis===1194###sois===47979###eois===48027###lif===63###soif===2602###eoif===2650###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");out[i * 4 + 3] = data[i * 4 + 3] * (1 / 255.0f);
      }
    }
  }

  AKA_mark("lis===1199###sois===48054###eois===48124###lif===68###soif===2677###eoif===2747###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");error = convertToXYZ_chrm(out, w, h, info, use_icc, &icc, whitepoint);
  if(AKA_mark("lis===1200###sois===48131###eois===48136###lif===69###soif===2754###eoif===2759###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1200###sois===48131###eois===48136###lif===69###soif===2754###eoif===2759###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)") && (error))) {
AKA_mark("lis===1200###sois===48138###eois===48151###lif===69###soif===2761###eoif===2774###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");goto cleanup;
}

else {
AKA_mark("lis===-1200-###sois===-48131-###eois===-481315-###lif===-69-###soif===-###eoif===-2759-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");
}

cleanup:
  AKA_mark("lis===1203###sois===48167###eois===48193###lif===72###soif===2790###eoif===2816###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");lodepng_icc_cleanup(&icc);
  AKA_mark("lis===1204###sois===48197###eois===48216###lif===73###soif===2820###eoif===2839###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");lodepng_free(data);
  AKA_mark("lis===1205###sois===48220###eois===48245###lif===74###soif===2843###eoif===2868###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");lodepng_free(gammatable);
  AKA_mark("lis===1206###sois===48249###eois===48262###lif===75###soif===2872###eoif===2885###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZ(float*,float[3],unsigned char const*,unsigned,unsigned,LodePNGState const*)");return error;
}

/** Instrumented function convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*) */
unsigned convertToXYZFloat(float* out, float whitepoint[3], const float* in,
                           unsigned w, unsigned h, const LodePNGState* state) /* << Aka begin of function unsigned convertToXYZFloat(float* out, float whitepoint[3], const float* in,
                           unsigned w, unsigned h, const LodePNGState* state) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.convertToXYZFloat.48278.stub"

  AKA_mark("lis===1211###sois===48430###eois===48449###lif===2###soif===161###eoif===180###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");unsigned error = 0;
  AKA_mark("lis===1212###sois===48453###eois===48496###lif===3###soif===184###eoif===227###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");const LodePNGInfo* info = &state->info_png;

  AKA_mark("lis===1214###sois===48502###eois===48523###lif===5###soif===233###eoif===254###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");unsigned use_icc = 0;
  AKA_mark("lis===1215###sois===48527###eois===48542###lif===6###soif===258###eoif===273###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");LodePNGICC icc;
  AKA_mark("lis===1216###sois===48546###eois===48569###lif===7###soif===277###eoif===300###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");lodepng_icc_init(&icc);
  if(AKA_mark("lis===1217###sois===48576###eois===48594###lif===8###soif===307###eoif===325###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1217###sois===48576###eois===48594###lif===8###soif===307###eoif===325###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)") && (info->iccp_defined))) {
    AKA_mark("lis===1218###sois===48603###eois===48671###lif===9###soif===334###eoif===402###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");error = parseICC(&icc, info->iccp_profile, info->iccp_profile_size);
    if(AKA_mark("lis===1219###sois===48680###eois===48685###lif===10###soif===411###eoif===416###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1219###sois===48680###eois===48685###lif===10###soif===411###eoif===416###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)") && (error))) {
AKA_mark("lis===1219###sois===48687###eois===48700###lif===10###soif===418###eoif===431###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");goto cleanup;
}

else {
AKA_mark("lis===-1219-###sois===-48680-###eois===-486805-###lif===-10-###soif===-###eoif===-416-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");
} /* corrupted ICC profile */
    AKA_mark("lis===1220###sois===48734###eois===48762###lif===11###soif===465###eoif===493###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");use_icc = validateICC(&icc);
  }
else {
AKA_mark("lis===-1217-###sois===-48576-###eois===-4857618-###lif===-8-###soif===-###eoif===-325-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");
}
  /* Input is floating point, so lookup table cannot be used, but it's ensured to
  use float pow, not the slower double pow. */
  AKA_mark("lis===1224###sois===48902###eois===48965###lif===15###soif===633###eoif===696###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");error = convertToXYZ_gamma(out, in, w, h, info, use_icc, &icc);
  if(AKA_mark("lis===1225###sois===48972###eois===48977###lif===16###soif===703###eoif===708###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1225###sois===48972###eois===48977###lif===16###soif===703###eoif===708###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)") && (error))) {
AKA_mark("lis===1225###sois===48979###eois===48992###lif===16###soif===710###eoif===723###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");goto cleanup;
}

else {
AKA_mark("lis===-1225-###sois===-48972-###eois===-489725-###lif===-16-###soif===-###eoif===-708-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");
}
  AKA_mark("lis===1226###sois===48996###eois===49066###lif===17###soif===727###eoif===797###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");error = convertToXYZ_chrm(out, w, h, info, use_icc, &icc, whitepoint);
  if(AKA_mark("lis===1227###sois===49073###eois===49078###lif===18###soif===804###eoif===809###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)") && (AKA_mark("lis===1227###sois===49073###eois===49078###lif===18###soif===804###eoif===809###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)") && (error))) {
AKA_mark("lis===1227###sois===49080###eois===49093###lif===18###soif===811###eoif===824###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");goto cleanup;
}

else {
AKA_mark("lis===-1227-###sois===-49073-###eois===-490735-###lif===-18-###soif===-###eoif===-809-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");
}

cleanup:
  AKA_mark("lis===1230###sois===49109###eois===49135###lif===21###soif===840###eoif===866###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");lodepng_icc_cleanup(&icc);
  AKA_mark("lis===1231###sois===49139###eois===49152###lif===22###soif===870###eoif===883###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToXYZFloat(float*,float[3],float const*,unsigned,unsigned,LodePNGState const*)");return error;
}

/** Instrumented function convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned) */
static unsigned convertFromXYZ_chrm(float* out, const float* in, unsigned w, unsigned h,
                                    const LodePNGInfo* info, unsigned use_icc, const LodePNGICC* icc,
                                    const float whitepoint[3], unsigned rendering_intent) /* << Aka begin of function unsigned convertFromXYZ_chrm(float* out, const float* in, unsigned w, unsigned h,
                                    const LodePNGInfo* info, unsigned use_icc, const LodePNGICC* icc,
                                    const float whitepoint[3], unsigned rendering_intent) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.convertFromXYZ_chrm.49175.stub"

  AKA_mark("lis===1237###sois===49447###eois===49459###lif===3###soif===288###eoif===300###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");size_t i, n;

  AKA_mark("lis===1239###sois===49465###eois===49476###lif===5###soif===306###eoif===317###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");float m[9]; /* XYZ to linear RGB matrix */
  AKA_mark("lis===1240###sois===49511###eois===49526###lif===6###soif===352###eoif===367###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");float white[3]; /* The whitepoint (absolute) of the target RGB space */

  if(AKA_mark("lis===1242###sois===49591###eois===49631###lif===8###soif===432###eoif===472###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (AKA_mark("lis===1242###sois===49591###eois===49631###lif===8###soif===432###eoif===472###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (lodepng_mulofl((size_t)w, (size_t)h, &n)))) {
AKA_mark("lis===1242###sois===49633###eois===49643###lif===8###soif===474###eoif===484###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");return 92;
}

else {
AKA_mark("lis===-1242-###sois===-49591-###eois===-4959140-###lif===-8-###soif===-###eoif===-472-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");
}

  if(AKA_mark("lis===1244###sois===49652###eois===49689###lif===10###soif===493###eoif===530###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (AKA_mark("lis===1244###sois===49652###eois===49689###lif===10###soif===493###eoif===530###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (getChrm(m, white, use_icc, icc, info)))) {
AKA_mark("lis===1244###sois===49691###eois===49700###lif===10###soif===532###eoif===541###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");return 1;
}

else {
AKA_mark("lis===-1244-###sois===-49652-###eois===-4965237-###lif===-10-###soif===-###eoif===-530-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");
}
  if(AKA_mark("lis===1245###sois===49707###eois===49719###lif===11###soif===548###eoif===560###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (AKA_mark("lis===1245###sois===49707###eois===49719###lif===11###soif===548###eoif===560###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (invMatrix(m)))) {
AKA_mark("lis===1245###sois===49721###eois===49730###lif===11###soif===562###eoif===571###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");return 1;
}

else {
AKA_mark("lis===-1245-###sois===-49707-###eois===-4970712-###lif===-11-###soif===-###eoif===-560-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");
} /* error, not invertible */

  /* for relative rendering intent (any except absolute "3"), must whitepoint adapt to the original whitepoint.
  this also ensures grayscale stays grayscale (with absolute, grayscale could become e.g. blue or sepia) */
  if(AKA_mark("lis===1249###sois===49989###eois===50010###lif===15###soif===830###eoif===851###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (AKA_mark("lis===1249###sois===49989###eois===50010###lif===15###soif===830###eoif===851###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (rendering_intent != 3))) {
    AKA_mark("lis===1250###sois===50019###eois===50054###lif===16###soif===860###eoif===895###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");float a[9] = {1,0,0, 0,1,0, 0,0,1};
    /* "white" = absolute whitepoint of the new target RGB space, read from the target color profile.
    "whitepoint" is original absolute whitepoint (input as parameter of this function) of an
    RGB space the XYZ data once had before it was converted to XYZ, in other words the whitepoint that
    we want to adapt our current data to to make sure values that had equal R==G==B in the old space have
    the same property now (white stays white and gray stays gray).
    Note: "absolute" whitepoint above means, can be used as-is, not needing further adaptation itself like icc.white does.*/
    if(AKA_mark("lis===1257###sois===50665###eois===50765###lif===23###soif===1506###eoif===1606###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (AKA_mark("lis===1257###sois===50665###eois===50765###lif===23###soif===1506###eoif===1606###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (getAdaptationMatrix(a, 1, whitepoint[0], whitepoint[1], whitepoint[2], white[0], white[1], white[2])))) {
      AKA_mark("lis===1258###sois===50776###eois===50785###lif===24###soif===1617###eoif===1626###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");return 1;
    }
else {
AKA_mark("lis===-1257-###sois===-50665-###eois===-50665100-###lif===-23-###soif===-###eoif===-1606-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");
}
    /* multiply the from xyz matrix with the adaptation matrix: in total,
    the resulting matrix first adapts in XYZ space, then converts to RGB*/
    AKA_mark("lis===1262###sois===50949###eois===50974###lif===28###soif===1790###eoif===1815###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");mulMatrixMatrix(m, m, a);
  }
else {
AKA_mark("lis===-1249-###sois===-49989-###eois===-4998921-###lif===-15-###soif===-###eoif===-851-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");
}

  /* Apply the above computed XYZ-to-linear-RGB matrix to the pixels.
  This transformation also includes the whitepoint adaptation. The transform
  can be skipped only if it's the unit matrix (only if grayscale profile and no
  whitepoint adaptation, such as with rendering intent 3)*/
  if(AKA_mark("lis===1269###sois===51279###eois===51336###lif===35###soif===2120###eoif===2177###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (((AKA_mark("lis===1269###sois===51279###eois===51287###lif===35###soif===2120###eoif===2128###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (!use_icc)) || (AKA_mark("lis===1269###sois===51291###eois===51311###lif===35###soif===2132###eoif===2152###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (icc->inputspace == 2))) || (AKA_mark("lis===1269###sois===51315###eois===51336###lif===35###soif===2156###eoif===2177###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (rendering_intent != 3)))) {
    int AKA_BLOCK_LOOP_51345 = 0;
    AKA_mark("lis===1270###sois===51349###eois===51355###lif===36###soif===2190###eoif===2196###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");
for(i = 0; AKA_mark("lis===1270###sois===51356###eois===51361###lif===36###soif===2197###eoif===2202###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (AKA_mark("lis===1270###sois===51356###eois===51361###lif===36###soif===2197###eoif===2202###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (i < n)); ({AKA_mark("lis===1270###sois===51363###eois===51366###lif===36###soif===2204###eoif===2207###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");i++;})) {
        AKA_BLOCK_LOOP_51345++;
        if (AKA_BLOCK_LOOP_51345 > 1000) {
            //break;
        }
      AKA_mark("lis===1271###sois===51377###eois===51394###lif===37###soif===2218###eoif===2235###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");size_t j = i * 4;
      AKA_mark("lis===1272###sois===51402###eois===51487###lif===38###soif===2243###eoif===2328###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");mulMatrix(&out[j + 0], &out[j + 1], &out[j + 2], m, in[j + 0], in[j + 1], in[j + 2]);
      AKA_mark("lis===1273###sois===51495###eois===51518###lif===39###soif===2336###eoif===2359###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");out[j + 3] = in[j + 3];
    }
  } else {
    int AKA_BLOCK_LOOP_51543 = 0;
    AKA_mark("lis===1276###sois===51547###eois===51553###lif===42###soif===2388###eoif===2394###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");
for(i = 0; AKA_mark("lis===1276###sois===51554###eois===51563###lif===42###soif===2395###eoif===2404###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (AKA_mark("lis===1276###sois===51554###eois===51563###lif===42###soif===2395###eoif===2404###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)") && (i < n * 4)); ({AKA_mark("lis===1276###sois===51565###eois===51568###lif===42###soif===2406###eoif===2409###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");i++;})) {
        AKA_BLOCK_LOOP_51543++;
        if (AKA_BLOCK_LOOP_51543 > 1000) {
            //break;
        }
      AKA_mark("lis===1277###sois===51579###eois===51594###lif===43###soif===2420###eoif===2435###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");out[i] = in[i];
    }
  }

  AKA_mark("lis===1281###sois===51612###eois===51621###lif===47###soif===2453###eoif===2462###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_chrm(float*,float const*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*,float const[3],unsigned)");return 0;
}

/* Converts in-place. Does not clamp. */
/** Instrumented function convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*) */
static unsigned convertFromXYZ_gamma(float* im, unsigned w, unsigned h,
                                     const LodePNGInfo* info, unsigned use_icc, const LodePNGICC* icc) /* << Aka begin of function unsigned convertFromXYZ_gamma(float* im, unsigned w, unsigned h,
                                     const LodePNGInfo* info, unsigned use_icc, const LodePNGICC* icc) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.convertFromXYZ_gamma.51686.stub"

  AKA_mark("lis===1287###sois===51851###eois===51866###lif===2###soif===181###eoif===196###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");size_t i, c, n;
  if(AKA_mark("lis===1288###sois===51873###eois===51913###lif===3###soif===203###eoif===243###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1288###sois===51873###eois===51913###lif===3###soif===203###eoif===243###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (lodepng_mulofl((size_t)w, (size_t)h, &n)))) {
AKA_mark("lis===1288###sois===51915###eois===51925###lif===3###soif===245###eoif===255###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");return 92;
}

else {
AKA_mark("lis===-1288-###sois===-51873-###eois===-5187340-###lif===-3-###soif===-###eoif===-243-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
}
  if(AKA_mark("lis===1289###sois===51932###eois===51939###lif===4###soif===262###eoif===269###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1289###sois===51932###eois===51939###lif===4###soif===262###eoif===269###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (use_icc))) {
    int AKA_BLOCK_LOOP_51948 = 0;
    AKA_mark("lis===1290###sois===51952###eois===51958###lif===5###soif===282###eoif===288###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(i = 0; AKA_mark("lis===1290###sois===51959###eois===51964###lif===5###soif===289###eoif===294###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1290###sois===51959###eois===51964###lif===5###soif===289###eoif===294###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (i < n)); ({AKA_mark("lis===1290###sois===51966###eois===51969###lif===5###soif===296###eoif===299###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");i++;})) {
        AKA_BLOCK_LOOP_51948++;
        if (AKA_BLOCK_LOOP_51948 > 1000) {
            //break;
        }
      int AKA_BLOCK_LOOP_51980 = 0;
    AKA_mark("lis===1291###sois===51984###eois===51990###lif===6###soif===314###eoif===320###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(c = 0; AKA_mark("lis===1291###sois===51991###eois===51996###lif===6###soif===321###eoif===326###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1291###sois===51991###eois===51996###lif===6###soif===321###eoif===326###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (c < 3)); ({AKA_mark("lis===1291###sois===51998###eois===52001###lif===6###soif===328###eoif===331###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");c++;})) {
        AKA_BLOCK_LOOP_51980++;
        if (AKA_BLOCK_LOOP_51980 > 1000) {
            //break;
        }
        /* TODO: this is likely very slow */
        AKA_mark("lis===1293###sois===52060###eois===52120###lif===8###soif===390###eoif===450###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");im[i * 4 + c] = iccBackwardTRC(&icc->trc[c], im[i * 4 + c]);
      }
    }
  } else {
if(AKA_mark("lis===1296###sois===52150###eois===52191###lif===11###soif===480###eoif===521###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && ((AKA_mark("lis===1296###sois===52150###eois===52168###lif===11###soif===480###eoif===498###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (info->gama_defined)) && (AKA_mark("lis===1296###sois===52172###eois===52191###lif===11###soif===502###eoif===521###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (!info->srgb_defined)))) {
    /* nothing to do if gamma is 1 */
    if(AKA_mark("lis===1298###sois===52242###eois===52268###lif===13###soif===572###eoif===598###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1298###sois===52242###eois===52268###lif===13###soif===572###eoif===598###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (info->gama_gamma != 100000))) {
      AKA_mark("lis===1299###sois===52279###eois===52322###lif===14###soif===609###eoif===652###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");float gamma = info->gama_gamma / 100000.0f;
      int AKA_BLOCK_LOOP_52330 = 0;
    AKA_mark("lis===1300###sois===52334###eois===52340###lif===15###soif===664###eoif===670###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(i = 0; AKA_mark("lis===1300###sois===52341###eois===52346###lif===15###soif===671###eoif===676###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1300###sois===52341###eois===52346###lif===15###soif===671###eoif===676###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (i < n)); ({AKA_mark("lis===1300###sois===52348###eois===52351###lif===15###soif===678###eoif===681###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");i++;})) {
        AKA_BLOCK_LOOP_52330++;
        if (AKA_BLOCK_LOOP_52330 > 1000) {
            //break;
        }
        int AKA_BLOCK_LOOP_52364 = 0;
    AKA_mark("lis===1301###sois===52368###eois===52374###lif===16###soif===698###eoif===704###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(c = 0; AKA_mark("lis===1301###sois===52375###eois===52380###lif===16###soif===705###eoif===710###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1301###sois===52375###eois===52380###lif===16###soif===705###eoif===710###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (c < 3)); ({AKA_mark("lis===1301###sois===52382###eois===52385###lif===16###soif===712###eoif===715###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");c++;})) {
        AKA_BLOCK_LOOP_52364++;
        if (AKA_BLOCK_LOOP_52364 > 1000) {
            //break;
        }
          if(AKA_mark("lis===1302###sois===52403###eois===52420###lif===17###soif===733###eoif===750###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1302###sois===52403###eois===52420###lif===17###soif===733###eoif===750###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (im[i * 4 + c] > 0))) {
AKA_mark("lis===1302###sois===52422###eois===52473###lif===17###soif===752###eoif===803###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");im[i * 4 + c] = lodepng_powf(im[i * 4 + c], gamma);
}

else {
AKA_mark("lis===-1302-###sois===-52403-###eois===-5240317-###lif===-17-###soif===-###eoif===-750-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
}
        }
      }
    }
else {
AKA_mark("lis===-1298-###sois===-52242-###eois===-5224226-###lif===-13-###soif===-###eoif===-598-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
}
  } else {
    int AKA_BLOCK_LOOP_52518 = 0;
    AKA_mark("lis===1307###sois===52522###eois===52528###lif===22###soif===852###eoif===858###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(i = 0; AKA_mark("lis===1307###sois===52529###eois===52534###lif===22###soif===859###eoif===864###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1307###sois===52529###eois===52534###lif===22###soif===859###eoif===864###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (i < n)); ({AKA_mark("lis===1307###sois===52536###eois===52539###lif===22###soif===866###eoif===869###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");i++;})) {
        AKA_BLOCK_LOOP_52518++;
        if (AKA_BLOCK_LOOP_52518 > 1000) {
            //break;
        }
      int AKA_BLOCK_LOOP_52550 = 0;
    AKA_mark("lis===1308###sois===52554###eois===52560###lif===23###soif===884###eoif===890###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");
for(c = 0; AKA_mark("lis===1308###sois===52561###eois===52566###lif===23###soif===891###eoif===896###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (AKA_mark("lis===1308###sois===52561###eois===52566###lif===23###soif===891###eoif===896###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)") && (c < 3)); ({AKA_mark("lis===1308###sois===52568###eois===52571###lif===23###soif===898###eoif===901###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");c++;})) {
        AKA_BLOCK_LOOP_52550++;
        if (AKA_BLOCK_LOOP_52550 > 1000) {
            //break;
        }
        /* sRGB gamma compress */
        AKA_mark("lis===1310###sois===52619###eois===52645###lif===25###soif===949###eoif===975###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");float* v = &im[i * 4 + c];
        AKA_mark("lis===1311###sois===52655###eois===52743###lif===26###soif===985###eoif===1073###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");*v = (*v < 0.0031308f) ? (*v * 12.92f) : (1.055f * lodepng_powf(*v, 1 / 2.4f) - 0.055f);
      }
    }
  }
}

  AKA_mark("lis===1315###sois===52768###eois===52777###lif===30###soif===1098###eoif===1107###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ_gamma(float*,unsigned,unsigned,LodePNGInfo const*,unsigned,LodePNGICC const*)");return 0; /* no error */
}

/** Instrumented function convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned) */
unsigned convertFromXYZ(unsigned char* out, const float* in, unsigned w, unsigned h,
                        const LodePNGState* state,
                        const float whitepoint[3], unsigned rendering_intent) /* << Aka begin of function unsigned convertFromXYZ(unsigned char* out, const float* in, unsigned w, unsigned h,
                        const LodePNGState* state,
                        const float whitepoint[3], unsigned rendering_intent) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.convertFromXYZ.52808.stub"

  AKA_mark("lis===1321###sois===53020###eois===53039###lif===3###soif===221###eoif===240###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");unsigned error = 0;
  AKA_mark("lis===1322###sois===53043###eois===53080###lif===4###soif===244###eoif===281###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");size_t i, c, n, bytes_im, bytes_data;
  AKA_mark("lis===1323###sois===53084###eois===53136###lif===5###soif===285###eoif===337###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");const LodePNGColorMode* mode_out = &state->info_raw;
  AKA_mark("lis===1324###sois===53140###eois===53183###lif===6###soif===341###eoif===384###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");const LodePNGInfo* info = &state->info_png;
  AKA_mark("lis===1325###sois===53187###eois===53222###lif===7###soif===388###eoif===423###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");int bit16 = mode_out->bitdepth > 8;
  AKA_mark("lis===1326###sois===53226###eois===53240###lif===8###soif===427###eoif===441###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");float* im = 0;
  AKA_mark("lis===1327###sois===53244###eois===53268###lif===9###soif===445###eoif===469###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");unsigned char* data = 0;

  /* parse ICC if present */
  AKA_mark("lis===1330###sois===53304###eois===53325###lif===12###soif===505###eoif===526###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");unsigned use_icc = 0;
  AKA_mark("lis===1331###sois===53329###eois===53344###lif===13###soif===530###eoif===545###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");LodePNGICC icc;
  AKA_mark("lis===1332###sois===53348###eois===53371###lif===14###soif===549###eoif===572###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");lodepng_icc_init(&icc);
  if(AKA_mark("lis===1333###sois===53378###eois===53396###lif===15###soif===579###eoif===597###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1333###sois===53378###eois===53396###lif===15###soif===579###eoif===597###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (info->iccp_defined))) {
    AKA_mark("lis===1334###sois===53405###eois===53473###lif===16###soif===606###eoif===674###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");error = parseICC(&icc, info->iccp_profile, info->iccp_profile_size);
    if(AKA_mark("lis===1335###sois===53482###eois===53487###lif===17###soif===683###eoif===688###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1335###sois===53482###eois===53487###lif===17###soif===683###eoif===688###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (error))) {
AKA_mark("lis===1335###sois===53489###eois===53502###lif===17###soif===690###eoif===703###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");goto cleanup;
}

else {
AKA_mark("lis===-1335-###sois===-53482-###eois===-534825-###lif===-17-###soif===-###eoif===-688-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
} /* corrupted ICC profile */
    AKA_mark("lis===1336###sois===53536###eois===53564###lif===18###soif===737###eoif===765###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");use_icc = validateICC(&icc);
  }
else {
AKA_mark("lis===-1333-###sois===-53378-###eois===-5337818-###lif===-15-###soif===-###eoif===-597-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}

  if(AKA_mark("lis===1339###sois===53578###eois===53618###lif===21###soif===779###eoif===819###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1339###sois===53578###eois===53618###lif===21###soif===779###eoif===819###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (lodepng_mulofl((size_t)w, (size_t)h, &n)))) {
AKA_mark("lis===1339###sois===53620###eois===53631###lif===21###soif===821###eoif===832###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");error = 92;
}

else {
AKA_mark("lis===-1339-###sois===-53578-###eois===-5357840-###lif===-21-###soif===-###eoif===-819-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}
  if(AKA_mark("lis===1340###sois===53638###eois===53643###lif===22###soif===839###eoif===844###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1340###sois===53638###eois===53643###lif===22###soif===839###eoif===844###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (error))) {
AKA_mark("lis===1340###sois===53645###eois===53658###lif===22###soif===846###eoif===859###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");goto cleanup;
}

else {
AKA_mark("lis===-1340-###sois===-53638-###eois===-536385-###lif===-22-###soif===-###eoif===-844-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}
  if(AKA_mark("lis===1341###sois===53665###eois===53712###lif===23###soif===866###eoif===913###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1341###sois===53665###eois===53712###lif===23###soif===866###eoif===913###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (lodepng_mulofl(n, 4 * sizeof(float), &bytes_im)))) {
AKA_mark("lis===1341###sois===53714###eois===53725###lif===23###soif===915###eoif===926###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");error = 92;
}

else {
AKA_mark("lis===-1341-###sois===-53665-###eois===-5366547-###lif===-23-###soif===-###eoif===-913-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}
  if(AKA_mark("lis===1342###sois===53732###eois===53737###lif===24###soif===933###eoif===938###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1342###sois===53732###eois===53737###lif===24###soif===933###eoif===938###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (error))) {
AKA_mark("lis===1342###sois===53739###eois===53752###lif===24###soif===940###eoif===953###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");goto cleanup;
}

else {
AKA_mark("lis===-1342-###sois===-53732-###eois===-537325-###lif===-24-###soif===-###eoif===-938-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}
  if(AKA_mark("lis===1343###sois===53759###eois===53804###lif===25###soif===960###eoif===1005###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1343###sois===53759###eois===53804###lif===25###soif===960###eoif===1005###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (lodepng_mulofl(n, bit16 ? 8 : 4, &bytes_data)))) {
AKA_mark("lis===1343###sois===53806###eois===53817###lif===25###soif===1007###eoif===1018###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");error = 92;
}

else {
AKA_mark("lis===-1343-###sois===-53759-###eois===-5375945-###lif===-25-###soif===-###eoif===-1005-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}
  if(AKA_mark("lis===1344###sois===53824###eois===53829###lif===26###soif===1025###eoif===1030###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1344###sois===53824###eois===53829###lif===26###soif===1025###eoif===1030###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (error))) {
AKA_mark("lis===1344###sois===53831###eois===53844###lif===26###soif===1032###eoif===1045###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");goto cleanup;
}

else {
AKA_mark("lis===-1344-###sois===-53824-###eois===-538245-###lif===-26-###soif===-###eoif===-1030-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}

  /* Handle gamut */
  AKA_mark("lis===1347###sois===53872###eois===53910###lif===29###soif===1073###eoif===1111###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");im = (float*)lodepng_malloc(bytes_im);
  AKA_mark("lis===1348###sois===53914###eois===54007###lif===30###soif===1115###eoif===1208###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");error = convertFromXYZ_chrm(im, in, w, h, info, use_icc, &icc, whitepoint, rendering_intent);
  if(AKA_mark("lis===1349###sois===54014###eois===54019###lif===31###soif===1215###eoif===1220###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1349###sois===54014###eois===54019###lif===31###soif===1215###eoif===1220###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (error))) {
AKA_mark("lis===1349###sois===54021###eois===54034###lif===31###soif===1222###eoif===1235###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");goto cleanup;
}

else {
AKA_mark("lis===-1349-###sois===-54014-###eois===-540145-###lif===-31-###soif===-###eoif===-1220-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}

  /* Handle transfer function */
  /* Input is floating point, so lookup table cannot be used, but it's ensured to use float pow, not the slower double pow. */
  AKA_mark("lis===1353###sois===54202###eois===54262###lif===35###soif===1403###eoif===1463###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");error = convertFromXYZ_gamma(im, w, h, info, use_icc, &icc);
  if(AKA_mark("lis===1354###sois===54269###eois===54274###lif===36###soif===1470###eoif===1475###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1354###sois===54269###eois===54274###lif===36###soif===1470###eoif===1475###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (error))) {
AKA_mark("lis===1354###sois===54276###eois===54289###lif===36###soif===1477###eoif===1490###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");goto cleanup;
}

else {
AKA_mark("lis===-1354-###sois===-54269-###eois===-542695-###lif===-36-###soif===-###eoif===-1475-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}

  /* Convert to integer output */
  AKA_mark("lis===1357###sois===54330###eois===54380###lif===39###soif===1531###eoif===1581###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");data = (unsigned char*)lodepng_malloc(bytes_data);
  /* TODO: check if also 1/2/4 bit case needed: rounding is at different fine-grainedness for 8 and 16 bits below. */
  if(AKA_mark("lis===1359###sois===54506###eois===54511###lif===41###soif===1707###eoif===1712###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1359###sois===54506###eois===54511###lif===41###soif===1707###eoif===1712###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (bit16))) {
    AKA_mark("lis===1360###sois===54520###eois===54584###lif===42###soif===1721###eoif===1785###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");LodePNGColorMode mode16 = lodepng_color_mode_make(LCT_RGBA, 16);
    int AKA_BLOCK_LOOP_54590 = 0;
    AKA_mark("lis===1361###sois===54594###eois===54600###lif===43###soif===1795###eoif===1801###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
for(i = 0; AKA_mark("lis===1361###sois===54601###eois===54606###lif===43###soif===1802###eoif===1807###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1361###sois===54601###eois===54606###lif===43###soif===1802###eoif===1807###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (i < n)); ({AKA_mark("lis===1361###sois===54608###eois===54611###lif===43###soif===1809###eoif===1812###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");i++;})) {
        AKA_BLOCK_LOOP_54590++;
        if (AKA_BLOCK_LOOP_54590 > 1000) {
            //break;
        }
      int AKA_BLOCK_LOOP_54622 = 0;
    AKA_mark("lis===1362###sois===54626###eois===54632###lif===44###soif===1827###eoif===1833###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
for(c = 0; AKA_mark("lis===1362###sois===54633###eois===54638###lif===44###soif===1834###eoif===1839###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1362###sois===54633###eois===54638###lif===44###soif===1834###eoif===1839###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (c < 4)); ({AKA_mark("lis===1362###sois===54640###eois===54643###lif===44###soif===1841###eoif===1844###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");c++;})) {
        AKA_BLOCK_LOOP_54622++;
        if (AKA_BLOCK_LOOP_54622 > 1000) {
            //break;
        }
        AKA_mark("lis===1363###sois===54656###eois===54681###lif===45###soif===1857###eoif===1882###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");size_t j = i * 8 + c * 2;
        AKA_mark("lis===1364###sois===54691###eois===54778###lif===46###soif===1892###eoif===1979###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");int i16 = (int)(0.5f + 65535.0f * LODEPNG_MIN(LODEPNG_MAX(0.0f, im[i * 4 + c]), 1.0f));
        AKA_mark("lis===1365###sois===54788###eois===54828###lif===47###soif===1989###eoif===2029###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");data[j + 0] = (unsigned char)(i16 >> 8);
        AKA_mark("lis===1366###sois===54838###eois===54879###lif===48###soif===2039###eoif===2080###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");data[j + 1] = (unsigned char)(i16 & 255);
      }
    }
    AKA_mark("lis===1369###sois===54901###eois===54961###lif===51###soif===2102###eoif===2162###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");error = lodepng_convert(out, data, mode_out, &mode16, w, h);
    if(AKA_mark("lis===1370###sois===54970###eois===54975###lif===52###soif===2171###eoif===2176###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1370###sois===54970###eois===54975###lif===52###soif===2171###eoif===2176###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (error))) {
AKA_mark("lis===1370###sois===54977###eois===54990###lif===52###soif===2178###eoif===2191###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");goto cleanup;
}

else {
AKA_mark("lis===-1370-###sois===-54970-###eois===-549705-###lif===-52-###soif===-###eoif===-2176-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}
  } else {
    AKA_mark("lis===1372###sois===55008###eois===55070###lif===54###soif===2209###eoif===2271###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");LodePNGColorMode mode8 = lodepng_color_mode_make(LCT_RGBA, 8);
    int AKA_BLOCK_LOOP_55076 = 0;
    AKA_mark("lis===1373###sois===55080###eois===55086###lif===55###soif===2281###eoif===2287###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
for(i = 0; AKA_mark("lis===1373###sois===55087###eois===55092###lif===55###soif===2288###eoif===2293###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1373###sois===55087###eois===55092###lif===55###soif===2288###eoif===2293###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (i < n)); ({AKA_mark("lis===1373###sois===55094###eois===55097###lif===55###soif===2295###eoif===2298###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");i++;})) {
        AKA_BLOCK_LOOP_55076++;
        if (AKA_BLOCK_LOOP_55076 > 1000) {
            //break;
        }
      int AKA_BLOCK_LOOP_55108 = 0;
    AKA_mark("lis===1374###sois===55112###eois===55118###lif===56###soif===2313###eoif===2319###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
for(c = 0; AKA_mark("lis===1374###sois===55119###eois===55124###lif===56###soif===2320###eoif===2325###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1374###sois===55119###eois===55124###lif===56###soif===2320###eoif===2325###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (c < 4)); ({AKA_mark("lis===1374###sois===55126###eois===55129###lif===56###soif===2327###eoif===2330###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");c++;})) {
        AKA_BLOCK_LOOP_55108++;
        if (AKA_BLOCK_LOOP_55108 > 1000) {
            //break;
        }
        AKA_mark("lis===1375###sois===55142###eois===55245###lif===57###soif===2343###eoif===2446###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");data[i * 4 + c] = (unsigned char)(0.5f + 255.0f * LODEPNG_MIN(LODEPNG_MAX(0.0f, im[i * 4 + c]), 1.0f));
      }
    }
    AKA_mark("lis===1378###sois===55267###eois===55326###lif===60###soif===2468###eoif===2527###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");error = lodepng_convert(out, data, mode_out, &mode8, w, h);
    if(AKA_mark("lis===1379###sois===55335###eois===55340###lif===61###soif===2536###eoif===2541###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1379###sois===55335###eois===55340###lif===61###soif===2536###eoif===2541###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (error))) {
AKA_mark("lis===1379###sois===55342###eois===55355###lif===61###soif===2543###eoif===2556###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");goto cleanup;
}

else {
AKA_mark("lis===-1379-###sois===-55335-###eois===-553355-###lif===-61-###soif===-###eoif===-2541-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}
  }

cleanup:
  AKA_mark("lis===1383###sois===55376###eois===55402###lif===65###soif===2577###eoif===2603###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");lodepng_icc_cleanup(&icc);
  AKA_mark("lis===1384###sois===55406###eois===55423###lif===66###soif===2607###eoif===2624###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");lodepng_free(im);
  AKA_mark("lis===1385###sois===55427###eois===55446###lif===67###soif===2628###eoif===2647###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");lodepng_free(data);
  AKA_mark("lis===1386###sois===55450###eois===55463###lif===68###soif===2651###eoif===2664###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZ(unsigned char*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");return error;
}

/** Instrumented function convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned) */
unsigned convertFromXYZFloat(float* out, const float* in, unsigned w, unsigned h,
                             const LodePNGState* state,
                             const float whitepoint[3], unsigned rendering_intent) /* << Aka begin of function unsigned convertFromXYZFloat(float* out, const float* in, unsigned w, unsigned h,
                             const LodePNGState* state,
                             const float whitepoint[3], unsigned rendering_intent) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.convertFromXYZFloat.55479.stub"

  AKA_mark("lis===1392###sois===55698###eois===55717###lif===3###soif===228###eoif===247###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");unsigned error = 0;
  AKA_mark("lis===1393###sois===55721###eois===55764###lif===4###soif===251###eoif===294###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");const LodePNGInfo* info = &state->info_png;

  /* parse ICC if present */
  AKA_mark("lis===1396###sois===55800###eois===55821###lif===7###soif===330###eoif===351###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");unsigned use_icc = 0;
  AKA_mark("lis===1397###sois===55825###eois===55840###lif===8###soif===355###eoif===370###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");LodePNGICC icc;
  AKA_mark("lis===1398###sois===55844###eois===55867###lif===9###soif===374###eoif===397###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");lodepng_icc_init(&icc);
  if(AKA_mark("lis===1399###sois===55874###eois===55892###lif===10###soif===404###eoif===422###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1399###sois===55874###eois===55892###lif===10###soif===404###eoif===422###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (info->iccp_defined))) {
    AKA_mark("lis===1400###sois===55901###eois===55969###lif===11###soif===431###eoif===499###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");error = parseICC(&icc, info->iccp_profile, info->iccp_profile_size);
    if(AKA_mark("lis===1401###sois===55978###eois===55983###lif===12###soif===508###eoif===513###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1401###sois===55978###eois===55983###lif===12###soif===508###eoif===513###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (error))) {
AKA_mark("lis===1401###sois===55985###eois===55998###lif===12###soif===515###eoif===528###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");goto cleanup;
}

else {
AKA_mark("lis===-1401-###sois===-55978-###eois===-559785-###lif===-12-###soif===-###eoif===-513-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
} /* corrupted ICC profile */
    AKA_mark("lis===1402###sois===56032###eois===56060###lif===13###soif===562###eoif===590###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");use_icc = validateICC(&icc);
  }
else {
AKA_mark("lis===-1399-###sois===-55874-###eois===-5587418-###lif===-10-###soif===-###eoif===-422-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}

  /* Handle gamut */
  AKA_mark("lis===1406###sois===56093###eois===56187###lif===17###soif===623###eoif===717###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");error = convertFromXYZ_chrm(out, in, w, h, info, use_icc, &icc, whitepoint, rendering_intent);
  if(AKA_mark("lis===1407###sois===56194###eois===56199###lif===18###soif===724###eoif===729###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1407###sois===56194###eois===56199###lif===18###soif===724###eoif===729###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (error))) {
AKA_mark("lis===1407###sois===56201###eois===56214###lif===18###soif===731###eoif===744###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");goto cleanup;
}

else {
AKA_mark("lis===-1407-###sois===-56194-###eois===-561945-###lif===-18-###soif===-###eoif===-729-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}

  /* Handle transfer function */
  AKA_mark("lis===1410###sois===56254###eois===56315###lif===21###soif===784###eoif===845###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");error = convertFromXYZ_gamma(out, w, h, info, use_icc, &icc);
  if(AKA_mark("lis===1411###sois===56322###eois===56327###lif===22###soif===852###eoif===857###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (AKA_mark("lis===1411###sois===56322###eois===56327###lif===22###soif===852###eoif===857###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)") && (error))) {
AKA_mark("lis===1411###sois===56329###eois===56342###lif===22###soif===859###eoif===872###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");goto cleanup;
}

else {
AKA_mark("lis===-1411-###sois===-56322-###eois===-563225-###lif===-22-###soif===-###eoif===-857-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");
}

cleanup:
  AKA_mark("lis===1414###sois===56358###eois===56384###lif===25###soif===888###eoif===914###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");lodepng_icc_cleanup(&icc);
  AKA_mark("lis===1415###sois===56388###eois===56401###lif===26###soif===918###eoif===931###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromXYZFloat(float*,float const*,unsigned,unsigned,LodePNGState const*,float const[3],unsigned)");return error;
}

/** Instrumented function convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned) */
unsigned convertRGBModel(unsigned char* out, const unsigned char* in,
                         unsigned w, unsigned h,
                         const LodePNGState* state_out,
                         const LodePNGState* state_in,
                         unsigned rendering_intent) /* << Aka begin of function unsigned convertRGBModel(unsigned char* out, const unsigned char* in,
                         unsigned w, unsigned h,
                         const LodePNGState* state_out,
                         const LodePNGState* state_in,
                         unsigned rendering_intent) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.convertRGBModel.56417.stub"

  if(AKA_mark("lis===1423###sois===56702###eois===56734###lif===5###soif===294###eoif===326###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)") && (AKA_mark("lis===1423###sois===56702###eois===56734###lif===5###soif===294###eoif===326###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)") && (modelsEqual(state_in, state_out)))) {
    AKA_mark("lis===1424###sois===56743###eois===56824###lif===6###soif===335###eoif===416###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");return lodepng_convert(out, in, &state_out->info_raw, &state_in->info_raw, w, h);
  } else {
    AKA_mark("lis===1426###sois===56842###eois===56861###lif===8###soif===434###eoif===453###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");unsigned error = 0;
    AKA_mark("lis===1427###sois===56867###eois===56883###lif===9###soif===459###eoif===475###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");size_t n, bytes;
    if(AKA_mark("lis===1428###sois===56892###eois===56932###lif===10###soif===484###eoif===524###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)") && (AKA_mark("lis===1428###sois===56892###eois===56932###lif===10###soif===484###eoif===524###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)") && (lodepng_mulofl((size_t)w, (size_t)h, &n)))) {
AKA_mark("lis===1428###sois===56934###eois===56944###lif===10###soif===526###eoif===536###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");return 92;
}

else {
AKA_mark("lis===-1428-###sois===-56892-###eois===-5689240-###lif===-10-###soif===-###eoif===-524-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");
}
    if(AKA_mark("lis===1429###sois===56953###eois===56997###lif===11###soif===545###eoif===589###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)") && (AKA_mark("lis===1429###sois===56953###eois===56997###lif===11###soif===545###eoif===589###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)") && (lodepng_mulofl(n, 4 * sizeof(float), &bytes)))) {
AKA_mark("lis===1429###sois===56999###eois===57009###lif===11###soif===591###eoif===601###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");return 92;
}

else {
AKA_mark("lis===-1429-###sois===-56953-###eois===-5695344-###lif===-11-###soif===-###eoif===-589-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");
}
    AKA_mark("lis===1430###sois===57015###eois===57058###lif===12###soif===607###eoif===650###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");float* xyz = (float*)lodepng_malloc(bytes);
    AKA_mark("lis===1431###sois===57064###eois===57084###lif===13###soif===656###eoif===676###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");float whitepoint[3];
    AKA_mark("lis===1432###sois===57090###eois===57148###lif===14###soif===682###eoif===740###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");error = convertToXYZ(xyz, whitepoint, in, w, h, state_in);
    if (AKA_mark("lis===1433###sois===57158###eois===57164###lif===15###soif===750###eoif===756###ifc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)") && (AKA_mark("lis===1433###sois===57158###eois===57164###lif===15###soif===750###eoif===756###isc===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)") && (!error))) {
AKA_mark("lis===1433###sois===57166###eois===57246###lif===15###soif===758###eoif===838###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");error = convertFromXYZ(out, xyz, w, h, state_out, whitepoint, rendering_intent);
}

else {
AKA_mark("lis===-1433-###sois===-57158-###eois===-571586-###lif===-15-###soif===-###eoif===-756-###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");
}
    AKA_mark("lis===1434###sois===57252###eois===57270###lif===16###soif===844###eoif===862###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");lodepng_free(xyz);
    AKA_mark("lis===1435###sois===57276###eois===57289###lif===17###soif===868###eoif===881###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertRGBModel(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*,LodePNGState const*,unsigned)");return error;
  }
}

/** Instrumented function convertToSrgb(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*) */
unsigned convertToSrgb(unsigned char* out, const unsigned char* in,
                       unsigned w, unsigned h,
                       const LodePNGState* state_in) /* << Aka begin of function unsigned convertToSrgb(unsigned char* out, const unsigned char* in,
                       unsigned w, unsigned h,
                       const LodePNGState* state_in) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToSrgb(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.convertToSrgb.57310.stub"

  AKA_mark("lis===1442###sois===57476###eois===57494###lif===3###soif===175###eoif===193###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToSrgb(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*)");LodePNGState srgb;
  AKA_mark("lis===1443###sois===57498###eois===57524###lif===4###soif===197###eoif===223###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToSrgb(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*)");lodepng_state_init(&srgb);
  AKA_mark("lis===1444###sois===57528###eois===57589###lif===5###soif===227###eoif===288###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToSrgb(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*)");lodepng_color_mode_copy(&srgb.info_raw, &state_in->info_raw);
  AKA_mark("lis===1445###sois===57593###eois===57651###lif===6###soif===292###eoif===350###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertToSrgb(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*)");return convertRGBModel(out, in, w, h, &srgb, state_in, 1);
}

/** Instrumented function convertFromSrgb(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*) */
unsigned convertFromSrgb(unsigned char* out, const unsigned char* in,
                         unsigned w, unsigned h,
                         const LodePNGState* state_out) /* << Aka begin of function unsigned convertFromSrgb(unsigned char* out, const unsigned char* in,
                         unsigned w, unsigned h,
                         const LodePNGState* state_out) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromSrgb(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*)");AKA_fCall++;
	/** Include stub source code */
	#include "lodepng_util.cpp.convertFromSrgb.57667.stub"

  AKA_mark("lis===1451###sois===57840###eois===57858###lif===3###soif===182###eoif===200###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromSrgb(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*)");LodePNGState srgb;
  AKA_mark("lis===1452###sois===57862###eois===57888###lif===4###soif===204###eoif===230###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromSrgb(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*)");lodepng_state_init(&srgb);
  AKA_mark("lis===1453###sois===57892###eois===57954###lif===5###soif===234###eoif===296###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromSrgb(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*)");lodepng_color_mode_copy(&srgb.info_raw, &state_out->info_raw);
  AKA_mark("lis===1454###sois===57958###eois===58017###lif===6###soif===300###eoif===359###ins===true###function===.\\lvandeve_lodepng\\src\\lodepng_util.cpp\\lodepng\\convertFromSrgb(unsigned char*,unsigned char const*,unsigned,unsigned,LodePNGState const*)");return convertRGBModel(out, in, w, h, state_out, &srgb, 1);
}

#endif /*LODEPNG_COMPILE_ANCILLARY_CHUNKS*/

} // namespace lodepng

#endif
