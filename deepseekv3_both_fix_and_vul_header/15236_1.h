#include <stdlib.h>
#include <limits.h>

typedef unsigned int Guint;
typedef unsigned char Guchar;

class JBIG2Segment {
public:
    JBIG2Segment(Guint segNumA);
};

class JBIG2Bitmap : public JBIG2Segment {
public:
    JBIG2Bitmap(Guint segNumA, int wA, int hA);
    int w;
    int h;
    int line;
    Guchar *data;
};

extern void error(int code, const char *msg);
extern void *gmallocn(int n, int size);
extern void *gmalloc(int size);