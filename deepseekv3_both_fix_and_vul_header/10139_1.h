#include <stdint.h>
#include <stddef.h>

typedef struct jpc_sizcomp_s {
    uint_fast8_t hsamp;
    uint_fast8_t vsamp;
    unsigned int sgnd;
    unsigned int prec;
} jpc_sizcomp_t;

typedef struct jpc_siz_s {
    uint_fast16_t caps;
    uint_fast32_t width;
    uint_fast32_t height;
    uint_fast32_t xoff;
    uint_fast32_t yoff;
    uint_fast32_t tilewidth;
    uint_fast32_t tileheight;
    uint_fast32_t tilexoff;
    uint_fast32_t tileyoff;
    uint_fast16_t numcomps;
    jpc_sizcomp_t *comps;
} jpc_siz_t;

typedef struct jpc_ms_s {
    struct {
        jpc_siz_t siz;
    } parms;
} jpc_ms_t;

typedef struct jpc_cstate_s jpc_cstate_t;
typedef struct jas_stream_s jas_stream_t;

extern int jpc_getuint8(jas_stream_t *in, uint_fast8_t *val);
extern int jpc_getuint16(jas_stream_t *in, uint_fast16_t *val);
extern int jpc_getuint32(jas_stream_t *in, uint_fast32_t *val);
extern void *jas_alloc2(size_t num_elements, size_t element_size);
extern void jas_free(void *ptr);
extern int jas_stream_eof(jas_stream_t *stream);
extern int jas_eprintf(const char *format, ...);