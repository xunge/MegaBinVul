#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short Gushort;
const int gTrue = 1;
const int psLevel3 = 3;

class FoFiTrueType;

class GooString {
public:
    GooString *copy();
    int cmp(GooString *other);
    void append(const char *str);
    const char *getCString();
    GooString *sanitizedName(int psMode);
};

class GfxFont {
public:
    GooString *getName();
};

class GfxCIDFont : public GfxFont {
public:
    Gushort *getCIDToGID();
    int getCIDToGIDLen();
    Gushort *getCodeToGIDMap(FoFiTrueType *ffTT, int *n);
};

class FoFiTrueType {
public:
    static FoFiTrueType *load(const char *fileName, int faceIndex);
    void convertToCIDType2(const char *psName, Gushort *codeToGID, int n, int needVerticalMetrics, void (*outputFunc)(void *stream, const char *data, int len), void *outputStream);
    void convertToType0(const char *psName, Gushort *codeToGID, int n, int needVerticalMetrics, void (*outputFunc)(void *stream, const char *data, int len), void *outputStream);
    ~FoFiTrueType();
};

class PSOutputDev {
public:
    GooString *setupExternalCIDTrueTypeFont(GfxFont *font, GooString *fileName, int faceIndex);
    void writePSFmt(const char *fmt, GooString *arg);
    void writePS(const char *str);
    GooString **fontFileNames;
    GooString **psFileNames;
    int fontFileNameLen;
    int fontFileNameSize;
    GooString *embFontList;
    void (*outputFunc)(void *stream, const char *data, int len);
    void *outputStream;
};

extern void *gmalloc(size_t size);
extern void *gmallocn(size_t n, size_t size);
extern void gfree(void *p);
extern void *grealloc(void *p, size_t size);

class GlobalParams {
public:
    int getPSLevel();
};

extern GlobalParams *globalParams;