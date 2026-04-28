#include <stdio.h>

#define BGD_DECLARE(ret) ret

typedef struct gdIOCtx {
    void (*gd_free)(struct gdIOCtx *);
} gdIOCtx;

typedef struct gdImage {
    // 基本图像结构定义
} gdImage;

typedef gdImage *gdImagePtr;

gdIOCtx *gdNewFileCtx(FILE *);
void gdImageWebpCtx(gdImagePtr, gdIOCtx *, int);