#include <stdio.h>
#include <string.h>
#include <assert.h>

#define EVP_CIPH_CBC_MODE 1

typedef struct ssl3_record_st {
    unsigned char type;
    unsigned char *input;
    unsigned char *data;
    size_t length;
    size_t orig_len;
} SSL3_RECORD;

typedef struct evp_md_ctx_st {
    int dummy;
} EVP_MD_CTX;

typedef struct evp_cipher_ctx_st {
    int dummy;
} EVP_CIPHER_CTX;

typedef struct ssl3_state_st {
    unsigned char *read_mac_secret;
    size_t read_mac_secret_size;
} SSL3_STATE;

typedef struct record_layer_st {
    unsigned char read_sequence[8];
    unsigned char write_sequence[8];
    unsigned int r_epoch;
    unsigned int w_epoch;
} RECORD_LAYER;

typedef struct ssl_st {
    RECORD_LAYER rlayer;
    EVP_MD_CTX *write_hash;
    EVP_MD_CTX *read_hash;
    EVP_CIPHER_CTX *enc_read_ctx;
    SSL3_STATE *s3;
    int version;
    int mac_flags;
} SSL;

#define SSL_MAC_FLAG_WRITE_MAC_STREAM 0x01
#define SSL_MAC_FLAG_READ_MAC_STREAM 0x02
#define SSL_USE_ETM(s) 0
#define SSL_IS_DTLS(s) 0
#define FIPS_mode() 0
#define OPENSSL_assert(x) assert(x)

#define RECORD_LAYER_get_write_sequence(rl) ((rl)->write_sequence)
#define RECORD_LAYER_get_read_sequence(rl) ((rl)->read_sequence)
#define DTLS_RECORD_LAYER_get_w_epoch(rl) ((rl)->w_epoch)
#define DTLS_RECORD_LAYER_get_r_epoch(rl) ((rl)->r_epoch)

#define s2n(s,p) do { \
        *(p)++ = (unsigned char)(((s) >> 8) & 0xff); \
        *(p)++ = (unsigned char)((s) & 0xff); \
    } while(0)

static int EVP_MD_CTX_size(EVP_MD_CTX *ctx) { return 0; }
static EVP_MD_CTX *EVP_MD_CTX_new(void) { return NULL; }
static int EVP_MD_CTX_copy(EVP_MD_CTX *out, EVP_MD_CTX *in) { return 0; }
static void EVP_MD_CTX_free(EVP_MD_CTX *ctx) {}
static int EVP_DigestSignUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt) { return 0; }
static int EVP_DigestSignFinal(EVP_MD_CTX *ctx, unsigned char *md, size_t *s) { return 0; }
static int EVP_CIPHER_CTX_mode(EVP_CIPHER_CTX *ctx) { return 0; }
static int ssl3_cbc_record_digest_supported(EVP_MD_CTX *ctx) { return 0; }
static int ssl3_cbc_digest_record(EVP_MD_CTX *ctx, unsigned char *md, size_t *md_size,
                                 unsigned char header[13], const unsigned char *data,
                                 size_t data_plus_mac_size, size_t data_plus_mac_plus_padding_size,
                                 const unsigned char *mac_secret, size_t mac_secret_size, int is_sslv3) { return 0; }
static int tls_fips_digest_extra(EVP_CIPHER_CTX *ctx, EVP_MD_CTX *mac_ctx,
                                const unsigned char *data, size_t data_len, size_t orig_len) { return 0; }