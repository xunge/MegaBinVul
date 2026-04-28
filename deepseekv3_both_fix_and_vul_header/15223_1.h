#include <stdlib.h>

#define gTrue 1
#define gFalse 0
#define gfxColorMaxComps 4

typedef unsigned char Guchar;
typedef double GfxColorComp;

typedef enum {
    csIndexed,
    csSeparation
} GfxColorSpaceMode;

typedef struct Object Object;
typedef struct GfxColorSpace GfxColorSpace;
typedef struct GfxIndexedColorSpace GfxIndexedColorSpace;
typedef struct GfxSeparationColorSpace GfxSeparationColorSpace;
typedef struct Function Function;

struct Object {
    int isNull();
    int isArray();
    int isNum();
    int arrayGetLength();
    void arrayGet(int i, Object* obj);
    double getNum();
    void free();
};

struct GfxColorSpace {
    int (*getNComps)(void);
    void (*getDefaultRanges)(double *decodeLow, double *decodeRange, int maxPixel);
    GfxColorSpaceMode (*getMode)(void);
};

struct GfxIndexedColorSpace {
    GfxColorSpace base;
    GfxColorSpace *(*getBase)(void);
    int (*getIndexHigh)(void);
    Guchar *(*getLookup)(void);
};

struct GfxSeparationColorSpace {
    GfxColorSpace base;
    GfxColorSpace *(*getAlt)(void);
    Function *(*getFunc)(void);
};

struct Function {
    void (*transform)(double *x, double *y);
};

struct GfxImageColorMap {
    int bits;
    GfxColorSpace *colorSpace;
    GfxColorSpace *colorSpace2;
    int nComps;
    int nComps2;
    GfxColorComp *lookup[gfxColorMaxComps];
    Guchar *byte_lookup;
    double decodeLow[gfxColorMaxComps];
    double decodeRange[gfxColorMaxComps];
    int ok;
    GfxImageColorMap(int bitsA, Object *decode, GfxColorSpace *colorSpaceA);
};

static GfxColorComp dblToCol(double x) {
    return (GfxColorComp)x;
}

static void *gmalloc(size_t size) {
    return malloc(size);
}

static void *gmallocn(size_t n, size_t size) {
    return malloc(n * size);
}