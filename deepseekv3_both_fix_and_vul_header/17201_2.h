#include <stdio.h>
#include <stdlib.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define NGIFLIB_MODE_INDEXED 0x01

struct ngiflib_rgb {
    u8 r;
    u8 g;
    u8 b;
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
    struct {
        u16 width;
        u16 height;
        FILE *log;
        u8 imgbits;
        u8 mode;
        union {
            u8 *p8;
            u32 *p32;
        } frbuff;
        struct ngiflib_rgb *palette;
    } *parent;
};

struct ngiflib_decode_context {
    u16 Xtogo;
    u16 curY;
    u8 pass;
    u8 nbbit;
    u16 max;
    u16 restbits;
    u16 restbyte;
    u16 lbyte;
    union {
        u8 *p8;
        u32 *p32;
    } line_p;
    union {
        u8 *p8;
        u32 *p32;
    } frbuff_p;
};

u16 GetWord(void *parent);
u8 GetByte(void *parent);
u16 GetGifWord(struct ngiflib_img *i, struct ngiflib_decode_context *context);
void WritePixel(struct ngiflib_img *i, struct ngiflib_decode_context *context, u8 pixel);
void WritePixels(struct ngiflib_img *i, struct ngiflib_decode_context *context, u8 *pixels, int count);
void *ngiflib_malloc(size_t size);