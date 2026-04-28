#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef enum {
    PB_WT_VARINT = 0,
    PB_WT_64BIT = 1,
    PB_WT_STRING = 2,
    PB_WT_32BIT = 5
} pb_wire_type_t;

typedef enum {
    PB_HTYPE_REQUIRED,
    PB_HTYPE_OPTIONAL,
    PB_HTYPE_REPEATED,
    PB_HTYPE_ONEOF
} pb_htype_t;

typedef enum {
    PB_LTYPE_VARINT,
    PB_LTYPE_UVARINT,
    PB_LTYPE_SVARINT,
    PB_LTYPE_FIXED32,
    PB_LTYPE_FIXED64,
    PB_LTYPE_BYTES,
    PB_LTYPE_STRING,
    PB_LTYPE_SUBMESSAGE,
    PB_LTYPE_FIXED_LENGTH_BYTES,
    PB_LTYPE_LAST_PACKABLE = PB_LTYPE_FIXED_LENGTH_BYTES
} pb_ltype_t;

typedef struct {
    pb_htype_t htype;
    pb_ltype_t ltype;
} pb_type_t;

typedef struct {
    pb_type_t type;
    uint32_t tag;
    size_t data_size;
    uint32_t array_size;
    const void *ptr;
} pb_field_t;

typedef struct {
    const pb_field_t *pos;
    void *pData;
    void *pSize;
} pb_field_iter_t;

typedef struct {
    size_t bytes_left;
} pb_istream_t;

typedef bool (*pb_decoder_t)(pb_istream_t *stream, const pb_field_t *field, void *dest);

typedef uint8_t pb_size_t;

extern const pb_decoder_t PB_DECODERS[];
#define PB_RETURN_ERROR(stream, msg) (false)
#define PB_LTYPE(type) ((type).ltype)
#define PB_HTYPE(type) ((type).htype)

bool pb_make_string_substream(pb_istream_t *stream, pb_istream_t *substream);
bool pb_close_string_substream(pb_istream_t *stream, pb_istream_t *substream);
void pb_message_set_to_defaults(const pb_field_t *fields, void *dest_struct);

#define checkreturn