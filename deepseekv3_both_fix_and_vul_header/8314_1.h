#include <stdio.h>
#include <stdlib.h>

typedef struct gdIOCtx gdIOCtx;

#define BGD_DECLARE(x) x

#define TGA_BPP_24 24
#define TGA_BPP_32 32

typedef struct {
    unsigned char *bitmap;
    char *ident;
    int width;
    int height;
    int bits;
    int alphabits;
    int flipv;
    int fliph;
} oTga;

struct gdImage {
    int** tpixels;
    int sx;
    int sy;
};
typedef struct gdImage* gdImagePtr;

extern int read_header_tga(gdIOCtx* ctx, oTga* tga);
extern int read_image_tga(gdIOCtx* ctx, oTga* tga);
extern void free_tga(oTga* tga);
extern void* gdMalloc(size_t size);
extern int gdAlphaMax;
extern void gdImageAlphaBlending(gdImagePtr im, int blending);
extern void gdImageSaveAlpha(gdImagePtr im, int saveArg);
extern void gdImageFlipBoth(gdImagePtr im);
extern void gdImageFlipVertical(gdImagePtr im);
extern void gdImageFlipHorizontal(gdImagePtr im);
extern int gdTrueColor(int r, int g, int b);
extern int gdTrueColorAlpha(int r, int g, int b, int a);
extern gdImagePtr gdImageCreateTrueColor(int sx, int sy);