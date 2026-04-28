#include <assert.h>
#include <stdlib.h>

typedef struct gdImageStruct *gdImagePtr;
struct gdImageStruct {
    int sx;
    int sy;
    int trueColor;
    int interpolation_id;
};

gdImagePtr gdImageClone(const gdImagePtr src);
void gdImagePaletteToTrueColor(gdImagePtr src);
gdImagePtr gdImageCreateTrueColor(int width, int height);
void gdImageSetInterpolationMethod(gdImagePtr im, int interpolation_id);
void _gdScalePass(gdImagePtr src, unsigned int src_size, gdImagePtr dst, 
                 unsigned int dst_size, unsigned int size2, int pass);
void gdFree(void *ptr);

enum {
    HORIZONTAL,
    VERTICAL
};