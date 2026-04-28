#include <sys/sysinfo.h>
#include <stddef.h>

#define PAGE_SHIFT 12
#define EP_ITEM_COST 1
#define SLAB_HWCACHE_ALIGN 0
#define SLAB_PANIC 0

struct epitem {
    // 定义足够大的结构体来满足sizeof需求
    char placeholder[128];  // 假设128字节足够
};

struct eppoll_entry {
    char placeholder[64];  // 假设64字节足够
};

struct nested_calls {
    // 基本结构定义
    int dummy;
};

extern unsigned long max_user_watches;
extern struct kmem_cache *epi_cache;
extern struct kmem_cache *pwq_cache;
extern struct nested_calls poll_loop_ncalls;
extern struct nested_calls poll_safewake_ncalls;
extern struct nested_calls poll_readywalk_ncalls;

void si_meminfo(struct sysinfo *si);
void ep_nested_calls_init(struct nested_calls *nc);
struct kmem_cache *kmem_cache_create(const char *name, size_t size,
                                   unsigned long flags,
                                   unsigned long slab_flags,
                                   void (*ctor)(void *));

#define __init
#define BUG_ON(cond) ((void)0)