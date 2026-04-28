#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define EINVAL 22
#define ENOMEM 12
#define EDQUOT 122

typedef unsigned int kuid_t;
typedef unsigned int kgid_t;
typedef unsigned int key_perm_t;
typedef unsigned long atomic_t;

#define ERR_PTR(err) ((void *)(long)(err))
#define GFP_KERNEL 0
#define KEY_ALLOC_NOT_IN_QUOTA (1 << 0)
#define KEY_ALLOC_QUOTA_OVERRUN (1 << 1)
#define KEY_ALLOC_BUILT_IN (1 << 2)
#define KEY_ALLOC_UID_KEYRING (1 << 3)
#define KEY_FLAG_IN_QUOTA (0)
#define KEY_FLAG_BUILTIN (1)
#define KEY_FLAG_UID_KEYRING (2)
#define GLOBAL_ROOT_UID 0
#define uid_eq(a, b) ((a) == (b))
#define spin_lock(lock) do {} while (0)
#define spin_unlock(lock) do {} while (0)
#define refcount_set(ref, val) do {} while (0)
#define init_rwsem(sem) do {} while (0)
#define lockdep_set_class(sem, class) do {} while (0)
#define atomic_inc(var) do {} while (0)

struct key_user {
    unsigned qnkeys;
    unsigned qnbytes;
    atomic_t nkeys;
    void *lock;
};

struct key_type {
    int (*vet_description)(const char *);
    size_t def_datalen;
    void *lock_class;
};

struct key_restriction {
    // dummy structure
};

struct cred {
    // dummy structure
};

struct key {
    struct {
        size_t desc_len;
        char *description;
        struct key_type *type;
    } index_key;
    struct key_user *user;
    size_t quotalen;
    size_t datalen;
    kuid_t uid;
    kgid_t gid;
    key_perm_t perm;
    struct key_restriction *restrict_link;
    unsigned long flags;
    atomic_t usage;
    void *sem;
#ifdef KEY_DEBUGGING
    unsigned magic;
#endif
    char *description;
};

extern unsigned key_quota_root_maxkeys;
extern unsigned key_quota_maxkeys;
extern unsigned key_quota_root_maxbytes;
extern unsigned key_quota_maxbytes;
extern struct kmem_cache *key_jar;

struct key_user *key_user_lookup(kuid_t uid);
void key_user_put(struct key_user *user);
void key_alloc_serial(struct key *key);
int security_key_alloc(struct key *key, const struct cred *cred, unsigned long flags);

static inline void *kmem_cache_zalloc(struct kmem_cache *cache, int flags) {
    return calloc(1, sizeof(struct key));
}

static inline void *kmemdup(const void *src, size_t len, int flags) {
    void *dst = malloc(len);
    if (dst) memcpy(dst, src, len);
    return dst;
}

static inline void kmem_cache_free(struct kmem_cache *cache, void *obj) {
    free(obj);
}

static inline void kfree(void *obj) {
    free(obj);
}