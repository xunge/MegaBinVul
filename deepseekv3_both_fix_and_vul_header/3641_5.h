#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ssl_st SSL;
typedef struct ssl_method_st {
    long (*ssl_get_message)(SSL *, int, int, int, long, int *);
} SSL_METHOD;
typedef struct ssl_cipher_st {
    unsigned long algorithm_ssl;
    unsigned long id;
} SSL_CIPHER;
typedef struct ssl_comp_st SSL_COMP;
typedef struct ssl_session_st {
    unsigned char session_id[32];
    unsigned int session_id_length;
    unsigned char master_key[48];
    unsigned int master_key_length;
    SSL_CIPHER *cipher;
    unsigned long cipher_id;
    unsigned char sid_ctx[32];
    unsigned int sid_ctx_length;
    unsigned int compress_meth;
} SSL_SESSION;
typedef struct ssl_ctx_st {
    void *comp_methods;
} SSL_CTX;

struct stack_st_SSL_CIPHER {
    SSL_CIPHER **data;
    int num;
};

#define STACK_OF(type) struct stack_st_##type
#define sk_SSL_CIPHER_find(st, cipher) 0

struct ssl3_state_st {
    struct {
        unsigned int message_type;
        unsigned int reuse_message;
        const SSL_CIPHER *new_cipher;
        void *new_compression;
        unsigned int flags;
    } tmp;
    unsigned int flags;
    unsigned char server_random[32];
};

struct dtls1_state_st {
    int send_cookie;
};

struct ssl_st {
    const SSL_METHOD *method;
    SSL_SESSION *session;
    SSL_CTX *ctx;
    struct ssl3_state_st *s3;
    struct dtls1_state_st *d1;
    unsigned int version;
    unsigned char *init_msg;
    unsigned int sid_ctx_length;
    unsigned char *sid_ctx;
    unsigned int hit;
    unsigned long options;
    void *tls_session_secret_cb_arg;
    int (*tls_session_secret_cb)(SSL *, unsigned char *, int *, void *, SSL_CIPHER **, void *);
};

#define OPENSSL_NO_COMP
#define OPENSSL_NO_TLSEXT
#define SSL3_ST_CR_SRVR_HELLO_A 0
#define SSL3_ST_CR_SRVR_HELLO_B 0
#define DTLS1_VERSION 0
#define DTLS1_BAD_VER 0
#define DTLS1_MT_HELLO_VERIFY_REQUEST 0
#define SSL3_MT_SERVER_HELLO 0
#define SSL3_RANDOM_SIZE 32
#define SSL3_SESSION_ID_SIZE 32
#define TLS1_VERSION 0
#define SSL_TLSV1_2 0
#define TLS1_2_VERSION 0
#define SSL_OP_NO_COMPRESSION 0
#define SSL_OP_NETSCAPE_REUSE_CIPHER_CHANGE_BUG 0
#define SSL3_AL_FATAL 0
#define SSL3_FLAGS_CCS_OK 0
#define SSL3_VERSION 0

#define SSL_F_SSL3_GET_SERVER_HELLO 0
#define SSL_R_BAD_MESSAGE_TYPE 0
#define SSL_R_WRONG_SSL_VERSION 0
#define SSL_R_SSL3_SESSION_ID_TOO_LONG 0
#define SSL_R_ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT 0
#define SSL_R_UNKNOWN_CIPHER_RETURNED 0
#define SSL_R_WRONG_CIPHER_RETURNED 0
#define SSL_R_OLD_SESSION_CIPHER_NOT_RETURNED 0
#define SSL_R_UNSUPPORTED_COMPRESSION_ALGORITHM 0
#define SSL_R_INCONSISTENT_COMPRESSION 0
#define SSL_R_COMPRESSION_DISABLED 0
#define SSL_R_OLD_SESSION_COMPRESSION_ALGORITHM_NOT_RETURNED 0
#define SSL_R_PARSE_TLSEXT 0
#define SSL_R_SERVERHELLO_TLSEXT 0
#define SSL_R_BAD_PACKET_LENGTH 0

#define SSL_AD_UNEXPECTED_MESSAGE 0
#define SSL_AD_PROTOCOL_VERSION 0
#define SSL_AD_ILLEGAL_PARAMETER 0
#define SSL_AD_INTERNAL_ERROR 0
#define SSL_AD_DECODE_ERROR 0

void SSLerr(int f, int r);
int SSL_version(SSL *s);
long ssl_get_new_session(SSL *s, int session);
const SSL_CIPHER *ssl_get_cipher_by_char(SSL *s, unsigned char *p);
int ssl_put_cipher_by_char(SSL *s, const SSL_CIPHER *c, unsigned char *p);
STACK_OF(SSL_CIPHER) *ssl_get_ciphers_by_id(SSL *s);
int ssl3_digest_cached_records(SSL *s);
SSL_COMP *ssl3_comp_find(SSL_CTX *ctx, int j);
int ssl_parse_serverhello_tlsext(SSL *s, unsigned char **p, unsigned char *d, long n, int *al);
int ssl_check_serverhello_tlsext(SSL *s);
void ssl3_send_alert(SSL *s, int level, int al);
long TLS1_get_version(SSL *s);