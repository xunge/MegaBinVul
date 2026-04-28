#include <stddef.h>

typedef struct bignum_st BIGNUM;
typedef struct bn_ctx_st BN_CTX;
typedef struct bn_mont_ctx_st BN_MONT_CTX;

struct dsa_method {
    int (*bn_mod_exp)(struct dsa_st *dsa, BIGNUM *r, BIGNUM *a, const BIGNUM *p,
                     const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);
};

struct dsa_st {
    BIGNUM *p;
    BIGNUM *q;
    BIGNUM *g;
    BIGNUM *priv_key;
    int flags;
    BN_MONT_CTX *method_mont_p;
    void *lock;
    struct dsa_method *meth;
};

typedef struct dsa_st DSA;

#define DSA_F_DSA_SIGN_SETUP 0
#define DSA_R_MISSING_PARAMETERS 0
#define DSA_FLAG_CACHE_MONT_P 1
#define BN_FLG_CONSTTIME (1 << 2)
#define ERR_R_BN_LIB 0

BIGNUM *BN_new(void);
void BN_clear_free(BIGNUM *a);
int BN_set_bit(BIGNUM *a, int n);
int BN_num_bits(const BIGNUM *a);
int BN_is_zero(const BIGNUM *a);
int BN_rand_range(BIGNUM *rnd, const BIGNUM *range);
int BN_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int BN_copy(BIGNUM *a, const BIGNUM *b);
int BN_mod_exp_mont(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, 
                   BN_CTX *ctx, BN_MONT_CTX *m_ctx);
int BN_mod(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx);
void BN_set_flags(BIGNUM *a, int b);
BN_CTX *BN_CTX_new(void);
void BN_CTX_free(BN_CTX *c);
int BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont, void *lock, const BIGNUM *mod, BN_CTX *ctx);
int BN_generate_dsa_nonce(BIGNUM *out, const BIGNUM *q, const BIGNUM *priv_key,
                         const unsigned char *dgst, int dlen, BN_CTX *ctx);

BIGNUM *dsa_mod_inverse_fermat(BIGNUM *k, BIGNUM *q, BN_CTX *ctx);
void DSAerr(int f, int r);