#include <stdlib.h>

#define OPENSSL_DH_CHECK_MAX_MODULUS_BITS 10000
#define DH_R_MODULUS_TOO_LARGE 100
#define DH_NOT_SUITABLE_GENERATOR 1
#define DH_CHECK_Q_NOT_PRIME 2
#define DH_CHECK_INVALID_Q_VALUE 4
#define DH_CHECK_INVALID_J_VALUE 8
#define DH_CHECK_P_NOT_PRIME 16
#define DH_CHECK_P_NOT_SAFE_PRIME 32
#define NID_undef 0
#define ERR_LIB_DH 0

typedef struct bignum_st BIGNUM;
typedef struct bn_ctx_st BN_CTX;

struct dh_st {
    void *libctx;
    struct {
        BIGNUM *p;
        BIGNUM *q;
        BIGNUM *g;
        BIGNUM *j;
    } params;
};

typedef struct dh_st DH;

int DH_get_nid(const DH *dh);
int DH_check_params(const DH *dh, int *ret);
int BN_num_bits(const BIGNUM *a);
int BN_cmp(const BIGNUM *a, const BIGNUM *b);
BIGNUM *BN_value_one(void);
int BN_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx);
int BN_is_one(const BIGNUM *a);
int BN_check_prime(const BIGNUM *p, BN_CTX *ctx, void *cb);
int BN_div(BIGNUM *dv, BIGNUM *rm, const BIGNUM *a, const BIGNUM *d, BN_CTX *ctx);
int BN_rshift1(BIGNUM *r, const BIGNUM *a);
BN_CTX *BN_CTX_new_ex(void *ctx);
void BN_CTX_start(BN_CTX *ctx);
BIGNUM *BN_CTX_get(BN_CTX *ctx);
void BN_CTX_end(BN_CTX *ctx);
void BN_CTX_free(BN_CTX *ctx);
void ERR_raise(int lib, int reason);