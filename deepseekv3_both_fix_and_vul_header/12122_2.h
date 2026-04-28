#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct evp_cipher_st EVP_CIPHER;
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;
typedef struct engine_st ENGINE;
typedef struct ossl_param_st {
    const char *key;
    int data_type;
    void *data;
    size_t data_size;
} OSSL_PARAM;

#define OPENSSL_NO_ENGINE
#define FIPS_MODULE
#define EVP_R_NO_CIPHER_SET 0
#define EVP_R_INITIALIZATION_ERROR 0
#define EVP_R_WRAP_MODE_NOT_ALLOWED 0
#define EVP_R_INVALID_IV_LENGTH 0
#define ERR_LIB_EVP 0
#define ERR_R_MALLOC_FAILURE 0
#define EVP_ORIG_METH 0
#define EVP_CIPH_CTRL_INIT 0
#define EVP_CIPH_CUSTOM_IV 0
#define EVP_CIPH_STREAM_CIPHER 0
#define EVP_CIPH_ECB_MODE 1
#define EVP_CIPH_CFB_MODE 2
#define EVP_CIPH_OFB_MODE 3
#define EVP_CIPH_CBC_MODE 4
#define EVP_CIPH_CTR_MODE 5
#define EVP_CIPH_WRAP_MODE 6
#define EVP_CIPH_ALWAYS_CALL_INIT 0
#define EVP_CTRL_INIT 0
#define NID_undef 0
#define EVP_CIPHER_CTX_FLAG_WRAP_ALLOW 0
#define EVP_CIPH_NO_PADDING (1<<0)

struct evp_cipher_ctx_st {
    const EVP_CIPHER *cipher;
    ENGINE *engine;
    int encrypt;
    int iv_len;
    unsigned char iv[16];
    unsigned char oiv[16];
    void *cipher_data;
    unsigned long flags;
    void *fetched_cipher;
    void *algctx;
    int key_len;
    int num;
    int buf_len;
    int final_used;
    int block_mask;
};

struct evp_cipher_st {
    int nid;
    int block_size;
    int key_len;
    int iv_len;
    unsigned long flags;
    int (*init)(EVP_CIPHER_CTX *ctx, const unsigned char *key, const unsigned char *iv, int enc);
    int (*einit)(void *ctx, const unsigned char *key, int key_len, const unsigned char *iv, int iv_len, const OSSL_PARAM *params);
    int (*dinit)(void *ctx, const unsigned char *key, int key_len, const unsigned char *iv, int iv_len, const OSSL_PARAM *params);
    int (*cleanup)(EVP_CIPHER_CTX *);
    int ctx_size;
    void *(*newctx)(void *provctx);
    void *prov;
    int origin;
};

#define OPENSSL_assert(x) assert(x)
static inline int ossl_assert(int x) { 
    if (!x) ERR_raise(ERR_LIB_EVP, EVP_R_INITIALIZATION_ERROR);
    return x; 
}

void ERR_raise(int lib, int reason);
void *OPENSSL_zalloc(size_t size);
void OPENSSL_clear_free(void *ptr, size_t size);
void EVP_CIPHER_free(EVP_CIPHER *cipher);
void EVP_CIPHER_CTX_reset(EVP_CIPHER_CTX *ctx);
int EVP_CIPHER_CTX_set_padding(EVP_CIPHER_CTX *ctx, int pad);
int EVP_CIPHER_CTX_get_key_length(const EVP_CIPHER_CTX *ctx);
int EVP_CIPHER_CTX_get_iv_length(const EVP_CIPHER_CTX *ctx);
int EVP_CIPHER_up_ref(EVP_CIPHER *cipher);
int EVP_CIPHER_CTX_ctrl(EVP_CIPHER_CTX *ctx, int type, int arg, void *ptr);
int EVP_CIPHER_get_flags(const EVP_CIPHER *cipher);
int EVP_CIPHER_CTX_get_mode(const EVP_CIPHER_CTX *ctx);
const EVP_CIPHER *EVP_CIPHER_CTX_get0_cipher(const EVP_CIPHER_CTX *ctx);
EVP_CIPHER *EVP_CIPHER_fetch(void *libctx, const char *algorithm, const char *properties);
void *ossl_provider_ctx(void *prov);