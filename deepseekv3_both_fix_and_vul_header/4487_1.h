#include <stdlib.h>
#include <string.h>

typedef struct bignum_st BIGNUM;
typedef struct bn_ctx_st BN_CTX;
typedef struct rsa_st {
    BIGNUM *n;
    BIGNUM *e;
    BIGNUM *d;
    BIGNUM *p;
    BIGNUM *q;
    BIGNUM *dmp1;
    BIGNUM *dmq1;
    BIGNUM *iqmp;
} RSA;

BIGNUM *BN_new(void);
void BN_free(BIGNUM *a);
int BN_set_bit(BIGNUM *a, int n);
int BN_set_word(BIGNUM *a, unsigned long w);
int BN_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int BN_gcd(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx);
int BN_is_one(const BIGNUM *a);
int BN_cmp(const BIGNUM *a, const BIGNUM *b);
int BN_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx);
BIGNUM *BN_mod_inverse(BIGNUM *r, const BIGNUM *a, const BIGNUM *n, BN_CTX *ctx);
int BN_mod(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx);
BIGNUM *BN_value_one(void);
BIGNUM *BN_generate_prime(BIGNUM *ret, int bits, int safe, const BIGNUM *add, const BIGNUM *rem, void (*callback)(int,int,void*), void *cb_arg);

BN_CTX *BN_CTX_new(void);
void BN_CTX_free(BN_CTX *c);
void BN_CTX_start(BN_CTX *ctx);
BIGNUM *BN_CTX_get(BN_CTX *ctx);
void BN_CTX_end(BN_CTX *ctx);

RSA *RSA_new(void);
void RSA_free(RSA *rsa);

void RSAerr(int func, int reason);
#define RSA_F_RSA_GENERATE_KEY 0
#define ERR_LIB_BN 0