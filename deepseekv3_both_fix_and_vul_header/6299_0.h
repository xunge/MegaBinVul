#include <stdio.h>
#include <string.h>

typedef unsigned char u8;

struct ngiflib_input_buffer {
    unsigned char *bytes;
    unsigned int count;
};

union ngiflib_input {
    FILE *file;
    struct ngiflib_input_buffer buffer;
    unsigned char *bytes;
};

struct ngiflib_gif {
    int mode;
    union ngiflib_input input;
};

#define NGIFLIB_MODE_FROM_MEM 1

static void ngiflib_memcpy(void *dest, const void *src, size_t n) {
    memcpy(dest, src, n);
}