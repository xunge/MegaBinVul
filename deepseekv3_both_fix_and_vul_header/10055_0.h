#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct gdIOCtx gdIOCtx;
typedef gdIOCtx *gdIOCtxPtr;

typedef struct {
    int offset;
    int size;
} t_chunk_info;

#define GD2_ID "gd2"
#define GD2_CHUNKSIZE_MIN 1
#define GD2_CHUNKSIZE_MAX 1024
#define GD2_FMT_RAW 1
#define GD2_FMT_COMPRESSED 2
#define GD2_FMT_TRUECOLOR_RAW 3
#define GD2_FMT_TRUECOLOR_COMPRESSED 4

#define GD2_DBG(x)

extern int gdGetC(gdIOCtxPtr in);
extern int gdGetWord(int *output, gdIOCtxPtr in);
extern int gdGetInt(int *output, gdIOCtxPtr in);
extern void *gdCalloc(size_t nmemb, size_t size);
extern void gdFree(void *ptr);
extern int gd2_compressed(int fmt);
extern int overflow2(size_t a, size_t b);