#include <stdint.h>

typedef uint8_t uchar;

typedef struct PaletteEntry {
    uchar r;
    uchar g;
    uchar b;
} PaletteEntry;

#define WRITE_PIX(dst, clr) \
    do { \
        (dst)[0] = (clr).r; \
        (dst)[1] = (clr).g; \
        (dst)[2] = (clr).b; \
    } while(0)