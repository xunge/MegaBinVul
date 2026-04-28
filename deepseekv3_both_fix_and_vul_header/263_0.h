#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_XBM_LINE_SIZE 1024

typedef struct gdImageStruct *gdImagePtr;

struct gdImageStruct {
    int sx;
    int sy;
    int colorsTotal;
    int transparent;
    int *pixels;
    int *polyInts;
    int polyAllocated;
    struct gdImageStruct *brush;
    struct gdImageStruct *tile;
    int brushColorMap[255];
    int tileColorMap[255];
    int styleLength;
    int stylePos;
    int *style;
    int interlace;
};

gdImagePtr gdImageCreate(int sx, int sy);
int gdImageColorAllocate(gdImagePtr im, int r, int g, int b);
void gdImageSetPixel(gdImagePtr im, int x, int y, int color);
void gdImageDestroy(gdImagePtr im);
void gd_error(const char *msg);