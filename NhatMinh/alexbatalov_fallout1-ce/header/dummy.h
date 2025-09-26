#ifndef MEMORY_WRAPPERS_H
#define MEMORY_WRAPPERS_H

#include <cstdlib> // malloc, free, realloc
#include <cstring> // memcpy, strlen
#include <cstdio>
#include <cstdint>

template <typename T>
const T& my_clamp(const T& v, const T& lo, const T& hi) {
    return (v < lo) ? lo : (hi < v) ? hi : v;
}
#endif // MEMORY_WRAPPERS_H
