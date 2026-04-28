#include <stdlib.h>

#define gdMaxColors 256
#define GD_BILINEAR_FIXED 0

typedef struct gdImage {
    unsigned char **pixels;
    unsigned char **AA_opacity;
    int *polyInts;
    int polyAllocated;
    void *brush;
    void *tile;
    int *style;
    int sx;
    int sy;
    int colorsTotal;
    int transparent;
    int interlace;
    int thick;
    int AA;
    int AA_polygon;
    int open[gdMaxColors];
    unsigned char red[gdMaxColors];
    unsigned char green[gdMaxColors];
    unsigned char blue[gdMaxColors];
    int trueColor;
    int **tpixels;
    int cx1;
    int cy1;
    int cx2;
    int cy2;
    void *interpolation;
    int interpolation_id;
} gdImage;

typedef gdImage *gdImagePtr;

extern void *gdMalloc(size_t size);
extern void *gdCalloc(size_t nmemb, size_t size);
extern int overflow2(int a, int b);