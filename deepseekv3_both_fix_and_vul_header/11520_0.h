#include <stdint.h>

typedef struct {
    int w;
    int h;
    uint8_t *data;
    uint8_t color;
} Bitmap;

#define BM_SET(b, x, y, c) ((b)->data[(y)*(b)->w + (x)] = (c))