#include <assert.h>
#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct fz_pixmap fz_pixmap;

struct fz_pixmap {
    unsigned char *samples;
    int w;
    int h;
    int n;
    int stride;
};

void *fz_resize_array(fz_context *ctx, void *array, int count, int size);
void fz_subsample_pixmap_ARM(unsigned char *s, int w, int h, int f, int factor, int n, int fwd, int back, int back2, int fwd2, int divX, int back4, int fwd4, int fwd3, int divY, int back5, int divXY);