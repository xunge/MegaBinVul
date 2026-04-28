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

int gdTrueColorGetRed(int color);
int gdTrueColorGetGreen(int color);
int gdTrueColorGetBlue(int color);
int gdTrueColorGetAlpha(int color);
void *safe_emalloc(size_t nmemb, size_t size, int zero);
void gdFree(void *ptr);