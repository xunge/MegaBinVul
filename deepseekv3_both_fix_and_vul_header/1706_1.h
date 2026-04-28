#include <stdatomic.h>

struct anon_vma {
    atomic_int refcount;
    int num_children;
    int num_active_vmas;
    int degree;
    struct anon_vma *parent;
    struct anon_vma *root;
};

extern struct kmem_cache *anon_vma_cachep;
#define GFP_KERNEL 0
void *kmem_cache_alloc(struct kmem_cache *cachep, int flags);