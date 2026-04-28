#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

typedef struct evp_cipher_st EVP_CIPHER;
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;

struct evp_cipher_st {
    unsigned int block_size;
    int flags;
    int (*do_cipher)(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, int inl);
};

struct evp_cipher_ctx_st {
    int encrypt;
    const EVP_CIPHER *cipher;
    unsigned int flags;
    unsigned char final[64];
    int final_used;
    int buf_len;
};

#define EVP_F_EVP_DECRYPTUPDATE 0
#define EVP_R_INVALID_OPERATION 0
#define EVP_R_PARTIALLY_OVERLAPPING 0
#define EVP_R_OUTPUT_WOULD_OVERFLOW 0
#define EVP_CIPH_FLAG_CUSTOM_CIPHER 0
#define EVP_CIPH_FLAG_LENGTH_BITS 0
#define EVP_CIPH_NO_PADDING 0
#define EVP_CIPH_CCM_MODE 0

#define EVPerr(a, b) 
#define EVP_CIPHER_CTX_test_flags(a, b) 0
#define EVP_CIPHER_mode(a) 0
#define is_partially_overlapping(a, b, c) 0
#define evp_EncryptDecryptUpdate(a, b, c, d, e) 0
#define OPENSSL_assert(a) 

#define PTRDIFF_T intptr_t