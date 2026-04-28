#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct blosc2_schunk {
    int32_t typesize;
} blosc2_schunk;

typedef struct {
    blosc2_schunk *schunk;
} blosc2_dparams;

typedef enum {
    zfp_type_float,
    zfp_type_double
} zfp_type;

typedef enum {
    zfp_false = 0,
    zfp_true = 1
} zfp_bool;

typedef struct zfp_field zfp_field;
typedef struct zfp_stream zfp_stream;
typedef struct bitstream bitstream;

#define BLOSC2_ERROR_FAILURE (-1)
#define BLOSC_UNUSED_PARAM(x) (void)(x)
#define ZFP_ERROR_NULL(ptr) if ((ptr) == NULL) return BLOSC2_ERROR_FAILURE
#define BLOSC_TRACE_ERROR(fmt, ...)

zfp_field* zfp_field_1d(void* data, zfp_type type, int size);
zfp_field* zfp_field_2d(void* data, zfp_type type, int size1, int size2);
zfp_field* zfp_field_3d(void* data, zfp_type type, int size1, int size2, int size3);
zfp_field* zfp_field_4d(void* data, zfp_type type, int size1, int size2, int size3, int size4);
void zfp_field_free(zfp_field* field);
zfp_stream* zfp_stream_open(void* buffer);
void zfp_stream_close(zfp_stream* stream);
void zfp_stream_set_rate(zfp_stream* stream, double rate, zfp_type type, int dims, zfp_bool wra);
bitstream* stream_open(void* buffer, size_t bytes);
void stream_close(bitstream* stream);
void zfp_stream_set_bit_stream(zfp_stream* stream, bitstream* bs);
void zfp_stream_rewind(zfp_stream* stream);
size_t zfp_decompress(zfp_stream* stream, zfp_field* field);
int blosc2_meta_get(blosc2_schunk* sc, const char* name, uint8_t** content, int32_t* content_len);
void deserialize_meta(uint8_t* smeta, int32_t smeta_len, int8_t* ndim, int64_t* shape, int32_t* chunkshape, int32_t* blockshape);