#include <stdlib.h>

#define TEE_Malloc(size, flags) calloc(1, (size))
#define TEE_MALLOC_FILL_ZERO 0

enum {
    TEE_SUCCESS = 0,
    TEE_ERROR_OUT_OF_MEMORY = 0xFFFF000C
};

typedef unsigned int TEE_Result;

struct tee_gcm_state {
    // 这里可以添加实际的成员变量
    // 由于示例中没有使用具体成员，暂时留空
};