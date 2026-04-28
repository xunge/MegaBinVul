#include <stdlib.h>
#include <assert.h>

typedef struct {
    int x;
    int y;
} BmPoint;

typedef struct {
    int x0;
    int y0;
    int x1;
    int y1;
} BmClip;

typedef struct {
    unsigned int color;
    int w;
    BmClip clip;
} Bitmap;

#define BM_GET(b, x, y) (0)
#define BM_SET(b, x, y, c) do {} while(0)