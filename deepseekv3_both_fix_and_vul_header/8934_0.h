#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct AVCodecContext {
    void *opaque;
    int log_level_offset;
} AVCodecContext;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

#define AV_LOG_ERROR 16
#define AVERROR_INVALIDDATA (-1)

static inline int av_log2(unsigned int v) {
    return v ? 31 - __builtin_clz(v) : -1;
}

static inline unsigned int show_bits(GetBitContext *gb, int n) {
    return 0;
}

static inline void skip_bits(GetBitContext *gb, int n) {
}

static inline unsigned int get_bits1(GetBitContext *gb) {
    return 0;
}

void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);