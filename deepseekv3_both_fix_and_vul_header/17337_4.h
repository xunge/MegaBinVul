#include <stdlib.h>

#define OPENSSL_DH_MAX_MODULUS_BITS 10000
#define DH_FLAG_CACHE_MONT_P 0x01
#define DH_FLAG_NO_EXP_CONSTTIME 0x02
#define CRYPTO_LOCK_DH 0
#define DH_F_GENERATE_KEY 0
#define DH_R_MODULUS_TOO_LARGE 0
#define ERR_R_BN_LIB 0
#define BN_FLG_CONSTTIME 0x04

typedef struct bignum_st {
    int dummy;
} BIGNUM;

typedef struct bn_ctx_st BN_CTX;
typedef struct bn_mont_ctx_st BN_MONT_CTX;

typedef struct DH DH;
typedef struct dh_method dh_method;

struct dh_method {
    int (*bn_mod_exp)(DH *dh, BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);
};

struct DH {
    BIGNUM *p;
    BIGNUM *g;
    BIGNUM *q;
    BIGNUM *pub_key;
    BIGNUM *priv_key;
    int flags;
    int length;
    BN_MONT_CTX *method_mont_p;
    dh_method *meth;
};

void DHerr(int f, int r);
void BN_free(BIGNUM *a);
BIGNUM *BN_new(void);
BN_CTX *BN_CTX_new(void);
void BN_CTX_free(BN_CTX *c);
int BN_num_bits(const BIGNUM *a);
int BN_rand(BIGNUM *rnd, int bits, int top, int bottom);
int BN_rand_range(BIGNUM *rnd, const BIGNUM *range);
int BN_is_zero(const BIGNUM *a);
int BN_is_one(const BIGNUM *a);
void BN_init(BIGNUM *);
void BN_with_flags(BIGNUM *dest, const BIGNUM *b, int flags);
BN_MONT_CTX *BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont, int lock, const BIGNUM *mod, BN_CTX *ctx);