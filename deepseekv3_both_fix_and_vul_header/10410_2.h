#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define GCM_AES_IV_LEN 12
#define MAX_SKB_FRAGS 16
#define GFP_ATOMIC 0

struct scatterlist {
    unsigned long page_link;
    unsigned int offset;
    unsigned int length;
};

struct crypto_aead {
    unsigned int dummy;
};

struct aead_request {
    unsigned int dummy;
};

#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))

static inline size_t crypto_aead_reqsize(struct crypto_aead *tfm) { return sizeof(struct aead_request); }
static inline void aead_request_set_tfm(struct aead_request *req, struct crypto_aead *tfm) {}

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }