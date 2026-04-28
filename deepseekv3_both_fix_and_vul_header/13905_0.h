#include <stdint.h>
#include <string.h>
#include <stdio.h>

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

#define AMF_DATA_TYPE_NUMBER   0
#define AMF_DATA_TYPE_BOOL     1
#define AMF_DATA_TYPE_STRING   2
#define AMF_DATA_TYPE_OBJECT   3

#define AV_RB64(x) (((uint64_t)((const uint8_t*)(x))[0] << 56) | \
                   ((uint64_t)((const uint8_t*)(x))[1] << 48) | \
                   ((uint64_t)((const uint8_t*)(x))[2] << 40) | \
                   ((uint64_t)((const uint8_t*)(x))[3] << 32) | \
                   ((uint64_t)((const uint8_t*)(x))[4] << 24) | \
                   ((uint64_t)((const uint8_t*)(x))[5] << 16) | \
                   ((uint64_t)((const uint8_t*)(x))[6] <<  8) | \
                   ((uint64_t)((const uint8_t*)(x))[7]      ))

static inline double av_int2double(uint64_t v) {
    union {
        uint64_t i;
        double   d;
    } u;
    u.i = v;
    return u.d;
}

static inline void bytestream2_init(GetByteContext *g, const uint8_t *buf, int buf_size) {
    g->buffer = buf;
    g->buffer_start = buf;
    g->buffer_end = buf + buf_size;
}

static inline uint16_t bytestream_get_be16(const uint8_t **buf) {
    uint16_t val = AV_RB16(*buf);
    *buf += 2;
    return val;
}

#define AV_RB16(x) ((((const uint8_t*)(x))[0] << 8) | ((const uint8_t*)(x))[1])

static inline size_t ff_amf_tag_size(const uint8_t *data, const uint8_t *data_end) {
    return 0;
}

static inline int amf_get_field_value2(GetByteContext *gb, const uint8_t *name, uint8_t *dst, int dst_size) {
    return 0;
}

static inline size_t av_strlcpy(char *dst, const char *src, size_t size) {
    size_t len = strlen(src);
    if (len + 1 < size) {
        memcpy(dst, src, len + 1);
    } else if (size) {
        memcpy(dst, src, size - 1);
        dst[size - 1] = '\0';
    }
    return len;
}

#define FFMIN(a, b) ((a) > (b) ? (b) : (a))