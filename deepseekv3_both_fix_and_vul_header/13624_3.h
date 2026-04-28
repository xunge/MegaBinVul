#include <stdlib.h>
#include <stddef.h>

typedef int GBool;
#define gFalse 0

struct XRef;
struct Dict;
struct Catalog;

struct PDFRectangle {
    double x1, y1, x2, y2;
};

struct OutputDev {
    GBool upsideDown();
    void startPage(int, void*);
    void setDefaultCTM(double*);
    void updateAll(void*);
    void clip(void*);
};

struct GfxResources {
    GfxResources(XRef*, Dict*, void*);
};

struct GfxState {
    GfxState(double, double, PDFRectangle*, int, GBool);
    double* getCTM();
    void moveTo(double, double);
    void lineTo(double, double);
    void closePath();
    void clip();
    void clearPath();
};

struct GlobalParams {
    GBool getPrintCommands();
    GBool getProfileCommands();
};

class Gfx {
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
public:
    Gfx(XRef*, OutputDev*, int, Dict*, Catalog*, double, double, PDFRectangle*,
        PDFRectangle*, int, GBool (*)(void*), void*);
    void pushStateGuard();
};

enum { clipNone };

extern GlobalParams* globalParams;