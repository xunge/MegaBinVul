#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef unsigned char u8;
typedef uint64_t dma_addr_t;

struct aead_request {
    unsigned int assoclen;
    void *src;
};

struct crypto_ccm_req_priv_ctx {
    u8 *odata;
    u8 *idata;
    unsigned long flags;
};

struct crypto_aead;
struct crypto_ccm_ctx {
    void *mac;
};

struct scatterlist {
    unsigned long page_link;
    unsigned int offset;
    unsigned int length;
    dma_addr_t dma_address;
};

struct ahash_request;

#define AHASH_REQUEST_ON_STACK(name, tfm) \
    char __##name##_desc[1024]; \
    struct ahash_request *name = (void *)__##name##_desc

static inline struct crypto_ccm_req_priv_ctx *crypto_ccm_reqctx(struct aead_request *req) { return NULL; }
static inline struct crypto_aead *crypto_aead_reqtfm(struct aead_request *req) { return NULL; }
static inline struct crypto_ccm_ctx *crypto_aead_ctx(struct crypto_aead *aead) { return NULL; }
static inline int format_input(u8 *odata, struct aead_request *req, unsigned int cryptlen) { return 0; }
static inline int format_adata(u8 *idata, unsigned int assoclen) { return 0; }
static inline void sg_init_table(struct scatterlist *sg, unsigned int nents) {}
static inline void sg_set_buf(struct scatterlist *sg, const void *buf, unsigned int buflen) {}
static inline void sg_chain(struct scatterlist *sg, unsigned int nents, void *src) {}
static inline void ahash_request_set_tfm(struct ahash_request *req, void *tfm) {}
static inline void ahash_request_set_callback(struct ahash_request *req, unsigned long flags, void *complete, void *data) {}
static inline void ahash_request_set_crypt(struct ahash_request *req, struct scatterlist *src, void *result, unsigned int nbytes) {}
static inline int crypto_ahash_init(struct ahash_request *req) { return 0; }
static inline int crypto_ahash_update(struct ahash_request *req) { return 0; }
static inline int crypto_ahash_finup(struct ahash_request *req) { return 0; }