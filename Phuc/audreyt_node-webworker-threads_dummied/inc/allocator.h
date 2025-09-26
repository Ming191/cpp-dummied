// allocator.h
#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstring>

void* Allocate(size_t length);

void* AllocateUninitialized(size_t length);

void Free(void* data);

#endif // ALLOCATOR_H