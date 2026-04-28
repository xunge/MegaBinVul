#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

typedef unsigned long BN_ULONG;

#define INT_MAX 2147483647
#define BN_DEC_NUM 19
#define BN_DEC_CONV 10000000000000000000UL

struct bignum_st {
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

BIGNUM *BN_new(void);
void BN_free(BIGNUM *a);
void BN_zero(BIGNUM *a);
int bn_expand(BIGNUM *a, int bits);
int BN_mul_word(BIGNUM *a, BN_ULONG w);
int BN_add_word(BIGNUM *a, BN_ULONG w);
void bn_correct_top(BIGNUM *a);
void bn_check_top(const BIGNUM *a);