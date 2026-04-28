#include <stdlib.h>
#include <string.h>

typedef struct asn1_string_st {
    int length;
    unsigned char *data;
} ASN1_STRING;

typedef struct pkcs7_recip_info_st {
    ASN1_STRING *enc_key;
    /* other members omitted */
} PKCS7_RECIP_INFO;

typedef struct evp_pkey_st EVP_PKEY;
typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;

#define EVP_PKEY_OP_DECRYPT 0
#define EVP_PKEY_CTRL_PKCS7_DECRYPT 0
#define PKCS7_F_PKCS7_DECRYPT_RINFO 0
#define PKCS7_R_CTRL_ERROR 0
#define ERR_R_MALLOC_FAILURE 0
#define ERR_R_EVP_LIB 0

void *OPENSSL_malloc(size_t size);
void OPENSSL_free(void *ptr);
void OPENSSL_clear_free(void *ptr, size_t len);
void PKCS7err(int f, int r);

EVP_PKEY_CTX *EVP_PKEY_CTX_new(EVP_PKEY *pkey, void *engine);
int EVP_PKEY_decrypt_init(EVP_PKEY_CTX *ctx);
int EVP_PKEY_CTX_ctrl(EVP_PKEY_CTX *ctx, int keytype, int optype, int cmd, int p1, void *p2);
int EVP_PKEY_decrypt(EVP_PKEY_CTX *ctx, unsigned char *out, size_t *outlen, const unsigned char *in, size_t inlen);
void EVP_PKEY_CTX_free(EVP_PKEY_CTX *ctx);