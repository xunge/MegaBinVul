#include <string.h>
#include <stdlib.h>

typedef struct cert_st CERT;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct evp_pkey_st EVP_PKEY;
typedef struct rsa_st RSA;
typedef struct dh_st DH;
typedef struct ec_key_st EC_KEY;
typedef struct x509_st X509;

/* Simplified stack implementation */
typedef struct stack_st {
    void **data;
    int num;
    int sorted;
    int num_alloc;
    int (*comp)(const void *, const void *);
} STACK;

typedef STACK STACK_OF_X509;
#define STACK_OF(type) STACK

#define OPENSSL_NO_RSA
#define OPENSSL_NO_DH
#define OPENSSL_NO_ECDH
#define OPENSSL_NO_TLSEXT
#define OPENSSL_NO_SRP
#define OPENSSL_NO_EC

#define SSL_CTRL_NEED_TMP_RSA 1
#define SSL_CTRL_SET_TMP_RSA 2
#define SSL_CTRL_SET_TMP_RSA_CB 3
#define SSL_CTRL_SET_TMP_DH 4
#define SSL_CTRL_SET_TMP_DH_CB 5
#define SSL_CTRL_SET_TMP_ECDH 6
#define SSL_CTRL_SET_TMP_ECDH_CB 7
#define SSL_CTRL_SET_TLSEXT_SERVERNAME_ARG 8
#define SSL_CTRL_SET_TLSEXT_TICKET_KEYS 9
#define SSL_CTRL_GET_TLSEXT_TICKET_KEYS 10
#define SSL_CTRL_SET_TLSEXT_OPAQUE_PRF_INPUT_CB_ARG 11
#define SSL_CTRL_SET_TLSEXT_STATUS_REQ_CB_ARG 12
#define SSL_CTRL_SET_TLS_EXT_SRP_USERNAME 13
#define SSL_CTRL_SET_TLS_EXT_SRP_PASSWORD 14
#define SSL_CTRL_SET_SRP_ARG 15
#define SSL_CTRL_SET_TLS_EXT_SRP_STRENGTH 16
#define SSL_CTRL_SET_CURVES 17
#define SSL_CTRL_SET_CURVES_LIST 18
#define SSL_CTRL_SET_ECDH_AUTO 19
#define SSL_CTRL_SET_SIGALGS 20
#define SSL_CTRL_SET_SIGALGS_LIST 21
#define SSL_CTRL_SET_CLIENT_SIGALGS 22
#define SSL_CTRL_SET_CLIENT_SIGALGS_LIST 23
#define SSL_CTRL_SET_CLIENT_CERT_TYPES 24
#define SSL_CTRL_BUILD_CERT_CHAIN 25
#define SSL_CTRL_SET_VERIFY_CERT_STORE 26
#define SSL_CTRL_SET_CHAIN_CERT_STORE 27
#define SSL_CTRL_EXTRA_CHAIN_CERT 28
#define SSL_CTRL_GET_EXTRA_CHAIN_CERTS 29
#define SSL_CTRL_CLEAR_EXTRA_CHAIN_CERTS 30
#define SSL_CTRL_CHAIN 31
#define SSL_CTRL_CHAIN_CERT 32
#define SSL_CTRL_GET_CHAIN_CERTS 33
#define SSL_CTRL_SELECT_CURRENT_CERT 34
#define SSL_CTRL_SET_CURRENT_CERT 35

#define SSL_PKEY_RSA_ENC 0
#define SSL_OP_SINGLE_DH_USE 0x00100000L
#define SSL_OP_SINGLE_ECDH_USE 0x00080000L
#define SSL_kSRP 0x00000020L
#define SSL_F_SSL3_CTX_CTRL 0
#define ERR_R_RSA_LIB 0
#define ERR_R_DH_LIB 0
#define ERR_R_ECDH_LIB 0
#define ERR_R_EC_LIB 0
#define ERR_R_INTERNAL_ERROR 0
#define ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED 0
#define SSL_R_INVALID_TICKET_KEYS_LENGTH 0
#define SSL_R_INVALID_SRP_USERNAME 0

#define TLSEXT_TYPE_opaque_prf_input 0

typedef int (*srp_password_from_info_cb)(void *, void *, char *, int);

struct cert_st {
    RSA *rsa_tmp;
    EVP_PKEY *pkeys[10];
    DH *dh_tmp;
    EC_KEY *ecdh_tmp;
    int ecdh_tmp_auto;
    struct {
        STACK_OF_X509 *chain;
    } *key;
    STACK_OF_X509 *chain;
};

struct ssl_ctx_st {
    CERT *cert;
    unsigned long options;
    void *tlsext_servername_arg;
    unsigned char tlsext_tick_key_name[16];
    unsigned char tlsext_tick_hmac_key[16];
    unsigned char tlsext_tick_aes_key[16];
    void *tlsext_opaque_prf_input_callback_arg;
    void *tlsext_status_arg;
    struct {
        unsigned int srp_Mask;
        char *login;
        void *info;
        srp_password_from_info_cb SRP_give_srp_client_pwd_callback;
        void *SRP_cb_arg;
        int strength;
    } srp_ctx;
    STACK_OF_X509 *extra_certs;
    void *cert_store;
    unsigned char *tlsext_ellipticcurvelist;
    size_t tlsext_ellipticcurvelist_length;
};

void SSLerr(int f, int r);
RSA *RSAPrivateKey_dup(RSA *rsa);
void RSA_free(RSA *rsa);
DH *DHparams_dup(DH *dh);
int DH_generate_key(DH *dh);
void DH_free(DH *dh);
EC_KEY *EC_KEY_dup(EC_KEY *ecdh);
int EC_KEY_generate_key(EC_KEY *ecdh);
void EC_KEY_free(EC_KEY *ecdh);
int EVP_PKEY_size(EVP_PKEY *pkey);
char *BUF_strdup(const char *str);
void OPENSSL_free(void *addr);
int tls1_set_curves(unsigned char **pext, size_t *pextlen, void *parg, long larg);
int tls1_set_curves_list(unsigned char **pext, size_t *pextlen, void *parg);
int tls1_set_sigalgs(CERT *cert, void *parg, long larg, int client);
int tls1_set_sigalgs_list(CERT *cert, void *parg, int client);
int ssl3_set_req_cert_type(CERT *cert, void *parg, long larg);
int ssl_build_cert_chain(CERT *cert, void *store, long flags);
int ssl_cert_set_cert_store(CERT *cert, void *store, int chain, long flags);
STACK_OF_X509 *sk_X509_new_null();
void sk_X509_push(STACK_OF_X509 *sk, X509 *cert);
void sk_X509_pop_free(STACK_OF_X509 *sk, void (*func)(X509 *));
int ssl_cert_set1_chain(CERT *cert, STACK_OF_X509 *chain);
int ssl_cert_set0_chain(CERT *cert, STACK_OF_X509 *chain);
int ssl_cert_add1_chain_cert(CERT *cert, X509 *x);
int ssl_cert_add0_chain_cert(CERT *cert, X509 *x);
int ssl_cert_select_current(CERT *cert, X509 *x);
int ssl_cert_set_current(CERT *cert, long i);
void X509_free(X509 *x);

/* Basic stack implementation */
STACK_OF_X509 *sk_X509_new_null() {
    STACK_OF_X509 *sk = calloc(1, sizeof(STACK_OF_X509));
    return sk;
}

void sk_X509_push(STACK_OF_X509 *sk, X509 *cert) {
    if (sk->num >= sk->num_alloc) {
        sk->num_alloc = sk->num_alloc ? sk->num_alloc * 2 : 4;
        sk->data = realloc(sk->data, sizeof(void *) * sk->num_alloc);
    }
    sk->data[sk->num++] = cert;
}

void sk_X509_pop_free(STACK_OF_X509 *sk, void (*func)(X509 *)) {
    if (sk) {
        while (sk->num > 0) {
            func(sk->data[--sk->num]);
        }
        free(sk->data);
        free(sk);
    }
}