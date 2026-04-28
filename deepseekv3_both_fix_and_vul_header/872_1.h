#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct mat_t mat_t;
typedef struct matvar_t matvar_t;
typedef struct matvar_internal matvar_internal;
typedef int mat_int32_t;
typedef unsigned int mat_uint32_t;
typedef unsigned char mat_uint8_t;

enum {
    MAT_T_DOUBLE,
    MAT_T_SINGLE,
    MAT_T_INT32,
    MAT_T_INT16,
    MAT_T_UINT16,
    MAT_T_UINT8
};

enum {
    MAT_C_DOUBLE,
    MAT_C_CHAR,
    MAT_C_SPARSE
};

struct matvar_internal {
    long datapos;
};

struct matvar_t {
    int data_type;
    int class_type;
    size_t rank;
    size_t *dims;
    int isComplex;
    char *name;
    matvar_internal *internal;
};

struct mat_t {
    FILE *fp;
    int byteswap;
};

matvar_t *Mat_VarCalloc(void);
void Mat_VarFree(matvar_t *matvar);
int Mat_int32Swap(mat_int32_t *a);
size_t Mat_SizeOf(int data_type);
int SafeMulDims(matvar_t *matvar, size_t *size);
void Mat_Critical(const char *msg);