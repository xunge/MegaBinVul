#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct pb_istream_t pb_istream_t;
typedef struct pb_field_t {
    unsigned type;
    size_t data_size;
} pb_field_t;

#define PB_ATYPE(type) ((type) & 0x0F)
#define PB_ATYPE_POINTER 1
#define PB_ENABLE_MALLOC
#define PB_RETURN_ERROR(stream, msg) (false)
#define checkreturn

bool pb_decode_varint32(pb_istream_t *stream, uint32_t *value);
bool allocate_field(pb_istream_t *stream, void *dest, size_t size, size_t count);
bool pb_read(pb_istream_t *stream, uint8_t *buf, size_t size);