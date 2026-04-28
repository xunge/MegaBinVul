#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int GBool;
typedef float SplashCoord;
typedef unsigned char *SplashColorPtr;
typedef int SplashClipResult;
typedef int SplashError;

typedef void (*SplashImageMaskSource)(void *srcData, unsigned char *dest);

typedef struct {
    int shape;
} SplashPipe;

typedef struct {
    SplashClipResult (*testRect)(int xMin, int yMin, int xMax, int yMax);
    SplashClipResult (*testSpan)(int spanXMin, int spanXMax, int spanY);
} SplashClip;

typedef struct {
    SplashClip *clip;
    void *fillPattern;
    SplashCoord fillAlpha;
} SplashState;

struct Splash {
    SplashState *state;
    GBool debugMode;
    GBool vectorAntialias;
    SplashClipResult opClipRes;
    
    SplashError fillImageMask(SplashImageMaskSource src, void *srcData,
                            int w, int h, SplashCoord *mat, GBool glyphMode);
};

#define gTrue 1
#define gFalse 0
#define splashOk 0
#define splashErrZeroImage 1
#define splashErrSingularMatrix 2
#define splashClipAllInside 0
#define splashClipAllOutside 1

static inline int splashAbs(int x) { return abs(x); }
static inline int splashRound(SplashCoord x) { return (int)roundf(x); }
static inline int splashFloor(SplashCoord x) { return (int)floorf(x); }

static void *gmalloc(size_t size) { return malloc(size); }
static void *gmallocn(size_t n, size_t size) { return malloc(n * size); }
static void gfree(void *p) { free(p); }

static void pipeInit(SplashPipe *pipe, int x, int y, void *pattern, void *color, SplashCoord alpha, GBool usesShape, GBool nonIsolated) {}
static void drawAAPixel(SplashPipe *pipe, int x, int y) {}
static void drawAAPixelInit() {}
static void drawPixel(SplashPipe *pipe, int x, int y, GBool clipAllInside) {}