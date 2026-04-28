#include <stdlib.h>

typedef struct gdIOCtx gdIOCtx;

struct gdImageStruct {
    int sx;
    int sy;
    int colorsTotal;
    int *open;
};

typedef struct gdImageStruct *gdImagePtr;

void php_gd_error(const char *msg);
void *gdCalloc(size_t num, size_t size);
void gdFree(void *ptr);
void gdPutBuf(const void *buf, int size, gdIOCtx *ctx);
int mapQualityToVP8QP(int quality);
void gd_RGBAToYUV420(gdImagePtr im, unsigned char *Y, unsigned char *U, unsigned char *V);

enum {
    webp_success
};

int WebPEncode(const unsigned char *Y, const unsigned char *U, const unsigned char *V,
               int width, int height, int Y_stride, int UV_width, int UV_height, int UV_stride,
               int quality, unsigned char **output, int *output_size, void *unused);