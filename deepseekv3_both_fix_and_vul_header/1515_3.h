#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef int32_t l_int32;
typedef struct Pix PIX;
typedef struct PIXTILING PIXTILING;

#define L_MAX(a, b) ((a) > (b) ? (a) : (b))
#define L_MIN(a, b) ((a) < (b) ? (a) : (b))

#define ERROR_PTR(msg, proc, ret) (ret)
#define PROCNAME(name) static const char *procName = name
#define L_WARNING(...) fprintf(stderr, "Warning: " __VA_ARGS__)
#define L_INFO(...) fprintf(stderr, __VA_ARGS__)

#define REMOVE_CMAP_BASED_ON_SRC 0
#define COLOR_RED 0
#define COLOR_GREEN 1
#define COLOR_BLUE 2

PIX *pixCopy(PIX *pixd, PIX *pixs);
PIX *pixBlockconv(PIX *pix, l_int32 wc, l_int32 hc);
PIX *pixRemoveColormap(PIX *pixs, l_int32 type);
PIX *pixClone(PIX *pixs);
l_int32 pixGetDimensions(PIX *pix, l_int32 *pw, l_int32 *ph, l_int32 *pd);
l_int32 pixGetDepth(PIX *pix);
l_int32 pixGetColormap(PIX *pix);
PIX *pixCreateTemplate(PIX *pixs);
PIXTILING *pixTilingCreate(PIX *pixs, l_int32 nx, l_int32 ny, l_int32 w, l_int32 h, l_int32 xoverlap, l_int32 yoverlap);
PIX *pixTilingGetTile(PIXTILING *pt, l_int32 i, l_int32 j);
PIX *pixBlockconvGrayTile(PIX *pixs, PIX *pixd, l_int32 wc, l_int32 hc);
PIX *pixGetRGBComponent(PIX *pixs, l_int32 comp);
PIX *pixCreateRGBImage(PIX *pixr, PIX *pixg, PIX *pixb);
void pixTilingPaintTile(PIX *pixd, l_int32 i, l_int32 j, PIX *pixs, PIXTILING *pt);
void pixDestroy(PIX **ppix);
void pixTilingDestroy(PIXTILING **ppt);