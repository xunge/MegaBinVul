#include <stdint.h>

typedef int32_t pixman_fixed_t;

#define PIXMAN_EXPORT

#define pixman_fixed_frac(y) ((y) & 0x0000ffff)
#define pixman_fixed_floor(y) ((y) & 0xffff0000)
#define pixman_fixed_to_int(y) ((y) >> 16)
#define pixman_fixed_1 (1 << 16)
#define pixman_fixed_e (1 << (16 - 8))

#define DIV(a, b) ((a) / (b))

#define Y_FRAC_FIRST(n) (pixman_fixed_1 / (2 * (n)))
#define Y_FRAC_LAST(n) (pixman_fixed_1 - Y_FRAC_FIRST(n))
#define STEP_Y_SMALL(n) (pixman_fixed_1 / (4 * (n)))