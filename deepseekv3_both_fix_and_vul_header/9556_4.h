#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define SSL2_MT_CLIENT_HELLO 1
#define SSL3_VERSION_MAJOR 0x03
#define TLS1_VERSION_MINOR 0x01
#define SSL3_MT_CLIENT_HELLO 1
#define SSL3_RT_HANDSHAKE 0x16
#define SSL3_RANDOM_SIZE 32
#define SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER (16*1024)
#define SSL2_VERSION 0x0002
#define SSL_ST_READ_HEADER 1

#define SSL_OP_NO_SSLv2 0x01000000
#define SSL_OP_NO_SSLv3 0x02000000
#define SSL_OP_NO_TLSv1 0x04000000

#define SSL_F_SSL23_GET_CLIENT_HELLO 100
#define SSL_R_UNSUPPORTED_PROTOCOL 101
#define SSL_R_RECORD_TOO_SMALL 102
#define SSL_R_HTTP_REQUEST 103
#define SSL_R_HTTPS_PROXY_REQUEST 104
#define SSL_R_ONLY_TLS_ALLOWED_IN_FIPS_MODE 105
#define SSL_R_RECORD_TOO_LARGE 106
#define SSL_R_RECORD_LENGTH_MISMATCH 107
#define SSL_R_UNKNOWN_PROTOCOL 108

#define SSL23_ST_SR_CLNT_HELLO_A 0x210
#define SSL23_ST_SR_CLNT_HELLO_B 0x211
#define SSL3_ST_SR_CLNT_HELLO_A 0x120
#define SSL2_ST_GET_CLIENT_HELLO_A 0x110

#define TLS1_VERSION 0x0301
#define SSL3_VERSION 0x0300
#define TLS_MAX_VERSION 0x0302

#define OPENSSL_FIPS
#define OPENSSL_NO_SSL2

#define n2s(c,s) (s = ((unsigned int)(c[0]) << 8) | (unsigned int)(c[1]), c += 2)
#define s2n(s,c) (c[0] = (unsigned char)((s) >> 8), c[1] = (unsigned char)(s), c += 2)
#define l2n3(l,c) (c[0] = (unsigned char)((l) >> 16), c[1] = (unsigned char)((l) >> 8), c[2] = (unsigned char)(l), c += 3)

typedef struct ssl_st SSL;
typedef struct ssl3_state_st SSL3_STATE;
typedef struct ssl2_state_st SSL2_STATE;
typedef struct buf_mem_st BUF_MEM;
typedef struct ssl_method_st {
    int (*ssl_accept)(SSL *);
} SSL_METHOD;

struct ssl_st {
    int state;
    int version;
    unsigned long options;
    int (*handshake_func)(SSL *);
    const SSL_METHOD *method;
    SSL2_STATE *s2;
    SSL3_STATE *s3;
    BUF_MEM *init_buf;
    char *packet;
    unsigned int packet_length;
    int rstate;
    int init_num;
    int (*msg_callback)(int, int, int, const void *, size_t, SSL *, void *);
    void *msg_callback_arg;
};

struct ssl3_state_st {
    struct {
        unsigned int reuse_message;
        int message_type;
        unsigned long message_size;
    } tmp;
    struct {
        unsigned char *buf;
        unsigned int left;
        unsigned int offset;
    } rbuf;
};

struct ssl2_state_st {
    unsigned char rbuf[SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER];
    unsigned int rbuf_left;
    unsigned int rbuf_offs;
    int ssl2_rollback;
};

struct buf_mem_st {
    char *data;
};

static void SSLerr(int f, int r) {}
static int ssl3_setup_buffers(SSL *s) { return 1; }
static int ssl23_read_bytes(SSL *s, int n) { return n; }
static void ssl3_finish_mac(SSL *s, const unsigned char *buf, int len) {}
static int ssl2_new(SSL *s) { return 1; }
static void ssl2_clear(SSL *s) {}
static void ssl3_free(SSL *s) {}
static int BUF_MEM_grow_clean(BUF_MEM *buf, int len) { return 1; }
static int ssl_init_wbio_buffer(SSL *s, int push) { return 1; }
static int SSL_accept(SSL *s) { return 1; }
static const SSL_METHOD *ssl23_get_server_method(int version) { return NULL; }
static const SSL_METHOD *SSLv2_server_method(void) { return NULL; }
static int FIPS_mode(void) { return 0; }
static void OPENSSL_assert(int x) { assert(x); }
static void OPENSSL_free(void *ptr) { free(ptr); }