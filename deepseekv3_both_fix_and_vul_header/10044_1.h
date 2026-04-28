#include <stdint.h>
#include <stddef.h>

typedef struct jas_stream_s jas_stream_t;

typedef struct {
    unsigned int numcmpts;
    uint_fast8_t *bpcs;
} jp2_bpcc_t;

typedef struct {
    unsigned long datalen;
    union {
        jp2_bpcc_t bpcc;
    } data;
} jp2_box_t;

extern void *jas_alloc2(size_t num_elements, size_t element_size);
extern int jp2_getuint8(jas_stream_t *in, uint_fast8_t *val);