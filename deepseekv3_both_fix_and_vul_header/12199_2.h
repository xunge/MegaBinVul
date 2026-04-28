#include <stddef.h>

#define OPENSSL_DH_MAX_MODULUS_BITS 10000
#define DH_MIN_MODULUS_BITS 512

typedef struct bignum_st BIGNUM;
typedef struct bn_ctx_st BN_CTX;
typedef struct bn_mont_ctx_st BN_MONT_CTX;
typedef struct crypto_lock_st CRYPTO_RWLOCK;

struct dh_method {
    int (*bn_mod_exp)(struct dh_st *, BIGNUM *, const BIGNUM *, const BIGNUM *,
                      const BIGNUM *, BN_CTX *, BN_MONT_CTX *);
};

struct dh_st {
    BIGNUM *priv_key;
    struct dh_method *meth;
    BN_MONT_CTX *method_mont_p;
    CRYPTO_RWLOCK *lock;
    void *libctx;
    int flags;
    struct {
        BIGNUM *p;
        BIGNUM *q;
    } params;
};

typedef struct dh_st DH;

#define ERR_LIB_DH 0
#define DH_R_MODULUS_TOO_LARGE 0
#define DH_R_Q_TOO_LARGE 0
#define DH_R_MODULUS_TOO_SMALL 0
#define DH_R_NO_PRIVATE_VALUE 0
#define DH_R_INVALID_SECRET 0
#define ERR_R_BN_LIB 0
#define DH_FLAG_CACHE_MONT_P 0
#define BN_FLG_CONSTTIME 0

static inline void ERR_raise(int lib, int reason) {}
static inline int BN_num_bits(const BIGNUM *a) { return 0; }
static inline BN_CTX *BN_CTX_new_ex(void *ctx) { return NULL; }
static inline void BN_CTX_start(BN_CTX *ctx) {}
static inline BIGNUM *BN_CTX_get(BN_CTX *ctx) { return NULL; }
static inline void BN_CTX_end(BN_CTX *ctx) {}
static inline void BN_CTX_free(BN_CTX *ctx) {}
static inline BN_MONT_CTX *BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont, CRYPTO_RWLOCK *lock, const BIGNUM *mod, BN_CTX *ctx) { return NULL; }
static inline void BN_set_flags(BIGNUM *a, int flags) {}
static inline int BN_copy(BIGNUM *to, const BIGNUM *from) { return 0; }
static inline int BN_sub_word(BIGNUM *a, unsigned long w) { return 0; }
static inline int BN_cmp(const BIGNUM *a, const BIGNUM *b) { return 0; }
static inline const BIGNUM *BN_value_one(void) { return NULL; }
static inline int BN_bn2binpad(const BIGNUM *a, unsigned char *to, int tolen) { return 0; }
static inline void BN_clear(BIGNUM *a) {}