#include <stdlib.h>
#include <assert.h>

#define MAX_POLY_CORNERS 64

typedef struct {
    int x, y;
} BmPoint;

typedef struct {
    int x0, y0, x1, y1;
} BmRect;

typedef struct {
    int w, h;
    BmRect clip;
} Bitmap;

unsigned int bm_get_color(Bitmap *b);
void bm_line(Bitmap *b, int x0, int y0, int x1, int y1);
void BM_SET(Bitmap *b, int x, int y, unsigned int c);