#include <stdlib.h>

typedef struct gdImageStruct *gdImagePtr;

struct gdImageStruct {
    int sx;
    int sy;
    int colorsTotal;
    int trueColor;
    int alphaBlendingFlag;
};

struct seg {
    int y;
    int x1;
    int x2;
    int dy;
};

#define gdTiled (-1)

#define FILL_PUSH(Y, X1, X2, DY) \
    if (sp < (stack + ((im->sy * im->sx)/4))) { \
        sp->y = Y; \
        sp->x1 = X1; \
        sp->x2 = X2; \
        sp->dy = DY; \
        sp++; \
    }

#define FILL_POP(Y, X1, X2, DY) \
    { \
        sp--; \
        Y = sp->y; \
        X1 = sp->x1; \
        X2 = sp->x2; \
        DY = sp->dy; \
    }

void *_safe_emalloc(size_t nmemb, size_t size, int zero);
#define safe_emalloc(nmemb, size, zero) _safe_emalloc(nmemb, size, zero)

void efree(void *ptr);

int gdImageGetPixel(gdImagePtr im, int x, int y);
void gdImageSetPixel(gdImagePtr im, int x, int y, int color);
void _gdImageFillTiled(gdImagePtr im, int x, int y, int nc);