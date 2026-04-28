#include <stddef.h>
#include <string.h>

#define DTLS1_RT_HEADER_LENGTH 13
#define SSL3_RT_HEADER_LENGTH 5
#define SSL3_RT_MAX_ENCRYPTED_LENGTH 18432
#define SSL3_RT_MAX_COMPRESSED_LENGTH 18432
#define SSL3_RT_MAX_PLAIN_LENGTH 16384
#define EVP_MAX_MD_SIZE 64

typedef struct ssl3_record_st {
    unsigned char *data;
    unsigned char *input;
    unsigned int length;
    unsigned int orig_len;
    unsigned int off;
} SSL3_RECORD;

typedef struct ssl_method_st {
    struct {
        int (*enc)(void *, int);
        int (*mac)(void *, unsigned char *, int);
    } *ssl3_enc;
} SSL_METHOD;

typedef struct ssl3_state_st {
    SSL3_RECORD rrec;
} SSL3_STATE;

typedef struct dtls1_state_st {
    struct {
        unsigned long bitmap;
    } *bitmap;
} DTLS1_STATE;

typedef struct ssl_session_st SSL_SESSION;
typedef struct evp_md_ctx_st EVP_MD_CTX;
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;

typedef struct ssl_st {
    SSL_SESSION *session;
    SSL3_STATE *s3;
    SSL_METHOD *method;
    EVP_CIPHER_CTX *enc_read_ctx;
    EVP_MD_CTX *read_hash;
    DTLS1_STATE *d1;
    void *expand;
    unsigned char *packet;
    unsigned int packet_length;
} SSL;

#define SSL_AD_RECORD_OVERFLOW 22
#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_DECOMPRESSION_FAILURE 30
#define SSL_F_DTLS1_PROCESS_RECORD 0
#define SSL_R_ENCRYPTED_LENGTH_TOO_LONG 0
#define SSL_R_LENGTH_TOO_SHORT 0
#define SSL_R_COMPRESSED_LENGTH_TOO_LONG 0
#define SSL_R_BAD_DECOMPRESSION 0
#define SSL_R_DATA_LENGTH_TOO_LONG 0
#define SSL3_AL_FATAL 2
#define EVP_CIPH_CBC_MODE 1

void SSLerr(int f, int r);
void ssl3_send_alert(SSL *s, int level, int desc);
int ssl3_do_uncompress(SSL *s);
void ssl3_cbc_copy_mac(unsigned char *mac, SSL3_RECORD *rr, unsigned int mac_size);
int CRYPTO_memcmp(const void *a, const void *b, size_t len);
void OPENSSL_assert(int condition);
void dtls1_record_bitmap_update(SSL *s, void *bitmap);

static inline int EVP_MD_CTX_md(EVP_MD_CTX *ctx) { return ctx != NULL; }
static inline unsigned int EVP_MD_CTX_size(EVP_MD_CTX *ctx) { return EVP_MAX_MD_SIZE; }
static inline int EVP_CIPHER_CTX_mode(EVP_CIPHER_CTX *ctx) { return EVP_CIPH_CBC_MODE; }