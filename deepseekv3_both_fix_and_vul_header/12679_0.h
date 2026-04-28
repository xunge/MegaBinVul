#include <stdint.h>
#include <string.h>

typedef enum DNNReturnType {
    DNN_SUCCESS,
    DNN_ERROR
} DNNReturnType;

typedef enum DnnOperandType {
    DOT_INPUT
} DnnOperandType;

typedef struct DnnOperand {
    char *name;
    DnnOperandType type;
    int32_t dims[4];
    void *data;
    size_t length;
} DnnOperand;

typedef struct DNNData {
    int height;
    int width;
    int channels;
    void *data;
} DNNData;

typedef struct ConvolutionalNetwork {
    int layers_num;
    int operands_num;
    DnnOperand *operands;
    uint32_t nb_output;
    uint32_t *output_indexes;
} ConvolutionalNetwork;

void *av_malloc(size_t size);
void *av_mallocz_array(size_t nmemb, size_t size);
void av_freep(void *ptr);
size_t calculate_operand_data_length(DnnOperand *oprd);