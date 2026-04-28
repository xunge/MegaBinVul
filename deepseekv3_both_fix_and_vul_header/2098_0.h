#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

typedef struct AVCodecContext AVCodecContext;

typedef struct ShortenContext {
    int channels;
    int nmean;
    int blocksize;
    int nwrap;
    AVCodecContext *avctx;
    int32_t **offset;
    int32_t **decoded_base;
    int32_t **decoded;
    int *coeffs;
} ShortenContext;

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define AV_LOG_ERROR 0

void av_log(void *avctx, int level, const char *fmt, ...);
void *av_realloc(void *ptr, size_t size);