#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define gTrue 1
#define gFalse 0

typedef int GBool;
typedef unsigned char Guchar;
typedef double SplashCoord;

typedef enum {
    splashClipAllInside,
    splashClipAllOutside,
    splashClipPartial
} SplashClipResult;

typedef struct {
    int y0, y1;
    int ia0, ia1, ib0, ib1;
    SplashCoord xa0, ya0, xa1, ya1;
    SplashCoord xb0, yb0, xb1, yb1;
    SplashCoord dxdya, dxdyb;
} ImageSection;

typedef struct {
    Guchar *data;
    int width;
    int height;
} SplashBitmap;

typedef struct SplashClip SplashClip;
struct SplashClip {
    SplashClipResult (*testRect)(int x0, int y0, int x1, int y1);
    SplashClipResult (*testSpan)(int x0, int x1, int y);
};

typedef struct {
    SplashClip *clip;
    void *fillPattern;
    SplashCoord fillAlpha;
} SplashState;

typedef struct {
    Guchar shape;
    void *pattern;
    Guchar alpha;
    GBool nonIsolated;
    GBool knockout;
} SplashPipe;

typedef void (*SplashImageMaskSource)(void *srcData, int x, int y, Guchar *pixel);

enum ErrorCategory {
    errInternal
};

static void error(ErrorCategory category, int code, const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(code);
}

class Splash {
public:
    void arbitraryTransformMask(SplashImageMaskSource src, void *srcData,
                              int srcWidth, int srcHeight,
                              SplashCoord *mat, GBool glyphMode);
};

static inline int splashFloor(SplashCoord x) {
    return (int)floor(x);
}

static inline SplashCoord splashAbs(SplashCoord x) {
    return fabs(x);
}

static inline int splashRound(SplashCoord x) {
    return (int)round(x);
}

static inline int imgCoordMungeLowerC(SplashCoord x, GBool glyphMode) {
    return (int)floor(x);
}

static inline int imgCoordMungeUpperC(SplashCoord x, GBool glyphMode) {
    return (int)ceil(x);
}

static SplashBitmap *scaleMask(SplashImageMaskSource src, void *srcData,
                              int srcWidth, int srcHeight,
                              int scaledWidth, int scaledHeight) {
    return NULL;
}

static void pipeInit(SplashPipe *pipe, int x0, int y0, void *pattern,
                    void *shape, Guchar alpha, GBool nonIsolated, GBool knockout) {}

static void drawAAPixelInit() {}
static void drawAAPixel(SplashPipe *pipe, int x, int y) {}
static void drawPixel(SplashPipe *pipe, int x, int y, GBool clipAllInside) {}

static SplashState *state;
static GBool vectorAntialias;
static SplashClipResult opClipRes;