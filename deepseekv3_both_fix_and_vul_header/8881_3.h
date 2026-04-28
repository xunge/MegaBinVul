#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t u32;

struct crypto_template;
struct rtattr;
struct mcryptd_queue;
struct crypto_alg {
    char cra_name[64];
    u32 cra_flags;
};

struct hash_alg_common {
    struct crypto_alg base;
    unsigned int digestsize;
    unsigned int statesize;
};

struct crypto_ahash_spawn {
    int dummy;
};

struct mcryptd_hash_ctx {
    int dummy;
};

struct hashd_instance_ctx {
    struct crypto_ahash_spawn spawn;
    struct mcryptd_queue *queue;
};

struct ahash_instance {
    struct {
        struct {
            struct {
                u32 cra_flags;
                unsigned int cra_ctxsize;
                int (*cra_init)(void);
                void (*cra_exit)(void);
            } base;
            unsigned int digestsize;
            unsigned int statesize;
        } halg;
        int (*init)(void);
        int (*update)(void);
        int (*final)(void);
        int (*finup)(void);
        int (*export)(void);
        int (*import)(void);
        int (*setkey)(void);
        int (*digest)(void);
    } alg;
};

#define EINVAL 22
#define CRYPTO_ALG_ASYNC 0x00000080
#define CRYPTO_ALG_INTERNAL 0x00000800

#define IS_ERR(ptr) ((uintptr_t)(ptr) > (uintptr_t)(-1000))
#define PTR_ERR(ptr) ((intptr_t)(ptr))
#define pr_debug(fmt, ...)

static int mcryptd_hash_init_tfm(void) { return 0; }
static void mcryptd_hash_exit_tfm(void) {}
static int mcryptd_hash_init_enqueue(void) { return 0; }
static int mcryptd_hash_update_enqueue(void) { return 0; }
static int mcryptd_hash_final_enqueue(void) { return 0; }
static int mcryptd_hash_finup_enqueue(void) { return 0; }
static int mcryptd_hash_export(void) { return 0; }
static int mcryptd_hash_import(void) { return 0; }
static int mcryptd_hash_setkey(void) { return 0; }
static int mcryptd_hash_digest_enqueue(void) { return 0; }

static inline bool mcryptd_check_internal(struct rtattr **tb, u32 *type, u32 *mask) { return false; }
static inline struct hash_alg_common *ahash_attr_alg(struct rtattr *tb, u32 type, u32 mask) { return NULL; }
static inline struct ahash_instance *mcryptd_alloc_instance(struct crypto_alg *alg, int headroom, int size) { return NULL; }
static inline void *ahash_instance_ctx(struct ahash_instance *inst) { return NULL; }
static inline int crypto_init_ahash_spawn(struct crypto_ahash_spawn *spawn, struct hash_alg_common *halg, void *inst) { return 0; }
static inline int ahash_register_instance(struct crypto_template *tmpl, struct ahash_instance *inst) { return 0; }
static inline void crypto_drop_ahash(struct crypto_ahash_spawn *spawn) {}
static inline void crypto_mod_put(struct crypto_alg *alg) {}
static inline void kfree(void *ptr) {}
static inline int ahash_instance_headroom(void) { return 0; }
static inline void *ahash_crypto_instance(struct ahash_instance *inst) { return NULL; }