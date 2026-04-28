#include <math.h>
#include <stdlib.h>

typedef struct gdImageStruct *gdImagePtr;

struct gdImageStruct {
    int thick;
    int AA_color;
};

#define gdAntiAliased (-1)

void gdImageAALine(gdImagePtr im, int x1, int y1, int x2, int y2, int color);
void gdImageVLine(gdImagePtr im, int x, int y1, int y2, int color);
void gdImageHLine(gdImagePtr im, int y, int x1, int x2, int color);
void gdImageSetPixel(gdImagePtr im, int x, int y, int color);
int clip_1d(int *x1, int *y1, int *x2, int *y2, int max);
int gdImageSX(gdImagePtr im);
int gdImageSY(gdImagePtr im);