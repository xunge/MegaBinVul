#include <stdlib.h>

typedef unsigned char Guchar;

typedef enum {
    csIndexed,
    csSeparation
} ColorSpaceMode;

typedef struct ColorSpace ColorSpace;
struct ColorSpace {
    ColorSpaceMode (*getMode)(void);
    void (*getRGBLine)(Guchar *in, unsigned int *out, int length);
};

struct GfxImageColorMap {
    int nComps;
    int nComps2;
    Guchar *byte_lookup;
    ColorSpace *colorSpace;
    ColorSpace *colorSpace2;
    void getRGBLine(Guchar *in, unsigned int *out, int length);
};

void *gmalloc(size_t size);
void *gmallocn(int n, int size);
void gfree(void *p);