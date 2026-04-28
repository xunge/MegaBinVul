#include <string.h>
#include <stdlib.h>

#define EVP_MAX_MD_SIZE 64

typedef struct ssl_st {
    void *initial_ctx;
} SSL;

typedef struct ssl_ctx_st {
    int (*tlsext_ticket_key_cb)(SSL *, unsigned char *, unsigned char *, void *, void *, int);
    unsigned char tlsext_tick_key_name[16];
    unsigned char tlsext_tick_hmac_key[16];
    unsigned char tlsext_tick_aes_key[16];
} SSL_CTX;

typedef struct ssl_session_st {
    unsigned char session_id[32];
    int session_id_length;
} SSL_SESSION;

typedef struct hmac_ctx_st {
    int dummy;
} HMAC_CTX;

typedef struct evp_cipher_ctx_st {
    int dummy;
} EVP_CIPHER_CTX;

void *OPENSSL_malloc(size_t size);
void OPENSSL_free(void *ptr);
int CRYPTO_memcmp(const void *a, const void *b, size_t len);
void HMAC_CTX_init(HMAC_CTX *ctx);
void HMAC_CTX_cleanup(HMAC_CTX *ctx);
void HMAC_Init_ex(HMAC_CTX *ctx, const void *key, int key_len, void *md, void *impl);
void HMAC_Update(HMAC_CTX *ctx, const unsigned char *data, int len);
void HMAC_Final(HMAC_CTX *ctx, unsigned char *md, unsigned int *len);
int HMAC_size(HMAC_CTX *ctx);
void EVP_CIPHER_CTX_init(EVP_CIPHER_CTX *ctx);
void EVP_CIPHER_CTX_cleanup(EVP_CIPHER_CTX *ctx);
int EVP_DecryptInit_ex(EVP_CIPHER_CTX *ctx, const void *cipher, void *impl, const unsigned char *key, const unsigned char *iv);
int EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl, const unsigned char *in, int inl);
int EVP_DecryptFinal(EVP_CIPHER_CTX *ctx, unsigned char *outm, int *outl);
int EVP_CIPHER_CTX_iv_length(EVP_CIPHER_CTX *ctx);
void *EVP_aes_128_cbc(void);
void *tlsext_tick_md(void);
SSL_SESSION *d2i_SSL_SESSION(SSL_SESSION **a, const unsigned char **pp, long length);
void ERR_clear_error(void);