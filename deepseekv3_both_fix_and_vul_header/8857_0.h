#include <stdint.h>

#define MAX_LOOPS 20
#define silk_assert(cond) ((void)0)
#define silk_RSHIFT(a, shift) ((a) >> (shift))
#define silk_RSHIFT_ROUND(a, shift) (((a) + (1 << ((shift) - 1))) >> (shift))
#define silk_LIMIT_32(a, min, max) ((a) < (min) ? (min) : (a) > (max) ? (max) : (a))
#define silk_max_int(a, b) ((a) > (b) ? (a) : (b))
#define silk_min_int(a, b) ((a) < (b) ? (a) : (b))

typedef int16_t opus_int16;
typedef int32_t opus_int32;
typedef int opus_int;

void silk_insertion_sort_increasing_all_values_int16(opus_int16 *a, opus_int n);