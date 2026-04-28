#include <stdint.h>

typedef struct {
    int x0, y0, x1, y1;
} ClipRect;

typedef struct {
    int w, h;
    uint32_t *data;
    uint32_t color;
    ClipRect clip;
} Bitmap;

#define BM_SET(b, x, y, c) ((b)->data[(y) * (b)->w + (x)] = (c))

void bm_line(Bitmap *b, int x0, int y0, int x1, int y1);