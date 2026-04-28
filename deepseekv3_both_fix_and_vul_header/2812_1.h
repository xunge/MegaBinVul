#include <stdlib.h>

#define BGD_DECLARE(ret) ret

typedef struct gdIOCtx gdIOCtx;
typedef struct gdImageStruct *gdImagePtr;

struct gdIOCtx {
    void (*gd_free)(gdIOCtx *);
};

extern gdIOCtx *gdNewDynamicCtx(int, void *);
extern void gdImageWebpCtx(gdImagePtr, gdIOCtx *, int);
extern void *gdDPExtractData(gdIOCtx *, int *);