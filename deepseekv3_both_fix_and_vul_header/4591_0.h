#include <stdlib.h>

typedef struct gdImageStruct {
    int sx;
    int sy;
    int alphaBlendingFlag;
} *gdImagePtr;

int gdImageGetPixel(gdImagePtr im, int x, int y);
void gdImageSetPixel(gdImagePtr im, int x, int y, int color);