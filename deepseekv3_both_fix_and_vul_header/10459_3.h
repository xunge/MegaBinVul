#include <string.h>
#include <assert.h>

#define SSL3_RT_HEADER_LENGTH 5
#define SSL2_MT_CLIENT_HELLO 1
#define SSL2_VERSION 0x0002
#define SSL2_RT_HEADER_LENGTH 2
#define MIN_SSL2_RECORD_LEN 9
#define SSL3_RT_HANDSHAKE 22
#define SSL3_RT_HEADER 0x1000
#define SSL3_RT_ALERT 21
#define SSL3_RT_APPLICATION_DATA 23
#define SSL3_VERSION_MAJOR 0x03
#define SSL3_RT_MAX_ENCRYPTED_LENGTH 16384
#define SSL3_RT_MAX_COMPRESSED_LENGTH 16384
#define SSL3_RT_MAX_PLAIN_LENGTH 16384
#define MAX_EMPTY_RECORDS 32
#define EVP_MAX_MD_SIZE 64

#define SSL_AD_RECORD_OVERFLOW 22
#define SSL_AD_HANDSHAKE_FAILURE 40
#define SSL_AD_PROTOCOL_VERSION 70
#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_BAD_RECORD_MAC 20
#define SSL_AD_DECRYPTION_FAILED 21
#define SSL_AD_DECOMPRESSION_FAILURE 30
#define SSL_AD_UNEXPECTED_MESSAGE 10
#define SSL3_AL_FATAL 2

#define SSL_F_SSL3_GET_RECORD 0
#define SSL_R_PACKET_LENGTH_TOO_LONG 0
#define SSL_R_LENGTH_TOO_SHORT 0
#define SSL_R_WRONG_VERSION_NUMBER 0
#define SSL_R_HTTP_REQUEST 0
#define SSL_R_HTTPS_PROXY_REQUEST 0
#define SSL_R_ENCRYPTED_LENGTH_TOO_LONG 0
#define SSL_R_DECRYPTION_FAILED_OR_BAD_RECORD_MAC 0
#define SSL_R_BLOCK_CIPHER_PAD_IS_WRONG 0
#define SSL_R_COMPRESSED_LENGTH_TOO_LONG 0
#define SSL_R_BAD_DECOMPRESSION 0
#define SSL_R_DATA_LENGTH_TOO_LONG 0
#define SSL_R_RECORD_TOO_SMALL 0

#define SSL_ST_READ_BODY 1
#define SSL_ST_READ_HEADER 2

#define SSL_USE_EXPLICIT_IV(s) 0
#define SSL_USE_ETM(s) 0

#define EVP_CIPH_CBC_MODE 1
#define EVP_CIPH_FLAG_PIPELINE (1L<<9)

typedef struct ssl3_record_st {
    int type;
    unsigned int length;
    unsigned int off;
    unsigned char *data;
    unsigned char *input;
    unsigned int orig_len;
    unsigned int rec_version;
    unsigned int read;
} SSL3_RECORD;

typedef struct ssl3_buffer_st {
    unsigned char *buf;
    size_t len;
} SSL3_BUFFER;

typedef struct ssl_session_st {
    int dummy;
} SSL_SESSION;

typedef struct ssl_st SSL;

struct ssl3_enc_method_st {
    int (*mac)(SSL *, SSL3_RECORD *, unsigned char *, int);
    int (*enc)(SSL *, SSL3_RECORD *, unsigned int, int);
};

typedef struct ssl_method_st {
    struct ssl3_enc_method_st *ssl3_enc;
} SSL_METHOD;

struct ssl_st {
    int server;
    int version;
    int first_packet;
    SSL_SESSION *session;
    void *enc_read_ctx;
    void *read_hash;
    void *write_hash;
    void *enc_write_ctx;
    void *expand;
    void *rlayer;
    SSL_METHOD *method;
    int (*msg_callback)(int, int, int, const void *, size_t, SSL *, void *);
    void *msg_callback_arg;
    int max_pipelines;
};

#define CRYPTO_memcmp(a, b, n) memcmp(a, b, n)
#define OPENSSL_assert(x) assert(x)
#define SSLerr(f, r) (void)0
#define n2s(p, s) ((s) = ((unsigned int)(p)[0] << 8) | (p)[1]), (p) += 2

static inline SSL3_RECORD *RECORD_LAYER_get_rrec(void *rlayer) { return NULL; }
static inline SSL3_BUFFER *RECORD_LAYER_get_rbuf(void *rlayer) { return NULL; }
static inline int RECORD_LAYER_get_rstate(void *rlayer) { return 0; }
static inline size_t RECORD_LAYER_get_packet_length(void *rlayer) { return 0; }
static inline unsigned char *RECORD_LAYER_get_packet(void *rlayer) { return NULL; }
static inline int RECORD_LAYER_is_first_record(void *rlayer) { return 0; }
static inline void RECORD_LAYER_set_rstate(void *rlayer, int state) {}
static inline void RECORD_LAYER_reset_packet_length(void *rlayer) {}
static inline void RECORD_LAYER_clear_first_record(void *rlayer) {}
static inline void RECORD_LAYER_inc_empty_record_count(void *rlayer) {}
static inline int RECORD_LAYER_get_empty_record_count(void *rlayer) { return 0; }
static inline void RECORD_LAYER_reset_empty_record_count(void *rlayer) {}
static inline void RECORD_LAYER_set_numrpipes(void *rlayer, unsigned int num) {}
static inline size_t SSL3_BUFFER_get_len(SSL3_BUFFER *rbuf) { return 0; }
static inline int ssl3_read_n(SSL *s, int n1, int n2, int extend, int clearold) { return 0; }
static inline int ssl3_record_app_data_waiting(SSL *s) { return 0; }
static inline void ssl3_cbc_copy_mac(unsigned char *mac, SSL3_RECORD *rr, unsigned int mac_size) {}
static inline int ssl3_do_uncompress(SSL *s, SSL3_RECORD *rr) { return 0; }
static inline void ssl3_send_alert(SSL *s, int level, int desc) {}

static inline int EVP_MD_CTX_size(void *ctx) { return 0; }
static inline void *EVP_MD_CTX_md(void *ctx) { return NULL; }
static inline int EVP_CIPHER_CTX_mode(void *ctx) { return 0; }
static inline void *EVP_CIPHER_CTX_cipher(void *ctx) { return NULL; }
static inline long EVP_CIPHER_flags(void *cipher) { return 0; }