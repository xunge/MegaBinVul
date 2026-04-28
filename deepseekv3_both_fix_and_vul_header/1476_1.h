#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AES_BLOCK_SIZE 16
#define AES_KEY_SIZE 32

typedef struct {
    unsigned char key[AES_KEY_SIZE];
    unsigned char iv[AES_KEY_SIZE/2];
} AesSettings;

typedef struct {
    int* length;
    unsigned char* body;
    AesSettings* aes_settings;
} Message;

typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;

EVP_CIPHER_CTX* EVP_CIPHER_CTX_new(void);
void EVP_CIPHER_CTX_cleanup(EVP_CIPHER_CTX *ctx);
int EVP_EncryptInit(EVP_CIPHER_CTX *ctx, const void *type, const unsigned char *key, const unsigned char *iv);
int EVP_EncryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl, const unsigned char *in, int inl);
int EVP_EncryptFinal_ex(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl);
const void* EVP_aes_256_cfb(void);