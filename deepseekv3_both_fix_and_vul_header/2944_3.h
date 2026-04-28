#include <stdlib.h>
#include <stdio.h>

typedef unsigned char Guchar;
typedef unsigned int Guint;

typedef void (*SplashImageMaskSource)(void *srcData, Guchar *lineBuf);

typedef struct {
    Guchar *data;
} SplashBitmap;

struct Splash {
    void scaleMaskYuXu(SplashImageMaskSource src, void *srcData,
                     int srcWidth, int srcHeight,
                     int scaledWidth, int scaledHeight,
                     SplashBitmap *dest);
};

enum {
    errInternal
};

void error(int errType, int code, const char *msg);
void *gmalloc(size_t size);
void gfree(void *ptr);