#include <stdlib.h>

#define BGD_DECLARE(x) x
#define gdMaxColors 256

typedef struct gdImageStruct {
    int sx;
    int sy;
    int trueColor;
    int colorsTotal;
    unsigned char red[gdMaxColors];
    unsigned char green[gdMaxColors];
    unsigned char blue[gdMaxColors];
    unsigned char alpha[gdMaxColors];
    unsigned char open[gdMaxColors];
    unsigned char **pixels;
    int **tpixels;
    int styleLength;
    int stylePos;
    int *style;
    int interlace;
    int alphaBlendingFlag;
    int saveAlphaFlag;
    int AA;
    int AA_color;
    int AA_dont_blend;
    int cx1;
    int cy1;
    int cx2;
    int cy2;
    int res_x;
    int res_y;
    int paletteQuantizationMethod;
    int paletteQuantizationSpeed;
    int paletteQuantizationMinQuality;
    int interpolation_id;
    void *interpolation;
    struct gdImageStruct *brush;
    struct gdImageStruct *tile;
    int brushColorMap[gdMaxColors];
    int tileColorMap[gdMaxColors];
    int polyAllocated;
    int *polyInts;
} *gdImagePtr;

gdImagePtr gdImageCreate(int sx, int sy);
gdImagePtr gdImageCreateTrueColor(int sx, int sy);
void gdImageSetStyle(gdImagePtr im, int *style, int styleLength);