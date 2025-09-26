// dummy SDL.h
#ifndef SDL_H
#define SDL_H

#include <cstdint>
#include <cstdlib>
#include <cstdio>

#include <cctype>
#include <cstring>
#include <cstdlib>

#define SDL_INIT_AUDIO 0x00000010
#define SDL_AUDIO_ALLOW_ANY_CHANGE 0x00000001
#define AUDIO_S16 0x8010
#define AUDIO_S8 0x8008
#define SDL_MIX_MAXVOLUME 128

typedef uint8_t Uint8;
typedef uint32_t Uint32;
typedef int64_t SDL_FingerID;
typedef int SDL_AudioDeviceID;

typedef void (*SDL_AudioCallback)(void* userdata, Uint8* stream, int len);

typedef struct SDL_AudioSpec {
    int freq;
    uint16_t format;
    uint8_t channels;
    uint8_t silence;
    uint16_t samples;
    uint16_t padding;
    uint32_t size;
    SDL_AudioCallback callback;
    void* userdata;
} SDL_AudioSpec;

typedef struct SDL_AudioStream SDL_AudioStream;

inline int SDL_InitSubSystem(uint32_t flags) { return 0; }
inline void SDL_QuitSubSystem(uint32_t flags) {}
inline int SDL_WasInit(uint32_t flags) { return 1; }

inline SDL_AudioDeviceID SDL_OpenAudioDevice(const char* device, int iscapture, const SDL_AudioSpec* desired, SDL_AudioSpec* obtained, int allowed_changes) {
    *obtained = *desired;
    obtained->silence = 0;
    return 1;
}

inline void SDL_CloseAudioDevice(SDL_AudioDeviceID dev) {}
inline void SDL_PauseAudioDevice(SDL_AudioDeviceID dev, int pause_on) {}

inline SDL_AudioStream* SDL_NewAudioStream(uint16_t, int, int, uint16_t, int, int) { return (SDL_AudioStream*)1; }
inline void SDL_FreeAudioStream(SDL_AudioStream* stream) {}
inline int SDL_AudioStreamPut(SDL_AudioStream* stream, const void* buf, int len) { return 0; }
inline int SDL_AudioStreamGet(SDL_AudioStream* stream, void* buf, int len) { return len; }

inline void SDL_MixAudioFormat(Uint8* dst, const Uint8* src, uint16_t, uint32_t len, int) {
    for (uint32_t i = 0; i < len; ++i) dst[i] = src[i];
}

#define SDL_MOUSEMOTION         0x400
#define SDL_MOUSEBUTTONDOWN     0x401
#define SDL_MOUSEBUTTONUP       0x402
#define SDL_MOUSEWHEEL          0x403
#define SDL_FINGERDOWN          0x700
#define SDL_FINGERMOTION        0x701
#define SDL_FINGERUP            0x702
#define SDL_KEYDOWN             0x300
#define SDL_KEYUP               0x301
#define SDL_WINDOWEVENT         0x200
#define SDL_QUIT                0x100

#define SDL_WINDOWEVENT_EXPOSED       0
#define SDL_WINDOWEVENT_SIZE_CHANGED  1
#define SDL_WINDOWEVENT_FOCUS_GAINED  2
#define SDL_WINDOWEVENT_FOCUS_LOST    3

#define SDL_PRESSED 1
#define SDL_RELEASED 0
#define SDL_DISABLE 0
#define SDL_ENABLE 1

#define SDL_NUM_SCANCODES 512
#define SDL_SCANCODE_RCTRL 228
#define SDL_SCANCODE_LCTRL 224

#define SDL_WINDOW_OPENGL 1
#define SDL_WINDOW_ALLOW_HIGHDPI 2
#define SDL_WINDOW_FULLSCREEN 4
#define SDL_INIT_VIDEO 1
#define SDL_PIXELFORMAT_RGB888 1
#define SDL_TEXTUREACCESS_STREAMING 1
#define SDL_HINT_RENDER_DRIVER "SDL_HINT_RENDER_DRIVER"
#define SDL_WINDOWPOS_UNDEFINED 0x1FFF0000
#define SDL_BITSPERPIXEL(X) 32

struct SDL_Window {};
struct SDL_Renderer {};
struct SDL_Texture {};

typedef struct {
    uint8_t r, g, b, a;
} SDL_Color;

typedef struct SDL_Palette {
    int ncolors;
    SDL_Color* colors;
} SDL_Palette;

typedef struct SDL_PixelFormat {
    SDL_Palette* palette;
} SDL_PixelFormat;

typedef struct SDL_Surface {
    void* pixels;
    int pitch;
    SDL_PixelFormat* format;
} SDL_Surface;

typedef struct {
    int x, y, w, h;
} SDL_Rect;

typedef struct {
    Uint32 type;
    Uint32 timestamp;
    SDL_FingerID fingerId;
    float x, y, dx, dy, pressure;
    uint32_t windowID;
} SDL_TouchFingerEvent;

typedef struct SDL_KeyboardEvent {
    Uint32 type;
    Uint32 timestamp;
    Uint32 windowID;
    Uint8 state;
    Uint8 repeat;
    Uint8 padding2;
    Uint8 padding3;
    struct {
        int scancode;
        int sym;
        int mod;
        Uint32 unused;
    } keysym;
} SDL_KeyboardEvent;

typedef struct SDL_WindowEvent {
    Uint32 type;
    Uint32 timestamp;
    Uint32 windowID;
    Uint8 event;
    Uint8 padding1;
    Uint8 padding2;
    Uint8 padding3;
    int data1;
    int data2;
} SDL_WindowEvent;

typedef struct SDL_MouseWheelEvent {
    Uint32 type;
    Uint32 timestamp;
    Uint32 windowID;
    int x;
    int y;
    Uint32 direction;
} SDL_MouseWheelEvent;

typedef union SDL_Event {
    Uint32 type;
    SDL_KeyboardEvent key;
    SDL_WindowEvent window;
    SDL_TouchFingerEvent tfinger;
    SDL_MouseWheelEvent wheel; // 👈 Thêm dòng này
} SDL_Event;


static inline Uint32 SDL_GetTicks(void) {
    static Uint32 t = 0;
    return (t += 16);
}

static inline void SDL_Delay(Uint32) {}
static inline int SDL_ShowCursor(int toggle) { return toggle; }
static inline int SDL_PollEvent(SDL_Event* event) { return 0; }
static inline int SDL_Init(uint32_t flags) { return 0; }
static inline void SDL_Quit(void) {}
static inline void SDL_StartTextInput(void) {}
static inline void SDL_StopTextInput(void) {}
static inline void SDL_SetHint(const char*, const char*) {}

inline SDL_Window* SDL_CreateWindow(const char*, int, int, int, int, unsigned int) { return new SDL_Window(); }
inline void SDL_DestroyWindow(SDL_Window* window) { delete window; }
inline SDL_Renderer* SDL_CreateRenderer(SDL_Window*, int, unsigned int) { return new SDL_Renderer(); }
inline int SDL_RenderSetLogicalSize(SDL_Renderer*, int, int) { return 0; }
inline void SDL_DestroyRenderer(SDL_Renderer* renderer) { delete renderer; }
inline SDL_Texture* SDL_CreateTexture(SDL_Renderer*, unsigned int, int, int, int) { return new SDL_Texture(); }
inline void SDL_DestroyTexture(SDL_Texture* texture) { delete texture; }
inline int SDL_QueryTexture(SDL_Texture*, unsigned int* format, void*, void*, void*) { *format = SDL_PIXELFORMAT_RGB888; return 0; }

inline SDL_Surface* SDL_CreateRGBSurface(int, int, int, int, int, int, int, int) {
    auto surf = new SDL_Surface();
    surf->pixels = new char[640 * 480];
    surf->pitch = 640;
    surf->format = new SDL_PixelFormat();
    surf->format->palette = new SDL_Palette();
    surf->format->palette->colors = new SDL_Color[256];
    return surf;
}

inline SDL_Surface* SDL_CreateRGBSurfaceWithFormat(int, int, int, int, unsigned int) {
    return SDL_CreateRGBSurface(0, 640, 480, 8, 0, 0, 0, 0);
}

inline void SDL_FreeSurface(SDL_Surface* surf) {
    delete[] static_cast<char*>(surf->pixels);
    delete[] surf->format->palette->colors;
    delete surf->format->palette;
    delete surf->format;
    delete surf;
}

inline int SDL_SetPaletteColors(SDL_Palette* palette, SDL_Color* colors, int start, int count) {
    for (int i = 0; i < count; ++i) palette->colors[start + i] = colors[i];
    return 0;
}

inline int SDL_BlitSurface(SDL_Surface*, SDL_Rect*, SDL_Surface*, SDL_Rect*) { return 0; }
inline void SDL_UpdateTexture(SDL_Texture*, SDL_Rect*, void* pixels, int pitch) {}
inline void SDL_RenderClear(SDL_Renderer*) {}
inline void SDL_RenderCopy(SDL_Renderer*, SDL_Texture*, SDL_Rect*, SDL_Rect*) {}
inline void SDL_RenderPresent(SDL_Renderer*) {}

inline int SDL_LockSurface(SDL_Surface* surface) {
    return 0;
}

inline void SDL_UnlockSurface(SDL_Surface* surface) {
}

typedef int SDL_bool;
#define SDL_TRUE 1
#define SDL_FALSE 0

typedef int SDL_TimerID;
typedef Uint32 (*SDL_TimerCallback)(Uint32 interval, void* param);

inline SDL_TimerID SDL_AddTimer(Uint32 interval, SDL_TimerCallback callback, void* param) {
    return 1;
}

inline SDL_bool SDL_RemoveTimer(SDL_TimerID id) {
    return SDL_TRUE;
}



#define SDL_SCANCODE_LALT 226
#define SDL_SCANCODE_RALT 230

#define SDL_SCANCODE_KP_DECIMAL 220
#define SDL_SCANCODE_PRIOR      75  // Page Up
#define SDL_SCANCODE_NEXT       78  // Page Down (nếu có)
#define SDL_SCANCODE_HOME       74
#define SDL_SCANCODE_END        77
#define SDL_SCANCODE_INSERT     73

#define SDL_SCANCODE_A 4
#define SDL_SCANCODE_B 5
#define SDL_SCANCODE_C 6
#define SDL_SCANCODE_D 7
#define SDL_SCANCODE_E 8
#define SDL_SCANCODE_F 9
#define SDL_SCANCODE_G 10
#define SDL_SCANCODE_H 11
#define SDL_SCANCODE_I 12
#define SDL_SCANCODE_J 13
#define SDL_SCANCODE_K 14
#define SDL_SCANCODE_L 15
#define SDL_SCANCODE_M 16
#define SDL_SCANCODE_N 17
#define SDL_SCANCODE_O 18
#define SDL_SCANCODE_P 19
#define SDL_SCANCODE_Q 20
#define SDL_SCANCODE_R 21
#define SDL_SCANCODE_S 22
#define SDL_SCANCODE_T 23
#define SDL_SCANCODE_U 24
#define SDL_SCANCODE_V 25
#define SDL_SCANCODE_W 26
#define SDL_SCANCODE_X 27
#define SDL_SCANCODE_Y 28
#define SDL_SCANCODE_Z 29

// Numbers
#define SDL_SCANCODE_1 30
#define SDL_SCANCODE_2 31
#define SDL_SCANCODE_3 32
#define SDL_SCANCODE_4 33
#define SDL_SCANCODE_5 34
#define SDL_SCANCODE_6 35
#define SDL_SCANCODE_7 36
#define SDL_SCANCODE_8 37
#define SDL_SCANCODE_9 38
#define SDL_SCANCODE_0 39

// Symbols and control keys
#define SDL_SCANCODE_RETURN 40
#define SDL_SCANCODE_ESCAPE 41
#define SDL_SCANCODE_BACKSPACE 42
#define SDL_SCANCODE_TAB 43
#define SDL_SCANCODE_SPACE 44
#define SDL_SCANCODE_MINUS 45
#define SDL_SCANCODE_EQUALS 46
#define SDL_SCANCODE_LEFTBRACKET 47
#define SDL_SCANCODE_RIGHTBRACKET 48
#define SDL_SCANCODE_BACKSLASH 49
#define SDL_SCANCODE_NONUS_HASH 50
#define SDL_SCANCODE_SEMICOLON 51
#define SDL_SCANCODE_APOSTROPHE 52
#define SDL_SCANCODE_GRAVE 53
#define SDL_SCANCODE_COMMA 54
#define SDL_SCANCODE_PERIOD 55
#define SDL_SCANCODE_SLASH 56
#define SDL_SCANCODE_CAPSLOCK 57

// Function keys
#define SDL_SCANCODE_F1 58
#define SDL_SCANCODE_F2 59
#define SDL_SCANCODE_F3 60
#define SDL_SCANCODE_F4 61
#define SDL_SCANCODE_F5 62
#define SDL_SCANCODE_F6 63
#define SDL_SCANCODE_F7 64
#define SDL_SCANCODE_F8 65
#define SDL_SCANCODE_F9 66
#define SDL_SCANCODE_F10 67
#define SDL_SCANCODE_F11 68
#define SDL_SCANCODE_F12 69
#define SDL_SCANCODE_F13 104
#define SDL_SCANCODE_F14 105
#define SDL_SCANCODE_F15 106

// Shift, Ctrl, Alt, GUI
#define SDL_SCANCODE_LCTRL 224
#define SDL_SCANCODE_LSHIFT 225
#define SDL_SCANCODE_LALT 226
#define SDL_SCANCODE_LGUI 227
#define SDL_SCANCODE_RCTRL 228
#define SDL_SCANCODE_RSHIFT 229
#define SDL_SCANCODE_RALT 230
#define SDL_SCANCODE_RGUI 231

// Arrow and nav keys
#define SDL_SCANCODE_INSERT 73
#define SDL_SCANCODE_HOME 74
#define SDL_SCANCODE_PAGEUP 75
#define SDL_SCANCODE_DELETE 76
#define SDL_SCANCODE_END 77
#define SDL_SCANCODE_PAGEDOWN 78
#define SDL_SCANCODE_RIGHT 79
#define SDL_SCANCODE_LEFT 80
#define SDL_SCANCODE_DOWN 81
#define SDL_SCANCODE_UP 82

// Keypad
#define SDL_SCANCODE_NUMLOCKCLEAR 83
#define SDL_SCANCODE_KP_DIVIDE 84
#define SDL_SCANCODE_KP_MULTIPLY 85
#define SDL_SCANCODE_KP_MINUS 86
#define SDL_SCANCODE_KP_PLUS 87
#define SDL_SCANCODE_KP_ENTER 88
#define SDL_SCANCODE_KP_1 89
#define SDL_SCANCODE_KP_2 90
#define SDL_SCANCODE_KP_3 91
#define SDL_SCANCODE_KP_4 92
#define SDL_SCANCODE_KP_5 93
#define SDL_SCANCODE_KP_6 94
#define SDL_SCANCODE_KP_7 95
#define SDL_SCANCODE_KP_8 96
#define SDL_SCANCODE_KP_9 97
#define SDL_SCANCODE_KP_0 98
#define SDL_SCANCODE_KP_PERIOD 99
#define SDL_SCANCODE_KP_EQUALS 103
#define SDL_SCANCODE_KP_COMMA 133

// Others
#define SDL_SCANCODE_SCROLLLOCK 71
#define SDL_SCANCODE_APPLICATION 101
#define SDL_SCANCODE_STOP 120

inline int SDL_strcasecmp(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        int diff = std::tolower(*s1) - std::tolower(*s2);
        if (diff != 0) return diff;
        s1++;
        s2++;
    }
    return std::tolower(*s1) - std::tolower(*s2);
}

// Case-insensitive string compare (n chars)
inline int SDL_strncasecmp(const char* s1, const char* s2, size_t n) {
    while (n-- && *s1 && *s2) {
        int diff = std::tolower(*s1) - std::tolower(*s2);
        if (diff != 0) return diff;
        s1++;
        s2++;
    }
    if (n == (size_t)-1) return 0;
    return std::tolower(*s1) - std::tolower(*s2);
}

// Convert string to uppercase in place
inline char* SDL_strupr(char* str) {
    char* p = str;
    while (*p) {
        *p = std::toupper(*p);
        p++;
    }
    return str;
}

// Convert string to lowercase in place
inline char* SDL_strlwr(char* str) {
    char* p = str;
    while (*p) {
        *p = std::tolower(*p);
        p++;
    }
    return str;
}

// Integer to string conversion
inline char* SDL_itoa(int value, char* buffer, int radix) {
    if (radix == 10) {
        std::sprintf(buffer, "%d", value);
    } else if (radix == 16) {
        std::sprintf(buffer, "%x", value);
    } else if (radix == 8) {
        std::sprintf(buffer, "%o", value);
    } else {
        buffer[0] = '\0'; // Unsupported radix
    }
    return buffer;
}

inline char* SDL_strdup(const char* string) {
    if (!string) return nullptr;
    size_t len = strlen(string);
    char* copy = static_cast<char*>(malloc(len + 1));
    if (copy) {
        memcpy(copy, string, len + 1);
    }
    return copy;
}

inline int SDL_SetSurfacePalette(SDL_Surface* surface, SDL_Color* palette) {
    if (surface && surface->format && palette) {
        //surface->format->palette = palette;
        return 0;
    }
    return -1;
}

#define SDL_INIT_EVENTS 0x00004000
#define SDL_TEXTINPUT 0x303

#define SDL_BUTTON(X) (1 << ((X) - 1))
#define SDL_BUTTON_LEFT   1
#define SDL_BUTTON_RIGHT  3

inline void SDL_PumpEvents() {
    // Không làm gì
}

inline void SDL_FlushEvents(Uint32 minType, Uint32 maxType) {
    // Không làm gì
}

inline int SDL_SetRelativeMouseMode(SDL_bool enabled) {
    // giả lập luôn thành công
    (void)enabled;
    return 0;
}

inline Uint32 SDL_GetRelativeMouseState(int* x, int* y) {
    if (x) *x = 0;
    if (y) *y = 0;
    return 0; // không có nút nào được nhấn
}

#endif // SDL_H