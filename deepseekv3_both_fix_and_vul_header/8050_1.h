#include <stdint.h>

struct ByteArray {
    int32_t Get(int32_t index);
    int32_t Length();
    int32_t InternalGet(int32_t index);
};