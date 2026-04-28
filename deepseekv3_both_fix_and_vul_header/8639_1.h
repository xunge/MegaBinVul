#include <stdlib.h>

struct crypto_skcipher;
struct skcipher_tfm {
    struct crypto_skcipher *skcipher;
};

void crypto_free_skcipher(struct crypto_skcipher *tfm);
void kfree(const void *objp);