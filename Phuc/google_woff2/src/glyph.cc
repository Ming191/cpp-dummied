/* Copyright 2013 Google Inc. All Rights Reserved.

   Distributed under MIT license.
   See file LICENSE for detail or copy at https://opensource.org/licenses/MIT
*/

/* Glyph manipulation */

#include "glyph.h"
#include "buffer.h"
#include "store_bytes.h"

namespace woff2 {

static const int32_t kFLAG_ONCURVE = 1;
static const int32_t kFLAG_XSHORT = 1 << 1;
static const int32_t kFLAG_YSHORT = 1 << 2;
static const int32_t kFLAG_REPEAT = 1 << 3;
static const int32_t kFLAG_XREPEATSIGN = 1 << 4;
static const int32_t kFLAG_YREPEATSIGN = 1 << 5;
static const int32_t kFLAG_OVERLAP_SIMPLE = 1 << 6;
static const int32_t kFLAG_ARG_1_AND_2_ARE_WORDS = 1 << 0;
static const int32_t kFLAG_WE_HAVE_A_SCALE = 1 << 3;
static const int32_t kFLAG_MORE_COMPONENTS = 1 << 5;
static const int32_t kFLAG_WE_HAVE_AN_X_AND_Y_SCALE = 1 << 6;
static const int32_t kFLAG_WE_HAVE_A_TWO_BY_TWO = 1 << 7;
static const int32_t kFLAG_WE_HAVE_INSTRUCTIONS = 1 << 8;

bool ReadCompositeGlyphData(Buffer* buffer, Glyph* glyph) {
  glyph->have_instructions = false;
  glyph->composite_data = buffer->buffer() + buffer->offset();
  size_t start_offset = buffer->offset();
  uint16_t flags = kFLAG_MORE_COMPONENTS;
  while (flags & kFLAG_MORE_COMPONENTS) {
    if (!buffer->ReadU16(&flags)) {
      return FONT_COMPRESSION_FAILURE();
    }
    glyph->have_instructions |= (flags & kFLAG_WE_HAVE_INSTRUCTIONS) != 0;
    size_t arg_size = 2;  // glyph index
    if (flags & kFLAG_ARG_1_AND_2_ARE_WORDS) {
      arg_size += 4;
    } else {
      arg_size += 2;
    }
    if (flags & kFLAG_WE_HAVE_A_SCALE) {
      arg_size += 2;
    } else if (flags & kFLAG_WE_HAVE_AN_X_AND_Y_SCALE) {
      arg_size += 4;
    } else if (flags & kFLAG_WE_HAVE_A_TWO_BY_TWO) {
      arg_size += 8;
    }
    if (!buffer->Skip(arg_size)) {
      return FONT_COMPRESSION_FAILURE();
    }
  }
  if (buffer->offset() - start_offset > std::numeric_limits<uint32_t>::max()) {
    return FONT_COMPRESSION_FAILURE();
  }
  glyph->composite_data_size = buffer->offset() - start_offset;
  return true;
}

bool ReadGlyph(const uint8_t* data, size_t len, Glyph* glyph) {
}

namespace {

void StoreBbox(const Glyph& glyph, size_t* offset, uint8_t* dst) {
}

void StoreInstructions(const Glyph& glyph, size_t* offset, uint8_t* dst) {

}

bool StoreEndPtsOfContours(const Glyph& glyph, size_t* offset, uint8_t* dst) {
}

bool StorePoints(const Glyph& glyph, size_t* offset,
                 uint8_t* dst, size_t dst_size) {
}

}  // namespace

bool StoreGlyph(const Glyph& glyph, uint8_t* dst, size_t* dst_size) {
  size_t offset = 0;
  if (glyph.composite_data_size > 0) {
    // Composite glyph.
    if (*dst_size < ((10ULL + glyph.composite_data_size) +
                     ((glyph.have_instructions ? 2ULL : 0) +
                      glyph.instructions_size))) {
      return FONT_COMPRESSION_FAILURE();
    }
    Store16(-1, &offset, dst);
    StoreBbox(glyph, &offset, dst);
    StoreBytes(glyph.composite_data, glyph.composite_data_size, &offset, dst);
    if (glyph.have_instructions) {
      StoreInstructions(glyph, &offset, dst);
    }
  } else if (glyph.contours.size() > 0) {
    // Simple glyph.
    if (glyph.contours.size() > std::numeric_limits<int16_t>::max()) {
      return FONT_COMPRESSION_FAILURE();
    }
    if (*dst_size < ((12ULL + 2 * glyph.contours.size()) +
                     glyph.instructions_size)) {
      return FONT_COMPRESSION_FAILURE();
    }
    Store16(glyph.contours.size(), &offset, dst);
    StoreBbox(glyph, &offset, dst);
    if (!StoreEndPtsOfContours(glyph, &offset, dst)) {
      return FONT_COMPRESSION_FAILURE();
    }
    StoreInstructions(glyph, &offset, dst);
    if (!StorePoints(glyph, &offset, dst, *dst_size)) {
      return FONT_COMPRESSION_FAILURE();
    }
  }
}

} // namespace woff2
