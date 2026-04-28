#include <time.h>
#include <stdint.h>

#define NSEC_PER_SEC 1000000000L

typedef uint64_t u64;
typedef uint32_t u32;

extern struct timespec sgi_clock_offset;
extern u64 sgi_clock_period;
extern u64 rtc_time(void);
extern u64 div_u64_rem(u64 dividend, u32 divisor, u32 *remainder);