#include <stddef.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned int word32;

#define NO_SHA
#define NO_SHA256
#define WOLFSSL_SHA384
#define WOLFSSL_SHA512

#define WC_SHA 1
#define WC_SHA256 2
#define WC_SHA384 3
#define WC_SHA512 4

#define WC_SHA_BLOCK_SIZE 64
#define WC_SHA_DIGEST_SIZE 20
#define WC_SHA_PAD_SIZE 9

#define WC_SHA256_BLOCK_SIZE 64
#define WC_SHA256_DIGEST_SIZE 32
#define WC_SHA256_PAD_SIZE 9

#define WC_SHA384_BLOCK_SIZE 128
#define WC_SHA384_DIGEST_SIZE 48
#define WC_SHA384_PAD_SIZE 17

#define WC_SHA512_BLOCK_SIZE 128
#define WC_SHA512_DIGEST_SIZE 64
#define WC_SHA512_PAD_SIZE 17

#define WC_MAX_BLOCK_SIZE 128
#define WC_MAX_DIGEST_SIZE 64

#define WOLFSSL_TLS_HMAC_INNER_SZ 13

#define BAD_FUNC_ARG -1

typedef struct Hmac {
    int macType;
    byte ipad[WC_MAX_BLOCK_SIZE];
    byte innerHash[WC_MAX_DIGEST_SIZE];
} Hmac;

static int Hmac_HashUpdate(Hmac* hmac, const byte* data, word32 len) { return 0; }
static int Hmac_HashFinalRaw(Hmac* hmac, byte* hash) { return 0; }
static int Hmac_OuterHash(Hmac* hmac, byte* digest) { return 0; }

static void c32toa(word32 u32, byte* c) {}
static word32 ctSetLTE(word32 a, word32 b) { return 0; }
static word32 ctMaskEq(word32 a, word32 b) { return 0; }
static word32 ctMaskGT(word32 a, word32 b) { return 0; }
static word32 ctMaskSel(word32 m, word32 a, word32 b) { return 0; }

#define XMEMSET(dest, val, len) memset((dest), (val), (len))