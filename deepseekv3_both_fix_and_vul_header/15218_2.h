#include <stdlib.h>

typedef unsigned char Guchar;
typedef unsigned char *SplashColorPtr;
typedef int GBool;

typedef enum {
    splashModeMono1,
    splashModeMono8,
    splashModeRGB8,
    splashModeBGR8,
    splashModeXBGR8,
    splashModeCMYK8
} SplashColorMode;

struct SplashBitmap {
    int width;
    int height;
    int rowSize;
    SplashColorMode mode;
    SplashColorPtr data;
    Guchar *alpha;
    
    SplashBitmap(int widthA, int heightA, int rowPad,
                SplashColorMode modeA, GBool alphaA,
                GBool topDown);
};

extern void *gmalloc(size_t size);
extern void *gmallocn(int n, int size);