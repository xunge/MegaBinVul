#include <stdint.h>
#include <string.h>

#define EVP_CTRL_INIT 0
#define EVP_CTRL_AEAD_TLS1_AAD 1
#define EVP_CTRL_CCM_SET_IV_FIXED 2
#define EVP_CTRL_AEAD_SET_IVLEN 3
#define EVP_CTRL_CCM_SET_L 4
#define EVP_CTRL_AEAD_SET_TAG 5
#define EVP_CTRL_AEAD_GET_TAG 6
#define EVP_CTRL_COPY 7

#define EVP_AEAD_TLS1_AAD_LEN 13
#define EVP_CCM_TLS_EXPLICIT_IV_LEN 8
#define EVP_CCM_TLS_FIXED_IV_LEN 4

typedef struct evp_cipher_ctx_st {
    void *cipher_data;
    unsigned char *buf;
    unsigned char *iv;
    int encrypt;
} EVP_CIPHER_CTX;

typedef struct ccm128_context {
    void *key;
} CCM128_CONTEXT;

typedef struct {
    int key_set;
    int iv_set;
    int L;
    int M;
    int tag_set;
    int len_set;
    int tls_aad_len;
    CCM128_CONTEXT ccm;
    void *ks;
} EVP_AES_CCM_CTX;

#define EVP_C_DATA(type, ctx) ((type *)(ctx)->cipher_data)
#define EVP_CIPHER_CTX_buf_noconst(ctx) ((ctx)->buf)
#define EVP_CIPHER_CTX_iv_noconst(ctx) ((ctx)->iv)
#define EVP_CIPHER_CTX_encrypting(ctx) ((ctx)->encrypt)
#define CRYPTO_ccm128_tag(ccm, ptr, size) (1)