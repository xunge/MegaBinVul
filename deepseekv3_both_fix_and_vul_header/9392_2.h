#include <string.h>

#define SSL2_MT_SERVER_HELLO 4
#define SSL3_VERSION_MAJOR 3
#define TLS1_2_VERSION_MINOR 3
#define SSL3_RT_HANDSHAKE 22
#define SSL3_MT_SERVER_HELLO 2
#define SSL3_RT_ALERT 21
#define SSL3_VERSION_MINOR 0
#define TLS1_VERSION_MINOR 1
#define TLS1_1_VERSION_MINOR 2
#define SSL3_AL_WARNING 1
#define SSL_CB_READ_ALERT 0x1000
#define SSL_AD_REASON_OFFSET 1000
#define SSL_F_SSL23_GET_SERVER_HELLO 0
#define SSL_R_UNSUPPORTED_PROTOCOL 0
#define SSL_R_UNKNOWN_PROTOCOL 0
#define SSL_R_ONLY_TLS_ALLOWED_IN_FIPS_MODE 0
#define ERR_R_BUF_LIB 0
#define SSL_OP_NO_SSLv2 0
#define SSL_OP_NO_SSLv3 0
#define SSL_OP_NO_TLSv1 0
#define SSL_OP_NO_TLSv1_1 0
#define SSL_OP_NO_TLSv1_2 0
#define SSL_OP_NETSCAPE_CHALLENGE_BUG 0
#define SSL2_CHALLENGE_LENGTH 16
#define SSL2_MAX_CHALLENGE_LENGTH 32
#define SSL3_RANDOM_SIZE 32
#define SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER 0
#define SSL2_ST_GET_SERVER_HELLO_A 0
#define SSL2_VERSION 0
#define SSL3_VERSION 0x0300
#define TLS1_VERSION 0x0301
#define TLS1_1_VERSION 0x0302
#define TLS1_2_VERSION 0x0303
#define SSL_ST_READ_HEADER 0
#define SSL3_ST_CR_SRVR_HELLO_A 0
#define SSL_NOTHING 0
#define TLS_MAX_VERSION TLS1_2_VERSION
#define OPENSSL_FIPS 0
#define OPENSSL_NO_SSL2

typedef struct ssl_method_st {
    int (*ssl_connect)(void *);
} SSL_METHOD;

typedef struct ssl_ctx_st {
    void (*info_callback)(const void *, int, int);
} SSL_CTX;

typedef struct buf_mem_st {
    int dummy;
} BUF_MEM;

struct ssl_st {
    int options;
    int state;
    int rstate;
    int rwstate;
    int version;
    int client_version;
    int packet_length;
    int init_num;
    int (*handshake_func)(struct ssl_st *s);
    SSL_METHOD *method;
    BUF_MEM *init_buf;
    char *packet;
    struct ssl2_state_st *s2;
    struct ssl3_state_st *s3;
    void (*info_callback)(const struct ssl_st *ssl, int type, int val);
    SSL_CTX *ctx;
    void (*msg_callback)(int write_p, int version, int content_type, const void *buf, size_t len, struct ssl_st *ssl, void *arg);
    void *msg_callback_arg;
};

struct ssl2_state_st {
    int ssl2_rollback;
    int challenge_length;
    int rbuf_left;
    int rbuf_offs;
    int write_sequence;
    unsigned char challenge[32];
    unsigned char rbuf[1024];
};

struct ssl3_state_st {
    struct {
        size_t left;
        size_t offset;
        unsigned char *buf;
    } rbuf;
    unsigned char client_random[32];
};

typedef struct ssl_st SSL;

static void SSLerr(int a, int b) {}
static int ssl23_read_bytes(SSL *s, int n) { return 0; }
static int ssl2_new(SSL *s) { return 0; }
static void ssl2_clear(SSL *s) {}
static void ssl3_free(SSL *s) {}
static int BUF_MEM_grow_clean(BUF_MEM *buf, int len) { return 0; }
static int ssl_init_wbio_buffer(SSL *s, int n) { return 0; }
static int ssl3_setup_read_buffer(SSL *s) { return 0; }
static int ssl_get_new_session(SSL *s, int n) { return 0; }
static int SSL_connect(SSL *s) { return 0; }
static int FIPS_mode() { return 0; }
static SSL_METHOD *SSLv2_client_method() { return 0; }
static SSL_METHOD *SSLv3_client_method() { return 0; }
static SSL_METHOD *TLSv1_client_method() { return 0; }
static SSL_METHOD *TLSv1_1_client_method() { return 0; }
static SSL_METHOD *TLSv1_2_client_method() { return 0; }
static void OPENSSL_assert(int x) {}