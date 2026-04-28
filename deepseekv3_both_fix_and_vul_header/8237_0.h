#include <stddef.h>

typedef struct gdImageStruct *gdImagePtr;

struct gdImageStruct {
    int transparent;
    int trueColor;
    unsigned char **pixels;
    int sx;
    int sy;
    int colorsTotal;
    int red[256];
    int green[256];
    int blue[256];
    int alpha[256];
    int open[256];
};

int gdImageGetPixel(gdImagePtr im, int x, int y);
int gdImageGetTransparent(gdImagePtr im);
int gdImageRed(gdImagePtr im, int color);
int gdImageGreen(gdImagePtr im, int color);
int gdImageBlue(gdImagePtr im, int color);
int gdImageColorResolve(gdImagePtr im, int r, int g, int b);
void gdImageSetPixel(gdImagePtr im, int x, int y, int color);