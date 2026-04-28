#include <stdint.h>

typedef uint8_t guchar;
typedef unsigned int guint;

typedef struct {
    guchar r;
    guchar g;
    guchar b;
    guchar a;
} TGAColor;

typedef struct {
    TGAColor *cols;
} ColorMap;

typedef struct {
    guint width;
} PixelBuffer;

typedef struct {
    guint cmap_bpp;
} TGAHeader;

typedef struct {
    guchar *data;
} InputData;

typedef struct {
    InputData *in;
    PixelBuffer *pbuf;
    guchar *pptr;
    ColorMap *cmap;
    TGAHeader *hdr;
} TGAContext;

TGAColor* colormap_get_color(ColorMap *cmap, guchar index);