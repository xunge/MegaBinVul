#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define MAX_ORDER 1024
#define AVERROR_INVALIDDATA -1
#define AV_LOG_ERROR 16

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVCodecContext {
    void *av_class;
    int log_level_offset;
} AVCodecContext;

typedef struct CDLMS {
    int order;
    int scaling;
    int coefsend;
    int bitsend;
    int *coefs;
} CDLMS;

typedef struct WmallDecodeCtx {
    GetBitContext gb;
    int num_channels;
    int *cdlms_ttl;
    CDLMS **cdlms;
    AVCodecContext *avctx;
} WmallDecodeCtx;

static inline int get_bits1(GetBitContext *gb) {
    return 0;
}

static inline unsigned int get_bits(GetBitContext *gb, int n) {
    return 0;
}

static int av_log2(unsigned int v) {
    return 0;
}

static void av_log(void *avcl, int level, const char *fmt, ...) {
}