#include <stdint.h>
#include <stddef.h>

typedef struct jas_stream_s jas_stream_t;

typedef struct jp2_cdefchan_s {
    uint16_t channo;
    uint16_t type;
    uint16_t assoc;
} jp2_cdefchan_t;

typedef struct {
    uint16_t numchans;
    jp2_cdefchan_t *ents;
} jp2_cdef_t;

typedef struct {
    union {
        jp2_cdef_t cdef;
    } data;
} jp2_box_t;

void *jas_alloc2(size_t num_elements, size_t element_size);
int jp2_getuint16(jas_stream_t *in, uint16_t *val);