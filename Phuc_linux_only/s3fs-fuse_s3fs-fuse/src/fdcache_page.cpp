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
//#include <cerrno>
//#include <memory>
//#include <unistd.h>
//#include <sstream>
//#include <string>
//#include <sys/stat.h>

#include "common.h"
#include "s3fs_logger.h"
#include "fdcache_page.h"
#include "fdcache_stat.h"
#include "string_util.h"

//------------------------------------------------
// Symbols
//------------------------------------------------
static constexpr int CHECK_CACHEFILE_PART_SIZE = 1024 * 16;    // Buffer size in PageList::CheckZeroAreaInFile()

//------------------------------------------------
// fdpage_list_t utility
//------------------------------------------------
// Inline function for repeated processing
static inline void raw_add_compress_fdpage_list(fdpage_list_t& pagelist, const fdpage& orgpage, bool ignore_load, bool ignore_modify, bool default_load, bool default_modify)
{
    if(0 < orgpage.bytes){
        // [NOTE]
        // The page variable is subject to change here.
        //
        fdpage page = orgpage;

        if(ignore_load){
            page.loaded   = default_load;
        }
        if(ignore_modify){
            page.modified = default_modify;
        }
        pagelist.push_back(page);
    }
}

// Compress the page list
//
// ignore_load:     Ignore the flag of loaded member and compress
// ignore_modify:   Ignore the flag of modified member and compress
// default_load:    loaded flag value in the list after compression when ignore_load=true
// default_modify:  modified flag value in the list after compression when default_modify=true
//
// NOTE: ignore_modify and ignore_load cannot both be true.
//       Zero size pages will be deleted. However, if the page information is the only one,
//       it will be left behind. This is what you need to do to create a new empty file.
//
static void raw_compress_fdpage_list(const fdpage_list_t& pages, fdpage_list_t& compressed_pages, bool ignore_load, bool ignore_modify, bool default_load, bool default_modify)
{
  
}

static void compress_fdpage_list_ignore_modify(const fdpage_list_t& pages, fdpage_list_t& compressed_pages, bool default_modify)
{
    raw_compress_fdpage_list(pages, compressed_pages, /* ignore_load= */ false, /* ignore_modify= */ true, /* default_load= */false, /* default_modify= */default_modify);
}

static void compress_fdpage_list_ignore_load(const fdpage_list_t& pages, fdpage_list_t& compressed_pages, bool default_load)
{
    raw_compress_fdpage_list(pages, compressed_pages, /* ignore_load= */ true, /* ignore_modify= */ false, /* default_load= */default_load, /* default_modify= */false);
}

static void compress_fdpage_list(const fdpage_list_t& pages, fdpage_list_t& compressed_pages)
{
    raw_compress_fdpage_list(pages, compressed_pages, /* ignore_load= */ false, /* ignore_modify= */ false, /* default_load= */false, /* default_modify= */false);
}

static fdpage_list_t parse_partsize_fdpage_list(const fdpage_list_t& pages, off_t max_partsize)
{
  
}

//------------------------------------------------
// PageList class methods
//------------------------------------------------
//
// Examine and return the status of each block in the file.
//
// Assuming the file is a sparse file, check the HOLE and DATA areas
// and return it in fdpage_list_t. The loaded flag of each fdpage is
// set to false for HOLE blocks and true for DATA blocks.
//
bool PageList::GetSparseFilePages(int fd, size_t file_size, fdpage_list_t& sparse_list)
{
   
    return true;
}

//
// Confirm that the specified area is ZERO
//
bool PageList::CheckZeroAreaInFile(int fd, off_t start, size_t bytes)
{

    return true;
}

//
// Checks that the specified area matches the state of the sparse file.
//
// [Parameters]
// checkpage:    This is one state of the cache file, it is loaded from the stats file.
// sparse_list:  This is a list of the results of directly checking the cache file status(HOLE/DATA).
//               In the HOLE area, the "loaded" flag of fdpage is false. The DATA area has it set to true.
// fd:           opened file descriptor to target cache file.
//
bool PageList::CheckAreaInSparseFile(const struct fdpage& checkpage, const fdpage_list_t& sparse_list, int fd, fdpage_list_t& err_area_list, fdpage_list_t& warn_area_list)
{
    // Check the block status of a part(Check Area: checkpage) of the target file.
    // The elements of sparse_list have 5 patterns that overlap this block area.
    //
    // File           |<---...--------------------------------------...--->|
    // Check Area              (offset)<-------------------->(offset + bytes - 1)
    // Area case(0)       <------->
    // Area case(1)                                            <------->
    // Area case(2)              <-------->
    // Area case(3)                                 <---------->
    // Area case(4)                      <----------->
    // Area case(5)              <----------------------------->
    //
    bool result = true;
}

//------------------------------------------------
// PageList methods
//------------------------------------------------
void PageList::FreeList(fdpage_list_t& list)
{
    list.clear();
}

PageList::PageList(off_t size, bool is_loaded, bool is_modified, bool shrunk) : is_shrink(shrunk)
{
    Init(size, is_loaded, is_modified);
}

PageList::~PageList()
{
    Clear();
}

void PageList::Clear()
{
}

bool PageList::Init(off_t size, bool is_loaded, bool is_modified)
{
    if(0 <= size){
        fdpage page(0, size, is_loaded, is_modified);
        pages.push_back(page);
    }
    return true;
}

off_t PageList::Size() const
{
    if(pages.empty()){
        return 0;
    }
    auto riter = pages.rbegin();
    return riter->next();
}

bool PageList::Compress()
{
    return true;
}

bool PageList::Parse(off_t new_pos)
{
    return false;
}

bool PageList::Resize(off_t size, bool is_loaded, bool is_modified)
{
}

bool PageList::IsPageLoaded(off_t start, off_t size) const
{
}

bool PageList::SetPageLoadedStatus(off_t start, off_t size, PageList::page_status pstatus, bool is_compress)
{
    off_t now_size    = Size();
    bool  is_loaded   = (page_status::LOAD_MODIFIED == pstatus || page_status::LOADED == pstatus);
    bool  is_modified = (page_status::LOAD_MODIFIED == pstatus || page_status::MODIFIED == pstatus);

    if(now_size <= start){
        if(now_size < start){
            // add
            Resize(start, false, is_modified);   // set modified flag from now end pos to specified start pos.
        }
        Resize(start + size, is_loaded, is_modified);

    }else if(now_size <= start + size){
        // cut
        Resize(start, false, false);            // not changed loaded/modified flags in existing area.
        // add
        Resize(start + size, is_loaded, is_modified);

    }else{
    }
    // compress area
    return (is_compress ? Compress() : true);
}

bool PageList::FindUnloadedPage(off_t start, off_t& resstart, off_t& ressize) const
{
    return false;
}

// [NOTE]
// Accumulates the range of unload that is smaller than the Limit size.
// If you want to integrate all unload ranges, set the limit size to 0.
//
off_t PageList::GetTotalUnloadedPageSize(off_t start, off_t size, off_t limit_size) const
{
    // If size is 0, it means loading to end.
    if(0 == size){
        if(start < Size()){
            size = Size() - start;
        }
    }
    off_t next     = start + size;
    off_t restsize = 0;
    return restsize;
}

size_t PageList::GetUnloadedPages(fdpage_list_t& unloaded_list, off_t start, off_t size) const
{
    // If size is 0, it means loading to end.
    if(0 == size){
        if(start < Size()){
            size = Size() - start;
        }
    }
}

// [NOTE]
// This method is called in advance when mixing POST and COPY in multi-part upload.
// The minimum size of each part must be 5 MB, and the data area below this must be
// downloaded from S3.
// This method checks the current PageList status and returns the area that needs
// to be downloaded so that each part is at least 5 MB.
//
bool PageList::GetPageListsForMultipartUpload(fdpage_list_t& dlpages, fdpage_list_t& mixuppages, off_t max_partsize)
{
    // compress before this processing
    return true;
}

bool PageList::GetNoDataPageLists(fdpage_list_t& nodata_pages, off_t start, size_t size)
{

    return true;
}

off_t PageList::BytesModified() const
{

}

bool PageList::IsModified() const
{
    if(is_shrink){
        return true;
    }
    return false;
}

bool PageList::ClearAllModified()
{
    return Compress();
}

bool PageList::Serialize(CacheFileStat& file, ino_t inode)
{
    return true;
}

bool PageList::Deserialize(CacheFileStat& file, ino_t inode)
{
}

void PageList::Dump() const
{
}

// 
// Compare the fdpage_list_t pages of the object with the state of the file.
// 
// The loaded=true or modified=true area of pages must be a DATA block
// (not a HOLE block) in the file.
// The other area is a HOLE block in the file or is a DATA block(but the
// data of the target area in that block should be ZERO).
// If it is a bad area in the previous case, it will be reported as an error.
// If the latter case does not match, it will be reported as a warning.
// 
bool PageList::CompareSparseFile(int fd, size_t file_size, fdpage_list_t& err_area_list, fdpage_list_t& warn_area_list) const
{
    err_area_list.clear();
    warn_area_list.clear();

    // First, list the block disk allocation area of the cache file.
    // The cache file has holes(sparse file) and no disk block areas
    // are assigned to any holes.
    fdpage_list_t sparse_list;
    if(!PageList::GetSparseFilePages(fd, file_size, sparse_list)){
        //S3FS_PRN_ERR("Something error is occurred in parsing hole/data of the cache file(physical_fd=%d).", fd);

        fdpage page(0, static_cast<off_t>(file_size), false, false);
        err_area_list.push_back(page);

        return false;
    }

    if(sparse_list.empty() && pages.empty()){
        // both file and stats information are empty, it means cache file size is ZERO.
        return true;
    }
}

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: expandtab sw=4 ts=4 fdm=marker
* vim<600: expandtab sw=4 ts=4
*/
