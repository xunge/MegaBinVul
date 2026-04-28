#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct blosc2_schunk blosc2_schunk;

typedef struct blosc2_cparams {
    blosc2_schunk *schunk;
    int32_t typesize;
} blosc2_cparams;

#define BLOSC_UNUSED_PARAM(x) (void)(x)
#define ZFP_ERROR_NULL(ptr) if ((ptr) == NULL) return BLOSC2_ERROR_FAILURE
#define BLOSC_TRACE_ERROR(...)
#define BLOSC2_ERROR_FAILURE (-1)

typedef enum {
    zfp_type_float,
    zfp_type_double
} zfp_type;

typedef struct zfp_field zfp_field;
typedef struct zfp_stream zfp_stream;
typedef struct bitstream bitstream;

zfp_stream* zfp_stream_open(void*);
void zfp_stream_close(zfp_stream*);
size_t zfp_compress(zfp_stream*, zfp_field*);
size_t zfp_stream_maximum_size(zfp_stream*, zfp_field*);
void zfp_stream_rewind(zfp_stream*);
void zfp_stream_set_bit_stream(zfp_stream*, bitstream*);
void zfp_stream_set_accuracy(zfp_stream*, double);
zfp_field* zfp_field_1d(void*, zfp_type, int);
zfp_field* zfp_field_2d(void*, zfp_type, int, int);
zfp_field* zfp_field_3d(void*, zfp_type, int, int, int);
zfp_field* zfp_field_4d(void*, zfp_type, int, int, int, int);
void zfp_field_free(zfp_field*);

bitstream* stream_open(void*, size_t);
void stream_close(bitstream*);

int blosc2_meta_get(blosc2_schunk*, const char*, uint8_t**, int32_t*);
void deserialize_meta(uint8_t*, int32_t, int8_t*, int64_t*, int32_t*, int32_t*);