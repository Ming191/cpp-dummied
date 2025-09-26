#include "sds.h"
#include <string>
#include "dummy.h"



// --- SDS ---
char* sdsnewlen(const void* init, size_t initlen) { return nullptr; }
char* sdsnew(const char* init) { return nullptr; }
sds sdsdup(const sds s) {};
void sdsfree(char* s) {}
size_t sdsavail(const char* s) { return 0; }

// --- zmalloc ---
size_t zmalloc_get_rss(void) { return 0; }