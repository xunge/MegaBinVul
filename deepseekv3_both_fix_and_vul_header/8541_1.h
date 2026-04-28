#include <stdint.h>
#include <stddef.h>

typedef struct gdIOCtx gdIOCtx;

typedef struct {
    int width;
    int height;
    int bits;
    int imagetype;
    int *bitmap;
} oTga;

#define TGA_TYPE_RGB 2
#define TGA_TYPE_RGB_RLE 10
#define TGA_RLE_FLAG 0x80

extern void *gdMalloc(size_t size);
extern void gdFree(void *ptr);
extern int gdGetBuf(void *buf, int size, gdIOCtx *ctx);
extern void gd_error(const char *format, ...);
extern int overflow2(int a, int b);