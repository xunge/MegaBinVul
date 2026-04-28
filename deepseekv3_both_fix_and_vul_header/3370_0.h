#include <stdlib.h>
#include <string.h>

typedef struct gdImageStruct *gdImagePtr;
typedef struct gdRect {
    int x, y;
    int width, height;
} gdRect, *gdRectPtr;

struct gdImageStruct {
    int sx;
    int sy;
    unsigned char **pixels;
    int **tpixels;
    int transparent;
    int trueColor;
};