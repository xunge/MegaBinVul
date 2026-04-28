#include <stdlib.h>

#define TEE_Malloc(size, flags) calloc(1, size)
#define TEE_MALLOC_FILL_ZERO 0

enum {
    TEE_SUCCESS = 0,
    TEE_ERROR_OUT_OF_MEMORY = 0xFFFF000C
};

typedef unsigned int TEE_Result;

struct tee_ccm_state {
    // 这里可以添加实际需要的成员
};