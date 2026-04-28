#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ssl_st;
struct ssl_cipher_st {
    unsigned long algorithm_ssl;
    unsigned long algorithm_mkey;
    unsigned long algorithm_auth;
    unsigned long id;
};
struct ssl_comp_st;
struct ssl_session_st;
struct ssl_method_st;
struct ssl3_state_st;
struct dtls1_state_st;

typedef struct ssl_st SSL;
typedef struct ssl_cipher_st SSL_CIPHER;
typedef struct ssl_comp_st SSL_COMP;
typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl_method_st SSL_METHOD;
typedef struct ssl3_state_st SSL3_STATE;
typedef struct dtls1_state_st DTLS1_STATE;

#define OPENSSL_NO_COMP
#define OPENSSL_NO_TLSEXT
#define OPENSSL_NO_SRP

#define SSL3_ST_CR_SRVR_HELLO_A 0
#define SSL3_ST_CR_SRVR_HELLO_B 1
#define SSL3_MT_SERVER_HELLO 2
#define DTLS1_MT_HELLO_VERIFY_REQUEST 3
#define SSL3_RANDOM_SIZE 32
#define SSL3_SESSION_ID_SIZE 32
#define SSL3_FLAGS_CCS_OK 0x01
#define SSL_TLSV1_2 0x02
#define SSL_OP_NO_COMPRESSION 0x04
#define SSL_OP_NETSCAPE_REUSE_CIPHER_CHANGE_BUG 0x08
#define SSL_kSRP 0x10
#define SSL_aSRP 0x20
#define SSL3_AL_FATAL 2
#define SSL_AD_UNEXPECTED_MESSAGE 10
#define SSL_AD_ILLEGAL_PARAMETER 47
#define SSL_AD_PROTOCOL_VERSION 70
#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_INTERNAL_ERROR 80

#define SSL_F_SSL3_GET_SERVER_HELLO 100
#define SSL_R_BAD_MESSAGE_TYPE 101
#define SSL_R_WRONG_SSL_VERSION 102
#define SSL_R_SSL3_SESSION_ID_TOO_LONG 103
#define SSL_R_ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT 104
#define SSL_R_UNKNOWN_CIPHER_RETURNED 105
#define SSL_R_WRONG_CIPHER_RETURNED 106
#define SSL_R_OLD_SESSION_CIPHER_NOT_RETURNED 107
#define SSL_R_UNSUPPORTED_COMPRESSION_ALGORITHM 108
#define SSL_R_INCONSISTENT_COMPRESSION 109
#define SSL_R_COMPRESSION_DISABLED 110
#define SSL_R_OLD_SESSION_COMPRESSION_ALGORITHM_NOT_RETURNED 111
#define SSL_R_PARSE_TLSEXT 112
#define SSL_R_SERVERHELLO_TLSEXT 113
#define SSL_R_BAD_PACKET_LENGTH 114

#define DTLS1_VERSION 0xFEFF
#define DTLS1_BAD_VER 0x0100
#define SSL3_VERSION 0x0300
#define TLS1_VERSION 0x0301
#define TLS1_2_VERSION 0x0303

struct dtls1_state_st {
    int send_cookie;
};

struct ssl3_state_st {
    struct {
        int reuse_message;
        int message_type;
        const SSL_CIPHER *new_cipher;
        SSL_COMP *new_compression;
    } tmp;
    unsigned long flags;
    unsigned char server_random[SSL3_RANDOM_SIZE];
};

struct ssl_session_st {
    unsigned char session_id[SSL3_SESSION_ID_SIZE];
    size_t session_id_length;
    size_t sid_ctx_length;
    unsigned char *sid_ctx;
    const SSL_CIPHER *cipher;
    unsigned long cipher_id;
    unsigned char master_key[48];
    size_t master_key_length;
    int compress_meth;
};

struct ssl_method_st {
    long (*ssl_get_message)(SSL *, int, int, int, long, int *);
};

struct ssl_st {
    unsigned char *init_msg;
    SSL3_STATE *s3;
    DTLS1_STATE *d1;
    SSL_SESSION *session;
    SSL_METHOD *method;
    int version;
    int hit;
    size_t sid_ctx_length;
    unsigned char *sid_ctx;
    void *tls_session_secret_cb;
    void *tls_session_secret_cb_arg;
    unsigned long options;
    void *ctx;
};

struct stack_st_SSL_CIPHER {
    SSL_CIPHER **data;
    int num;
};

#define STACK_OF(type) struct stack_st_##type

void SSLerr(int f, int r);
int sk_SSL_CIPHER_find(STACK_OF(SSL_CIPHER) *sk, const SSL_CIPHER *c);
const SSL_CIPHER *ssl_get_cipher_by_char(SSL *s, const unsigned char *p);
STACK_OF(SSL_CIPHER) *ssl_get_ciphers_by_id(SSL *s);
int ssl3_send_alert(SSL *s, int level, int desc);
int ssl_get_new_session(SSL *s, int session);
int ssl3_digest_cached_records(SSL *s);
SSL_COMP *ssl3_comp_find(void *methods, int j);
int ssl_parse_serverhello_tlsext(SSL *s, unsigned char **p, unsigned char *d, long n, int *al);
int ssl_check_serverhello_tlsext(SSL *s);
int ssl_put_cipher_by_char(SSL *s, const SSL_CIPHER *c, unsigned char *p);
int SSL_version(SSL *s);
int TLS1_get_version(SSL *s);