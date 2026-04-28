#include <stdio.h>
#include <stdlib.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define NGIFLIB_MODE_INDEXED 1

struct ngiflib_rgb {
    u8 r;
    u8 g;
    u8 b;
};

struct ngiflib_img;
struct ngiflib_decode_context;

struct ngiflib_parent {
    u16 width;
    u16 height;
    FILE *log;
    u8 mode;
    u8 imgbits;
    struct ngiflib_rgb *palette;
    union {
        u8 *p8;
        u32 *p32;
    } frbuff;
    void (*palette_cb)(void*, struct ngiflib_rgb*, int);
};

struct ngiflib_img {
    u16 posX;
    u16 posY;
    u16 width;
    u16 height;
    u8 interlaced;
    u8 sort_flag;
    u8 localpalbits;
    u8 imgbits;
    u16 ncolors;
    struct ngiflib_rgb *palette;
    struct ngiflib_parent *parent;
};

struct ngiflib_decode_context {
    u16 Xtogo;
    u16 curY;
    u8 pass;
    u16 nbbit;
    u16 max;
    u16 restbits;
    u16 restbyte;
    u16 lbyte;
    union {
        u8 *p8;
        u32 *p32;
    } frbuff_p;
    union {
        u8 *p8;
        u32 *p32;
    } line_p;
};

u16 GetWord(struct ngiflib_parent *parent);
u8 GetByte(struct ngiflib_parent *parent);
u16 GetGifWord(struct ngiflib_img *i, struct ngiflib_decode_context *context);
void WritePixel(struct ngiflib_img *i, struct ngiflib_decode_context *context, u8 pixel);
void WritePixels(struct ngiflib_img *i, struct ngiflib_decode_context *context, u8 *pixels, int count);
void *ngiflib_malloc(size_t size);