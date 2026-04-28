#include <stdlib.h>
#include <string.h>

#define SHA_DIGEST_LENGTH 20
#define EVP_MAX_MD_SIZE 64  /* SHA-512 is the longest supported */

typedef struct bignum_st BIGNUM;

struct evp_md_ctx_st {
    void *digest;
    void *md_data;
    unsigned int flags;
};

typedef struct evp_md_ctx_st EVP_MD_CTX;

void *OPENSSL_malloc(size_t size);
void OPENSSL_free(void *ptr);
int BN_num_bytes(const BIGNUM *a);
int BN_bn2bin(const BIGNUM *a, unsigned char *to);
BIGNUM *BN_bin2bn(const unsigned char *s, int len, BIGNUM *ret);
void EVP_MD_CTX_init(EVP_MD_CTX *ctx);
int EVP_DigestInit_ex(EVP_MD_CTX *ctx, const void *type, void *impl);
int EVP_DigestUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt);
int EVP_DigestFinal_ex(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *s);
void EVP_MD_CTX_cleanup(EVP_MD_CTX *ctx);
const void *EVP_sha1(void);