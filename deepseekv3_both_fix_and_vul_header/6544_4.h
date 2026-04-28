#include <stdint.h>

typedef uint64_t dma_addr_t;

struct scatterlist {
    unsigned long page_link;
    unsigned int offset;
    unsigned int length;
    dma_addr_t dma_address;
    struct {
        void *addr;
    } virt;
};

struct blkcipher_desc {
    void *tfm;
    unsigned long flags;
};

struct crypto_blkcipher {
    unsigned int dummy;
};

struct blkcipher_walk {
    struct scatterlist src;
    struct scatterlist dst;
    unsigned int nbytes;
    void *iv;
};

struct salsa20_ctx {
    uint32_t input[16];
};

#define likely(x) __builtin_expect(!!(x), 1)

static inline void *crypto_blkcipher_ctx(struct crypto_blkcipher *tfm) {
    return (void *)tfm;
}

static inline void blkcipher_walk_init(struct blkcipher_walk *walk,
                                     struct scatterlist *dst,
                                     struct scatterlist *src,
                                     unsigned int nbytes) {
    walk->src = *src;
    walk->dst = *dst;
    walk->nbytes = nbytes;
}

static inline int blkcipher_walk_virt_block(struct blkcipher_desc *desc,
                                          struct blkcipher_walk *walk,
                                          unsigned int blocksize) {
    return 0;
}

static inline void salsa20_ivsetup(struct salsa20_ctx *ctx, void *iv) {}

static inline void salsa20_encrypt_bytes(struct salsa20_ctx *ctx,
                                       void *src, void *dst,
                                       unsigned int bytes) {}

static inline int blkcipher_walk_done(struct blkcipher_desc *desc,
                                    struct blkcipher_walk *walk,
                                    int err) {
    return err;
}