#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef struct blosc2_schunk {
    int32_t typesize;
} blosc2_schunk;

typedef struct blosc2_dparams {
    struct blosc2_schunk *schunk;
} blosc2_dparams;

typedef enum {
    zfp_type_float,
    zfp_type_double
} zfp_type;

typedef struct zfp_field zfp_field;
typedef struct zfp_stream zfp_stream;
typedef struct bitstream bitstream;

#define ZFP_ERROR_NULL(ptr) if ((ptr) == NULL) return -1
#define BLOSC_UNUSED_PARAM(param) (void)(param)
#define BLOSC2_ERROR_FAILURE -1
#define BLOSC_TRACE_ERROR(fmt, ...)

int blosc2_meta_get(struct blosc2_schunk *sc, const char *name, uint8_t **smeta, int32_t *smeta_len);
void deserialize_meta(uint8_t *smeta, int32_t smeta_len, int8_t *ndim, int64_t *shape, int32_t *chunkshape, int32_t *blockshape);

zfp_stream *zfp_stream_open(void *ptr);
void zfp_stream_close(zfp_stream *stream);
void zfp_stream_set_accuracy(zfp_stream *stream, double tolerance);
void zfp_stream_set_bit_stream(zfp_stream *stream, bitstream *bs);
void zfp_stream_rewind(zfp_stream *stream);

bitstream *stream_open(void *buffer, size_t bytes);
void stream_close(bitstream *stream);

zfp_field *zfp_field_1d(void *ptr, zfp_type type, int nx);
zfp_field *zfp_field_2d(void *ptr, zfp_type type, int nx, int ny);
zfp_field *zfp_field_3d(void *ptr, zfp_type type, int nx, int ny, int nz);
zfp_field *zfp_field_4d(void *ptr, zfp_type type, int nx, int ny, int nz, int nw);
void zfp_field_free(zfp_field *field);

size_t zfp_decompress(zfp_stream *stream, zfp_field *field);