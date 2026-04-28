#include <stdlib.h>
#include <string.h>

#define EVP_MAX_IV_LENGTH 16
#define EVP_GCM_TLS_EXPLICIT_IV_LEN 8
#define EVP_GCM_TLS_TAG_LEN 16
#define EVP_AEAD_TLS1_AAD_LEN 13

#define EVP_CTRL_INIT 0x0
#define EVP_CTRL_AEAD_SET_IVLEN 0x9
#define EVP_CTRL_AEAD_SET_TAG 0x10
#define EVP_CTRL_AEAD_GET_TAG 0x11
#define EVP_CTRL_GCM_SET_IV_FIXED 0x12
#define EVP_CTRL_GCM_IV_GEN 0x13
#define EVP_CTRL_GCM_SET_IV_INV 0x14
#define EVP_CTRL_AEAD_TLS1_AAD 0x15
#define EVP_CTRL_COPY 0x16

typedef struct {
    void *key;
} GCM128_CONTEXT;

typedef struct {
    GCM128_CONTEXT gcm;
    void *ks;
    unsigned char *iv;
    int ivlen;
    int key_set;
    int iv_set;
    int iv_gen;
    int taglen;
    int tls_aad_len;
} EVP_AES_GCM_CTX;

typedef struct {
    void *cipher_data;
    int encrypting;
    unsigned char *iv;
    int iv_length;
    unsigned char buf[16];
} EVP_CIPHER_CTX;

#define EVP_C_DATA(type, ctx) ((type *)(ctx)->cipher_data)

static int EVP_CIPHER_CTX_iv_length(EVP_CIPHER_CTX *ctx) { return ctx->iv_length; }
static unsigned char *EVP_CIPHER_CTX_iv_noconst(EVP_CIPHER_CTX *ctx) { return ctx->iv; }
static int EVP_CIPHER_CTX_encrypting(EVP_CIPHER_CTX *ctx) { return ctx->encrypting; }
static unsigned char *EVP_CIPHER_CTX_buf_noconst(EVP_CIPHER_CTX *ctx) { return ctx->buf; }

static void ctr64_inc(unsigned char *counter) {
    int n = 8;
    unsigned char c;
    do {
        --n;
        c = counter[n];
        ++c;
        counter[n] = c;
        if (c) return;
    } while (n);
}

static void *OPENSSL_malloc(size_t size) { return malloc(size); }
static void OPENSSL_free(void *ptr) { free(ptr); }
static int RAND_bytes(unsigned char *buf, int num) { return 1; }
static void CRYPTO_gcm128_setiv(GCM128_CONTEXT *ctx, unsigned char *iv, int len) {}