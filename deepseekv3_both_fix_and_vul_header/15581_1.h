#include <stdint.h>
#include <string.h>

typedef uint32_t u32;
typedef uint64_t u64;

static inline void put_unaligned(u64 val, u64 *p)
{
    memcpy(p, &val, sizeof(val));
}