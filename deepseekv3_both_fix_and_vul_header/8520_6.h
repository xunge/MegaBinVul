#include <stdlib.h>
#include <string.h>

typedef struct x509_name_st X509_NAME;

struct stack_st_X509_NAME {
    X509_NAME **data;
    int num;
    int sorted;
};
typedef struct stack_st_X509_NAME STACK_OF_X509_NAME;

typedef struct ssl_cipher_st {
    unsigned int algorithm_auth;
} SSL_CIPHER;

typedef struct ssl3_state_st {
    struct {
        int cert_req;
        int message_type;
        int reuse_message;
        unsigned char ctype[16];
        int ctype_num;
        STACK_OF_X509_NAME *ca_names;
        void *handshake_buffer;
        SSL_CIPHER *new_cipher;
    } tmp;
    void *handshake_buffer;
} SSL3_STATE;

typedef struct ssl_method_st {
    unsigned long (*ssl_get_message)(void *, int, int, int, int, int *);
} SSL_METHOD;

typedef struct ssl_st {
    SSL_METHOD *method;
    SSL3_STATE *s3;
    int version;
    unsigned long options;
    int max_cert_list;
    void *init_msg;
    int state;
} SSL;

#define SSL3_ST_CR_CERT_REQ_A 0
#define SSL3_ST_CR_CERT_REQ_B 0
#define SSL3_MT_SERVER_DONE 0
#define SSL3_MT_CERTIFICATE_REQUEST 0
#define SSL3_VERSION 0
#define SSL3_AL_FATAL 0
#define SSL_AD_UNEXPECTED_MESSAGE 0
#define SSL_AD_DECODE_ERROR 0
#define SSL_F_SSL3_GET_CERTIFICATE_REQUEST 0
#define SSL_R_WRONG_MESSAGE_TYPE 0
#define SSL_R_TLS_CLIENT_CERT_REQ_WITH_ANON_CIPHER 0
#define SSL_R_DATA_LENGTH_TOO_LONG 0
#define SSL_R_SIGNATURE_ALGORITHMS_ERROR 0
#define SSL_R_LENGTH_MISMATCH 0
#define SSL_R_CA_DN_TOO_LONG 0
#define SSL_R_CA_DN_LENGTH_MISMATCH 0
#define SSL3_CT_NUMBER 16
#define TLS1_2_VERSION 0
#define SSL_OP_NETSCAPE_CA_DN_BUG 0
#define SSL_ST_ERR 0
#define SSL_aNULL 0
#define ERR_R_MALLOC_FAILURE 0
#define ERR_R_ASN1_LIB 0

#define n2s(p, l) ((l) = ((unsigned int)(p)[0] << 8) | (p)[1], (p) += 2)

int ca_dn_cmp(const X509_NAME **a, const X509_NAME **b);
int ssl3_digest_cached_records(SSL *s);
void ssl3_send_alert(SSL *s, int level, int desc);
int tls1_process_sigalgs(SSL *s, const unsigned char *data, size_t len);
unsigned long TLS1_get_version(const SSL *s);
void SSLerr(int f, int r);
void ERR_clear_error(void);
X509_NAME *d2i_X509_NAME(X509_NAME **a, const unsigned char **pp, long length);
int sk_X509_NAME_push(STACK_OF_X509_NAME *sk, X509_NAME *ptr);
void sk_X509_NAME_pop_free(STACK_OF_X509_NAME *sk, void (*func)(void *));
STACK_OF_X509_NAME *sk_X509_NAME_new(int (*cmp)(const X509_NAME **, const X509_NAME **));
void X509_NAME_free(X509_NAME *a);

static void X509_NAME_free_wrapper(void *a) {
    X509_NAME_free((X509_NAME *)a);
}

#define STACK_OF(type) struct stack_st_##type