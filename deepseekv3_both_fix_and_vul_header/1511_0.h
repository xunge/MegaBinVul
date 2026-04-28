#include <stdlib.h>
#include <string.h>

typedef int l_int32;
typedef unsigned int l_uint32;

#define ERROR_PTR(msg, proc, ret) (ret)
#define L_MIN(a, b) ((a) < (b) ? (a) : (b))
#define L_WARNING(msg, proc)
#define L_INFO(msg, proc, ...)

typedef struct PIX {
    l_int32 w;
    l_int32 h;
    l_int32 d;
    l_int32 wpl;
    l_uint32 *data;
} PIX;

PIX *pixAddMirroredBorder(PIX *pixs, l_int32 left, l_int32 right, l_int32 top, l_int32 bottom);
PIX *pixBlockconvAccum(PIX *pixs);
PIX *pixCopy(PIX *pixd, PIX *pixs);
void pixDestroy(PIX **ppix);
void pixGetDimensions(PIX *pix, l_int32 *pw, l_int32 *ph, l_int32 *pd);
l_int32 pixGetWpl(PIX *pix);
l_uint32 *pixGetData(PIX *pix);
PIX *pixCreate(l_int32 width, l_int32 height, l_int32 depth);

static const char *procName = "pixBlockconvGrayUnnormalized";