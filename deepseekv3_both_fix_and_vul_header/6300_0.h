#include <stdio.h>

typedef unsigned char u8;

struct ngiflib_gif {
    int mode;
    union {
        struct {
            u8 *bytes;
        };
        struct {
            u8 *bytes;
            size_t count;
        } buffer;
        FILE *file;
    } input;
    FILE *log;
};

#define NGIFLIB_MODE_FROM_MEM 1