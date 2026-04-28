#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
void gd_error(const char *msg);

#define BGD_DECLARE(x) x