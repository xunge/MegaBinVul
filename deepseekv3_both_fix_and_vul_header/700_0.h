#include <stdint.h>

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
        u8 *p8;
        u32 *p32;
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
    struct {
        u8 transparent_color;
        int transparent_flag;
    } gce;
    void *palette;
};

struct ngiflib_decode_context {
    int Xtogo;
    int curY;
    int pass;
    union {
        u8 *p8;
        u32 *p32;
    } frbuff_p;
    #ifdef NGIFLIB_ENABLE_CALLBACKS
    union {
        u8 *p8;
        u32 *p32;
    } line_p;
    #endif
};

#define NGIFLIB_MODE_INDEXED 1
#ifndef NGIFLIB_INDEXED_ONLY
u32 GifIndexToTrueColor(void *palette, u8 index);
#endif