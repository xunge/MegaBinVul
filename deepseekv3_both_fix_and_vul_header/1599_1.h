#include <stdlib.h>

struct tee_obj {
    // 添加至少一个成员使结构体完整
    int dummy;
};

void *TEE_Malloc(size_t size, unsigned int flags);
#define TEE_MALLOC_FILL_ZERO 0