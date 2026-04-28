#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned int word32;

enum wc_HashType {
    WC_HASH_TYPE_SHA1,
    WC_HASH_TYPE_SHA256,
    WC_HASH_TYPE_SHA512
};

typedef struct WC_RNG {
    int dummy;
} WC_RNG;

#define WC_MAX_DIGEST_SIZE 64
#define RSA_MAX_SIZE 2048
#define RSA_PSS_PAD_SZ 8
#define RSA_PSS_SALT_LEN_DEFAULT 20
#define RSA_PSS_SALT_MAX_SZ 62
#define RSA_PSS_SALT_LEN_DISCOVER (-1)
#define RSA_PSS_PAD_TERM 0xBC
#define WC_SHA512_DIGEST_SIZE 64

#define MEMORY_E (-1)
#define BAD_FUNC_ARG (-2)
#define PSS_SALTLEN_E (-3)
#define DYNAMIC_TYPE_RSA_BUFFER 0

int wc_HashGetDigestSize(enum wc_HashType hType);
int wc_Hash(enum wc_HashType hType, const byte* data, word32 dataSz, byte* hash, word32 hashSz);
int wc_RNG_GenerateBlock(WC_RNG* rng, byte* output, word32 sz);
int RsaMGF(int mgf, const byte* mgfSeed, word32 seedLen, byte* mask, word32 maskLen, void* heap);

#define XMALLOC(size, heap, type) malloc(size)
#define XFREE(ptr, heap, type) free(ptr)
#define XMEMSET(dest, val, len) memset(dest, val, len)
#define XMEMCPY(dest, src, len) memcpy(dest, src, len)