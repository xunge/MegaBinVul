#include <stdlib.h>

typedef struct {
    int x0, y0, x1, y1;
} ClipRect;

typedef struct {
    int width;
    int height;
    unsigned char *data;
    ClipRect clip;
    unsigned int color;
} Bitmap;

#define BM_SET(b, x, y, c) \
    do { \
        if((x) >= 0 && (x) < (b)->width && (y) >= 0 && (y) < (b)->height) \
            (b)->data[(y) * (b)->width + (x)] = (c); \
    } while(0)