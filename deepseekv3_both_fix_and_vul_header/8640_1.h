#include <stdbool.h>
#include <stdint.h>

typedef uint8_t u8;

struct crypto_skcipher;

struct skcipher_tfm {
    struct crypto_skcipher *skcipher;
    bool has_key;
};

int crypto_skcipher_setkey(struct crypto_skcipher *tfm, const u8 *key, unsigned int keylen);