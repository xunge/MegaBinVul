#include <stdint.h>

typedef struct {
    int w;
    int h;
    unsigned int color;
} Bitmap;

unsigned int bm_get(Bitmap *bm, int x, int y);