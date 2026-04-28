#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gdIOCtx *gdIOCtxPtr;

typedef struct t_chunk_info {
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

#define GD2_DBG(x) x

extern int gdGetC(gdIOCtxPtr in);
extern int gdGetWord(int *out, gdIOCtxPtr in);
extern int gdGetInt(int *out, gdIOCtxPtr in);
extern void *gdCalloc(size_t nmemb, size_t size);
extern void gdFree(void *ptr);
extern int gd2_compressed(int fmt);
extern void php_gd_error(const char *format, ...);