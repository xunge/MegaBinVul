#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct pb_istream_t pb_istream_t;
typedef uint8_t pb_size_t;

struct pb_field_t {
    uint32_t type;
    size_t data_size;
};
typedef struct pb_field_t pb_field_t;

struct pb_bytes_array_t {
    pb_size_t size;
    uint8_t bytes[1];
};
typedef struct pb_bytes_array_t pb_bytes_array_t;

#define PB_ATYPE(type) ((type) & 0x0F)
#define PB_ATYPE_POINTER 1
#define PB_ENABLE_MALLOC 1
#define PB_BYTES_ARRAY_T_ALLOCSIZE(size) (sizeof(pb_bytes_array_t) + (size) - 1)
#define PB_SIZE_MAX ((pb_size_t)-1)
#define PB_RETURN_ERROR(stream, msg) (false)

#define checkreturn

bool pb_decode_varint32(pb_istream_t *stream, uint32_t *dest);
bool allocate_field(pb_istream_t *stream, void *dest, size_t data_size, size_t array_size);
bool pb_read(pb_istream_t *stream, uint8_t *buf, size_t count);