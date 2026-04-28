#include <stdlib.h>
#include <stddef.h>

struct file_lock_context {
    int dummy;
};

struct file_lock {
    int dummy;
};

struct file_lock_list_struct {
    void* lock;
    void* hlist;
};

extern struct file_lock_list_struct file_lock_list;
extern void* flctx_cache;
extern void* filelock_cache;

#define SLAB_PANIC 0
#define __init
#define for_each_possible_cpu(i) for(i=0;i<1;i++)
#define per_cpu_ptr(ptr, cpu) (ptr)
#define spin_lock_init(lock)
#define INIT_HLIST_HEAD(head)
#define kmem_cache_create(name, size, align, flags, ctor) malloc(size)
#define lease_notifier_chain_init()