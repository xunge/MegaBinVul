#include <stdint.h>
#include <stdlib.h>

typedef struct DnnOperand {
    int32_t dims[4];
    int data_type;
    int length;
    float *data;
} DnnOperand;

typedef struct DepthToSpaceParams {
    int block_size;
} DepthToSpaceParams;

static int calculate_operand_data_length(const DnnOperand *op) {
    return op->dims[0] * op->dims[1] * op->dims[2] * op->dims[3] * sizeof(float);
}

void *av_realloc(void *ptr, size_t size);