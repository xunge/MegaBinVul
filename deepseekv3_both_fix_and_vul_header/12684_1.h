#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    VALID,
    SAME_CLAMP_TO_EDGE
} PaddingMethod;

typedef enum {
    RELU,
    TANH,
    SIGMOID,
    NONE,
    LEAKY_RELU
} Activation;

typedef struct ConvolutionalParams {
    int32_t kernel_size;
    int32_t input_num;
    int32_t output_num;
    int32_t dilation;
    PaddingMethod padding_method;
    int has_bias;
    Activation activation;
    float *biases;
    float *kernel;
} ConvolutionalParams;

typedef struct DnnOperand {
    int32_t dims[4];
    int32_t data_type;
    int32_t length;
    float *data;
} DnnOperand;

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))
#define FFMIN(a, b) ((a) < (b) ? (a) : (b))
#define CLAMP_TO_EDGE(x, max) ((x) < 0 ? 0 : ((x) >= (max) ? (max) - 1 : (x)))

void *av_realloc(void *ptr, size_t size);
void av_assert0(int condition);

int calculate_operand_data_length(DnnOperand *operand);