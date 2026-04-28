#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    unsigned char Qx[32];
    unsigned char Qy[32];
    unsigned char d[32];
} ECC_KEY_T;

typedef struct {
    unsigned char au32R[32];
    unsigned char au32S[32];
} ECDSA_SIGN_T;

typedef struct {
    unsigned char au32Key0[32];
    unsigned char au32Key1[32];
} PUB_KEY_T;

typedef struct {
    PUB_KEY_T pubkey;
    ECDSA_SIGN_T sign;
} FW_INFO_T;

typedef struct ec_key_st EC_KEY;
typedef struct ec_group_st EC_GROUP;
typedef struct bignum_st BIGNUM;

struct ecdsa_sig_st {
    BIGNUM *r;
    BIGNUM *s;
};
typedef struct ecdsa_sig_st ECDSA_SIG;

#define NID_X9_62_prime256v1 0
#define OPENSSL_VERSION_NUMBER 0

void sha256(unsigned char *input, unsigned int size, unsigned char *output);

EC_KEY *EC_KEY_new(void);
void EC_KEY_free(EC_KEY *key);
EC_GROUP *EC_GROUP_new_by_curve_name(int nid);
void EC_GROUP_free(EC_GROUP *group);
int EC_KEY_set_group(EC_KEY *key, const EC_GROUP *group);
int EC_KEY_set_private_key(EC_KEY *key, const BIGNUM *prv);
int EC_KEY_set_public_key_affine_coordinates(EC_KEY *key, const BIGNUM *x, const BIGNUM *y);
ECDSA_SIG *ECDSA_do_sign(const unsigned char *dgst, int dgst_len, EC_KEY *eckey);
int ECDSA_do_verify(const unsigned char *dgst, int dgst_len, const ECDSA_SIG *sig, EC_KEY *eckey);
BIGNUM *BN_bin2bn(const unsigned char *s, int len, BIGNUM *ret);
void BN_free(BIGNUM *a);
int BN_bn2bin(const BIGNUM *a, unsigned char *to);
void ECDSA_SIG_free(ECDSA_SIG *sig);
void ECDSA_SIG_get0(const ECDSA_SIG *sig, const BIGNUM **pr, const BIGNUM **ps);