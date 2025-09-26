// jslib.cc
// #include <cstdio>
// #include <cstdlib>
#include <cstring>
#include "dummy.h"
void console_log(const char* msg) {
    printf("%s\n", msg);
}

void console_error(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}

char* readFileSync(const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) {
        fprintf(stderr, "Error opening file %s\n", path);
        return nullptr;
    }
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    rewind(f);
    char* buf = (char*)malloc(size + 1);
    if (fread(buf, 1, size, f) != size) {
        fprintf(stderr, "Error reading file %s\n", path);
        free(buf);
        fclose(f);
        return nullptr;
    }
    buf[size] = '\0';
    fclose(f);
    return buf;
}