#include <stdlib.h>

typedef struct gdImageStruct {
    int saveAlphaFlag;
    int trueColor;
} *gdImagePtr;

typedef struct {
    int x, y;
    int width, height;
} gdRect;
typedef gdRect *gdRectPtr;

#define GD_TRUE 1
#define GD_FALSE 0

int gdImageSX(gdImagePtr im);
int gdImageSY(gdImagePtr im);
gdImagePtr gdImageCreateTrueColor(int sx, int sy);
void gdImageDestroy(gdImagePtr im);
void gdImageAlphaBlending(gdImagePtr im, int alphaBlendingArg);
void gdAffineTranslate(double dst[6], double tx, double ty);
void gdAffineConcat(double dst[6], double m1[6], double m2[6]);
void gdTransformAffineBoundingBox(gdRectPtr src, const double affine[6], gdRectPtr bbox);
int gdTransformAffineCopy(gdImagePtr dst, int dstX, int dstY, gdImagePtr src, gdRectPtr srcRect, const double affine[6]);
void gdImagePaletteToTrueColor(gdImagePtr src);