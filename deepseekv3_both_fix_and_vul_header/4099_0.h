#include <stddef.h>

typedef unsigned long BN_ULONG;

struct bignum_st {
    BN_ULONG *d;
    int top;
};
typedef struct bignum_st BIGNUM;