#include <stddef.h>
#include <assert.h>

#define B64_EOF       -1
#define B64_EOLN      -2
#define B64_CR        -3
#define B64_ERROR     -4
#define B64_NOT_BASE64(x) ((x) == B64_EOF || (x) == B64_EOLN || (x) == B64_CR || (x) == B64_ERROR)

#define OPENSSL_assert(x) assert(x)

typedef struct evp_encode_ctx_st {
    int num;
    int length;
    int line_num;
    int expect_nl;
    unsigned char enc_data[80];
} EVP_ENCODE_CTX;

int conv_ascii2bin(unsigned char a);
int EVP_DecodeBlock(unsigned char *t, unsigned char *f, int n);