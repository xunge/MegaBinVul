#include <stdio.h>

typedef struct gdIOCtx gdIOCtx;
typedef struct gdImage gdImage;
typedef gdImage* gdImagePtr;

struct gdImage {
    int trueColor;
    int colorsTotal;
    int transparent;
    unsigned char red[256];
    unsigned char green[256];
    unsigned char blue[256];
    unsigned char alpha[256];
    int open[256];
};

#define gdMaxColors 256
#define TRUE 1
#define FALSE 0
#define GD2_DBG(x)

int gdGetByte(unsigned char *output, gdIOCtx *ctx);
int gdGetWord(int *output, gdIOCtx *ctx);
int gdGetInt(int *output, gdIOCtx *ctx);