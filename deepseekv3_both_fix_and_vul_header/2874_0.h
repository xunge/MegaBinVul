#include <stdint.h>
#include <stdlib.h>

typedef struct AVCodecContext {
    int height;
    int width;
} AVCodecContext;

typedef struct AVPicture {
    uint8_t *data[4];
    int linesize[4];
} AVPicture;

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

#define FFABS(a) ((a) >= 0 ? (a) : (-(a)))
#define AVERROR_INVALIDDATA (-1)
#define AV_LOG_ERROR 0
#define AV_LOG_WARNING 1

static inline unsigned int bytestream2_get_bytes_left(const GetByteContext *gb) {
    return gb->buffer_end - gb->buffer;
}

static inline uint8_t bytestream2_get_byteu(GetByteContext *gb) {
    return *gb->buffer++;
}

static inline uint8_t bytestream2_get_byte(GetByteContext *gb) {
    return *gb->buffer++;
}

static inline uint16_t bytestream2_get_le16u(GetByteContext *gb) {
    uint16_t val = gb->buffer[0] | (gb->buffer[1] << 8);
    gb->buffer += 2;
    return val;
}

static inline uint16_t bytestream2_get_le16(GetByteContext *gb) {
    uint16_t val = gb->buffer[0] | (gb->buffer[1] << 8);
    gb->buffer += 2;
    return val;
}

static inline uint32_t bytestream2_get_le32u(GetByteContext *gb) {
    uint32_t val = gb->buffer[0] | (gb->buffer[1] << 8) | (gb->buffer[2] << 16) | (gb->buffer[3] << 24);
    gb->buffer += 4;
    return val;
}

static inline uint32_t bytestream2_get_le32(GetByteContext *gb) {
    uint32_t val = gb->buffer[0] | (gb->buffer[1] << 8) | (gb->buffer[2] << 16) | (gb->buffer[3] << 24);
    gb->buffer += 4;
    return val;
}

static inline uint16_t bytestream2_get_be16(GetByteContext *gb) {
    uint16_t val = (gb->buffer[0] << 8) | gb->buffer[1];
    gb->buffer += 2;
    return val;
}

static inline void bytestream2_skip(GetByteContext *gb, unsigned int size) {
    gb->buffer += size;
}

static inline void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}