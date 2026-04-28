#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define STITCHED_CALL
#define STITCHED_DECRYPT_CALL
#define NO_PAYLOAD_LENGTH (~(size_t)0)
#define TLS1_1_VERSION 0x0302
#define SHA_DIGEST_LENGTH 20
#define SHA_CBLOCK 64
#define SHA_LBLOCK (SHA_CBLOCK/4)
#define AES_BLOCK_SIZE 16

typedef struct {
    unsigned int h0, h1, h2, h3, h4;
    unsigned int Nl, Nh;
    unsigned int data[SHA_LBLOCK];
    unsigned int num;
} SHA_CTX;

typedef struct {
    unsigned char tls_aad[16];
    unsigned int tls_ver;
} aux_st;

typedef struct {
    void *ks;  // Placeholder for AES key schedule
    SHA_CTX head, tail, md;
    aux_st aux;
    size_t payload_length;
} EVP_AES_HMAC_SHA1;

typedef struct {
    unsigned char *iv;
    int encrypt;
    int key_len;
    void *cipher_data;
} EVP_CIPHER_CTX;

static void *data(EVP_CIPHER_CTX *ctx) { return ctx->cipher_data; }

static void SHA1_Update(SHA_CTX *c, const void *data, size_t len);
static void SHA1_Final(unsigned char *md, SHA_CTX *c);
static void sha1_block_data_order(SHA_CTX *c, const void *p, size_t num);
static void aesni_cbc_sha1_enc(const unsigned char *in, unsigned char *out,
                              size_t blocks, const void *key,
                              unsigned char ivec[16], SHA_CTX *ctx,
                              const unsigned char *in0);
static void aesni256_cbc_sha1_dec(const unsigned char *in, unsigned char *out,
                                 size_t blocks, const void *key,
                                 unsigned char ivec[16], SHA_CTX *ctx,
                                 const unsigned char *in0);
static void aesni_cbc_encrypt(const unsigned char *in, unsigned char *out,
                             size_t length, const void *key,
                             unsigned char *ivec, int enc);