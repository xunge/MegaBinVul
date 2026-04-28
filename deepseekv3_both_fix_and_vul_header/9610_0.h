#include <stdint.h>
#include <string.h>

#define PALETTE_COUNT 256
#define AV_RL16(x) ((x)[0] | ((x)[1] << 8))

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
} AVFrame;

typedef struct AVCodecContext {
    int width;
    int height;
} AVCodecContext;

typedef struct VmdVideoContext {
    const uint8_t *buf;
    int size;
    AVCodecContext *avctx;
    AVFrame *prev_frame;
    uint32_t palette[256];
    int x_off;
    int y_off;
    uint8_t *unpack_buffer;
    int unpack_buffer_size;
} VmdVideoContext;

#define AV_LOG_ERROR 0
#define AVERROR_INVALIDDATA (-1)

static inline void bytestream2_init(GetByteContext *g, const uint8_t *buf, int buf_size) {
    g->buffer = buf;
    g->buffer_start = buf;
    g->buffer_end = buf + buf_size;
}

static inline int bytestream2_get_bytes_left(const GetByteContext *g) {
    return g->buffer_end - g->buffer;
}

static inline void bytestream2_skip(GetByteContext *g, unsigned int size) {
    g->buffer += size;
}

static inline uint8_t bytestream2_get_byte(GetByteContext *g) {
    return *g->buffer++;
}

static inline uint8_t bytestream2_get_byteu(GetByteContext *g) {
    return *g->buffer++;
}

static inline uint8_t bytestream2_peek_byte(GetByteContext *g) {
    return *g->buffer;
}

static inline void bytestream2_get_buffer(GetByteContext *g, uint8_t *dst, unsigned int size) {
    memcpy(dst, g->buffer, size);
    g->buffer += size;
}

static inline void bytestream2_get_bufferu(GetByteContext *g, uint8_t *dst, unsigned int size) {
    memcpy(dst, g->buffer, size);
    g->buffer += size;
}

static void av_log(void *avcl, int level, const char *fmt, ...) {}

static int lz_unpack(const uint8_t *src, int src_size, uint8_t *dst, int dst_size) {
    return 0;
}

static int rle_unpack(const uint8_t *src, uint8_t *dst, int count, int src_size, int dst_size) {
    return 0;
}