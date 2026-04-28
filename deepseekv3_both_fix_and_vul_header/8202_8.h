#include <math.h>

typedef struct gdImageStruct {
    int interpolation_id;
    int interpolation;
    int alphaBlendingFlag;
    int **tpixels;
    int sx;
    int sy;
} *gdImagePtr;

typedef struct gdPointF {
    double x, y;
} gdPointF;

typedef struct gdRect {
    int x, y, width, height;
} gdRect;
typedef gdRect *gdRectPtr;

typedef enum {
    GD_DEFAULT,
    GD_BILINEAR_FIXED,
    GD_BICUBIC_FIXED,
    GD_NEAREST_NEIGHBOUR,
    GD_BICUBIC
} gdInterpolationMethod;

#define GD_FALSE 0
#define GD_TRUE 1

int gdImageSX(gdImagePtr im);
int gdImageSY(gdImagePtr im);
void gdImageSetInterpolationMethod(gdImagePtr im, gdInterpolationMethod interpolation_id);
void gdImageClipRectangle(gdImagePtr im, gdRectPtr rect);
void gdImageGetClip(gdImagePtr im, int *x1, int *y1, int *x2, int *y2);
void gdImageSetClip(gdImagePtr im, int x1, int y1, int x2, int y2);
int gdTransformAffineBoundingBox(gdRectPtr src, const double affine[6], gdRectPtr bbox);
void gdAffineInvert(double dst[6], const double src[6]);
void gdAffineApplyToPointF(gdPointF *dst, const gdPointF *src, const double affine[6]);
int getPixelInterpolated(gdImagePtr src, double x, double y, int bg);
void gdImageSetPixel(gdImagePtr im, int x, int y, int color);

typedef gdInterpolationMethod interpolation_method;