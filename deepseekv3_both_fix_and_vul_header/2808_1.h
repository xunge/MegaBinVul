#include <string.h>

typedef struct dynamicPtr dynamicPtr;
typedef struct dpIOCtx dpIOCtx;
typedef dpIOCtx *dpIOCtxPtr;
typedef struct gdIOCtx gdIOCtx;
typedef gdIOCtx *gdIOCtxPtr;

struct dynamicPtr {
    void *data;
    int pos;
    int realSize;
    int logicalSize;
};

struct gdIOCtx {
    int dummy;
};

struct dpIOCtx {
    struct gdIOCtx ctx;
    dynamicPtr *dp;
};