#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned char Guchar;
typedef int SplashClipResult;
typedef int GBool;

#define gTrue 1
#define gFalse 0

enum {
    splashClipAllInside,
    errInternal
};

struct SplashBitmap {
    int width;
    int height;
    Guchar *data;
    int getWidth() { return width; }
    int getHeight() { return height; }
    Guchar* getDataPtr() { return data; }
};

struct SplashState {
    void *fillPattern;
    double fillAlpha;
    struct SplashClip *clip;
};

struct Splash;

struct SplashPipe {
    void (Splash::*run)(SplashPipe *);
    Guchar shape;
};

struct SplashClip {
    GBool test(int x, int y) { return gTrue; }
};

struct Splash {
    void blitMask(SplashBitmap *src, int xDest, int yDest, SplashClipResult clipRes);
    void updateModX(int x);
    void updateModY(int y);
};

extern SplashState *state;
extern int vectorAntialias;
extern void pipeInit(SplashPipe *pipe, int xDest, int yDest, void *fillPattern, void *ptr, Guchar alpha, GBool bool1, GBool bool2);
extern void drawAAPixelInit();
extern void drawAAPixel(SplashPipe *pipe, int x, int y);
extern void pipeSetXY(SplashPipe *pipe, int x, int y);
extern void pipeIncX(SplashPipe *pipe);
extern int splashRound(double x);
extern void error(int errCode, int pos, const char *msg);