#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct mat_t mat_t;
typedef struct matvar_t matvar_t;
typedef struct matvar_internal matvar_internal;

typedef int32_t mat_int32_t;
typedef uint32_t mat_uint32_t;

enum matio_types {
    MAT_T_COMPRESSED,
    MAT_T_MATRIX,
    MAT_T_UINT32,
    MAT_T_INT32,
    MAT_T_INT8,
    MAT_T_MATRIX_OPAQUE
};

enum matio_classes {
    MAT_C_SPARSE,
    MAT_C_STRUCT,
    MAT_C_CELL,
    MAT_C_OPAQUE,
    MAT_C_FUNCTION
};

enum matio_flags {
    MAT_F_COMPLEX,
    MAT_F_GLOBAL,
    MAT_F_LOGICAL
};

#define CLASS_FROM_ARRAY_FLAGS(flags) ((flags) >> 8 & 0xFF)
#define MAT_COMPRESSION_ZLIB 1
#define HAVE_ZLIB 0
#define Z_OK 0

struct z_stream_s {
    void* next_in;
    unsigned avail_in;
    unsigned total_in;
    void* next_out;
    unsigned avail_out;
    unsigned total_out;
    char* msg;
    void* state;
    void* zalloc;
    void* zfree;
    void* opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
};
typedef struct z_stream_s z_stream;
typedef z_stream* z_streamp;

struct matvar_internal {
    z_streamp z;
    size_t datapos;
    size_t avail_in;
};

struct matvar_t {
    int class_type;
    int isComplex;
    int isGlobal;
    int isLogical;
    size_t nbytes;
    size_t rank;
    size_t *dims;
    char *name;
    int compression;
    matvar_internal *internal;
};

struct mat_t {
    FILE *fp;
    int byteswap;
    char *filename;
};

matvar_t *Mat_VarCalloc(void);
void Mat_VarFree(matvar_t *matvar);
void Mat_Critical(const char *format, ...);
int Mat_int32Swap(mat_int32_t *a);
int Mat_uint32Swap(mat_uint32_t *a);
long InflateVarTag(mat_t *mat, matvar_t *matvar, mat_uint32_t *uncomp_buf);
long InflateArrayFlags(mat_t *mat, matvar_t *matvar, mat_uint32_t *uncomp_buf);
long InflateRankDims(mat_t *mat, matvar_t *matvar, mat_uint32_t *uncomp_buf, size_t bufsize, mat_uint32_t **dims);
long InflateVarName(mat_t *mat, matvar_t *matvar, char *name, mat_uint32_t len_pad);
size_t ReadRankDims(mat_t *mat, matvar_t *matvar, enum matio_types type, mat_uint32_t nBytes);
void ReadNextStructField(mat_t *mat, matvar_t *matvar);
void ReadNextCell(mat_t *mat, matvar_t *matvar);
void ReadNextFunctionHandle(mat_t *mat, matvar_t *matvar);