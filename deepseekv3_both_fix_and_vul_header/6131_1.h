#include <stdio.h>
#include <stddef.h>

typedef struct gdIOCtx gdIOCtx;

typedef struct {
    unsigned char identsize;
    unsigned char colormaptype;
    unsigned char imagetype;
    unsigned short colormapstart;
    unsigned short colormaplength;
    unsigned char colormapbits;
    unsigned short xstart;
    unsigned short ystart;
    unsigned short width;
    unsigned short height;
    unsigned char bits;
    unsigned char alphabits;
    unsigned char fliph;
    unsigned char flipv;
    char *ident;
} oTga;

#define TGA_BPP_24 24
#define TGA_BPP_32 32
#define DEBUG 0
#define GD_WARNING 1

extern int gdGetBuf(void *buf, int size, gdIOCtx *ctx);
extern void *gdMalloc(size_t size);
extern void gd_error(const char *msg);
extern void gd_error_ex(int level, const char *fmt, ...);