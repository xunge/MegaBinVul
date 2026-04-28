#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define Z_OK 0
#define EXR_FLOAT 1

typedef struct GetByteContext {
    const uint8_t *buffer;
    int size;
    int pos;
} GetByteContext;

typedef struct EXRThreadData {
    int xsize;
    int ysize;
    uint8_t *ac_data;
    size_t ac_size;
    uint8_t *dc_data;
    size_t dc_size;
    uint8_t *rle_data;
    size_t rle_size;
    uint8_t *rle_raw_data;
    size_t rle_raw_size;
    void *uncompressed_data;
    float block[3][64];
} EXRThreadData;

typedef struct EXRContext {
    int scan_lines_per_block;
    int nb_channels;
    int pixel_type;
    const uint16_t *mantissatable;
    const uint16_t *exponenttable;
    const uint16_t *offsettable;
    struct {
        void (*predictor)(uint8_t *src, unsigned size);
        void (*reorder_pixels)(uint8_t *dst, const uint8_t *src, unsigned size);
    } dsp;
} EXRContext;

#define AVERROR_INVALIDDATA (-1)
#define AVERROR(ENOMEM) (-2)
#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))
#define AV_RL64(p) (*(const uint64_t *)(p))

static inline void bytestream2_init(GetByteContext *gb, const uint8_t *buf, int size) {
    gb->buffer = buf;
    gb->size = size;
    gb->pos = 0;
}

static inline uint16_t bytestream2_get_le16(GetByteContext *gb) {
    uint16_t val = gb->buffer[gb->pos] | (gb->buffer[gb->pos + 1] << 8);
    gb->pos += 2;
    return val;
}

static inline void bytestream2_skip(GetByteContext *gb, int n) {
    gb->pos += n;
}

static inline void av_fast_padded_malloc(void *ptr, size_t *size, size_t min_size) {
    if (min_size > *size) {
        free(*(void **)ptr);
        *(void **)ptr = malloc(min_size);
        *size = min_size;
    }
}

static int uncompress(void *dest, unsigned long *destLen, const void *source, unsigned long sourceLen) {
    return 0;
}

static int huf_uncompress(EXRContext *s, EXRThreadData *td, GetByteContext *gb, int16_t *dst, int64_t count) {
    return 0;
}

static int rle(uint8_t *dst, const uint8_t *src, int src_size, int dst_size) {
    return 0;
}

static float half2float(uint16_t h, const uint16_t *mantissatable, const uint16_t *exponenttable, const uint16_t *offsettable) {
    return 0.0f;
}

static void ac_uncompress(EXRContext *s, GetByteContext *gb, float *block) {
}

static void dct_inverse(float *block) {
}

static void convert(float y, float u, float v, float *b, float *g, float *r) {
}

static float to_linear(float val, float scale) {
    return val * scale;
}

typedef union av_intfloat32 {
    uint32_t i;
    float f;
} av_intfloat32;