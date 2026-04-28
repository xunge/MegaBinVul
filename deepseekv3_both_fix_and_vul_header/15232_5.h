#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char Guchar;
typedef int GBool;
typedef unsigned char SplashColor[4];
typedef unsigned char *SplashColorPtr;
typedef double SplashCoord;

typedef enum {
    splashModeMono1,
    splashModeMono8,
    splashModeRGB8,
    splashModeBGR8,
    splashModeXBGR8,
    splashModeCMYK8
} SplashColorMode;

struct ImageStream;
struct GfxImageColorMap;
struct SplashBitmap;
struct Splash;
struct SplashSolidColor;
struct GfxDeviceGrayColorSpace;

typedef struct {
    struct ImageStream* imgStr;
    struct GfxImageColorMap* colorMap;
    struct SplashBitmap* mask;
    SplashColorMode colorMode;
    int width;
    int height;
    int y;
    SplashColorPtr lookup;
} SplashOutMaskedImageData;

typedef struct {
    struct ImageStream* imgStr;
    int invert;
    int width;
    int height;
    int y;
} SplashOutImageMaskData;

typedef struct {
    double r, g, b;
} GfxRGB;

typedef struct {
    double c, m, y, k;
} GfxCMYK;

typedef double GfxGray;

struct Object {
    void initInt(int val);
    void initArray(void *xref);
    void arrayAdd(struct Object *item);
    void free();
};

struct GfxState {
    double *getCTM();
};

struct Stream {
    void close();
};

struct GfxImageColorMap {
    GfxImageColorMap(int nComps, struct Object *decode, struct GfxDeviceGrayColorSpace *colorSpace);
    int getNumPixelComps();
    int getBits();
    void getGray(Guchar *pix, GfxGray *gray);
    void getRGB(Guchar *pix, GfxRGB *rgb);
    void getCMYK(Guchar *pix, GfxCMYK *cmyk);
    ~GfxImageColorMap();
};

struct ImageStream {
    ImageStream(struct Stream *str, int width, int nComps, int bits);
    void reset();
    ~ImageStream();
};

struct Splash {
    Splash(struct SplashBitmap *bitmap, GBool vectorAntialias);
    void clear(SplashColor color);
    void setFillPattern(struct SplashSolidColor *pattern);
    void fillImageMask(void *src, void *data, int width, int height, SplashCoord *mat, GBool t3Glyph);
    void drawImage(void *src, void *data, SplashColorMode srcMode, GBool interpolate, int width, int height, SplashCoord *mat);
    ~Splash();
};

struct SplashBitmap {
    SplashBitmap(int width, int height, int rowPad, SplashColorMode mode, GBool topDown);
    ~SplashBitmap();
};

struct SplashSolidColor {
    SplashSolidColor(SplashColor color);
};

struct GfxDeviceGrayColorSpace {
    GfxDeviceGrayColorSpace();
};

struct SplashOutputDev {
    void drawMaskedImage(struct GfxState *state, struct Object *ref, struct Stream *str, int width, int height,
                        struct GfxImageColorMap *colorMap, struct Stream *maskStr, int maskWidth,
                        int maskHeight, GBool maskInvert);
    void drawSoftMaskedImage(struct GfxState *state, struct Object *ref, struct Stream *str, int width, int height,
                            struct GfxImageColorMap *colorMap, struct Stream *maskStr, int maskWidth,
                            int maskHeight, struct GfxImageColorMap *maskColorMap);
};

#define SPLASH_CMYK 1
#define gFalse 0
#define gTrue 1

void *gmalloc(size_t size);
void *gmallocn(int n, int size);
void gfree(void *p);

unsigned char colToByte(double col);

extern void *imageMaskSrc;
extern void *maskedImageSrc;
extern struct Splash *splash;
extern SplashColorMode colorMode;
extern void *xref;