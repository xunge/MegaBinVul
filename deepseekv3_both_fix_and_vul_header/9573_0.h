#include <stdint.h>

typedef uint32_t BN_ULONG;
typedef uint64_t BN_ULLONG;

#define BN_LLONG

#define mul_add_c(a,b,c0,c1,c2) \
    do { \
        BN_ULONG lo, hi; \
        BN_ULLONG t = (BN_ULLONG)(a) * (b); \
        lo = (BN_ULONG)t; \
        hi = (BN_ULONG)(t >> 32); \
        c0 += lo; \
        hi += (c0 < lo) ? 1 : 0; \
        c1 += hi; \
        c2 += (c1 < hi) ? 1 : 0; \
    } while(0)