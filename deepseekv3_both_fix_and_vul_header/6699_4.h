#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;

struct crypto_template;
struct rtattr;
struct crypto_attr_type {
    int dummy;
};
struct aead_instance {
    struct {
        struct {
            int cra_flags;
            int cra_ctxsize;
        } base;
        int ivsize;
        int maxauthsize;
        void (*init)(void);
        void (*exit)(void);
        int (*setkey)(void);
        int (*setauthsize)(void);
        int (*encrypt)(void);
        int (*decrypt)(void);
    } alg;
    void (*free)(void);
};
struct aead_alg {
    struct {
        int dummy;
    } base;
    int dummy;
};
struct pcrypt_instance_ctx {
    void *spawn;
};
struct pcrypt_aead_ctx {
    void *child;
};

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)-1000UL)
#define PTR_ERR(x) ((long)(x))
#define ENOMEM 12
#define GFP_KERNEL 0
#define CRYPTO_ALG_ASYNC 1

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline struct crypto_attr_type *crypto_get_attr_type(struct rtattr **tb) { return NULL; }
static inline const char *crypto_attr_alg_name(struct rtattr *rta) { return NULL; }
static inline void *aead_instance_ctx(struct aead_instance *inst) { return NULL; }
static inline void *aead_crypto_instance(struct aead_instance *inst) { return NULL; }
static inline void crypto_set_aead_spawn(void *spawn, void *inst) {}
static inline int crypto_grab_aead(void *spawn, const char *name, int a, int b) { return 0; }
static inline struct aead_alg *crypto_spawn_aead_alg(void *spawn) { return NULL; }
static inline int pcrypt_init_instance(void *inst, void *base) { return 0; }
static inline int crypto_aead_alg_ivsize(struct aead_alg *alg) { return 0; }
static inline int crypto_aead_alg_maxauthsize(struct aead_alg *alg) { return 0; }
static inline int aead_register_instance(struct crypto_template *tmpl, struct aead_instance *inst) { return 0; }
static inline void crypto_drop_aead(void *spawn) {}
static inline void pcrypt_aead_init_tfm(void) {}
static inline void pcrypt_aead_exit_tfm(void) {}
static inline int pcrypt_aead_setkey(void) { return 0; }
static inline int pcrypt_aead_setauthsize(void) { return 0; }
static inline int pcrypt_aead_encrypt(void) { return 0; }
static inline int pcrypt_aead_decrypt(void) { return 0; }
static inline void pcrypt_free(void) {}