#include <stdlib.h>
#include <math.h>

typedef int GBool;
typedef float SplashCoord;
typedef unsigned char Guchar;

#define gTrue 1
#define gFalse 0
#define errInternal 1

typedef enum {
  splashClipAllOutside,
  splashClipAllInside,
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
  unsigned char *data;
} SplashBitmap;

typedef struct SplashClip {
  SplashClipResult (*testRect)(int, int, int, int);
  SplashClipResult (*testSpan)(int, int, int);
} SplashClip;

typedef struct {
  SplashClip *clip;
  void *fillPattern;
  SplashCoord fillAlpha;
} SplashState;

typedef struct SplashPipe {
  unsigned char shape;
} SplashPipe;

typedef void (*SplashImageMaskSource)(void *srcData, int x, int y, unsigned char *pixel);

struct Splash {
  SplashState *state;
  GBool vectorAntialias;
  SplashClipResult opClipRes;
  
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

static void pipeInit(SplashPipe *pipe, int x0, int y0, void *fillPattern, void *strokePattern, Guchar alpha, GBool nonIsolatedGroup, GBool usesShape) {}
static void drawAAPixelInit() {}
static void drawAAPixel(SplashPipe *pipe, int x, int y) {}
static void drawPixel(SplashPipe *pipe, int x, int y, GBool clipRes) {}
static SplashBitmap *scaleMask(SplashImageMaskSource src, void *srcData, int srcWidth, int srcHeight, int scaledWidth, int scaledHeight) { return NULL; }
static void error(int errCode, int pos, const char *msg) {}