#include <stdlib.h>

typedef struct gdImageStruct *gdImagePtr;
struct gdImageStruct {
    int trueColor;
    int interpolation_id;
};

void gdImagePaletteToTrueColor(gdImagePtr im);
gdImagePtr gdImageCreateTrueColor(int sx, int sy);
void gdImageSetInterpolationMethod(gdImagePtr im, int interpolation_id);
void _gdScaleHoriz(gdImagePtr src, unsigned int src_width, unsigned int src_height, gdImagePtr dst, unsigned int new_width, unsigned int new_height);
void _gdScaleVert(gdImagePtr src, unsigned int src_width, unsigned int src_height, gdImagePtr dst, unsigned int new_width, unsigned int new_height);
void gdFree(void *ptr);