#include <stdlib.h>
#include <string.h>

typedef struct ssl_st SSL;
typedef struct ssl3_state_st SSL3_STATE;
typedef struct evp_pkey_st EVP_PKEY;

struct ssl_st {
    SSL3_STATE *s3;
};

struct ssl3_state_st {
    EVP_PKEY *peer_tmp;
};

#define OPENSSL_NO_EC
#define SSL_F_TLS_CONSTRUCT_CKE_ECDHE 0
#define ERR_R_INTERNAL_ERROR 0
#define ERR_R_EVP_LIB 0
#define ERR_R_EC_LIB 0
#define SSL_AD_INTERNAL_ERROR 0

static void SSLerr(int a, int b) {}
static EVP_PKEY *ssl_generate_pkey(EVP_PKEY *skey) { return NULL; }
static int ssl_derive(SSL *s, EVP_PKEY *ckey, EVP_PKEY *skey) { return 0; }
static int EVP_PKEY_get1_tls_encodedpoint(EVP_PKEY *ckey, unsigned char **p) { return 0; }
static void EVP_PKEY_free(EVP_PKEY *pkey) {}
static void OPENSSL_free(void *p) {}