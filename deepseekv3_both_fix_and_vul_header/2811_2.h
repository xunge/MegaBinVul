#include <stdint.h>
#include <stdlib.h>

typedef struct gdIOCtx gdIOCtx;
typedef struct gdImageStruct {
    int **tpixels;
} *gdImagePtr;

#define BGD_DECLARE(ret) ret

int gdImageTrueColor(gdImagePtr im);
int gdImageSX(gdImagePtr im);
int gdImageSY(gdImagePtr im);
void *gdMalloc(size_t size);
void gdFree(void *ptr);
int overflow2(int a, int b);
void gd_error(const char *msg);
int gdTrueColorGetAlpha(int c);
int gdTrueColorGetRed(int c);
int gdTrueColorGetGreen(int c);
int gdTrueColorGetBlue(int c);
void gdPutBuf(const void *buf, int size, gdIOCtx *ctx);

size_t WebPEncodeRGBA(const uint8_t* rgb, int width, int height, int stride, float quality_factor, uint8_t** output);