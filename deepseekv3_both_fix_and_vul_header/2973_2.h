#include <stdint.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t uid_t;
typedef uint32_t gid_t;

typedef struct {
    uid_t val;
} kuid_t;

typedef struct {
    gid_t val;
} kgid_t;

struct user_namespace {
    _Atomic int count;
    struct user_namespace *parent;
    kuid_t owner;
    kgid_t group;
    unsigned int proc_inum;
};

struct cred {
    struct user_namespace *user_ns;
    kuid_t euid;
    kgid_t egid;
};

extern struct kmem_cache *user_ns_cachep;
#define GFP_KERNEL 0
#define EPERM 1
#define ENOMEM 12

static inline bool kuid_has_mapping(struct user_namespace *ns, kuid_t uid) { return true; }
static inline bool kgid_has_mapping(struct user_namespace *ns, kgid_t gid) { return true; }
static inline void set_cred_user_ns(struct cred *new, struct user_namespace *ns) {}
static inline void *kmem_cache_zalloc(struct kmem_cache *cachep, int flags) { return NULL; }
static inline void kmem_cache_free(struct kmem_cache *cachep, void *objp) {}
static inline int proc_alloc_inum(unsigned int *inum) { return 0; }
static inline void atomic_set(_Atomic int *v, int i) { *v = i; }