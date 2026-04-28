#include <stdint.h>
#include <stdlib.h>

#define AV_LOG_ERROR 16
#define AV_LOG_DEBUG 48
#define FF_DEBUG_PICT_INFO 1
#define AVERROR_INVALIDDATA (-1)
#define PNG_IDAT (1 << 0)
#define PNG_IHDR (1 << 1)

typedef struct AVCodecContext {
    int debug;
    void *priv_data;
} AVCodecContext;

typedef struct GetByteContext {
    const uint8_t *buffer;
    int index;
} GetByteContext;

typedef struct PNGDecContext {
    uint32_t state;
    uint32_t width;
    uint32_t height;
    int bit_depth;
    int color_type;
    int compression_type;
    int filter_type;
    int interlace_type;
    GetByteContext gb;
} PNGDecContext;

static inline uint32_t bytestream2_get_be32(GetByteContext *gb) {
    uint32_t val = 0;
    val |= gb->buffer[gb->index++] << 24;
    val |= gb->buffer[gb->index++] << 16;
    val |= gb->buffer[gb->index++] << 8;
    val |= gb->buffer[gb->index++];
    return val;
}

static inline uint8_t bytestream2_get_byte(GetByteContext *gb) {
    return gb->buffer[gb->index++];
}

static inline void bytestream2_skip(GetByteContext *gb, int n) {
    gb->index += n;
}

static int av_image_check_size(unsigned int w, unsigned int h, int log_offset, void *log_ctx) {
    return (w == 0 || h == 0) ? 1 : 0;
}

static void av_log(void *avcl, int level, const char *fmt, ...) {
    (void)avcl;
    (void)level;
    (void)fmt;
}