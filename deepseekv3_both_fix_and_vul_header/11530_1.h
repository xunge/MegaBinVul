#include <assert.h>

typedef struct {
    int x0;
    int y0;
    int x1;
    int y1;
} ClipRect;

typedef struct {
    int w;
    int h;
    int color;
    ClipRect clip;
    unsigned char *data;
} Bitmap;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define BM_SET(b, x, y, color) ((b)->data[(y) * (b)->w + (x)] = (color))