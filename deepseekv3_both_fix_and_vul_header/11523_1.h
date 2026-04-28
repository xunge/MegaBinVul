#include <assert.h>
#include <stdlib.h>

typedef struct {
    int x0, y0, x1, y1;
} ClipRect;

typedef struct {
    int w, h;
    int color;
    ClipRect clip;
    unsigned char *pixels;
} Bitmap;

#define BM_SET(b, x, y, c) ((b)->pixels[(y) * (b)->w + (x)] = (c))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))