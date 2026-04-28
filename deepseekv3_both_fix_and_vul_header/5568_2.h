#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

typedef struct ssl3_buffer_st {
    unsigned char *buf;
    unsigned int len;
    unsigned int offset;
    unsigned int left;
} SSL3_BUFFER;

typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;
typedef struct evp_cipher_st EVP_CIPHER;

struct ssl3_state_st {
    SSL3_BUFFER wbuf;
    unsigned int wnum;
    unsigned int wpend_tot;
    const unsigned char *wpend_buf;
    int wpend_type;
    int wpend_ret;
    unsigned char write_sequence[8];
    int alert_dispatch;
    int empty_fragment_done;
};

typedef struct ssl_st {
    struct ssl3_state_st *s3;
    int rwstate;
    int in_handshake;
    int (*handshake_func)(struct ssl_st *s);
    int max_send_fragment;
    void *compress;
    void *msg_callback;
    EVP_CIPHER_CTX *enc_write_ctx;
    int mode;
    int version;
    struct {
        int (*ssl_dispatch_alert)(struct ssl_st *s);
    } *method;
} SSL;

#define SSL_F_SSL3_WRITE_BYTES 0
#define SSL_R_SSL_HANDSHAKE_FAILURE 0
#define SSL_R_BAD_LENGTH 0
#define SSL_R_BAD_WRITE_RETRY 0
#define ERR_R_MALLOC_FAILURE 0

#define OPENSSL_NO_MULTIBLOCK 0
#define EVP_CIPH_FLAG_TLS1_1_MULTIBLOCK 0
#define SSL3_RT_APPLICATION_DATA 0
#define SSL_NOTHING 0
#define SSL_MODE_RELEASE_BUFFERS 0
#define SSL_MODE_ENABLE_PARTIAL_WRITE 0
#define SSL_IS_DTLS(s) 0
#define SSL_USE_EXPLICIT_IV(s) 0

#define OPENSSL_assert(x) assert(x)
#define OPENSSL_malloc(x) malloc(x)
#define OPENSSL_free(x) free(x)

typedef struct {
    unsigned char *out;
    const unsigned char *inp;
    unsigned int len;
    unsigned int interleave;
} EVP_CTRL_TLS1_1_MULTIBLOCK_PARAM;

int SSL_in_init(SSL *s);
int ssl3_write_pending(SSL *s, int type, const void *buf, int len);
int do_ssl3_write(SSL *s, int type, const void *buf, int len, int dummy);
void ssl3_release_write_buffer(SSL *s);
void SSLerr(int func, int reason);