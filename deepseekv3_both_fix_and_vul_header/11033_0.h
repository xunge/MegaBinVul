#include <stdlib.h>
#include <stddef.h>

typedef enum {
    MAT_C_EMPTY,
    MAT_C_CELL,
    MAT_C_STRUCT,
    MAT_C_OBJECT,
    MAT_C_CHAR,
    MAT_C_SPARSE,
    MAT_C_DOUBLE,
    MAT_C_SINGLE,
    MAT_C_INT8,
    MAT_C_UINT8,
    MAT_C_INT16,
    MAT_C_UINT16,
    MAT_C_INT32,
    MAT_C_UINT32,
    MAT_C_INT64,
    MAT_C_UINT64,
    MAT_C_FUNCTION,
    MAT_C_OPAQUE
} matio_classes;

typedef enum {
    MAT_COMPRESSION_NONE,
    MAT_COMPRESSION_ZLIB
} matio_compression;

typedef struct mat_complex_split_t {
    void *Re;
    void *Im;
} mat_complex_split_t;

typedef struct mat_sparse_t {
    size_t *ir;
    size_t *jc;
    void *data;
} mat_sparse_t;

typedef struct matvar_internal {
    size_t num_fields;
    char **fieldnames;
    void *data;
    int id;
    int hdf5_ref;
    char *hdf5_name;
    void *z;
} matvar_internal;

typedef struct matvar_t {
    char *name;
    int class_type;
    size_t *dims;
    void *data;
    int isComplex;
    int mem_conserve;
    matio_compression compression;
    matvar_internal *internal;
} matvar_t;

void ComplexFree(mat_complex_split_t *complex_data);
void SafeMulDims(matvar_t *matvar, size_t *nelems);
void SafeMul(size_t *result, size_t a, size_t b);