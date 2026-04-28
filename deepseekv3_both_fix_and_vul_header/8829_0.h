#include <stdlib.h>

typedef struct gdImageStruct *gdImagePtr;

struct gdImageStruct {
    int sx;
    int sy;
    int colorsTotal;
    int trueColor;
    int alphaBlendingFlag;
};

#define BGD_DECLARE(x) x

int gdImageGetPixel(gdImagePtr im, int x, int y);
void gdImageSetPixel(gdImagePtr im, int x, int y, int color);