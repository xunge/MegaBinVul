#include <stdlib.h>
#include <string.h>

typedef struct ossl_param_st OSSL_PARAM;
typedef struct engine_st ENGINE;
typedef struct evp_cipher_st EVP_CIPHER;
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;

struct ossl_param_st {
    const char *key;
    int data_type;
    void *data;
    size_t data_size;
};

struct engine_st {
    const char *id;
};

struct evp_cipher_st {
    int nid;
    int origin;
    void *prov;
    int (*init)(EVP_CIPHER_CTX *ctx, const unsigned char *key, const unsigned char *iv, int enc);
    int (*einit)(void *ctx, const unsigned char *key, size_t key_len, const unsigned char *iv, size_t iv_len, const OSSL_PARAM *params);
    int (*dinit)(void *ctx, const unsigned char *key, size_t key_len, const unsigned char *iv, size_t iv_len, const OSSL_PARAM *params);
    void *(*newctx)(void *provctx);
    size_t ctx_size;
    unsigned long flags;
    int block_size;
    size_t key_len;
};

struct evp_cipher_ctx_st {
    int iv_len;
    int encrypt;
    const EVP_CIPHER *cipher;
    const EVP_CIPHER *fetched_cipher;
    void *cipher_data;
    unsigned long flags;
    void *algctx;
    ENGINE *engine;
    unsigned char iv[16];
    unsigned char oiv[16];
    int num;
    size_t key_len;
    int buf_len;
    int final_used;
    int block_mask;
};

#define OPENSSL_NO_ENGINE
#define FIPS_MODULE
#define EVP_R_NO_CIPHER_SET 0
#define EVP_R_INITIALIZATION_ERROR 0
#define EVP_R_INVALID_IV_LENGTH 0
#define EVP_R_WRAP_MODE_NOT_ALLOWED 0
#define ERR_LIB_EVP 0
#define ERR_R_MALLOC_FAILURE 0

#define EVP_ORIG_METH 0
#define EVP_CIPH_CTRL_INIT 0
#define EVP_CIPH_CUSTOM_IV 0
#define EVP_CIPH_WRAP_MODE 0
#define EVP_CIPH_STREAM_CIPHER 1
#define EVP_CIPH_ECB_MODE 2
#define EVP_CIPH_CFB_MODE 3
#define EVP_CIPH_OFB_MODE 4
#define EVP_CIPH_CBC_MODE 5
#define EVP_CIPH_CTR_MODE 6
#define EVP_CIPH_NO_PADDING 0
#define EVP_CIPH_ALWAYS_CALL_INIT 0
#define EVP_CIPHER_CTX_FLAG_WRAP_ALLOW 0

#define EVP_CTRL_INIT 0

static void ERR_raise(int lib, int reason) {}
static void OPENSSL_clear_free(void *ptr, size_t size) { free(ptr); }
static void *OPENSSL_zalloc(size_t size) { return calloc(1, size); }
static void OPENSSL_assert(int condition) {}

static int EVP_CIPHER_CTX_set_padding(EVP_CIPHER_CTX *ctx, int pad) { return 1; }
static size_t EVP_CIPHER_CTX_get_key_length(const EVP_CIPHER_CTX *ctx) { return ctx->key_len; }
static size_t EVP_CIPHER_CTX_get_iv_length(const EVP_CIPHER_CTX *ctx) { return sizeof(ctx->iv); }
static int EVP_CIPHER_CTX_ctrl(EVP_CIPHER_CTX *ctx, int type, int arg, void *ptr) { return 1; }
static void EVP_CIPHER_CTX_reset(EVP_CIPHER_CTX *ctx) {}
static const EVP_CIPHER *EVP_CIPHER_CTX_get0_cipher(const EVP_CIPHER_CTX *ctx) { return ctx->cipher; }
static int EVP_CIPHER_get_flags(const EVP_CIPHER *cipher) { return cipher->flags; }
static int EVP_CIPHER_CTX_get_mode(const EVP_CIPHER_CTX *ctx) { return 0; }
static void EVP_CIPHER_free(EVP_CIPHER *cipher) { free((void*)cipher); }
static int EVP_CIPHER_up_ref(EVP_CIPHER *cipher) { return 1; }
static void *ossl_provider_ctx(void *prov) { return prov; }