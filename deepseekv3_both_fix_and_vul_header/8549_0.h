#include <stddef.h>
#include <stdint.h>
#include <string.h>

struct page;
typedef unsigned int gfp_t;
typedef uintptr_t phys_addr_t;

extern struct gen_pool *atomic_pool;
void *gen_pool_alloc(struct gen_pool *pool, size_t size);
phys_addr_t gen_pool_virt_to_phys(struct gen_pool *pool, unsigned long addr);
struct page *phys_to_page(phys_addr_t phys);
#define WARN(cond, msg) 
#define __GFP_ZERO 0