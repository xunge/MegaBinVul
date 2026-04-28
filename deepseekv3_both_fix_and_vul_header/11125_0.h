#include <stdint.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVCodecContext {
    int profile;
    int level;
} AVCodecContext;

typedef struct MpegEncContext {
    AVCodecContext *avctx;
} MpegEncContext;

static inline unsigned int get_bits(GetBitContext *gb, int n);