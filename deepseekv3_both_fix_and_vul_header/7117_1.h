#include <stddef.h>

typedef struct bignum_st BIGNUM;
typedef struct bn_ctx_st BN_CTX;

typedef struct ffc_params_st FFC_PARAMS;
struct ffc_params_st {
    const BIGNUM *p;
};

#define FFC_ERROR_PASSED_NULL_PARAM 1
#define FFC_ERROR_PUBKEY_TOO_SMALL 2
#define FFC_ERROR_PUBKEY_TOO_LARGE 4

BN_CTX *BN_CTX_new_ex(void *libctx);
void BN_CTX_free(BN_CTX *c);
void BN_CTX_start(BN_CTX *ctx);
BIGNUM *BN_CTX_get(BN_CTX *ctx);
void BN_CTX_end(BN_CTX *ctx);
int BN_set_word(BIGNUM *a, unsigned long w);
int BN_cmp(const BIGNUM *a, const BIGNUM *b);
BIGNUM *BN_copy(BIGNUM *a, const BIGNUM *b);
int BN_sub_word(BIGNUM *a, unsigned long w);