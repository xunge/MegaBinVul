#include <stdlib.h>
#include <stdio.h>

typedef int l_int32;
typedef unsigned int l_uint32;

typedef struct PIX {
    l_int32 w;
    l_int32 h;
    l_int32 d;
    l_uint32 *data;
    l_int32 wpl;
} PIX;

#define ERROR_PTR(msg, proc, ret) (ret)
#define L_ERROR(...) 
#define L_WARNING(...) 
#define L_INFO(...) 
#define PROCNAME(func) 

PIX *pixCopy(PIX *pixd, PIX *pixs);
PIX *pixCreateTemplate(PIX *pixs);
void pixDestroy(PIX **pix);
l_int32 pixGetDimensions(PIX *pix, l_int32 *pw, l_int32 *ph, l_int32 *pd);
l_int32 pixGetDepth(PIX *pix);
l_uint32 *pixGetData(PIX *pix);
l_int32 pixGetWpl(PIX *pix);
void pixSetPadBits(PIX *pix, l_int32 val);
PIX *pixBlockconvAccum(PIX *pixs);
void blockconvLow(l_uint32 *datad, l_int32 w, l_int32 h, l_int32 wpl, 
                 l_uint32 *dataa, l_int32 wpla, l_int32 wc, l_int32 hc);
PIX *pixClone(PIX *pix);