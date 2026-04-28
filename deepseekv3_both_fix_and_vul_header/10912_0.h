#include <stdint.h>
#include <math.h>

#define GET_LDOUBLE_WORDS(se, i0, i1, x) \
  do {                                    \
    uint64_t __lx = *(uint64_t*)&x;       \
    (i1) = __lx;                          \
    (i0) = (__lx >> 32);                  \
    (se) = (i0 >> 16) & 0x7fff;           \
  } while (0)

extern int __kernel_rem_pio2(double*, double*, int, int, int, const int32_t*);
extern const int32_t two_over_pi[];