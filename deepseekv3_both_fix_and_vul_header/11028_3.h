#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned int mat_uint32_t;

struct matvar_internal {
    void* z;
    long datapos;
    void* data;
};

struct matvar_t {
    size_t data_size;
    size_t nbytes;
    void* data;
    char* name;
    int compression;
    struct matvar_internal* internal;
    int class_type;
    int isComplex;
    int isGlobal;
    int isLogical;
    size_t rank;
    size_t* dims;
};

struct mat_t {
    FILE* fp;
    int byteswap;
};

typedef struct mat_t mat_t;
typedef struct matvar_t matvar_t;
typedef void* z_streamp;

#define MAT_COMPRESSION_ZLIB 1
#define MAT_T_MATRIX 0
#define MAT_T_UINT32 0
#define MAT_T_INT32 0
#define MAT_T_INT8 0
#define MAT_F_COMPLEX 0
#define MAT_F_GLOBAL 0
#define MAT_F_LOGICAL 0
#define MAT_C_SPARSE 0
#define MAT_C_OPAQUE 0
#define MAT_C_STRUCT 0
#define MAT_C_CELL 0
#define SIZE_T_FMTSTR "zu"
#define MAX_WBITS 0
#define UINT32_MAX 0xFFFFFFFFU
#define Z_OK 0
#define HAVE_ZLIB 0

enum matio_types {
    MAT_T_UNKNOWN = 0
};

#define CLASS_FROM_ARRAY_FLAGS(flags) 0

static int SafeMulDims(matvar_t *matvar, size_t *nelems) { return 0; }
static int SafeMul(size_t *result, size_t a, size_t b) { return 0; }
static void Mat_Critical(const char *fmt, ...) {}
static matvar_t *Mat_VarCalloc(void) { return NULL; }
static void Mat_VarFree(matvar_t *matvar) {}
static size_t InflateVarTag(mat_t *mat, matvar_t *matvar, mat_uint32_t *buf) { return 0; }
static mat_uint32_t Mat_uint32Swap(mat_uint32_t *x) { return 0; }
static size_t InflateArrayFlags(mat_t *mat, matvar_t *matvar, mat_uint32_t *buf) { return 0; }
static size_t InflateSkip(mat_t *mat, z_streamp z, int nbytes) { return 0; }
static size_t InflateRankDims(mat_t *mat, matvar_t *matvar, mat_uint32_t *buf, size_t bufsize, mat_uint32_t **dims) { return 0; }
static size_t InflateVarName(mat_t *mat, matvar_t *matvar, char *name, mat_uint32_t len) { return 0; }
static size_t ReadNextStructField(mat_t *mat, matvar_t *matvar) { return 0; }
static int Mat_VarRead5(mat_t *mat, matvar_t *matvar) { return 0; }
static char *zError(int err) { return ""; }
static size_t ReadRankDims(mat_t *mat, matvar_t *matvar, enum matio_types type, mat_uint32_t len) { return 0; }