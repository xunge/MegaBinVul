#include <stdlib.h>
#include <stdio.h>

typedef int l_int32;
typedef unsigned int l_uint32;
typedef int l_ok;

#define FALSE 0
#define TRUE 1
#define PIX_SRC 0

#define ERROR_INT(msg, procName, val) (printf("%s: %s\n", procName, msg), val)
#define L_WARNING(msg, procName) printf("%s: %s\n", procName, msg)
#define PROCNAME(name) static const char *procName = name
#define L_FILL_WHITE 1

typedef struct Numa NUMA;
typedef struct Pix PIX;

struct Numa {
    void *dummy;
};

struct Pix {
    void *dummy;
};

NUMA *numaCreate(int size);
void numaDestroy(NUMA **pna);
void numaAddNumber(NUMA *na, l_int32 val);
l_int32 numaGetIValue(NUMA *na, l_int32 index, l_int32 *pval);
PIX *pixCopy(PIX *pixd, PIX *pixs);
void pixDestroy(PIX **ppix);
l_int32 pixGetDepth(PIX *pix);
l_int32 pixGetColormap(PIX *pix);
void pixGetDimensions(PIX *pix, l_int32 *pw, l_int32 *ph, l_int32 *pd);
void pixGetPixel(PIX *pix, l_int32 x, l_int32 y, l_uint32 *pval);
void pixSetPixel(PIX *pix, l_int32 x, l_int32 y, l_uint32 val);
void pixRasterop(PIX *pixd, l_int32 dx, l_int32 dy, l_int32 dw, l_int32 dh, 
                 l_int32 op, PIX *pixs, l_int32 sx, l_int32 sy);