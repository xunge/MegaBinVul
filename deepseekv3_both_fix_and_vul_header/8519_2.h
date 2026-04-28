#include <stdlib.h>
#include <string.h>

typedef struct X509 X509;
typedef struct stack_st_X509 STACK_OF_X509;
#define STACK_OF(X509) STACK_OF_X509

typedef struct ssl_st SSL;
typedef struct ssl_method_st {
    int (*ssl_get_message)(SSL *, int, int, int, size_t, int *);
} SSL_METHOD;
typedef struct ssl3_state_st SSL3_STATE;
typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl_sess_cert_st SSL_SESS_CERT;

struct ssl_st {
    const SSL_METHOD *method;
    SSL3_STATE *s3;
    SSL_SESSION *session;
    int verify_mode;
    int verify_result;
    int state;
    int version;
    unsigned char *init_msg;
    size_t max_cert_list;
};

struct ssl3_state_st {
    struct {
        int message_type;
        int cert_request;
        int reuse_message;
        unsigned long handshake_buffer;
    } tmp;
    unsigned long handshake_buffer;
};

struct ssl_session_st {
    X509 *peer;
    long verify_result;
    SSL_SESS_CERT *sess_cert;
};

struct ssl_sess_cert_st {
    STACK_OF_X509 *cert_chain;
};

#define SSL_F_SSL3_GET_CLIENT_CERTIFICATE 0
#define SSL_R_PEER_DID_NOT_RETURN_A_CERTIFICATE 0
#define SSL_R_TLS_PEER_DID_NOT_RESPOND_WITH_CERTIFICATE_LIST 0
#define SSL_R_WRONG_MESSAGE_TYPE 0
#define SSL_R_LENGTH_MISMATCH 0
#define SSL_R_CERT_LENGTH_MISMATCH 0
#define SSL_R_NO_CERTIFICATES_RETURNED 0
#define SSL_R_NO_CERTIFICATE_RETURNED 0
#define ERR_R_MALLOC_FAILURE 0
#define ERR_R_ASN1_LIB 0

#define SSL3_ST_SR_CERT_A 0
#define SSL3_ST_SR_CERT_B 0
#define SSL3_MT_CLIENT_KEY_EXCHANGE 0
#define SSL3_MT_CERTIFICATE 0
#define SSL3_AL_FATAL 0
#define SSL_AD_HANDSHAKE_FAILURE 0
#define SSL_AD_UNEXPECTED_MESSAGE 0
#define SSL_AD_DECODE_ERROR 0
#define SSL_AD_INTERNAL_ERROR 0

#define SSL_ST_ERR 0
#define SSL3_VERSION 0
#define SSL_VERIFY_PEER 0
#define SSL_VERIFY_FAIL_IF_NO_PEER_CERT 0

#define n2l3(p, l) 
#define sk_X509_new_null() NULL
#define sk_X509_push(st, x) 0
#define sk_X509_num(st) 0
#define sk_X509_shift(st) NULL
#define sk_X509_pop_free(st, free_func)
#define d2i_X509(a, b, c) NULL
#define X509_free(x)
#define SSLerr(a, b)
#define ssl3_send_alert(a, b, c)
#define ssl_verify_cert_chain(a, b) 0
#define ssl_verify_alarm_type(a) 0
#define ssl3_digest_cached_records(a) 0
#define ssl_sess_cert_new() NULL