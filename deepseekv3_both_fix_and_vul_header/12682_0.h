#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct DnnOperand {
    int32_t dims[4];
    int data_type;
    int length;
    float *data;
} DnnOperand;

typedef struct LayerPadParams {
    int32_t paddings[4][2];
    int mode;
    float constant_values;
} LayerPadParams;

enum {
    LPMP_CONSTANT,
    // Add other mode values if needed
};

static int before_get_buddy(int pos, int paddings, int mode);
static int after_get_buddy(int pos, int size, int mode);
static int calculate_operand_data_length(const DnnOperand *operand);
void *av_realloc(void *ptr, size_t size);