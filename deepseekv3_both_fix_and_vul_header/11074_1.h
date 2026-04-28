#include <stddef.h>

#define NGIFLIB_MODE_INDEXED 0x01

typedef unsigned int u32;

struct ngiflib_gif {
    int width;
    int height;
    union {
        unsigned char *p8;
        u32 *p32;
    } frbuff;
    unsigned char *palette;
    unsigned char backgroundindex;
    unsigned int mode;
    int ncolors;
};

u32 GifIndexToTrueColor(unsigned char *palette, unsigned char index);
void ngiflib_memset(void *ptr, int value, size_t num);