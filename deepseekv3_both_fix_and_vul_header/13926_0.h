#include <stdio.h>
#include <string.h>

#define MAXCOLORMAPSIZE 256
#define FALSE 0
#define TRUE 1
#define VERBOSE 0

typedef struct gdIOCtx gdIOCtx;
typedef struct gdIOCtx *gdIOCtxPtr;
typedef struct gdImageStruct *gdImagePtr;

struct gdImageStruct {
    int interlace;
    int colorsTotal;
    int *open;
};

int ReadOK(gdIOCtxPtr fd, unsigned char *buf, int len);
int BitSet(unsigned char byte, int bit);
int LM_to_uint(unsigned char a, unsigned char b);
int ReadColorMap(gdIOCtxPtr fd, int number, unsigned char buffer[3][MAXCOLORMAPSIZE]);
void DoExtension(gdIOCtxPtr fd, int label, int *Transparent, int *ZeroDataBlock);
gdImagePtr gdImageCreate(int width, int height);
void gdImageDestroy(gdImagePtr im);
void ReadImage(gdImagePtr im, gdIOCtxPtr fd, int width, int height, unsigned char cmap[3][MAXCOLORMAPSIZE], int interlace, int *ZeroDataBlock);
void gdImageColorTransparent(gdImagePtr im, int color);

#define LOCALCOLORMAP 7
#define INTERLACE 6