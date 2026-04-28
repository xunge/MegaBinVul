#include <stdint.h>

typedef struct {
    int width;
    int height;
    uint32_t *data;
} Bitmap;

void bm_line(Bitmap *b, int x0, int y0, int x1, int y1);