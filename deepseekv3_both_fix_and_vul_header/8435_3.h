#include <string.h>
#include <stdlib.h>

#define TLSEXT_KEYNAME_LENGTH 16
#define EVP_MAX_MD_SIZE 64

typedef struct ssl_st {
    struct ssl_ctx_st *initial_ctx;
} SSL;

typedef struct ssl_session_st {
    unsigned char session_id[32];
    unsigned int session_id_length;
} SSL_SESSION;

typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;
typedef struct hmac_ctx_st HMAC_CTX;

typedef struct ssl_ctx_st {
    int (*tlsext_ticket_key_cb)(SSL *, unsigned char *, unsigned char *,
                               EVP_CIPHER_CTX *, HMAC_CTX *, int);
    unsigned char tlsext_tick_key_name[16];
    unsigned char tlsext_tick_hmac_key[32];
    unsigned char tlsext_tick_aes_key[32];
} SSL_CTX;

struct hmac_ctx_st {};
struct evp_cipher_ctx_st {};

HMAC_CTX *HMAC_CTX_new(void);
void HMAC_CTX_free(HMAC_CTX *ctx);
int HMAC_Init_ex(HMAC_CTX *ctx, const void *key, int key_len, const void *md, void *engine);
int HMAC_Update(HMAC_CTX *ctx, const unsigned char *data, int len);
int HMAC_Final(HMAC_CTX *ctx, unsigned char *md, unsigned int *len);
int HMAC_size(const HMAC_CTX *ctx);

EVP_CIPHER_CTX *EVP_CIPHER_CTX_new(void);
void EVP_CIPHER_CTX_free(EVP_CIPHER_CTX *ctx);
int EVP_DecryptInit_ex(EVP_CIPHER_CTX *ctx, const void *type, void *impl,
                      const unsigned char *key, const unsigned char *iv);
int EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl,
                     const unsigned char *in, int inl);
int EVP_DecryptFinal(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl);
int EVP_CIPHER_CTX_iv_length(const EVP_CIPHER_CTX *ctx);

const void *EVP_sha256(void);
const void *EVP_aes_256_cbc(void);

void *OPENSSL_malloc(size_t size);
void OPENSSL_free(void *ptr);
int CRYPTO_memcmp(const void *a, const void *b, size_t len);
void ERR_clear_error(void);

SSL_SESSION *d2i_SSL_SESSION(SSL_SESSION **a, const unsigned char **pp, long length);