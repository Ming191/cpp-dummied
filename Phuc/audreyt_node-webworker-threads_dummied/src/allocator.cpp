#include "allocator.h"

// Stub malloc
void* malloc(size_t size) {
    // Bạn có thể trả về nullptr hoặc cấp phát giả lập nếu cần
    return nullptr;
}

void* Allocate(size_t length) {
    void* data = malloc(length);
    if (data) memset(data, 0, length);
    return data;
}

void* AllocateUninitialized(size_t length) {
    return malloc(length);
}

void Free(void* data) {
    // free(data);
}