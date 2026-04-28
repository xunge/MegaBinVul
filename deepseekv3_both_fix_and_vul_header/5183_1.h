#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define CHACHA_CTR_SIZE 16
#define CHACHA20_POLY1305_MAX_IVLEN 12
#define POLY1305_BLOCK_SIZE 16
#define EVP_AEAD_TLS1_AAD_LEN 13
#define NO_TLS_PAYLOAD_LENGTH ((size_t)-1)
#define EVP_CTRL_INIT 0
#define EVP_CTRL_COPY 1
#define EVP_CTRL_AEAD_SET_IVLEN 2
#define EVP_CTRL_AEAD_SET_IV_FIXED 3
#define EVP_CTRL_AEAD_SET_TAG 4
#define EVP_CTRL_AEAD_GET_TAG 5
#define EVP_CTRL_AEAD_TLS1_AAD 6
#define EVP_CTRL_AEAD_SET_MAC_KEY 7
#define EVP_F_CHACHA20_POLY1305_CTRL 0
#define EVP_R_INITIALIZATION_ERROR 0
#define EVP_R_COPY_ERROR 0

typedef struct {
    size_t aad;
    size_t text;
} EVP_AEAD_LEN;

typedef struct {
    unsigned char key[32];
    unsigned int counter[4];
} EVP_CHACHA_KEY;

typedef struct {
    EVP_CHACHA_KEY key;
    EVP_AEAD_LEN len;
    unsigned char tag[POLY1305_BLOCK_SIZE];
    unsigned char tls_aad[POLY1305_BLOCK_SIZE];
    unsigned char nonce[12];
    size_t tls_payload_length;
    unsigned int nonce_len;
    unsigned int tag_len;
    unsigned int mac_inited;
    unsigned int aad;
    unsigned char poly1305_ctx[];
} EVP_CHACHA_AEAD_CTX;

typedef struct {
    void *cipher_data;
    int encrypt;
} EVP_CIPHER_CTX;

#define CHACHA_U8TOU32(p) ((unsigned int)(p)[0] | ((unsigned int)(p)[1] << 8) | \
                          ((unsigned int)(p)[2] << 16) | ((unsigned int)(p)[3] << 24))

static inline void *OPENSSL_zalloc(size_t size) {
    void *ptr = calloc(1, size);
    return ptr;
}

static inline void *OPENSSL_memdup(const void *src, size_t size) {
    void *dst = malloc(size);
    if (dst) memcpy(dst, src, size);
    return dst;
}

static inline void EVPerr(int a, int b) {
    (void)a; (void)b;
}

static inline size_t Poly1305_ctx_size(void) {
    return 256;
}

static inline EVP_CHACHA_AEAD_CTX *aead_data(EVP_CIPHER_CTX *ctx) {
    return (EVP_CHACHA_AEAD_CTX *)ctx->cipher_data;
}