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

struct ngiflib_frbuff {
    union {
        u8 *p8;
        u32 *p32;
    };
};

struct ngiflib_img;
struct ngiflib_gif;

struct ngiflib_gif {
    u16 width;
    u16 height;
    u8 mode;
    u8 imgbits;
    FILE *log;
    struct ngiflib_frbuff frbuff;
    struct ngiflib_rgb *palette;
    void (*palette_cb)(struct ngiflib_gif*, struct ngiflib_rgb*, int);
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
    struct ngiflib_gif *parent;
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

u16 GetWord(struct ngiflib_gif *parent);
u8 GetByte(struct ngiflib_gif *parent);
u16 GetGifWord(struct ngiflib_img *i, struct ngiflib_decode_context *context);
void WritePixel(struct ngiflib_img *i, struct ngiflib_decode_context *context, u8 pixel);
void WritePixels(struct ngiflib_img *i, struct ngiflib_decode_context *context, u8 *pixels, long count);
void *ngiflib_malloc(size_t size);