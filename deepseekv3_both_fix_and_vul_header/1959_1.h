#include <stdint.h>
#include <string.h>

#define GHASH_BLOCK_SIZE 16
#define ENOKEY 126

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t be128[2];

struct shash_desc {
    void *tfm;
    void *__ctx[];
};

struct ghash_desc_ctx {
    u8 buffer[GHASH_BLOCK_SIZE];
    u32 bytes;
};

struct ghash_ctx {
    be128 *gf128;
};

static inline void crypto_xor(u8 *dst, const u8 *src, unsigned int size) {
    for (unsigned int i = 0; i < size; i++)
        dst[i] ^= src[i];
}

static inline void gf128mul_4k_lle(be128 *a, be128 *b) {
    // Dummy implementation
}

static inline struct ghash_desc_ctx *shash_desc_ctx(struct shash_desc *desc) {
    return (struct ghash_desc_ctx *)desc->__ctx;
}

static inline struct ghash_ctx *crypto_shash_ctx(void *tfm) {
    return (struct ghash_ctx *)tfm;
}

#define min(a, b) ((a) < (b) ? (a) : (b))