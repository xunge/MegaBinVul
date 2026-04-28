#include <stdlib.h>
#include <stdio.h>

typedef unsigned char Guchar;
typedef unsigned char GBool;
#define gTrue 1
#define gFalse 0

typedef double GfxGray;
typedef double SplashCoord;

typedef struct {
    double r, g, b;
} GfxRGB;

typedef struct {
    double c, m, y, k;
} GfxCMYK;

typedef enum {
    splashModeMono1,
    splashModeMono8,
    splashModeRGB8,
    splashModeBGR8,
    splashModeXBGR8,
    splashModeCMYK8
} SplashColorMode;

typedef unsigned char *SplashColorPtr;
typedef void *SplashImageSource;

typedef struct SplashOutImageData {
    struct ImageStream *imgStr;
    struct GfxImageColorMap *colorMap;
    int *maskColors;
    SplashColorMode colorMode;
    int width;
    int height;
    int y;
    SplashColorPtr lookup;
} SplashOutImageData;

typedef struct GfxState {
    double* getCTM();
} GfxState;

typedef struct Object Object;

typedef struct Stream {
    void close();
} Stream;

typedef struct GfxImageColorMap {
    int getNumPixelComps();
    int getBits();
    void getGray(Guchar* pix, GfxGray* gray);
    void getRGB(Guchar* pix, GfxRGB* rgb);
    void getCMYK(Guchar* pix, GfxCMYK* cmyk);
} GfxImageColorMap;

typedef struct ImageStream {
    ImageStream(Stream* str, int width, int comps, int bits);
    void reset();
    void getLine();
} ImageStream;

typedef struct Splash {
    void drawImage(SplashImageSource src, SplashOutImageData* imgData, SplashColorMode srcMode, GBool maskColors, int width, int height, SplashCoord* mat);
} Splash;

typedef struct SplashOutputDev {
    void drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, int *maskColors, GBool inlineImg);
} SplashOutputDev;

extern SplashImageSource imageSrc;
extern SplashImageSource alphaImageSrc;
extern Splash *splash;
extern SplashColorMode colorMode;

void *gmalloc(size_t size);
void *gmallocn(int n, int size);
void gfree(void *p);
unsigned char colToByte(double color);