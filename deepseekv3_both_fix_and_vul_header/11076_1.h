#include <stdint.h>

#define NGIFLIB_MODE_INDEXED 1

typedef uint8_t u8;
typedef uint32_t u32;

struct ngiflib_gif;
struct ngiflib_img;
struct ngiflib_decode_context;

struct ngiflib_gif {
    int mode;
    int height;
    int width;
    union {
        uint8_t *p8;
        uint32_t *p32;
    } frbuff;
    #ifdef NGIFLIB_ENABLE_CALLBACKS
    void (*line_cb)(struct ngiflib_gif *, void *, int);
    #endif
};

struct ngiflib_img {
    struct ngiflib_gif *parent;
    int width;
    int posX;
    int posY;
    int ncolors;
    struct {
        uint8_t transparent_color;
        int transparent_flag;
    } gce;
    uint32_t *palette;
};

struct ngiflib_decode_context {
    int Xtogo;
    int curY;
    int pass;
    union {
        uint8_t *p8;
        uint32_t *p32;
    } frbuff_p;
    #ifdef NGIFLIB_ENABLE_CALLBACKS
    union {
        uint8_t *p8;
        uint32_t *p32;
    } line_p;
    #endif
};

#ifndef NGIFLIB_INDEXED_ONLY
static uint32_t GifIndexToTrueColor(uint32_t *palette, u8 index) {
    return palette ? palette[index] : 0;
}
#endif