#include <stdlib.h>

typedef int GBool;
#define gTrue 1
#define gFalse 0

enum ClipType {
    clipNone
};

struct XRef;
struct Dict;
struct Catalog;
struct GlobalParams {
    GBool (*getPrintCommands)();
    GBool (*getProfileCommands)();
};
extern GlobalParams* globalParams;

struct PDFRectangle {
    double x1, y1, x2, y2;
};

struct GfxResources {
    GfxResources(XRef*, Dict*, void*);
};

struct GfxState {
    GfxState(double, double, PDFRectangle*, int, GBool);
    void moveTo(double, double);
    void lineTo(double, double);
    void closePath();
    void clip();
    void clearPath();
    const double* getCTM();
};

struct OutputDev {
    void clip(GfxState*);
};

struct Gfx {
    XRef *xref;
    Catalog *catalog;
    GBool subPage;
    GBool printCommands;
    GBool profileCommands;
    GBool textHaveCSPattern;
    GBool drawText;
    GBool maskHaveCSPattern;
    void *mcStack;
    void *parser;
    GfxResources *res;
    OutputDev *out;
    GfxState *state;
    int stackHeight;
    GBool fontChanged;
    ClipType clip;
    int ignoreUndef;
    double baseMatrix[6];
    int formDepth;
    GBool (*abortCheckCbk)(void *data);
    void *abortCheckCbkData;
    
    void pushStateGuard();
    Gfx(XRef*, OutputDev*, Dict*, Catalog*,
        PDFRectangle*, PDFRectangle*,
        GBool (*)(void*), void*);
};