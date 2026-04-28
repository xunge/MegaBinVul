#include <stdint.h>

typedef struct {
    int x;
    int y;
} BmPoint;

typedef struct {
    uint32_t *data;
    int w;
    int h;
} Bitmap;

void bm_line(Bitmap *b, int x0, int y0, int x1, int y1);