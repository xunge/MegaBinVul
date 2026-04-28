#include <math.h>

typedef struct {
    int w, h;
    unsigned char *data;
} Bitmap;

void bm_line(Bitmap *b, int x0, int y0, int x1, int y1);