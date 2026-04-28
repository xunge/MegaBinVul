#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>

enum track_item {
    TRACK_ALLOC,
    TRACK_FREE
};

struct location {
    unsigned long count;
    unsigned long addr;
    long sum_time;
    long min_time;
    long max_time;
    long min_pid;
    long max_pid;
    unsigned long cpus;
    unsigned long nodes;
};

struct loc_track {
    unsigned long max;
    unsigned long count;
    struct location *loc;
};

struct kmem_cache;
struct list_head {
    struct list_head *next, *prev;
};
struct page {
    struct list_head lru;
};
struct kmem_cache_node {
    long nr_slabs;
    int list_lock;
    struct list_head partial;
    struct list_head full;
};

#define GFP_TEMPORARY 0
#define N_NORMAL_MEMORY 0
#define PAGE_SIZE 4096

#define for_each_node_state(node, state) for((node)=0; (node)<1; (node)++)
#define list_for_each_entry(pos, head, member) while(0)
#define cpus_empty(mask) (0)
#define nodes_empty(mask) (0)
#define num_online_cpus() (1)
#define num_online_nodes() (1)

static inline int alloc_loc_track(struct loc_track *t, unsigned long max, int gfp) { return 0; }
static inline void free_loc_track(struct loc_track *t) {}
static inline void flush_all(struct kmem_cache *s) {}
static inline struct kmem_cache_node *get_node(struct kmem_cache *s, int node) { return NULL; }
static inline void process_slab(struct loc_track *t, struct kmem_cache *s, struct page *page, enum track_item alloc) {}
static inline int sprint_symbol(char *buffer, unsigned long address) { return 0; }
static inline int cpulist_scnprintf(char *buf, size_t size, unsigned long mask) { return 0; }
static inline int nodelist_scnprintf(char *buf, size_t size, unsigned long mask) { return 0; }
static inline long atomic_long_read(long *v) { return *v; }
static inline void spin_lock_irqsave(int *lock, unsigned long flags) { flags = 0; }
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static inline long div_long_long_rem(long long a, long long b, unsigned long *remainder) { *remainder = 0; return 0; }