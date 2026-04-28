#include <stdio.h>
#include <stdlib.h>

typedef unsigned char Guchar;
typedef int GBool;

struct GfxCMYK {
    double c;
    double m;
    double y;
    double k;
};

class Stream {
public:
    virtual void close() = 0;
};

class GfxImageColorMap {
public:
    virtual int getNumPixelComps() = 0;
    virtual int getBits() = 0;
    virtual void getCMYK(const Guchar *pixBuf, GfxCMYK *cmyk) = 0;
};

class ImageStream {
public:
    ImageStream(Stream *str, int width, int nComps, int nBits);
    ~ImageStream();
    void reset();
    void getPixel(Guchar *pixBuf);
};

class PSOutputDev {
public:
    void doImageL1Sep(GfxImageColorMap *colorMap, GBool invert, GBool inlineImg,
                     Stream *str, int width, int height, int len);
};

#define gfxColorMaxComps 32

void writePSFmt(const char *fmt, ...);
void writePSChar(char c);
void addProcessColor(double c, double m, double y, double k);
unsigned char colToByte(double color);
double colToDbl(double color);
void *gmalloc(size_t size);
void *gmallocn(int n, int size);
void gfree(void *p);