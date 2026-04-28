#include <string.h>
#include <assert.h>

#define EVP_CIPH_FLAG_CUSTOM_CIPHER 0x0010

struct evp_cipher_st {
    int flags;
    int block_size;
    int (*do_cipher)(struct evp_cipher_ctx_st *ctx, unsigned char *out, const unsigned char *in, int inl);
};

typedef struct evp_cipher_ctx_st {
    const struct evp_cipher_st *cipher;
    unsigned char buf[64];
    int buf_len;
    int block_mask;
} EVP_CIPHER_CTX;

#define OPENSSL_assert(x) assert(x)