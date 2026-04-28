#include <stddef.h>
#include <stdlib.h>

typedef struct bignum_st BIGNUM;
typedef struct bn_ctx_st BN_CTX;

#define BN_BITS2 64
#define BN_MASK2 (0xffffffffffffffffUL)
#define BN_DEBUG 1

typedef unsigned long BN_ULONG;

struct bignum_st {
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

void BN_CTX_start(BN_CTX *ctx);
void BN_CTX_end(BN_CTX *ctx);
BIGNUM *BN_CTX_get(BN_CTX *ctx);
int BN_GF2m_mod(BIGNUM *r, const BIGNUM *a, const BIGNUM *p);
int BN_is_zero(const BIGNUM *a);
int BN_copy(BIGNUM *to, const BIGNUM *from);
int BN_num_bits(const BIGNUM *a);
void bn_wexpand(BIGNUM *a, int words);
void bn_correct_top(BIGNUM *a);
int BN_num_bits_word(BN_ULONG w);
void bn_check_top(const BIGNUM *a);