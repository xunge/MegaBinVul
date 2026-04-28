#include <string.h>
#include <assert.h>

typedef struct evp_encode_ctx_st {
    int num;
    int length;
    unsigned char enc_data[64];
} EVP_ENCODE_CTX;

int EVP_EncodeBlock(unsigned char *out, const unsigned char *in, int inl);
#define OPENSSL_assert(x) assert(x)