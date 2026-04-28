#include <stddef.h>
#include <stdint.h>

typedef struct ssl_st SSL;
typedef struct ssl3_state_st SSL3_STATE;
typedef struct dh_st DH;
typedef struct evp_pkey_st EVP_PKEY;
typedef struct bignum_st BIGNUM;

#define OPENSSL_NO_DH
#define SSL_F_TLS_CONSTRUCT_CKE_DHE 0
#define ERR_R_INTERNAL_ERROR 0
#define SSL_AD_INTERNAL_ERROR 0

static void SSLerr(int a, int b) {}
static EVP_PKEY* ssl_generate_pkey(EVP_PKEY* p) { return NULL; }
static int ssl_derive(SSL* s, EVP_PKEY* a, EVP_PKEY* b) { return 0; }
static DH* EVP_PKEY_get0_DH(EVP_PKEY* p) { return NULL; }
static void EVP_PKEY_free(EVP_PKEY* p) {}
static void DH_get0_key(const DH* dh, const BIGNUM** pub_key, const BIGNUM** priv_key) {}
static int BN_num_bytes(const BIGNUM* a) { return 0; }
static void s2n(int a, unsigned char* b) {}
static int BN_bn2bin(const BIGNUM* a, unsigned char* b) { return 0; }