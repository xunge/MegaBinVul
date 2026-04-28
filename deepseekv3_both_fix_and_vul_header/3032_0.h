#include <stdint.h>

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

static inline void bytestream2_init(GetByteContext *gb, const uint8_t *buf, int buf_size)
{
    gb->buffer = buf;
    gb->buffer_start = buf;
    gb->buffer_end = buf + buf_size;
}

static inline unsigned int bytestream2_get_byteu(GetByteContext *gb)
{
    return *gb->buffer++;
}

static inline int bytestream2_get_bytes_left(GetByteContext *gb)
{
    return gb->buffer_end - gb->buffer;
}

static inline void bytestream2_get_bufferu(GetByteContext *gb, uint8_t *dst, int size)
{
    memcpy(dst, gb->buffer, size);
    gb->buffer += size;
}

static inline void bytestream2_skip(GetByteContext *gb, int size)
{
    gb->buffer += size;
}

static inline int bytestream2_tell(GetByteContext *gb)
{
    return (int)(gb->buffer - gb->buffer_start);
}