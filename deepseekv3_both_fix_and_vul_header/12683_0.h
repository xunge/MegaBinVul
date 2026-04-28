#include <stdint.h>
#include <stdlib.h>

typedef enum {
    DMBO_SUB,
    DMBO_ADD,
    DMBO_MUL,
    DMBO_REALDIV,
    DMBO_MINIMUM
} DnnMathBinaryOperation;

typedef struct DnnOperand {
    int32_t dims[4];
    int data_type;
    int length;
    float *data;
} DnnOperand;

typedef struct DnnLayerMathBinaryParams {
    DnnMathBinaryOperation bin_op;
    float v;
    int input0_broadcast;
    int input1_broadcast;
} DnnLayerMathBinaryParams;

#define DNN_ERROR (-1)
#define FFMIN(a, b) ((a) < (b) ? (a) : (b))

extern int calculate_operand_data_length(const DnnOperand *op);
extern int calculate_operand_dims_count(const DnnOperand *op);
extern void *av_realloc(void *ptr, size_t size);