#include <stdint.h>

typedef uint32_t BN_ULONG;
typedef uint64_t BN_ULLONG;

#define BN_LLONG

void mul_add_c(BN_ULONG a, BN_ULONG b, BN_ULONG c1, BN_ULONG c2, BN_ULONG c3);