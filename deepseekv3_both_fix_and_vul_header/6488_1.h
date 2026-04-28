#include <stdlib.h>
#include <stdint.h>

#define GFP_KERNEL 0
#define ENOMEM 12

typedef uint8_t u8;

struct crypto_rng {
    int (*seed)(struct crypto_rng *tfm, const u8 *seed, unsigned int slen);
};

struct crypto_rng_alg {
    int (*seed)(struct crypto_rng *tfm, const u8 *seed, unsigned int slen);
};

static inline struct crypto_rng_alg *crypto_rng_alg(struct crypto_rng *tfm)
{
    return (struct crypto_rng_alg *)tfm;
}

static inline void get_random_bytes(void *buf, size_t len) {
    // Dummy implementation
}