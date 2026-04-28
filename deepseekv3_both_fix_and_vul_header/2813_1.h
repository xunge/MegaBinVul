#include <stdlib.h>

typedef struct gdIOCtx {
    void (*gd_free)(struct gdIOCtx *);
} gdIOCtx;

typedef struct gdImageStruct *gdImagePtr;

#define BGD_DECLARE(x) x

gdIOCtx *gdNewDynamicCtx(int size, void *data);
void gdImageWebpCtx(gdImagePtr im, gdIOCtx *out, int quality);
void *gdDPExtractData(gdIOCtx *out, int *size);