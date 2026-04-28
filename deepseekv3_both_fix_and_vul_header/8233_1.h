#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct gdImageStruct {
    int sx;
    int sy;
} *gdImagePtr;

typedef struct gdIOCtx {
    int (*printf)(struct gdIOCtx *, const char *, ...);
} gdIOCtx;

#define BGD_DECLARE(x) x
#define gdImageSX(im) ((im)->sx)
#define gdImageSY(im) ((im)->sy)

int gdImageGetPixel(gdImagePtr im, int x, int y);
void gdCtxPrintf(gdIOCtx *ctx, const char *format, ...);