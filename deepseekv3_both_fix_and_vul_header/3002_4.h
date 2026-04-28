#include <stdint.h>
#include <string.h>
#include <stdlib.h>

struct pdf_struct {
    unsigned char *fileID;
    unsigned fileIDlen;
    unsigned char *key;
    unsigned keylen;
    int flags;
};

struct arc4_state {
    uint8_t i;
    uint8_t j;
    uint8_t s[256];
};

typedef struct cli_md5_ctx {
    uint32_t lo, hi;
    uint32_t a, b, c, d;
    unsigned char buffer[64];
    uint32_t block[16];
} cli_md5_ctx;

typedef struct SHA256_CTX {
    uint32_t h[8];
    unsigned char data[64];
    unsigned int datalen;
    unsigned long long bitlen;
} SHA256_CTX;

#define DECRYPTABLE_PDF 0

static const unsigned char key_padding[32] = {
    0x28, 0xBF, 0x4E, 0x5E, 0x4E, 0x75, 0x8A, 0x41,
    0x64, 0x00, 0x4E, 0x56, 0xFF, 0xFA, 0x01, 0x08,
    0x2E, 0x2E, 0x00, 0xB6, 0xD0, 0x68, 0x3E, 0x80,
    0x2F, 0x0C, 0xA9, 0xFE, 0x64, 0x53, 0x69, 0x7A
};

static inline uint32_t le32_to_host(uint32_t x) {
    return x;
}

static void *cli_malloc(unsigned int size) {
    return malloc(size);
}

static void cli_dbgmsg(const char *format, ...) {}
static void dbg_printhex(const char *prefix, const void *data, unsigned len) {}

static void sha256_init(SHA256_CTX *ctx) {
    memset(ctx, 0, sizeof(*ctx));
}

static void sha256_update(SHA256_CTX *ctx, const unsigned char *data, size_t len) {}
static void sha256_final(SHA256_CTX *ctx, unsigned char *hash) {}

static void cli_md5_init(cli_md5_ctx *ctx) {
    memset(ctx, 0, sizeof(*ctx));
}

static void cli_md5_update(cli_md5_ctx *ctx, const void *data, unsigned long size) {}
static void cli_md5_final(void *resbuf, cli_md5_ctx *ctx) {}

static void arc4_init(struct arc4_state *state, const unsigned char *key, unsigned keylen) {
    memset(state, 0, sizeof(*state));
}

static void arc4_apply(struct arc4_state *state, unsigned char *data, unsigned len) {}