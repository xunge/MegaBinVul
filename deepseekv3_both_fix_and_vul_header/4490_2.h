#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define NO_PAYLOAD_LENGTH 0
#define STITCHED_CALL 1
#define AES_BLOCK_SIZE 16
#define SHA256_DIGEST_LENGTH 32
#define SHA256_CBLOCK 64
#define SHA_LBLOCK 16
#define TLS1_1_VERSION 0x0302

typedef struct {
    unsigned int Nl, Nh;
    unsigned int num;
    unsigned char data[SHA256_CBLOCK];
    unsigned int h[8];
} SHA256_CTX;

typedef struct {
    unsigned char tls_aad[16];
    unsigned int tls_ver;
} EVP_AES_HMAC_SHA256_AUX;

typedef struct {
    SHA256_CTX md;
    SHA256_CTX head;
    SHA256_CTX tail;
    EVP_AES_HMAC_SHA256_AUX aux;
    size_t payload_length;
    void *ks;
} EVP_AES_HMAC_SHA256;

typedef struct {
    int encrypt;
    unsigned char iv[AES_BLOCK_SIZE];
    void *cipher_data;
} EVP_CIPHER_CTX;

extern unsigned int OPENSSL_ia32cap_P[4];

static EVP_AES_HMAC_SHA256 *data(EVP_CIPHER_CTX *ctx) {
    return (EVP_AES_HMAC_SHA256 *)ctx->cipher_data;
}

static void SHA256_Update(SHA256_CTX *ctx, const void *data, size_t len);
static void SHA256_Final(unsigned char *md, SHA256_CTX *ctx);
static void sha256_block_data_order(SHA256_CTX *ctx, const void *in, size_t num);
static void aesni_cbc_encrypt(const void *in, void *out, size_t length, const void *key, void *iv, int enc);
static void aesni_cbc_sha256_enc(const void *in, void *out, size_t blocks, const void *key, void *iv, SHA256_CTX *ctx, const void *inp);