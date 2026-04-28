#include <stdint.h>

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

#define bytestream2_get_le16(gb) ((gb)->buffer += 2, (gb)->buffer[-2] | ((gb)->buffer[-1] << 8))
#define bytestream2_get_le16u(gb) ((gb)->buffer[0] | ((gb)->buffer[1] << 8))
#define bytestream2_get_byte(gb) (*((gb)->buffer++))
#define bytestream2_get_bytes_left(gb) ((gb)->buffer_end - (gb)->buffer)