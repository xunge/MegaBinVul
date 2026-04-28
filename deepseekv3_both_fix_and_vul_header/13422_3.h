#include <stdint.h>
#include <stdlib.h>

#define override 
#define const
#define llvm_unreachable(msg) abort()

struct dummy_class {
    const uint8_t *(*getBytecode)(uint32_t);
};