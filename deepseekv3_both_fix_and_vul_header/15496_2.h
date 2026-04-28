#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct blosc2_schunk blosc2_schunk;

typedef struct {
    blosc2_schunk* schunk;
    int32_t typesize;
} blosc2_cparams;

#define BLOSC_UNUSED_PARAM(x) (void)(x)
#define BLOSC2_ERROR_FAILURE (-1)
#define BLOSC_TRACE_ERROR(...)

#define ZFP_ERROR_NULL(ptr) if ((ptr) == NULL) return BLOSC2_ERROR_FAILURE

typedef enum {
    zfp_type_float,
    zfp_type_double
} zfp_type;

typedef enum {
    zfp_false
} zfp_bool;

typedef struct zfp_field zfp_field;
typedef struct zfp_stream zfp_stream;
typedef struct bitstream bitstream;

zfp_stream* zfp_stream_open(void*);
void zfp_stream_close(zfp_stream*);
void zfp_stream_rewind(zfp_stream*);
size_t zfp_stream_maximum_size(const zfp_stream*, const zfp_field*);
size_t zfp_compress(zfp_stream*, const zfp_field*);
void zfp_stream_set_rate(zfp_stream*, double, zfp_type, int, zfp_bool);
void zfp_stream_set_bit_stream(zfp_stream*, bitstream*);

bitstream* stream_open(void*, size_t);
void stream_close(bitstream*);

zfp_field* zfp_field_1d(void*, zfp_type, size_t);
zfp_field* zfp_field_2d(void*, zfp_type, size_t, size_t);
zfp_field* zfp_field_3d(void*, zfp_type, size_t, size_t, size_t);
zfp_field* zfp_field_4d(void*, zfp_type, size_t, size_t, size_t, size_t);
void zfp_field_free(zfp_field*);

int blosc2_meta_get(blosc2_schunk*, const char*, uint8_t**, int32_t*);
void deserialize_meta(uint8_t*, int32_t, int8_t*, int64_t*, int32_t*, int32_t*);