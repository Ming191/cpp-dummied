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

//#include <algorithm>
//#include <cstdlib>
//#include <mutex>
//#include <vector>

#include "fdcache_pseudofd.h"

//------------------------------------------------
// Symbols
//------------------------------------------------
// [NOTE]
// The minimum pseudo fd value starts 2.
// This is to avoid mistakes for 0(stdout) and 1(stderr), which are usually used.
//
static constexpr int MIN_PSEUDOFD_NUMBER = 2;

//------------------------------------------------
// PseudoFdManager class methods
//------------------------------------------------
PseudoFdManager& PseudoFdManager::GetManager()
{
}

int PseudoFdManager::Get()
{
}

bool PseudoFdManager::Release(int fd)
{
}

//------------------------------------------------
// PseudoFdManager methods
//------------------------------------------------
int PseudoFdManager::GetUnusedMinPseudoFd() const
{

}

int PseudoFdManager::CreatePseudoFd()
{
}

bool PseudoFdManager::ReleasePseudoFd(int fd)
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
