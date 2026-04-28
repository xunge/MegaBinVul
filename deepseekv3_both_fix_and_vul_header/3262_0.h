#include <stdint.h>
#include <string.h>

static inline int32_t sign_extend(int32_t val, int bits)
{
    int shift = 32 - bits;
    return (val << shift) >> shift;
}

static inline int sign_only(int32_t val)
{
    return (val > 0) - (val < 0);
}