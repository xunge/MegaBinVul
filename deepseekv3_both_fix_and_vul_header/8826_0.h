#include <string.h>

typedef struct gdIOCtx gdIOCtx;
typedef gdIOCtx *gdIOCtxPtr;

typedef struct dpIOCtx {
    struct dynamicPtr *dp;
} dpIOCtx;
typedef dpIOCtx *dpIOCtxPtr;

typedef struct dynamicPtr {
    void *data;
    int logicalSize;
    int pos;
} dynamicPtr;