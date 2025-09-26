/** Guard statement to avoid multiple declaration */
#ifndef AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_LVANDEVE_LODEPNG_SRC_PNGDETAIL_CPP
#define AKA_SRC_E__CPP_PROJECTS_COLLECTION_NHATMINH_LVANDEVE_LODEPNG_SRC_PNGDETAIL_CPP
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
LodePNG pngdetail

Copyright (c) 2005-2025 Lode Vandevenne

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

//g++ pngdetail.cpp lodepng_util.cpp lodepng.cpp -ansi -pedantic -Wall -Wextra -o pngdetail -O3


/*
Utility program that shows a lot of information in the console about a PNG file,
including color type, text chunks, the names and sizes of all chunks in the
image, exif, and ICC profile, etc...
*/

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__LODEPNG_H_
#define AKA_INCLUDE__LODEPNG_H_
#include "lodepng.akaignore.h"
#endif

/** Guard statement to avoid multiple declaration */
#ifndef AKA_INCLUDE__LODEPNG_UTIL_H_
#define AKA_INCLUDE__LODEPNG_UTIL_H_
#include "lodepng_util.akaignore.h"
#endif

#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <inttypes.h>

/** Instrumented function showHelp() */
void showHelp() /* << Aka begin of function void showHelp() >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHelp()");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.showHelp.1456.stub"

  AKA_mark("lis===47###sois===1472###eois===1529###lif===1###soif===21###eoif===78###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHelp()");std::cout << "pngdetail by Lode Vandevenne" << std::endl;
  AKA_mark("lis===48###sois===1533###eois===1597###lif===2###soif===82###eoif===146###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHelp()");std::cout << "version: " << LODEPNG_VERSION_STRING << std::endl;
  AKA_mark("lis===49###sois===1601###eois===3837###lif===3###soif===150###eoif===2386###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHelp()");std::cout << "Shows detailed information about a PNG image, its compression and possible corruptions.\n"
               "Usage: pngdetail [filename] [options]...\n"
               "Without options shows a default set of stats. With options, shows only selected options.\n"
               "E.g. 'pngdetail image.png -plc' to show png info, palette info and chunks\n"
               "Options:\n"
               "-o: show header summary on one line\n"
               "-H: show header info\n"
               "-p: show PNG file info\n"
               "-a: analyze errors or warnings\n"
               "-e: show exif metadata (if the PNG has an eXIf chunk)\n"
               "-E: show exif metadata hex bytes\n"
               "-i: show ICC profile details (if any)\n"
               "-I: show ICC profile hex bytes\n"
               "--format=<format>: display mode for -I:\n"
               "    hex: print bytes in hex\n"
               "    mix: print printable bytes as ASCII characters, hex for others\n"
               "    bin: dump as binary in terminal\n"
               "-l: show palette (if any)\n"
               "-s: show color statistics\n"
               "-r: render the PNG image in terminal (with --mode and --size)\n"
               "--size=<width>: render width for -r\n"
               "--mode=<mode>: render mode for -r:\n"
               "    ascii:   Letters ROYLGTCABVMF indicate hue (L=lime, T=turquoise, A=azure, F=fuchsia, ...).\n"
               "    hex:     CSS hex notation for every pixel.\n"
               "    hex16:   Like hex but shows 16 bits values per channel.\n"
               "    palette: Shows palette index of each pixel, only for palette images.\n"
               "--size=<width>: render width (not used by hex, hex16 or palette):\n"
               "-c: show PNG chunks\n"
               "-C: show PNG chunks (alternate format)\n"
               "-f: show PNG filters\n"
               "-z: show Zlib info\n"
               "-v: be more verbose\n"
               "-t: expand long texts\n"
               "-x: print most integer numbers in hexadecimal (includes e.g. year, num unique colors, ...)\n"
               "-?, --help, -h: show this help" << std::endl;
}

enum RenderMode {
  RM_ASCII,
  RM_HEX, // CSS
  RM_HEX16,
  RM_PAL // palette indices (only rendered if image is palette based)
};

// for displaying ICC profile
enum HexFormat {
  HF_HEX,
  HF_MIX, // hex and ascii
  HF_BIN // bytes as binary data dump
};

struct Options {
  bool verbose;
  bool expand_long_texts;
  bool show_one_line_summary; //show filesize, pixels and color type on single line
  bool show_header; // show only info from the IHDR chunk
  bool show_errors;
  bool show_icc_details; // show ICC color profile details
  bool show_icc_hex; // show ICC color profile in full
  bool show_exif;
  bool show_exif_hex;
  bool show_color_stats;
  bool show_png_info; //show things like filesize, width, height, palette size, ...
  bool show_palette; //show all palette values
  bool show_palette_pixels; //show palette indices of pixels

  HexFormat hexformat;

  bool show_render;
  RenderMode rendermode;
  int rendersize;

  bool show_chunks; //show the PNG chunk names and their lengths
  bool show_chunks2; //alternate form to print chunks
  bool show_filters; //show the PNG filter of each scanline (not supported for interlaced PNGs currently)
  bool show_zlib_info; //show basic zlib info
  bool use_hex; //show some sizes or positions in hexadecimal

  /** Instrumented function Options() */
Options() : verbose(false), expand_long_texts(false),
              show_one_line_summary(false), show_header(false), show_errors(false),
              show_icc_details(false), show_icc_hex(false), show_exif(false), show_exif_hex(false),
              show_color_stats(false), show_png_info(false),
              show_palette(false), show_palette_pixels(false),
              hexformat(HF_MIX), show_render(false), rendermode(RM_ASCII), rendersize(80),
              show_chunks(false), show_chunks2(false), show_filters(false),
              show_zlib_info(false), use_hex(false) /* << Aka begin of function  Options() >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\Options\\Options()");AKA_fCall++;
  }
};

/** Instrumented function inspect_chunk_by_name(unsigned char const*,unsigned char const*,lodepng::State&,char const[5]) */
unsigned inspect_chunk_by_name(const unsigned char* data, const unsigned char* end,
                               lodepng::State& state, const char type[5]) /* << Aka begin of function unsigned inspect_chunk_by_name(const unsigned char* data, const unsigned char* end,
                               lodepng::State& state, const char type[5]) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\inspect_chunk_by_name(unsigned char const*,unsigned char const*,lodepng::State&,char const[5])");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.inspect_chunk_by_name.5772.stub"

  AKA_mark("lis===140###sois===5927###eois===5994###lif===2###soif===164###eoif===231###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\inspect_chunk_by_name(unsigned char const*,unsigned char const*,lodepng::State&,char const[5])");const unsigned char* p = lodepng_chunk_find_const(data, end, type);
  if(AKA_mark("lis===141###sois===6001###eois===6003###lif===3###soif===238###eoif===240###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\inspect_chunk_by_name(unsigned char const*,unsigned char const*,lodepng::State&,char const[5])") && (AKA_mark("lis===141###sois===6001###eois===6003###lif===3###soif===238###eoif===240###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\inspect_chunk_by_name(unsigned char const*,unsigned char const*,lodepng::State&,char const[5])") && (!p))) {
AKA_mark("lis===141###sois===6005###eois===6014###lif===3###soif===242###eoif===251###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\inspect_chunk_by_name(unsigned char const*,unsigned char const*,lodepng::State&,char const[5])");return 0;
}

else {
AKA_mark("lis===-141-###sois===-6001-###eois===-60012-###lif===-3-###soif===-###eoif===-240-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\inspect_chunk_by_name(unsigned char const*,unsigned char const*,lodepng::State&,char const[5])");
} // not found, but this is not considered an error
  AKA_mark("lis===142###sois===6068###eois===6133###lif===4###soif===305###eoif===370###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\inspect_chunk_by_name(unsigned char const*,unsigned char const*,lodepng::State&,char const[5])");return lodepng_inspect_chunk(&state, p - data, data, end - data);
}

// Lazy loads the raw file, inspected header or entire image as needed
struct Data {
  std::string filename;
  std::vector<unsigned char> buffer;
  std::vector<unsigned char> pixels; // 16-bit
  unsigned w;
  unsigned h;
  lodepng::State state;
  unsigned error;
  bool inspected;
  bool is_png; // not is_icc or is_exif
  bool is_icc; // the file is a raw icc file, not a PNG, only options -i and -I are useful
  bool is_exif; // the file is a raw exif file, not a PNG, only option -e is useful

  /** Instrumented function Data(std::string const&) */
Data(const std::string& filename) : filename(filename), error(0), inspected(false), is_png(false), is_icc(false), is_exif(false) /* << Aka begin of function  Data(const std::string& filename) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\Data(std::string const&)");AKA_fCall++;}

  // Load the file if not already loaded
  /** Instrumented function loadFile() */
void loadFile() /* << Aka begin of function void loadFile() >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadFile()");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.loadFile.6837.stub"

    if(AKA_mark("lis===163###sois===6858###eois===6872###lif===1###soif===26###eoif===40###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadFile()") && (AKA_mark("lis===163###sois===6858###eois===6872###lif===1###soif===26###eoif===40###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadFile()") && (buffer.empty()))) {
      AKA_mark("lis===164###sois===6883###eois===6928###lif===2###soif===51###eoif===96###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadFile()");error = lodepng::load_file(buffer, filename); //load the image file with given filename
    } else {
      AKA_mark("lis===166###sois===6992###eois===7002###lif===4###soif===160###eoif===170###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadFile()");error = 0; // for reloadpixels, reset error if file was already successfully loaded
    }
  }

  // is PNG according to the file signature
  /** Instrumented function isPng() */
bool isPng() /* << Aka begin of function bool isPng() >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isPng()");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.isPng.7143.stub"

    if(AKA_mark("lis===172###sois===7161###eois===7178###lif===1###soif===23###eoif===40###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isPng()") && (AKA_mark("lis===172###sois===7161###eois===7178###lif===1###soif===23###eoif===40###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isPng()") && (buffer.size() < 8))) {
AKA_mark("lis===172###sois===7180###eois===7193###lif===1###soif===42###eoif===55###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isPng()");return false;
}

else {
AKA_mark("lis===-172-###sois===-7161-###eois===-716117-###lif===-1-###soif===-###eoif===-40-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isPng()");
}
    AKA_mark("lis===173###sois===7199###eois===7365###lif===2###soif===61###eoif===227###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isPng()");return buffer[0] == 137 && buffer[1] == 80 && buffer[2] == 78 && buffer[3] == 71
        && buffer[4] == 13 && buffer[5] == 10 && buffer[6] == 26 && buffer[7] == 10;
  }

  // is probably an ICC profile instead of a PNG image
  /** Instrumented function isIcc() */
bool isIcc() /* << Aka begin of function bool isIcc() >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.isIcc.7437.stub"

    if(AKA_mark("lis===179###sois===7455###eois===7462###lif===1###soif===23###eoif===30###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (AKA_mark("lis===179###sois===7455###eois===7462###lif===1###soif===23###eoif===30###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (isPng()))) {
AKA_mark("lis===179###sois===7464###eois===7477###lif===1###soif===32###eoif===45###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");return false;
}

else {
AKA_mark("lis===-179-###sois===-7455-###eois===-74557-###lif===-1-###soif===-###eoif===-30-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");
}
    if(AKA_mark("lis===180###sois===7486###eois===7505###lif===2###soif===54###eoif===73###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (AKA_mark("lis===180###sois===7486###eois===7505###lif===2###soif===54###eoif===73###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (buffer.size() < 128))) {
AKA_mark("lis===180###sois===7507###eois===7520###lif===2###soif===75###eoif===88###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");return false;
}

else {
AKA_mark("lis===-180-###sois===-7486-###eois===-748619-###lif===-2-###soif===-###eoif===-73-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");
}
    AKA_mark("lis===181###sois===7526###eois===7609###lif===3###soif===94###eoif===177###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");size_t size = (buffer[0] << 24) + (buffer[1] << 16) + (buffer[2] << 8) + buffer[3];
    if(AKA_mark("lis===182###sois===7618###eois===7639###lif===4###soif===186###eoif===207###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (AKA_mark("lis===182###sois===7618###eois===7639###lif===4###soif===186###eoif===207###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (size != buffer.size()))) {
AKA_mark("lis===182###sois===7641###eois===7654###lif===4###soif===209###eoif===222###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");return false;
}

else {
AKA_mark("lis===-182-###sois===-7618-###eois===-761821-###lif===-4-###soif===-###eoif===-207-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");
}
    if(AKA_mark("lis===183###sois===7663###eois===7680###lif===5###soif===231###eoif===248###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (AKA_mark("lis===183###sois===7663###eois===7680###lif===5###soif===231###eoif===248###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (buffer[36] != 'a'))) {
AKA_mark("lis===183###sois===7682###eois===7695###lif===5###soif===250###eoif===263###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");return false;
}

else {
AKA_mark("lis===-183-###sois===-7663-###eois===-766317-###lif===-5-###soif===-###eoif===-248-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");
}
    if(AKA_mark("lis===184###sois===7704###eois===7721###lif===6###soif===272###eoif===289###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (AKA_mark("lis===184###sois===7704###eois===7721###lif===6###soif===272###eoif===289###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (buffer[37] != 'c'))) {
AKA_mark("lis===184###sois===7723###eois===7736###lif===6###soif===291###eoif===304###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");return false;
}

else {
AKA_mark("lis===-184-###sois===-7704-###eois===-770417-###lif===-6-###soif===-###eoif===-289-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");
}
    if(AKA_mark("lis===185###sois===7745###eois===7762###lif===7###soif===313###eoif===330###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (AKA_mark("lis===185###sois===7745###eois===7762###lif===7###soif===313###eoif===330###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (buffer[38] != 's'))) {
AKA_mark("lis===185###sois===7764###eois===7777###lif===7###soif===332###eoif===345###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");return false;
}

else {
AKA_mark("lis===-185-###sois===-7745-###eois===-774517-###lif===-7-###soif===-###eoif===-330-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");
}
    if(AKA_mark("lis===186###sois===7786###eois===7803###lif===8###soif===354###eoif===371###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (AKA_mark("lis===186###sois===7786###eois===7803###lif===8###soif===354###eoif===371###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()") && (buffer[39] != 'p'))) {
AKA_mark("lis===186###sois===7805###eois===7818###lif===8###soif===373###eoif===386###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");return false;
}

else {
AKA_mark("lis===-186-###sois===-7786-###eois===-778617-###lif===-8-###soif===-###eoif===-371-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");
}
    AKA_mark("lis===187###sois===7824###eois===7836###lif===9###soif===392###eoif===404###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isIcc()");return true;
  }
  // is probably an EXIF file instead of a PNG image
  /** Instrumented function isExif() */
bool isExif() /* << Aka begin of function bool isExif() >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.isExif.7904.stub"

    if(AKA_mark("lis===191###sois===7923###eois===7940###lif===1###soif===24###eoif===41###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()") && (AKA_mark("lis===191###sois===7923###eois===7940###lif===1###soif===24###eoif===41###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()") && (buffer.size() < 8))) {
AKA_mark("lis===191###sois===7942###eois===7955###lif===1###soif===43###eoif===56###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()");return false;
}

else {
AKA_mark("lis===-191-###sois===-7923-###eois===-792317-###lif===-1-###soif===-###eoif===-41-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()");
}
    if(AKA_mark("lis===192###sois===7964###eois===8037###lif===2###soif===65###eoif===138###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()") && ((((AKA_mark("lis===192###sois===7964###eois===7980###lif===2###soif===65###eoif===81###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()") && (buffer[0] == 'M')) && (AKA_mark("lis===192###sois===7984###eois===8000###lif===2###soif===85###eoif===101###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()") && (buffer[1] == 'M'))) && (AKA_mark("lis===192###sois===8004###eois===8018###lif===2###soif===105###eoif===119###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()") && (buffer[2] == 0))) && (AKA_mark("lis===192###sois===8022###eois===8037###lif===2###soif===123###eoif===138###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()") && (buffer[3] == 42)))) {
AKA_mark("lis===192###sois===8039###eois===8051###lif===2###soif===140###eoif===152###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()");return true;
}

else {
AKA_mark("lis===-192-###sois===-7964-###eois===-796473-###lif===-2-###soif===-###eoif===-138-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()");
}
    if(AKA_mark("lis===193###sois===8060###eois===8133###lif===3###soif===161###eoif===234###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()") && ((((AKA_mark("lis===193###sois===8060###eois===8076###lif===3###soif===161###eoif===177###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()") && (buffer[0] == 'I')) && (AKA_mark("lis===193###sois===8080###eois===8096###lif===3###soif===181###eoif===197###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()") && (buffer[1] == 'I'))) && (AKA_mark("lis===193###sois===8100###eois===8115###lif===3###soif===201###eoif===216###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()") && (buffer[2] == 42))) && (AKA_mark("lis===193###sois===8119###eois===8133###lif===3###soif===220###eoif===234###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()") && (buffer[3] == 0)))) {
AKA_mark("lis===193###sois===8135###eois===8147###lif===3###soif===236###eoif===248###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()");return true;
}

else {
AKA_mark("lis===-193-###sois===-8060-###eois===-806073-###lif===-3-###soif===-###eoif===-234-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()");
}
    AKA_mark("lis===194###sois===8153###eois===8166###lif===4###soif===254###eoif===267###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\isExif()");return false;
  }

  // Load header info (plus a few more nearby light chunks) if not already loaded, and the file if needed
  /** Instrumented function loadInspect() */
void loadInspect() /* << Aka begin of function void loadInspect() >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.loadInspect.8289.stub"

    if(AKA_mark("lis===199###sois===8313###eois===8322###lif===1###soif===29###eoif===38###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===199###sois===8313###eois===8322###lif===1###soif===29###eoif===38###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (inspected))) {
AKA_mark("lis===199###sois===8324###eois===8331###lif===1###soif===40###eoif===47###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");return;
}

else {
AKA_mark("lis===-199-###sois===-8313-###eois===-83139-###lif===-1-###soif===-###eoif===-38-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
}
    AKA_mark("lis===200###sois===8337###eois===8354###lif===2###soif===53###eoif===70###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");inspected = true;
    AKA_mark("lis===201###sois===8360###eois===8371###lif===3###soif===76###eoif===87###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");loadFile();
    if(AKA_mark("lis===202###sois===8380###eois===8385###lif===4###soif===96###eoif===101###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===202###sois===8380###eois===8385###lif===4###soif===96###eoif===101###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (error))) {
AKA_mark("lis===202###sois===8387###eois===8394###lif===4###soif===103###eoif===110###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");return;
}

else {
AKA_mark("lis===-202-###sois===-8380-###eois===-83805-###lif===-4-###soif===-###eoif===-101-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
}
    AKA_mark("lis===203###sois===8400###eois===8434###lif===5###soif===116###eoif===150###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");is_png = is_icc = is_exif = false;
    if(AKA_mark("lis===204###sois===8443###eois===8450###lif===6###soif===159###eoif===166###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===204###sois===8443###eois===8450###lif===6###soif===159###eoif===166###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (isIcc()))) {
      AKA_mark("lis===205###sois===8461###eois===8531###lif===7###soif===177###eoif===247###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");lodepng_set_icc(&state.info_png, "<none>", &buffer[0], buffer.size());
      AKA_mark("lis===206###sois===8539###eois===8553###lif===8###soif===255###eoif===269###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");is_icc = true;
    } else {
if(AKA_mark("lis===207###sois===8569###eois===8577###lif===9###soif===285###eoif===293###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===207###sois===8569###eois===8577###lif===9###soif===285###eoif===293###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (isExif()))) {
      AKA_mark("lis===208###sois===8588###eois===8649###lif===10###soif===304###eoif===365###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");lodepng_set_exif(&state.info_png, &buffer[0], buffer.size());
      AKA_mark("lis===209###sois===8657###eois===8672###lif===11###soif===373###eoif===388###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");is_exif = true;
    } else {
      AKA_mark("lis===211###sois===8694###eois===8708###lif===13###soif===410###eoif===424###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");is_png = true;
      AKA_mark("lis===212###sois===8716###eois===8755###lif===14###soif===432###eoif===471###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");const unsigned char* data = &buffer[0];
      AKA_mark("lis===213###sois===8763###eois===8824###lif===15###soif===479###eoif===540###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");error = lodepng_inspect(&w, &h, &state, data, buffer.size());
      if(AKA_mark("lis===214###sois===8835###eois===8840###lif===16###soif===551###eoif===556###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===214###sois===8835###eois===8840###lif===16###soif===551###eoif===556###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (error))) {
AKA_mark("lis===214###sois===8842###eois===8849###lif===16###soif===558###eoif===565###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");return;
}

else {
AKA_mark("lis===-214-###sois===-8835-###eois===-88355-###lif===-16-###soif===-###eoif===-556-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
}
      // end before first IDAT chunk: do not parse more than first part of file for all this.
      AKA_mark("lis===216###sois===8952###eois===9040###lif===18###soif===668###eoif===756###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");const unsigned char* end = lodepng_chunk_find_const(data, data + buffer.size(), "IDAT");
      if(AKA_mark("lis===217###sois===9051###eois===9055###lif===19###soif===767###eoif===771###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===217###sois===9051###eois===9055###lif===19###soif===767###eoif===771###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (!end))) {
AKA_mark("lis===217###sois===9057###eois===9084###lif===19###soif===773###eoif===800###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");end = data + buffer.size();
}

else {
AKA_mark("lis===-217-###sois===-9051-###eois===-90514-###lif===-19-###soif===-###eoif===-771-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
} // no IDAT, invalid PNG but extract info anyway
      AKA_mark("lis===218###sois===9140###eois===9196###lif===20###soif===856###eoif===912###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");error = inspect_chunk_by_name(data, end, state, "PLTE");
      if(AKA_mark("lis===219###sois===9207###eois===9212###lif===21###soif===923###eoif===928###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===219###sois===9207###eois===9212###lif===21###soif===923###eoif===928###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (error))) {
AKA_mark("lis===219###sois===9214###eois===9221###lif===21###soif===930###eoif===937###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");return;
}

else {
AKA_mark("lis===-219-###sois===-9207-###eois===-92075-###lif===-21-###soif===-###eoif===-928-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
}
      AKA_mark("lis===220###sois===9229###eois===9285###lif===22###soif===945###eoif===1001###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");error = inspect_chunk_by_name(data, end, state, "tRNS");
      if(AKA_mark("lis===221###sois===9296###eois===9301###lif===23###soif===1012###eoif===1017###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===221###sois===9296###eois===9301###lif===23###soif===1012###eoif===1017###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (error))) {
AKA_mark("lis===221###sois===9303###eois===9310###lif===23###soif===1019###eoif===1026###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");return;
}

else {
AKA_mark("lis===-221-###sois===-9296-###eois===-92965-###lif===-23-###soif===-###eoif===-1017-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
}
      AKA_mark("lis===222###sois===9318###eois===9374###lif===24###soif===1034###eoif===1090###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");error = inspect_chunk_by_name(data, end, state, "cHRM");
      if(AKA_mark("lis===223###sois===9385###eois===9390###lif===25###soif===1101###eoif===1106###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===223###sois===9385###eois===9390###lif===25###soif===1101###eoif===1106###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (error))) {
AKA_mark("lis===223###sois===9392###eois===9399###lif===25###soif===1108###eoif===1115###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");return;
}

else {
AKA_mark("lis===-223-###sois===-9385-###eois===-93855-###lif===-25-###soif===-###eoif===-1106-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
}
      AKA_mark("lis===224###sois===9407###eois===9463###lif===26###soif===1123###eoif===1179###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");error = inspect_chunk_by_name(data, end, state, "gAMA");
      if(AKA_mark("lis===225###sois===9474###eois===9479###lif===27###soif===1190###eoif===1195###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===225###sois===9474###eois===9479###lif===27###soif===1190###eoif===1195###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (error))) {
AKA_mark("lis===225###sois===9481###eois===9488###lif===27###soif===1197###eoif===1204###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");return;
}

else {
AKA_mark("lis===-225-###sois===-9474-###eois===-94745-###lif===-27-###soif===-###eoif===-1195-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
}
      AKA_mark("lis===226###sois===9496###eois===9552###lif===28###soif===1212###eoif===1268###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");error = inspect_chunk_by_name(data, end, state, "sBIT");
      if(AKA_mark("lis===227###sois===9563###eois===9568###lif===29###soif===1279###eoif===1284###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===227###sois===9563###eois===9568###lif===29###soif===1279###eoif===1284###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (error))) {
AKA_mark("lis===227###sois===9570###eois===9577###lif===29###soif===1286###eoif===1293###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");return;
}

else {
AKA_mark("lis===-227-###sois===-9563-###eois===-95635-###lif===-29-###soif===-###eoif===-1284-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
}
      AKA_mark("lis===228###sois===9585###eois===9641###lif===30###soif===1301###eoif===1357###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");error = inspect_chunk_by_name(data, end, state, "bKGD");
      if(AKA_mark("lis===229###sois===9652###eois===9657###lif===31###soif===1368###eoif===1373###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===229###sois===9652###eois===9657###lif===31###soif===1368###eoif===1373###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (error))) {
AKA_mark("lis===229###sois===9659###eois===9666###lif===31###soif===1375###eoif===1382###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");return;
}

else {
AKA_mark("lis===-229-###sois===-9652-###eois===-96525-###lif===-31-###soif===-###eoif===-1373-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
}
      AKA_mark("lis===230###sois===9674###eois===9730###lif===32###soif===1390###eoif===1446###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");error = inspect_chunk_by_name(data, end, state, "hIST");
      if(AKA_mark("lis===231###sois===9741###eois===9746###lif===33###soif===1457###eoif===1462###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===231###sois===9741###eois===9746###lif===33###soif===1457###eoif===1462###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (error))) {
AKA_mark("lis===231###sois===9748###eois===9755###lif===33###soif===1464###eoif===1471###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");return;
}

else {
AKA_mark("lis===-231-###sois===-9741-###eois===-97415-###lif===-33-###soif===-###eoif===-1462-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
}
      AKA_mark("lis===232###sois===9763###eois===9819###lif===34###soif===1479###eoif===1535###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");error = inspect_chunk_by_name(data, end, state, "pHYs");
      if(AKA_mark("lis===233###sois===9830###eois===9835###lif===35###soif===1546###eoif===1551###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===233###sois===9830###eois===9835###lif===35###soif===1546###eoif===1551###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (error))) {
AKA_mark("lis===233###sois===9837###eois===9844###lif===35###soif===1553###eoif===1560###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");return;
}

else {
AKA_mark("lis===-233-###sois===-9830-###eois===-98305-###lif===-35-###soif===-###eoif===-1551-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
}
      AKA_mark("lis===234###sois===9852###eois===9908###lif===36###soif===1568###eoif===1624###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");error = inspect_chunk_by_name(data, end, state, "iCCP");
      if(AKA_mark("lis===235###sois===9919###eois===9924###lif===37###soif===1635###eoif===1640###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===235###sois===9919###eois===9924###lif===37###soif===1635###eoif===1640###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (error))) {
AKA_mark("lis===235###sois===9926###eois===9933###lif===37###soif===1642###eoif===1649###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");return;
}

else {
AKA_mark("lis===-235-###sois===-9919-###eois===-99195-###lif===-37-###soif===-###eoif===-1640-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
}
      AKA_mark("lis===236###sois===9941###eois===9997###lif===38###soif===1657###eoif===1713###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");error = inspect_chunk_by_name(data, end, state, "eXIf");
      if(AKA_mark("lis===237###sois===10008###eois===10013###lif===39###soif===1724###eoif===1729###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (AKA_mark("lis===237###sois===10008###eois===10013###lif===39###soif===1724###eoif===1729###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()") && (error))) {
AKA_mark("lis===237###sois===10015###eois===10022###lif===39###soif===1731###eoif===1738###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");return;
}

else {
AKA_mark("lis===-237-###sois===-10008-###eois===-100085-###lif===-39-###soif===-###eoif===-1729-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadInspect()");
}
    }
}

  }

  // Load the pixels if not already loaded, and the file if needed
  /** Instrumented function loadPixels() */
void loadPixels() /* << Aka begin of function void loadPixels() >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadPixels()");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.loadPixels.10113.stub"

    if(AKA_mark("lis===243###sois===10136###eois===10150###lif===1###soif===28###eoif===42###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadPixels()") && (AKA_mark("lis===243###sois===10136###eois===10150###lif===1###soif===28###eoif===42###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadPixels()") && (pixels.empty()))) {
AKA_mark("lis===243###sois===10152###eois===10167###lif===1###soif===44###eoif===59###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadPixels()");reloadPixels();
}

else {
AKA_mark("lis===-243-###sois===-10136-###eois===-1013614-###lif===-1-###soif===-###eoif===-42-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\loadPixels()");
}
  }

  /** Instrumented function reloadPixels() */
void reloadPixels() /* << Aka begin of function void reloadPixels() >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\reloadPixels()");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.reloadPixels.10183.stub"

    AKA_mark("lis===247###sois===10205###eois===10216###lif===1###soif===27###eoif===38###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\reloadPixels()");loadFile();
    if(AKA_mark("lis===248###sois===10225###eois===10230###lif===2###soif===47###eoif===52###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\reloadPixels()") && (AKA_mark("lis===248###sois===10225###eois===10230###lif===2###soif===47###eoif===52###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\reloadPixels()") && (error))) {
AKA_mark("lis===248###sois===10232###eois===10239###lif===2###soif===54###eoif===61###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\reloadPixels()");return;
}

else {
AKA_mark("lis===-248-###sois===-10225-###eois===-102255-###lif===-2-###soif===-###eoif===-52-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\reloadPixels()");
}
    AKA_mark("lis===249###sois===10245###eois===10262###lif===3###soif===67###eoif===84###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\reloadPixels()");inspected = true;
    AKA_mark("lis===250###sois===10268###eois===10304###lif===4###soif===90###eoif===126###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\reloadPixels()");state.info_raw.colortype = LCT_RGBA;
    AKA_mark("lis===251###sois===10310###eois===10339###lif===5###soif===132###eoif===161###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\reloadPixels()");state.info_raw.bitdepth = 16;
    AKA_mark("lis===252###sois===10345###eois===10360###lif===6###soif===167###eoif===182###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\reloadPixels()");pixels.clear();
    AKA_mark("lis===253###sois===10366###eois===10419###lif===7###soif===188###eoif===241###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\Data\\reloadPixels()");error = lodepng::decode(pixels, w, h, state, buffer);
  }
};

/** Instrumented function colorTypeString(LodePNGColorType) */
std::string colorTypeString(LodePNGColorType type) /* << Aka begin of function std::string colorTypeString(LodePNGColorType type) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.colorTypeString.10444.stub"

  AKA_mark("lis===258###sois===10488###eois===10505###lif===1###soif===56###eoif===73###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");std::string name;
  AKA_mark("lis===259###sois===10516###eois===10520###lif===2###soif===84###eoif===88###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");switch(type) {
    case LCT_GREY: if (type == LCT_GREY)
AKA_mark("lis===260###sois===10529###eois===10543###lif===3###soif===97###eoif===111###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");
 AKA_mark("lis===260###sois===10544###eois===10558###lif===3###soif===112###eoif===126###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");name = "grey"; AKA_mark("lis===260###sois===10559###eois===10565###lif===3###soif===127###eoif===133###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");break;
    case LCT_RGB: if (type == LCT_RGB)
AKA_mark("lis===261###sois===10571###eois===10584###lif===4###soif===139###eoif===152###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");
 AKA_mark("lis===261###sois===10585###eois===10598###lif===4###soif===153###eoif===166###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");name = "RGB"; AKA_mark("lis===261###sois===10599###eois===10605###lif===4###soif===167###eoif===173###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");break;
    case LCT_PALETTE: if (type == LCT_PALETTE)
AKA_mark("lis===262###sois===10611###eois===10628###lif===5###soif===179###eoif===196###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");
 AKA_mark("lis===262###sois===10629###eois===10646###lif===5###soif===197###eoif===214###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");name = "palette"; AKA_mark("lis===262###sois===10647###eois===10653###lif===5###soif===215###eoif===221###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");break;
    case LCT_GREY_ALPHA: if (type == LCT_GREY_ALPHA)
AKA_mark("lis===263###sois===10659###eois===10679###lif===6###soif===227###eoif===247###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");
 AKA_mark("lis===263###sois===10680###eois===10700###lif===6###soif===248###eoif===268###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");name = "grey+alpha"; AKA_mark("lis===263###sois===10701###eois===10707###lif===6###soif===269###eoif===275###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");break;
    case LCT_RGBA: if (type == LCT_RGBA)
AKA_mark("lis===264###sois===10713###eois===10727###lif===7###soif===281###eoif===295###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");
 AKA_mark("lis===264###sois===10728###eois===10742###lif===7###soif===296###eoif===310###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");name = "RGBA"; AKA_mark("lis===264###sois===10743###eois===10749###lif===7###soif===311###eoif===317###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");break;
    default: if (type != LCT_GREY && type != LCT_RGB && type != LCT_PALETTE && type != LCT_GREY_ALPHA && type != LCT_RGBA)
AKA_mark("lis===265###sois===10755###eois===10763###lif===8###soif===323###eoif===331###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");
 AKA_mark("lis===265###sois===10764###eois===10781###lif===8###soif===332###eoif===349###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");name = "invalid"; AKA_mark("lis===265###sois===10782###eois===10788###lif===8###soif===350###eoif===356###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");break;
  }
  AKA_mark("lis===267###sois===10797###eois===10818###lif===10###soif===365###eoif===386###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");std::stringstream ss;
  AKA_mark("lis===268###sois===10822###eois===10856###lif===11###soif===390###eoif===424###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");ss << type << " (" << name << ")";
  AKA_mark("lis===269###sois===10860###eois===10876###lif===12###soif===428###eoif===444###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\colorTypeString(LodePNGColorType)");return ss.str();
}

template<typename T>
/** Instrumented function strtoval(std::string const&) */
T strtoval(const std::string& s) /* << Aka begin of function T strtoval(const std::string& s) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\strtoval(std::string const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.strtoval.10907.stub"

  AKA_mark("lis===274###sois===10943###eois===10973###lif===1###soif===38###eoif===68###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\strtoval(std::string const&)");std::istringstream sstream(s);
  AKA_mark("lis===275###sois===10977###eois===10983###lif===2###soif===72###eoif===78###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\strtoval(std::string const&)");T val;
  AKA_mark("lis===276###sois===10987###eois===11002###lif===3###soif===82###eoif===97###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\strtoval(std::string const&)");sstream >> val;
  AKA_mark("lis===277###sois===11006###eois===11017###lif===4###soif===101###eoif===112###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\strtoval(std::string const&)");return val;
}


/*
Display the names and sizes of all chunks in the PNG file.
*/
/** Instrumented function displayChunkNames(Data&,Options const&) */
void displayChunkNames(Data& data, const Options& options) /* << Aka begin of function void displayChunkNames(Data& data, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.displayChunkNames.11099.stub"

  AKA_mark("lis===285###sois===11158###eois===11177###lif===1###soif===64###eoif===83###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");data.loadInspect();
  if(AKA_mark("lis===286###sois===11184###eois===11196###lif===2###soif===90###eoif===102###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (AKA_mark("lis===286###sois===11184###eois===11196###lif===2###soif===90###eoif===102###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (!data.is_png))) {
AKA_mark("lis===286###sois===11198###eois===11205###lif===2###soif===104###eoif===111###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");return;
}

else {
AKA_mark("lis===-286-###sois===-11184-###eois===-1118412-###lif===-2-###soif===-###eoif===-102-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");
}
  AKA_mark("lis===287###sois===11209###eois===11225###lif===3###soif===115###eoif===131###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");data.loadFile();
  if(AKA_mark("lis===288###sois===11232###eois===11242###lif===4###soif===138###eoif===148###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (AKA_mark("lis===288###sois===11232###eois===11242###lif===4###soif===138###eoif===148###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (data.error))) {
AKA_mark("lis===288###sois===11244###eois===11251###lif===4###soif===150###eoif===157###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");return;
}

else {
AKA_mark("lis===-288-###sois===-11232-###eois===-1123210-###lif===-4-###soif===-###eoif===-148-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");
}
  AKA_mark("lis===289###sois===11255###eois===11307###lif===5###soif===161###eoif===213###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << (options.use_hex ? std::hex: std::dec);
  AKA_mark("lis===290###sois===11311###eois===11366###lif===6###soif===217###eoif===272###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");const std::vector<unsigned char>& buffer = data.buffer;
  AKA_mark("lis===291###sois===11370###eois===11401###lif===7###soif===276###eoif===307###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::vector<std::string> names;
  AKA_mark("lis===292###sois===11405###eois===11431###lif===8###soif===311###eoif===337###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::vector<size_t> sizes;
  AKA_mark("lis===293###sois===11435###eois===11496###lif===9###soif===341###eoif===402###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");unsigned error = lodepng::getChunkInfo(names, sizes, buffer);
  if(AKA_mark("lis===294###sois===11503###eois===11508###lif===10###soif===409###eoif===414###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (AKA_mark("lis===294###sois===11503###eois===11508###lif===10###soif===409###eoif===414###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (error))) {
    if(AKA_mark("lis===295###sois===11520###eois===11581###lif===11###soif===426###eoif===487###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (((AKA_mark("lis===295###sois===11520###eois===11534###lif===11###soif===426###eoif===440###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (!names.empty())) && (AKA_mark("lis===295###sois===11538###eois===11560###lif===11###soif===444###eoif===466###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (names.back() == "IEND"))) && (AKA_mark("lis===295###sois===11564###eois===11581###lif===11###soif===470###eoif===487###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (sizes.back() == 0)))) {
      AKA_mark("lis===296###sois===11592###eois===11681###lif===12###soif===498###eoif===587###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << "Corruption or superfluous data detected after the IEND chunk" << std::endl;
    } else {
      AKA_mark("lis===298###sois===11703###eois===11797###lif===14###soif===609###eoif===703###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << "Error while identifying chunks. Listing identified chunks anyway." << std::endl;
    }
  }
else {
AKA_mark("lis===-294-###sois===-11503-###eois===-115035-###lif===-10-###soif===-###eoif===-414-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");
}

  if(AKA_mark("lis===302###sois===11818###eois===11838###lif===18###soif===724###eoif===744###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (AKA_mark("lis===302###sois===11818###eois===11838###lif===18###soif===724###eoif===744###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (options.show_chunks2))) {
    AKA_mark("lis===303###sois===11847###eois===11876###lif===19###soif===753###eoif===782###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << "Chunk types: ";
    int AKA_BLOCK_LOOP_11882 = 0;
    AKA_mark("lis===304###sois===11886###eois===11899###lif===20###soif===792###eoif===805###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");
for(size_t i = 0; AKA_mark("lis===304###sois===11900###eois===11916###lif===20###soif===806###eoif===822###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (AKA_mark("lis===304###sois===11900###eois===11916###lif===20###soif===806###eoif===822###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (i < names.size())); ({AKA_mark("lis===304###sois===11918###eois===11921###lif===20###soif===824###eoif===827###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");i++;})) {
AKA_mark("lis===304###sois===11923###eois===11952###lif===20###soif===829###eoif===858###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << names[i] << " ";
}

    AKA_mark("lis===305###sois===11958###eois===11981###lif===21###soif===864###eoif===887###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << std::endl;
    AKA_mark("lis===306###sois===11987###eois===12016###lif===22###soif===893###eoif===922###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << "Chunk sizes: ";
    int AKA_BLOCK_LOOP_12022 = 0;
    AKA_mark("lis===307###sois===12026###eois===12039###lif===23###soif===932###eoif===945###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");
for(size_t i = 0; AKA_mark("lis===307###sois===12040###eois===12056###lif===23###soif===946###eoif===962###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (AKA_mark("lis===307###sois===12040###eois===12056###lif===23###soif===946###eoif===962###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (i < sizes.size())); ({AKA_mark("lis===307###sois===12058###eois===12061###lif===23###soif===964###eoif===967###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");i++;})) {
AKA_mark("lis===307###sois===12063###eois===12092###lif===23###soif===969###eoif===998###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << sizes[i] << " ";
}

    AKA_mark("lis===308###sois===12098###eois===12121###lif===24###soif===1004###eoif===1027###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << std::endl;
  } else {
    AKA_mark("lis===310###sois===12139###eois===12178###lif===26###soif===1045###eoif===1084###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << "Chunks (type: lengths):";
    AKA_mark("lis===311###sois===12184###eois===12206###lif===27###soif===1090###eoif===1112###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::string last_type;
    int AKA_BLOCK_LOOP_12212 = 0;
    AKA_mark("lis===312###sois===12216###eois===12229###lif===28###soif===1122###eoif===1135###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");
for(size_t i = 0; AKA_mark("lis===312###sois===12230###eois===12246###lif===28###soif===1136###eoif===1152###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (AKA_mark("lis===312###sois===12230###eois===12246###lif===28###soif===1136###eoif===1152###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (i < names.size())); ({AKA_mark("lis===312###sois===12248###eois===12251###lif===28###soif===1154###eoif===1157###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");i++;})) {
        AKA_BLOCK_LOOP_12212++;
        if (AKA_BLOCK_LOOP_12212 > 1000) {
            //break;
        }
      if(AKA_mark("lis===313###sois===12265###eois===12286###lif===29###soif===1171###eoif===1192###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (AKA_mark("lis===313###sois===12265###eois===12286###lif===29###soif===1171###eoif===1192###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (last_type != names[i]))) {
        AKA_mark("lis===314###sois===12299###eois===12322###lif===30###soif===1205###eoif===1228###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << std::endl;
        AKA_mark("lis===315###sois===12332###eois===12369###lif===31###soif===1238###eoif===1275###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << " " << names[i] << ": ";
      }
else {
AKA_mark("lis===-313-###sois===-12265-###eois===-1226521-###lif===-29-###soif===-###eoif===-1192-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");
}
      AKA_mark("lis===317###sois===12386###eois===12407###lif===33###soif===1292###eoif===1313###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");last_type = names[i];

      AKA_mark("lis===319###sois===12417###eois===12446###lif===35###soif===1323###eoif===1352###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << sizes[i] << " ";
    }
    AKA_mark("lis===321###sois===12459###eois===12482###lif===37###soif===1365###eoif===1388###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << std::endl;
  }

  AKA_mark("lis===324###sois===12493###eois===12530###lif===40###soif===1399###eoif===1436###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::map<std::string, bool> typedict;
  int AKA_BLOCK_LOOP_12534 = 0;
    AKA_mark("lis===325###sois===12538###eois===12551###lif===41###soif===1444###eoif===1457###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");
for(size_t i = 0; AKA_mark("lis===325###sois===12552###eois===12568###lif===41###soif===1458###eoif===1474###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (AKA_mark("lis===325###sois===12552###eois===12568###lif===41###soif===1458###eoif===1474###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (i < names.size())); ({AKA_mark("lis===325###sois===12570###eois===12573###lif===41###soif===1476###eoif===1479###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");i++;})) {
        AKA_BLOCK_LOOP_12534++;
        if (AKA_BLOCK_LOOP_12534 > 1000) {
            //break;
        }
    AKA_mark("lis===326###sois===12582###eois===12608###lif===42###soif===1488###eoif===1514###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");typedict[names[i]] = true;
  }

  if(AKA_mark("lis===329###sois===12622###eois===12628###lif===45###soif===1528###eoif===1534###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (AKA_mark("lis===329###sois===12622###eois===12628###lif===45###soif===1528###eoif===1534###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (!error))) {
    if(AKA_mark("lis===330###sois===12640###eois===12657###lif===46###soif===1546###eoif===1563###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (AKA_mark("lis===330###sois===12640###eois===12657###lif===46###soif===1546###eoif===1563###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (!typedict["IHDR"]))) {
AKA_mark("lis===330###sois===12659###eois===12708###lif===46###soif===1565###eoif===1614###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << "Error: no IHDR chunk" << std::endl;
}

else {
AKA_mark("lis===-330-###sois===-12640-###eois===-1264017-###lif===-46-###soif===-###eoif===-1563-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");
}
    if(AKA_mark("lis===331###sois===12717###eois===12734###lif===47###soif===1623###eoif===1640###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (AKA_mark("lis===331###sois===12717###eois===12734###lif===47###soif===1623###eoif===1640###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (!typedict["IDAT"]))) {
AKA_mark("lis===331###sois===12736###eois===12785###lif===47###soif===1642###eoif===1691###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << "Error: no IDAT chunk" << std::endl;
}

else {
AKA_mark("lis===-331-###sois===-12717-###eois===-1271717-###lif===-47-###soif===-###eoif===-1640-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");
}
    if(AKA_mark("lis===332###sois===12794###eois===12811###lif===48###soif===1700###eoif===1717###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (AKA_mark("lis===332###sois===12794###eois===12811###lif===48###soif===1700###eoif===1717###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)") && (!typedict["IEND"]))) {
AKA_mark("lis===332###sois===12813###eois===12862###lif===48###soif===1719###eoif===1768###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");std::cout << "Error: no IEND chunk" << std::endl;
}

else {
AKA_mark("lis===-332-###sois===-12794-###eois===-1279417-###lif===-48-###soif===-###eoif===-1717-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");
}
  }
else {
AKA_mark("lis===-329-###sois===-12622-###eois===-126226-###lif===-45-###soif===-###eoif===-1534-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayChunkNames(Data&,Options const&)");
}
}

/** Instrumented function RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*) */
void RGBtoHSL(unsigned char r, unsigned char g, unsigned char b, unsigned char* h, unsigned char* s, unsigned char* l) /* << Aka begin of function void RGBtoHSL(unsigned char r, unsigned char g, unsigned char b, unsigned char* h, unsigned char* s, unsigned char* l) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.RGBtoHSL.12879.stub"

  AKA_mark("lis===337###sois===12998###eois===13047###lif===1###soif===124###eoif===173###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");int cmax = std::max<int>(r, std::max<int>(g, b));
  AKA_mark("lis===338###sois===13051###eois===13100###lif===2###soif===177###eoif===226###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");int cmin = std::min<int>(r, std::min<int>(g, b));
  if(AKA_mark("lis===339###sois===13107###eois===13119###lif===3###soif===233###eoif===245###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)") && (AKA_mark("lis===339###sois===13107###eois===13119###lif===3###soif===233###eoif===245###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)") && (cmin == cmax))) {
    AKA_mark("lis===340###sois===13128###eois===13140###lif===4###soif===254###eoif===266###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");*h = *s = 0;
    AKA_mark("lis===341###sois===13146###eois===13153###lif===5###soif===272###eoif===279###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");*l = r;
  } else {
    AKA_mark("lis===343###sois===13171###eois===13193###lif===7###soif===297###eoif===319###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");int sum = cmin + cmax;
    AKA_mark("lis===344###sois===13199###eois===13222###lif===8###soif===325###eoif===348###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");int diff = cmax - cmin;
    AKA_mark("lis===345###sois===13228###eois===13241###lif===9###soif===354###eoif===367###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");*l = sum / 2;
    AKA_mark("lis===346###sois===13247###eois===13298###lif===10###soif===373###eoif===424###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");*s = 255 * diff / ((*l < 128) ? sum : (512 - sum));
    AKA_mark("lis===347###sois===13304###eois===13429###lif===11###soif===430###eoif===555###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");int hi = (r == cmax) ? (255 * (g - b) / diff) : ((g == cmax) ? (512 + 255 * (b - r) / diff) : (1024 + 255 * (r - g) / diff));
    AKA_mark("lis===348###sois===13435###eois===13457###lif===12###soif===561###eoif===583###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHSL(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");*h = ((hi / 6) & 255);
  }
}

/*
HCT: Hue, Chroma, Tone: returns a linear combination between a pure hue and a greyscale value.
*) Chroma: The linear combination factor: 255 for pure hue, 0 for pure greyscale
*) Tone: greyscale to mix with: 0 = black (shade), 255 = white (tint), in between = grey (tone)
*/
/** Instrumented function RGBtoHCT(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*) */
void RGBtoHCT(unsigned char r, unsigned char g, unsigned char b, unsigned char* h, unsigned char* c, unsigned char* t) /* << Aka begin of function void RGBtoHCT(unsigned char r, unsigned char g, unsigned char b, unsigned char* h, unsigned char* c, unsigned char* t) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHCT(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.RGBtoHCT.13757.stub"

  AKA_mark("lis===358###sois===13876###eois===13925###lif===1###soif===124###eoif===173###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHCT(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");int cmax = std::max<int>(r, std::max<int>(g, b));
  AKA_mark("lis===359###sois===13929###eois===13978###lif===2###soif===177###eoif===226###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHCT(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");int cmin = std::min<int>(r, std::min<int>(g, b));
  AKA_mark("lis===360###sois===13982###eois===14009###lif===3###soif===230###eoif===257###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHCT(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");RGBtoHSL(r, g, b, h, c, t);
  AKA_mark("lis===361###sois===14013###eois===14030###lif===4###soif===261###eoif===278###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHCT(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");*c = cmax - cmin;
  AKA_mark("lis===362###sois===14034###eois===14088###lif===5###soif===282###eoif===336###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHCT(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");*t = *c == 255 ? 0 : 255 * cmin / (255 + cmin - cmax);
}

// add 32 to get small letter instead of capital
/** Instrumented function HueToLetter(int) */
char HueToLetter(int h) /* << Aka begin of function char HueToLetter(int h) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.HueToLetter.14150.stub"

  AKA_mark("lis===367###sois===14174###eois===14188###lif===1###soif===29###eoif===43###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");char hl = 'R';
  // 12 unique hue letters for 30 degree increment hues.
  if(AKA_mark("lis===369###sois===14253###eois===14271###lif===3###soif===108###eoif===126###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && ((AKA_mark("lis===369###sois===14253###eois===14259###lif===3###soif===108###eoif===114###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h < 11)) || (AKA_mark("lis===369###sois===14263###eois===14271###lif===3###soif===118###eoif===126###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h >= 244)))) {
AKA_mark("lis===369###sois===14273###eois===14282###lif===3###soif===128###eoif===137###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");hl = 'R';
}
  // red
  else {
if(AKA_mark("lis===370###sois===14302###eois===14319###lif===4###soif===157###eoif===174###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && ((AKA_mark("lis===370###sois===14302###eois===14309###lif===4###soif===157###eoif===164###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h >= 11)) && (AKA_mark("lis===370###sois===14313###eois===14319###lif===4###soif===168###eoif===174###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h < 32)))) {
AKA_mark("lis===370###sois===14321###eois===14330###lif===4###soif===176###eoif===185###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");hl = 'O';
}
  // orange
  else {
if(AKA_mark("lis===371###sois===14353###eois===14370###lif===5###soif===208###eoif===225###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && ((AKA_mark("lis===371###sois===14353###eois===14360###lif===5###soif===208###eoif===215###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h >= 32)) && (AKA_mark("lis===371###sois===14364###eois===14370###lif===5###soif===219###eoif===225###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h < 53)))) {
AKA_mark("lis===371###sois===14372###eois===14381###lif===5###soif===227###eoif===236###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");hl = 'Y';
}
  // yellow
  else {
if(AKA_mark("lis===372###sois===14404###eois===14421###lif===6###soif===259###eoif===276###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && ((AKA_mark("lis===372###sois===14404###eois===14411###lif===6###soif===259###eoif===266###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h >= 53)) && (AKA_mark("lis===372###sois===14415###eois===14421###lif===6###soif===270###eoif===276###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h < 74)))) {
AKA_mark("lis===372###sois===14423###eois===14432###lif===6###soif===278###eoif===287###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");hl = 'L';
}
  // lime (officialy "chartreuse" but c is for cyan)
  else {
if(AKA_mark("lis===373###sois===14496###eois===14513###lif===7###soif===351###eoif===368###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && ((AKA_mark("lis===373###sois===14496###eois===14503###lif===7###soif===351###eoif===358###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h >= 74)) && (AKA_mark("lis===373###sois===14507###eois===14513###lif===7###soif===362###eoif===368###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h < 96)))) {
AKA_mark("lis===373###sois===14515###eois===14524###lif===7###soif===370###eoif===379###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");hl = 'G';
}
  // green
  else {
if(AKA_mark("lis===374###sois===14546###eois===14564###lif===8###soif===401###eoif===419###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && ((AKA_mark("lis===374###sois===14546###eois===14553###lif===8###soif===401###eoif===408###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h >= 96)) && (AKA_mark("lis===374###sois===14557###eois===14564###lif===8###soif===412###eoif===419###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h < 117)))) {
AKA_mark("lis===374###sois===14566###eois===14575###lif===8###soif===421###eoif===430###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");hl = 'T';
}
  // turquoise (officially "spring green" but that name overlaps green)
  else {
if(AKA_mark("lis===375###sois===14658###eois===14677###lif===9###soif===513###eoif===532###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && ((AKA_mark("lis===375###sois===14658###eois===14666###lif===9###soif===513###eoif===521###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h >= 117)) && (AKA_mark("lis===375###sois===14670###eois===14677###lif===9###soif===525###eoif===532###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h < 138)))) {
AKA_mark("lis===375###sois===14679###eois===14688###lif===9###soif===534###eoif===543###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");hl = 'C';
}
  // cyan
  else {
if(AKA_mark("lis===376###sois===14709###eois===14728###lif===10###soif===564###eoif===583###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && ((AKA_mark("lis===376###sois===14709###eois===14717###lif===10###soif===564###eoif===572###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h >= 138)) && (AKA_mark("lis===376###sois===14721###eois===14728###lif===10###soif===576###eoif===583###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h < 159)))) {
AKA_mark("lis===376###sois===14730###eois===14739###lif===10###soif===585###eoif===594###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");hl = 'A';
}
  // azure
  else {
if(AKA_mark("lis===377###sois===14761###eois===14780###lif===11###soif===616###eoif===635###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && ((AKA_mark("lis===377###sois===14761###eois===14769###lif===11###soif===616###eoif===624###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h >= 159)) && (AKA_mark("lis===377###sois===14773###eois===14780###lif===11###soif===628###eoif===635###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h < 181)))) {
AKA_mark("lis===377###sois===14782###eois===14791###lif===11###soif===637###eoif===646###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");hl = 'B';
}
  // blue
  else {
if(AKA_mark("lis===378###sois===14812###eois===14831###lif===12###soif===667###eoif===686###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && ((AKA_mark("lis===378###sois===14812###eois===14820###lif===12###soif===667###eoif===675###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h >= 181)) && (AKA_mark("lis===378###sois===14824###eois===14831###lif===12###soif===679###eoif===686###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h < 202)))) {
AKA_mark("lis===378###sois===14833###eois===14842###lif===12###soif===688###eoif===697###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");hl = 'V';
}
  // violet
  else {
if(AKA_mark("lis===379###sois===14865###eois===14884###lif===13###soif===720###eoif===739###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && ((AKA_mark("lis===379###sois===14865###eois===14873###lif===13###soif===720###eoif===728###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h >= 202)) && (AKA_mark("lis===379###sois===14877###eois===14884###lif===13###soif===732###eoif===739###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h < 223)))) {
AKA_mark("lis===379###sois===14886###eois===14895###lif===13###soif===741###eoif===750###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");hl = 'M';
}
  // magenta
  else {
if(AKA_mark("lis===380###sois===14919###eois===14938###lif===14###soif===774###eoif===793###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && ((AKA_mark("lis===380###sois===14919###eois===14927###lif===14###soif===774###eoif===782###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h >= 223)) && (AKA_mark("lis===380###sois===14931###eois===14938###lif===14###soif===786###eoif===793###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)") && (h < 244)))) {
AKA_mark("lis===380###sois===14940###eois===14949###lif===14###soif===795###eoif===804###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");hl = 'F';
}

else {
AKA_mark("lis===-380-###sois===-14919-###eois===-1491919-###lif===-14-###soif===-###eoif===-793-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");
}
}

}

}

}

}

}

}

}

}

}

}
  // fuchsia (officially "rose" but r is for red)
  AKA_mark("lis===381###sois===15002###eois===15012###lif===15###soif===857###eoif===867###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\HueToLetter(int)");return hl;
}

/** Instrumented function lightnessToLetter(int) */
char lightnessToLetter(int l) /* << Aka begin of function char lightnessToLetter(int l) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.lightnessToLetter.15024.stub"

  AKA_mark("lis===385###sois===15054###eois===15066###lif===1###soif===35###eoif===47###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)");int c = ' ';
  if(AKA_mark("lis===386###sois===15073###eois===15079###lif===2###soif===54###eoif===60###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (AKA_mark("lis===386###sois===15073###eois===15079###lif===2###soif===54###eoif===60###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (l < 16))) {
AKA_mark("lis===386###sois===15081###eois===15089###lif===2###soif===62###eoif===70###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)");c = ' ';
}

  else {
if(AKA_mark("lis===387###sois===15101###eois===15107###lif===3###soif===82###eoif===88###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (AKA_mark("lis===387###sois===15101###eois===15107###lif===3###soif===82###eoif===88###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (l < 48))) {
AKA_mark("lis===387###sois===15109###eois===15117###lif===3###soif===90###eoif===98###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)");c = '.';
}

  else {
if(AKA_mark("lis===388###sois===15129###eois===15135###lif===4###soif===110###eoif===116###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (AKA_mark("lis===388###sois===15129###eois===15135###lif===4###soif===110###eoif===116###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (l < 80))) {
AKA_mark("lis===388###sois===15137###eois===15145###lif===4###soif===118###eoif===126###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)");c = ':';
}

  else {
if(AKA_mark("lis===389###sois===15157###eois===15164###lif===5###soif===138###eoif===145###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (AKA_mark("lis===389###sois===15157###eois===15164###lif===5###soif===138###eoif===145###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (l < 112))) {
AKA_mark("lis===389###sois===15166###eois===15174###lif===5###soif===147###eoif===155###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)");c = '-';
}

  else {
if(AKA_mark("lis===390###sois===15186###eois===15193###lif===6###soif===167###eoif===174###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (AKA_mark("lis===390###sois===15186###eois===15193###lif===6###soif===167###eoif===174###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (l < 144))) {
AKA_mark("lis===390###sois===15195###eois===15203###lif===6###soif===176###eoif===184###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)");c = '!';
}

  else {
if(AKA_mark("lis===391###sois===15215###eois===15222###lif===7###soif===196###eoif===203###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (AKA_mark("lis===391###sois===15215###eois===15222###lif===7###soif===196###eoif===203###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (l < 176))) {
AKA_mark("lis===391###sois===15224###eois===15232###lif===7###soif===205###eoif===213###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)");c = '*';
}

  else {
if(AKA_mark("lis===392###sois===15244###eois===15251###lif===8###soif===225###eoif===232###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (AKA_mark("lis===392###sois===15244###eois===15251###lif===8###soif===225###eoif===232###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (l < 208))) {
AKA_mark("lis===392###sois===15253###eois===15261###lif===8###soif===234###eoif===242###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)");c = '+';
}
 // The + looks denser than the * in a terminal...
  else {
if(AKA_mark("lis===393###sois===15323###eois===15330###lif===9###soif===304###eoif===311###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (AKA_mark("lis===393###sois===15323###eois===15330###lif===9###soif===304###eoif===311###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)") && (l < 240))) {
AKA_mark("lis===393###sois===15332###eois===15340###lif===9###soif===313###eoif===321###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)");c = '=';
}

  else {
AKA_mark("lis===394###sois===15349###eois===15357###lif===10###soif===330###eoif===338###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)");c = '#';
}

}

}

}

}

}

}

}

  AKA_mark("lis===395###sois===15361###eois===15370###lif===11###soif===342###eoif===351###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\lightnessToLetter(int)");return c;
}

// Both v and result are assumed in range 0-255
// range is the size of an individual bucket. A value in roughly range [-range/2, range/2) can get added to v.
// E.g. if there are 12 hue letters, give 255/12 = 21 as range
/** Instrumented function applyDither(int,int,int,int,bool) */
static inline int applyDither(int v, int range, int x, int y, bool wrap) /* << Aka begin of function int applyDither(int v, int range, int x, int y, bool wrap) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\applyDither(int,int,int,int,bool)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.applyDither.15620.stub"

  // ordered dithering pattern; ranges from 0-15, so multiply with 17 to have 0-255
  AKA_mark("lis===403###sois===15765###eois===15944###lif===2###soif===163###eoif===342###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\applyDither(int,int,int,int,bool)");static const int pattern[16] = {0,8,2,10,
                                  12,4,14,6,
                                  3,11,1,9,
                                  15,7,13,5};
  AKA_mark("lis===407###sois===15948###eois===15998###lif===6###soif===346###eoif===396###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\applyDither(int,int,int,int,bool)");int d = pattern[(x & 3) + 4 * (y & 3)] * 17 - 128; // range: -128 to 127
  if(AKA_mark("lis===408###sois===16027###eois===16031###lif===7###soif===425###eoif===429###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\applyDither(int,int,int,int,bool)") && (AKA_mark("lis===408###sois===16027###eois===16031###lif===7###soif===425###eoif===429###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\applyDither(int,int,int,int,bool)") && (wrap))) {
AKA_mark("lis===408###sois===16033###eois===16068###lif===7###soif===431###eoif===466###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\applyDither(int,int,int,int,bool)");return (v + d * range / 256) & 255;
}

  else {
AKA_mark("lis===409###sois===16077###eois===16132###lif===8###soif===475###eoif===530###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\applyDither(int,int,int,int,bool)");return std::max(0, std::min(255, v + d * range / 256));
}

}

// x and y are to use for dithering
// inverted inverts black and white, for in case black text on white background is used (by default it assumes white text on black background)
/** Instrumented function RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false) */
char RGBtoLetter(unsigned char r, unsigned char g, unsigned char b, unsigned char a, unsigned x, unsigned y, bool dither = true, bool inverted = false) /* << Aka begin of function char RGBtoLetter(unsigned char r, unsigned char g, unsigned char b, unsigned char a, unsigned x, unsigned y, bool dither = true, bool inverted = false) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.RGBtoLetter.16325.stub"

  if(AKA_mark("lis===415###sois===16480###eois===16487###lif===1###soif===160###eoif===167###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (AKA_mark("lis===415###sois===16480###eois===16487###lif===1###soif===160###eoif===167###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (a < 255))) {
    AKA_mark("lis===416###sois===16496###eois===16512###lif===2###soif===176###eoif===192###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");r = a * r / 255;
    AKA_mark("lis===417###sois===16518###eois===16534###lif===3###soif===198###eoif===214###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");g = a * g / 255;
    AKA_mark("lis===418###sois===16540###eois===16556###lif===4###soif===220###eoif===236###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");b = a * b / 255;
  }
else {
AKA_mark("lis===-415-###sois===-16480-###eois===-164807-###lif===-1-###soif===-###eoif===-167-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");
}

  if(AKA_mark("lis===421###sois===16570###eois===16576###lif===7###soif===250###eoif===256###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (AKA_mark("lis===421###sois===16570###eois===16576###lif===7###soif===250###eoif===256###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (dither))) {
    AKA_mark("lis===422###sois===16585###eois===16607###lif===8###soif===265###eoif===287###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");unsigned char h, c, t;
    AKA_mark("lis===423###sois===16613###eois===16643###lif===9###soif===293###eoif===323###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");RGBtoHCT(r, g, b, &h, &c, &t);
    AKA_mark("lis===424###sois===16649###eois===16721###lif===10###soif===329###eoif===401###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");int l = (std::max(std::max(r, g), b) + std::min(std::min(r, g), b)) / 2;
    if(AKA_mark("lis===425###sois===16730###eois===16738###lif===11###soif===410###eoif===418###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (AKA_mark("lis===425###sois===16730###eois===16738###lif===11###soif===410###eoif===418###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (inverted))) {
      AKA_mark("lis===426###sois===16749###eois===16761###lif===12###soif===429###eoif===441###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");l = 255 - l;
      AKA_mark("lis===427###sois===16769###eois===16781###lif===13###soif===449###eoif===461###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");t = 255 - t;
    }
else {
AKA_mark("lis===-425-###sois===-16730-###eois===-167308-###lif===-11-###soif===-###eoif===-418-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");
}
    if(AKA_mark("lis===429###sois===16797###eois===16836###lif===15###soif===477###eoif===516###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (AKA_mark("lis===429###sois===16797###eois===16836###lif===15###soif===477###eoif===516###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (applyDither(c, 254, x, y, false) >= 128))) {
      AKA_mark("lis===430###sois===16847###eois===16905###lif===16###soif===527###eoif===585###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");char letter = HueToLetter(applyDither(h, 21, x, y, true));
      AKA_mark("lis===431###sois===16913###eois===16971###lif===17###soif===593###eoif===651###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");bool smallcaps = applyDither(l, 64, x+2, y+2, false) < 80;
      AKA_mark("lis===432###sois===16979###eois===17016###lif===18###soif===659###eoif===696###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");return letter + (smallcaps ? 32 : 0);
    }
    else {
AKA_mark("lis===434###sois===17034###eois===17092###lif===20###soif===714###eoif===772###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");return lightnessToLetter(applyDither(l, 31, x, y, false));
}

  } else {
    AKA_mark("lis===436###sois===17110###eois===17132###lif===22###soif===790###eoif===812###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");unsigned char h, s, l;
    AKA_mark("lis===437###sois===17138###eois===17168###lif===23###soif===818###eoif===848###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");RGBtoHSL(r, g, b, &h, &s, &l);
    if(AKA_mark("lis===438###sois===17177###eois===17185###lif===24###soif===857###eoif===865###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (AKA_mark("lis===438###sois===17177###eois===17185###lif===24###soif===857###eoif===865###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (inverted))) {
AKA_mark("lis===438###sois===17187###eois===17199###lif===24###soif===867###eoif===879###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");l = 255 - l;
}

else {
AKA_mark("lis===-438-###sois===-17177-###eois===-171778-###lif===-24-###soif===-###eoif===-865-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");
}

    AKA_mark("lis===440###sois===17207###eois===17232###lif===26###soif===887###eoif===912###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");char hl = HueToLetter(h);
    AKA_mark("lis===441###sois===17238###eois===17251###lif===27###soif===918###eoif===931###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");char c = ' ';
    if(AKA_mark("lis===442###sois===17260###eois===17287###lif===28###soif===940###eoif===967###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (((AKA_mark("lis===442###sois===17260###eois===17266###lif===28###soif===940###eoif===946###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (l < 24)) || (AKA_mark("lis===442###sois===17270###eois===17277###lif===28###soif===950###eoif===957###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (l > 232))) || (AKA_mark("lis===442###sois===17281###eois===17287###lif===28###soif===961###eoif===967###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (s < 64)))) {
      AKA_mark("lis===443###sois===17298###eois===17323###lif===29###soif===978###eoif===1003###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");c = lightnessToLetter(l);
    } else {
      if(AKA_mark("lis===445###sois===17348###eois===17355###lif===31###soif===1028###eoif===1035###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (AKA_mark("lis===445###sois===17348###eois===17355###lif===31###soif===1028###eoif===1035###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)") && (l < 128))) {
AKA_mark("lis===445###sois===17357###eois===17369###lif===31###soif===1037###eoif===1049###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");c = hl + 32;
}

      else {
AKA_mark("lis===446###sois===17382###eois===17389###lif===32###soif===1062###eoif===1069###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");c = hl;
}

    }
    AKA_mark("lis===448###sois===17402###eois===17411###lif===34###soif===1082###eoif===1091###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoLetter(unsigned char,unsigned char,unsigned char,unsigned char,unsigned,unsigned,bool= true,bool= false)");return c;
  }
}

/** Instrumented function rescale(std::vector<unsigned char>const&,int,int,int,int,bool) */
std::vector<unsigned char> rescale(const std::vector<unsigned char>& in,
                                   int w0, int h0, int w1, int h1, bool smooth) /* << Aka begin of function std::vector<unsigned char> rescale(const std::vector<unsigned char>& in,
                                   int w0, int h0, int w1, int h1, bool smooth) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.rescale.17450.stub"

  AKA_mark("lis===454###sois===17582###eois===17622###lif===2###soif===159###eoif===199###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");int numchannels = in.size() / (w0 * h0);
  AKA_mark("lis===455###sois===17626###eois===17680###lif===3###soif===203###eoif===257###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");std::vector<unsigned char> out(w1 * h1 * numchannels);
  if(AKA_mark("lis===456###sois===17687###eois===17693###lif===4###soif===264###eoif===270###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (AKA_mark("lis===456###sois===17687###eois===17693###lif===4###soif===264###eoif===270###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (smooth))) {
    // box filter.
    AKA_mark("lis===458###sois===17722###eois===17777###lif===6###soif===299###eoif===354###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");std::vector<unsigned char> temp(w1 * h0 * numchannels);
    int AKA_BLOCK_LOOP_17783 = 0;
    AKA_mark("lis===459###sois===17787###eois===17797###lif===7###soif===364###eoif===374###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
for(int c = 0; AKA_mark("lis===459###sois===17798###eois===17813###lif===7###soif===375###eoif===390###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (AKA_mark("lis===459###sois===17798###eois===17813###lif===7###soif===375###eoif===390###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (c < numchannels)); ({AKA_mark("lis===459###sois===17815###eois===17818###lif===7###soif===392###eoif===395###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");c++;})) {
        AKA_BLOCK_LOOP_17783++;
        if (AKA_BLOCK_LOOP_17783 > 1000) {
            //break;
        }
      int AKA_BLOCK_LOOP_17829 = 0;
    AKA_mark("lis===460###sois===17833###eois===17843###lif===8###soif===410###eoif===420###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
for(int x = 0; AKA_mark("lis===460###sois===17844###eois===17850###lif===8###soif===421###eoif===427###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (AKA_mark("lis===460###sois===17844###eois===17850###lif===8###soif===421###eoif===427###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (x < w1)); ({AKA_mark("lis===460###sois===17852###eois===17855###lif===8###soif===429###eoif===432###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");x++;})) {
        AKA_BLOCK_LOOP_17829++;
        if (AKA_BLOCK_LOOP_17829 > 1000) {
            //break;
        }
        AKA_mark("lis===461###sois===17868###eois===17898###lif===9###soif===445###eoif===475###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");float xaf = x * 1.0 * w0 / w1;
        AKA_mark("lis===462###sois===17908###eois===17940###lif===10###soif===485###eoif===517###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");float xbf = (x + 1.0) * w0 / w1;
        AKA_mark("lis===463###sois===17950###eois===17968###lif===11###soif===527###eoif===545###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");int xa = (int)xaf;
        AKA_mark("lis===464###sois===17978###eois===17996###lif===12###soif===555###eoif===573###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");int xb = (int)xbf;
        AKA_mark("lis===465###sois===18006###eois===18038###lif===13###soif===583###eoif===615###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");double norm = 1.0 / (xbf - xaf);
        AKA_mark("lis===466###sois===18048###eois===18071###lif===14###soif===625###eoif===648###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");xaf -= std::floor(xaf);
        AKA_mark("lis===467###sois===18081###eois===18104###lif===15###soif===658###eoif===681###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");xbf -= std::floor(xbf);
        int AKA_BLOCK_LOOP_18114 = 0;
    AKA_mark("lis===468###sois===18118###eois===18128###lif===16###soif===695###eoif===705###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
for(int y = 0; AKA_mark("lis===468###sois===18129###eois===18135###lif===16###soif===706###eoif===712###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (AKA_mark("lis===468###sois===18129###eois===18135###lif===16###soif===706###eoif===712###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (y < h0)); ({AKA_mark("lis===468###sois===18137###eois===18140###lif===16###soif===714###eoif===717###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");y++;})) {
        AKA_BLOCK_LOOP_18114++;
        if (AKA_BLOCK_LOOP_18114 > 1000) {
            //break;
        }
          AKA_mark("lis===469###sois===18155###eois===18207###lif===17###soif===732###eoif===784###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");int index1 = x * numchannels + y * w1 * numchannels;
          AKA_mark("lis===470###sois===18219###eois===18234###lif===18###soif===796###eoif===811###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");double val = 0;
          int AKA_BLOCK_LOOP_18246 = 0;
    AKA_mark("lis===471###sois===18250###eois===18262###lif===19###soif===827###eoif===839###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
for(int x0 = xa; AKA_mark("lis===471###sois===18263###eois===18282###lif===19###soif===840###eoif===859###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && ((AKA_mark("lis===471###sois===18263###eois===18271###lif===19###soif===840###eoif===848###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (x0 <= xb)) && (AKA_mark("lis===471###sois===18275###eois===18282###lif===19###soif===852###eoif===859###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (x0 < w0))); ({AKA_mark("lis===471###sois===18284###eois===18288###lif===19###soif===861###eoif===865###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");x0++;})) {
        AKA_BLOCK_LOOP_18246++;
        if (AKA_BLOCK_LOOP_18246 > 1000) {
            //break;
        }
            AKA_mark("lis===472###sois===18305###eois===18358###lif===20###soif===882###eoif===935###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");int index0 = x0 * numchannels + y * w0 * numchannels;
            AKA_mark("lis===473###sois===18372###eois===18385###lif===21###soif===949###eoif===962###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");double v = 1;
            if(AKA_mark("lis===474###sois===18402###eois===18410###lif===22###soif===979###eoif===987###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (AKA_mark("lis===474###sois===18402###eois===18410###lif===22###soif===979###eoif===987###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (x0 == xa))) {
AKA_mark("lis===474###sois===18412###eois===18421###lif===22###soif===989###eoif===998###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");v -= xaf;
}

else {
AKA_mark("lis===-474-###sois===-18402-###eois===-184028-###lif===-22-###soif===-###eoif===-987-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
}
            if(AKA_mark("lis===475###sois===18438###eois===18446###lif===23###soif===1015###eoif===1023###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (AKA_mark("lis===475###sois===18438###eois===18446###lif===23###soif===1015###eoif===1023###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (x0 == xb))) {
AKA_mark("lis===475###sois===18448###eois===18463###lif===23###soif===1025###eoif===1040###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");v -= (1 - xbf);
}

else {
AKA_mark("lis===-475-###sois===-18438-###eois===-184388-###lif===-23-###soif===-###eoif===-1023-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
}
            AKA_mark("lis===476###sois===18477###eois===18503###lif===24###soif===1054###eoif===1080###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");val += v * in[index0 + c];
          }
          AKA_mark("lis===478###sois===18528###eois===18558###lif===26###soif===1105###eoif===1135###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");temp[index1 + c] = val * norm;
        }
      }
      int AKA_BLOCK_LOOP_18586 = 0;
    AKA_mark("lis===481###sois===18590###eois===18600###lif===29###soif===1167###eoif===1177###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
for(int y = 0; AKA_mark("lis===481###sois===18601###eois===18607###lif===29###soif===1178###eoif===1184###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (AKA_mark("lis===481###sois===18601###eois===18607###lif===29###soif===1178###eoif===1184###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (y < h1)); ({AKA_mark("lis===481###sois===18609###eois===18612###lif===29###soif===1186###eoif===1189###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");y++;})) {
        AKA_BLOCK_LOOP_18586++;
        if (AKA_BLOCK_LOOP_18586 > 1000) {
            //break;
        }
        AKA_mark("lis===482###sois===18625###eois===18655###lif===30###soif===1202###eoif===1232###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");float yaf = y * 1.0 * h0 / h1;
        AKA_mark("lis===483###sois===18665###eois===18697###lif===31###soif===1242###eoif===1274###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");float ybf = (y + 1.0) * h0 / h1;
        AKA_mark("lis===484###sois===18707###eois===18725###lif===32###soif===1284###eoif===1302###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");int ya = (int)yaf;
        AKA_mark("lis===485###sois===18735###eois===18753###lif===33###soif===1312###eoif===1330###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");int yb = (int)ybf;
        AKA_mark("lis===486###sois===18763###eois===18795###lif===34###soif===1340###eoif===1372###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");double norm = 1.0 / (ybf - yaf);
        AKA_mark("lis===487###sois===18805###eois===18828###lif===35###soif===1382###eoif===1405###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");yaf -= std::floor(yaf);
        AKA_mark("lis===488###sois===18838###eois===18861###lif===36###soif===1415###eoif===1438###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");ybf -= std::floor(ybf);
        int AKA_BLOCK_LOOP_18871 = 0;
    AKA_mark("lis===489###sois===18875###eois===18885###lif===37###soif===1452###eoif===1462###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
for(int x = 0; AKA_mark("lis===489###sois===18886###eois===18892###lif===37###soif===1463###eoif===1469###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (AKA_mark("lis===489###sois===18886###eois===18892###lif===37###soif===1463###eoif===1469###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (x < w1)); ({AKA_mark("lis===489###sois===18894###eois===18897###lif===37###soif===1471###eoif===1474###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");x++;})) {
        AKA_BLOCK_LOOP_18871++;
        if (AKA_BLOCK_LOOP_18871 > 1000) {
            //break;
        }
          AKA_mark("lis===490###sois===18912###eois===18964###lif===38###soif===1489###eoif===1541###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");int index1 = x * numchannels + y * w1 * numchannels;
          AKA_mark("lis===491###sois===18976###eois===18991###lif===39###soif===1553###eoif===1568###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");double val = 0;
          int AKA_BLOCK_LOOP_19003 = 0;
    AKA_mark("lis===492###sois===19007###eois===19019###lif===40###soif===1584###eoif===1596###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
for(int y0 = ya; AKA_mark("lis===492###sois===19020###eois===19039###lif===40###soif===1597###eoif===1616###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && ((AKA_mark("lis===492###sois===19020###eois===19028###lif===40###soif===1597###eoif===1605###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (y0 <= yb)) && (AKA_mark("lis===492###sois===19032###eois===19039###lif===40###soif===1609###eoif===1616###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (y0 < h0))); ({AKA_mark("lis===492###sois===19041###eois===19045###lif===40###soif===1618###eoif===1622###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");y0++;})) {
        AKA_BLOCK_LOOP_19003++;
        if (AKA_BLOCK_LOOP_19003 > 1000) {
            //break;
        }
            AKA_mark("lis===493###sois===19062###eois===19115###lif===41###soif===1639###eoif===1692###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");int index0 = x * numchannels + y0 * w1 * numchannels;
            AKA_mark("lis===494###sois===19129###eois===19142###lif===42###soif===1706###eoif===1719###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");double v = 1;
            if(AKA_mark("lis===495###sois===19159###eois===19167###lif===43###soif===1736###eoif===1744###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (AKA_mark("lis===495###sois===19159###eois===19167###lif===43###soif===1736###eoif===1744###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (y0 == ya))) {
AKA_mark("lis===495###sois===19169###eois===19178###lif===43###soif===1746###eoif===1755###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");v -= yaf;
}

else {
AKA_mark("lis===-495-###sois===-19159-###eois===-191598-###lif===-43-###soif===-###eoif===-1744-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
}
            if(AKA_mark("lis===496###sois===19195###eois===19203###lif===44###soif===1772###eoif===1780###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (AKA_mark("lis===496###sois===19195###eois===19203###lif===44###soif===1772###eoif===1780###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (y0 == yb))) {
AKA_mark("lis===496###sois===19205###eois===19220###lif===44###soif===1782###eoif===1797###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");v -= (1 - ybf);
}

else {
AKA_mark("lis===-496-###sois===-19195-###eois===-191958-###lif===-44-###soif===-###eoif===-1780-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
}
            AKA_mark("lis===497###sois===19234###eois===19262###lif===45###soif===1811###eoif===1839###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");val += v * temp[index0 + c];
          }
          AKA_mark("lis===499###sois===19287###eois===19316###lif===47###soif===1864###eoif===1893###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");out[index1 + c] = val * norm;
        }
      }
    }
  } else {
    int AKA_BLOCK_LOOP_19361 = 0;
    AKA_mark("lis===504###sois===19365###eois===19375###lif===52###soif===1942###eoif===1952###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
for(int y = 0; AKA_mark("lis===504###sois===19376###eois===19382###lif===52###soif===1953###eoif===1959###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (AKA_mark("lis===504###sois===19376###eois===19382###lif===52###soif===1953###eoif===1959###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (y < h1)); ({AKA_mark("lis===504###sois===19384###eois===19387###lif===52###soif===1961###eoif===1964###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");y++;})) {
        AKA_BLOCK_LOOP_19361++;
        if (AKA_BLOCK_LOOP_19361 > 1000) {
            //break;
        }
      AKA_mark("lis===505###sois===19398###eois===19440###lif===53###soif===1975###eoif===2017###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");int y0 = (int)((y + 0.5) * h0 / h1 - 0.5);
      int AKA_BLOCK_LOOP_19448 = 0;
    AKA_mark("lis===506###sois===19453###eois===19463###lif===54###soif===2030###eoif===2040###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
for (int x = 0; AKA_mark("lis===506###sois===19464###eois===19470###lif===54###soif===2041###eoif===2047###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (AKA_mark("lis===506###sois===19464###eois===19470###lif===54###soif===2041###eoif===2047###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (x < w1)); ({AKA_mark("lis===506###sois===19472###eois===19475###lif===54###soif===2049###eoif===2052###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");x++;})) {
        AKA_BLOCK_LOOP_19448++;
        if (AKA_BLOCK_LOOP_19448 > 1000) {
            //break;
        }
        AKA_mark("lis===507###sois===19488###eois===19530###lif===55###soif===2065###eoif===2107###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");int x0 = (int)((x + 0.5) * w0 / w1 - 0.5);
        AKA_mark("lis===508###sois===19540###eois===19594###lif===56###soif===2117###eoif===2171###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");int index0 = x0 * numchannels + y0 * w0 * numchannels;
        AKA_mark("lis===509###sois===19604###eois===19656###lif===57###soif===2181###eoif===2233###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");int index1 = x * numchannels + y * w1 * numchannels;
        int AKA_BLOCK_LOOP_19666 = 0;
    AKA_mark("lis===510###sois===19671###eois===19681###lif===58###soif===2248###eoif===2258###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");
for (int c = 0; AKA_mark("lis===510###sois===19682###eois===19697###lif===58###soif===2259###eoif===2274###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (AKA_mark("lis===510###sois===19682###eois===19697###lif===58###soif===2259###eoif===2274###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)") && (c < numchannels)); ({AKA_mark("lis===510###sois===19699###eois===19702###lif===58###soif===2276###eoif===2279###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");c++;})) {
        AKA_BLOCK_LOOP_19666++;
        if (AKA_BLOCK_LOOP_19666 > 1000) {
            //break;
        }
          AKA_mark("lis===511###sois===19717###eois===19750###lif===59###soif===2294###eoif===2327###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");out[index1 + c] = in[index0 + c];
        }
      }
    }
  }
  AKA_mark("lis===516###sois===19786###eois===19797###lif===64###soif===2363###eoif===2374###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\rescale(std::vector<unsigned char>const&,int,int,int,int,bool)");return out;
}

/*
Show ASCII art preview of the image
Image is given in 16-bit big endian (because only one format, with the max possible precision, is used throughout this)
*/
/** Instrumented function displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned) */
void displayAsciiArt(const std::vector<unsigned char>& image, unsigned w, unsigned h, unsigned asciiw) /* << Aka begin of function void displayAsciiArt(const std::vector<unsigned char>& image, unsigned w, unsigned h, unsigned asciiw) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.displayAsciiArt.19975.stub"

  AKA_mark("lis===524###sois===20078###eois===20128###lif===1###soif===108###eoif===158###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");const std::vector<unsigned char>* imagep = &image;
  AKA_mark("lis===525###sois===20132###eois===20166###lif===2###soif===162###eoif===196###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");std::vector<unsigned char> image2;
  if(AKA_mark("lis===526###sois===20173###eois===20183###lif===3###soif===203###eoif===213###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)") && (AKA_mark("lis===526###sois===20173###eois===20183###lif===3###soif===203###eoif===213###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)") && (asciiw < w))) {
    AKA_mark("lis===527###sois===20192###eois===20213###lif===4###soif===222###eoif===243###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");unsigned w2 = asciiw;
    AKA_mark("lis===528###sois===20219###eois===20244###lif===5###soif===249###eoif===274###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");unsigned h2 = h * w2 / w;
    AKA_mark("lis===529###sois===20250###eois===20294###lif===6###soif===280###eoif===324###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");image2 = rescale(image, w, h, w2, h2, true);
    AKA_mark("lis===530###sois===20300###eois===20317###lif===7###soif===330###eoif===347###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");imagep = &image2;
    AKA_mark("lis===531###sois===20323###eois===20330###lif===8###soif===353###eoif===360###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");w = w2;
    AKA_mark("lis===532###sois===20336###eois===20343###lif===9###soif===366###eoif===373###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");h = h2;
  }
else {
AKA_mark("lis===-526-###sois===-20173-###eois===-2017310-###lif===-3-###soif===-###eoif===-213-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");
}
  if(AKA_mark("lis===534###sois===20355###eois===20369###lif===11###soif===385###eoif===399###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)") && ((AKA_mark("lis===534###sois===20355###eois===20360###lif===11###soif===385###eoif===390###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)") && (w > 0)) && (AKA_mark("lis===534###sois===20364###eois===20369###lif===11###soif===394###eoif===399###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)") && (h > 0)))) {
    AKA_mark("lis===535###sois===20378###eois===20426###lif===12###soif===408###eoif===456###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");std::cout << "ASCII Art Preview: " << std::endl;
    AKA_mark("lis===536###sois===20432###eois===20468###lif===13###soif===462###eoif===498###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");unsigned h2 = 1 + ((h - 1) * 4) / 7; //compensate for non-square characters in terminal
    AKA_mark("lis===537###sois===20525###eois===20542###lif===14###soif===555###eoif===572###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");std::cout << '+';
    int AKA_BLOCK_LOOP_20548 = 0;
    AKA_mark("lis===538###sois===20552###eois===20567###lif===15###soif===582###eoif===597###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");
for(unsigned x = 0; AKA_mark("lis===538###sois===20568###eois===20573###lif===15###soif===598###eoif===603###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)") && (AKA_mark("lis===538###sois===20568###eois===20573###lif===15###soif===598###eoif===603###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)") && (x < w)); ({AKA_mark("lis===538###sois===20575###eois===20578###lif===15###soif===605###eoif===608###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");x++;})) {
AKA_mark("lis===538###sois===20580###eois===20597###lif===15###soif===610###eoif===627###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");std::cout << '-';
}

    AKA_mark("lis===539###sois===20603###eois===20633###lif===16###soif===633###eoif===663###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");std::cout << '+' << std::endl;
    int AKA_BLOCK_LOOP_20639 = 0;
    AKA_mark("lis===540###sois===20643###eois===20658###lif===17###soif===673###eoif===688###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");
for(unsigned y = 0; AKA_mark("lis===540###sois===20659###eois===20665###lif===17###soif===689###eoif===695###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)") && (AKA_mark("lis===540###sois===20659###eois===20665###lif===17###soif===689###eoif===695###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)") && (y < h2)); ({AKA_mark("lis===540###sois===20667###eois===20670###lif===17###soif===697###eoif===700###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");y++;})) {
        AKA_BLOCK_LOOP_20639++;
        if (AKA_BLOCK_LOOP_20639 > 1000) {
            //break;
        }
      AKA_mark("lis===541###sois===20681###eois===20698###lif===18###soif===711###eoif===728###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");std::cout << "|";
      AKA_mark("lis===542###sois===20706###eois===20731###lif===19###soif===736###eoif===761###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");unsigned y2 = y * h / h2;
      int AKA_BLOCK_LOOP_20739 = 0;
    AKA_mark("lis===543###sois===20743###eois===20758###lif===20###soif===773###eoif===788###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");
for(unsigned x = 0; AKA_mark("lis===543###sois===20759###eois===20764###lif===20###soif===789###eoif===794###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)") && (AKA_mark("lis===543###sois===20759###eois===20764###lif===20###soif===789###eoif===794###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)") && (x < w)); ({AKA_mark("lis===543###sois===20766###eois===20769###lif===20###soif===796###eoif===799###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");x++;})) {
        AKA_BLOCK_LOOP_20739++;
        if (AKA_BLOCK_LOOP_20739 > 1000) {
            //break;
        }
        AKA_mark("lis===544###sois===20782###eois===20824###lif===21###soif===812###eoif===854###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");int r = (*imagep)[y2 * w * 8 + x * 8 + 0];
        AKA_mark("lis===545###sois===20834###eois===20876###lif===22###soif===864###eoif===906###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");int g = (*imagep)[y2 * w * 8 + x * 8 + 2];
        AKA_mark("lis===546###sois===20886###eois===20928###lif===23###soif===916###eoif===958###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");int b = (*imagep)[y2 * w * 8 + x * 8 + 4];
        AKA_mark("lis===547###sois===20938###eois===20980###lif===24###soif===968###eoif===1010###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");int a = (*imagep)[y2 * w * 8 + x * 8 + 6];
        AKA_mark("lis===548###sois===20990###eois===21047###lif===25###soif===1020###eoif===1077###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");char symbol = RGBtoLetter(r, g, b, a, x, y, true, false);
        AKA_mark("lis===549###sois===21057###eois===21083###lif===26###soif===1087###eoif===1113###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");std::cout << (char)symbol;
      }
      AKA_mark("lis===551###sois===21100###eois===21117###lif===28###soif===1130###eoif===1147###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");std::cout << "|";
      AKA_mark("lis===552###sois===21125###eois===21148###lif===29###soif===1155###eoif===1178###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");std::cout << std::endl;
    }
    AKA_mark("lis===554###sois===21161###eois===21178###lif===31###soif===1191###eoif===1208###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");std::cout << '+';
    int AKA_BLOCK_LOOP_21184 = 0;
    AKA_mark("lis===555###sois===21188###eois===21203###lif===32###soif===1218###eoif===1233###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");
for(unsigned x = 0; AKA_mark("lis===555###sois===21204###eois===21209###lif===32###soif===1234###eoif===1239###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)") && (AKA_mark("lis===555###sois===21204###eois===21209###lif===32###soif===1234###eoif===1239###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)") && (x < w)); ({AKA_mark("lis===555###sois===21211###eois===21214###lif===32###soif===1241###eoif===1244###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");x++;})) {
AKA_mark("lis===555###sois===21216###eois===21233###lif===32###soif===1246###eoif===1263###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");std::cout << '-';
}

    AKA_mark("lis===556###sois===21239###eois===21269###lif===33###soif===1269###eoif===1299###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");std::cout << '+' << std::endl;
  }
else {
AKA_mark("lis===-534-###sois===-20355-###eois===-2035514-###lif===-11-###soif===-###eoif===-399-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayAsciiArt(std::vector<unsigned char>const&,unsigned,unsigned,unsigned)");
}
}

//sixteen: print 16 bits per pixel
//alpha: print alpha channel
//input image ALWAYS given in 16-bit per channel RGBA
/** Instrumented function displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool) */
void displayColorsHex(const std::vector<unsigned char>& image, unsigned w, unsigned h, bool sixteen) /* << Aka begin of function void displayColorsHex(const std::vector<unsigned char>& image, unsigned w, unsigned h, bool sixteen) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.displayColorsHex.21407.stub"

  AKA_mark("lis===564###sois===21508###eois===21558###lif===1###soif===106###eoif===156###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");std::ios_base::fmtflags flags = std::cout.flags();

  if(AKA_mark("lis===566###sois===21567###eois===21581###lif===3###soif===165###eoif===179###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)") && ((AKA_mark("lis===566###sois===21567###eois===21572###lif===3###soif===165###eoif===170###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)") && (w > 0)) && (AKA_mark("lis===566###sois===21576###eois===21581###lif===3###soif===174###eoif===179###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)") && (h > 0)))) {
    AKA_mark("lis===567###sois===21590###eois===21648###lif===4###soif===188###eoif===246###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");std::cout << "Colors (CSS RGBA hex format):" << std::endl;

    int AKA_BLOCK_LOOP_21656 = 0;
    AKA_mark("lis===569###sois===21660###eois===21675###lif===6###soif===258###eoif===273###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");
for(unsigned y = 0; AKA_mark("lis===569###sois===21676###eois===21681###lif===6###soif===274###eoif===279###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)") && (AKA_mark("lis===569###sois===21676###eois===21681###lif===6###soif===274###eoif===279###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)") && (y < h)); ({AKA_mark("lis===569###sois===21683###eois===21686###lif===6###soif===281###eoif===284###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");y++;})) {
        AKA_BLOCK_LOOP_21656++;
        if (AKA_BLOCK_LOOP_21656 > 1000) {
            //break;
        }
      AKA_mark("lis===570###sois===21697###eois===21720###lif===7###soif===295###eoif===318###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");std::cout.flags(flags); //print line numbers in hex or dec whatever it originally was
      AKA_mark("lis===571###sois===21790###eois===21812###lif===8###soif===388###eoif===410###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");std::cout << y << ":";
      int AKA_BLOCK_LOOP_21820 = 0;
    AKA_mark("lis===572###sois===21824###eois===21839###lif===9###soif===422###eoif===437###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");
for(unsigned x = 0; AKA_mark("lis===572###sois===21840###eois===21845###lif===9###soif===438###eoif===443###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)") && (AKA_mark("lis===572###sois===21840###eois===21845###lif===9###soif===438###eoif===443###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)") && (x < w)); ({AKA_mark("lis===572###sois===21847###eois===21850###lif===9###soif===445###eoif===448###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");x++;})) {
        AKA_BLOCK_LOOP_21820++;
        if (AKA_BLOCK_LOOP_21820 > 1000) {
            //break;
        }
        AKA_mark("lis===573###sois===21863###eois===21896###lif===10###soif===461###eoif===494###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");size_t index = y * w * 8 + x * 8;
        if (AKA_mark("lis===574###sois===21910###eois===21917###lif===11###soif===508###eoif===515###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)") && (AKA_mark("lis===574###sois===21910###eois===21917###lif===11###soif===508###eoif===515###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)") && (sixteen))) {
          AKA_mark("lis===575###sois===21932###eois===21982###lif===12###soif===530###eoif===580###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");int r = image[index + 0] * 256 + image[index + 1];
          AKA_mark("lis===576###sois===21994###eois===22044###lif===13###soif===592###eoif===642###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");int g = image[index + 2] * 256 + image[index + 3];
          AKA_mark("lis===577###sois===22056###eois===22106###lif===14###soif===654###eoif===704###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");int b = image[index + 4] * 256 + image[index + 5];
          AKA_mark("lis===578###sois===22118###eois===22168###lif===15###soif===716###eoif===766###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");int a = image[index + 6] * 256 + image[index + 7];
          AKA_mark("lis===579###sois===22180###eois===22315###lif===16###soif===778###eoif===913###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");std::cout << std::hex << std::setfill('0') << " #" << std::setw(4) << r << std::setw(4) << g << std::setw(4) << b << std::setw(4) << a;
        } else {
          AKA_mark("lis===581###sois===22345###eois===22370###lif===18###soif===943###eoif===968###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");int r = image[index + 0];
          AKA_mark("lis===582###sois===22382###eois===22407###lif===19###soif===980###eoif===1005###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");int g = image[index + 2];
          AKA_mark("lis===583###sois===22419###eois===22444###lif===20###soif===1017###eoif===1042###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");int b = image[index + 4];
          AKA_mark("lis===584###sois===22456###eois===22481###lif===21###soif===1054###eoif===1079###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");int a = image[index + 6];
          AKA_mark("lis===585###sois===22493###eois===22628###lif===22###soif===1091###eoif===1226###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");std::cout << std::hex << std::setfill('0') << " #" << std::setw(2) << r << std::setw(2) << g << std::setw(2) << b << std::setw(2) << a;
        }
      }
      AKA_mark("lis===588###sois===22656###eois===22679###lif===25###soif===1254###eoif===1277###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");std::cout << std::endl;
    }
  }
else {
AKA_mark("lis===-566-###sois===-21567-###eois===-2156714-###lif===-3-###soif===-###eoif===-179-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");
}

  AKA_mark("lis===592###sois===22697###eois===22720###lif===29###soif===1295###eoif===1318###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayColorsHex(std::vector<unsigned char>const&,unsigned,unsigned,bool)");std::cout.flags(flags);
}


/*
Show the filtertypes of each scanline in this PNG image.
*/
/** Instrumented function displayFilterTypes(Data&,Options const&) */
void displayFilterTypes(Data& data, const Options& options) /* << Aka begin of function void displayFilterTypes(Data& data, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.displayFilterTypes.22800.stub"

  AKA_mark("lis===600###sois===22860###eois===22912###lif===1###soif===65###eoif===117###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");std::cout << (options.use_hex ? std::hex: std::dec);
  AKA_mark("lis===601###sois===22916###eois===22932###lif===2###soif===121###eoif===137###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");data.loadFile();
  if(AKA_mark("lis===602###sois===22939###eois===22949###lif===3###soif===144###eoif===154###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)") && (AKA_mark("lis===602###sois===22939###eois===22949###lif===3###soif===144###eoif===154###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)") && (data.error))) {
AKA_mark("lis===602###sois===22951###eois===22958###lif===3###soif===156###eoif===163###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");return;
}

else {
AKA_mark("lis===-602-###sois===-22939-###eois===-2293910-###lif===-3-###soif===-###eoif===-154-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");
}
  AKA_mark("lis===603###sois===22962###eois===23017###lif===4###soif===167###eoif===222###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");const std::vector<unsigned char>& buffer = data.buffer;
  AKA_mark("lis===604###sois===23021###eois===23068###lif===5###soif===226###eoif===273###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");std::vector<std::vector<unsigned char> > types;
  AKA_mark("lis===605###sois===23072###eois===23138###lif===6###soif===277###eoif===343###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");unsigned error = lodepng::getFilterTypesInterlaced(types, buffer);
  if(AKA_mark("lis===606###sois===23145###eois===23150###lif===7###soif===350###eoif===355###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)") && (AKA_mark("lis===606###sois===23145###eois===23150###lif===7###soif===350###eoif===355###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)") && (error))) {
    AKA_mark("lis===607###sois===23159###eois===23214###lif===8###soif===364###eoif===419###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");std::cout << "Error getting filter types" << std::endl;
    AKA_mark("lis===608###sois===23220###eois===23227###lif===9###soif===425###eoif===432###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");return;
  }
else {
AKA_mark("lis===-606-###sois===-23145-###eois===-231455-###lif===-7-###soif===-###eoif===-355-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");
}

  if(AKA_mark("lis===611###sois===23241###eois===23258###lif===12###soif===446###eoif===463###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)") && (AKA_mark("lis===611###sois===23241###eois===23258###lif===12###soif===446###eoif===463###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)") && (types.size() == 7))) {
    AKA_mark("lis===612###sois===23267###eois===23328###lif===13###soif===472###eoif===533###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");std::cout << "Filter types (Adam7 interlaced):" << std::endl;
    int AKA_BLOCK_LOOP_23334 = 0;
    AKA_mark("lis===613###sois===23338###eois===23348###lif===14###soif===543###eoif===553###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");
for(int j = 0; AKA_mark("lis===613###sois===23349###eois===23354###lif===14###soif===554###eoif===559###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)") && (AKA_mark("lis===613###sois===23349###eois===23354###lif===14###soif===554###eoif===559###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)") && (j < 7)); ({AKA_mark("lis===613###sois===23356###eois===23359###lif===14###soif===561###eoif===564###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");j++;})) {
        AKA_BLOCK_LOOP_23334++;
        if (AKA_BLOCK_LOOP_23334 > 1000) {
            //break;
        }
      AKA_mark("lis===614###sois===23370###eois===23411###lif===15###soif===575###eoif===616###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");std::cout << " Pass " << (j + 1) << ": ";
      int AKA_BLOCK_LOOP_23419 = 0;
    AKA_mark("lis===615###sois===23423###eois===23436###lif===16###soif===628###eoif===641###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");
for(size_t i = 0; AKA_mark("lis===615###sois===23437###eois===23456###lif===16###soif===642###eoif===661###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)") && (AKA_mark("lis===615###sois===23437###eois===23456###lif===16###soif===642###eoif===661###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)") && (i < types[j].size())); ({AKA_mark("lis===615###sois===23458###eois===23461###lif===16###soif===663###eoif===666###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");i++;})) {
        AKA_BLOCK_LOOP_23419++;
        if (AKA_BLOCK_LOOP_23419 > 1000) {
            //break;
        }
        AKA_mark("lis===616###sois===23474###eois===23506###lif===17###soif===679###eoif===711###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");std::cout << (int)(types[j][i]);
      }
      AKA_mark("lis===618###sois===23523###eois===23546###lif===19###soif===728###eoif===751###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");std::cout << std::endl;
    }
  } else {
    AKA_mark("lis===621###sois===23571###eois===23601###lif===22###soif===776###eoif===806###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");std::cout << "Filter types: ";
    int AKA_BLOCK_LOOP_23607 = 0;
    AKA_mark("lis===622###sois===23611###eois===23624###lif===23###soif===816###eoif===829###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");
for(size_t i = 0; AKA_mark("lis===622###sois===23625###eois===23644###lif===23###soif===830###eoif===849###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)") && (AKA_mark("lis===622###sois===23625###eois===23644###lif===23###soif===830###eoif===849###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)") && (i < types[0].size())); ({AKA_mark("lis===622###sois===23646###eois===23649###lif===23###soif===851###eoif===854###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");i++;})) {
        AKA_BLOCK_LOOP_23607++;
        if (AKA_BLOCK_LOOP_23607 > 1000) {
            //break;
        }
      AKA_mark("lis===623###sois===23660###eois===23692###lif===24###soif===865###eoif===897###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");std::cout << (int)(types[0][i]);
    }
    AKA_mark("lis===625###sois===23705###eois===23728###lif===26###soif===910###eoif===933###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayFilterTypes(Data&,Options const&)");std::cout << std::endl;
  }
}

//image type MUST be palette
/** Instrumented function displayPalette(Data&,Options const&) */
void displayPalette(Data& data, const Options& options) /* << Aka begin of function void displayPalette(Data& data, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.displayPalette.23775.stub"

  AKA_mark("lis===631###sois===23831###eois===23850###lif===1###soif===61###eoif===80###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");data.loadInspect();
  if(AKA_mark("lis===632###sois===23857###eois===23867###lif===2###soif===87###eoif===97###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)") && (AKA_mark("lis===632###sois===23857###eois===23867###lif===2###soif===87###eoif===97###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)") && (data.error))) {
AKA_mark("lis===632###sois===23869###eois===23876###lif===2###soif===99###eoif===106###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");return;
}

else {
AKA_mark("lis===-632-###sois===-23857-###eois===-2385710-###lif===-2-###soif===-###eoif===-97-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");
}
  AKA_mark("lis===633###sois===23880###eois===23932###lif===3###soif===110###eoif===162###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");std::cout << (options.use_hex ? std::hex: std::dec);

  AKA_mark("lis===635###sois===23938###eois===23984###lif===5###soif===168###eoif===214###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");const LodePNGInfo& info = data.state.info_png;
  AKA_mark("lis===636###sois===23988###eois===24031###lif===6###soif===218###eoif===261###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");const LodePNGColorMode& color = info.color;

  AKA_mark("lis===638###sois===24037###eois===24101###lif===8###soif===267###eoif===331###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");std::cout << "Palette size: " << color.palettesize << std::endl;
  AKA_mark("lis===639###sois===24105###eois===24137###lif===9###soif===335###eoif===367###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");std::cout << "Palette colors: ";
  AKA_mark("lis===640###sois===24141###eois===24191###lif===10###soif===371###eoif===421###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");std::ios_base::fmtflags flags = std::cout.flags();
  AKA_mark("lis===641###sois===24195###eois===24238###lif===11###soif===425###eoif===468###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");std::cout << std::hex << std::setfill('0');
  int AKA_BLOCK_LOOP_24242 = 0;
    AKA_mark("lis===642###sois===24246###eois===24259###lif===12###soif===476###eoif===489###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");
for(size_t i = 0; AKA_mark("lis===642###sois===24260###eois===24281###lif===12###soif===490###eoif===511###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)") && (AKA_mark("lis===642###sois===24260###eois===24281###lif===12###soif===490###eoif===511###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)") && (i < color.palettesize)); ({AKA_mark("lis===642###sois===24283###eois===24286###lif===12###soif===513###eoif===516###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");i++;})) {
        AKA_BLOCK_LOOP_24242++;
        if (AKA_BLOCK_LOOP_24242 > 1000) {
            //break;
        }
    AKA_mark("lis===643###sois===24295###eois===24336###lif===13###soif===525###eoif===566###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");unsigned char* p = &color.palette[i * 4];
    AKA_mark("lis===644###sois===24342###eois===24482###lif===14###soif===572###eoif===712###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");std::cout << "#" << std::setw(2) << (int)p[0] << std::setw(2) << (int)p[1] << std::setw(2) << (int)p[2] << std::setw(2) << (int)p[3] << " ";
  }
  AKA_mark("lis===646###sois===24491###eois===24514###lif===16###soif===721###eoif===744###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");std::cout.flags(flags);
  AKA_mark("lis===647###sois===24518###eois===24541###lif===17###soif===748###eoif===771###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalette(Data&,Options const&)");std::cout << std::endl;
}

//image type MUST be palette
/** Instrumented function displayPalettePixels(std::vector<unsigned char>const&,Options const&) */
void displayPalettePixels(const std::vector<unsigned char>& buffer, const Options& options) /* << Aka begin of function void displayPalettePixels(const std::vector<unsigned char>& buffer, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.displayPalettePixels.24583.stub"

  AKA_mark("lis===652###sois===24675###eois===24689###lif===1###soif===97###eoif===111###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");unsigned w, h;
  AKA_mark("lis===653###sois===24693###eois===24714###lif===2###soif===115###eoif===136###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");lodepng::State state;
  AKA_mark("lis===654###sois===24718###eois===24749###lif===3###soif===140###eoif===171###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");std::vector<unsigned char> out;
  AKA_mark("lis===655###sois===24753###eois===24805###lif===4###soif===175###eoif===227###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");std::cout << (options.use_hex ? std::hex: std::dec);

  AKA_mark("lis===657###sois===24811###eois===24843###lif===6###soif===233###eoif===265###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");state.decoder.color_convert = 0;

  AKA_mark("lis===659###sois===24849###eois===24891###lif===8###soif===271###eoif===313###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");lodepng::decode(out, w, h, state, buffer);

  if(AKA_mark("lis===661###sois===24900###eois===24945###lif===10###soif===322###eoif===367###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (AKA_mark("lis===661###sois===24900###eois===24945###lif===10###soif===322###eoif===367###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (state.info_png.color.colortype == LCT_PALETTE))) {
    if (AKA_mark("lis===662###sois===24958###eois===24982###lif===11###soif===380###eoif===404###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (AKA_mark("lis===662###sois===24958###eois===24982###lif===11###soif===380###eoif===404###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (options.show_color_stats))) {
      AKA_mark("lis===663###sois===24993###eois===25027###lif===12###soif===415###eoif===449###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");std::vector<size_t> count(256, 0);
      AKA_mark("lis===664###sois===25035###eois===25058###lif===13###soif===457###eoif===480###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");size_t outofbounds = 0;

      int AKA_BLOCK_LOOP_25068 = 0;
    AKA_mark("lis===666###sois===25072###eois===25085###lif===15###soif===494###eoif===507###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");
for(size_t i = 0; AKA_mark("lis===666###sois===25086###eois===25095###lif===15###soif===508###eoif===517###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (AKA_mark("lis===666###sois===25086###eois===25095###lif===15###soif===508###eoif===517###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (i < w * h)); ({AKA_mark("lis===666###sois===25097###eois===25100###lif===15###soif===519###eoif===522###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");i++;})) {
        AKA_BLOCK_LOOP_25068++;
        if (AKA_BLOCK_LOOP_25068 > 1000) {
            //break;
        }
        AKA_mark("lis===667###sois===25113###eois===25187###lif===16###soif===535###eoif===609###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");int value = lodepng::getPaletteValue(&out[0], i, state.info_raw.bitdepth);
        AKA_mark("lis===668###sois===25197###eois===25212###lif===17###soif===619###eoif===634###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");count[value]++;
        if(AKA_mark("lis===669###sois===25225###eois===25265###lif===18###soif===647###eoif===687###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (AKA_mark("lis===669###sois===25225###eois===25265###lif===18###soif===647###eoif===687###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (value >= (int)state.info_raw.palettesize))) {
AKA_mark("lis===669###sois===25267###eois===25281###lif===18###soif===689###eoif===703###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");outofbounds++;
}

else {
AKA_mark("lis===-669-###sois===-25225-###eois===-2522540-###lif===-18-###soif===-###eoif===-687-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");
}
      }

      AKA_mark("lis===672###sois===25300###eois===25331###lif===21###soif===722###eoif===753###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");std::cout << "Palette count: ";
      int AKA_BLOCK_LOOP_25339 = 0;
    AKA_mark("lis===673###sois===25343###eois===25356###lif===22###soif===765###eoif===778###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");
for(size_t i = 0; AKA_mark("lis===673###sois===25357###eois===25387###lif===22###soif===779###eoif===809###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (AKA_mark("lis===673###sois===25357###eois===25387###lif===22###soif===779###eoif===809###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (i < state.info_raw.palettesize)); ({AKA_mark("lis===673###sois===25389###eois===25392###lif===22###soif===811###eoif===814###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");i++;})) {
        AKA_BLOCK_LOOP_25339++;
        if (AKA_BLOCK_LOOP_25339 > 1000) {
            //break;
        }
        AKA_mark("lis===674###sois===25405###eois===25434###lif===23###soif===827###eoif===856###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");std::cout << count[i] << " ";
      }
      AKA_mark("lis===676###sois===25451###eois===25474###lif===25###soif===873###eoif===896###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");std::cout << std::endl;

      if(AKA_mark("lis===678###sois===25487###eois===25502###lif===27###soif===909###eoif===924###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (AKA_mark("lis===678###sois===25487###eois===25502###lif===27###soif===909###eoif===924###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (outofbounds > 0))) {
AKA_mark("lis===678###sois===25504###eois===25578###lif===27###soif===926###eoif===1000###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");std::cout << "Out of bounds palette values: " << outofbounds << std::endl;
}

else {
AKA_mark("lis===-678-###sois===-25487-###eois===-2548715-###lif===-27-###soif===-###eoif===-924-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");
}
    }
else {
AKA_mark("lis===-662-###sois===-24958-###eois===-2495824-###lif===-11-###soif===-###eoif===-404-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");
}

    AKA_mark("lis===681###sois===25593###eois===25644###lif===30###soif===1015###eoif===1066###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");std::cout << "Pixel palette indices:" << std::endl;
    int AKA_BLOCK_LOOP_25650 = 0;
    AKA_mark("lis===682###sois===25654###eois===25667###lif===31###soif===1076###eoif===1089###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");
for(size_t i = 0; AKA_mark("lis===682###sois===25668###eois===25677###lif===31###soif===1090###eoif===1099###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (AKA_mark("lis===682###sois===25668###eois===25677###lif===31###soif===1090###eoif===1099###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (i < w * h)); ({AKA_mark("lis===682###sois===25679###eois===25682###lif===31###soif===1101###eoif===1104###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");i++;})) {
        AKA_BLOCK_LOOP_25650++;
        if (AKA_BLOCK_LOOP_25650 > 1000) {
            //break;
        }
      AKA_mark("lis===683###sois===25693###eois===25767###lif===32###soif===1115###eoif===1189###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");int value = lodepng::getPaletteValue(&out[0], i, state.info_raw.bitdepth);
      AKA_mark("lis===684###sois===25775###eois===25802###lif===33###soif===1197###eoif===1224###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");std::cout << value << ", ";
      if(AKA_mark("lis===685###sois===25813###eois===25827###lif===34###soif===1235###eoif===1249###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (AKA_mark("lis===685###sois===25813###eois===25827###lif===34###soif===1235###eoif===1249###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)") && (i % w == w - 1))) {
AKA_mark("lis===685###sois===25829###eois===25852###lif===34###soif===1251###eoif===1274###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");std::cout << std::endl;
}

else {
AKA_mark("lis===-685-###sois===-25813-###eois===-2581314-###lif===-34-###soif===-###eoif===-1249-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");
}
    }
  } else {
    AKA_mark("lis===688###sois===25877###eois===25961###lif===37###soif===1299###eoif===1383###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\displayPalettePixels(std::vector<unsigned char>const&,Options const&)");std::cout << "Pixel palette indices: not shown, not a palette image\n" << std::endl;
  }
}

/** Instrumented function printZlibInfo(Data&) */
void printZlibInfo(Data& data) /* << Aka begin of function void printZlibInfo(Data& data) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.printZlibInfo.25978.stub"

  AKA_mark("lis===693###sois===26009###eois===26025###lif===1###soif===36###eoif===52###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");data.loadFile();
  if(AKA_mark("lis===694###sois===26032###eois===26059###lif===2###soif===59###eoif===86###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && ((AKA_mark("lis===694###sois===26032###eois===26042###lif===2###soif===59###eoif===69###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (data.error)) || (AKA_mark("lis===694###sois===26046###eois===26059###lif===2###soif===73###eoif===86###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (!data.isPng())))) {
AKA_mark("lis===694###sois===26061###eois===26068###lif===2###soif===88###eoif===95###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");return;
}

else {
AKA_mark("lis===-694-###sois===-26032-###eois===-2603227-###lif===-2-###soif===-###eoif===-86-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");
}
  AKA_mark("lis===695###sois===26072###eois===26124###lif===3###soif===99###eoif===151###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");const std::vector<unsigned char>& png = data.buffer;

  //Read literal data from all IDAT chunks
  AKA_mark("lis===698###sois===26174###eois===26215###lif===6###soif===201###eoif===242###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");const unsigned char *chunk, *begin, *end;
  AKA_mark("lis===699###sois===26219###eois===26241###lif===7###soif===246###eoif===268###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");end = &png.back() + 1;
  AKA_mark("lis===700###sois===26245###eois===26278###lif===8###soif===272###eoif===305###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");begin = chunk = &png.front() + 8;

  AKA_mark("lis===702###sois===26284###eois===26322###lif===10###soif===311###eoif===349###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");std::vector<unsigned char> compressed;

  int AKA_BLOCK_LOOP_26328 = 0;
    while(AKA_mark("lis===704###sois===26334###eois===26365###lif===12###soif===361###eoif===392###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && ((AKA_mark("lis===704###sois===26334###eois===26345###lif===12###soif===361###eoif===372###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (chunk < end)) && (AKA_mark("lis===704###sois===26349###eois===26365###lif===12###soif===376###eoif===392###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (end - chunk >= 8)))) {
        AKA_BLOCK_LOOP_26328++;
        if (AKA_BLOCK_LOOP_26328 > 1000) {
            //break;
        }
    AKA_mark("lis===705###sois===26374###eois===26387###lif===13###soif===401###eoif===414###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");char type[5];
    AKA_mark("lis===706###sois===26393###eois===26425###lif===14###soif===420###eoif===452###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");lodepng_chunk_type(type, chunk);
    if(AKA_mark("lis===707###sois===26434###eois===26463###lif===15###soif===461###eoif===490###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (AKA_mark("lis===707###sois===26434###eois===26463###lif===15###soif===461###eoif===490###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (std::string(type).size() != 4))) {
      AKA_mark("lis===708###sois===26474###eois===26514###lif===16###soif===501###eoif===541###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");std::cout << "invalid png" << std::endl;
      AKA_mark("lis===709###sois===26522###eois===26529###lif===17###soif===549###eoif===556###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");return;
    }
else {
AKA_mark("lis===-707-###sois===-26434-###eois===-2643429-###lif===-15-###soif===-###eoif===-490-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");
}

    if(AKA_mark("lis===712###sois===26547###eois===26574###lif===20###soif===574###eoif===601###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (AKA_mark("lis===712###sois===26547###eois===26574###lif===20###soif===574###eoif===601###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (std::string(type) == "IDAT"))) {
      AKA_mark("lis===713###sois===26585###eois===26646###lif===21###soif===612###eoif===673###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");const unsigned char* cdata = lodepng_chunk_data_const(chunk);
      AKA_mark("lis===714###sois===26654###eois===26701###lif===22###soif===681###eoif===728###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");unsigned clength = lodepng_chunk_length(chunk);
      if(AKA_mark("lis===715###sois===26712###eois===26794###lif===23###soif===739###eoif===821###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (((AKA_mark("lis===715###sois===26712###eois===26738###lif===23###soif===739###eoif===765###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (chunk + clength + 12 > end)) || (AKA_mark("lis===715###sois===26742###eois===26762###lif===23###soif===769###eoif===789###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (clength > png.size()))) || (AKA_mark("lis===715###sois===26766###eois===26794###lif===23###soif===793###eoif===821###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (chunk + clength + 12 < begin)))) {
        AKA_mark("lis===716###sois===26807###eois===26856###lif===24###soif===834###eoif===883###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");std::cout << "corrupt chunk length" << std::endl;
        AKA_mark("lis===717###sois===26866###eois===26873###lif===25###soif===893###eoif===900###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");return;
      }
else {
AKA_mark("lis===-715-###sois===-26712-###eois===-2671282-###lif===-23-###soif===-###eoif===-821-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");
}
      AKA_mark("lis===719###sois===26890###eois===26950###lif===27###soif===917###eoif===977###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");compressed.insert(compressed.end(), cdata, cdata + clength);
    }
else {
AKA_mark("lis===-712-###sois===-26547-###eois===-2654727-###lif===-20-###soif===-###eoif===-601-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");
}

    AKA_mark("lis===722###sois===26965###eois===27010###lif===30###soif===992###eoif===1037###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");chunk = lodepng_chunk_next_const(chunk, end);
  }

  if(AKA_mark("lis===725###sois===27024###eois===27046###lif===33###soif===1051###eoif===1073###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (AKA_mark("lis===725###sois===27024###eois===27046###lif===33###soif===1051###eoif===1073###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (compressed.size() >= 3))) {
    AKA_mark("lis===726###sois===27055###eois===27086###lif===34###soif===1082###eoif===1113###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");int bfinal = compressed[2] & 1;
    AKA_mark("lis===727###sois===27092###eois===27129###lif===35###soif===1119###eoif===1156###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");int btype = (compressed[2] & 6) >> 1;
    if(AKA_mark("lis===728###sois===27138###eois===27144###lif===36###soif===1165###eoif===1171###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (AKA_mark("lis===728###sois===27138###eois===27144###lif===36###soif===1165###eoif===1171###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (bfinal))) {
      AKA_mark("lis===729###sois===27155###eois===27236###lif===37###soif===1182###eoif===1263###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");std::cout << "zlib data stored in a single block, btype: " << btype << std::endl;
    } else {
      AKA_mark("lis===731###sois===27258###eois===27354###lif===39###soif===1285###eoif===1381###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");std::cout << "zlib data spread over multiple blocks. First block btype: " << btype << std::endl;
    }
  }
else {
AKA_mark("lis===-725-###sois===-27024-###eois===-2702422-###lif===-33-###soif===-###eoif===-1073-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");
}

  AKA_mark("lis===735###sois===27372###eois===27444###lif===43###soif===1399###eoif===1471###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");std::cout << "zlib compressed size: " << compressed.size() << std::endl;

  //Decompress all IDAT data (if the while loop ended early, this might fail)
  AKA_mark("lis===738###sois===27529###eois===27569###lif===46###soif===1556###eoif===1596###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");std::vector<unsigned char> uncompressed;
  AKA_mark("lis===739###sois===27573###eois===27683###lif===47###soif===1600###eoif===1710###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");data.error = lodepng::decompress(uncompressed, compressed.empty() ? NULL : &compressed[0], compressed.size());
  if(AKA_mark("lis===740###sois===27690###eois===27700###lif===48###soif===1717###eoif===1727###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (AKA_mark("lis===740###sois===27690###eois===27700###lif===48###soif===1717###eoif===1727###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)") && (data.error))) {
AKA_mark("lis===740###sois===27702###eois===27709###lif===48###soif===1729###eoif===1736###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");return;
}

else {
AKA_mark("lis===-740-###sois===-27690-###eois===-2769010-###lif===-48-###soif===-###eoif===-1727-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");
}

  AKA_mark("lis===742###sois===27715###eois===27791###lif===50###soif===1742###eoif===1818###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printZlibInfo(Data&)");std::cout << "zlib uncompressed size: " << uncompressed.size() << std::endl;
}

// returns number of unique RGBA colors in the image
// also fills unique r, g, b, a counts in the output parameters
// the input image is in 16-bit per channel color, so 8 chars per pixel
/** Instrumented function countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*) */
size_t countColors(const std::vector<unsigned char>& image, unsigned w, unsigned h,
    size_t* ro, size_t* go, size_t* bo, size_t* ao) /* << Aka begin of function size_t countColors(const std::vector<unsigned char>& image, unsigned w, unsigned h,
    size_t* ro, size_t* go, size_t* bo, size_t* ao) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.countColors.27997.stub"

  AKA_mark("lis===750###sois===28132###eois===28242###lif===2###soif===142###eoif===252###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");typedef std::pair<std::pair<unsigned short, unsigned short>, std::pair<unsigned short, unsigned short> > RGBA;
  AKA_mark("lis===751###sois===28246###eois===28275###lif===3###soif===256###eoif===285###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");std::map<RGBA, size_t> rgbam;
  //std::map<uint64_t, size_t> rgbam;
  AKA_mark("lis===753###sois===28318###eois===28358###lif===5###soif===328###eoif===368###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");std::vector<unsigned char> rm(65536, 0);
  AKA_mark("lis===754###sois===28362###eois===28402###lif===6###soif===372###eoif===412###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");std::vector<unsigned char> gm(65536, 0);
  AKA_mark("lis===755###sois===28406###eois===28446###lif===7###soif===416###eoif===456###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");std::vector<unsigned char> bm(65536, 0);
  AKA_mark("lis===756###sois===28450###eois===28490###lif===8###soif===460###eoif===500###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");std::vector<unsigned char> am(65536, 0);
  int AKA_BLOCK_LOOP_28494 = 0;
    AKA_mark("lis===757###sois===28498###eois===28513###lif===9###soif===508###eoif===523###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");
for(unsigned y = 0; AKA_mark("lis===757###sois===28514###eois===28519###lif===9###soif===524###eoif===529###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)") && (AKA_mark("lis===757###sois===28514###eois===28519###lif===9###soif===524###eoif===529###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)") && (y < h)); ({AKA_mark("lis===757###sois===28521###eois===28524###lif===9###soif===531###eoif===534###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");y++;})) {
        AKA_BLOCK_LOOP_28494++;
        if (AKA_BLOCK_LOOP_28494 > 1000) {
            //break;
        }
    int AKA_BLOCK_LOOP_28533 = 0;
    AKA_mark("lis===758###sois===28537###eois===28552###lif===10###soif===547###eoif===562###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");
for(unsigned x = 0; AKA_mark("lis===758###sois===28553###eois===28558###lif===10###soif===563###eoif===568###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)") && (AKA_mark("lis===758###sois===28553###eois===28558###lif===10###soif===563###eoif===568###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)") && (x < w)); ({AKA_mark("lis===758###sois===28560###eois===28563###lif===10###soif===570###eoif===573###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");x++;})) {
        AKA_BLOCK_LOOP_28533++;
        if (AKA_BLOCK_LOOP_28533 > 1000) {
            //break;
        }
      AKA_mark("lis===759###sois===28574###eois===28659###lif===11###soif===584###eoif===669###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");unsigned short r = 256 * image[y * 8 * w + x * 8 + 0] + image[y * 8 * w + x * 8 + 1];
      AKA_mark("lis===760###sois===28667###eois===28752###lif===12###soif===677###eoif===762###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");unsigned short g = 256 * image[y * 8 * w + x * 8 + 2] + image[y * 8 * w + x * 8 + 3];
      AKA_mark("lis===761###sois===28760###eois===28845###lif===13###soif===770###eoif===855###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");unsigned short b = 256 * image[y * 8 * w + x * 8 + 4] + image[y * 8 * w + x * 8 + 5];
      AKA_mark("lis===762###sois===28853###eois===28938###lif===14###soif===863###eoif===948###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");unsigned short a = 256 * image[y * 8 * w + x * 8 + 6] + image[y * 8 * w + x * 8 + 7];
      AKA_mark("lis===763###sois===28946###eois===29000###lif===15###soif===956###eoif===1010###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");RGBA rgba(std::make_pair(r, g), std::make_pair(b, a));
      //uint64_t rgba = (uint64_t)r + ((uint64_t)g << 16) + ((uint64_t)b << 32) + ((uint64_t)a << 48);
      AKA_mark("lis===765###sois===29112###eois===29126###lif===17###soif===1122###eoif===1136###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");rgbam[rgba]++;
      AKA_mark("lis===766###sois===29134###eois===29144###lif===18###soif===1144###eoif===1154###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");rm[r] = 1;
      AKA_mark("lis===767###sois===29152###eois===29162###lif===19###soif===1162###eoif===1172###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");gm[g] = 1;
      AKA_mark("lis===768###sois===29170###eois===29180###lif===20###soif===1180###eoif===1190###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");bm[b] = 1;
      AKA_mark("lis===769###sois===29188###eois===29198###lif===21###soif===1198###eoif===1208###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");am[a] = 1;
    }
  }
  AKA_mark("lis===772###sois===29214###eois===29240###lif===24###soif===1224###eoif===1250###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");*ro = *go = *bo = *ao = 0;
  int AKA_BLOCK_LOOP_29244 = 0;
    AKA_mark("lis===773###sois===29248###eois===29261###lif===25###soif===1258###eoif===1271###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");
for(size_t i = 0; AKA_mark("lis===773###sois===29262###eois===29275###lif===25###soif===1272###eoif===1285###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)") && (AKA_mark("lis===773###sois===29262###eois===29275###lif===25###soif===1272###eoif===1285###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)") && (i < rm.size())); ({AKA_mark("lis===773###sois===29277###eois===29280###lif===25###soif===1287###eoif===1290###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");i++;})) {
        AKA_BLOCK_LOOP_29244++;
        if (AKA_BLOCK_LOOP_29244 > 1000) {
            //break;
        }
    AKA_mark("lis===774###sois===29289###eois===29302###lif===26###soif===1299###eoif===1312###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");*ro += rm[i];
    AKA_mark("lis===775###sois===29308###eois===29321###lif===27###soif===1318###eoif===1331###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");*go += gm[i];
    AKA_mark("lis===776###sois===29327###eois===29340###lif===28###soif===1337###eoif===1350###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");*bo += bm[i];
    AKA_mark("lis===777###sois===29346###eois===29359###lif===29###soif===1356###eoif===1369###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");*ao += am[i];
  }

  AKA_mark("lis===780###sois===29370###eois===29390###lif===32###soif===1380###eoif===1400###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\countColors(std::vector<unsigned char>const&,unsigned,unsigned,size_t*,size_t*,size_t*,size_t*)");return rgbam.size();
}


/** Instrumented function showError(Data&,Options const&) */
void showError(Data& data, const Options& options) /* << Aka begin of function void showError(Data& data, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\showError(Data&,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.showError.29404.stub"

  AKA_mark("lis===785###sois===29455###eois===29507###lif===1###soif===56###eoif===108###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showError(Data&,Options const&)");std::cout << (options.use_hex ? std::hex: std::dec);
  AKA_mark("lis===786###sois===29511###eois===29561###lif===2###soif===112###eoif===162###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showError(Data&,Options const&)");std::string prefix = (options.use_hex ? "0x": "");
  if(AKA_mark("lis===787###sois===29568###eois===29579###lif===3###soif===169###eoif===180###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showError(Data&,Options const&)") && (AKA_mark("lis===787###sois===29568###eois===29579###lif===3###soif===169###eoif===180###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showError(Data&,Options const&)") && (!data.error))) {
    AKA_mark("lis===788###sois===29588###eois===29625###lif===4###soif===189###eoif===226###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showError(Data&,Options const&)");std::cout << "No error" << std::endl;
  }
else {
AKA_mark("lis===-787-###sois===-29568-###eois===-2956811-###lif===-3-###soif===-###eoif===-180-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showError(Data&,Options const&)");
}
  AKA_mark("lis===790###sois===29634###eois===29744###lif===6###soif===235###eoif===345###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showError(Data&,Options const&)");std::cout << "Decoding error " << prefix << data.error << ": " << lodepng_error_text(data.error) << std::endl;
}

/** Instrumented function loadWithErrorRecovery(Data&,Options const&,bool) */
void loadWithErrorRecovery(Data& data, const Options& options, bool show_errors_mode) /* << Aka begin of function void loadWithErrorRecovery(Data& data, const Options& options, bool show_errors_mode) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.loadWithErrorRecovery.29756.stub"

  AKA_mark("lis===794###sois===29842###eois===29856###lif===1###soif===91###eoif===105###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");(void)options;
  AKA_mark("lis===795###sois===29860###eois===29889###lif===2###soif===109###eoif===138###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");unsigned& error = data.error;
  AKA_mark("lis===796###sois===29893###eois===29928###lif===3###soif===142###eoif===177###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");lodepng::State& state = data.state;

  AKA_mark("lis===798###sois===29934###eois===29952###lif===5###soif===183###eoif===201###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");data.loadPixels();

  if(AKA_mark("lis===800###sois===29961###eois===29977###lif===7###soif===210###eoif===226###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===800###sois===29961###eois===29977###lif===7###soif===210###eoif===226###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (show_errors_mode))) {
    if(AKA_mark("lis===801###sois===29989###eois===29995###lif===8###soif===238###eoif===244###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===801###sois===29989###eois===29995###lif===8###soif===238###eoif===244###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (!error))) {
AKA_mark("lis===801###sois===29997###eois===30047###lif===8###soif===246###eoif===296###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");std::cout << "No errors or warnings" << std::endl;
}

else {
AKA_mark("lis===-801-###sois===-29989-###eois===-299896-###lif===-8-###soif===-###eoif===-244-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");
}
    AKA_mark("lis===802###sois===30053###eois===30060###lif===9###soif===302###eoif===309###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");return;
  }
else {
AKA_mark("lis===-800-###sois===-29961-###eois===-2996116-###lif===-7-###soif===-###eoif===-226-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");
}

  // In case of checksum errors and some other ignorable errors, report it but ignore it and retry
  int AKA_BLOCK_LOOP_30171 = 0;
    while(AKA_mark("lis===806###sois===30177###eois===30182###lif===13###soif===426###eoif===431###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===806###sois===30177###eois===30182###lif===13###soif===426###eoif===431###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (error))) {
        AKA_BLOCK_LOOP_30171++;
        if (AKA_BLOCK_LOOP_30171 > 1000) {
            //break;
        }
    // Not showing regular error here, is shown at end of program.
    AKA_mark("lis===808###sois===30259###eois===30283###lif===15###soif===508###eoif===532###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");unsigned error2 = error;
    if(AKA_mark("lis===809###sois===30292###eois===30303###lif===16###soif===541###eoif===552###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===809###sois===30292###eois===30303###lif===16###soif===541###eoif===552###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (error == 57))) {
      AKA_mark("lis===810###sois===30314###eois===30339###lif===17###soif===563###eoif===588###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");showError(data, options);
      if(AKA_mark("lis===811###sois===30350###eois===30367###lif===18###soif===599###eoif===616###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===811###sois===30350###eois===30367###lif===18###soif===599###eoif===616###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (!show_errors_mode))) {
AKA_mark("lis===811###sois===30369###eois===30437###lif===18###soif===618###eoif===686###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");std::cerr << "Ignoring the error: enabling ignore_crc" << std::endl;
}

else {
AKA_mark("lis===-811-###sois===-30350-###eois===-3035017-###lif===-18-###soif===-###eoif===-616-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");
}
      AKA_mark("lis===812###sois===30445###eois===30474###lif===19###soif===694###eoif===723###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");state.decoder.ignore_crc = 1;
      AKA_mark("lis===813###sois===30482###eois===30502###lif===20###soif===731###eoif===751###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");data.reloadPixels();
    } else {
if(AKA_mark("lis===814###sois===30518###eois===30529###lif===21###soif===767###eoif===778###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===814###sois===30518###eois===30529###lif===21###soif===767###eoif===778###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (error == 58))) {
      AKA_mark("lis===815###sois===30540###eois===30565###lif===22###soif===789###eoif===814###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");showError(data, options);
      if(AKA_mark("lis===816###sois===30576###eois===30593###lif===23###soif===825###eoif===842###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===816###sois===30576###eois===30593###lif===23###soif===825###eoif===842###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (!show_errors_mode))) {
AKA_mark("lis===816###sois===30595###eois===30667###lif===23###soif===844###eoif===916###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");std::cerr << "Ignoring the error: enabling ignore_adler32" << std::endl;
}

else {
AKA_mark("lis===-816-###sois===-30576-###eois===-3057617-###lif===-23-###soif===-###eoif===-842-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");
}
      AKA_mark("lis===817###sois===30675###eois===30721###lif===24###soif===924###eoif===970###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");state.decoder.zlibsettings.ignore_adler32 = 1;
      AKA_mark("lis===818###sois===30729###eois===30749###lif===25###soif===978###eoif===998###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");data.reloadPixels();
    } else {
if(AKA_mark("lis===819###sois===30765###eois===30776###lif===26###soif===1014###eoif===1025###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===819###sois===30765###eois===30776###lif===26###soif===1014###eoif===1025###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (error == 69))) {
      AKA_mark("lis===820###sois===30787###eois===30812###lif===27###soif===1036###eoif===1061###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");showError(data, options);
      if(AKA_mark("lis===821###sois===30823###eois===30840###lif===28###soif===1072###eoif===1089###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===821###sois===30823###eois===30840###lif===28###soif===1072###eoif===1089###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (!show_errors_mode))) {
AKA_mark("lis===821###sois===30842###eois===30915###lif===28###soif===1091###eoif===1164###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");std::cerr << "Ignoring the error: enabling ignore_critical" << std::endl;
}

else {
AKA_mark("lis===-821-###sois===-30823-###eois===-3082317-###lif===-28-###soif===-###eoif===-1089-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");
}
      AKA_mark("lis===822###sois===30923###eois===30957###lif===29###soif===1172###eoif===1206###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");state.decoder.ignore_critical = 1;
      AKA_mark("lis===823###sois===30965###eois===30985###lif===30###soif===1214###eoif===1234###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");data.reloadPixels();
    } else {
if(AKA_mark("lis===824###sois===31001###eois===31027###lif===31###soif===1250###eoif===1276###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && ((AKA_mark("lis===824###sois===31001###eois===31012###lif===31###soif===1250###eoif===1261###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (error == 30)) || (AKA_mark("lis===824###sois===31016###eois===31027###lif===31###soif===1265###eoif===1276###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (error == 63)))) {
      AKA_mark("lis===825###sois===31038###eois===31063###lif===32###soif===1287###eoif===1312###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");showError(data, options);
      if(AKA_mark("lis===826###sois===31074###eois===31091###lif===33###soif===1323###eoif===1340###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===826###sois===31074###eois===31091###lif===33###soif===1323###eoif===1340###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (!show_errors_mode))) {
AKA_mark("lis===826###sois===31093###eois===31161###lif===33###soif===1342###eoif===1410###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");std::cerr << "Ignoring the error: enabling ignore_end" << std::endl;
}

else {
AKA_mark("lis===-826-###sois===-31074-###eois===-3107417-###lif===-33-###soif===-###eoif===-1340-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");
}
      AKA_mark("lis===827###sois===31169###eois===31198###lif===34###soif===1418###eoif===1447###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");state.decoder.ignore_end = 1;
      AKA_mark("lis===828###sois===31206###eois===31226###lif===35###soif===1455###eoif===1475###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");data.reloadPixels();
    } else {
      AKA_mark("lis===830###sois===31248###eois===31273###lif===37###soif===1497###eoif===1522###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");showError(data, options);
      if(AKA_mark("lis===831###sois===31284###eois===31301###lif===38###soif===1533###eoif===1550###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===831###sois===31284###eois===31301###lif===38###soif===1533###eoif===1550###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (!show_errors_mode))) {
AKA_mark("lis===831###sois===31303###eois===31359###lif===38###soif===1552###eoif===1608###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");std::cerr << "This error is unrecoverable" << std::endl;
}

else {
AKA_mark("lis===-831-###sois===-31284-###eois===-3128417-###lif===-38-###soif===-###eoif===-1550-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");
}
      AKA_mark("lis===832###sois===31367###eois===31373###lif===39###soif===1616###eoif===1622###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");break;  // other error that we cannot ignore
    }
}

}

}

    if(AKA_mark("lis===834###sois===31427###eois===31444###lif===41###soif===1676###eoif===1693###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===834###sois===31427###eois===31444###lif===41###soif===1676###eoif===1693###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (!show_errors_mode))) {
if(AKA_mark("lis===834###sois===31449###eois===31459###lif===41###soif===1698###eoif===1708###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===834###sois===31449###eois===31459###lif===41###soif===1698###eoif===1708###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (error == 0))) {
AKA_mark("lis===834###sois===31461###eois===31520###lif===41###soif===1710###eoif===1769###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");std::cerr << "Successfully ignored the error" << std::endl;
}

else {
AKA_mark("lis===-834-###sois===-31449-###eois===-3144910-###lif===-41-###soif===-###eoif===-1708-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");
}
}

else {
AKA_mark("lis===-834-###sois===-31427-###eois===-3142717-###lif===-41-###soif===-###eoif===-1693-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");
}
    if(AKA_mark("lis===835###sois===31529###eois===31544###lif===42###soif===1778###eoif===1793###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===835###sois===31529###eois===31544###lif===42###soif===1778###eoif===1793###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (error == error2))) {
      if(AKA_mark("lis===836###sois===31558###eois===31575###lif===43###soif===1807###eoif===1824###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===836###sois===31558###eois===31575###lif===43###soif===1807###eoif===1824###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (!show_errors_mode))) {
AKA_mark("lis===836###sois===31577###eois===31632###lif===43###soif===1826###eoif===1881###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");std::cerr << "Failed to ignore the error" << std::endl;
}

else {
AKA_mark("lis===-836-###sois===-31558-###eois===-3155817-###lif===-43-###soif===-###eoif===-1824-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");
}
      AKA_mark("lis===837###sois===31640###eois===31646###lif===44###soif===1889###eoif===1895###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");break; // avoid infinite loop if ignoring did not fix the error code
    }
else {
AKA_mark("lis===-835-###sois===-31529-###eois===-3152915-###lif===-42-###soif===-###eoif===-1793-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");
}
  }

  if(AKA_mark("lis===841###sois===31729###eois===31745###lif===48###soif===1978###eoif===1994###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===841###sois===31729###eois===31745###lif===48###soif===1978###eoif===1994###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (show_errors_mode))) {
    if(AKA_mark("lis===842###sois===31757###eois===31763###lif===49###soif===2006###eoif===2012###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (AKA_mark("lis===842###sois===31757###eois===31763###lif===49###soif===2006###eoif===2012###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)") && (!error))) {
AKA_mark("lis===842###sois===31765###eois===31818###lif===49###soif===2014###eoif===2067###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");std::cout << "The error is recoverable" << std::endl;
}

    else {
AKA_mark("lis===843###sois===31829###eois===31886###lif===50###soif===2078###eoif===2135###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");std::cout << "The error is not recoverable" << std::endl;
}

  }
else {
AKA_mark("lis===-841-###sois===-31729-###eois===-3172916-###lif===-48-###soif===-###eoif===-1994-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\loadWithErrorRecovery(Data&,Options const&,bool)");
}
}

/** Instrumented function showSingleLineSummary(Data&,Options const&) */
void showSingleLineSummary(Data& data, const Options& options) /* << Aka begin of function void showSingleLineSummary(Data& data, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.showSingleLineSummary.31903.stub"

  AKA_mark("lis===848###sois===31966###eois===31985###lif===1###soif===68###eoif===87###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");data.loadInspect();
  if(AKA_mark("lis===849###sois===31992###eois===32022###lif===2###soif===94###eoif===124###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)") && ((AKA_mark("lis===849###sois===31992###eois===32002###lif===2###soif===94###eoif===104###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)") && (data.error)) && (AKA_mark("lis===849###sois===32006###eois===32022###lif===2###soif===108###eoif===124###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)") && (data.error != 57)))) {
AKA_mark("lis===849###sois===32024###eois===32031###lif===2###soif===126###eoif===133###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");return;
}

else {
AKA_mark("lis===-849-###sois===-31992-###eois===-3199230-###lif===-2-###soif===-###eoif===-124-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");
} // CRC error (57) ignored here for parsing of header only
  AKA_mark("lis===850###sois===32093###eois===32145###lif===3###soif===195###eoif===247###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");std::cout << (options.use_hex ? std::hex: std::dec);
  AKA_mark("lis===851###sois===32149###eois===32242###lif===4###soif===251###eoif===344###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");std::cout << "Filesize: " << data.buffer.size() << " (" << data.buffer.size() / 1024 << "K)";
  if(AKA_mark("lis===852###sois===32249###eois===32260###lif===5###soif===351###eoif===362###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)") && (AKA_mark("lis===852###sois===32249###eois===32260###lif===5###soif===351###eoif===362###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)") && (data.is_icc))) {
    AKA_mark("lis===853###sois===32269###eois===32364###lif===6###soif===371###eoif===466###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");std::cout << ", not a PNG but an ICC profile, use -i to expand ICC profile info." << std::endl;
    AKA_mark("lis===854###sois===32370###eois===32377###lif===7###soif===472###eoif===479###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");return;
  }
else {
AKA_mark("lis===-852-###sois===-32249-###eois===-3224911-###lif===-5-###soif===-###eoif===-362-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");
}
  if(AKA_mark("lis===856###sois===32389###eois===32401###lif===9###soif===491###eoif===503###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)") && (AKA_mark("lis===856###sois===32389###eois===32401###lif===9###soif===491###eoif===503###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)") && (data.is_exif))) {
    AKA_mark("lis===857###sois===32410###eois===32501###lif===10###soif===512###eoif===603###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");std::cout << ", not a PNG but an EXIF file, use -e to expand EXIF file info." << std::endl;
    AKA_mark("lis===858###sois===32507###eois===32514###lif===11###soif===609###eoif===616###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");return;
  }
else {
AKA_mark("lis===-856-###sois===-32389-###eois===-3238912-###lif===-9-###soif===-###eoif===-503-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");
}

  AKA_mark("lis===861###sois===32525###eois===32578###lif===14###soif===627###eoif===680###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");std::cout << ", " << data.w << "x" << data.h << ", ";
  AKA_mark("lis===862###sois===32582###eois===32730###lif===15###soif===684###eoif===832###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showSingleLineSummary(Data&,Options const&)");std::cout << "Color: " << colorTypeString(data.state.info_png.color.colortype) << ", " << data.state.info_png.color.bitdepth << " bit" << std::endl;
}

/** Instrumented function getICCUint16(unsigned char const*,size_t,size_t) */
static unsigned getICCUint16(const unsigned char* icc, size_t size, size_t pos) /* << Aka begin of function unsigned getICCUint16(const unsigned char* icc, size_t size, size_t pos) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCUint16(unsigned char const*,size_t,size_t)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.getICCUint16.32753.stub"

  if (AKA_mark("lis===866###sois===32826###eois===32840###lif===1###soif===89###eoif===103###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCUint16(unsigned char const*,size_t,size_t)") && (AKA_mark("lis===866###sois===32826###eois===32840###lif===1###soif===89###eoif===103###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCUint16(unsigned char const*,size_t,size_t)") && (pos + 2 > size))) {
AKA_mark("lis===866###sois===32842###eois===32851###lif===1###soif===105###eoif===114###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCUint16(unsigned char const*,size_t,size_t)");return 0;
}

else {
AKA_mark("lis===-866-###sois===-32826-###eois===-3282614-###lif===-1-###soif===-###eoif===-103-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCUint16(unsigned char const*,size_t,size_t)");
}
  AKA_mark("lis===867###sois===32855###eois===32907###lif===2###soif===118###eoif===170###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCUint16(unsigned char const*,size_t,size_t)");return (unsigned)((icc[pos] << 8) | (icc[pos + 1]));
}

/** Instrumented function getICCUint32(unsigned char const*,size_t,size_t) */
static unsigned getICCUint32(const unsigned char* icc, size_t size, size_t pos) /* << Aka begin of function unsigned getICCUint32(const unsigned char* icc, size_t size, size_t pos) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCUint32(unsigned char const*,size_t,size_t)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.getICCUint32.32930.stub"

  if (AKA_mark("lis===871###sois===33003###eois===33017###lif===1###soif===89###eoif===103###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCUint32(unsigned char const*,size_t,size_t)") && (AKA_mark("lis===871###sois===33003###eois===33017###lif===1###soif===89###eoif===103###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCUint32(unsigned char const*,size_t,size_t)") && (pos + 4 > size))) {
AKA_mark("lis===871###sois===33019###eois===33028###lif===1###soif===105###eoif===114###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCUint32(unsigned char const*,size_t,size_t)");return 0;
}

else {
AKA_mark("lis===-871-###sois===-33003-###eois===-3300314-###lif===-1-###soif===-###eoif===-103-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCUint32(unsigned char const*,size_t,size_t)");
}
  AKA_mark("lis===872###sois===33032###eois===33135###lif===2###soif===118###eoif===221###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCUint32(unsigned char const*,size_t,size_t)");return (unsigned)((icc[pos] << 24) | (icc[pos + 1] << 16) | (icc[pos + 2] << 8) | (icc[pos + 3] << 0));
}

/** Instrumented function getICCInt32(unsigned char const*,size_t,size_t) */
static int getICCInt32(const unsigned char* icc, size_t size, size_t pos) /* << Aka begin of function int getICCInt32(const unsigned char* icc, size_t size, size_t pos) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCInt32(unsigned char const*,size_t,size_t)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.getICCInt32.33153.stub"

  if (AKA_mark("lis===876###sois===33225###eois===33239###lif===1###soif===83###eoif===97###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCInt32(unsigned char const*,size_t,size_t)") && (AKA_mark("lis===876###sois===33225###eois===33239###lif===1###soif===83###eoif===97###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCInt32(unsigned char const*,size_t,size_t)") && (pos + 4 > size))) {
AKA_mark("lis===876###sois===33241###eois===33250###lif===1###soif===99###eoif===108###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCInt32(unsigned char const*,size_t,size_t)");return 0;
}

else {
AKA_mark("lis===-876-###sois===-33225-###eois===-3322514-###lif===-1-###soif===-###eoif===-97-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCInt32(unsigned char const*,size_t,size_t)");
}
  AKA_mark("lis===877###sois===33254###eois===33352###lif===2###soif===112###eoif===210###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICCInt32(unsigned char const*,size_t,size_t)");return (int)((icc[pos] << 24) | (icc[pos + 1] << 16) | (icc[pos + 2] << 8) | (icc[pos + 3] << 0));
}

// Signed
/** Instrumented function getICC15Fixed16(unsigned char const*,size_t,size_t) */
static float getICC15Fixed16(const unsigned char* icc, size_t size, size_t pos) /* << Aka begin of function float getICC15Fixed16(const unsigned char* icc, size_t size, size_t pos) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICC15Fixed16(unsigned char const*,size_t,size_t)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.getICC15Fixed16.33383.stub"

  AKA_mark("lis===882###sois===33455###eois===33500###lif===1###soif===85###eoif===130###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICC15Fixed16(unsigned char const*,size_t,size_t)");return getICCInt32(icc, size, pos) / 65536.0;
}

// Unsigned
/** Instrumented function getICC16Fixed16(unsigned char const*,size_t,size_t) */
static float getICC16Fixed16(const unsigned char* icc, size_t size, size_t pos) /* << Aka begin of function float getICC16Fixed16(const unsigned char* icc, size_t size, size_t pos) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICC16Fixed16(unsigned char const*,size_t,size_t)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.getICC16Fixed16.33533.stub"

  AKA_mark("lis===887###sois===33605###eois===33651###lif===1###soif===85###eoif===131###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\getICC16Fixed16(unsigned char const*,size_t,size_t)");return getICCUint32(icc, size, pos) / 65536.0;
}

/** Instrumented function printableICCWord(unsigned char const*,size_t,size_t) */
static std::string printableICCWord(const unsigned char* icc, size_t size, size_t pos) /* << Aka begin of function std::string printableICCWord(const unsigned char* icc, size_t size, size_t pos) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\printableICCWord(unsigned char const*,size_t,size_t)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.printableICCWord.33677.stub"

  if (AKA_mark("lis===891###sois===33754###eois===33768###lif===1###soif===96###eoif===110###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printableICCWord(unsigned char const*,size_t,size_t)") && (AKA_mark("lis===891###sois===33754###eois===33768###lif===1###soif===96###eoif===110###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printableICCWord(unsigned char const*,size_t,size_t)") && (pos + 4 > size))) {
    AKA_mark("lis===892###sois===33777###eois===33799###lif===2###soif===119###eoif===141###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printableICCWord(unsigned char const*,size_t,size_t)");return "out of range";
  }
else {
AKA_mark("lis===-891-###sois===-33754-###eois===-3375414-###lif===-1-###soif===-###eoif===-110-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printableICCWord(unsigned char const*,size_t,size_t)");
}
  AKA_mark("lis===894###sois===33808###eois===33827###lif===4###soif===150###eoif===169###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printableICCWord(unsigned char const*,size_t,size_t)");std::string result;
  int AKA_BLOCK_LOOP_33831 = 0;
    AKA_mark("lis===895###sois===33836###eois===33846###lif===5###soif===178###eoif===188###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printableICCWord(unsigned char const*,size_t,size_t)");
for (int i = 0; AKA_mark("lis===895###sois===33847###eois===33852###lif===5###soif===189###eoif===194###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printableICCWord(unsigned char const*,size_t,size_t)") && (AKA_mark("lis===895###sois===33847###eois===33852###lif===5###soif===189###eoif===194###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printableICCWord(unsigned char const*,size_t,size_t)") && (i < 4)); ({AKA_mark("lis===895###sois===33854###eois===33857###lif===5###soif===196###eoif===199###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printableICCWord(unsigned char const*,size_t,size_t)");i++;})) {
        AKA_BLOCK_LOOP_33831++;
        if (AKA_BLOCK_LOOP_33831 > 1000) {
            //break;
        }
    AKA_mark("lis===896###sois===33866###eois===33888###lif===6###soif===208###eoif===230###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printableICCWord(unsigned char const*,size_t,size_t)");char c = icc[pos + i];
    AKA_mark("lis===897###sois===33894###eois===33937###lif===7###soif===236###eoif===279###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printableICCWord(unsigned char const*,size_t,size_t)");result += ((c >= 32 && c < 127) ? c : '?');
  }
  AKA_mark("lis===899###sois===33946###eois===33960###lif===9###soif===288###eoif===302###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printableICCWord(unsigned char const*,size_t,size_t)");return result;
}

/** Instrumented function printICCDetails(unsigned char const*,size_t,std::string const&) */
void printICCDetails(const unsigned char* icc, size_t size, const std::string& indent) /* << Aka begin of function void printICCDetails(const unsigned char* icc, size_t size, const std::string& indent) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.printICCDetails.33972.stub"

  // 128 for header, 4 for num tags
  if(AKA_mark("lis===904###sois===34099###eois===34109###lif===2###soif===132###eoif===142###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===904###sois===34099###eois===34109###lif===2###soif===132###eoif===142###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (size < 132))) {
    AKA_mark("lis===905###sois===34118###eois===34197###lif===3###soif===151###eoif===230###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "Invalid ICC: too small to contain header" << std::endl;
    AKA_mark("lis===906###sois===34203###eois===34210###lif===4###soif===236###eoif===243###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");return;
  }
else {
AKA_mark("lis===-904-###sois===-34099-###eois===-3409910-###lif===-2-###soif===-###eoif===-142-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
  if(AKA_mark("lis===908###sois===34222###eois===34263###lif===6###soif===255###eoif===296###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===908###sois===34222###eois===34263###lif===6###soif===255###eoif===296###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (printableICCWord(icc, size, 36) != "acsp"))) {
    AKA_mark("lis===909###sois===34272###eois===34359###lif===7###soif===305###eoif===392###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "Invalid ICC: does not contain signature \"acsp\"" << std::endl;
    AKA_mark("lis===910###sois===34365###eois===34372###lif===8###soif===398###eoif===405###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");return;
  }
else {
AKA_mark("lis===-908-###sois===-34222-###eois===-3422241-###lif===-6-###soif===-###eoif===-296-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}

  AKA_mark("lis===913###sois===34383###eois===34466###lif===11###soif===416###eoif===499###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "profile size: " << getICCUint32(icc, size, 0) << std::endl;
  AKA_mark("lis===914###sois===34470###eois===34553###lif===12###soif===503###eoif===586###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "CMM type: " << printableICCWord(icc, size, 4) << std::endl;

  AKA_mark("lis===916###sois===34559###eois===34605###lif===14###soif===592###eoif===638###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");uint32_t version = getICCUint32(icc, size, 8);
  AKA_mark("lis===917###sois===34609###eois===34656###lif===15###soif===642###eoif===689###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");uint16_t version_major = (version >> 24) & 255;
  AKA_mark("lis===918###sois===34660###eois===34706###lif===16###soif===693###eoif===739###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");uint16_t version_minor = (version >> 20) & 15;
  AKA_mark("lis===919###sois===34710###eois===34757###lif===17###soif===743###eoif===790###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");uint16_t version_bugfix = (version >> 16) & 15;
  AKA_mark("lis===920###sois===34761###eois===34888###lif===18###soif===794###eoif===921###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "version: " << version_major << "." << version_minor
            << "." << version_bugfix << std::endl;

  AKA_mark("lis===923###sois===34894###eois===34982###lif===21###soif===927###eoif===1015###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "device class: " << printableICCWord(icc, size, 12) << std::endl;
  AKA_mark("lis===924###sois===34986###eois===35072###lif===22###soif===1019###eoif===1105###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "input space: \"" << printableICCWord(icc, size, 16) << "\", ";
  AKA_mark("lis===925###sois===35076###eois===35164###lif===23###soif===1109###eoif===1197###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << "output space: \"" << printableICCWord(icc, size, 20) << "\"" << std::endl;
  AKA_mark("lis===926###sois===35168###eois===35188###lif===24###soif===1201###eoif===1221###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent;
  AKA_mark("lis===927###sois===35192###eois===35434###lif===25###soif===1225###eoif===1467###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");printf("date: %02d-%02d-%02dT%02d:%02d:%02d\n",
         getICCUint16(icc, size, 24), getICCUint16(icc, size, 26), getICCUint16(icc, size, 28),
         getICCUint16(icc, size, 30), getICCUint16(icc, size, 32), getICCUint16(icc, size, 34));
  AKA_mark("lis===930###sois===35438###eois===35523###lif===28###soif===1471###eoif===1556###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "signature: " << printableICCWord(icc, size, 36) << std::endl;
  AKA_mark("lis===931###sois===35527###eois===35611###lif===29###soif===1560###eoif===1644###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "platform: " << printableICCWord(icc, size, 40) << std::endl;
  AKA_mark("lis===932###sois===35615###eois===35692###lif===30###soif===1648###eoif===1725###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "flags: " << getICCUint32(icc, size, 44) << std::endl;
  AKA_mark("lis===933###sois===35696###eois===35786###lif===31###soif===1729###eoif===1819###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "device manufacturer: " << printableICCWord(icc, size, 48) << ", ";
  AKA_mark("lis===934###sois===35790###eois===35863###lif===32###soif===1823###eoif===1896###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << "device model: " << printableICCWord(icc, size, 52) << ", ";
  AKA_mark("lis===935###sois===35867###eois===35997###lif===33###soif===1900###eoif===2030###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << "device attributes: " << getICCUint32(icc, size, 56) << " "
            << getICCUint32(icc, size, 60) << std::endl;
  AKA_mark("lis===937###sois===36001###eois===36089###lif===35###soif===2034###eoif===2122###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "rendering intent: " << getICCUint32(icc, size, 64) << std::endl;

  AKA_mark("lis===939###sois===36095###eois===36139###lif===37###soif===2128###eoif===2172###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");float pcsx = getICC15Fixed16(icc, size, 68);
  AKA_mark("lis===940###sois===36143###eois===36187###lif===38###soif===2176###eoif===2220###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");float pcsy = getICC15Fixed16(icc, size, 72);
  AKA_mark("lis===941###sois===36191###eois===36235###lif===39###soif===2224###eoif===2268###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");float pcsz = getICC15Fixed16(icc, size, 76);
  AKA_mark("lis===942###sois===36239###eois===36273###lif===40###soif===2272###eoif===2306###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");float pcsxyz = pcsx + pcsy + pcsz;
  AKA_mark("lis===943###sois===36277###eois===36447###lif===41###soif===2310###eoif===2480###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "xyz illuminant: X:" << pcsx << ", Y:" << pcsy << ", Z:" << pcsz
            << ", xy:" << (pcsx / pcsxyz) << "," << (pcsy / pcsxyz) << std::endl;

  AKA_mark("lis===946###sois===36453###eois===36536###lif===44###soif===2486###eoif===2569###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "creator: " << printableICCWord(icc, size, 80) << std::endl;

  // The md5 is present in v2.4 and above profiles, but it's always shown anyway. Those
  // bytes are normally all zero for older versions.
  AKA_mark("lis===950###sois===36685###eois===36705###lif===48###soif===2718###eoif===2738###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent;
  AKA_mark("lis===951###sois===36709###eois===36896###lif===49###soif===2742###eoif===2929###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");printf("md5: %08x%08x%08x%08x\n", getICCUint32(icc, size, 84), getICCUint32(icc, size, 88),
                                    getICCUint32(icc, size, 92), getICCUint32(icc, size, 96));

  AKA_mark("lis===954###sois===36902###eois===36948###lif===52###soif===2935###eoif===2981###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");size_t numtags = getICCUint32(icc, size, 128);
  AKA_mark("lis===955###sois===36952###eois===37016###lif===53###soif===2985###eoif===3049###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "num icc tags: " << numtags << std::endl;
  if(AKA_mark("lis===956###sois===37023###eois===37052###lif===54###soif===3056###eoif===3085###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===956###sois===37023###eois===37052###lif===54###soif===3056###eoif===3085###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (size < 128 + 4 + numtags * 12))) {
    AKA_mark("lis===957###sois===37061###eois===37150###lif===55###soif===3094###eoif===3183###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "Invalid ICC: too small to contain tag descriptions" << std::endl;
    AKA_mark("lis===958###sois===37156###eois===37163###lif===56###soif===3189###eoif===3196###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");return;
  }
else {
AKA_mark("lis===-956-###sois===-37023-###eois===-3702329-###lif===-54-###soif===-###eoif===-3085-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
  int AKA_BLOCK_LOOP_37172 = 0;
    AKA_mark("lis===960###sois===37176###eois===37189###lif===58###soif===3209###eoif===3222###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
for(size_t i = 0; AKA_mark("lis===960###sois===37190###eois===37201###lif===58###soif===3223###eoif===3234###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===960###sois===37190###eois===37201###lif===58###soif===3223###eoif===3234###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (i < numtags)); ({AKA_mark("lis===960###sois===37203###eois===37206###lif===58###soif===3236###eoif===3239###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");i++;})) {
        AKA_BLOCK_LOOP_37172++;
        if (AKA_BLOCK_LOOP_37172 > 1000) {
            //break;
        }
    AKA_mark("lis===961###sois===37215###eois===37241###lif===59###soif===3248###eoif===3274###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");size_t pos = 132 + i * 12;
    AKA_mark("lis===962###sois===37247###eois===37328###lif===60###soif===3280###eoif===3361###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << indent << "icc tag: \"" << printableICCWord(icc, size, pos) << "\"";
    AKA_mark("lis===963###sois===37334###eois===37383###lif===61###soif===3367###eoif===3416###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");size_t offset = getICCUint32(icc, size, pos + 4);
    AKA_mark("lis===964###sois===37389###eois===37439###lif===62###soif===3422###eoif===3472###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");size_t tagsize = getICCUint32(icc, size, pos + 8);
    AKA_mark("lis===965###sois===37445###eois===37506###lif===63###soif===3478###eoif===3539###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << ", offset: " << offset << ", size: " << tagsize;
    if(AKA_mark("lis===966###sois===37515###eois===37553###lif===64###soif===3548###eoif===3586###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && ((AKA_mark("lis===966###sois===37515###eois===37538###lif===64###soif===3548###eoif===3571###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (offset + tagsize > size)) || (AKA_mark("lis===966###sois===37542###eois===37553###lif===64###soif===3575###eoif===3586###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (tagsize < 4)))) {
      AKA_mark("lis===967###sois===37564###eois===37645###lif===65###soif===3597###eoif===3678###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << std::endl << indent << "Invalid ICC: tag out of range" << std::endl;
      AKA_mark("lis===968###sois===37653###eois===37660###lif===66###soif===3686###eoif===3693###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");return;
    }
else {
AKA_mark("lis===-966-###sois===-37515-###eois===-3751538-###lif===-64-###soif===-###eoif===-3586-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
    AKA_mark("lis===970###sois===37673###eois===37732###lif===68###soif===3706###eoif===3765###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::string datatype = printableICCWord(icc, size, offset);
    AKA_mark("lis===971###sois===37738###eois===37788###lif===69###soif===3771###eoif===3821###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << ", datatype: \"" << datatype << "\"";
    if(AKA_mark("lis===972###sois===37797###eois===37815###lif===70###soif===3830###eoif===3848###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===972###sois===37797###eois===37815###lif===70###soif===3830###eoif===3848###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (datatype == "XYZ "))) {
      AKA_mark("lis===973###sois===37826###eois===37875###lif===71###soif===3859###eoif===3908###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");float x = getICC15Fixed16(icc, size, offset + 8);
      AKA_mark("lis===974###sois===37883###eois===37933###lif===72###soif===3916###eoif===3966###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");float y = getICC15Fixed16(icc, size, offset + 12);
      AKA_mark("lis===975###sois===37941###eois===37991###lif===73###soif===3974###eoif===4024###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");float z = getICC15Fixed16(icc, size, offset + 16);
      AKA_mark("lis===976###sois===37999###eois===38021###lif===74###soif===4032###eoif===4054###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");float xyz = x + y + z;
      AKA_mark("lis===977###sois===38029###eois===38084###lif===75###soif===4062###eoif===4117###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << ", X:" << x << ", Y:" << y << ", Z:" << z;
      if(AKA_mark("lis===978###sois===38095###eois===38098###lif===76###soif===4128###eoif===4131###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===978###sois===38095###eois===38098###lif===76###soif===4128###eoif===4131###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (xyz))) {
AKA_mark("lis===978###sois===38100###eois===38154###lif===76###soif===4133###eoif===4187###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << ", xy:" << (x / xyz) << "," << (y / xyz);
}

else {
AKA_mark("lis===-978-###sois===-38095-###eois===-380953-###lif===-76-###soif===-###eoif===-4131-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
    }
else {
AKA_mark("lis===-972-###sois===-37797-###eois===-3779718-###lif===-70-###soif===-###eoif===-3848-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
    if(AKA_mark("lis===980###sois===38170###eois===38188###lif===78###soif===4203###eoif===4221###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===980###sois===38170###eois===38188###lif===78###soif===4203###eoif===4221###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (datatype == "curv"))) {
      AKA_mark("lis===981###sois===38199###eois===38252###lif===79###soif===4232###eoif===4285###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");size_t lutsize = getICCUint32(icc, size, offset + 8);
      AKA_mark("lis===982###sois===38260###eois===38308###lif===80###soif===4293###eoif===4341###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << ", lookup table size: " << lutsize;
      if(AKA_mark("lis===983###sois===38319###eois===38354###lif===81###soif===4352###eoif===4387###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && ((AKA_mark("lis===983###sois===38319###eois===38331###lif===81###soif===4352###eoif===4364###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (lutsize == 1)) && (AKA_mark("lis===983###sois===38335###eois===38354###lif===81###soif===4368###eoif===4387###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (offset + 14 <= size)))) {
        AKA_mark("lis===984###sois===38367###eois===38449###lif===82###soif===4400###eoif===4482###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << " (gamma: " << (getICCUint16(icc, size, offset + 12) / 256.0) << ")";
      }
else {
AKA_mark("lis===-983-###sois===-38319-###eois===-3831935-###lif===-81-###soif===-###eoif===-4387-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
      if(AKA_mark("lis===986###sois===38469###eois===38481###lif===84###soif===4502###eoif===4514###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===986###sois===38469###eois===38481###lif===84###soif===4502###eoif===4514###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (lutsize == 0))) {
AKA_mark("lis===986###sois===38483###eois===38508###lif===84###soif===4516###eoif===4541###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << " (linear)";
}

else {
AKA_mark("lis===-986-###sois===-38469-###eois===-3846912-###lif===-84-###soif===-###eoif===-4514-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
    }
else {
AKA_mark("lis===-980-###sois===-38170-###eois===-3817018-###lif===-78-###soif===-###eoif===-4221-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
    if(AKA_mark("lis===988###sois===38524###eois===38542###lif===86###soif===4557###eoif===4575###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===988###sois===38524###eois===38542###lif===86###soif===4557###eoif===4575###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (datatype == "para"))) {
      AKA_mark("lis===989###sois===38553###eois===38605###lif===87###soif===4586###eoif===4638###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");unsigned type = getICCUint16(icc, size, offset + 8);
      AKA_mark("lis===990###sois===38613###eois===38667###lif===88###soif===4646###eoif===4700###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");float gamma = getICC15Fixed16(icc, size, offset + 12);
      AKA_mark("lis===991###sois===38675###eois===38753###lif===89###soif===4708###eoif===4786###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");int numparams = (type == 4) ? 7 : ((type >= 1 && type <= 3) ? (type + 1) : 0);
      AKA_mark("lis===992###sois===38761###eois===38817###lif===90###soif===4794###eoif===4850###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << " type: " << type << ", gamma: " <<  gamma;
      if(AKA_mark("lis===993###sois===38828###eois===38841###lif===91###soif===4861###eoif===4874###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===993###sois===38828###eois===38841###lif===91###soif===4861###eoif===4874###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (numparams > 0))) {
        AKA_mark("lis===994###sois===38854###eois===38880###lif===92###soif===4887###eoif===4913###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << ", params: ";
        int AKA_BLOCK_LOOP_38890 = 0;
    AKA_mark("lis===995###sois===38894###eois===38904###lif===93###soif===4927###eoif===4937###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
for(int j = 0; AKA_mark("lis===995###sois===38905###eois===38918###lif===93###soif===4938###eoif===4951###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===995###sois===38905###eois===38918###lif===93###soif===4938###eoif===4951###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (j < numparams)); ({AKA_mark("lis===995###sois===38920###eois===38923###lif===93###soif===4953###eoif===4956###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");j++;})) {
        AKA_BLOCK_LOOP_38890++;
        if (AKA_BLOCK_LOOP_38890 > 1000) {
            //break;
        }
          if(AKA_mark("lis===996###sois===38941###eois===38946###lif===94###soif===4974###eoif===4979###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===996###sois===38941###eois===38946###lif===94###soif===4974###eoif===4979###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (j > 0))) {
AKA_mark("lis===996###sois===38948###eois===38966###lif===94###soif===4981###eoif===4999###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << ", ";
}

else {
AKA_mark("lis===-996-###sois===-38941-###eois===-389415-###lif===-94-###soif===-###eoif===-4979-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
          AKA_mark("lis===997###sois===38978###eois===39039###lif===95###soif===5011###eoif===5072###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << getICC15Fixed16(icc, size, offset + 16 + j * 4);
        }
      }
else {
AKA_mark("lis===-993-###sois===-38828-###eois===-3882813-###lif===-91-###soif===-###eoif===-4874-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
    }
else {
AKA_mark("lis===-988-###sois===-38524-###eois===-3852418-###lif===-86-###soif===-###eoif===-4575-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
    if(AKA_mark("lis===1001###sois===39075###eois===39093###lif===99###soif===5108###eoif===5126###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===1001###sois===39075###eois===39093###lif===99###soif===5108###eoif===5126###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (datatype == "sf32"))) {
      AKA_mark("lis===1002###sois===39104###eois===39121###lif===100###soif===5137###eoif===5154###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << ":";
      int AKA_BLOCK_LOOP_39129 = 0;
    AKA_mark("lis===1003###sois===39133###eois===39146###lif===101###soif===5166###eoif===5179###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
for(size_t j = 8; AKA_mark("lis===1003###sois===39147###eois===39158###lif===101###soif===5180###eoif===5191###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===1003###sois===39147###eois===39158###lif===101###soif===5180###eoif===5191###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (j < tagsize)); ({AKA_mark("lis===1003###sois===39160###eois===39166###lif===101###soif===5193###eoif===5199###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");j += 4;})) {
        AKA_BLOCK_LOOP_39129++;
        if (AKA_BLOCK_LOOP_39129 > 1000) {
            //break;
        }
        AKA_mark("lis===1004###sois===39179###eois===39228###lif===102###soif===5212###eoif===5261###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");float v = getICC15Fixed16(icc, size, offset + j);
        AKA_mark("lis===1005###sois===39238###eois===39260###lif===103###soif===5271###eoif===5293###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << " " << v;
      }
    }
else {
AKA_mark("lis===-1001-###sois===-39075-###eois===-3907518-###lif===-99-###soif===-###eoif===-5126-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
    if(AKA_mark("lis===1008###sois===39285###eois===39303###lif===106###soif===5318###eoif===5336###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===1008###sois===39285###eois===39303###lif===106###soif===5318###eoif===5336###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (datatype == "chrm"))) {
      AKA_mark("lis===1009###sois===39314###eois===39371###lif===107###soif===5347###eoif===5404###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");size_t numchannels = getICCUint16(icc, size, offset + 8);
      AKA_mark("lis===1010###sois===39379###eois===39487###lif===108###soif===5412###eoif===5520###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << ": n:" << numchannels
                << " phosphor:" << getICCUint16(icc, size, offset + 10);
      int AKA_BLOCK_LOOP_39495 = 0;
    AKA_mark("lis===1012###sois===39499###eois===39512###lif===110###soif===5532###eoif===5545###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
for(size_t j = 0; AKA_mark("lis===1012###sois===39513###eois===39528###lif===110###soif===5546###eoif===5561###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===1012###sois===39513###eois===39528###lif===110###soif===5546###eoif===5561###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (j < numchannels)); ({AKA_mark("lis===1012###sois===39530###eois===39533###lif===110###soif===5563###eoif===5566###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");j++;})) {
        AKA_BLOCK_LOOP_39495++;
        if (AKA_BLOCK_LOOP_39495 > 1000) {
            //break;
        }
        AKA_mark("lis===1013###sois===39546###eois===39698###lif===111###soif===5579###eoif===5731###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << " xy:" << getICC16Fixed16(icc, size, offset + 12 + j * 8)
                  << "," << getICC16Fixed16(icc, size, offset + 12 + j * 8 + 4);
      }
    }
else {
AKA_mark("lis===-1008-###sois===-39285-###eois===-3928518-###lif===-106-###soif===-###eoif===-5336-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
    if(AKA_mark("lis===1017###sois===39723###eois===39785###lif===115###soif===5756###eoif===5818###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (((AKA_mark("lis===1017###sois===39723###eois===39741###lif===115###soif===5756###eoif===5774###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (datatype == "text")) || (AKA_mark("lis===1017###sois===39745###eois===39763###lif===115###soif===5778###eoif===5796###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (datatype == "mluc"))) || (AKA_mark("lis===1017###sois===39767###eois===39785###lif===115###soif===5800###eoif===5818###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (datatype == "desc")))) {
      // TODO: this is a bit of a simplification of the parse for now, e.g.
      // ignoring UTF-16, instead implicitely skipping non-ASCII bytes, and
      // potentially printing things multiple times in a row if multiple
      // variants are in desc or mluc.
      AKA_mark("lis===1022###sois===40064###eois===40082###lif===120###soif===6097###eoif===6115###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << ": ";
      int AKA_BLOCK_LOOP_40090 = 0;
    AKA_mark("lis===1023###sois===40094###eois===40135###lif===121###soif===6127###eoif===6168###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
for(size_t j = (datatype == "mluc" ? 28 : 8); AKA_mark("lis===1023###sois===40136###eois===40147###lif===121###soif===6169###eoif===6180###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (AKA_mark("lis===1023###sois===40136###eois===40147###lif===121###soif===6169###eoif===6180###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (j < tagsize)); ({AKA_mark("lis===1023###sois===40149###eois===40152###lif===121###soif===6182###eoif===6185###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");j++;})) {
        AKA_BLOCK_LOOP_40090++;
        if (AKA_BLOCK_LOOP_40090 > 1000) {
            //break;
        }
        AKA_mark("lis===1024###sois===40165###eois===40190###lif===122###soif===6198###eoif===6223###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");char c = icc[offset + j];
        if(AKA_mark("lis===1025###sois===40203###eois===40221###lif===123###soif===6236###eoif===6254###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && ((AKA_mark("lis===1025###sois===40203###eois===40210###lif===123###soif===6236###eoif===6243###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (c >= 32)) && (AKA_mark("lis===1025###sois===40214###eois===40221###lif===123###soif===6247###eoif===6254###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)") && (c < 127)))) {
AKA_mark("lis===1025###sois===40223###eois===40238###lif===123###soif===6256###eoif===6271###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << c;
}

else {
AKA_mark("lis===-1025-###sois===-40203-###eois===-4020318-###lif===-123-###soif===-###eoif===-6254-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
      }
    }
else {
AKA_mark("lis===-1017-###sois===-39723-###eois===-3972362-###lif===-115-###soif===-###eoif===-5818-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");
}
    AKA_mark("lis===1028###sois===40260###eois===40283###lif===126###soif===6293###eoif===6316###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\printICCDetails(unsigned char const*,size_t,std::string const&)");std::cout << std::endl;
  }
}

/** Instrumented function showHex(unsigned char const*,size_t,Options const&) */
void showHex(const unsigned char* data, size_t size, const Options& options) /* << Aka begin of function void showHex(const unsigned char* data, size_t size, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.showHex.40300.stub"

  int AKA_BLOCK_LOOP_40377 = 0;
    AKA_mark("lis===1033###sois===40381###eois===40394###lif===1###soif===86###eoif===99###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)");
for(size_t i = 0; AKA_mark("lis===1033###sois===40395###eois===40403###lif===1###soif===100###eoif===108###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)") && (AKA_mark("lis===1033###sois===40395###eois===40403###lif===1###soif===100###eoif===108###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)") && (i < size)); ({AKA_mark("lis===1033###sois===40405###eois===40408###lif===1###soif===110###eoif===113###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)");i++;})) {
        AKA_BLOCK_LOOP_40377++;
        if (AKA_BLOCK_LOOP_40377 > 1000) {
            //break;
        }
    AKA_mark("lis===1034###sois===40417###eois===40443###lif===2###soif===122###eoif===148###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)");unsigned char c = data[i];
    if(AKA_mark("lis===1035###sois===40452###eois===40479###lif===3###soif===157###eoif===184###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)") && (AKA_mark("lis===1035###sois===40452###eois===40479###lif===3###soif===157###eoif===184###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)") && (options.hexformat == HF_BIN))) {
      AKA_mark("lis===1036###sois===40490###eois===40506###lif===4###soif===195###eoif===211###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)");printf("%c", c);
    } else {
      if(AKA_mark("lis===1038###sois===40531###eois===40579###lif===6###soif===236###eoif===284###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)") && (((AKA_mark("lis===1038###sois===40531###eois===40537###lif===6###soif===236###eoif===242###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)") && (c > 32)) && (AKA_mark("lis===1038###sois===40541###eois===40548###lif===6###soif===246###eoif===253###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)") && (c < 127))) && (AKA_mark("lis===1038###sois===40552###eois===40579###lif===6###soif===257###eoif===284###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)") && (options.hexformat == HF_MIX)))) {
AKA_mark("lis===1038###sois===40581###eois===40599###lif===6###soif===286###eoif===304###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)");printf(" %c ", c);
}

      else {
AKA_mark("lis===1039###sois===40612###eois===40631###lif===7###soif===317###eoif===336###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)");printf("%02x ", c);
}

      if(AKA_mark("lis===1040###sois===40642###eois===40671###lif===8###soif===347###eoif===376###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)") && ((AKA_mark("lis===1040###sois===40642###eois===40654###lif===8###soif===347###eoif===359###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)") && (i % 32 == 31)) && (AKA_mark("lis===1040###sois===40658###eois===40671###lif===8###soif===363###eoif===376###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)") && (i + 1 != size)))) {
AKA_mark("lis===1040###sois===40673###eois===40696###lif===8###soif===378###eoif===401###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)");std::cout << std::endl;
}

else {
AKA_mark("lis===-1040-###sois===-40642-###eois===-4064229-###lif===-8-###soif===-###eoif===-376-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)");
}
    }
  }
  if(AKA_mark("lis===1043###sois===40715###eois===40742###lif===11###soif===420###eoif===447###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)") && (AKA_mark("lis===1043###sois===40715###eois===40742###lif===11###soif===420###eoif===447###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)") && (options.hexformat != HF_BIN))) {
AKA_mark("lis===1043###sois===40744###eois===40767###lif===11###soif===449###eoif===472###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)");std::cout << std::endl;
}

else {
AKA_mark("lis===-1043-###sois===-40715-###eois===-4071527-###lif===-11-###soif===-###eoif===-447-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHex(unsigned char const*,size_t,Options const&)");
}
}

/** Instrumented function showHeaderInfo(Data&,Options const&) */
void showHeaderInfo(Data& data, const Options& options) /* << Aka begin of function void showHeaderInfo(Data& data, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.showHeaderInfo.40779.stub"

  AKA_mark("lis===1047###sois===40835###eois===40854###lif===1###soif===61###eoif===80###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");data.loadInspect();
  if(AKA_mark("lis===1048###sois===40861###eois===40871###lif===2###soif===87###eoif===97###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1048###sois===40861###eois===40871###lif===2###soif===87###eoif===97###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (data.error))) {
AKA_mark("lis===1048###sois===40873###eois===40880###lif===2###soif===99###eoif===106###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");return;
}

else {
AKA_mark("lis===-1048-###sois===-40861-###eois===-4086110-###lif===-2-###soif===-###eoif===-97-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
  AKA_mark("lis===1049###sois===40884###eois===40936###lif===3###soif===110###eoif===162###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << (options.use_hex ? std::hex: std::dec);

  AKA_mark("lis===1051###sois===40942###eois===40988###lif===5###soif===168###eoif===214###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");const LodePNGInfo& info = data.state.info_png;
  AKA_mark("lis===1052###sois===40992###eois===41035###lif===6###soif===218###eoif===261###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");const LodePNGColorMode& color = info.color;
  if(AKA_mark("lis===1053###sois===41042###eois===41061###lif===7###soif===268###eoif===287###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1053###sois===41042###eois===41061###lif===7###soif===268###eoif===287###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (options.show_header))) {
    AKA_mark("lis===1054###sois===41070###eois===41176###lif===8###soif===296###eoif===402###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Filesize: " << data.buffer.size() << " (" << data.buffer.size() / 1024 << "K)" << std::endl;
    if(AKA_mark("lis===1055###sois===41185###eois===41196###lif===9###soif===411###eoif===422###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1055###sois===41185###eois===41196###lif===9###soif===411###eoif===422###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (data.is_icc))) {
      AKA_mark("lis===1056###sois===41207###eois===41293###lif===10###soif===433###eoif===519###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Not a PNG but an ICC profile, use -i or -I for more info." << std::endl;
    } else {
if(AKA_mark("lis===1057###sois===41309###eois===41321###lif===11###soif===535###eoif===547###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1057###sois===41309###eois===41321###lif===11###soif===535###eoif===547###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (data.is_exif))) {
      AKA_mark("lis===1058###sois===41332###eois===41410###lif===12###soif===558###eoif===636###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Not a PNG but an EXIF file, use -e for more info." << std::endl;
    } else {
      AKA_mark("lis===1060###sois===41432###eois===41478###lif===14###soif===658###eoif===704###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Width: " << data.w << std::endl;
      AKA_mark("lis===1061###sois===41486###eois===41533###lif===15###soif===712###eoif===759###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Height: " << data.h << std::endl;
      if(AKA_mark("lis===1062###sois===41544###eois===41559###lif===16###soif===770###eoif===785###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1062###sois===41544###eois===41559###lif===16###soif===770###eoif===785###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (options.verbose))) {
        AKA_mark("lis===1063###sois===41572###eois===41632###lif===17###soif===798###eoif===858###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");double bpp = data.buffer.size() / (double)(data.w * data.h);
        AKA_mark("lis===1064###sois===41642###eois===41694###lif===18###soif===868###eoif===920###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Compressed bpp: " << bpp << std::endl;
      }
else {
AKA_mark("lis===-1062-###sois===-41544-###eois===-4154415-###lif===-16-###soif===-###eoif===-785-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
      AKA_mark("lis===1066###sois===41711###eois===41783###lif===20###soif===937###eoif===1009###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Interlace method: " << info.interlace_method << std::endl;
      if(AKA_mark("lis===1067###sois===41794###eois===41809###lif===21###soif===1020###eoif===1035###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1067###sois===41794###eois===41809###lif===21###soif===1020###eoif===1035###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (options.verbose))) {
        AKA_mark("lis===1068###sois===41822###eois===41898###lif===22###soif===1048###eoif===1124###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Compression method: " << info.compression_method << std::endl;
        AKA_mark("lis===1069###sois===41908###eois===41974###lif===23###soif===1134###eoif===1200###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Filter method: " << info.filter_method << std::endl;
      }
else {
AKA_mark("lis===-1067-###sois===-41794-###eois===-4179415-###lif===-21-###soif===-###eoif===-1035-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
      AKA_mark("lis===1071###sois===41991###eois===42068###lif===25###soif===1217###eoif===1294###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Color type: " << colorTypeString(color.colortype) << std::endl;
      AKA_mark("lis===1072###sois===42076###eois===42134###lif===26###soif===1302###eoif===1360###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Bit depth: " << color.bitdepth << std::endl;
      if(AKA_mark("lis===1073###sois===42145###eois===42160###lif===27###soif===1371###eoif===1386###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1073###sois===42145###eois===42160###lif===27###soif===1371###eoif===1386###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (options.verbose))) {
        AKA_mark("lis===1074###sois===42173###eois===42245###lif===28###soif===1399###eoif===1471###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Bits per pixel: " << lodepng_get_bpp(&color) << std::endl;
        AKA_mark("lis===1075###sois===42255###eois===42336###lif===29###soif===1481###eoif===1562###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Channels per pixel: " << lodepng_get_channels(&color) << std::endl;
        AKA_mark("lis===1076###sois===42346###eois===42431###lif===30###soif===1572###eoif===1657###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Is greyscale type: " << lodepng_is_greyscale_type(&color) << std::endl;
        AKA_mark("lis===1077###sois===42441###eois===42520###lif===31###soif===1667###eoif===1746###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Can have alpha: " << lodepng_can_have_alpha(&color) << std::endl;
        AKA_mark("lis===1078###sois===42530###eois===42595###lif===32###soif===1756###eoif===1821###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Has color key: " << color.key_defined << std::endl;
      }
else {
AKA_mark("lis===-1073-###sois===-42145-###eois===-4214515-###lif===-27-###soif===-###eoif===-1386-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
    }
}

  }
else {
AKA_mark("lis===-1053-###sois===-41042-###eois===-4104219-###lif===-7-###soif===-###eoif===-287-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
  if(AKA_mark("lis===1082###sois===42623###eois===42659###lif===36###soif===1849###eoif===1885###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && ((AKA_mark("lis===1082###sois===42623###eois===42644###lif===36###soif===1849###eoif===1870###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (options.show_png_info)) && (AKA_mark("lis===1082###sois===42648###eois===42659###lif===36###soif===1874###eoif===1885###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (data.is_png)))) {
    if (AKA_mark("lis===1083###sois===42672###eois===42702###lif===37###soif===1898###eoif===1928###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1083###sois===42672###eois===42702###lif===37###soif===1898###eoif===1928###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (color.colortype == LCT_PALETTE))) {
      AKA_mark("lis===1084###sois===42713###eois===42777###lif===38###soif===1939###eoif===2003###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Palette size: " << color.palettesize << std::endl;
    }
else {
AKA_mark("lis===-1083-###sois===-42672-###eois===-4267230-###lif===-37-###soif===-###eoif===-1928-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
    if(AKA_mark("lis===1086###sois===42793###eois===42810###lif===40###soif===2019###eoif===2036###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1086###sois===42793###eois===42810###lif===40###soif===2019###eoif===2036###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (color.key_defined))) {
      AKA_mark("lis===1087###sois===42821###eois===42960###lif===41###soif===2047###eoif===2186###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Color key rgb: " << color.key_r
                << ", " << color.key_g
                << ", " << color.key_b << std::endl;
    }
else {
AKA_mark("lis===-1086-###sois===-42793-###eois===-4279317-###lif===-40-###soif===-###eoif===-2036-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
    if(AKA_mark("lis===1091###sois===42976###eois===42999###lif===45###soif===2202###eoif===2225###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1091###sois===42976###eois===42999###lif===45###soif===2202###eoif===2225###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (info.background_defined))) {
      if(AKA_mark("lis===1092###sois===43013###eois===43043###lif===46###soif===2239###eoif===2269###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1092###sois===43013###eois===43043###lif===46###soif===2239###eoif===2269###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (color.colortype == LCT_PALETTE))) {
        AKA_mark("lis===1093###sois===43056###eois===43124###lif===47###soif===2282###eoif===2350###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Background index: " << info.background_r << std::endl;
      } else {
        AKA_mark("lis===1095###sois===43150###eois===43312###lif===49###soif===2376###eoif===2538###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Background rgb: " << info.background_r
                  << ", " << info.background_g
                  << ", " << info.background_b << std::endl;
      }
    }
else {
AKA_mark("lis===-1091-###sois===-42976-###eois===-4297623-###lif===-45-###soif===-###eoif===-2225-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
    if(AKA_mark("lis===1100###sois===43337###eois===43354###lif===54###soif===2563###eoif===2580###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1100###sois===43337###eois===43354###lif===54###soif===2563###eoif===2580###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (info.gama_defined))) {
      AKA_mark("lis===1101###sois===43365###eois===43531###lif===55###soif===2591###eoif===2757###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "gAMA defined: " << info.gama_gamma << " (" << (info.gama_gamma / 100000.0)
                << ", " << (100000.0 / info.gama_gamma) << ")" << std::endl;
    }
else {
AKA_mark("lis===-1100-###sois===-43337-###eois===-4333717-###lif===-54-###soif===-###eoif===-2580-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
    if(AKA_mark("lis===1104###sois===43547###eois===43564###lif===58###soif===2773###eoif===2790###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1104###sois===43547###eois===43564###lif===58###soif===2773###eoif===2790###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (info.chrm_defined))) {
      AKA_mark("lis===1105###sois===43575###eois===44016###lif===59###soif===2801###eoif===3242###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "cHRM defined: w: " << (info.chrm_white_x / 100000.0) << " " << (info.chrm_white_y / 100000.0)
                << ", r: " << (info.chrm_red_x / 100000.0) << " " << (info.chrm_red_y / 100000.0)
                << ", g: " << (info.chrm_green_x / 100000.0) << " " << (info.chrm_green_y / 100000.0)
                << ", b: " << (info.chrm_blue_x / 100000.0) << " " << (info.chrm_blue_y / 100000.0)
                << std::endl;
    }
else {
AKA_mark("lis===-1104-###sois===-43547-###eois===-4354717-###lif===-58-###soif===-###eoif===-2790-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
    if(AKA_mark("lis===1111###sois===44032###eois===44049###lif===65###soif===3258###eoif===3275###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1111###sois===44032###eois===44049###lif===65###soif===3258###eoif===3275###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (info.srgb_defined))) {
      AKA_mark("lis===1112###sois===44060###eois===44141###lif===66###soif===3286###eoif===3367###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "sRGB defined: rendering intent: " << info.srgb_intent << std::endl;
    }
else {
AKA_mark("lis===-1111-###sois===-44032-###eois===-4403217-###lif===-65-###soif===-###eoif===-3275-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
    if(AKA_mark("lis===1114###sois===44157###eois===44174###lif===68###soif===3383###eoif===3400###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1114###sois===44157###eois===44174###lif===68###soif===3383###eoif===3400###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (info.iccp_defined))) {
      AKA_mark("lis===1115###sois===44185###eois===44300###lif===69###soif===3411###eoif===3526###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "ICC profile defined (" << info.iccp_profile_size << " bytes): name: " << info.iccp_name << std::endl;
      if(AKA_mark("lis===1116###sois===44311###eois===44380###lif===70###soif===3537###eoif===3606###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (((AKA_mark("lis===1116###sois===44311###eois===44326###lif===70###soif===3537###eoif===3552###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (options.verbose)) && (AKA_mark("lis===1116###sois===44330###eois===44355###lif===70###soif===3556###eoif===3581###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (!options.show_icc_details))) && (AKA_mark("lis===1116###sois===44359###eois===44380###lif===70###soif===3585###eoif===3606###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (!options.show_icc_hex)))) {
        AKA_mark("lis===1117###sois===44393###eois===44469###lif===71###soif===3619###eoif===3695###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Use -i or -I to show ICC profile details or hex" << std::endl;
      }
else {
AKA_mark("lis===-1116-###sois===-44311-###eois===-4431169-###lif===-70-###soif===-###eoif===-3606-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
    }
else {
AKA_mark("lis===-1114-###sois===-44157-###eois===-4415717-###lif===-68-###soif===-###eoif===-3400-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
    if(AKA_mark("lis===1120###sois===44494###eois===44511###lif===74###soif===3720###eoif===3737###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1120###sois===44494###eois===44511###lif===74###soif===3720###eoif===3737###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (info.exif_defined))) {
      AKA_mark("lis===1121###sois===44522###eois===44605###lif===75###soif===3748###eoif===3831###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "EXIF metadata defined (" << info.exif_size << " bytes)" << std::endl;
      if(AKA_mark("lis===1122###sois===44616###eois===44679###lif===76###soif===3842###eoif===3905###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (((AKA_mark("lis===1122###sois===44616###eois===44631###lif===76###soif===3842###eoif===3857###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (options.verbose)) && (AKA_mark("lis===1122###sois===44635###eois===44653###lif===76###soif===3861###eoif===3879###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (!options.show_exif))) && (AKA_mark("lis===1122###sois===44657###eois===44679###lif===76###soif===3883###eoif===3905###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (!options.show_exif_hex)))) {
        AKA_mark("lis===1123###sois===44692###eois===44761###lif===77###soif===3918###eoif===3987###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Use -e or -E to show EXIF details or hex" << std::endl;
      }
else {
AKA_mark("lis===-1122-###sois===-44616-###eois===-4461663-###lif===-76-###soif===-###eoif===-3905-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
    }
else {
AKA_mark("lis===-1120-###sois===-44494-###eois===-4449417-###lif===-74-###soif===-###eoif===-3737-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
  }
else {
AKA_mark("lis===-1082-###sois===-42623-###eois===-4262336-###lif===-36-###soif===-###eoif===-1885-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
  if(AKA_mark("lis===1127###sois===44789###eois===44834###lif===81###soif===4015###eoif===4060###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && ((AKA_mark("lis===1127###sois===44789###eois===44806###lif===81###soif===4015###eoif===4032###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (info.iccp_defined)) && (AKA_mark("lis===1127###sois===44810###eois===44834###lif===81###soif===4036###eoif===4060###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (options.show_icc_details)))) {
    if(AKA_mark("lis===1128###sois===44846###eois===44866###lif===82###soif===4072###eoif===4092###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1128###sois===44846###eois===44866###lif===82###soif===4072###eoif===4092###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (!options.show_header))) {
      AKA_mark("lis===1129###sois===44877###eois===44996###lif===83###soif===4103###eoif===4222###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "ICC profile details (" << info.iccp_profile_size << " bytes), PNG name: " << info.iccp_name << std::endl;
    }
else {
AKA_mark("lis===-1128-###sois===-44846-###eois===-4484620-###lif===-82-###soif===-###eoif===-4092-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
    AKA_mark("lis===1131###sois===45009###eois===45074###lif===85###soif===4235###eoif===4300###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");printICCDetails(info.iccp_profile, info.iccp_profile_size, "  ");
    AKA_mark("lis===1132###sois===45080###eois===45127###lif===86###soif===4306###eoif===4353###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "end of ICC profile" << std::endl;
  }
else {
AKA_mark("lis===-1127-###sois===-44789-###eois===-4478945-###lif===-81-###soif===-###eoif===-4060-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
  if(AKA_mark("lis===1134###sois===45139###eois===45180###lif===88###soif===4365###eoif===4406###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && ((AKA_mark("lis===1134###sois===45139###eois===45156###lif===88###soif===4365###eoif===4382###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (info.iccp_defined)) && (AKA_mark("lis===1134###sois===45160###eois===45180###lif===88###soif===4386###eoif===4406###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (options.show_icc_hex)))) {
    AKA_mark("lis===1135###sois===45189###eois===45249###lif===89###soif===4415###eoif===4475###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");showHex(info.iccp_profile, info.iccp_profile_size, options);
  }
else {
AKA_mark("lis===-1134-###sois===-45139-###eois===-4513941-###lif===-88-###soif===-###eoif===-4406-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
  if(AKA_mark("lis===1137###sois===45261###eois===45303###lif===91###soif===4487###eoif===4529###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && ((AKA_mark("lis===1137###sois===45261###eois===45278###lif===91###soif===4487###eoif===4504###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (info.exif_defined)) && (AKA_mark("lis===1137###sois===45282###eois===45303###lif===91###soif===4508###eoif===4529###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (options.show_exif_hex)))) {
    AKA_mark("lis===1138###sois===45312###eois===45356###lif===92###soif===4538###eoif===4582###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");showHex(info.exif, info.exif_size, options);
  }
else {
AKA_mark("lis===-1137-###sois===-45261-###eois===-4526142-###lif===-91-###soif===-###eoif===-4529-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}

  if(AKA_mark("lis===1141###sois===45370###eois===45406###lif===95###soif===4596###eoif===4632###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && ((AKA_mark("lis===1141###sois===45370###eois===45391###lif===95###soif===4596###eoif===4617###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (options.show_png_info)) && (AKA_mark("lis===1141###sois===45395###eois===45406###lif===95###soif===4621###eoif===4632###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (data.is_png)))) {
    if(AKA_mark("lis===1142###sois===45418###eois===45433###lif===96###soif===4644###eoif===4659###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1142###sois===45418###eois===45433###lif===96###soif===4644###eoif===4659###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (options.verbose))) {
AKA_mark("lis===1142###sois===45435###eois===45502###lif===96###soif===4661###eoif===4728###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Physics defined: " << info.phys_defined << std::endl;
}

else {
AKA_mark("lis===-1142-###sois===-45418-###eois===-4541815-###lif===-96-###soif===-###eoif===-4659-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
    if(AKA_mark("lis===1143###sois===45511###eois===45528###lif===97###soif===4737###eoif===4754###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (AKA_mark("lis===1143###sois===45511###eois===45528###lif===97###soif===4737###eoif===4754###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)") && (info.phys_defined))) {
      AKA_mark("lis===1144###sois===45539###eois===45653###lif===98###soif===4765###eoif===4879###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");std::cout << "Physics: X: " << info.phys_x << ", Y: " << info.phys_y << ", unit: " << info.phys_unit << std::endl;
    }
else {
AKA_mark("lis===-1143-###sois===-45511-###eois===-4551117-###lif===-97-###soif===-###eoif===-4754-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
  }
else {
AKA_mark("lis===-1141-###sois===-45370-###eois===-4537036-###lif===-95-###soif===-###eoif===-4632-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showHeaderInfo(Data&,Options const&)");
}
}

// shortens the text unless options.expand_long_texts is true
/** Instrumented function shortenText(std::string const&,Options const&) */
std::string shortenText(const std::string& text, const Options& options) /* << Aka begin of function std::string shortenText(const std::string& text, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.shortenText.45747.stub"

  if(AKA_mark("lis===1151###sois===45816###eois===45841###lif===1###soif===81###eoif===106###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)") && (AKA_mark("lis===1151###sois===45816###eois===45841###lif===1###soif===81###eoif===106###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)") && (options.expand_long_texts))) {
AKA_mark("lis===1151###sois===45843###eois===45855###lif===1###soif===108###eoif===120###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");return text;
}

else {
AKA_mark("lis===-1151-###sois===-45816-###eois===-4581625-###lif===-1-###soif===-###eoif===-106-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");
}
  AKA_mark("lis===1152###sois===45859###eois===45879###lif===2###soif===124###eoif===144###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");size_t maxlen = 512;
  AKA_mark("lis===1153###sois===45883###eois===45922###lif===3###soif===148###eoif===187###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");size_t maxnl = options.verbose ? 5 : 1;
  AKA_mark("lis===1154###sois===45926###eois===45943###lif===4###soif===191###eoif===208###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");size_t numnl = 0; // amount of newlines
  int AKA_BLOCK_LOOP_45969 = 0;
    AKA_mark("lis===1155###sois===45973###eois===45986###lif===5###soif===238###eoif===251###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");
for(size_t i = 0; AKA_mark("lis===1155###sois===45987###eois===46002###lif===5###soif===252###eoif===267###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)") && (AKA_mark("lis===1155###sois===45987###eois===46002###lif===5###soif===252###eoif===267###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)") && (i < text.size())); ({AKA_mark("lis===1155###sois===46004###eois===46007###lif===5###soif===269###eoif===272###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");i++;})) {
        AKA_BLOCK_LOOP_45969++;
        if (AKA_BLOCK_LOOP_45969 > 1000) {
            //break;
        }
    if(AKA_mark("lis===1156###sois===46019###eois===46032###lif===6###soif===284###eoif===297###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)") && (AKA_mark("lis===1156###sois===46019###eois===46032###lif===6###soif===284###eoif===297###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)") && (text[i] == 10))) {
AKA_mark("lis===1156###sois===46034###eois===46042###lif===6###soif===299###eoif===307###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");numnl++;
}

else {
AKA_mark("lis===-1156-###sois===-46019-###eois===-4601913-###lif===-6-###soif===-###eoif===-297-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");
}
    if(AKA_mark("lis===1157###sois===46051###eois===46065###lif===7###soif===316###eoif===330###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)") && (AKA_mark("lis===1157###sois===46051###eois===46065###lif===7###soif===316###eoif===330###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)") && (numnl >= maxnl))) {
      AKA_mark("lis===1158###sois===46076###eois===46087###lif===8###soif===341###eoif===352###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");maxlen = i;
      AKA_mark("lis===1159###sois===46095###eois===46101###lif===9###soif===360###eoif===366###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");break;
    }
else {
AKA_mark("lis===-1157-###sois===-46051-###eois===-4605114-###lif===-7-###soif===-###eoif===-330-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");
}
  }

  if(AKA_mark("lis===1163###sois===46122###eois===46142###lif===13###soif===387###eoif===407###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)") && (AKA_mark("lis===1163###sois===46122###eois===46142###lif===13###soif===387###eoif===407###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)") && (text.size() < maxlen))) {
AKA_mark("lis===1163###sois===46144###eois===46156###lif===13###soif===409###eoif===421###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");return text;
}

else {
AKA_mark("lis===-1163-###sois===-46122-###eois===-4612220-###lif===-13-###soif===-###eoif===-407-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");
}

  AKA_mark("lis===1165###sois===46162###eois===46269###lif===15###soif===427###eoif===534###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\shortenText(std::string const&,Options const&)");return text.substr(0, maxlen) + (numnl > 1 ? "\n" : "") + "... [TEXT SNIPPED! use -t to expand long text]";
}

// A bit more PNG info, which is from chunks that can come after IDAT. showHeaderInfo shows most other stuff.
/** Instrumented function showPNGInfo(Data&,Options const&) */
void showPNGInfo(Data& data, const Options& options) /* << Aka begin of function void showPNGInfo(Data& data, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.showPNGInfo.46392.stub"

  AKA_mark("lis===1170###sois===46445###eois===46464###lif===1###soif===58###eoif===77###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");data.loadInspect();
  if(AKA_mark("lis===1171###sois===46471###eois===46483###lif===2###soif===84###eoif===96###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (AKA_mark("lis===1171###sois===46471###eois===46483###lif===2###soif===84###eoif===96###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (!data.is_png))) {
AKA_mark("lis===1171###sois===46485###eois===46492###lif===2###soif===98###eoif===105###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");return;
}

else {
AKA_mark("lis===-1171-###sois===-46471-###eois===-4647112-###lif===-2-###soif===-###eoif===-96-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");
}
  AKA_mark("lis===1172###sois===46496###eois===46540###lif===3###soif===109###eoif===153###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");loadWithErrorRecovery(data, options, false);
  if(AKA_mark("lis===1173###sois===46547###eois===46557###lif===4###soif===160###eoif===170###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (AKA_mark("lis===1173###sois===46547###eois===46557###lif===4###soif===160###eoif===170###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (data.error))) {
AKA_mark("lis===1173###sois===46559###eois===46566###lif===4###soif===172###eoif===179###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");return;
}

else {
AKA_mark("lis===-1173-###sois===-46547-###eois===-4654710-###lif===-4-###soif===-###eoif===-170-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");
}
  AKA_mark("lis===1174###sois===46570###eois===46622###lif===5###soif===183###eoif===235###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");std::cout << (options.use_hex ? std::hex: std::dec);

  AKA_mark("lis===1176###sois===46628###eois===46674###lif===7###soif===241###eoif===287###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");const LodePNGInfo& info = data.state.info_png;

  if(AKA_mark("lis===1178###sois===46683###eois===46698###lif===9###soif===296###eoif===311###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (AKA_mark("lis===1178###sois===46683###eois===46698###lif===9###soif===296###eoif===311###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (options.verbose))) {
AKA_mark("lis===1178###sois===46700###eois===46753###lif===9###soif===313###eoif===366###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");std::cout << "Texts: " << info.text_num << std::endl;
}

else {
AKA_mark("lis===-1178-###sois===-46683-###eois===-4668315-###lif===-9-###soif===-###eoif===-311-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");
}
  int AKA_BLOCK_LOOP_46757 = 0;
    AKA_mark("lis===1179###sois===46761###eois===46774###lif===10###soif===374###eoif===387###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");
for(size_t i = 0; AKA_mark("lis===1179###sois===46775###eois===46792###lif===10###soif===388###eoif===405###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (AKA_mark("lis===1179###sois===46775###eois===46792###lif===10###soif===388###eoif===405###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (i < info.text_num)); ({AKA_mark("lis===1179###sois===46794###eois===46797###lif===10###soif===407###eoif===410###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");i++;})) {
        AKA_BLOCK_LOOP_46757++;
        if (AKA_BLOCK_LOOP_46757 > 1000) {
            //break;
        }
    AKA_mark("lis===1180###sois===46806###eois===46980###lif===11###soif===419###eoif===593###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");std::cout << "Text (" << (strlen(info.text_strings[i])) << " bytes): "
              << info.text_keys[i] << ": " << shortenText(info.text_strings[i], options) << std::endl;
  }
  if(AKA_mark("lis===1183###sois===46992###eois===47007###lif===14###soif===605###eoif===620###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (AKA_mark("lis===1183###sois===46992###eois===47007###lif===14###soif===605###eoif===620###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (options.verbose))) {
AKA_mark("lis===1183###sois===47009###eois===47077###lif===14###soif===622###eoif===690###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");std::cout << "International texts: " << info.itext_num << std::endl;
}

else {
AKA_mark("lis===-1183-###sois===-46992-###eois===-4699215-###lif===-14-###soif===-###eoif===-620-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");
}
  int AKA_BLOCK_LOOP_47081 = 0;
    AKA_mark("lis===1184###sois===47085###eois===47098###lif===15###soif===698###eoif===711###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");
for(size_t i = 0; AKA_mark("lis===1184###sois===47099###eois===47117###lif===15###soif===712###eoif===730###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (AKA_mark("lis===1184###sois===47099###eois===47117###lif===15###soif===712###eoif===730###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (i < info.itext_num)); ({AKA_mark("lis===1184###sois===47119###eois===47122###lif===15###soif===732###eoif===735###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");i++;})) {
        AKA_BLOCK_LOOP_47081++;
        if (AKA_BLOCK_LOOP_47081 > 1000) {
            //break;
        }
    AKA_mark("lis===1185###sois===47131###eois===47422###lif===16###soif===744###eoif===1035###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");std::cout << "Text (" << (strlen(info.itext_strings[i])) << " bytes): "
              << info.itext_keys[i] << ", "
              << info.itext_langtags[i] << ", "
              << info.itext_transkeys[i] << ": "
              << shortenText(info.itext_strings[i], options) << std::endl;
  }
  if(AKA_mark("lis===1191###sois===47434###eois===47449###lif===22###soif===1047###eoif===1062###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (AKA_mark("lis===1191###sois===47434###eois===47449###lif===22###soif===1047###eoif===1062###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (options.verbose))) {
AKA_mark("lis===1191###sois===47451###eois===47515###lif===22###soif===1064###eoif===1128###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");std::cout << "Time defined: " << info.time_defined << std::endl;
}

else {
AKA_mark("lis===-1191-###sois===-47434-###eois===-4743415-###lif===-22-###soif===-###eoif===-1062-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");
}
  if(AKA_mark("lis===1192###sois===47522###eois===47539###lif===23###soif===1135###eoif===1152###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (AKA_mark("lis===1192###sois===47522###eois===47539###lif===23###soif===1135###eoif===1152###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)") && (info.time_defined))) {
    AKA_mark("lis===1193###sois===47548###eois===47584###lif===24###soif===1161###eoif===1197###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");const LodePNGTime& time = info.time;
    AKA_mark("lis===1194###sois===47590###eois===47720###lif===25###soif===1203###eoif===1333###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");printf("time: %02d-%02d-%02dT%02d:%02d:%02d\n",
           time.year, time.month, time.day, time.hour, time.minute, time.second);

  }
else {
AKA_mark("lis===-1192-###sois===-47522-###eois===-4752217-###lif===-23-###soif===-###eoif===-1152-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showPNGInfo(Data&,Options const&)");
}
}

/** Instrumented function showColorStats(Data&,Options const&) */
void showColorStats(Data& data, const Options& options) /* << Aka begin of function void showColorStats(Data& data, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.showColorStats.47739.stub"

  AKA_mark("lis===1201###sois===47795###eois===47814###lif===1###soif===61###eoif===80###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");data.loadInspect();
  if(AKA_mark("lis===1202###sois===47821###eois===47833###lif===2###soif===87###eoif===99###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (AKA_mark("lis===1202###sois===47821###eois===47833###lif===2###soif===87###eoif===99###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (!data.is_png))) {
AKA_mark("lis===1202###sois===47835###eois===47842###lif===2###soif===101###eoif===108###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");return;
}

else {
AKA_mark("lis===-1202-###sois===-47821-###eois===-4782112-###lif===-2-###soif===-###eoif===-99-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");
}
  AKA_mark("lis===1203###sois===47846###eois===47898###lif===3###soif===112###eoif===164###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");std::cout << (options.use_hex ? std::hex: std::dec);
  AKA_mark("lis===1204###sois===47902###eois===47950###lif===4###soif===168###eoif===216###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");std::vector<unsigned char>& image = data.pixels;
  AKA_mark("lis===1205###sois===47954###eois===47975###lif===5###soif===220###eoif===241###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");unsigned& w = data.w;
  AKA_mark("lis===1206###sois===47979###eois===48000###lif===6###soif===245###eoif===266###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");unsigned& h = data.h;

  AKA_mark("lis===1208###sois===48006###eois===48024###lif===8###soif===272###eoif===290###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");data.loadPixels();
  if(AKA_mark("lis===1209###sois===48031###eois===48041###lif===9###soif===297###eoif===307###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (AKA_mark("lis===1209###sois===48031###eois===48041###lif===9###soif===297###eoif===307###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (data.error))) {
AKA_mark("lis===1209###sois===48043###eois===48050###lif===9###soif===309###eoif===316###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");return;
}

else {
AKA_mark("lis===-1209-###sois===-48031-###eois===-4803110-###lif===-9-###soif===-###eoif===-307-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");
}
  // TODO: move to show color stats function
  if(AKA_mark("lis===1211###sois===48103###eois===48118###lif===11###soif===369###eoif===384###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (AKA_mark("lis===1211###sois===48103###eois===48118###lif===11###soif===369###eoif===384###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (options.verbose))) {
AKA_mark("lis===1211###sois===48120###eois===48170###lif===11###soif===386###eoif===436###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");std::cout << "Num pixels: " << w * h << std::endl;
}

else {
AKA_mark("lis===-1211-###sois===-48103-###eois===-4810315-###lif===-11-###soif===-###eoif===-384-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");
}
  AKA_mark("lis===1212###sois===48174###eois===48196###lif===12###soif===440###eoif===462###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");size_t rc, gc, bc, ac;
  AKA_mark("lis===1213###sois===48200###eois===48283###lif===13###soif===466###eoif===549###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");std::cout << "Num unique colors: " << countColors(image, w, h, &rc, &gc, &bc, &ac);
  AKA_mark("lis===1214###sois===48287###eois===48372###lif===14###soif===553###eoif===638###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");std::cout << " (r: " << rc << ", g: " << gc << ", b: " << bc << ", a: " << ac << ")";
  AKA_mark("lis===1215###sois===48376###eois===48399###lif===15###soif===642###eoif===665###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");std::cout << std::endl;
  if(AKA_mark("lis===1216###sois===48406###eois===48420###lif===16###soif===672###eoif===686###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && ((AKA_mark("lis===1216###sois===48406###eois===48411###lif===16###soif===672###eoif===677###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (w > 0)) && (AKA_mark("lis===1216###sois===48415###eois===48420###lif===16###soif===681###eoif===686###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (h > 0)))) {
    AKA_mark("lis===1217###sois===48429###eois===48458###lif===17###soif===695###eoif===724###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");double avg[4] = {0, 0, 0, 0};
    AKA_mark("lis===1218###sois===48464###eois===48513###lif===18###soif===730###eoif===779###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");double min[4] = {999999, 999999, 999999, 999999};
    AKA_mark("lis===1219###sois===48519###eois===48548###lif===19###soif===785###eoif===814###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");double max[4] = {0, 0, 0, 0};
    int AKA_BLOCK_LOOP_48554 = 0;
    AKA_mark("lis===1220###sois===48558###eois===48573###lif===20###soif===824###eoif===839###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");
for(unsigned y = 0; AKA_mark("lis===1220###sois===48574###eois===48579###lif===20###soif===840###eoif===845###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (AKA_mark("lis===1220###sois===48574###eois===48579###lif===20###soif===840###eoif===845###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (y < h)); ({AKA_mark("lis===1220###sois===48581###eois===48584###lif===20###soif===847###eoif===850###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");y++;})) {
        AKA_BLOCK_LOOP_48554++;
        if (AKA_BLOCK_LOOP_48554 > 1000) {
            //break;
        }
      int AKA_BLOCK_LOOP_48595 = 0;
    AKA_mark("lis===1221###sois===48599###eois===48614###lif===21###soif===865###eoif===880###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");
for(unsigned x = 0; AKA_mark("lis===1221###sois===48615###eois===48620###lif===21###soif===881###eoif===886###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (AKA_mark("lis===1221###sois===48615###eois===48620###lif===21###soif===881###eoif===886###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (x < w)); ({AKA_mark("lis===1221###sois===48622###eois===48625###lif===21###soif===888###eoif===891###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");x++;})) {
        AKA_BLOCK_LOOP_48595++;
        if (AKA_BLOCK_LOOP_48595 > 1000) {
            //break;
        }
        int AKA_BLOCK_LOOP_48638 = 0;
    AKA_mark("lis===1222###sois===48642###eois===48652###lif===22###soif===908###eoif===918###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");
for(int c = 0; AKA_mark("lis===1222###sois===48653###eois===48658###lif===22###soif===919###eoif===924###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (AKA_mark("lis===1222###sois===48653###eois===48658###lif===22###soif===919###eoif===924###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (c < 4)); ({AKA_mark("lis===1222###sois===48660###eois===48663###lif===22###soif===926###eoif===929###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");c++;})) {
        AKA_BLOCK_LOOP_48638++;
        if (AKA_BLOCK_LOOP_48638 > 1000) {
            //break;
        }
          AKA_mark("lis===1223###sois===48678###eois===48767###lif===23###soif===944###eoif===1033###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");double v = 256 * image[y * 8 * w + x * 8 + c * 2] + image[y * 8 * w + x * 8 + c * 2 + 1];
          AKA_mark("lis===1224###sois===48779###eois===48791###lif===24###soif===1045###eoif===1057###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");avg[c] += v;
          AKA_mark("lis===1225###sois===48803###eois===48832###lif===25###soif===1069###eoif===1098###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");min[c] = std::min(min[c], v);
          AKA_mark("lis===1226###sois===48844###eois===48873###lif===26###soif===1110###eoif===1139###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");max[c] = std::max(max[c], v);
        }
      }
    }
    int AKA_BLOCK_LOOP_48906 = 0;
    AKA_mark("lis===1230###sois===48910###eois===48920###lif===30###soif===1176###eoif===1186###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");
for(int c = 0; AKA_mark("lis===1230###sois===48921###eois===48926###lif===30###soif===1187###eoif===1192###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (AKA_mark("lis===1230###sois===48921###eois===48926###lif===30###soif===1187###eoif===1192###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (c < 4)); ({AKA_mark("lis===1230###sois===48928###eois===48931###lif===30###soif===1194###eoif===1197###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");c++;})) {
        AKA_BLOCK_LOOP_48906++;
        if (AKA_BLOCK_LOOP_48906 > 1000) {
            //break;
        }
      AKA_mark("lis===1231###sois===48942###eois===48968###lif===31###soif===1208###eoif===1234###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");avg[c] /= (w * h * 257.0);
      AKA_mark("lis===1232###sois===48976###eois===48992###lif===32###soif===1242###eoif===1258###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");min[c] /= 257.0;
      AKA_mark("lis===1233###sois===49000###eois===49016###lif===33###soif===1266###eoif===1282###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");max[c] /= 257.0;
    }
    if(AKA_mark("lis===1235###sois===49032###eois===49047###lif===35###soif===1298###eoif===1313###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (AKA_mark("lis===1235###sois===49032###eois===49047###lif===35###soif===1298###eoif===1313###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)") && (options.verbose))) {
AKA_mark("lis===1235###sois===49049###eois===49126###lif===35###soif===1315###eoif===1392###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");std::cout << "Ranges shown as 0.0-255.0, even for 16-bit data:" << std::endl;
}

else {
AKA_mark("lis===-1235-###sois===-49032-###eois===-4903215-###lif===-35-###soif===-###eoif===-1313-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");
}
    AKA_mark("lis===1236###sois===49132###eois===49240###lif===36###soif===1398###eoif===1506###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");std::cout << "Average color: " << avg[0] << ", " << avg[1] << ", " << avg[2] << ", " << avg[3] << std::endl;
    AKA_mark("lis===1237###sois===49246###eois===49421###lif===37###soif===1512###eoif===1687###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");std::cout << "Color ranges: " << min[0] << "-" << max[0] << ", " << min[1] << "-" << max[1] << ", " << min[2] << "-" << max[2] << ", " << min[3] << "-" << max[3] << std::endl;
  }
else {
AKA_mark("lis===-1216-###sois===-48406-###eois===-4840614-###lif===-16-###soif===-###eoif===-686-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showColorStats(Data&,Options const&)");
}
}

/** Instrumented function showErrors(Data&,Options const&) */
void showErrors(Data& data, const Options& options) /* << Aka begin of function void showErrors(Data& data, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\showErrors(Data&,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.showErrors.49438.stub"

  AKA_mark("lis===1242###sois===49490###eois===49533###lif===1###soif===57###eoif===100###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showErrors(Data&,Options const&)");std::cout << "Error report: " << std::endl;
  AKA_mark("lis===1243###sois===49537###eois===49563###lif===2###soif===104###eoif===130###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showErrors(Data&,Options const&)");Data data2(data.filename);
  AKA_mark("lis===1244###sois===49567###eois===49611###lif===3###soif===134###eoif===178###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showErrors(Data&,Options const&)");loadWithErrorRecovery(data2, options, true);
}

/** Instrumented function readExifUint32(unsigned char const*,size_t,size_t,bool) */
uint32_t readExifUint32(const unsigned char* exif, size_t size, size_t pos, bool big_endian) /* << Aka begin of function uint32_t readExifUint32(const unsigned char* exif, size_t size, size_t pos, bool big_endian) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint32(unsigned char const*,size_t,size_t,bool)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.readExifUint32.49627.stub"

  if(AKA_mark("lis===1248###sois===49719###eois===49733###lif===1###soif===101###eoif===115###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint32(unsigned char const*,size_t,size_t,bool)") && (AKA_mark("lis===1248###sois===49719###eois===49733###lif===1###soif===101###eoif===115###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint32(unsigned char const*,size_t,size_t,bool)") && (pos + 4 > size))) {
AKA_mark("lis===1248###sois===49735###eois===49744###lif===1###soif===117###eoif===126###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint32(unsigned char const*,size_t,size_t,bool)");return 0;
}

else {
AKA_mark("lis===-1248-###sois===-49719-###eois===-4971914-###lif===-1-###soif===-###eoif===-115-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint32(unsigned char const*,size_t,size_t,bool)");
}
  if(AKA_mark("lis===1249###sois===49751###eois===49761###lif===2###soif===133###eoif===143###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint32(unsigned char const*,size_t,size_t,bool)") && (AKA_mark("lis===1249###sois===49751###eois===49761###lif===2###soif===133###eoif===143###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint32(unsigned char const*,size_t,size_t,bool)") && (big_endian))) {
    AKA_mark("lis===1250###sois===49770###eois===49905###lif===3###soif===152###eoif===287###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint32(unsigned char const*,size_t,size_t,bool)");return ((uint32_t)exif[pos + 0] << 24u) | ((uint32_t)exif[pos + 1] << 16u) | ((uint32_t)exif[pos + 2] << 8u) | (uint32_t)exif[pos + 3];
  } else {
    AKA_mark("lis===1252###sois===49923###eois===50058###lif===5###soif===305###eoif===440###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint32(unsigned char const*,size_t,size_t,bool)");return ((uint32_t)exif[pos + 3] << 24u) | ((uint32_t)exif[pos + 2] << 16u) | ((uint32_t)exif[pos + 1] << 8u) | (uint32_t)exif[pos + 0];
  }
}

/** Instrumented function readExifUint16(unsigned char const*,size_t,size_t,bool) */
uint32_t readExifUint16(const unsigned char* exif, size_t size, size_t pos, bool big_endian) /* << Aka begin of function uint32_t readExifUint16(const unsigned char* exif, size_t size, size_t pos, bool big_endian) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint16(unsigned char const*,size_t,size_t,bool)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.readExifUint16.50079.stub"

  if(AKA_mark("lis===1257###sois===50171###eois===50185###lif===1###soif===101###eoif===115###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint16(unsigned char const*,size_t,size_t,bool)") && (AKA_mark("lis===1257###sois===50171###eois===50185###lif===1###soif===101###eoif===115###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint16(unsigned char const*,size_t,size_t,bool)") && (pos + 2 > size))) {
AKA_mark("lis===1257###sois===50187###eois===50196###lif===1###soif===117###eoif===126###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint16(unsigned char const*,size_t,size_t,bool)");return 0;
}

else {
AKA_mark("lis===-1257-###sois===-50171-###eois===-5017114-###lif===-1-###soif===-###eoif===-115-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint16(unsigned char const*,size_t,size_t,bool)");
}
  if(AKA_mark("lis===1258###sois===50203###eois===50213###lif===2###soif===133###eoif===143###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint16(unsigned char const*,size_t,size_t,bool)") && (AKA_mark("lis===1258###sois===50203###eois===50213###lif===2###soif===133###eoif===143###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint16(unsigned char const*,size_t,size_t,bool)") && (big_endian))) {
    AKA_mark("lis===1259###sois===50222###eois===50287###lif===3###soif===152###eoif===217###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint16(unsigned char const*,size_t,size_t,bool)");return ((uint32_t)exif[pos + 0] << 8u) | (uint32_t)exif[pos + 1];
  } else {
    AKA_mark("lis===1261###sois===50305###eois===50370###lif===5###soif===235###eoif===300###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\readExifUint16(unsigned char const*,size_t,size_t,bool)");return ((uint32_t)exif[pos + 1] << 8u) | (uint32_t)exif[pos + 0];
  }
}


// shows all the information from 1 IFD from the exif file. If more IFDs are linked, recursively shows those too.
/** Instrumented function showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool) */
void showExifIFD(const unsigned char* exif, size_t size, size_t ifd_pos, bool big_endian, bool is_thumbnail, bool is_sub) /* << Aka begin of function void showExifIFD(const unsigned char* exif, size_t size, size_t ifd_pos, bool big_endian, bool is_thumbnail, bool is_sub) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.showExifIFD.50504.stub"

  AKA_mark("lis===1268###sois===50626###eois===50647###lif===1###soif===127###eoif===148###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");size_t pos = ifd_pos;
  AKA_mark("lis===1269###sois===50651###eois===50670###lif===2###soif===152###eoif===171###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");size_t sub_ifd = 0;
  if(AKA_mark("lis===1270###sois===50677###eois===50691###lif===3###soif===178###eoif===192###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1270###sois===50677###eois===50691###lif===3###soif===178###eoif===192###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (pos + 2 > size))) {
    AKA_mark("lis===1271###sois===50700###eois===50759###lif===4###soif===201###eoif===260###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "EXIF IFD out of range: " << pos << std::endl;
    AKA_mark("lis===1272###sois===50765###eois===50772###lif===5###soif===266###eoif===273###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");return;
  }
else {
AKA_mark("lis===-1270-###sois===-50677-###eois===-5067714-###lif===-3-###soif===-###eoif===-192-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
}
  AKA_mark("lis===1274###sois===50781###eois===50846###lif===7###soif===282###eoif===347###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");size_t num_entries = readExifUint16(exif, size, pos, big_endian);
  if(AKA_mark("lis===1275###sois===50853###eois===50859###lif===8###soif===354###eoif===360###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1275###sois===50853###eois===50859###lif===8###soif===354###eoif===360###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (is_sub))) {
    AKA_mark("lis===1276###sois===50868###eois===50956###lif===9###soif===369###eoif===457###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "EXIF Sub-IFD at " << pos << ", num entries: " << num_entries << std::endl;
  } else {
if(AKA_mark("lis===1277###sois===50970###eois===50982###lif===10###soif===471###eoif===483###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1277###sois===50970###eois===50982###lif===10###soif===471###eoif===483###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (is_thumbnail))) {
    AKA_mark("lis===1278###sois===50991###eois===51085###lif===11###soif===492###eoif===586###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "EXIF Thumbnail IFD at " << pos << ", num entries: " << num_entries << std::endl;
  } else {
    AKA_mark("lis===1280###sois===51103###eois===51187###lif===13###soif===604###eoif===688###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "EXIF IFD at " << pos << ", num entries: " << num_entries << std::endl;
  }
}

  AKA_mark("lis===1282###sois===51196###eois===51205###lif===15###soif===697###eoif===706###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");pos += 2;
  int AKA_BLOCK_LOOP_51209 = 0;
    AKA_mark("lis===1283###sois===51213###eois===51226###lif===16###soif===714###eoif===727###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
for(size_t i = 0; AKA_mark("lis===1283###sois===51227###eois===51242###lif===16###soif===728###eoif===743###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1283###sois===51227###eois===51242###lif===16###soif===728###eoif===743###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (i < num_entries)); ({AKA_mark("lis===1283###sois===51244###eois===51247###lif===16###soif===745###eoif===748###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");i++;})) {
        AKA_BLOCK_LOOP_51209++;
        if (AKA_BLOCK_LOOP_51209 > 1000) {
            //break;
        }
    if(AKA_mark("lis===1284###sois===51259###eois===51274###lif===17###soif===760###eoif===775###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1284###sois===51259###eois===51274###lif===17###soif===760###eoif===775###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (pos + 12 > size))) {
      AKA_mark("lis===1285###sois===51285###eois===51350###lif===18###soif===786###eoif===851###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "EXIF IFD entry out of range: " << pos << std::endl;
      AKA_mark("lis===1286###sois===51358###eois===51365###lif===19###soif===859###eoif===866###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");return;
    }
else {
AKA_mark("lis===-1284-###sois===-51259-###eois===-5125915-###lif===-17-###soif===-###eoif===-775-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
}
    AKA_mark("lis===1288###sois===51378###eois===51444###lif===21###soif===879###eoif===945###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");uint32_t tag_number = readExifUint16(exif, size, pos, big_endian);
    AKA_mark("lis===1289###sois===51450###eois===51516###lif===22###soif===951###eoif===1017###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");uint32_t format = readExifUint16(exif, size, pos + 2, big_endian);
    AKA_mark("lis===1290###sois===51522###eois===51585###lif===23###soif===1023###eoif===1086###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");uint32_t num = readExifUint32(exif, size, pos + 4, big_endian);
    AKA_mark("lis===1291###sois===51591###eois===51657###lif===24###soif===1092###eoif===1158###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");uint32_t offset = readExifUint32(exif, size, pos + 8, big_endian);
    AKA_mark("lis===1292###sois===51663###eois===51691###lif===25###soif===1164###eoif===1192###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");uint32_t component_size = 1;
    if(AKA_mark("lis===1293###sois===51700###eois===51726###lif===26###soif===1201###eoif===1227###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && ((AKA_mark("lis===1293###sois===51700###eois===51711###lif===26###soif===1201###eoif===1212###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 3)) || (AKA_mark("lis===1293###sois===51715###eois===51726###lif===26###soif===1216###eoif===1227###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 8)))) {
AKA_mark("lis===1293###sois===51728###eois===51747###lif===26###soif===1229###eoif===1248###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");component_size = 2;
}

    else {
if(AKA_mark("lis===1294###sois===51761###eois===51803###lif===27###soif===1262###eoif===1304###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (((AKA_mark("lis===1294###sois===51761###eois===51772###lif===27###soif===1262###eoif===1273###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 4)) || (AKA_mark("lis===1294###sois===51776###eois===51787###lif===27###soif===1277###eoif===1288###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 9))) || (AKA_mark("lis===1294###sois===51791###eois===51803###lif===27###soif===1292###eoif===1304###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 11)))) {
AKA_mark("lis===1294###sois===51805###eois===51824###lif===27###soif===1306###eoif===1325###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");component_size = 4;
}

    else {
if(AKA_mark("lis===1295###sois===51838###eois===51881###lif===28###soif===1339###eoif===1382###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (((AKA_mark("lis===1295###sois===51838###eois===51849###lif===28###soif===1339###eoif===1350###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 5)) || (AKA_mark("lis===1295###sois===51853###eois===51865###lif===28###soif===1354###eoif===1366###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 10))) || (AKA_mark("lis===1295###sois===51869###eois===51881###lif===28###soif===1370###eoif===1382###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 12)))) {
AKA_mark("lis===1295###sois===51883###eois===51902###lif===28###soif===1384###eoif===1403###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");component_size = 8;
}

else {
AKA_mark("lis===-1295-###sois===-51838-###eois===-5183843-###lif===-28-###soif===-###eoif===-1382-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
}
}

}

    AKA_mark("lis===1296###sois===51908###eois===51942###lif===29###soif===1409###eoif===1443###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");size_t len = num * component_size;
    if(AKA_mark("lis===1297###sois===51951###eois===51959###lif===30###soif===1452###eoif===1460###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1297###sois===51951###eois===51959###lif===30###soif===1452###eoif===1460###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (len <= 4))) {
AKA_mark("lis===1297###sois===51961###eois===51978###lif===30###soif===1462###eoif===1479###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");offset = pos + 8;
}

else {
AKA_mark("lis===-1297-###sois===-51951-###eois===-519518-###lif===-30-###soif===-###eoif===-1460-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
} // small value is stored in the offset itself
    AKA_mark("lis===1298###sois===52030###eois===52040###lif===31###soif===1531###eoif===1541###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");pos += 12;

    if(AKA_mark("lis===1300###sois===52051###eois===52076###lif===33###soif===1552###eoif===1577###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && ((AKA_mark("lis===1300###sois===52051###eois===52061###lif===33###soif===1552###eoif===1562###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format < 1)) || (AKA_mark("lis===1300###sois===52065###eois===52076###lif===33###soif===1566###eoif===1577###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format > 12)))) {
      AKA_mark("lis===1301###sois===52087###eois===52141###lif===34###soif===1588###eoif===1642###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "EXIF unknown entry format" << std::endl;
      AKA_mark("lis===1302###sois===52149###eois===52156###lif===35###soif===1650###eoif===1657###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");return;
    }
else {
AKA_mark("lis===-1300-###sois===-52051-###eois===-5205125-###lif===-33-###soif===-###eoif===-1577-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
}
    if(AKA_mark("lis===1304###sois===52172###eois===52184###lif===37###soif===1673###eoif===1685###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1304###sois===52172###eois===52184###lif===37###soif===1673###eoif===1685###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (is_thumbnail))) {
AKA_mark("lis===1304###sois===52186###eois===52224###lif===37###soif===1687###eoif===1725###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "EXIF tag (thumbnail): ";
}

    else {
AKA_mark("lis===1305###sois===52235###eois===52261###lif===38###soif===1736###eoif===1762###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "EXIF tag: ";
}

    // Only show some common tags by full name
    if(AKA_mark("lis===1307###sois===52318###eois===52335###lif===40###soif===1819###eoif===1836###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1307###sois===52318###eois===52335###lif===40###soif===1819###eoif===1836###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 256))) {
AKA_mark("lis===1307###sois===52337###eois===52364###lif===40###soif===1838###eoif===1865###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "Umage Width";
}

    else {
if(AKA_mark("lis===1308###sois===52378###eois===52395###lif===41###soif===1879###eoif===1896###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1308###sois===52378###eois===52395###lif===41###soif===1879###eoif===1896###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 257))) {
AKA_mark("lis===1308###sois===52397###eois===52425###lif===41###soif===1898###eoif===1926###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "Image Height";
}

    else {
if(AKA_mark("lis===1309###sois===52439###eois===52456###lif===42###soif===1940###eoif===1957###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1309###sois===52439###eois===52456###lif===42###soif===1940###eoif===1957###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 259))) {
AKA_mark("lis===1309###sois===52458###eois===52485###lif===42###soif===1959###eoif===1986###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "Compression";
}

    else {
if(AKA_mark("lis===1310###sois===52499###eois===52516###lif===43###soif===2000###eoif===2017###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1310###sois===52499###eois===52516###lif===43###soif===2000###eoif===2017###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 269))) {
AKA_mark("lis===1310###sois===52518###eois===52547###lif===43###soif===2019###eoif===2048###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "Document Name";
}

    else {
if(AKA_mark("lis===1311###sois===52561###eois===52578###lif===44###soif===2062###eoif===2079###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1311###sois===52561###eois===52578###lif===44###soif===2062###eoif===2079###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 270))) {
AKA_mark("lis===1311###sois===52580###eois===52613###lif===44###soif===2081###eoif===2114###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "Image Description";
}

    else {
if(AKA_mark("lis===1312###sois===52627###eois===52644###lif===45###soif===2128###eoif===2145###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1312###sois===52627###eois===52644###lif===45###soif===2128###eoif===2145###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 274))) {
AKA_mark("lis===1312###sois===52646###eois===52673###lif===45###soif===2147###eoif===2174###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "Orientation";
}

    else {
if(AKA_mark("lis===1313###sois===52687###eois===52704###lif===46###soif===2188###eoif===2205###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1313###sois===52687###eois===52704###lif===46###soif===2188###eoif===2205###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 282))) {
AKA_mark("lis===1313###sois===52706###eois===52734###lif===46###soif===2207###eoif===2235###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "X Resolution";
}

    else {
if(AKA_mark("lis===1314###sois===52748###eois===52765###lif===47###soif===2249###eoif===2266###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1314###sois===52748###eois===52765###lif===47###soif===2249###eoif===2266###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 283))) {
AKA_mark("lis===1314###sois===52767###eois===52795###lif===47###soif===2268###eoif===2296###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "Y Resolution";
}

    else {
if(AKA_mark("lis===1315###sois===52809###eois===52826###lif===48###soif===2310###eoif===2327###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1315###sois===52809###eois===52826###lif===48###soif===2310###eoif===2327###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 296))) {
AKA_mark("lis===1315###sois===52828###eois===52859###lif===48###soif===2329###eoif===2360###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "Resolution Unit";
}

    else {
if(AKA_mark("lis===1316###sois===52873###eois===52890###lif===49###soif===2374###eoif===2391###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1316###sois===52873###eois===52890###lif===49###soif===2374###eoif===2391###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 513))) {
AKA_mark("lis===1316###sois===52892###eois===52924###lif===49###soif===2393###eoif===2425###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "Thumbnail Offset";
}

    else {
if(AKA_mark("lis===1317###sois===52938###eois===52955###lif===50###soif===2439###eoif===2456###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1317###sois===52938###eois===52955###lif===50###soif===2439###eoif===2456###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 514))) {
AKA_mark("lis===1317###sois===52957###eois===52987###lif===50###soif===2458###eoif===2488###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "Thumbnail Size";
}

    else {
if(AKA_mark("lis===1318###sois===53001###eois===53020###lif===51###soif===2502###eoif===2521###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1318###sois===53001###eois===53020###lif===51###soif===2502###eoif===2521###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 33434))) {
AKA_mark("lis===1318###sois===53022###eois===53051###lif===51###soif===2523###eoif===2552###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "Exposure Time";
}

    else {
if(AKA_mark("lis===1319###sois===53065###eois===53084###lif===52###soif===2566###eoif===2585###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1319###sois===53065###eois===53084###lif===52###soif===2566###eoif===2585###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 33432))) {
AKA_mark("lis===1319###sois===53086###eois===53111###lif===52###soif===2587###eoif===2612###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "Copyright";
}

    else {
if(AKA_mark("lis===1320###sois===53125###eois===53144###lif===53###soif===2626###eoif===2645###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1320###sois===53125###eois===53144###lif===53###soif===2626###eoif===2645###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 36864))) {
AKA_mark("lis===1320###sois===53146###eois===53174###lif===53###soif===2647###eoif===2675###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "Exif Version";
}

    else {
if(AKA_mark("lis===1321###sois===53188###eois===53207###lif===54###soif===2689###eoif===2708###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1321###sois===53188###eois===53207###lif===54###soif===2689###eoif===2708###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 37510))) {
AKA_mark("lis===1321###sois===53209###eois===53237###lif===54###soif===2710###eoif===2738###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "User Comment";
}

    else {
AKA_mark("lis===1322###sois===53248###eois===53279###lif===55###soif===2749###eoif===2780###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "#" << tag_number;
}

}

}

}

}

}

}

}

}

}

}

}

}

}

}
 // tag for which we don't show a name here
    AKA_mark("lis===1323###sois===53328###eois===53346###lif===56###soif===2829###eoif===2847###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << ": ";

    if(AKA_mark("lis===1325###sois===53357###eois===53376###lif===58###soif===2858###eoif===2877###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1325###sois===53357###eois===53376###lif===58###soif===2858###eoif===2877###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (offset + len > size))) {
      AKA_mark("lis===1326###sois===53387###eois===53438###lif===59###soif===2888###eoif===2939###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "EXIF data out of range" << std::endl;
      AKA_mark("lis===1327###sois===53446###eois===53453###lif===60###soif===2947###eoif===2954###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");return;
    }
else {
AKA_mark("lis===-1325-###sois===-53357-###eois===-5335719-###lif===-58-###soif===-###eoif===-2877-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
}
    if(AKA_mark("lis===1329###sois===53469###eois===53477###lif===62###soif===2970###eoif===2978###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1329###sois===53469###eois===53477###lif===62###soif===2970###eoif===2978###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (len == 0))) {
      AKA_mark("lis===1330###sois===53488###eois===53524###lif===63###soif===2989###eoif===3025###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "[empty]" << std::endl;
      AKA_mark("lis===1331###sois===53532###eois===53541###lif===64###soif===3033###eoif===3042###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");continue;
    }
else {
AKA_mark("lis===-1329-###sois===-53469-###eois===-534698-###lif===-62-###soif===-###eoif===-2978-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
}

    if(AKA_mark("lis===1334###sois===53559###eois===53570###lif===67###soif===3060###eoif===3071###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1334###sois===53559###eois===53570###lif===67###soif===3060###eoif===3071###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 1))) {
      AKA_mark("lis===1335###sois===53581###eois===53617###lif===68###soif===3082###eoif===3118###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << (uint32_t)exif[offset];
    } else {
if(AKA_mark("lis===1336###sois===53633###eois===53644###lif===69###soif===3134###eoif===3145###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1336###sois===53633###eois===53644###lif===69###soif===3134###eoif===3145###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 2))) {
      int AKA_BLOCK_LOOP_53655 = 0;
    AKA_mark("lis===1337###sois===53659###eois===53672###lif===70###soif===3160###eoif===3173###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
for(size_t j = 0; AKA_mark("lis===1337###sois===53673###eois===53680###lif===70###soif===3174###eoif===3181###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1337###sois===53673###eois===53680###lif===70###soif===3174###eoif===3181###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (j < len)); ({AKA_mark("lis===1337###sois===53682###eois===53685###lif===70###soif===3183###eoif===3186###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");j++;})) {
        AKA_BLOCK_LOOP_53655++;
        if (AKA_BLOCK_LOOP_53655 > 1000) {
            //break;
        }
        if(AKA_mark("lis===1338###sois===53701###eois===53718###lif===71###soif===3202###eoif===3219###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1338###sois===53701###eois===53718###lif===71###soif===3202###eoif===3219###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (!exif[offset + j]))) {
AKA_mark("lis===1338###sois===53720###eois===53726###lif===71###soif===3221###eoif===3227###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");break;
}

else {
AKA_mark("lis===-1338-###sois===-53701-###eois===-5370117-###lif===-71-###soif===-###eoif===-3219-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
} // NULL terminator
        AKA_mark("lis===1339###sois===53755###eois===53785###lif===72###soif===3256###eoif===3286###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << exif[offset + j];
      }
    } else {
if(AKA_mark("lis===1341###sois===53810###eois===53821###lif===74###soif===3311###eoif===3322###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1341###sois===53810###eois===53821###lif===74###soif===3311###eoif===3322###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 3))) {
      AKA_mark("lis===1342###sois===53832###eois===53892###lif===75###soif===3333###eoif===3393###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << readExifUint16(exif, size, offset, big_endian);
    } else {
if(AKA_mark("lis===1343###sois===53908###eois===53919###lif===76###soif===3409###eoif===3420###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1343###sois===53908###eois===53919###lif===76###soif===3409###eoif===3420###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 4))) {
      if(AKA_mark("lis===1344###sois===53933###eois===53952###lif===77###soif===3434###eoif===3453###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1344###sois===53933###eois===53952###lif===77###soif===3434###eoif===3453###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 34665))) {
AKA_mark("lis===1344###sois===53954###eois===54011###lif===77###soif===3455###eoif===3512###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");sub_ifd = readExifUint32(exif, size, offset, big_endian);
}

      else {
AKA_mark("lis===1345###sois===54024###eois===54084###lif===78###soif===3525###eoif===3585###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << readExifUint32(exif, size, offset, big_endian);
}

    } else {
if(AKA_mark("lis===1346###sois===54100###eois===54111###lif===79###soif===3601###eoif===3612###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1346###sois===54100###eois===54111###lif===79###soif===3601###eoif===3612###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 5))) {
      AKA_mark("lis===1347###sois===54122###eois===54180###lif===80###soif===3623###eoif===3681###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");double n = readExifUint32(exif, size, offset, big_endian);
      AKA_mark("lis===1348###sois===54188###eois===54250###lif===81###soif===3689###eoif===3751###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");double d = readExifUint32(exif, size, offset + 4, big_endian);
      AKA_mark("lis===1349###sois===54258###eois===54279###lif===82###soif===3759###eoif===3780###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << (n / d);
    } else {
if(AKA_mark("lis===1350###sois===54295###eois===54467###lif===83###soif===3796###eoif===3968###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (((((((AKA_mark("lis===1350###sois===54295###eois===54306###lif===83###soif===3796###eoif===3807###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 7)) && (AKA_mark("lis===1350###sois===54310###eois===54317###lif===83###soif===3811###eoif===3818###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (len > 8))) && (AKA_mark("lis===1350###sois===54321###eois===54344###lif===83###soif===3822###eoif===3845###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (exif[offset + 0] == 'A'))) && (AKA_mark("lis===1350###sois===54348###eois===54371###lif===83###soif===3849###eoif===3872###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (exif[offset + 1] == 'S'))) &&
              (AKA_mark("lis===1351###sois===54390###eois===54413###lif===84###soif===3891###eoif===3914###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (exif[offset + 2] == 'C'))) && (AKA_mark("lis===1351###sois===54417###eois===54440###lif===84###soif===3918###eoif===3941###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (exif[offset + 3] == 'I'))) && (AKA_mark("lis===1351###sois===54444###eois===54467###lif===84###soif===3945###eoif===3968###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (exif[offset + 4] == 'I')))) {
      int AKA_BLOCK_LOOP_54478 = 0;
    AKA_mark("lis===1352###sois===54482###eois===54495###lif===85###soif===3983###eoif===3996###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
for(size_t j = 8; AKA_mark("lis===1352###sois===54496###eois===54503###lif===85###soif===3997###eoif===4004###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1352###sois===54496###eois===54503###lif===85###soif===3997###eoif===4004###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (j < len)); ({AKA_mark("lis===1352###sois===54505###eois===54508###lif===85###soif===4006###eoif===4009###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");j++;})) {
AKA_mark("lis===1352###sois===54510###eois===54540###lif===85###soif===4011###eoif===4041###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << exif[offset + j];
}

    } else {
if(AKA_mark("lis===1353###sois===54556###eois===54602###lif===86###soif===4057###eoif===4103###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (((AKA_mark("lis===1353###sois===54556###eois===54567###lif===86###soif===4057###eoif===4068###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 7)) && (AKA_mark("lis===1353###sois===54571###eois===54579###lif===86###soif===4072###eoif===4080###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (len == 4))) && (AKA_mark("lis===1353###sois===54583###eois===54602###lif===86###soif===4084###eoif===4103###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (tag_number == 36864)))) {
      int AKA_BLOCK_LOOP_54613 = 0;
    AKA_mark("lis===1354###sois===54617###eois===54630###lif===87###soif===4118###eoif===4131###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
for(size_t j = 0; AKA_mark("lis===1354###sois===54631###eois===54638###lif===87###soif===4132###eoif===4139###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1354###sois===54631###eois===54638###lif===87###soif===4132###eoif===4139###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (j < len)); ({AKA_mark("lis===1354###sois===54640###eois===54643###lif===87###soif===4141###eoif===4144###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");j++;})) {
AKA_mark("lis===1354###sois===54645###eois===54675###lif===87###soif===4146###eoif===4176###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << exif[offset + j];
}

    } else {
if(AKA_mark("lis===1355###sois===54691###eois===54702###lif===88###soif===4192###eoif===4203###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1355###sois===54691###eois===54702###lif===88###soif===4192###eoif===4203###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 8))) {
      AKA_mark("lis===1356###sois===54713###eois===54782###lif===89###soif===4214###eoif===4283###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << (int32_t)readExifUint16(exif, size, offset, big_endian);
    } else {
if(AKA_mark("lis===1357###sois===54798###eois===54809###lif===90###soif===4299###eoif===4310###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1357###sois===54798###eois===54809###lif===90###soif===4299###eoif===4310###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 9))) {
      AKA_mark("lis===1358###sois===54820###eois===54889###lif===91###soif===4321###eoif===4390###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << (int16_t)readExifUint32(exif, size, offset, big_endian);
    } else {
if(AKA_mark("lis===1359###sois===54905###eois===54917###lif===92###soif===4406###eoif===4418###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1359###sois===54905###eois===54917###lif===92###soif===4406###eoif===4418###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (format == 10))) {
      AKA_mark("lis===1360###sois===54928###eois===54995###lif===93###soif===4429###eoif===4496###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");double n = (int32_t)readExifUint32(exif, size, offset, big_endian);
      AKA_mark("lis===1361###sois===55003###eois===55074###lif===94###soif===4504###eoif===4575###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");double d = (int32_t)readExifUint32(exif, size, offset + 4, big_endian);
      AKA_mark("lis===1362###sois===55082###eois===55103###lif===95###soif===4583###eoif===4604###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << (n / d);
    } else {
      // Formats like double not handled here
      AKA_mark("lis===1365###sois===55172###eois===55232###lif===98###soif===4673###eoif===4733###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "[format " << format << ", len " << len << "]";
    }
}

}

}

}

}

}

}

}

}

    AKA_mark("lis===1367###sois===55245###eois===55268###lif===100###soif===4746###eoif===4769###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << std::endl;
  }
  if(AKA_mark("lis===1369###sois===55280###eois===55294###lif===102###soif===4781###eoif===4795###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (AKA_mark("lis===1369###sois===55280###eois===55294###lif===102###soif===4781###eoif===4795###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (pos + 4 > size))) {
    AKA_mark("lis===1370###sois===55303###eois===55360###lif===103###soif===4804###eoif===4861###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");std::cout << "EXIF IFD footer out of range" << std::endl;
    AKA_mark("lis===1371###sois===55366###eois===55373###lif===104###soif===4867###eoif===4874###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");return;
  }
else {
AKA_mark("lis===-1369-###sois===-55280-###eois===-5528014-###lif===-102-###soif===-###eoif===-4795-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
}
  AKA_mark("lis===1373###sois===55382###eois===55444###lif===106###soif===4883###eoif===4945###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");size_t next_ifd = readExifUint32(exif, size, pos, big_endian);

  // The > checks are to guarantee progress rather than infinity recursion, though it does mean
  // that an odd EXIF that places later parts earlier in the file won't be supported correctly
  if(AKA_mark("lis===1377###sois===55646###eois===55697###lif===110###soif===5147###eoif===5198###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (((AKA_mark("lis===1377###sois===55646###eois===55653###lif===110###soif===5147###eoif===5154###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (sub_ifd)) && (AKA_mark("lis===1377###sois===55657###eois===55674###lif===110###soif===5158###eoif===5175###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (sub_ifd > ifd_pos))) && (AKA_mark("lis===1377###sois===55678###eois===55697###lif===110###soif===5179###eoif===5198###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (sub_ifd != next_ifd)))) {
    AKA_mark("lis===1378###sois===55706###eois===55771###lif===111###soif===5207###eoif===5272###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");showExifIFD(exif, size, sub_ifd, big_endian, is_thumbnail, true);
  }
else {
AKA_mark("lis===-1377-###sois===-55646-###eois===-5564651-###lif===-110-###soif===-###eoif===-5198-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
}
  if(AKA_mark("lis===1380###sois===55783###eois===55813###lif===113###soif===5284###eoif===5314###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && ((AKA_mark("lis===1380###sois===55783###eois===55791###lif===113###soif===5284###eoif===5292###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (next_ifd)) && (AKA_mark("lis===1380###sois===55795###eois===55813###lif===113###soif===5296###eoif===5314###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)") && (next_ifd > ifd_pos)))) {
    AKA_mark("lis===1381###sois===55822###eois===55881###lif===114###soif===5323###eoif===5382###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");showExifIFD(exif, size, sub_ifd, big_endian, true, is_sub);
  }
else {
AKA_mark("lis===-1380-###sois===-55783-###eois===-5578330-###lif===-113-###soif===-###eoif===-5314-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExifIFD(unsigned char const*,size_t,size_t,bool,bool,bool)");
}
}

// Shows information from the EXIF chunk in the PNG, this only shows the basics
// and some primitive values of the EXIF, it's not a complete EXIF parser but
// shows the most common tags by name to verify the EXIF chunk handling is working.
/** Instrumented function showExif(Data&) */
void showExif(Data& data) /* << Aka begin of function void showExif(Data& data) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.showExif.56143.stub"

  AKA_mark("lis===1389###sois===56169###eois===56188###lif===1###soif===31###eoif===50###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");data.loadInspect();
  if(AKA_mark("lis===1390###sois===56195###eois===56205###lif===2###soif===57###eoif===67###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)") && (AKA_mark("lis===1390###sois===56195###eois===56205###lif===2###soif===57###eoif===67###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)") && (data.error))) {
AKA_mark("lis===1390###sois===56207###eois===56214###lif===2###soif===69###eoif===76###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");return;
}

else {
AKA_mark("lis===-1390-###sois===-56195-###eois===-5619510-###lif===-2-###soif===-###eoif===-67-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");
}
  if(AKA_mark("lis===1391###sois===56221###eois===56254###lif===3###soif===83###eoif===116###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)") && (AKA_mark("lis===1391###sois===56221###eois===56254###lif===3###soif===83###eoif===116###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)") && (!data.state.info_png.exif_defined))) {
    AKA_mark("lis===1392###sois===56263###eois===56330###lif===4###soif===125###eoif===192###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");std::cout << "No EXIF data present in this PNG image" << std::endl;
    AKA_mark("lis===1393###sois===56336###eois===56343###lif===5###soif===198###eoif===205###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");return;
  }
else {
AKA_mark("lis===-1391-###sois===-56221-###eois===-5622133-###lif===-3-###soif===-###eoif===-116-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");
}
  AKA_mark("lis===1395###sois===56352###eois===56405###lif===7###soif===214###eoif===267###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");const unsigned char* exif = data.state.info_png.exif;
  AKA_mark("lis===1396###sois===56409###eois===56453###lif===8###soif===271###eoif===315###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");size_t size = data.state.info_png.exif_size;
  if(AKA_mark("lis===1397###sois===56460###eois===56468###lif===9###soif===322###eoif===330###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)") && (AKA_mark("lis===1397###sois===56460###eois===56468###lif===9###soif===322###eoif===330###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)") && (size < 8))) {
    AKA_mark("lis===1398###sois===56477###eois===56535###lif===10###soif===339###eoif===397###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");std::cout << "EXIF size too small: " << size << std::endl;
    AKA_mark("lis===1399###sois===56541###eois===56548###lif===11###soif===403###eoif===410###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");return;
  }
else {
AKA_mark("lis===-1397-###sois===-56460-###eois===-564608-###lif===-9-###soif===-###eoif===-330-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");
}
  AKA_mark("lis===1401###sois===56557###eois===56605###lif===13###soif===419###eoif===467###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");std::cout << "EXIF size: " << size << std::endl;
  AKA_mark("lis===1402###sois===56609###eois===56693###lif===14###soif===471###eoif===555###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");bool big_endian = exif[0] == 'M' && exif[1] == 'M' && exif[2] == 0 && exif[3] == 42;
  AKA_mark("lis===1403###sois===56697###eois===56784###lif===15###soif===559###eoif===646###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");bool little_endian = exif[0] == 'I' && exif[1] == 'I' && exif[2] == 42 && exif[3] == 0;
  if(AKA_mark("lis===1404###sois===56791###eois===56801###lif===16###soif===653###eoif===663###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)") && (AKA_mark("lis===1404###sois===56791###eois===56801###lif===16###soif===653###eoif===663###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)") && (big_endian))) {
    AKA_mark("lis===1405###sois===56810###eois===56873###lif===17###soif===672###eoif===735###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");std::cout << "EXIF encoded using big endian (MM)" << std::endl;
  } else {
if(AKA_mark("lis===1406###sois===56887###eois===56900###lif===18###soif===749###eoif===762###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)") && (AKA_mark("lis===1406###sois===56887###eois===56900###lif===18###soif===749###eoif===762###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)") && (little_endian))) {
    AKA_mark("lis===1407###sois===56909###eois===56975###lif===19###soif===771###eoif===837###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");std::cout << "EXIF encoded using little endian (II)" << std::endl;
  } else {
    AKA_mark("lis===1409###sois===56993###eois===57071###lif===21###soif===855###eoif===933###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");std::cout << "EXIF has invalid header, must start with MM or II" << std::endl;
    AKA_mark("lis===1410###sois===57077###eois===57084###lif===22###soif===939###eoif===946###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");return;
  }
}

  AKA_mark("lis===1412###sois===57093###eois===57148###lif===24###soif===955###eoif===1010###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");size_t ifd = readExifUint32(exif, size, 4, big_endian);
  AKA_mark("lis===1413###sois===57152###eois===57207###lif===25###soif===1014###eoif===1069###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showExif(Data&)");showExifIFD(exif, size, ifd, big_endian, false, false);
}

/** Instrumented function showRender(Data&,Options const&) */
void showRender(Data& data, const Options& options) /* << Aka begin of function void showRender(Data& data, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.showRender.57219.stub"

  AKA_mark("lis===1417###sois===57271###eois===57289###lif===1###soif===57###eoif===75###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)");data.loadPixels();
  if(AKA_mark("lis===1418###sois===57296###eois===57306###lif===2###soif===82###eoif===92###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)") && (AKA_mark("lis===1418###sois===57296###eois===57306###lif===2###soif===82###eoif===92###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)") && (data.error))) {
AKA_mark("lis===1418###sois===57308###eois===57315###lif===2###soif===94###eoif===101###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)");return;
}

else {
AKA_mark("lis===-1418-###sois===-57296-###eois===-5729610-###lif===-2-###soif===-###eoif===-92-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)");
}
  if(AKA_mark("lis===1419###sois===57322###eois===57352###lif===3###soif===108###eoif===138###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)") && (AKA_mark("lis===1419###sois===57322###eois===57352###lif===3###soif===108###eoif===138###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)") && (options.rendermode == RM_ASCII))) {
    AKA_mark("lis===1420###sois===57361###eois===57426###lif===4###soif===147###eoif===212###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)");displayAsciiArt(data.pixels, data.w, data.h, options.rendersize);
  }
else {
AKA_mark("lis===-1419-###sois===-57322-###eois===-5732230-###lif===-3-###soif===-###eoif===-138-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)");
}

  if(AKA_mark("lis===1423###sois===57440###eois===57468###lif===7###soif===226###eoif===254###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)") && (AKA_mark("lis===1423###sois===57440###eois===57468###lif===7###soif===226###eoif===254###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)") && (options.rendermode == RM_HEX))) {
    AKA_mark("lis===1424###sois===57477###eois===57530###lif===8###soif===263###eoif===316###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)");displayColorsHex(data.pixels, data.w, data.h, false);
  }
else {
AKA_mark("lis===-1423-###sois===-57440-###eois===-5744028-###lif===-7-###soif===-###eoif===-254-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)");
}

  if(AKA_mark("lis===1427###sois===57544###eois===57574###lif===11###soif===330###eoif===360###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)") && (AKA_mark("lis===1427###sois===57544###eois===57574###lif===11###soif===330###eoif===360###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)") && (options.rendermode == RM_HEX16))) {
    AKA_mark("lis===1428###sois===57583###eois===57635###lif===12###soif===369###eoif===421###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)");displayColorsHex(data.pixels, data.w, data.h, true);
  }
else {
AKA_mark("lis===-1427-###sois===-57544-###eois===-5754430-###lif===-11-###soif===-###eoif===-360-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)");
}

  if(AKA_mark("lis===1431###sois===57649###eois===57677###lif===15###soif===435###eoif===463###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)") && (AKA_mark("lis===1431###sois===57649###eois===57677###lif===15###soif===435###eoif===463###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)") && (options.rendermode == RM_PAL))) {
    AKA_mark("lis===1432###sois===57686###eois===57729###lif===16###soif===472###eoif===515###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)");displayPalettePixels(data.buffer, options);
  }
else {
AKA_mark("lis===-1431-###sois===-57649-###eois===-5764928-###lif===-15-###soif===-###eoif===-463-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showRender(Data&,Options const&)");
}
}


/** Instrumented function showInfos(Data&,Options const&) */
void showInfos(Data& data, const Options& options) /* << Aka begin of function void showInfos(Data& data, const Options& options) >> */
{AKA_mark("Calling: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");AKA_fCall++;
	/** Include stub source code */
	#include "pngdetail.cpp.showInfos.57748.stub"

  if(AKA_mark("lis===1438###sois===57802###eois===57831###lif===1###soif===59###eoif===88###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (AKA_mark("lis===1438###sois===57802###eois===57831###lif===1###soif===59###eoif===88###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_one_line_summary))) {
AKA_mark("lis===1438###sois===57833###eois===57870###lif===1###soif===90###eoif===127###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");showSingleLineSummary(data, options);
}

else {
AKA_mark("lis===-1438-###sois===-57802-###eois===-5780229-###lif===-1-###soif===-###eoif===-88-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");
}
  if(AKA_mark("lis===1439###sois===57877###eois===57896###lif===2###soif===134###eoif===153###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (AKA_mark("lis===1439###sois===57877###eois===57896###lif===2###soif===134###eoif===153###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_errors))) {
AKA_mark("lis===1439###sois===57898###eois===57924###lif===2###soif===155###eoif===181###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");showErrors(data, options);
}

else {
AKA_mark("lis===-1439-###sois===-57877-###eois===-5787719-###lif===-2-###soif===-###eoif===-153-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");
}
  if(AKA_mark("lis===1440###sois===57931###eois===57948###lif===3###soif===188###eoif===205###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (AKA_mark("lis===1440###sois===57931###eois===57948###lif===3###soif===188###eoif===205###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_exif))) {
AKA_mark("lis===1440###sois===57950###eois===57965###lif===3###soif===207###eoif===222###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");showExif(data);
}

else {
AKA_mark("lis===-1440-###sois===-57931-###eois===-5793117-###lif===-3-###soif===-###eoif===-205-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");
}
  if(AKA_mark("lis===1441###sois===57972###eois===58068###lif===4###soif===229###eoif===325###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && ((((AKA_mark("lis===1441###sois===57972###eois===57991###lif===4###soif===229###eoif===248###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_header)) || (AKA_mark("lis===1441###sois===57995###eois===58019###lif===4###soif===252###eoif===276###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_icc_details))) || (AKA_mark("lis===1441###sois===58023###eois===58043###lif===4###soif===280###eoif===300###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_icc_hex))) || (AKA_mark("lis===1441###sois===58047###eois===58068###lif===4###soif===304###eoif===325###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_exif_hex)))) {
AKA_mark("lis===1441###sois===58070###eois===58100###lif===4###soif===327###eoif===357###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");showHeaderInfo(data, options);
}

else {
AKA_mark("lis===-1441-###sois===-57972-###eois===-5797296-###lif===-4-###soif===-###eoif===-325-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");
}
  if(AKA_mark("lis===1442###sois===58107###eois===58131###lif===5###soif===364###eoif===388###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (AKA_mark("lis===1442###sois===58107###eois===58131###lif===5###soif===364###eoif===388###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_color_stats))) {
AKA_mark("lis===1442###sois===58133###eois===58163###lif===5###soif===390###eoif===420###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");showColorStats(data, options);
}

else {
AKA_mark("lis===-1442-###sois===-58107-###eois===-5810724-###lif===-5-###soif===-###eoif===-388-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");
}
  if(AKA_mark("lis===1443###sois===58170###eois===58191###lif===6###soif===427###eoif===448###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (AKA_mark("lis===1443###sois===58170###eois===58191###lif===6###soif===427###eoif===448###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_png_info))) {
AKA_mark("lis===1443###sois===58193###eois===58220###lif===6###soif===450###eoif===477###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");showPNGInfo(data, options);
}

else {
AKA_mark("lis===-1443-###sois===-58170-###eois===-5817021-###lif===-6-###soif===-###eoif===-448-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");
}
  if(AKA_mark("lis===1444###sois===58227###eois===58247###lif===7###soif===484###eoif===504###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (AKA_mark("lis===1444###sois===58227###eois===58247###lif===7###soif===484###eoif===504###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_palette))) {
AKA_mark("lis===1444###sois===58249###eois===58279###lif===7###soif===506###eoif===536###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");displayPalette(data, options);
}

else {
AKA_mark("lis===-1444-###sois===-58227-###eois===-5822720-###lif===-7-###soif===-###eoif===-504-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");
}
  if(AKA_mark("lis===1445###sois===58286###eois===58329###lif===8###soif===543###eoif===586###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && ((AKA_mark("lis===1445###sois===58286###eois===58305###lif===8###soif===543###eoif===562###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_chunks)) || (AKA_mark("lis===1445###sois===58309###eois===58329###lif===8###soif===566###eoif===586###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_chunks2)))) {
AKA_mark("lis===1445###sois===58331###eois===58364###lif===8###soif===588###eoif===621###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");displayChunkNames(data, options);
}

else {
AKA_mark("lis===-1445-###sois===-58286-###eois===-5828643-###lif===-8-###soif===-###eoif===-586-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");
}
  if(AKA_mark("lis===1446###sois===58371###eois===58391###lif===9###soif===628###eoif===648###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (AKA_mark("lis===1446###sois===58371###eois===58391###lif===9###soif===628###eoif===648###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_filters))) {
AKA_mark("lis===1446###sois===58393###eois===58427###lif===9###soif===650###eoif===684###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");displayFilterTypes(data, options);
}

else {
AKA_mark("lis===-1446-###sois===-58371-###eois===-5837120-###lif===-9-###soif===-###eoif===-648-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");
}
  if(AKA_mark("lis===1447###sois===58434###eois===58456###lif===10###soif===691###eoif===713###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (AKA_mark("lis===1447###sois===58434###eois===58456###lif===10###soif===691###eoif===713###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_zlib_info))) {
AKA_mark("lis===1447###sois===58458###eois===58478###lif===10###soif===715###eoif===735###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");printZlibInfo(data);
}

else {
AKA_mark("lis===-1447-###sois===-58434-###eois===-5843422-###lif===-10-###soif===-###eoif===-713-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");
}
  if(AKA_mark("lis===1448###sois===58485###eois===58504###lif===11###soif===742###eoif===761###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (AKA_mark("lis===1448###sois===58485###eois===58504###lif===11###soif===742###eoif===761###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (options.show_render))) {
AKA_mark("lis===1448###sois===58506###eois===58532###lif===11###soif===763###eoif===789###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");showRender(data, options);
}

else {
AKA_mark("lis===-1448-###sois===-58485-###eois===-5848519-###lif===-11-###soif===-###eoif===-761-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");
}

  if(AKA_mark("lis===1450###sois===58541###eois===58551###lif===13###soif===798###eoif===808###ifc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (AKA_mark("lis===1450###sois===58541###eois===58551###lif===13###soif===798###eoif===808###isc===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)") && (data.error))) {
AKA_mark("lis===1450###sois===58553###eois===58578###lif===13###soif===810###eoif===835###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");showError(data, options);
}

else {
AKA_mark("lis===-1450-###sois===-58541-###eois===-5854110-###lif===-13-###soif===-###eoif===-808-###ins===true###function===.\\lvandeve_lodepng\\src\\pngdetail.cpp\\showInfos(Data&,Options const&)");
}
}

// int main(int argc, char *argv[]) {
//   Options options;
//   bool options_chosen = false;

//   std::vector<std::string> filenames;
//   for (int i = 1; i < argc; i++) {
//     std::string s = argv[i];
//     if(s.size() > 1 && s[0] == '-' && s[1] != '-') {
//       // anything that chooses actual set disables the defaults
//       if(s != "-x" && s != "-v" && s != "-t") options_chosen = true;
//       for(size_t j = 1; j < s.size(); j++) {
//         char c = s[j];
//         if(c == 'o') options.show_one_line_summary = true;
//         else if(c == 'H') options.show_header = true;
//         else if(c == 'i') options.show_icc_details = true;
//         else if(c == 'I') options.show_icc_hex = true;
//         else if(c == 'e') options.show_exif = true;
//         else if(c == 'E') options.show_exif_hex = true;
//         else if(c == 'v') options.verbose = true;
//         else if(c == 't') options.expand_long_texts = true;
//         else if(c == 's') options.show_color_stats = true;
//         else if(c == 'a') options.show_errors = true;
//         else if(c == 'p') options.show_header = options.show_png_info = true;
//         else if(c == 'r') options.show_render = true;
//         else if(c == 'l') options.show_palette = true;
//         else if(c == 'L') options.show_palette_pixels = true;
//         else if(c == 'c') options.show_chunks = true;
//         else if(c == 'C') options.show_chunks2 = true;
//         else if(c == 'f') options.show_filters = true;
//         else if(c == 'z') options.show_zlib_info = true;
//         else if(c == 'x') {
//           options.use_hex = true;
//           std::cout << std::hex;
//         } else {
//           if(s != "--help" && c != 'h' && c != '?') std::cout << "Unknown flag: " << c << ". Use -h for help" << std::endl;
//           showHelp();
//           return 0;
//         }

//       }
//     } else if(s.size() > 1 && s[0] == '-' && s[1] == '-') {
//       size_t eqpos = 2;
//       while(eqpos < s.size() && s[eqpos] != '=') eqpos++;
//       std::string key = s.substr(2, eqpos - 2);
//       std::string value = (eqpos + 1) < s.size() ? s.substr(eqpos + 1) : "";
//       if(key == "help") {
//         showHelp();
//         return 0;
//       }
//       if(key == "mode") {
//         if(value == "ascii") options.rendermode = RM_ASCII;
//         else if(value == "hex") options.rendermode = RM_HEX;
//         else if(value == "hex16") options.rendermode = RM_HEX16;
//         else if(value == "palette") options.rendermode = RM_PAL;
//       }
//       if(key == "size") {
//         int size = strtoval<int>(value);
//         if(size >= 1 && size <= 4096) options.rendersize = size;
//       }
//       if(key == "format") {
//         if(value == "mix") options.hexformat = HF_MIX;
//         else if(value == "hex") options.hexformat = HF_HEX;
//         else if(value == "bin") options.hexformat = HF_BIN;
//       }
//     }
//     else filenames.push_back(s);
//   }

//   if(filenames.empty()) {
//     std::cout << "Please provide a filename to preview" << std::endl;
//     showHelp();
//     return 0;
//   }

//   if(!options_chosen) {
//     //fill in defaults
//     options.show_header = true;
//     options.show_png_info = true;
//     options.show_chunks2 = true;
//     // verbose lets individual sections show more, and in addition adds more default unlocked sections if no specific one chosen
//     if(options.verbose) {
//       options.show_chunks2 = false;
//       options.show_chunks = true;
//     }
//   }

//   for(size_t i = 0; i < filenames.size(); i++) {
//     if(filenames.size() > 1) {
//       if(i > 0 && !options.show_one_line_summary) std::cout << std::endl;
//       std::cout << filenames[i] << ":";
//       if(!options.show_one_line_summary) std::cout << std::endl; else std::cout << " ";
//     }
//     Data data(filenames[i]);
//     showInfos(data, options);
//   }
// }


#endif
