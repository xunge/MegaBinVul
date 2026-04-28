#include <stdlib.h>

typedef struct gdImageStruct *gdImagePtr;

struct gdImageStruct {
    int thick;
};

void gdImageSetPixel(gdImagePtr im, int x, int y, int color);
void gdImageLine(gdImagePtr im, int x1, int y1, int x2, int y2, int color);