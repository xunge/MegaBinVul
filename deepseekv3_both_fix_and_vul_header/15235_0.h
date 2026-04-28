#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned int Guint;
typedef unsigned char Guchar;

class JBIG2Segment {
public:
    JBIG2Segment(Guint segNumA);
};

class JBIG2Bitmap : public JBIG2Segment {
public:
    JBIG2Bitmap(Guint segNumA, JBIG2Bitmap *bitmap);
    int w;
    int h;
    int line;
    Guchar *data;
};

extern void error(int code, const char *msg);
extern void *gmalloc(size_t size);
extern void *gmallocn(int count, int size);