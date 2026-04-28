#include <stdint.h>
#include <limits.h>
#include <stddef.h>

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

#define AVERROR_BUFFER_TOO_SMALL (-1)
#define AVERROR_INVALIDDATA (-2)
#define FF_JPEGXL_CODESTREAM_SIGNATURE_LE 0x0AFF
#define FF_JPEGXL_CONTAINER_SIGNATURE_LE 0x204C584A0C000000

typedef struct JXLParseContext {
    int skip;
} JXLParseContext;

static inline void bytestream2_init(GetByteContext *gb, const uint8_t *buf, int buf_size) {
    gb->buffer = buf;
    gb->buffer_start = buf;
    gb->buffer_end = buf + buf_size;
}

static inline int bytestream2_peek_le16(const GetByteContext *gb) {
    return gb->buffer < gb->buffer_end - 1 ? (gb->buffer[1] << 8) | gb->buffer[0] : 0;
}

static inline uint64_t bytestream2_peek_le64(const GetByteContext *gb) {
    uint64_t ret = 0;
    if (gb->buffer < gb->buffer_end - 7) {
        for (int i = 0; i < 8; i++)
            ret |= (uint64_t)gb->buffer[i] << (8 * i);
    }
    return ret;
}

static inline int bytestream2_get_bytes_left(const GetByteContext *gb) {
    return gb->buffer_end - gb->buffer;
}

static inline uint32_t bytestream2_get_be32(GetByteContext *gb) {
    uint32_t ret = 0;
    if (gb->buffer < gb->buffer_end - 3) {
        for (int i = 0; i < 4; i++)
            ret = (ret << 8) | gb->buffer[i];
        gb->buffer += 4;
    }
    return ret;
}

static inline uint64_t bytestream2_get_be64(GetByteContext *gb) {
    uint64_t ret = 0;
    if (gb->buffer < gb->buffer_end - 7) {
        for (int i = 0; i < 8; i++)
            ret = (ret << 8) | gb->buffer[i];
        gb->buffer += 8;
    }
    return ret;
}

static inline void bytestream2_skip(GetByteContext *gb, size_t size) {
    gb->buffer += FFMIN(size, gb->buffer_end - gb->buffer);
}