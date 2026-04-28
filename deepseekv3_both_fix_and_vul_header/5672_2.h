#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define AESNI_ALIGN 16
#define AES_KEYSIZE_128 16
#define AES_KEYSIZE_192 24
#define AES_KEYSIZE_256 32
#define EINVAL 22
#define ENOMEM 12
#define EBADMSG 74
#define GFP_ATOMIC 0

typedef uint32_t __be32;
typedef uint8_t u8;
typedef uint32_t u32;

struct scatter_walk {
    void *data;
    unsigned int length;
};

struct scatterlist {
    void *page_link;
    unsigned int offset;
    unsigned int length;
};

struct aead_request {
    unsigned int cryptlen;
    unsigned int assoclen;
    struct scatterlist *src;
    struct scatterlist *assoc;
    struct scatterlist *dst;
    u8 *iv;
};

struct crypto_aead {
    unsigned int authsize;
};

struct aesni_rfc4106_gcm_ctx {
    struct {
        u32 key_length;
    } aes_key_expanded;
    u8 nonce[4];
    u8 hash_subkey[16];
};

static inline int sg_is_last(struct scatterlist *sg) {
    return 1;
}

static inline void scatterwalk_start(struct scatter_walk *walk, struct scatterlist *sg) {
    walk->data = sg->page_link;
    walk->length = sg->length;
}

static inline void *scatterwalk_map(struct scatter_walk *walk) {
    return walk->data;
}

static inline void scatterwalk_unmap(void *vaddr) {
}

static inline void scatterwalk_done(struct scatter_walk *walk, int out, int more) {
}

static inline void scatterwalk_map_and_copy(void *buf, struct scatterlist *sg,
                      unsigned int start, unsigned int nbytes, int out) {
    memcpy(buf, sg->page_link + start, nbytes);
}

static inline struct crypto_aead *crypto_aead_reqtfm(struct aead_request *req) {
    return NULL;
}

static inline struct aesni_rfc4106_gcm_ctx *aesni_rfc4106_gcm_ctx_get(struct crypto_aead *tfm) {
    return NULL;
}

static inline unsigned int crypto_aead_authsize(struct crypto_aead *tfm) {
    return tfm->authsize;
}

static inline int crypto_memneq(const void *a, const void *b, size_t size) {
    return memcmp(a, b, size) != 0;
}

static inline __be32 cpu_to_be32(u32 x) {
    return x;
}

static inline void *PTR_ALIGN(void *ptr, unsigned int align) {
    return (void *)(((uintptr_t)ptr + align - 1) & ~(align - 1));
}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

#define unlikely(x) (x)

static void aesni_gcm_dec_tfm(void *aes_ctx, u8 *dst, u8 *src, unsigned long len,
                u8 *iv, u8 *hash_subkey, u8 *assoc, unsigned long assoc_len,
                u8 *authTag, unsigned long auth_tag_len) {
}