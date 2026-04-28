#include <stdint.h>
#include <stddef.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct ngiflib_gif;
struct ngiflib_img;
struct ngiflib_decode_context;

struct ngiflib_gif {
    int mode;
    int height;
    int width;
    union {
        uint8_t* p8;
        uint32_t* p32;
    } frbuff;
    #ifdef NGIFLIB_ENABLE_CALLBACKS
    void (*line_cb)(struct ngiflib_gif*, union { uint8_t* p8; uint32_t* p32; }, int);
    #endif
};

struct ngiflib_img {
    struct ngiflib_gif* parent;
    int width;
    int posX;
    int posY;
    struct {
        int transparent_flag;
        uint8_t transparent_color;
    } gce;
    uint32_t* palette;
};

struct ngiflib_decode_context {
    int Xtogo;
    int curY;
    int pass;
    int line;
    union {
        uint8_t* p8;
        uint32_t* p32;
    } frbuff_p;
    #ifdef NGIFLIB_ENABLE_CALLBACKS
    union {
        uint8_t* p8;
        uint32_t* p32;
    } line_p;
    #endif
};

#define NGIFLIB_MODE_INDEXED 1

#ifndef NGIFLIB_INDEXED_ONLY
static uint32_t GifIndexToTrueColor(uint32_t* palette, uint8_t index);
#endif

#define ngiflib_memcpy memcpy