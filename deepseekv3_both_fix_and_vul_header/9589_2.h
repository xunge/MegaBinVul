#include <stdio.h>
#include <stdlib.h>

#define SSL3_ST_SR_CERT_VRFY_A 0
#define SSL3_ST_SR_CERT_VRFY_B 0
#define SSL3_RT_MAX_PLAIN_LENGTH 0
#define SSL3_MT_CERTIFICATE_VERIFY 0
#define SSL_AD_UNEXPECTED_MESSAGE 0
#define SSL_AD_ILLEGAL_PARAMETER 0
#define SSL_AD_DECODE_ERROR 0
#define SSL_AD_INTERNAL_ERROR 0
#define SSL_AD_DECRYPT_ERROR 0
#define SSL_AD_UNSUPPORTED_CERTIFICATE 0
#define SSL3_AL_FATAL 0
#define TLS1_FLAGS_KEEP_HANDSHAKE 0
#define NID_id_GostR3410_94 0
#define NID_id_GostR3410_2001 0
#define EVP_PKT_SIGN 0
#define MD5_DIGEST_LENGTH 16
#define SHA_DIGEST_LENGTH 20
#define EVP_PKEY_RSA 6
#define EVP_PKEY_DSA 116
#define EVP_PKEY_EC 408

#define SSL_USE_SIGALGS(s) 0
#define SSL_F_SSL3_GET_CERT_VERIFY 0
#define SSL_R_MISSING_VERIFY_MESSAGE 0
#define SSL_R_NO_CLIENT_CERT_RECEIVED 0
#define SSL_R_SIGNATURE_FOR_NON_SIGNING_CERTIFICATE 0
#define SSL_R_CCS_RECEIVED_EARLY 0
#define SSL_R_LENGTH_MISMATCH 0
#define SSL_R_WRONG_SIGNATURE_SIZE 0
#define SSL_R_BAD_SIGNATURE 0
#define SSL_R_BAD_RSA_DECRYPT 0
#define SSL_R_BAD_RSA_SIGNATURE 0
#define SSL_R_BAD_DSA_SIGNATURE 0
#define SSL_R_BAD_ECDSA_SIGNATURE 0
#define ERR_R_INTERNAL_ERROR 0
#define ERR_R_EVP_LIB 0

#define n2s(p, i) 0
#define OPENSSL_NO_RSA
#define OPENSSL_NO_DSA
#define OPENSSL_NO_ECDSA

typedef struct evp_pkey_st {
    int type;
    int save_type;
    union {
        void *rsa;
        void *dsa;
        void *ec;
    } pkey;
} EVP_PKEY;

typedef struct x509_st X509;
typedef struct evp_md_st EVP_MD;
typedef struct evp_md_ctx_st {
    int dummy;
} EVP_MD_CTX;
typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;
typedef struct bio_st BIO;

typedef struct ssl_st SSL;
typedef struct ssl3_state_st {
    struct {
        int message_type;
        int reuse_message;
        unsigned char cert_verify_md[MD5_DIGEST_LENGTH + SHA_DIGEST_LENGTH];
    } tmp;
    int change_cipher_spec;
    BIO *handshake_buffer;
    int flags;
} SSL3_STATE;

typedef struct ssl_session_st {
    X509 *peer;
} SSL_SESSION;

struct ssl_method_st {
    long (*ssl_get_message)(SSL *, int, int, int, long, int *);
};

struct ssl_st {
    const struct ssl_method_st *method;
    SSL_SESSION *session;
    SSL3_STATE *s3;
    unsigned char *init_msg;
};

void SSLerr(int f, int r);
void ssl3_send_alert(SSL *s, int level, int desc);
int tls12_check_peer_sigalg(const EVP_MD **md, SSL *s, unsigned char *p, EVP_PKEY *pkey);

void EVP_MD_CTX_init(EVP_MD_CTX *ctx);
void EVP_MD_CTX_cleanup(EVP_MD_CTX *ctx);
EVP_PKEY *X509_get_pubkey(X509 *x);
int X509_certificate_type(X509 *x, EVP_PKEY *pkey);
int EVP_PKEY_size(EVP_PKEY *pkey);
int EVP_VerifyInit_ex(EVP_MD_CTX *ctx, const EVP_MD *type, void *e);
int EVP_VerifyUpdate(EVP_MD_CTX *ctx, const void *d, unsigned int cnt);
int EVP_VerifyFinal(EVP_MD_CTX *ctx, const unsigned char *sigbuf, unsigned int siglen, EVP_PKEY *pkey);
void EVP_PKEY_free(EVP_PKEY *pkey);
EVP_PKEY_CTX *EVP_PKEY_CTX_new(EVP_PKEY *pkey, void *e);
int EVP_PKEY_verify_init(EVP_PKEY_CTX *ctx);
int EVP_PKEY_verify(EVP_PKEY_CTX *ctx, const unsigned char *sig, size_t siglen, const unsigned char *tbs, size_t tbslen);
void EVP_PKEY_CTX_free(EVP_PKEY_CTX *ctx);
long BIO_get_mem_data(BIO *b, void **pp);
void BIO_free(BIO *a);