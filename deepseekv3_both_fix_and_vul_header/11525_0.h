#include <stdint.h>

typedef struct {
    int x0;
    int y0;
    int x1;
    int y1;
} Rect;

typedef struct {
    uint32_t *data;
    int width;
    int height;
    int stride;
    uint32_t color;
    Rect clip;
} Bitmap;

#define BM_SET(b, x, y, color) ((b)->data[(y) * (b)->stride + (x)] = (color))