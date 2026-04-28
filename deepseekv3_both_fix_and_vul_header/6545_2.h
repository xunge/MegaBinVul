#include <stdint.h>
#include <stddef.h>

struct scatterlist {
    struct {
        void *addr;
    } virt;
    unsigned int length;
};

struct blkcipher_desc {
    struct crypto_blkcipher *tfm;
};

struct blkcipher_walk {
    struct scatterlist dst;
    struct scatterlist src;
    unsigned int nbytes;
    uint8_t iv[8];
};

struct crypto_blkcipher {
    void *ctx;
};

struct salsa20_ctx {
    uint32_t state[16];
};

static inline struct salsa20_ctx *crypto_blkcipher_ctx(struct crypto_blkcipher *tfm)
{
    return (struct salsa20_ctx *)tfm->ctx;
}

void salsa20_ivsetup(struct salsa20_ctx *ctx, uint8_t *iv);
void salsa20_encrypt_bytes(struct salsa20_ctx *ctx, uint8_t *dst, const uint8_t *src, unsigned int bytes);
void blkcipher_walk_init(struct blkcipher_walk *walk, struct scatterlist *dst, struct scatterlist *src, unsigned int nbytes);
int blkcipher_walk_virt_block(struct blkcipher_desc *desc, struct blkcipher_walk *walk, unsigned int blocksize);
int blkcipher_walk_done(struct blkcipher_desc *desc, struct blkcipher_walk *walk, int err);

#define likely(x) __builtin_expect(!!(x), 1)