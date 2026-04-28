#include <stdlib.h>
#include <stdint.h>

typedef int32_t l_int32;
typedef uint32_t l_uint32;
typedef float l_float32;

typedef struct PIX PIX;
typedef struct PIXCMAP PIXCMAP;

#define LEPT_CALLOC(n, size) calloc(n, size)
#define LEPT_FREE(ptr) free(ptr)
#define ERROR_PTR(msg, proc, ret) NULL
#define PROCNAME(name)
#define L_MIN(a, b) ((a) < (b) ? (a) : (b))
#define L_MAX(a, b) ((a) > (b) ? (a) : (b))
#define GET_DATA_BYTE(line, j) (*((line) + (j)/4) >> (8*((j)%4)) & 0xff)
#define SET_DATA_BIT(line, j) (*((line) + (j)/32) |= (1 << ((j)%32)))
#define SET_DATA_BYTE(line, j, val) (*((line) + (j)/4) = (*((line) + (j)/4) & ~(0xff << (8*((j)%4)))) | ((val) << (8*((j)%4))))

PIX *pixFewColorsOctcubeQuant1(PIX *pixs, l_int32 level);
l_int32 pixGetDepth(PIX *pix);
PIXCMAP *pixGetColormap(PIX *pix);
l_int32 pixcmapGetCount(PIXCMAP *cmap);
void pixcmapGetColor(PIXCMAP *cmap, l_int32 index, l_int32 *rval, l_int32 *gval, l_int32 *bval);
PIXCMAP *pixcmapCreate(l_int32 depth);
void pixcmapAddColor(PIXCMAP *cmap, l_int32 rval, l_int32 gval, l_int32 bval);
void pixGetDimensions(PIX *pix, l_int32 *w, l_int32 *h, l_int32 *d);
PIX *pixCreate(l_int32 width, l_int32 height, l_int32 depth);
void pixSetColormap(PIX *pix, PIXCMAP *cmap);
l_uint32 *pixGetData(PIX *pix);
l_int32 pixGetWpl(PIX *pix);
PIX *pixConvertTo8(PIX *pix, l_int32 cmapflag);
void pixGrayQuantFromHisto(PIX *pixd, PIX *pixg, PIX *pixm, l_float32 minfract, l_int32 maxspan);
void pixDestroy(PIX **pix);