#include <stdlib.h>

typedef int GBool;
#define gFalse 0
#define gTrue 1

typedef struct XRef XRef;
typedef struct Dict Dict;
typedef struct Catalog Catalog;

typedef struct PDFRectangle {
    double x1, y1, x2, y2;
} PDFRectangle;

struct OutputDev {
    void startPage(int pageNum, void* state);
    void setDefaultCTM(double* ctm);
    void updateAll(void* state);
    void clip(void* state);
    GBool upsideDown();
};

struct GfxResources {
    GfxResources(XRef* xref, Dict* resDict, void*);
};

struct GfxState {
    GfxState(double hDPI, double vDPI, PDFRectangle* box, int rotate, GBool upsideDown);
    void moveTo(double x, double y);
    void lineTo(double x, double y);
    void closePath();
    void clip();
    void clearPath();
    double* getCTM();
};

typedef enum {
    clipNone,
    clipNormal,
    clipIntersect
} GfxClipType;

struct GlobalParams {
    GBool getPrintCommands();
    GBool getProfileCommands();
};
extern GlobalParams* globalParams;

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
    GfxClipType clip;
    int ignoreUndef;
    double baseMatrix[6];
    int formDepth;
    GBool (*abortCheckCbk)(void *data);
    void *abortCheckCbkData;
    
    void pushStateGuard();
    
    Gfx(XRef *xrefA, OutputDev *outA, int pageNum, Dict *resDict, Catalog *catalogA,
        double hDPI, double vDPI, PDFRectangle *box, PDFRectangle *cropBox, int rotate,
        GBool (*abortCheckCbkA)(void *data), void *abortCheckCbkDataA);
};