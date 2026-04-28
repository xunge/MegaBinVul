#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef int l_int32;
typedef float l_float32;
typedef unsigned int l_uint32;
typedef unsigned char l_uint8;

typedef struct PIX {
    l_int32 w;
    l_int32 h;
    l_int32 d;
    l_uint32 *data;
    l_int32 wpl;
} PIX;

#define ERROR_PTR(msg, proc, ret) (ret)
#define L_MAX(a, b) ((a) > (b) ? (a) : (b))
#define L_MIN(a, b) ((a) < (b) ? (a) : (b))
#define L_WARNING(msg, proc)
#define L_INFO(msg, proc, ...)
#define PROCNAME(name) static const char *procName = name
#define SET_DATA_BYTE(line, j, val) (line[j] = (val))

static PIX *pixCopy(PIX *pixd, PIX *pixs);
static PIX *pixCreateTemplate(PIX *pixs);
static void pixDestroy(PIX **ppix);
static void pixGetDimensions(PIX *pix, l_int32 *pw, l_int32 *ph, l_int32 *pd);
static l_uint32 *pixGetData(PIX *pix);
static l_int32 pixGetWpl(PIX *pix);
static l_int32 pixGetDepth(PIX *pix);
static PIX *pixBlockconvAccum(PIX *pixs);