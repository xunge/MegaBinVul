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

static inline int gdTrueColorGetRed(int c) {
    return (c >> 16) & 0xFF;
}

static inline int gdTrueColorGetGreen(int c) {
    return (c >> 8) & 0xFF;
}

static inline int gdTrueColorGetBlue(int c) {
    return c & 0xFF;
}

static inline int gdTrueColorGetAlpha(int c) {
    return (c >> 24) & 0xFF;
}