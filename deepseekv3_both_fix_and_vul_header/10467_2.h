#include <string.h>

#define OPENSSL_NO_MULTIBLOCK 0
#define EVP_CIPH_FLAG_TLS1_1_MULTIBLOCK 0
#define EVP_CIPH_FLAG_PIPELINE 0
#define SSL_MAX_PIPELINES 1
#define SSL_MODE_RELEASE_BUFFERS 0
#define SSL_MODE_ENABLE_PARTIAL_WRITE 0
#define SSL_F_SSL3_WRITE_BYTES 0
#define SSL_R_SSL_NEGATIVE_LENGTH 0
#define SSL_R_BAD_LENGTH 0
#define SSL_R_SSL_HANDSHAKE_FAILURE 0
#define SSL_R_BAD_WRITE_RETRY 0
#define ERR_R_MALLOC_FAILURE 0
#define ERR_R_INTERNAL_ERROR 0
#define SSL_NOTHING 0
#define SSL3_RT_APPLICATION_DATA 0x17

typedef struct ssl3_buffer_st {
    unsigned char *buf;
    unsigned int left;
    unsigned int len;
    unsigned int offset;
} SSL3_BUFFER;

typedef struct ssl3_state_st {
    int alert_dispatch;
    int empty_fragment_done;
} SSL3_STATE;

typedef struct bio_st BIO;

typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;
typedef struct evp_cipher_st EVP_CIPHER;

typedef struct ssl_st {
    int rwstate;
    int wnum;
    int max_send_fragment;
    int split_send_fragment;
    int max_pipelines;
    int mode;
    int version;
    SSL3_STATE *s3;
    BIO *wbio;
    EVP_CIPHER_CTX *enc_write_ctx;
    SSL3_BUFFER *wbuf;
    unsigned char write_sequence[8];
    int (*handshake_func)(struct ssl_st *);
    struct {
        int (*ssl_dispatch_alert)(struct ssl_st *);
    } method;
    void *compress;
    void *msg_callback;
    struct {
        int wnum;
        SSL3_BUFFER *wbuf;
        unsigned char write_sequence[8];
        int wpend_tot;
        void *wpend_buf;
        int wpend_type;
        int wpend_ret;
    } rlayer;
} SSL;

typedef struct {
    unsigned char *out;
    const unsigned char *inp;
    unsigned int len;
    unsigned int interleave;
} EVP_CTRL_TLS1_1_MULTIBLOCK_PARAM;

#define SSL_in_init(s) 0
#define ossl_statem_get_in_handshake(s) 0
#define SSL_USE_ETM(s) 0
#define SSL_USE_EXPLICIT_IV(s) 0
#define SSL_IS_DTLS(s) 0

int EVP_CIPHER_flags(const EVP_CIPHER *cipher) { return 0; }
const EVP_CIPHER *EVP_CIPHER_CTX_cipher(const EVP_CIPHER_CTX *ctx) { return NULL; }

void SSLerr(int a, int b) {}
int ssl3_write_pending(SSL *s, int type, const void *buf, int len) { return 0; }
void ssl3_release_write_buffer(SSL *s) {}
int ssl3_setup_write_buffer(SSL *s, int a, int b) { return 0; }
int do_ssl3_write(SSL *s, int type, const void *buf, unsigned int *lens, unsigned int num, int a) { return 0; }