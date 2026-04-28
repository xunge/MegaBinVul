#include <stddef.h>

#define __init
#define SLAB_HWCACHE_ALIGN (1 << 0)
#define SLAB_PANIC (1 << 1)
#define PAGE_SIZE 4096
#define NR_FILE 8192

struct file {
    // 最小可编译的file结构体定义
    int dummy;
};

struct files_stat_struct {
    unsigned long max_files;
};

struct lglock {
    // 最小可编译的lglock结构体定义  
    int dummy;
};

extern struct kmem_cache *filp_cachep;
extern struct files_stat_struct files_stat;
extern struct lglock files_lglock;
extern int nr_files;

void *kmem_cache_create(const char *, size_t, int, unsigned long, void *);
#define max_t(type, x, y) ((x) > (y) ? (x) : (y))
void files_defer_init(void);
void lg_lock_init(struct lglock *, const char *);
void percpu_counter_init(int *, long);