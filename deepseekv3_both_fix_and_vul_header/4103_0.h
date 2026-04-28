#include <ctype.h>
#include <limits.h>
#include <stdlib.h>

#define BN_BYTES 4

typedef unsigned long BN_ULONG;

struct bignum_st {
    BN_ULONG *d;
    int top;
    int neg;
};

typedef struct bignum_st BIGNUM;

BIGNUM *BN_new(void);
void BN_zero(BIGNUM *a);
int bn_expand(BIGNUM *a, int bits);
void bn_correct_top(BIGNUM *a);
void bn_check_top(const BIGNUM *a);
void BN_free(BIGNUM *a);