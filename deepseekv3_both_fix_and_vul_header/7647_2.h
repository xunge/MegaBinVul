#include <stdlib.h>

typedef struct mat_t mat_t;
typedef struct matvar_t matvar_t;

struct matvar_t {
    void *data;
    size_t data_size;
    size_t nbytes;
};

static int Mat_MulDims(matvar_t *matvar, size_t *nelems);
static int Mul(size_t *result, size_t a, size_t b);
static matvar_t *Mat_VarReadNextInfo(mat_t *mat);