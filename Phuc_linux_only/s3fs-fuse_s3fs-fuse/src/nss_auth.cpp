/*
 * s3fs - FUSE-based file system backed by Amazon S3
 *
 * Copyright(C) 2007 Randy Rizun <rrizun@gmail.com>
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

//#include <cerrno>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <unistd.h>
//#include <syslog.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <nss.h>
//#include <pk11pub.h>
//#include <hasht.h>
//#include <prinit.h>
//#include <string>
//#include <map>

#include "s3fs_auth.h"


//-------------------------------------------------------------------
// Utility Function for version
//-------------------------------------------------------------------


//-------------------------------------------------------------------
// Utility Function for global init
//-------------------------------------------------------------------
bool s3fs_init_global_ssl()
{
}

//------------------------------------------------------------------
// Utility Function for crypt lock
//-------------------------------------------------------------------
//-------------------------------------------------------------------
// Utility Function for HMAC
//-------------------------------------------------------------------
static std::unique_ptr<unsigned char[]> s3fs_HMAC_RAW(const void* key, size_t keylen, const unsigned char* data, size_t datalen, unsigned int* digestlen, bool is_sha256)
{
}


//-------------------------------------------------------------------
// Utility Function for MD5
//-------------------------------------------------------------------



//-------------------------------------------------------------------
// Utility Function for SHA256
//-------------------------------------------------------------------



/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: expandtab sw=4 ts=4 fdm=marker
* vim<600: expandtab sw=4 ts=4
*/
