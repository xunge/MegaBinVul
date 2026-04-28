#include <stdint.h>
#include <stdlib.h>

typedef struct DnnOperand {
    int dims[4];
    int data_type;
    int length;
    float *data;
} DnnOperand;

typedef struct DnnLayerMaximumParams {
    struct {
        float y;
    } val;
} DnnLayerMaximumParams;

#define DNN_ERROR (-1)

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

static inline int calculate_operand_data_length(const DnnOperand *operand) {
    return operand->dims[0] * operand->dims[1] * operand->dims[2] * operand->dims[3] * sizeof(float);
}

static inline int calculate_operand_dims_count(const DnnOperand *operand) {
    return operand->dims[0] * operand->dims[1] * operand->dims[2] * operand->dims[3];
}

void *av_realloc(void *ptr, size_t size);