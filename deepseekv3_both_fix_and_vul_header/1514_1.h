#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct PIX PIX;
typedef int32_t l_int32;

#define ERROR_PTR(msg, proc, ret) (ret)
#define L_MIN(a, b) ((a) < (b) ? (a) : (b))
#define L_WARNING(msg, proc)
#define L_INFO(msg, proc, ...)

#define REMOVE_CMAP_BASED_ON_SRC 0
#define COLOR_RED 0
#define COLOR_GREEN 1
#define COLOR_BLUE 2

PIX *pixCopy(PIX *pixd, PIX *pixs);
PIX *pixRemoveColormap(PIX *pix, l_int32 type);
PIX *pixClone(PIX *pix);
void pixDestroy(PIX **pix);
void pixGetDimensions(PIX *pix, l_int32 *pw, l_int32 *ph, l_int32 *pd);
l_int32 pixGetDepth(PIX *pix);
l_int32 pixGetColormap(PIX *pix);
PIX *pixBlockconvGray(PIX *pix, PIX *pixd, l_int32 wc, l_int32 hc);
PIX *pixGetRGBComponent(PIX *pixs, l_int32 color);
PIX *pixCreateRGBImage(PIX *pixr, PIX *pixg, PIX *pixb);

static const char *procName = "pixBlockconv";