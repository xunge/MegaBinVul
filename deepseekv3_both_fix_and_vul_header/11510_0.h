#include <stdint.h>

typedef struct {
    int x0, y0, x1, y1;
} ClipRect;

typedef struct {
    uint8_t *data;
    int width;
    int height;
    int stride;
    uint32_t color;
    ClipRect clip;
} Bitmap;

#define BM_SET(b, x, y, c) ((b)->data[(y) * (b)->stride + (x)] = (c))