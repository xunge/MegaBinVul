#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef struct DnnOperand {
    int32_t dims[4];
    int data_type;
    int length;
    float *data;
} DnnOperand;

typedef struct DnnLayerMathUnaryParams {
    int un_op;
} DnnLayerMathUnaryParams;

enum DnnMathUnaryOperation {
    DMUO_ABS,
    DMUO_SIN,
    DMUO_COS,
    DMUO_TAN,
    DMUO_ASIN,
    DMUO_ACOS,
    DMUO_ATAN,
    DMUO_SINH,
    DMUO_COSH,
    DMUO_TANH,
    DMUO_ASINH,
    DMUO_ACOSH,
    DMUO_ATANH
};

#define DNN_ERROR (-1)
#define FFABS(x) ((x) >= 0 ? (x) : -(x))

void *av_realloc(void *ptr, size_t size);
int calculate_operand_data_length(const DnnOperand *operand);
int calculate_operand_dims_count(const DnnOperand *operand);