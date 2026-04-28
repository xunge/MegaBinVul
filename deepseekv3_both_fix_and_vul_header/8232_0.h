#include <stdio.h>
#include <stdarg.h>

typedef struct gdIOCtx {
    int (*putBuf)(struct gdIOCtx *ctx, const void *buf, int len);
} gdIOCtx;