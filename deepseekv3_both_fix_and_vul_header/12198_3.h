#include <stddef.h>

#define OPENSSL_DH_CHECK_MAX_MODULUS_BITS 10000
#define DH_R_MODULUS_TOO_LARGE 100
#define DH_MODULUS_TOO_LARGE 1
#define DH_CHECK_PUBKEY_INVALID 2
#define DH_CHECK_INVALID_Q_VALUE 4
#define ERR_LIB_DH 1

typedef struct bignum_st BIGNUM;

typedef struct dh_params {
    BIGNUM *p;
    BIGNUM *q;
} DH_PARAMS;

typedef struct dh_st {
    DH_PARAMS params;
} DH;

int BN_num_bits(const BIGNUM *a);
int BN_ucmp(const BIGNUM *a, const BIGNUM *b);
void ERR_raise(int lib, int reason);
int ossl_ffc_validate_public_key(const DH *dh, const BIGNUM *pub_key, int *ret);