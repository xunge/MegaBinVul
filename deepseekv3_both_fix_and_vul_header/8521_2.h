#include <stdio.h>
#include <stdlib.h>

typedef struct X509_st {
    int references;
} X509;

typedef struct evp_pkey_st EVP_PKEY;
typedef struct stack_st_X509 STACK_OF_X509;
#define STACK_OF(type) struct stack_st_##type

typedef struct sess_cert_st {
    STACK_OF_X509 *cert_chain;
    int peer_cert_type;
    struct cert_pkey_st {
        X509 *x509;
        EVP_PKEY *privatekey;
    } peer_pkeys[10];
    struct cert_pkey_st *peer_key;
} SESS_CERT;

typedef struct ssl3_state_st {
    unsigned long flags;
    struct {
        unsigned char *data;
        unsigned int length;
        unsigned int type;
        unsigned int message_type;
        const struct ssl_cipher_st *new_cipher;
        int reuse_message;
    } tmp;
} SSL3_STATE;

typedef struct ssl_session_st {
    X509 *peer;
    int verify_result;
    SESS_CERT *sess_cert;
} SSL_SESSION;

typedef struct ssl_st {
    struct ssl_method_st *method;
    SSL_SESSION *session;
    SSL3_STATE *s3;
    int state;
    int verify_mode;
    long verify_result;
    unsigned char *init_msg;
    unsigned long max_cert_list;
} SSL;

typedef struct ssl_method_st {
    long (*ssl_get_message)(SSL *s, int st1, int st2, int mt, long max, int *ok);
} SSL_METHOD;

typedef struct ssl_cipher_st {
    const char *name;
    unsigned long algorithm_mkey;
    unsigned long algorithm_auth;
} SSL_CIPHER;

#define SSL3_ST_CR_CERT_A 0x120
#define SSL3_ST_CR_CERT_B 0x121
#define SSL3_MT_SERVER_KEY_EXCHANGE 12
#define SSL3_MT_SERVER_DONE 14
#define SSL3_MT_CERTIFICATE 11
#define SSL3_AL_FATAL 2
#define SSL_AD_UNEXPECTED_MESSAGE 10
#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_BAD_CERTIFICATE 42
#define SSL_aKRB5 0x20
#define SSL_kKRB5 0x20
#define SSL_VERIFY_NONE 0
#define SSL_F_SSL3_GET_SERVER_CERTIFICATE 100
#define SSL_R_BAD_MESSAGE_TYPE 101
#define SSL_R_LENGTH_MISMATCH 102
#define SSL_R_CERT_LENGTH_MISMATCH 103
#define SSL_R_CERTIFICATE_VERIFY_FAILED 104
#define SSL_R_UNABLE_TO_FIND_PUBLIC_KEY_PARAMETERS 105
#define SSL_R_UNKNOWN_CERTIFICATE_TYPE 106
#define SSL_ST_ERR 0xFF
#define CRYPTO_LOCK_X509 1
#define ERR_R_MALLOC_FAILURE 1
#define ERR_R_ASN1_LIB 2

void n2l3(const unsigned char *p, unsigned long *l);
int ssl_verify_alarm_type(int verify_result);

SESS_CERT *ssl_sess_cert_new(void);
void ssl_sess_cert_free(SESS_CERT *sc);
int ssl_verify_cert_chain(SSL *s, STACK_OF_X509 *sk);
int ssl_cert_type(X509 *x, EVP_PKEY *pkey);
void ssl3_send_alert(SSL *s, int level, int desc);
void SSLerr(int f, int r);
void ERR_clear_error(void);
void X509_free(X509 *x);
void EVP_PKEY_free(EVP_PKEY *pkey);
STACK_OF_X509 *sk_X509_new_null(void);
int sk_X509_push(STACK_OF_X509 *sk, X509 *x);
X509 *sk_X509_value(STACK_OF_X509 *sk, int i);
void sk_X509_pop_free(STACK_OF_X509 *sk, void (*func)(X509 *));
X509 *d2i_X509(X509 **px, const unsigned char **in, int len);
EVP_PKEY *X509_get_pubkey(X509 *x);
int EVP_PKEY_missing_parameters(EVP_PKEY *pkey);
void CRYPTO_add(int *ref, int amount, int type);