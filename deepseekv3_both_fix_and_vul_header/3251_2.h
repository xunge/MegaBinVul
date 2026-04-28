#include <stdint.h>

typedef struct GetBitContext {
    unsigned int dummy;
} GetBitContext;

typedef struct ALSSpecificConfig {
    int floating;
} ALSSpecificConfig;

typedef struct AVCodecContext {
    int bits_per_raw_sample;
} AVCodecContext;

typedef struct ALSDecContext {
    ALSSpecificConfig sconf;
    AVCodecContext *avctx;
    GetBitContext gb;
} ALSDecContext;

typedef struct ALSBlockData {
    int block_length;
    int32_t *raw_samples;
    int *const_block;
    int js_blocks;
} ALSBlockData;

static inline unsigned int get_bits1(GetBitContext *gb) { return 0; }
static inline void skip_bits(GetBitContext *gb, int n) {}
static inline int32_t get_sbits_long(GetBitContext *gb, int n) { return 0; }