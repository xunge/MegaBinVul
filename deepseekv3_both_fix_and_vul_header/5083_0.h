#include <stdlib.h>
#include <string.h>

typedef struct gdImageStruct {
    int sx;
    int sy;
    int trueColor;
    int colorsTotal;
    int **pixels;
    int **tpixels;
    unsigned char *red;
    unsigned char *green;
    unsigned char *blue;
    unsigned char *alpha;
} *gdImagePtr;

#define gdMaxColors 256

void *safe_emalloc(size_t nmemb, size_t size, int zero);
void gdFree(void *ptr);

#define gdTrueColorGetRed(c) (((c) >> 16) & 0xFF)
#define gdTrueColorGetGreen(c) (((c) >> 8) & 0xFF)
#define gdTrueColorGetBlue(c) ((c) & 0xFF)
#define gdTrueColorGetAlpha(c) (((c) >> 24) & 0xFF)