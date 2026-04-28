#include <stddef.h>
#include <string.h>
#include <assert.h>

#define SSL_MAX_PIPELINES 8
#define EVP_AEAD_TLS1_AAD_LEN 13
#define EVP_GCM_TLS_EXPLICIT_IV_LEN 8
#define EVP_CCM_TLS_EXPLICIT_IV_LEN 8
#define EVP_CIPH_CBC_MODE 1
#define EVP_CIPH_GCM_MODE 2
#define EVP_CIPH_CCM_MODE 3
#define EVP_CIPH_FLAG_PIPELINE 0x1000
#define EVP_CIPH_FLAG_AEAD_CIPHER 0x2000
#define EVP_CIPH_FLAG_CUSTOM_CIPHER 0x4000
#define EVP_CTRL_AEAD_TLS1_AAD 0x10
#define EVP_CTRL_SET_PIPELINE_OUTPUT_BUFS 0x11
#define EVP_CTRL_SET_PIPELINE_INPUT_BUFS 0x12
#define EVP_CTRL_SET_PIPELINE_INPUT_LENS 0x13

typedef struct SSL {
    struct {
        unsigned char *write_sequence;
        unsigned char *read_sequence;
        int w_epoch;
        int r_epoch;
    } rlayer;
    void *enc_write_ctx;
    void *enc_read_ctx;
    void *write_hash;
    void *read_hash;
    void *session;
    int version;
} SSL;

typedef struct SSL3_RECORD {
    unsigned char *data;
    unsigned char *input;
    size_t length;
    unsigned char type;
} SSL3_RECORD;

typedef struct EVP_CIPHER_CTX EVP_CIPHER_CTX;
typedef struct EVP_CIPHER EVP_CIPHER;
typedef struct EVP_MD_CTX EVP_MD_CTX;

#define SSL_USE_EXPLICIT_IV(s) 1
#define SSL_IS_DTLS(s) 0
#define SSL_USE_ETM(s) 0
#define SSL_F_TLS1_ENC 0
#define SSL_R_PIPELINE_FAILURE 0
#define ERR_R_INTERNAL_ERROR 0

#define OPENSSL_assert(x) assert(x)
#define SSLerr(f,r) 0
#define RECORD_LAYER_get_write_sequence(r) ((r)->write_sequence)
#define RECORD_LAYER_get_read_sequence(r) ((r)->read_sequence)
#define DTLS_RECORD_LAYER_get_w_epoch(r) ((r)->w_epoch)
#define DTLS_RECORD_LAYER_get_r_epoch(r) ((r)->r_epoch)

static inline int EVP_MD_CTX_md(EVP_MD_CTX *ctx) { return 0; }
static inline int EVP_MD_CTX_size(EVP_MD_CTX *ctx) { return 0; }
static inline const EVP_CIPHER *EVP_CIPHER_CTX_cipher(EVP_CIPHER_CTX *ctx) { return NULL; }
static inline int EVP_CIPHER_mode(const EVP_CIPHER *cipher) { return 0; }
static inline int EVP_CIPHER_iv_length(const EVP_CIPHER *cipher) { return 0; }
static inline int EVP_CIPHER_block_size(const EVP_CIPHER *cipher) { return 0; }
static inline int EVP_CIPHER_flags(const EVP_CIPHER *cipher) { return 0; }
static inline int EVP_CIPHER_CTX_ctrl(EVP_CIPHER_CTX *ctx, int type, int arg, void *ptr) { return 0; }
static inline int EVP_Cipher(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, unsigned int inl) { return 0; }
static inline int RAND_bytes(unsigned char *buf, int num) { return 0; }
static inline void s2n(unsigned int s, unsigned char *p) { *p++ = (s >> 8) & 0xff; *p = s & 0xff; }

static inline int constant_time_eq_int(int a, int b) { return a == b; }
static inline int constant_time_select_int(int a, int b, int c) { return a ? b : c; }

int tls1_cbc_remove_padding(SSL *s, SSL3_RECORD *rec, int bs, int mac_size);