#include <stdio.h>
#include <string.h>

typedef struct gdIOCtx gdIOCtx;
typedef gdIOCtx *gdIOCtxPtr;
typedef struct dpIOCtx dpIOCtx;
typedef dpIOCtx *dpIOCtxPtr;
typedef struct dynamicPtr dynamicPtr;

struct dynamicPtr {
    void *data;
    int logicalSize;
    int pos;
};

struct dpIOCtx {
    dynamicPtr *dp;
};