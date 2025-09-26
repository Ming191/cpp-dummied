/*
 * s3fs - FUSE-based file system backed by Amazon S3
 *
 * Copyright(C) 2007 Takeshi Nakatani <ggtakec.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

//#include <cstdlib>
//#include <mutex>

#include "s3fs_logger.h"
#include "fdcache_untreated.h"

//------------------------------------------------
// UntreatedParts methods
//------------------------------------------------
bool UntreatedParts::empty() const
{
}

bool UntreatedParts::AddPart(off_t start, off_t size)
{
}

bool UntreatedParts::RowGetPart(off_t& start, off_t& size, off_t max_size, off_t min_size, bool lastpart) const
{
    return false;
}

// [NOTE]
// If size is specified as 0, all areas(parts) after start will be deleted.
//
bool UntreatedParts::ClearParts(off_t start, off_t size)
{
    return true;
}

//
// Update the last updated Untreated part
//
bool UntreatedParts::GetLastUpdatePart(off_t& start, off_t& size) const
{
}

//
// Replaces the last updated Untreated part.
//
// [NOTE]
// If size <= 0, delete that part
//
bool UntreatedParts::ReplaceLastUpdatePart(off_t start, off_t size)
{
}

//
// Remove the last updated Untreated part.
//
bool UntreatedParts::RemoveLastUpdatePart()
{
}

//
// Duplicate the internally untreated_list.
//
bool UntreatedParts::Duplicate(untreated_list_t& list)
{
}

void UntreatedParts::Dump()
{
}

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: expandtab sw=4 ts=4 fdm=marker
* vim<600: expandtab sw=4 ts=4
*/
