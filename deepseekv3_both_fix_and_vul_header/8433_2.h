#include <stdio.h>
#include <string.h>
#include <assert.h>

#define SSL3_RT_MAX_ENCRYPTED_LENGTH 16834
#define SSL3_RT_MAX_COMPRESSED_LENGTH 16834
#define SSL3_RT_MAX_PLAIN_LENGTH 16384
#define EVP_MAX_MD_SIZE 64
#define DTLS1_RT_HEADER_LENGTH 13
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

typedef struct ssl3_record_st {
    unsigned char *data;
    unsigned char *input;
    unsigned int length;
    unsigned int orig_len;
    unsigned int off;
} SSL3_RECORD;

typedef struct dtls1_bitmap_st {
    unsigned long map;
    unsigned long max_seq_num;
} DTLS1_BITMAP;

typedef struct ssl_session_st {
    int dummy;
} SSL_SESSION;

typedef struct ssl_method_st {
    struct {
        int (*enc)(void*, SSL3_RECORD*, int, int);
        int (*mac)(void*, SSL3_RECORD*, unsigned char*, int);
    } *ssl3_enc;
} SSL_METHOD;

typedef struct evp_md_ctx_st {
    int dummy;
} EVP_MD_CTX;

typedef struct evp_cipher_ctx_st {
    int dummy;
} EVP_CIPHER_CTX;

typedef struct ssl_st {
    struct {
        SSL3_RECORD rrec;
        unsigned char *packet;
        unsigned int packet_length;
    } rlayer;
    SSL_SESSION *session;
    SSL_METHOD *method;
    EVP_CIPHER_CTX *enc_read_ctx;
    EVP_MD_CTX *read_hash;
    void *expand;
} SSL;

#define RECORD_LAYER_get_rrec(x) (&(x)->rrec)
#define RECORD_LAYER_get_packet(x) ((x)->packet)
#define RECORD_LAYER_reset_packet_length(x) ((x)->packet_length = 0)
#define OPENSSL_assert(x) assert(x)

int EVP_MD_CTX_md(EVP_MD_CTX *ctx) { return 1; }
unsigned int EVP_MD_CTX_size(EVP_MD_CTX *ctx) { return 0; }
int EVP_CIPHER_CTX_mode(EVP_CIPHER_CTX *ctx) { return 0; }
int CRYPTO_memcmp(const void *a, const void *b, size_t len) { return memcmp(a, b, len); }

void SSLerr(int f, int r) {}
void ssl3_send_alert(SSL *s, int level, int desc) {}
int ssl3_do_uncompress(SSL *s, SSL3_RECORD *rr) { return 1; }
void ssl3_cbc_copy_mac(unsigned char *out, const SSL3_RECORD *rec, unsigned int md_size) {}
void dtls1_record_bitmap_update(SSL *s, DTLS1_BITMAP *bitmap) {}