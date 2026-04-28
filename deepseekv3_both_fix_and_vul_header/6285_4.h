#include <stddef.h>

typedef struct EVP_MD EVP_MD;
typedef struct EC_KEY EC_KEY;

typedef struct {
    EC_KEY *ec;
} EVP_PKEY_PKEY;

typedef struct EVP_PKEY {
    EVP_PKEY_PKEY pkey;
} EVP_PKEY;

typedef struct EVP_PKEY_CTX {
    EVP_PKEY *pkey;
    void *data;
} EVP_PKEY_CTX;

typedef struct SM2_PKEY_CTX {
    const EVP_MD *md;
} SM2_PKEY_CTX;

const EVP_MD *EVP_sm3(void);
int sm2_plaintext_size_ec(EC_KEY *ec, const EVP_MD *md, size_t inlen, size_t *outlen);
int sm2_plaintext_size_data(const unsigned char *in, size_t inlen, size_t *outlen);
int sm2_decrypt(EC_KEY *ec, const EVP_MD *md, const unsigned char *in, size_t inlen, unsigned char *out, size_t *outlen);