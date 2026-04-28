#include <stdlib.h>
#include <string.h>

#define CHACHA_CTR_SIZE 16
#define POLY1305_BLOCK_SIZE 16
#define EVP_AEAD_TLS1_AAD_LEN 13
#define NO_TLS_PAYLOAD_LENGTH -1

typedef struct {
    size_t aad;
    size_t text;
} len_struct;

typedef struct {
    unsigned int counter[4];
} chacha_key;

typedef struct {
    len_struct len;
    unsigned char tag[POLY1305_BLOCK_SIZE];
    unsigned char nonce[12];
    chacha_key key;
    int mac_inited;
    int tag_len;
    int nonce_len;
    int tls_payload_length;
    int aad;
} EVP_CHACHA_AEAD_CTX;

typedef struct evp_cipher_ctx_st {
    void *cipher_data;
    int encrypt;
} EVP_CIPHER_CTX;

#define CHACHA_U8TOU32(p) ((unsigned int)(p)[0] | \
                          ((unsigned int)(p)[1] << 8) | \
                          ((unsigned int)(p)[2] << 16) | \
                          ((unsigned int)(p)[3] << 24))

#define EVP_F_CHACHA20_POLY1305_CTRL 0
#define EVP_R_INITIALIZATION_ERROR 0
#define EVP_R_COPY_ERROR 0

#define EVP_CTRL_INIT 0
#define EVP_CTRL_COPY 1
#define EVP_CTRL_AEAD_SET_IVLEN 2
#define EVP_CTRL_AEAD_SET_IV_FIXED 3
#define EVP_CTRL_AEAD_SET_TAG 4
#define EVP_CTRL_AEAD_GET_TAG 5
#define EVP_CTRL_AEAD_TLS1_AAD 6
#define EVP_CTRL_AEAD_SET_MAC_KEY 7

static void *OPENSSL_zalloc(size_t size) {
    void *ptr = calloc(1, size);
    return ptr;
}

static void *OPENSSL_memdup(const void *src, size_t size) {
    void *dst = malloc(size);
    if (dst) memcpy(dst, src, size);
    return dst;
}

static void EVPerr(int a, int b) {}

static EVP_CHACHA_AEAD_CTX *aead_data(EVP_CIPHER_CTX *ctx) {
    return (EVP_CHACHA_AEAD_CTX *)ctx->cipher_data;
}

static int Poly1305_ctx_size() { return 0; }
static int chacha20_poly1305_cipher(EVP_CIPHER_CTX *ctx, void *a, void *b, int c) { return 0; }