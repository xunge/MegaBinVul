#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define TGA_BPP_24 24
#define TGA_BPP_32 32
#define DEBUG 0
#define GD_WARNING 1

typedef struct {
    int identsize;
    int colormaptype;
    int imagetype;
    int colormapstart;
    int colormaplength;
    int colormapbits;
    int xstart;
    int ystart;
    int width;
    int height;
    int bits;
    int alphabits;
    int fliph;
    int flipv;
    char *ident;
} oTga;

typedef struct {
    int dummy;
} gdIOCtx;

int gdGetBuf(void *buf, int size, gdIOCtx *ctx);
void gd_error(const char *msg, ...);
void gd_error_ex(int level, const char *fmt, ...);
void *gdMalloc(size_t size);