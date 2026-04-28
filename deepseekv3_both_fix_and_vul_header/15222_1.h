#include <stdlib.h>

typedef unsigned char Guchar;

class GfxColorSpace {
public:
    virtual int getNComps() = 0;
    virtual void getRGBLine(Guchar *in, unsigned int *out, int length) = 0;
};

class GfxIndexedColorSpace {
public:
    GfxColorSpace *base;
    Guchar *lookup;
    void getRGBLine(Guchar *in, unsigned int *out, int length);
};

void *gmalloc(size_t size);
void *gmallocn(int n, int size);
void gfree(void *p);