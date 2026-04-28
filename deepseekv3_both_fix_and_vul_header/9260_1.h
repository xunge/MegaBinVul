#include <math.h>
#include <stddef.h>

typedef struct gdImageStruct *gdImagePtr;
struct gdImageStruct {
    int trueColor;
    unsigned char *red;
    unsigned char *green;
    unsigned char *blue;
    unsigned char *alpha;
    int interpolation_id;
};

#define gdMaxColors 256
#define GD_METHOD_COUNT 3
#define GD_NEAREST_NEIGHBOUR 1
#define GD_BILINEAR_FIXED 2
#define GD_BICUBIC_FIXED 3

extern gdImagePtr gdImageRotate90(gdImagePtr src, int ignore);
extern gdImagePtr gdImageRotate180(gdImagePtr src, int ignore);
extern gdImagePtr gdImageRotate270(gdImagePtr src, int ignore);
extern gdImagePtr gdImageRotateNearestNeighbour(gdImagePtr src, float angle, int bgcolor);
extern gdImagePtr gdImageRotateBilinear(gdImagePtr src, float angle, int bgcolor);
extern gdImagePtr gdImageRotateBicubicFixed(gdImagePtr src, float angle, int bgcolor);
extern gdImagePtr gdImageRotateGeneric(gdImagePtr src, float angle, int bgcolor);
extern void gdImagePaletteToTrueColor(gdImagePtr src);
extern int gdTrueColorAlpha(int r, int g, int b, int a);