#include <stdint.h>
#include <stdlib.h>

#define FF_DWT_MAX_DECLVLS 32
#define FF_DWT97 0
#define FF_DWT53 1

#define AVERROR_INVALIDDATA -1
#define AVERROR(ENOMEM) -2

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct DWTContext {
    int ndeclevels;
    int type;
    int linelen[FF_DWT_MAX_DECLVLS][2];
    int mod[FF_DWT_MAX_DECLVLS][2];
    void *linebuf;
} DWTContext;

void *av_malloc(size_t size);