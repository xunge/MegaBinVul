#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define GFP_KERNEL 0
#define CRYPTO_ALG_ASYNC 0
#define IS_ERR(x) (0)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define BUILD_BUG_ON(cond) ((void)sizeof(char[1 - 2*!!(cond)]))
#define IEEE802154_LLSEC_KEY_SIZE 16

typedef uint32_t u32;
typedef uint8_t u8;

struct kref {
    int refcount;
};

static inline void kref_init(struct kref *kref) {
    kref->refcount = 1;
}

struct crypto_aead;
struct crypto_sync_skcipher;

struct ieee802154_llsec_key {
    u8 key[IEEE802154_LLSEC_KEY_SIZE];
};

struct mac802154_llsec_key {
    struct kref ref;
    struct ieee802154_llsec_key key;
    struct crypto_aead *tfm[3];
    struct crypto_sync_skcipher *tfm0;
};

static void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static void kfree_sensitive(void *ptr) {
    free(ptr);
}

static struct crypto_aead *crypto_alloc_aead(const char *alg_name, u32 type, u32 mask) {
    return NULL;
}

static int crypto_aead_setkey(struct crypto_aead *tfm, const u8 *key, unsigned int keylen) {
    return 0;
}

static int crypto_aead_setauthsize(struct crypto_aead *tfm, unsigned int authsize) {
    return 0;
}

static void crypto_free_aead(struct crypto_aead *tfm) {
}

static struct crypto_sync_skcipher *crypto_alloc_sync_skcipher(const char *alg_name, u32 type, u32 mask) {
    return NULL;
}

static int crypto_sync_skcipher_setkey(struct crypto_sync_skcipher *tfm, const u8 *key, unsigned int keylen) {
    return 0;
}

static void crypto_free_sync_skcipher(struct crypto_sync_skcipher *tfm) {
}