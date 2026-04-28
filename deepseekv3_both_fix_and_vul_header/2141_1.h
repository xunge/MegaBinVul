#include <stdint.h>
#include <string.h>

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

#define bytestream2_get_le16(gb) ((gb)->buffer += 2, (gb)->buffer[-2] | ((gb)->buffer[-1] << 8))
#define bytestream2_get_le16u(gb) bytestream2_get_le16(gb)
#define bytestream2_get_byte(gb) (*(gb)->buffer++)
#define bytestream2_peek_byte(gb) (*(gb)->buffer)
#define bytestream2_get_bytes_left(gb) ((int)((gb)->buffer_end - (gb)->buffer))
#define bytestream2_get_buffer(gb, dst, size) (memcpy(dst, (gb)->buffer, size), (gb)->buffer += size, (int)(size))

static inline void bytestream_put_le16(uint8_t **dst, uint16_t val) {
    *(*dst)++ = val;
    *(*dst)++ = val >> 8;
}