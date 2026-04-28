#include <stdlib.h>
#include <string.h>

typedef struct bignum_st {
    int neg;
    int top;
    unsigned long *d;
} BIGNUM;

typedef struct bn_ctx_st BN_CTX;

#define BN_F_BN_MOD_SQRT 0
#define BN_R_P_IS_NOT_PRIME 0
#define BN_R_NOT_A_SQUARE 0
#define BN_R_TOO_MANY_ITERATIONS 0

#define BN_CTX_start(ctx)
#define BN_CTX_end(ctx)
#define BN_CTX_get(ctx) NULL
#define BN_is_odd(a) 0
#define BN_abs_is_word(a, w) 0
#define BN_is_zero(a) 0
#define BN_is_one(a) 0
#define BN_set_word(a, w) 0
#define BN_is_bit_set(a, n) 0
#define BN_new() NULL
#define BN_free(a)
#define BN_clear_free(a)
#define BN_copy(a, b) NULL
#define BN_nnmod(r, a, m, ctx) 0
#define BN_rshift(r, a, n) 0
#define BN_add_word(a, w) 0
#define BN_mod_exp(r, a, p, m, ctx) 0
#define BN_mod_lshift1_quick(r, a, m) 0
#define BN_mod_sqr(r, a, m, ctx) 0
#define BN_mod_mul(r, a, b, m, ctx) 0
#define BN_sub_word(a, w) 0
#define BN_priv_rand(r, bits, top, bottom) 0
#define BN_num_bits(a) 0
#define BN_ucmp(a, b) 0
#define BN_kronecker(a, b, ctx) 0
#define BN_rshift1(r, a) 0
#define BN_zero(a)
#define BN_one(a) 0
#define BN_cmp(a, b) 0
#define bn_check_top(a)

#define BNerr(f, r)

static int BN_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b) { return 0; }
static int BN_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b) { return 0; }