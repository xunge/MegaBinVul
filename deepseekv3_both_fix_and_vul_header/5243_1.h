#include <string.h>
#include <stddef.h>

#define unlikely(x) __builtin_expect(!!(x), 0)

typedef unsigned char SplashColor;
typedef SplashColor *SplashColorPtr;

typedef enum {
    splashModeMono1,
    splashModeMono8,
    splashModeRGB8,
    splashModeBGR8,
    splashModeXBGR8,
    splashModeCMYK8,
    splashModeDeviceN8
} SplashMode;

typedef enum {
    splashOk,
    splashErrModeMismatch,
    splashErrZeroImage
} SplashError;

class SplashBitmap {
public:
    SplashMode mode;
    unsigned char *data;
    unsigned char *alpha;
    int rowSize;
    int width;
    int getWidth();
    int getHeight();
};

class Splash {
public:
    SplashBitmap *bitmap;
    SplashError blitTransparent(SplashBitmap *src, int xSrc, int ySrc, int xDest, int yDest, int w, int h);
};