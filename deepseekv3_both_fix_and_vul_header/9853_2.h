#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Uchar;
typedef unsigned int Uint32;
typedef int Int32;

struct DviFontChar {
    int offset;
    int width;
    int code;
    Int32 tfmwidth;
    int loaded;
};

struct DviFontRef {
    struct DviFontRef *next;
};

struct DviFont {
    FILE *in;
    char *fontname;
    Int32 checksum;
    Int32 design;
    long scale;
    struct DviFontRef *subfonts;
    struct DviFontChar *chars;
    int loc;
    int hic;
    Uchar *private;
};

struct DviParams {
    double tfm_conv;
    double mag;
    int dpi;
    int vdpi;
};

typedef struct DviParams DviParams;
typedef struct DviFont DviFont;
typedef struct DviFontRef DviFontRef;
typedef struct DviFontChar DviFontChar;

#define _(x) x
#define DEBUG(x, ...)
#define DBG_FONTS 0
#define DBG_GLYPHS 0
#define DVI_FNT_DEF1 0
#define DVI_FNT_DEF4 0
#define DVI_EOP 0
#define TFMPREPARE(a,b,c,d)
#define TFMSCALE(a,b,c,d) 0
#define FROUND(a) 0
#define xnalloc(type, num) malloc((num) * sizeof(type))
#define xresize(ptr, type, num) realloc(ptr, (num) * sizeof(type))
#define mdvi_malloc malloc
#define mdvi_free free
#define mdvi_warning printf
#define mdvi_error printf
#define fuget1(f) 0
#define fuget3(f) 0
#define fuget4(f) 0
#define fugetn(f,n) 0
#define font_reference(a,b,c,d,e,f,g) NULL