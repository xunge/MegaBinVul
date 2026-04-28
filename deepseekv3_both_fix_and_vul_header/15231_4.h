#include <stdlib.h>
#include <stdio.h>

typedef unsigned char Guchar;
typedef unsigned char *SplashColorPtr;
typedef unsigned char SplashColor[4];
typedef double SplashCoord;

typedef enum {
    splashModeMono1,
    splashModeMono8,
    splashModeRGB8,
    splashModeBGR8,
    splashModeXBGR8,
    splashModeCMYK8
} SplashColorMode;

typedef struct {
    struct ImageStream *imgStr;
    struct GfxImageColorMap *colorMap;
    void *maskColors;
    SplashColorMode colorMode;
    int width;
    int height;
    int y;
    SplashColorPtr lookup;
} SplashOutImageData;

typedef struct SplashBitmap {
    SplashBitmap(int width, int height, int planes, SplashColorMode mode, int gFalse);
    int getWidth();
    int getHeight();
} SplashBitmap;

typedef struct GfxImageColorMap {
    void getGray(Guchar *pix, unsigned char *gray);
    void getRGB(Guchar *pix, struct GfxRGB *rgb);
#if SPLASH_CMYK
    void getCMYK(Guchar *pix, struct GfxCMYK *cmyk);
#endif
    int getNumPixelComps();
    int getBits();
} GfxImageColorMap;

typedef struct GfxState {
    double *getCTM();
} GfxState;

typedef struct Stream {
    void close();
} Stream;

typedef struct Object {} Object;

typedef struct Splash {
    Splash(SplashBitmap *bitmap, int vectorAntialias);
    void setSoftMask(SplashBitmap *);
    void clear(SplashColor);
    void drawImage(void *, SplashOutImageData *, SplashColorMode, int, int, int, SplashCoord *);
} Splash;

typedef struct ImageStream {
    ImageStream(Stream *str, int width, int numComps, int bits);
    void reset();
} ImageStream;

typedef struct GfxRGB {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} GfxRGB;

typedef unsigned char GfxGray;

#if SPLASH_CMYK
typedef struct GfxCMYK {
    unsigned char c;
    unsigned char m;
    unsigned char y;
    unsigned char k;
} GfxCMYK;
#endif

struct SplashOutputDev {
    void drawSoftMaskedImage(GfxState *state, Object *ref,
                           Stream *str, int width, int height,
                           GfxImageColorMap *colorMap,
                           Stream *maskStr,
                           int maskWidth, int maskHeight,
                           GfxImageColorMap *maskColorMap);
};

extern int vectorAntialias;
extern Splash *splash;
extern SplashBitmap *bitmap;
extern SplashColorMode colorMode;
extern void *imageSrc;
extern int gFalse;

#define gmalloc malloc
#define gfree free
#define gmallocn calloc

static inline unsigned char colToByte(unsigned char gray) {
    return gray;
}