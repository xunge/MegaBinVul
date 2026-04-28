#include <string.h>
#include <stdlib.h>

#define SSL2_MT_CLIENT_HELLO 1
#define SSL3_VERSION_MAJOR 3
#define TLS1_VERSION_MINOR 1
#define TLS1_1_VERSION_MINOR 2
#define TLS1_2_VERSION_MINOR 3
#define SSL3_MT_CLIENT_HELLO 1
#define SSL3_RT_HANDSHAKE 22
#define SSL3_RANDOM_SIZE 32
#define SSL_OP_NO_SSLv2 0x01000000
#define SSL_OP_NO_SSLv3 0x02000000
#define SSL_OP_NO_TLSv1 0x04000000
#define SSL_OP_NO_TLSv1_1 0x08000000
#define SSL_OP_NO_TLSv1_2 0x10000000
#define SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER 32767
#define SSL3_VERSION 0x0300
#define TLS1_VERSION 0x0301
#define TLS1_1_VERSION 0x0302
#define TLS1_2_VERSION 0x0303
#define SSL23_ST_SR_CLNT_HELLO_A 0x210
#define SSL23_ST_SR_CLNT_HELLO_B 0x211
#define SSL2_ST_GET_CLIENT_HELLO_A 0x110
#define SSL3_ST_SR_CLNT_HELLO_A 0x120
#define SSL2_VERSION 0x0002
#define SSL_ST_READ_HEADER 1
#define SSL_F_SSL23_GET_CLIENT_HELLO 100
#define SSL_R_HTTP_REQUEST 1000
#define SSL_R_HTTPS_PROXY_REQUEST 1001
#define SSL_R_ONLY_TLS_1_2_ALLOWED_IN_SUITEB_MODE 1002
#define SSL_R_VERSION_TOO_LOW 1003
#define SSL_R_RECORD_TOO_LARGE 1004
#define SSL_R_RECORD_LENGTH_MISMATCH 1005
#define SSL_R_UNSUPPORTED_PROTOCOL 1006
#define SSL_R_UNKNOWN_PROTOCOL 1007
#define SSL_R_ONLY_TLS_ALLOWED_IN_FIPS_MODE 1008
#define SSL_R_RECORD_TOO_SMALL 1009
#define SSL_SECOP_VERSION 1
#define OPENSSL_NO_SSL2
#define OPENSSL_FIPS
#define FIPS_mode() 0

typedef struct ssl_st {
    int state;
    int version;
    unsigned long options;
    char *packet;
    unsigned int packet_length;
    struct ssl3_state_st *s3;
    struct ssl2_state_st *s2;
    struct buf_mem_st *init_buf;
    int (*handshake_func)(struct ssl_st *);
    const struct ssl_method_st *method;
    int (*msg_callback)(int, int, int, const void *, size_t, struct ssl_st *, void *);
    void *msg_callback_arg;
    int rstate;
    int init_num;
} SSL;

typedef struct ssl3_state_st {
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
} SSL3_STATE;

typedef struct ssl2_state_st {
    unsigned char rbuf[SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER];
    unsigned int rbuf_left;
    unsigned int rbuf_offs;
    int ssl2_rollback;
} SSL2_STATE;

typedef struct buf_mem_st {
    char *data;
} BUF_MEM;

struct ssl_method_st {
    int (*ssl_accept)(SSL *);
};

#define n2s(c,s) ((s=(((unsigned int)(c[0]))<<8)|(((unsigned int)(c[1])))),c+=2)
#define s2n(s,c) ((c[0]=(unsigned char)(((s)>>8)&0xff), \
                  c[1]=(unsigned char)(((s))&0xff)),c+=2)
#define l2n3(l,c) (*((c)++)=(unsigned char)(((l)>>16L)&0xff), \
                 *((c)++)=(unsigned char)(((l)>>8L)&0xff), \
                 *((c)++)=(unsigned char)(((l))&0xff))

int ssl3_setup_buffers(SSL *s);
int ssl23_read_bytes(SSL *s, int n);
void SSLerr(int f, int r);
int tls1_suiteb(SSL *s);
int ssl_security(SSL *s, int op, int bits, int version, void *arg);
void ssl3_finish_mac(SSL *s, const unsigned char *buf, int len);
int ssl2_new(SSL *s);
void ssl2_clear(SSL *s);
void ssl3_free(SSL *s);
int BUF_MEM_grow_clean(BUF_MEM *buf, int len);
int ssl_init_wbio_buffer(SSL *s, int push);
int ssl3_setup_read_buffer(SSL *s);
int SSL_accept(SSL *s);
const struct ssl_method_st *SSLv2_server_method(void);
const struct ssl_method_st *SSLv3_server_method(void);
const struct ssl_method_st *TLSv1_server_method(void);
const struct ssl_method_st *TLSv1_1_server_method(void);
const struct ssl_method_st *TLSv1_2_server_method(void);
void OPENSSL_free(void *ptr);