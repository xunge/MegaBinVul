#include <stdbool.h>
#include <stddef.h>

typedef enum {
    PB_WT_VARINT = 0,
    PB_WT_64BIT = 1,
    PB_WT_STRING = 2,
    PB_WT_32BIT = 5
} pb_wire_type_t;

typedef enum {
    PB_LTYPE_VARINT,
    PB_LTYPE_SVARINT,
    PB_LTYPE_FIXED32,
    PB_LTYPE_FIXED64,
    PB_LTYPE_BYTES,
    PB_LTYPE_STRING,
    PB_LTYPE_SUBMESSAGE,
    PB_LTYPE_FIXED_LENGTH_BYTES,
    PB_LTYPE_LAST_PACKABLE = PB_LTYPE_FIXED_LENGTH_BYTES
} pb_ltype_t;

typedef enum {
    PB_HTYPE_REQUIRED,
    PB_HTYPE_OPTIONAL,
    PB_HTYPE_REPEATED,
    PB_HTYPE_ONEOF
} pb_htype_t;

typedef struct {
    pb_ltype_t ltype;
    pb_htype_t htype;
    unsigned tag;
    size_t data_size;
} pb_field_t;

typedef struct {
    const pb_field_t *pos;
    void *pData;
    void *pSize;
} pb_field_iter_t;

typedef struct {
    const char *errmsg;
    size_t bytes_left;
} pb_istream_t;

typedef bool (*pb_decoder_t)(pb_istream_t *stream, const pb_field_t *field, void *dest);

#define PB_DECODERS {NULL}
#define PB_LTYPE(type) ((type).ltype)
#define PB_HTYPE(type) ((type).htype)
#define PB_SIZE_MAX ((pb_size_t)-1)
#define PB_UNUSED(x) (void)(x)
#define PB_RETURN_ERROR(stream, msg) (stream->errmsg = (msg), false)

typedef unsigned int pb_size_t;
typedef pb_field_t pb_type_t;

extern bool pb_make_string_substream(pb_istream_t *stream, pb_istream_t *substream);
extern bool pb_close_string_substream(pb_istream_t *stream, pb_istream_t *substream);
extern bool allocate_field(pb_istream_t *stream, void *pData, size_t size, size_t count);
extern void initialize_pointer_field(void *pItem, pb_field_iter_t *iter);
extern void pb_release_single_field(pb_field_iter_t *iter);

#define checkreturn