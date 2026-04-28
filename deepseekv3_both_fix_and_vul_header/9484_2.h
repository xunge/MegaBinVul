#include <stdbool.h>
#include <stddef.h>

enum d_walk_ret {
    D_WALK_CONTINUE,
    D_WALK_QUIT,
    D_WALK_SKIP,
    D_WALK_NORETRY
};

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct dentry {
    struct dentry *d_parent;
    struct list_head d_subdirs;
    struct list_head d_child;
    unsigned long d_flags;
    struct {
        int lock;
        void *dep_map;
    } d_lock;
};

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); \
})

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

extern int rename_lock;
#define DENTRY_D_LOCK_NESTED 1
#define DCACHE_DENTRY_KILLED 0x00000001
#define _RET_IP_ (void*)0

void spin_lock(int *lock);
void spin_unlock(int *lock);
void spin_lock_nested(int *lock, int nested);
void spin_release(void *dep_map, int i, void *ret_ip);
void spin_acquire(void *dep_map, int i, int j, void *ret_ip);
void rcu_read_lock(void);
void rcu_read_unlock(void);
unsigned read_seqbegin_or_lock(int *lock, unsigned *seq);
bool need_seqretry(int *lock, unsigned seq);
void done_seqretry(int *lock, unsigned seq);