#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Guint;
typedef long long Goffset;
typedef int GBool;
#define gFalse 0
#define gTrue 1

#define errSyntaxError 0

class Stream {
public:
    int getChar();
    Goffset getPos();
};

class JBIG2Stream {
public:
    void readSegments();
    int readULong(Guint*);
    int readUByte(Guint*);
    int readUWord(Guint*);
    int readByte(int*);
    int readSymbolDictSeg(Guint, Guint, Guint*, Guint);
    void readTextRegionSeg(Guint, GBool, GBool, Guint, Guint*, Guint);
    void readPatternDictSeg(Guint, Guint);
    void readHalftoneRegionSeg(Guint, GBool, GBool, Guint, Guint*, Guint);
    void readGenericRegionSeg(Guint, GBool, GBool, Guint);
    void readGenericRefinementRegionSeg(Guint, GBool, GBool, Guint, Guint*, Guint);
    void readPageInfoSeg(Guint);
    void readEndOfStripeSeg(Guint);
    void readProfilesSeg(Guint);
    void readCodeTableSeg(Guint, Guint);
    void readExtensionSeg(Guint);
};

void *gmallocn(size_t nmemb, size_t size);
void gfree(void *p);
void error(int err, Goffset pos, const char *msg, ...);

extern Stream* curStr;
extern GBool pageBitmap;