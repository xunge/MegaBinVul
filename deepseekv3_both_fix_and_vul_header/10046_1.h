#include <stdint.h>
#include <stddef.h>

typedef struct jas_stream_s jas_stream_t;

typedef struct {
    uint_fast16_t numlutents;
    uint_fast8_t numchans;
    uint_fast8_t *bpc;
    int_fast32_t *lutdata;
} jp2_pclr_t;

typedef struct {
    union {
        jp2_pclr_t pclr;
    } data;
} jp2_box_t;

extern int jp2_getuint16(jas_stream_t *in, uint_fast16_t *val);
extern int jp2_getuint8(jas_stream_t *in, uint_fast8_t *val);
extern int jp2_getint(jas_stream_t *in, int sgnd, int prec, int_fast32_t *val);
extern void *jas_alloc2(size_t num_elements, size_t element_size);