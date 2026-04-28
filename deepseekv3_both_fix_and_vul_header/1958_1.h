#include <stdint.h>
#include <string.h>

#define GHASH_BLOCK_SIZE 16
#define ENOKEY 126

typedef uint8_t u8;

struct shash_desc {
    void *tfm;
};

struct ghash_ctx {
    void *gf128;
};

struct ghash_desc_ctx {
    u8 buffer[GHASH_BLOCK_SIZE];
};

static inline struct ghash_desc_ctx *shash_desc_ctx(struct shash_desc *desc) {
    return (struct ghash_desc_ctx *)(desc + 1);
}

static inline struct ghash_ctx *crypto_shash_ctx(void *tfm) {
    return (struct ghash_ctx *)tfm;
}

static inline void ghash_flush(struct ghash_ctx *ctx, struct ghash_desc_ctx *dctx) {}