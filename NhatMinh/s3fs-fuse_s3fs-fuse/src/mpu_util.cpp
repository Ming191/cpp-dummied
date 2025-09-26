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

//#include <cstdio>
//#include <cstdlib>
//#include <string>

#include "s3fs.h"
#include "s3fs_logger.h"
#include "mpu_util.h"
#include "curl.h"
#include "s3fs_xml.h"
#include "s3fs_auth.h"
#include "string_util.h"
#include "s3fs_threadreqs.h"

//-------------------------------------------------------------------
// Global variables
//-------------------------------------------------------------------
utility_incomp_type utility_mode = utility_incomp_type::NO_UTILITY_MODE;

//-------------------------------------------------------------------
// Functions
//-------------------------------------------------------------------
static void print_incomp_mpu_list(const incomp_mpu_list_t& list)
{
   
}

static bool abort_incomp_mpu_list(const incomp_mpu_list_t& list, time_t abort_time)
{
}

int s3fs_utility_processing(time_t abort_time)
{
    if(utility_incomp_type::NO_UTILITY_MODE == utility_mode){
        return EXIT_FAILURE;
    }

    S3fsCurl s3fscurl;
    std::string body;
    int result = EXIT_SUCCESS;
    if(0 != s3fscurl.MultipartListRequest(body)){
        result = EXIT_FAILURE;
    }else{
    
    }

    

    return result;
}

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: expandtab sw=4 ts=4 fdm=marker
* vim<600: expandtab sw=4 ts=4
*/
