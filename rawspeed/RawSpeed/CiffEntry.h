#ifndef CIFF_ENTRY_H
#define CIFF_ENTRY_H

#include "CiffParserException.h"
#include "CiffTag.h"
#include "FileMap.h"

/* 
    RawSpeed - RAW file decoder.

    Copyright (C) 2009-2014 Klaus Post
    Copyright (C) 2014 Pedro Côrte-Real

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

    http://www.klauspost.com
*/

namespace RawSpeed {

/*
 * Tag data type information.
 */
typedef	enum {
	CIFF_BYTE  = 0x0000,	/* 8-bit unsigned integer */
	CIFF_ASCII = 0x0800,	/* 8-bit bytes w/ last byte null */
	CIFF_SHORT = 0x1000,	/* 16-bit unsigned integer */
	CIFF_LONG  = 0x1800,	/* 32-bit unsigned integer */
	CIFF_MIX   = 0x2000,	/* 32-bit unsigned integer */
	CIFF_SUB1  = 0x2800,	/* 32-bit unsigned integer */
	CIFF_SUB2  = 0x3000,	/* 32-bit unsigned integer */
} CiffDataType;


class CiffEntry
{
public:
  CiffEntry(FileMap* f, uint32 value_data, uint32 offset);
  ~CiffEntry(void);
  uint32 getInt(uint32 num=0);
  ushort16 getShort(uint32 num=0);
  string getString();
  vector<string> getStrings();
  uchar8 getByte(uint32 num=0);
  const uchar8* getData() {return data;};
  uchar8* getDataWrt();;
  void setData(const void *data, uint32 byte_count );
  uint32 getElementSize();
  uint32 getElementShift();
// variables:
  CiffTag tag;
  CiffDataType type;
  uint32 count;
  uint32 bytesize;
  uint32 data_offset;
  uint32 getDataOffset() const { return data_offset; }
  bool isInt();
  bool isString();
protected:
  string getValueAsString();
  uchar8* own_data;
  const uchar8* data;
#ifdef _DEBUG
  int debug_intVal;
  float debug_floatVal;
#endif
};

} // namespace RawSpeed

#endif
