#include <stdint.h>

typedef struct SWFInput {
    // 最小可编译的占位结构体定义
    int dummy;
} SWFInput;

extern int SWFInput_readBits(SWFInput input, int number);