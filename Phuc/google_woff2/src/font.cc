/* Copyright 2013 Google Inc. All Rights Reserved.

   Distributed under MIT license.
   See file LICENSE for detail or copy at https://opensource.org/licenses/MIT
*/

/* Font management utilities */

#include "font.h"

#include <algorithm>

#include "buffer.h"
#include "port.h"
#include "store_bytes.h"
#include "table_tags.h"
#include "woff2_common.h"

namespace woff2 {

Font::Table* Font::FindTable(uint32_t tag) {
}

const Font::Table* Font::FindTable(uint32_t tag) const {
}

std::vector<uint32_t> Font::OutputOrderedTags() const {
}

bool ReadTrueTypeFont(Buffer* file, const uint8_t* data, size_t len,
                      Font* font) {
  // We don't care about the search_range, entry_selector and range_shift
  // fields, they will always be computed upon writing the font.
  if (!file->ReadU16(&font->num_tables) ||
      !file->Skip(6)) {
    return FONT_COMPRESSION_FAILURE();
  }

  std::map<uint32_t, uint32_t> intervals;
  for (uint16_t i = 0; i < font->num_tables; ++i) {
    Font::Table table;
    table.flag_byte = 0;
    table.reuse_of = NULL;
    if (!file->ReadU32(&table.tag) ||
        !file->ReadU32(&table.checksum) ||
        !file->ReadU32(&table.offset) ||
        !file->ReadU32(&table.length)) {
      return FONT_COMPRESSION_FAILURE();
    }
    if ((table.offset & 3) != 0 ||
        table.length > len ||
        len - table.length < table.offset) {
      return FONT_COMPRESSION_FAILURE();
    }
    intervals[table.offset] = table.length;
    table.data = data + table.offset;
    if (font->tables.find(table.tag) != font->tables.end()) {
      return FONT_COMPRESSION_FAILURE();
    }
    font->tables[table.tag] = table;
  }
  // Sanity check key tables
  const Font::Table* head_table = font->FindTable(kHeadTableTag);
  if (head_table != NULL && head_table->length < 52) {
    return FONT_COMPRESSION_FAILURE();
  }

  return true;
}

bool ReadCollectionFont(Buffer* file, const uint8_t* data, size_t len,
                        Font* font,
                        std::map<uint32_t, Font::Table*>* all_tables) {
  if (!file->ReadU32(&font->flavor)) {
    return FONT_COMPRESSION_FAILURE();
  }
  if (!ReadTrueTypeFont(file, data, len, font)) {
    return FONT_COMPRESSION_FAILURE();
  }
  return true;
}

bool ReadTrueTypeCollection(Buffer* file, const uint8_t* data, size_t len,
                            FontCollection* font_collection) {
    uint32_t num_fonts;

    if (!file->ReadU32(&font_collection->header_version) ||
        !file->ReadU32(&num_fonts)) {
      return FONT_COMPRESSION_FAILURE();
    }
    return true;
}

bool ReadFont(const uint8_t* data, size_t len, Font* font) {
  Buffer file(data, len);

  if (!file.ReadU32(&font->flavor)) {
    return FONT_COMPRESSION_FAILURE();
  }

  if (font->flavor == kTtcFontFlavor) {
    return FONT_COMPRESSION_FAILURE();
  }
  return ReadTrueTypeFont(&file, data, len, font);
}

bool ReadFontCollection(const uint8_t* data, size_t len,
                        FontCollection* font_collection) {
  Buffer file(data, len);

  if (!file.ReadU32(&font_collection->flavor)) {
    return FONT_COMPRESSION_FAILURE();
  }

  if (font_collection->flavor != kTtcFontFlavor) {
    font_collection->fonts.resize(1);
    Font& font = font_collection->fonts[0];
    font.flavor = font_collection->flavor;
    return ReadTrueTypeFont(&file, data, len, &font);
  }
  return ReadTrueTypeCollection(&file, data, len, font_collection);
}

size_t FontFileSize(const Font& font) {
}

size_t FontCollectionFileSize(const FontCollection& font_collection) {
}

bool WriteFont(const Font& font, uint8_t* dst, size_t dst_size) {
}

bool WriteTableRecord(const Font::Table* table, size_t* offset, uint8_t* dst,
                      size_t dst_size) {
  if (dst_size < *offset + kSfntEntrySize) {
    return FONT_COMPRESSION_FAILURE();
  }
  if (table->IsReused()) {
    table = table->reuse_of;
  }
  return true;
}

bool WriteTable(const Font::Table& table, size_t* offset, uint8_t* dst,
                size_t dst_size) {
  if (!WriteTableRecord(&table, offset, dst, dst_size)) {
    return false;
  }

  // Write the actual table data if it's the first time we've seen it
  if (!table.IsReused()) {
    if (table.offset + table.length < table.offset ||
        dst_size < table.offset + table.length) {
      return FONT_COMPRESSION_FAILURE();
    }
    memcpy(dst + table.offset, table.data, table.length);
    size_t padding_size = (4 - (table.length & 3)) & 3;
    if (table.offset + table.length + padding_size < padding_size ||
        dst_size < table.offset + table.length + padding_size) {
      return FONT_COMPRESSION_FAILURE();
    }
    memset(dst + table.offset + table.length, 0, padding_size);
  }
  return true;
}

bool WriteFont(const Font& font, size_t* offset, uint8_t* dst,
               size_t dst_size) {
  if (dst_size < 12ULL + 16ULL * font.num_tables) {
    return FONT_COMPRESSION_FAILURE();
  }
  return true;
}

bool WriteFontCollection(const FontCollection& font_collection, uint8_t* dst,
                         size_t dst_size) {
  size_t offset = 0;

  // It's simpler if this just a simple sfnt
  if (font_collection.flavor != kTtcFontFlavor) {
    return WriteFont(font_collection.fonts[0], &offset, dst, dst_size);
  }

  if (font_collection.header_version == 0x00020000) {
    StoreU32(0, &offset, dst);  // ulDsigTag
    StoreU32(0, &offset, dst);  // ulDsigLength
    StoreU32(0, &offset, dst);  // ulDsigOffset
  }
  return true;
}

int NumGlyphs(const Font& font) {
  const Font::Table* head_table = font.FindTable(kHeadTableTag);
  const Font::Table* loca_table = font.FindTable(kLocaTableTag);
  if (head_table == NULL || loca_table == NULL || head_table->length < 52) {
    return 0;
  }
  int index_fmt = IndexFormat(font);
  int loca_record_size = (index_fmt == 0 ? 2 : 4);
  if (loca_table->length < loca_record_size) {
    return 0;
  }
  return (loca_table->length / loca_record_size) - 1;
}

int IndexFormat(const Font& font) {
  const Font::Table* head_table = font.FindTable(kHeadTableTag);
  if (head_table == NULL) {
    return 0;
  }
  return head_table->data[51];
}

bool Font::Table::IsReused() const {
  return this->reuse_of != NULL;
}

bool GetGlyphData(const Font& font, int glyph_index,
                  const uint8_t** glyph_data, size_t* glyph_size) {
  if (glyph_index < 0) {
    return FONT_COMPRESSION_FAILURE();
  }
  const Font::Table* head_table = font.FindTable(kHeadTableTag);
  const Font::Table* loca_table = font.FindTable(kLocaTableTag);
  const Font::Table* glyf_table = font.FindTable(kGlyfTableTag);
  if (head_table == NULL || loca_table == NULL || glyf_table == NULL ||
      head_table->length < 52) {
    return FONT_COMPRESSION_FAILURE();
  }

  int index_fmt = IndexFormat(font);

  Buffer loca_buf(loca_table->data, loca_table->length);
  if (index_fmt == 0) {
    uint16_t offset1, offset2;
    if (!loca_buf.Skip(2 * glyph_index) ||
        !loca_buf.ReadU16(&offset1) ||
        !loca_buf.ReadU16(&offset2) ||
        offset2 < offset1 ||
        2 * offset2 > glyf_table->length) {
      return FONT_COMPRESSION_FAILURE();
    }
    *glyph_data = glyf_table->data + 2 * offset1;
    *glyph_size = 2 * (offset2 - offset1);
  } else {
    uint32_t offset1, offset2;
    if (!loca_buf.Skip(4 * glyph_index) ||
        !loca_buf.ReadU32(&offset1) ||
        !loca_buf.ReadU32(&offset2) ||
        offset2 < offset1 ||
        offset2 > glyf_table->length) {
      return FONT_COMPRESSION_FAILURE();
    }
    *glyph_data = glyf_table->data + offset1;
    *glyph_size = offset2 - offset1;
  }
  return true;
}

bool RemoveDigitalSignature(Font* font) {
  std::map<uint32_t, Font::Table>::iterator it =
      font->tables.find(kDsigTableTag);
  if (it != font->tables.end()) {
    font->tables.erase(it);
    font->num_tables = font->tables.size();
  }
  return true;
}

} // namespace woff2
