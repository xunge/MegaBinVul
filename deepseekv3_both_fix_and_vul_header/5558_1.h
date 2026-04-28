#include <stddef.h>
#include <string.h>

typedef struct ssl_st SSL;
typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl3_state_st SSL3_STATE;
typedef struct ssl_comp_st SSL_COMP;
typedef struct ssl_method_st SSL_METHOD;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct ssl_buffer_st SSL_BUFFER;

#define OPENSSL_NO_COMP
#define OPENSSL_NO_TLSEXT
#define OPENSSL_MAX_TLS1_2_CIPHER_LENGTH 0
#define SSL_OP_NO_DTLSv1 0
#define SSL_OP_NO_DTLSv1_2 0
#define SSL_F_SSL3_CLIENT_HELLO 0
#define SSL_R_ONLY_DTLS_1_2_ALLOWED_IN_SUITEB_MODE 0
#define SSL_R_WRONG_SSL_VERSION 0
#define SSL_R_NO_CIPHERS_AVAILABLE 0
#define SSL_R_CLIENTHELLO_TLSEXT 0
#define ERR_R_INTERNAL_ERROR 0
#define SSL3_RANDOM_SIZE 32
#define SSL3_MT_CLIENT_HELLO 1
#define SSL3_AL_FATAL 2
#define SSL3_ST_CW_CLNT_HELLO_A 0
#define SSL3_ST_CW_CLNT_HELLO_B 0
#define SSL3_RT_MAX_PLAIN_LENGTH 0
#define DTLS_ANY_VERSION 0
#define DTLS1_VERSION 0
#define DTLS1_2_VERSION 0
#define TLS1_2_VERSION 0

#define SSL_IS_DTLS(s) 0
#define s2n(l, p) do { \
        *(p)++ = (unsigned char)(((l) >> 8) & 0xff); \
        *(p)++ = (unsigned char)((l) & 0xff); \
    } while (0)

static inline void SSLerr(int f, int r) {}
static inline int ssl_get_new_session(SSL *s, int i) { return 0; }
static inline int tls1_suiteb(SSL *s) { return 0; }
static inline SSL_METHOD *DTLSv1_client_method(void) { return NULL; }
static inline SSL_METHOD *DTLSv1_2_client_method(void) { return NULL; }
static inline int ssl_fill_hello_random(SSL *s, int i, unsigned char *p, size_t sz) { return 0; }
static inline unsigned char *ssl_handshake_start(SSL *s) { return NULL; }
static inline int ssl_cipher_list_to_bytes(SSL *s, void *ciphers, unsigned char *p, int i) { return 0; }
static inline void *SSL_get_ciphers(SSL *s) { return NULL; }
static inline int ssl_allow_compression(SSL *s) { return 0; }
static inline int sk_SSL_COMP_num(void *sk) { return 0; }
static inline SSL_COMP *sk_SSL_COMP_value(void *sk, int i) { return NULL; }
static inline int ssl_prepare_clienthello_tlsext(SSL *s) { return 0; }
static inline unsigned char *ssl_add_clienthello_tlsext(SSL *s, unsigned char *p, unsigned char *buf, int *al) { return NULL; }
static inline void ssl3_send_alert(SSL *s, int level, int desc) {}
static inline void ssl_set_handshake_header(SSL *s, int mt, unsigned long l) {}
static inline int ssl_do_write(SSL *s) { return 0; }
static inline int TLS1_get_version(SSL *s) { return 0; }

struct ssl_buffer_st {
    void *data;
};

struct ssl_st {
    SSL_BUFFER *init_buf;
    int state;
    SSL_SESSION *session;
    int version;
    SSL_METHOD *method;
    int client_version;
    int options;
    SSL3_STATE *s3;
    int new_session;
    SSL_CTX *ctx;
    struct dtls1_state_st *d1;
};

struct ssl_session_st {
    int ssl_version;
    unsigned char session_id[32];
    unsigned int session_id_length;
    int not_resumable;
};

struct ssl3_state_st {
    unsigned char client_random[32];
};

struct dtls1_state_st {
    unsigned char cookie[256];
    size_t cookie_len;
};

struct ssl_comp_st {
    int id;
};

struct ssl_method_st {
    int version;
};