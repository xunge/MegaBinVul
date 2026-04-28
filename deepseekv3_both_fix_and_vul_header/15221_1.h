#include <stdlib.h>

typedef unsigned char Guchar;

enum {
    csIndexed,
    csSeparation
};

struct GfxColorSpace {
    int getMode();
    void getGrayLine(Guchar *in, Guchar *out, int length);
};

struct GfxImageColorMap {
    GfxColorSpace *colorSpace;
    GfxColorSpace *colorSpace2;
    int nComps;
    int nComps2;
    Guchar *byte_lookup;
    void getGrayLine(Guchar *in, Guchar *out, int length);
};

void *gmalloc(size_t size);
void *gmallocn(int n, int size);
void gfree(void *p);