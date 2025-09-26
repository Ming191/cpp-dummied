#include "winmain.h"

#include <stdlib.h>

#include <SDL.h>

#ifndef _WIN32
#include <unistd.h>
#endif

#include "main.h"
#include "gnw.h"
#include "svga.h"

#if __APPLE__ && TARGET_OS_IOS
#include "platform/ios/paths.h"
#endif

//namespace fallout {

// 0x53A290
bool GNW95_isActive = false;

#if _WIN32
// 0x53A294
HANDLE GNW95_mutex = NULL;
#endif

// 0x6B0760
char GNW95_title[256];
//}