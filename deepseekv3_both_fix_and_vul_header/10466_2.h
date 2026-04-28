#include <string.h>
#include <stddef.h>

#define SSL_MAX_PIPELINES 4
#define SSL3_RT_HEADER_LENGTH 5
#define SSL3_RT_SEND_MAX_ENCRYPTED_OVERHEAD 256
#define SSL3_ALIGN_PAYLOAD 0
#define EVP_GCM_TLS_EXPLICIT_IV_LEN 8
#define EVP_CCM_TLS_EXPLICIT_IV_LEN 8
#define TLS_ST_CW_CLNT_HELLO 0
#define TLS1_VERSION 0x0301
#define SSL3_RT_APPLICATION_DATA 0x17
#define SSL3_RT_HEADER 0x1000
#define SSL_F_DO_SSL3_WRITE 0
#define SSL_R_COMPRESSION_FAILURE 0
#define ERR_R_INTERNAL_ERROR 0

#define EVP_CIPH_CBC_MODE 1
#define EVP_CIPH_GCM_MODE 2
#define EVP_CIPH_CCM_MODE 3

typedef struct ssl3_record_st {
    unsigned char *data;
    unsigned int length;
    unsigned char *input;
    int type;
} SSL3_RECORD;

typedef struct ssl3_buffer_st {
    unsigned char *buf;
    size_t offset;
    size_t left;
} SSL3_BUFFER;

typedef struct record_layer_st {
    SSL3_BUFFER wbuf[SSL_MAX_PIPELINES];
    unsigned int numwpipes;
    int write_pending;
    unsigned int wpend_tot;
    const unsigned char *wpend_buf;
    int wpend_type;
    int wpend_ret;
} RECORD_LAYER;

typedef struct ssl_session_st {
    /* session structure fields */
} SSL_SESSION;

typedef struct ssl3_state_st {
    int alert_dispatch;
    int empty_fragment_done;
    int need_empty_fragments;
} SSL3_STATE;

typedef struct evp_cipher_ctx_st {
    /* cipher context fields */
} EVP_CIPHER_CTX;

typedef struct evp_md_ctx_st {
    /* message digest context fields */
} EVP_MD_CTX;

typedef struct ssl_method_st {
    int (*ssl_dispatch_alert)(void *);
    struct {
        int (*mac)(void *, SSL3_RECORD *, unsigned char *, int);
        int (*enc)(void *, SSL3_RECORD *, unsigned int, int);
    } *ssl3_enc;
} SSL_METHOD;

typedef struct ssl_st {
    RECORD_LAYER rlayer;
    SSL_SESSION *session;
    SSL3_STATE *s3;
    const SSL_METHOD *method;
    EVP_CIPHER_CTX *enc_write_ctx;
    EVP_MD_CTX *write_hash;
    int version;
    int renegotiate;
    int (*msg_callback)(int, int, int, const void *, size_t, void *, void *);
    void *msg_callback_arg;
    void *compress;
} SSL;

#define SSL_USE_EXPLICIT_IV(s) 0
#define SSL_USE_ETM(s) 0
#define SSL_get_state(s) 0
#define TLS1_get_version(s) 0

#define SSL3_BUFFER_get_buf(wb) ((wb)->buf)
#define SSL3_BUFFER_get_offset(wb) ((wb)->offset)
#define SSL3_BUFFER_set_offset(wb, off) ((wb)->offset = (off))
#define SSL3_BUFFER_set_left(wb, l) ((wb)->left = (l))
#define SSL3_RECORD_set_type(rec, t) ((rec)->type = (t))
#define SSL3_RECORD_set_data(rec, d) ((rec)->data = (d))
#define SSL3_RECORD_set_length(rec, l) ((rec)->length = (l))
#define SSL3_RECORD_set_input(rec, i) ((rec)->input = (i))
#define SSL3_RECORD_add_length(rec, l) ((rec)->length += (l))
#define SSL3_RECORD_reset_input(rec) ((rec)->input = NULL)
#define SSL3_RECORD_get_length(rec) ((rec)->length)
#define RECORD_LAYER_write_pending(rl) ((rl)->write_pending)

static inline int EVP_MD_CTX_size(EVP_MD_CTX *ctx) { return 0; }
static inline void *EVP_MD_CTX_md(EVP_MD_CTX *ctx) { return NULL; }
static inline int EVP_CIPHER_CTX_mode(EVP_CIPHER_CTX *ctx) { return 0; }
static inline int EVP_CIPHER_CTX_iv_length(EVP_CIPHER_CTX *ctx) { return 0; }

void SSLerr(int f, int r);
int ssl3_write_pending(SSL *s, int type, const unsigned char *buf, unsigned int totlen);
int ssl3_setup_write_buffer(SSL *s, unsigned int numpipes, int clear);
int ssl3_do_compress(SSL *s, SSL3_RECORD *wr);

static inline void s2n(unsigned int s, unsigned char *p) {
    p[0] = (unsigned char)(s >> 8);
    p[1] = (unsigned char)(s);
}