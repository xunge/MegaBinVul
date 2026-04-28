#include <stdlib.h>
#include <string.h>

#define OPENSSL_NO_RSA
#define OPENSSL_NO_DH 
#define OPENSSL_NO_ECDH
#define OPENSSL_NO_PSK
#define OPENSSL_NO_SRP

#define EVP_MAX_MD_SIZE 64
#define PSK_MAX_IDENTITY_LEN 128
#define SSL3_RANDOM_SIZE 32

#define SSL3_ST_CR_KEY_EXCH_A 0x120
#define SSL3_ST_CR_KEY_EXCH_B 0x121  
#define SSL3_MT_SERVER_KEY_EXCHANGE 12
#define SSL3_AL_FATAL 2
#define SSL_ST_ERR 1

typedef struct ssl_st {
    const struct ssl_method_st *method;
    struct ssl_ctx_st *ctx;
    struct ssl_session_st *session;
    struct ssl3_state_st *s3;
    struct srp_ctx_st *srp_ctx;
    int state;
    int max_cert_list;
    unsigned char init_msg[1];
} SSL;

typedef struct ssl_method_st {
    int (*ssl_get_message)(SSL *s, int st1, int st2, int mt, long max, int *ok);
} SSL_METHOD;

typedef struct ssl_ctx_st {
    void *md5;
    void *sha1;
    char *psk_identity_hint;
} SSL_CTX;

typedef struct ssl_session_st {
    struct ssl_sess_cert_st *sess_cert;
    char *psk_identity_hint;
} SSL_SESSION;

typedef struct ssl_cipher_st {
    long algorithm_mkey;
    long algorithm_auth;
} SSL_CIPHER;

typedef struct ssl_sess_cert_st {
    void *peer_rsa_tmp;
    void *peer_dh_tmp;
    void *peer_ecdh_tmp;
    struct evp_pkey_st *peer_pkeys[3];
    void *x509;
} SSL_SESS_CERT;

typedef struct srp_ctx_st {
    void *N;
    void *g;
    void *s;
    void *B;
} SRP_CTX;

typedef struct ssl3_state_st {
    struct {
        SSL_CIPHER *new_cipher;
        int message_type;
        int reuse_message;
    } tmp;
    unsigned char client_random[SSL3_RANDOM_SIZE];
    unsigned char server_random[SSL3_RANDOM_SIZE];
} SSL3_STATE;

typedef struct evp_md_ctx_st {
    int dummy;
} EVP_MD_CTX;

typedef struct evp_pkey_st {
    int type;
    int bits;
    union {
        void *rsa;
    } pkey;
} EVP_PKEY;

typedef struct evp_md_st {
    const char *name;
} EVP_MD;

#define SSL_F_SSL3_GET_KEY_EXCHANGE 1000
#define SSL_R_UNEXPECTED_MESSAGE 1001
#define SSL_AD_UNEXPECTED_MESSAGE 10
#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_HANDSHAKE_FAILURE 40
#define SSL_AD_ILLEGAL_PARAMETER 47
#define SSL_AD_DECRYPT_ERROR 51
#define SSL_AD_INTERNAL_ERROR 80
#define SSL_AD_EXPORT_RESTRICTION 60
#define SSL_R_LENGTH_TOO_SHORT 1002
#define SSL_R_DATA_LENGTH_TOO_LONG 1003
#define SSL_R_BAD_PSK_IDENTITY_HINT_LENGTH 1004
#define SSL_R_BAD_SRP_N_LENGTH 1005
#define SSL_R_BAD_SRP_G_LENGTH 1006
#define SSL_R_BAD_SRP_S_LENGTH 1007
#define SSL_R_BAD_SRP_B_LENGTH 1008
#define SSL_R_BAD_RSA_MODULUS_LENGTH 1009
#define SSL_R_BAD_RSA_E_LENGTH 1010
#define SSL_R_BAD_DH_P_LENGTH 1011
#define SSL_R_BAD_DH_G_LENGTH 1012
#define SSL_R_BAD_DH_PUB_KEY_LENGTH 1013
#define SSL_R_BAD_ECPOINT 1014
#define SSL_R_WRONG_CURVE 1015
#define SSL_R_WRONG_SIGNATURE_LENGTH 1016
#define SSL_R_BAD_RSA_DECRYPT 1017
#define SSL_R_BAD_SIGNATURE 1018
#define SSL_R_EXTRA_DATA_IN_MESSAGE 1019
#define SSL_R_TRIED_TO_USE_UNSUPPORTED_CIPHER 1020
#define SSL_R_UNABLE_TO_FIND_ECDH_PARAMETERS 1021
#define SSL_R_ECGROUP_TOO_LARGE_FOR_CIPHER 1022
#define SSL_R_BAD_SRP_PARAMETERS 1023
#define SSL_R_BAD_ECDSA_SIGNATURE 1024

#define ERR_R_MALLOC_FAILURE 1
#define ERR_R_BN_LIB 2
#define ERR_R_DH_LIB 3
#define ERR_R_EC_LIB 4
#define ERR_R_INTERNAL_ERROR 5

#define SSL_kRSA 0x00000001L
#define SSL_kDHE 0x00000002L
#define SSL_kECDHE 0x00000004L
#define SSL_kPSK 0x00000008L
#define SSL_kSRP 0x00000010L
#define SSL_kEDH 0x00000020L
#define SSL_kDHr 0x00000040L
#define SSL_kDHd 0x00000080L
#define SSL_kEECDH 0x00000100L
#define SSL_aRSA 0x00000001L
#define SSL_aDSS 0x00000002L
#define SSL_aNULL 0x00000004L
#define SSL_aECDSA 0x00000008L
#define SSL_aSRP 0x00000010L

#define SSL_PKEY_RSA_ENC 0
#define SSL_PKEY_DSA_SIGN 1
#define SSL_PKEY_ECC 2

static SSL_SESS_CERT *ssl_sess_cert_new(void) { return NULL; }
static int tls1_check_curve(SSL *s, unsigned char *p, int len) { return 0; }
static int tls1_ec_curve_id2nid(int id) { return 0; }
static int srp_verify_server_param(SSL *s, int *al) { return 0; }
static int ssl3_check_cert_and_algorithm(SSL *s) { return 0; }
static int SSL_USE_SIGALGS(SSL *s) { return 0; }
static int tls12_check_peer_sigalg(const EVP_MD **md, SSL *s, unsigned char *p, EVP_PKEY *pkey) { return 0; }
static int SSL_C_IS_EXPORT(SSL_CIPHER *c) { return 0; }
static int SSL_C_EXPORT_PKEYLENGTH(SSL_CIPHER *c) { return 0; }
static void ssl3_send_alert(SSL *s, int level, int desc) {}
static void SSLerr(int f, int r) {}
static char *BUF_strndup(const char *str, size_t len) { return NULL; }
static void n2s(unsigned char **p, unsigned int *n) { *n = (*p)[0] << 8 | (*p)[1]; *p += 2; }
static void EVP_MD_CTX_init(EVP_MD_CTX *ctx) {}
static void EVP_MD_CTX_cleanup(EVP_MD_CTX *ctx) {}
static void EVP_PKEY_free(EVP_PKEY *pkey) {}
static const EVP_MD *EVP_sha1(void) { return NULL; }
static int EVP_PKEY_size(EVP_PKEY *pkey) { return 0; }
static int EVP_VerifyInit_ex(EVP_MD_CTX *ctx, const EVP_MD *type, void *e) { return 0; }
static int EVP_VerifyUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt) { return 0; }
static int EVP_VerifyFinal(EVP_MD_CTX *ctx, const unsigned char *sig, unsigned int siglen, EVP_PKEY *pkey) { return 0; }