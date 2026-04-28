#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BLOSC_UNUSED_PARAM(x) ((void)(x))
#define ZFP_ERROR_NULL(ptr) if ((ptr) == NULL) return BLOSC2_ERROR_FAILURE
#define BLOSC_TRACE_ERROR(...)
#define BLOSC2_ERROR_FAILURE (-1)

#define ZFP_MAX_PREC 64

typedef enum {
    zfp_type_float,
    zfp_type_double
} zfp_type;

typedef struct {
    void *schunk;
    int32_t typesize;
} blosc2_cparams;

typedef struct {
    // zfp field structure
} zfp_field;

typedef struct {
    // zfp stream structure
} zfp_stream;

typedef struct {
    // bitstream structure
} bitstream;

zfp_field* zfp_field_1d(void* ptr, zfp_type type, int size);
zfp_field* zfp_field_2d(void* ptr, zfp_type type, int size1, int size2);
zfp_field* zfp_field_3d(void* ptr, zfp_type type, int size1, int size2, int size3);
zfp_field* zfp_field_4d(void* ptr, zfp_type type, int size1, int size2, int size3, int size4);
void zfp_field_free(zfp_field* field);

zfp_stream* zfp_stream_open(void* ptr);
void zfp_stream_close(zfp_stream* stream);
void zfp_stream_set_precision(zfp_stream* stream, uint prec);
void zfp_stream_set_bit_stream(zfp_stream* stream, bitstream* bs);
void zfp_stream_rewind(zfp_stream* stream);
size_t zfp_stream_maximum_size(zfp_stream* stream, zfp_field* field);
size_t zfp_compress(zfp_stream* stream, zfp_field* field);

bitstream* stream_open(uint8_t* buffer, int size);
void stream_close(bitstream* stream);

int blosc2_meta_get(void* schunk, const char* name, uint8_t** content, int32_t* content_len);
void deserialize_meta(uint8_t* smeta, int32_t smeta_len, int8_t* ndim, int64_t* shape, int32_t* chunkshape, int32_t* blockshape);