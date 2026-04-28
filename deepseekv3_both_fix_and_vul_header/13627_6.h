#include <stddef.h>

typedef struct XRef XRef;
typedef struct Dict Dict;
typedef struct Catalog Catalog;

typedef struct PDFRectangle {
    double x1, y1, x2, y2;
} PDFRectangle;

typedef struct GfxResources {
    GfxResources(XRef*, Dict*, void*);
} GfxResources;

typedef struct GfxState {
    GfxState(double, double, PDFRectangle*, int, int);
    const double* getCTM();
    void moveTo(double, double);
    void lineTo(double, double);
    void closePath();
    void clip();
    void clearPath();
} GfxState;

typedef struct OutputDev {
    void clip(GfxState*);
} OutputDev;

typedef int GBool;
#define gTrue 1
#define gFalse 0

enum { clipNone };

struct GlobalParams {
    GBool (*getPrintCommands)();
    GBool (*getProfileCommands)();
};

extern GlobalParams* globalParams;

struct Gfx {
    Gfx(XRef*, OutputDev*, Dict*, Catalog*, PDFRectangle*, PDFRectangle*, GBool (*)(void*), void*);
    
    void pushStateGuard();
    
    XRef* xref;
    Catalog* catalog;
    GBool subPage;
    GBool printCommands;
    GBool profileCommands;
    GBool textHaveCSPattern;
    GBool drawText;
    GBool maskHaveCSPattern;
    void* mcStack;
    GfxResources* res;
    OutputDev* out;
    GfxState* state;
    int stackHeight;
    GBool fontChanged;
    int clip;
    int ignoreUndef;
    double baseMatrix[6];
    int formDepth;
    GBool (*abortCheckCbk)(void*);
    void* abortCheckCbkData;
};