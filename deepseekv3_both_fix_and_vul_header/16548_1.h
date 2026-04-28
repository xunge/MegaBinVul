#include <string.h>
#include <limits.h>

typedef struct evp_cipher_st EVP_CIPHER;
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;

struct evp_cipher_st {
    int block_size;
    int flags;
    int (*do_cipher)(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, int inl);
};

struct evp_cipher_ctx_st {
    const EVP_CIPHER *cipher;
    unsigned char buf[64];
    int buf_len;
    int block_mask;
};

#define EVP_CIPH_FLAG_LENGTH_BITS 0
#define EVP_CIPH_CCM_MODE 0
#define EVP_CIPH_FLAG_CUSTOM_CIPHER 0
#define EVP_F_EVP_ENCRYPTDECRYPTUPDATE 0
#define EVP_R_PARTIALLY_OVERLAPPING 0
#define EVP_R_OUTPUT_WOULD_OVERFLOW 0

static int EVP_CIPHER_CTX_test_flags(const EVP_CIPHER_CTX *ctx, int flags);
static int EVP_CIPHER_mode(const EVP_CIPHER *cipher);
static void EVPerr(int lib, int reason);
static int is_partially_overlapping(const unsigned char *a, const unsigned char *b, size_t len);