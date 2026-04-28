#include <stdbool.h>
#include <stddef.h>
#include <string.h>

typedef unsigned int gfp_t;

struct kmem_cache {
    struct kmem_cache_cpu *cpu_slab;
    size_t object_size;
};

struct kmem_cache_cpu {
    void *freelist;
    unsigned long tid;
};

#define NUMA_NO_NODE (-1)
#define _RET_IP_ ((void *)0)
#define unlikely(x) (x)

static inline void *this_cpu_ptr(void *ptr) { return ptr; }
static inline void local_irq_disable(void) {}
static inline void local_irq_enable(void) {}
static inline unsigned long next_tid(unsigned long tid) { return tid + 1; }

struct kmem_cache *slab_pre_alloc_hook(struct kmem_cache *s, gfp_t flags);
void slab_post_alloc_hook(struct kmem_cache *s, gfp_t flags, size_t size, void **p);
void *___slab_alloc(struct kmem_cache *s, gfp_t flags, int node, void *ip, struct kmem_cache_cpu *c);
void maybe_wipe_obj_freeptr(struct kmem_cache *s, void *obj);
void *get_freepointer(struct kmem_cache *s, void *obj);
bool slab_want_init_on_alloc(gfp_t flags, struct kmem_cache *s);
void __kmem_cache_free_bulk(struct kmem_cache *s, int size, void **p);