#include <stdlib.h>

#define BGD_DECLARE(x) x
#define gdMaxColors 256
#define GD_RESOLUTION 96
#define GD_BILINEAR_FIXED 0

typedef struct gdImageStruct *gdImagePtr;
typedef struct gdImageStruct {
    unsigned char **pixels;
    int *polyInts;
    int polyAllocated;
    gdImagePtr brush;
    gdImagePtr tile;
    int *style;
    int sx;
    int sy;
    int colorsTotal;
    int transparent;
    int interlace;
    int thick;
    int AA;
    int open[gdMaxColors];
    int trueColor;
    int **tpixels;
    int cx1;
    int cy1;
    int cx2;
    int cy2;
    int res_x;
    int res_y;
    void *interpolation;
    int interpolation_id;
} gdImage;

void *gdMalloc(size_t size);
void *gdCalloc(size_t nmemb, size_t size);
void gdFree(void *ptr);
int overflow2(int a, int b);