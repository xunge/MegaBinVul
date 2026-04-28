#include <stdio.h>
#include <stdlib.h>

typedef struct gdIOCtx gdIOCtx;
typedef gdIOCtx* gdIOCtxPtr;

typedef struct t_chunk_info {
    int offset;
    int size;
} t_chunk_info;

typedef struct gdImageStruct {
    int sx;
    int sy;
    int trueColor;
    int **tpixels;
    unsigned char **pixels;
} gdImageStruct;

typedef gdImageStruct *gdImagePtr;

#define BGD_DECLARE(x) x
#define GD2_DBG(x)
typedef unsigned long uLongf;

int gd2_compressed(int fmt);
gdImagePtr _gd2CreateFromFile(gdIOCtxPtr in, int *sx, int *sy, int *cs, int *vers, int *fmt, int *ncx, int *ncy, t_chunk_info **chunkIdx);
int _gd2ReadChunk(int offset, unsigned char *compBuf, int compSize, char *chunkBuf, uLongf *chunkLen, gdIOCtxPtr in);
void *gdCalloc(size_t nmemb, size_t size);
void gdFree(void *ptr);
int gdGetInt(int *result, gdIOCtxPtr in);
int gdGetByte(int *result, gdIOCtxPtr in);
void gdImageDestroy(gdImagePtr im);