#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct mat_t mat_t;
typedef struct matvar_t matvar_t;
typedef unsigned int mat_uint32_t;

#define MAT_COMPRESSION_ZLIB 1
#define MAT_T_INT32 0
#define MAT_T_INT8 0
#define MAT_T_MATRIX 0
#define MAT_T_UINT32 0
#define MAT_C_SPARSE 0
#define MAT_C_STRUCT 0
#define MAT_C_CELL 0
#define MAT_C_OPAQUE 0
#define MAT_F_COMPLEX 0
#define MAT_F_GLOBAL 0
#define MAT_F_LOGICAL 0
#define SIZE_T_FMTSTR ""

struct matvar_t {
    int compression;
    size_t data_size;
    size_t nbytes;
    void *data;
    struct {
        size_t num_fields;
        char **fieldnames;
        void *z;
        long datapos;
        void *data;
    } *internal;
    int class_type;
    int isComplex;
    int isGlobal;
    int isLogical;
    int rank;
    size_t *dims;
    char *name;
};

struct mat_t {
    int byteswap;
    void *fp;
};

enum matio_types {
    MAT_T_UNKNOWN = 0
};

#define CLASS_FROM_ARRAY_FLAGS(x) 0

static int SafeMulDims(matvar_t *matvar, size_t *nelems) { return 0; }
static int SafeMul(size_t *result, size_t a, size_t b) { return 0; }
static void Mat_Critical(const char *fmt, ...) {}
static size_t InflateVarTag(mat_t *mat, matvar_t *matvar, mat_uint32_t *buf) { return 0; }
static mat_uint32_t Mat_uint32Swap(mat_uint32_t *x) { return 0; }
static size_t InflateVarName(mat_t *mat, matvar_t *matvar, char *ptr, size_t len) { return 0; }
static void SetFieldNames(matvar_t *matvar, char *ptr, size_t nfields, mat_uint32_t fieldname_size) {}
static matvar_t *Mat_VarCalloc(void) { return NULL; }
static size_t InflateArrayFlags(mat_t *mat, matvar_t *matvar, mat_uint32_t *buf) { return 0; }
static size_t InflateSkip(mat_t *mat, void *z, size_t nbytes) { return 0; }
static size_t InflateRankDims(mat_t *mat, matvar_t *matvar, mat_uint32_t *buf, size_t bufsize, mat_uint32_t **dims) { return 0; }
static int Mat_VarRead5(mat_t *mat, matvar_t *matvar) { return 0; }
static void Mat_VarFree(matvar_t *matvar) {}
static size_t ReadNextCell(mat_t *mat, matvar_t *matvar) { return 0; }
static size_t ReadRankDims(mat_t *mat, matvar_t *matvar, enum matio_types type, mat_uint32_t len) { return 0; }