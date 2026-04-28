#include <stdio.h>

typedef struct gdIOCtx {
    void (*gd_free)(struct gdIOCtx *);
} gdIOCtx;

typedef struct gdImageStruct *gdImagePtr;

#define BGD_DECLARE(x) x

gdIOCtx *gdNewFileCtx(FILE *);
void gdImageWebpCtx(gdImagePtr, gdIOCtx *, int);