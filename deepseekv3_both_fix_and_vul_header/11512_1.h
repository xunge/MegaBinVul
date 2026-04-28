#include <assert.h>

typedef struct {
    int x0, y0, x1, y1;
} Clip;

typedef struct {
    int w, h;
    int color;
    Clip clip;
} Bitmap;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define BM_SET(b, x, y, color) /* implementation dependent */