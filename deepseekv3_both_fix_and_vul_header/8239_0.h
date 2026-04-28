#include <stdlib.h>

typedef struct gdImageStruct *gdImagePtr;
struct gdImageStruct {
    int trueColor;
    int transparent;
};

#define gdMaxColors 256

int gdImageGetPixel(gdImagePtr im, int x, int y);
int gdImageGetTrueColorPixel(gdImagePtr im, int x, int y);
int gdImageGetTransparent(gdImagePtr im);
int gdImageColorResolveAlpha(gdImagePtr im, int r, int g, int b, int a);
void gdImageSetPixel(gdImagePtr im, int x, int y, int color);
int gdImageRed(gdImagePtr im, int color);
int gdImageGreen(gdImagePtr im, int color);
int gdImageBlue(gdImagePtr im, int color);
int gdImageAlpha(gdImagePtr im, int color);

#define gdTrueColorGetRed(c) (((c) >> 16) & 0xFF)
#define gdTrueColorGetGreen(c) (((c) >> 8) & 0xFF)
#define gdTrueColorGetBlue(c) ((c) & 0xFF)
#define gdTrueColorGetAlpha(c) (((c) >> 24) & 0x7F)

void *gdMalloc(size_t size);
void gdFree(void *ptr);

static int overflow2(int a, int b);