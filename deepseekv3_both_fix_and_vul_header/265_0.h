#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_XBM_LINE_SIZE 1024

typedef struct gdImageStruct *gdImagePtr;
struct gdImageStruct {
    int sx;
    int sy;
};

gdImagePtr gdImageCreate(int width, int height);
int gdImageColorAllocate(gdImagePtr im, int r, int g, int b);
void gdImageSetPixel(gdImagePtr im, int x, int y, int color);
void gdImageDestroy(gdImagePtr im);