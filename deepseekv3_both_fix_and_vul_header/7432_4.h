#include <stdlib.h>
#include <string.h>

typedef struct bignum_st {
    int neg;
    int top;
    unsigned long *d;
    int max;
    int flags;
} BIGNUM;

typedef struct bn_ctx_st BN_CTX;

#define BN_R_P_IS_NOT_PRIME 100
#define BN_R_NOT_A_SQUARE 101
#define BN_R_TOO_MANY_ITERATIONS 102
#define ERR_LIB_BN 3

/* Remove conflicting macros */
#undef BN_add
#undef BN_sub

/* Function declarations */
int BN_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int BN_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);

/* Other macros */
#define BN_num_bits(a) 0
#define BN_is_zero(a) 0
#define BN_is_one(a) 0
#define BN_is_odd(a) 0
#define BN_abs_is_word(a,w) 0
#define BN_is_bit_set(a,n) 0
#define BN_set_word(a,w) 0
#define BN_new() NULL
#define BN_free(a) 
#define BN_clear_free(a)
#define BN_copy(a,b) NULL
#define BN_nnmod(r,a,b,ctx) 0
#define BN_mod_exp(r,a,p,m,ctx) 0
#define BN_mod_sqr(r,a,m,ctx) 0
#define BN_mod_mul(r,a,b,m,ctx) 0
#define BN_rshift(r,a,n) 0
#define BN_rshift1(r,a) 0
#define BN_add_word(a,w) 0
#define BN_sub_word(a,w) 0
#define BN_mod_lshift1_quick(r,a,m) 0
#define BN_ucmp(a,b) 0
#define BN_kronecker(a,b,ctx) 0
#define BN_priv_rand_ex(r,bits,top,bottom,ctx,flags) 0
#define BN_zero(a)
#define BN_one(a) 0
#define BN_cmp(a,b) 0
#define bn_check_top(a)

#define ERR_raise(lib,reason)

BN_CTX *BN_CTX_new(void);
void BN_CTX_free(BN_CTX *c);
void BN_CTX_start(BN_CTX *ctx);
BIGNUM *BN_CTX_get(BN_CTX *ctx);
void BN_CTX_end(BN_CTX *ctx);

/* Function implementations */
int BN_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b) { return 0; }
int BN_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b) { return 0; }