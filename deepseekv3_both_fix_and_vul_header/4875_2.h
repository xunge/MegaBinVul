#include <stdlib.h>
#include <string.h>

typedef struct bignum_st BIGNUM;
#define SHA_DIGEST_LENGTH 20

struct evp_md_ctx_st {
    void *digest;
    void *engine;
    unsigned long flags;
    void *md_data;
};
typedef struct evp_md_ctx_st EVP_MD_CTX;

const void *EVP_sha1(void);

void *OPENSSL_malloc(size_t size);
void OPENSSL_free(void *ptr);

int BN_num_bytes(const BIGNUM *a);
int BN_bn2bin(const BIGNUM *a, unsigned char *to);
BIGNUM *BN_bin2bn(const unsigned char *s, int len, BIGNUM *ret);
int BN_is_zero(const BIGNUM *a);
void BN_free(BIGNUM *a);

void EVP_MD_CTX_init(EVP_MD_CTX *ctx);
int EVP_DigestInit_ex(EVP_MD_CTX *ctx, const void *type, void *impl);
int EVP_DigestUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt);
int EVP_DigestFinal_ex(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *s);
void EVP_MD_CTX_cleanup(EVP_MD_CTX *ctx);