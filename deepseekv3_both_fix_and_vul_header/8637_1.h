#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;
#define GFP_KERNEL 0
#define ENOMEM 12

struct crypto_skcipher;
struct skcipher_tfm {
    struct crypto_skcipher *skcipher;
};

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)-1000)
#define ERR_PTR(x) ((void *)(uintptr_t)(x))
#define ERR_CAST(x) ((void *)(x))
#define kzalloc(size, flags) calloc(1, size)
#define kfree free
void *crypto_alloc_skcipher(const char *name, u32 type, u32 mask);