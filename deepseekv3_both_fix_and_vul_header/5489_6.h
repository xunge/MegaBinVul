#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef unsigned char u8;

struct crypto_shash {
    unsigned int descsize;
    unsigned int digestsize;
    unsigned int blocksize;
    unsigned int statesize;
};

struct shash_desc {
    struct crypto_shash *tfm;
    unsigned int flags;
};

struct crypto_tfm {
    void *__crt_alg;
    unsigned int cra_ctxsize;
    int (*cra_init)(struct crypto_tfm *tfm);
    void (*cra_exit)(struct crypto_tfm *tfm);
};

struct crypto_alg {
    unsigned int cra_blocksize;
    unsigned int cra_alignmask;
    unsigned int cra_priority;
    unsigned int cra_ctxsize;
    int (*cra_init)(struct crypto_tfm *tfm);
    void (*cra_exit)(struct crypto_tfm *tfm);
};

struct shash_alg {
    struct crypto_alg base;
    unsigned int digestsize;
    unsigned int statesize;
    int (*init)(struct shash_desc *desc);
    int (*update)(struct shash_desc *desc, const u8 *data, unsigned int len);
    int (*final)(struct shash_desc *desc, u8 *out);
    int (*finup)(struct shash_desc *desc, const u8 *data, unsigned int len, u8 *out);
    int (*export)(struct shash_desc *desc, void *out);
    int (*import)(struct shash_desc *desc, const void *in);
    int (*setkey)(struct crypto_shash *tfm, const u8 *key, unsigned int keylen);
};

struct rtattr {
    unsigned short rta_len;
    unsigned short rta_type;
};

struct crypto_instance;
struct crypto_template {
    const char *name;
    int (*create)(struct crypto_template *tmpl, struct rtattr **tb);
    void (*free)(struct crypto_instance *inst);
    void *module;
};
struct crypto_shash_spawn;

struct shash_instance {
    struct shash_alg alg;
};

struct hmac_ctx {
    struct crypto_shash *hash;
};

#define SHASH_DESC_ON_STACK(shash, ctx) \
    struct shash_desc *shash = (struct shash_desc *)malloc(sizeof(struct shash_desc))

#define CRYPTO_TFM_REQ_MAY_SLEEP 0x00000001
#define CRYPTO_ALG_TYPE_SHASH 0x00000002
#define EINVAL 22
#define ALIGN(x, a) (((x) + ((a) - 1)) & ~((a) - 1))
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define THIS_MODULE ((void*)0)

#define __init
#define __exit
#define module_init(x)
#define module_exit(x)
#define MODULE_LICENSE(x)
#define MODULE_DESCRIPTION(x)
#define MODULE_ALIAS_CRYPTO(x)

static inline void *align_ptr(void *ptr, unsigned long align)
{
    return (void *)ALIGN((unsigned long)ptr, align);
}

static inline int crypto_shash_blocksize(struct crypto_shash *tfm) { return tfm->blocksize; }
static inline int crypto_shash_digestsize(struct crypto_shash *tfm) { return tfm->digestsize; }
static inline int crypto_shash_statesize(struct crypto_shash *tfm) { return tfm->statesize; }
static inline char *crypto_shash_ctx_aligned(struct crypto_shash *tfm) { return NULL; }
static inline unsigned long crypto_tfm_ctx_alignment(void) { return 16; }
static inline int crypto_shash_get_flags(struct crypto_shash *tfm) { return 0; }
static inline int crypto_shash_digest(struct shash_desc *desc, const u8 *data,
                    unsigned int len, u8 *out) { return 0; }
static inline int crypto_shash_init(struct shash_desc *desc) { return 0; }
static inline int crypto_shash_update(struct shash_desc *desc, const u8 *data,
                     unsigned int len) { return 0; }
static inline int crypto_shash_export(struct shash_desc *desc, void *out) { return 0; }
static inline int crypto_shash_import(struct shash_desc *desc, const void *in) { return 0; }
static inline int crypto_shash_final(struct shash_desc *desc, u8 *out) { return 0; }
static inline int crypto_shash_finup(struct shash_desc *desc, const u8 *data,
                   unsigned int len, u8 *out) { return 0; }
static inline int crypto_shash_descsize(struct crypto_shash *tfm) { return 0; }
static inline struct shash_desc *shash_desc_ctx(struct shash_desc *desc) { return desc; }
static inline struct hmac_ctx *hmac_ctx(struct crypto_shash *tfm) { return NULL; }
static inline struct crypto_shash *__crypto_shash_cast(struct crypto_tfm *tfm) { return NULL; }
static inline struct crypto_shash *crypto_spawn_shash(struct crypto_shash_spawn *spawn) { return NULL; }
static inline void crypto_free_shash(struct crypto_shash *tfm) { }
static inline int crypto_check_attr_type(struct rtattr **tb, int type) { return 0; }
static inline struct shash_alg *shash_attr_alg(struct rtattr *rta, int type, int mask) { return NULL; }
static inline struct shash_instance *shash_alloc_instance(const char *name, struct crypto_alg *alg) { return NULL; }
static inline void *shash_instance_ctx(struct shash_instance *inst) { return NULL; }
static inline struct crypto_instance *shash_crypto_instance(struct shash_instance *inst) { return NULL; }
static inline int crypto_init_shash_spawn(struct crypto_shash_spawn *spawn,
                    struct shash_alg *alg,
                    struct crypto_instance *inst) { return 0; }
static inline int shash_register_instance(struct crypto_template *tmpl,
                    struct shash_instance *inst) { return 0; }
static inline void shash_free_instance(struct crypto_instance *inst) { }
static inline void crypto_mod_put(struct crypto_alg *alg) { }
static inline int crypto_register_template(struct crypto_template *tmpl) { return 0; }
static inline void crypto_unregister_template(struct crypto_template *tmpl) { }
static inline void *crypto_instance_ctx(struct crypto_instance *inst) { return NULL; }