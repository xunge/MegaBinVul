#include <stdint.h>

typedef struct {
    int x0, y0, x1, y1;
} Rect;

typedef struct {
    uint8_t *data;
    int width;
    int height;
    int stride;
    Rect clip;
    uint32_t color;
} Bitmap;

#define BM_SET(b, x, y, c) \
    do { \
        if((x) >= 0 && (x) < (b)->width && (y) >= 0 && (y) < (b)->height) { \
            uint32_t *pixel = (uint32_t*)&(b)->data[(y) * (b)->stride + (x) * sizeof(uint32_t)]; \
            *pixel = (c); \
        } \
    } while(0)