#include <stddef.h>

typedef struct {
    int x;
    int y;
    int width;
    int height;
} gdRect;

typedef void* gdImagePtr;
#define BGD_DECLARE(type) type

int gdImageSX(gdImagePtr im);
int gdImageSY(gdImagePtr im);
int gdColorMatch(gdImagePtr im, unsigned int color1, unsigned int color2, float threshold);
unsigned int gdImageGetPixel(gdImagePtr im, int x, int y);
gdImagePtr gdImageCrop(gdImagePtr im, const gdRect* crop);