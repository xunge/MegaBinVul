#include <cmath>
#include <climits>
#include <algorithm>

#define unlikely(x) __builtin_expect(!!(x), 0)

struct PDFRectangle {
    double x1, y1, x2, y2;
};

struct Matrix {
    double m[6];
    void transform(double x, double y, double *tx, double *ty) {
        *tx = m[0] * x + m[2] * y + m[4];
        *ty = m[1] * x + m[3] * y + m[5];
    }
};

struct SplashColor {
    unsigned char c[4];
    unsigned char& operator[](int i) { return c[i]; }
};

typedef double SplashCoord;

enum SplashColorMode {
    splashModeMono8,
    splashModeCMYK8,
    splashModeDeviceN8
};

enum SplashError {
    splashOk
};

struct SplashBitmap {
    SplashBitmap(int, int, int, SplashColorMode, bool) {}
    unsigned char* getDataPtr() { return nullptr; }
    int getWidth() { return 0; }
    int getHeight() { return 0; }
};

struct Splash {
    Splash(SplashBitmap*, bool) {}
    void clear(SplashColor, int) {}
    void setThinLineMode(bool) {}
    void setMinLineWidth(double) {}
    void* getFillPattern() { return nullptr; }
    bool blitImage(SplashBitmap*, bool, int, int) { return false; }
    SplashError drawImage(void*, void*, void*, SplashColorMode, bool, int, int, SplashCoord*, bool, bool) { return splashOk; }
    bool getThinLineMode() { return false; }
};

struct TilingSplashOutBitmap {
    SplashBitmap* bitmap;
    int paintType;
    void* pattern;
    SplashColorMode colorMode;
    int y;
    int repeatX;
    int repeatY;
};

struct GfxState {
    const double* getCTM() { return nullptr; }
    void concatCTM(double, double, double, double, double, double) {}
    void setCTM(double, double, double, double, double, double) {}
    double getHDPI() { return 0; }
    double getVDPI() { return 0; }
};

struct Gfx {
    Gfx(void*, void*, void*, PDFRectangle*, void*, void*, void*, Gfx*) {}
    void display(void*) {}
    GfxState* getState() { return nullptr; }
};

struct Catalog {};
struct Object {};
struct Dict {};

class SplashOutputDev {
public:
    void updateCTM(GfxState*, double, double, double, double, double, double) {}
    bool tilingPatternFill(GfxState*, Gfx*, Catalog*, Object*,
                         const double*, int, int, Dict*,
                         const double*, const double*,
                         int, int, int, int,
                         double, double);
};

static double s_minLineWidth;
static Splash* splash;
static SplashBitmap* bitmap;
static SplashColorMode colorMode;
static SplashColor paperColor;
static void* doc;
static void* tilingBitmapSrc;

inline double splashAbs(double x) { return fabs(x); }
inline int splashFloor(double x) { return (int)floor(x); }