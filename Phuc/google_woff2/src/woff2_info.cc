/* Copyright 2014 Google Inc. All Rights Reserved.

   Distributed under MIT license.
   See file LICENSE for detail or copy at https://opensource.org/licenses/MIT
*/

/* A commandline tool for dumping info about a woff2 file. */

#include <string>

#include "file.h"
#include "woff2_common.h"
#include "buffer.h"
#include "font.h"
#include "table_tags.h"
#include "variable_length.h"

std::string PrintTag(int tag) {
  if (tag & 0x80808080) {
    return std::string("_xfm");  // print _xfm for xform tables (else garbage)
  }
  char printable[] = {
    static_cast<char>((tag >> 24) & 0xFF),
    static_cast<char>((tag >> 16) & 0xFF),
    static_cast<char>((tag >> 8) & 0xFF),
    static_cast<char>(tag & 0xFF)
  };
  return std::string(printable, 4);
}

