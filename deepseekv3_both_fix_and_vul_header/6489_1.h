#include <stddef.h>

struct crypto_alg {
    struct {
        unsigned int seedsize;
        void *rng_make_random;
    } cra_rng;
};

struct rng_alg {
    unsigned int seedsize;
    struct crypto_alg base;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))