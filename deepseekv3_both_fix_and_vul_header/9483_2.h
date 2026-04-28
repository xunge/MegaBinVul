#include <stdbool.h>
#include <stddef.h>

#define IS_ROOT(d) ((d)->d_parent == (d))
#define DCACHE_OP_PRUNE 0x00000001
#define DCACHE_LRU_LIST 0x00000002  
#define DCACHE_SHRINK_LIST 0x00000004
#define DCACHE_DENTRY_KILLED 0x00000008
#define DCACHE_MAY_FREE 0x00000010

struct list_head {
    struct list_head *next, *prev;
};

static inline void list_del(struct list_head *entry) {
    entry->next = entry->prev = entry;
}

struct lockref {
    int count;
};

struct dentry {
    struct dentry *d_parent;
    struct list_head d_child;
    unsigned int d_flags;
    struct lockref d_lockref;
    int d_lock;
    struct dentry_operations *d_op;
};

struct dentry_operations {
    void (*d_prune)(struct dentry *);
    void (*d_release)(struct dentry *);
};

extern void __d_drop(struct dentry *);
extern void d_lru_del(struct dentry *);
extern void dentry_iput(struct dentry *);
extern void dentry_free(struct dentry *);
extern int nr_dentry;

#define spin_lock(lock) (void)0
#define spin_unlock(lock) (void)0
#define lockref_mark_dead(ref) (void)0
#define BUG_ON(cond) (void)0
#define this_cpu_dec(var) (void)0
#define likely(x) (x)