#include <stdbool.h>
#include <stddef.h>

typedef unsigned int gfp_t;
#define KMALLOC_NOT_NORMAL_BITS 0
#define __GFP_NOMEMALLOC 0
#define __GFP_NOWARN 0
#define SKB_HEAD_ALIGN(x) (x)
#define SKB_SMALL_HEAD_CACHE_SIZE 0

struct kmem_cache;
extern struct kmem_cache *skb_small_head_cache;
extern void *kmem_cache_alloc_node(struct kmem_cache *, gfp_t, int);
extern void *kmalloc_node_track_caller(size_t, gfp_t, int);
extern bool gfp_pfmemalloc_allowed(gfp_t);
extern size_t kmalloc_size_roundup(size_t);