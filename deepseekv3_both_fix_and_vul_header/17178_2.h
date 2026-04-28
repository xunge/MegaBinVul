#include <stddef.h>

typedef struct bignum_st {
    int dummy;
} BIGNUM;

typedef struct bn_gencb_st {
    int dummy; 
} BN_GENCB;

typedef struct bn_ctx_st {
    int dummy;
} BN_CTX;

typedef struct rsa_st {
    BIGNUM *n;
    BIGNUM *e;
    BIGNUM *d;
    BIGNUM *p;
    BIGNUM *q;
    BIGNUM *dmp1;
    BIGNUM *dmq1;
    BIGNUM *iqmp;
    int flags;
} RSA;

#define BN_FLG_CONSTTIME 0x04
#define RSA_FLAG_NO_CONSTTIME 0x0001
#define RSA_F_RSA_BUILTIN_KEYGEN 0
#define RSA_R_KEY_SIZE_TOO_SMALL 0
#define ERR_LIB_BN 0
#define BN_R_NO_INVERSE 0

BIGNUM *BN_new(void);
void BN_free(BIGNUM *a);
int BN_set_flags(BIGNUM *a, int flags);
int BN_copy(BIGNUM *to, const BIGNUM *from);
int BN_cmp(const BIGNUM *a, const BIGNUM *b);
int BN_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int BN_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx);
int BN_mod(BIGNUM *rem, const BIGNUM *m, const BIGNUM *d, BN_CTX *ctx);
BIGNUM *BN_mod_inverse(BIGNUM *r, const BIGNUM *a, const BIGNUM *n, BN_CTX *ctx);
int BN_generate_prime_ex(BIGNUM *ret, int bits, int safe, const BIGNUM *add, const BIGNUM *rem, BN_GENCB *cb);
BIGNUM *BN_value_one(void);
void BN_with_flags(BIGNUM *dest, const BIGNUM *b, int flags);

BN_CTX *BN_CTX_new(void);
void BN_CTX_free(BN_CTX *c);
void BN_CTX_start(BN_CTX *ctx);
BIGNUM *BN_CTX_get(BN_CTX *ctx);
void BN_CTX_end(BN_CTX *ctx);

int BN_GENCB_call(BN_GENCB *cb, int a, int b);

void RSAerr(int f, int r);
void ERR_set_mark(void);
void ERR_pop_to_mark(void);
unsigned long ERR_peek_last_error(void);
#define ERR_GET_LIB(l) 0
#define ERR_GET_REASON(l) 0