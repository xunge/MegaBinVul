#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct z_stream_s {
    void *next_in;
    unsigned int avail_in;
    unsigned long total_in;
    void *next_out;
    unsigned int avail_out;
    unsigned long total_out;
    char *msg;
    void *state;
    void *(*zalloc)(void *, unsigned int, unsigned int);
    void (*zfree)(void *, void *);
    void *opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
} z_stream;

typedef z_stream *z_streamp;

typedef struct matvar_internal {
    z_streamp z;
    void *data;
    long datapos;
} matvar_internal;

typedef struct matvar_t {
    size_t data_size;
    size_t nbytes;
    void *data;
    char *name;
    int compression;
    int class_type;
    int isComplex;
    int isGlobal;
    int isLogical;
    int rank;
    size_t *dims;
    matvar_internal *internal;
} matvar_t;

typedef struct mat_t {
    FILE *fp;
    int byteswap;
} mat_t;

#define SIZE_T_FMTSTR "zu"
#define HAVE_ZLIB 0
#define MAT_COMPRESSION_ZLIB 1
#define MAT_T_MATRIX 1
#define MAT_T_UINT32 2
#define MAT_T_INT32 3
#define MAT_T_INT8 4
#define MAT_F_COMPLEX 1
#define MAT_F_GLOBAL 2
#define MAT_F_LOGICAL 4
#define MAT_C_SPARSE 1
#define MAT_C_OPAQUE 2
#define MAT_C_STRUCT 3
#define MAT_C_CELL 4
#define MAT_C_EMPTY 0
#define UINT32_MAX 0xFFFFFFFF
#define MAX_WBITS 15
#define Z_OK 0

enum matio_types {
    MAT_T_UNKNOWN = 0
};

typedef unsigned int mat_uint32_t;

int SafeMulDims(matvar_t *matvar, size_t *nelems);
int SafeMul(size_t *result, size_t a, size_t b);
void Mat_Critical(const char *format, ...);
matvar_t *Mat_VarCalloc(void);
void Mat_VarFree(matvar_t *matvar);
size_t InflateVarTag(mat_t *mat, matvar_t *matvar, mat_uint32_t *buf);
mat_uint32_t Mat_uint32Swap(mat_uint32_t *x);
size_t InflateArrayFlags(mat_t *mat, matvar_t *matvar, mat_uint32_t *buf);
size_t InflateSkip(mat_t *mat, z_streamp z, int nbytes);
size_t InflateRankDims(mat_t *mat, matvar_t *matvar, mat_uint32_t *buf, size_t buf_size, mat_uint32_t **dims);
size_t InflateVarName(mat_t *mat, matvar_t *matvar, char *name, mat_uint32_t len);
size_t ReadNextStructField(mat_t *mat, matvar_t *matvar);
int Mat_VarRead5(mat_t *mat, matvar_t *matvar);
char *zError(int err);
size_t ReadRankDims(mat_t *mat, matvar_t *matvar, enum matio_types type, mat_uint32_t size);

#define CLASS_FROM_ARRAY_FLAGS(flags) ((flags) >> 8 & 0xFF)