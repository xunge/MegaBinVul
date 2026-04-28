#include <stddef.h>

typedef struct bignum_st BIGNUM;
typedef struct bn_ctx_st BN_CTX;
typedef struct bn_mont_ctx_st BN_MONT_CTX;
typedef struct crypto_lock_st CRYPTO_RWLOCK;

struct dsa_st {
    BIGNUM *p;
    BIGNUM *q;
    BIGNUM *g;
    BIGNUM *priv_key;
    unsigned long flags;
    CRYPTO_RWLOCK *lock;
    BN_MONT_CTX *method_mont_p;
    struct dsa_method *meth;
};

typedef struct dsa_st DSA;

struct dsa_method {
    int (*bn_mod_exp)(DSA *dsa, BIGNUM *r, BIGNUM *a, const BIGNUM *p,
                     const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);
};

#define DSA_F_DSA_SIGN_SETUP 0
#define DSA_R_MISSING_PARAMETERS 0
#define ERR_R_BN_LIB 0
#define BN_FLG_CONSTTIME (1 << 2)
#define DSA_FLAG_CACHE_MONT_P (1 << 0)

BIGNUM *BN_new(void);
void BN_clear_free(BIGNUM *a);
int BN_set_bit(BIGNUM *a, int n);
int BN_num_bits(const BIGNUM *a);
int BN_generate_dsa_nonce(BIGNUM *out, const BIGNUM *q, const BIGNUM *priv,
                         const unsigned char *dgst, int dlen, BN_CTX *ctx);
int BN_priv_rand_range(BIGNUM *r, const BIGNUM *range);
int BN_is_zero(const BIGNUM *a);
void BN_set_flags(BIGNUM *a, int flags);
int BN_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int BN_copy(BIGNUM *to, const BIGNUM *from);
int BN_mod_exp_mont(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                   const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *mont);
int BN_mod(BIGNUM *rem, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx);
BIGNUM *dsa_mod_inverse_fermat(const BIGNUM *k, const BIGNUM *q, BN_CTX *ctx);
BN_CTX *BN_CTX_new(void);
void BN_CTX_free(BN_CTX *c);
int BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont, CRYPTO_RWLOCK *lock,
                          const BIGNUM *mod, BN_CTX *ctx);
void DSAerr(int function, int reason);