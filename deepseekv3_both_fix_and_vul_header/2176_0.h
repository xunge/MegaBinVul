#include <stdint.h>
#include <sys/time.h>

#define TICK_NSEC ((u32)(1000000000UL / HZ))
#define NSEC_PER_SEC 1000000000UL
#define NSEC_PER_USEC 1000UL
#define HZ 100

typedef uint64_t u64;
typedef uint32_t u32;

static inline u64 div_u64_rem(u64 dividend, u32 divisor, u32 *remainder)
{
    *remainder = dividend % divisor;
    return dividend / divisor;
}