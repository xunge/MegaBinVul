#include <stdbool.h>
#include <stddef.h>

typedef struct pb_istream_t pb_istream_t;
typedef unsigned char pb_size_t;

#define PB_ATYPE(type) ((type) & 0x0F)
#define PB_ATYPE_POINTER 4
#define PB_RETURN_ERROR(stream, msg) (false)

typedef struct {
    pb_size_t tag;
    void *pField;
    void *pSize;
    void *pData;
    unsigned type;
} pb_field_iter_t;

bool pb_field_iter_find(pb_field_iter_t *iter, pb_size_t tag);
bool pb_release_single_field(pb_field_iter_t *field);