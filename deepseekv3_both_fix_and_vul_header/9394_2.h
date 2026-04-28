#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define SSL2_MT_CLIENT_HELLO 1
#define SSL3_VERSION_MAJOR 0x03
#define TLS1_VERSION_MINOR 0x01
#define TLS1_1_VERSION_MINOR 0x02
#define TLS1_2_VERSION_MINOR 0x03
#define SSL3_MT_CLIENT_HELLO 1
#define SSL3_RT_HANDSHAKE 22
#define SSL3_RANDOM_SIZE 32
#define SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER (16*1024)

#define SSL_OP_NO_SSLv2 0x01000000L
#define SSL_OP_NO_SSLv3 0x02000000L
#define SSL_OP_NO_TLSv1 0x04000000L
#define SSL_OP_NO_TLSv1_1 0x08000000L
#define SSL_OP_NO_TLSv1_2 0x10000000L

#define SSL3_VERSION 0x0300
#define TLS1_VERSION 0x0301
#define TLS1_1_VERSION 0x0302
#define TLS1_2_VERSION 0x0303
#define TLS_MAX_VERSION TLS1_2_VERSION
#define SSL2_VERSION 0x0002

#define SSL_F_SSL23_GET_CLIENT_HELLO 100
#define SSL_R_UNSUPPORTED_PROTOCOL 101
#define SSL_R_RECORD_TOO_SMALL 102
#define SSL_R_HTTP_REQUEST 103
#define SSL_R_HTTPS_PROXY_REQUEST 104
#define SSL_R_RECORD_TOO_LARGE 105
#define SSL_R_RECORD_LENGTH_MISMATCH 106
#define SSL_R_UNKNOWN_PROTOCOL 107
#define SSL_R_ONLY_TLS_ALLOWED_IN_FIPS_MODE 108

#define SSL23_ST_SR_CLNT_HELLO_A 0x210
#define SSL23_ST_SR_CLNT_HELLO_B 0x211
#define SSL2_ST_GET_CLIENT_HELLO_A 0x110
#define SSL3_ST_SR_CLNT_HELLO_A 0x120
#define SSL_ST_READ_HEADER 0x10

#define OPENSSL_FIPS
#define OPENSSL_NO_SSL2
#define OPENSSL_assert(x) assert(x)

typedef struct ssl_st SSL;
typedef struct ssl3_state_st SSL3_STATE;
typedef struct ssl2_state_st SSL2_STATE;

struct buf_mem_st {
    void *data;
};

struct ssl_st {
    int state;
    int version;
    unsigned long options;
    char *packet;
    unsigned int packet_length;
    struct buf_mem_st *init_buf;
    SSL3_STATE *s3;
    SSL2_STATE *s2;
    int (*handshake_func)(SSL *);
    const struct ssl_method_st *method;
    int rstate;
    int init_num;
    int (*msg_callback)(int, int, int, const void *, size_t, SSL *, void *);
    void *msg_callback_arg;
};

struct ssl3_state_st {
    struct {
        unsigned char *buf;
        unsigned int left;
        unsigned int offset;
    } rbuf;
    struct {
        int reuse_message;
        int message_type;
        unsigned long message_size;
    } tmp;
};

struct ssl_method_st {
    int (*ssl_accept)(SSL *);
};

static inline void n2s(const unsigned char *p, unsigned int *n) {
    *n = ((unsigned int)(p[0])) << 8 | (unsigned int)(p[1]);
}

static inline void s2n(unsigned int s, unsigned char *p) {
    p[0] = (unsigned char)(s >> 8);
    p[1] = (unsigned char)(s);
}

static inline void l2n3(unsigned long l, unsigned char *p) {
    p[0] = (unsigned char)(l >> 16);
    p[1] = (unsigned char)(l >> 8);
    p[2] = (unsigned char)(l);
}

static void SSLerr(int a, int b) {}
static int ssl3_setup_buffers(SSL *s) { return 1; }
static int ssl23_read_bytes(SSL *s, int n) { return n; }
static void ssl3_finish_mac(SSL *s, const unsigned char *buf, int len) {}
static int ssl2_new(SSL *s) { return 1; }
static void ssl2_clear(SSL *s) {}
static void ssl3_free(SSL *s) {}
static int ssl3_setup_read_buffer(SSL *s) { return 1; }
static int ssl_init_wbio_buffer(SSL *s, int push) { return 1; }
static int SSL_accept(SSL *s) { return 1; }
static int FIPS_mode() { return 0; }
static void OPENSSL_free(void *ptr) { free(ptr); }

static const struct ssl_method_st *SSLv2_server_method(void) { return NULL; }
static const struct ssl_method_st *SSLv3_server_method(void) { return NULL; }
static const struct ssl_method_st *TLSv1_server_method(void) { return NULL; }
static const struct ssl_method_st *TLSv1_1_server_method(void) { return NULL; }
static const struct ssl_method_st *TLSv1_2_server_method(void) { return NULL; }