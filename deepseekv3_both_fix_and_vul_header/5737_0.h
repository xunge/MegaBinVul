#include <stdint.h>
#include <stdlib.h>

typedef struct AVCodecContext {
    int width;
    int height;
} AVCodecContext;

typedef struct AVPicture {
    uint8_t *data[4];
    int linesize[4];
} AVPicture;

typedef struct GetByteContext {
    const uint8_t *buffer;
    int buffer_size;
    int index;
} GetByteContext;

#define AV_LOG_ERROR 0
#define AVERROR_INVALIDDATA (-1)

static inline int bytestream2_get_bytes_left(const GetByteContext *gb) {
    return gb->buffer_size - gb->index;
}

static inline uint8_t bytestream2_get_byte(GetByteContext *gb) {
    return gb->buffer[gb->index++];
}

static inline uint8_t bytestream2_get_byteu(GetByteContext *gb) {
    return gb->buffer[gb->index++];
}

static inline void bytestream2_skip(GetByteContext *gb, int n) {
    gb->index += n;
}

void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);