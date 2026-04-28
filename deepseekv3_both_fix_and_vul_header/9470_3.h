#include <stddef.h>

struct spinlock {
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct dentry {
    struct list_head d_subdirs;
    struct list_head d_child;
    struct inode *d_inode;
    struct spinlock d_lock;
    struct {
        struct list_head d_child;
    } d_u;
};

struct inode {
    void *i_private;
};

struct ftrace_event_file {
    struct dentry *dir;
    struct list_head list;
    char *system;
    void *filter;
};

extern struct kmem_cache *file_cachep;
void remove_subsystem(char *system);
void free_event_filter(void *filter);
void debugfs_remove_recursive(struct dentry *dentry);
void spin_lock(struct spinlock *lock);
void spin_unlock(struct spinlock *lock);
void list_del(struct list_head *entry);
void kmem_cache_free(struct kmem_cache *cachep, void *objp);

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)); \
        &pos->member != (head); \
        pos = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)))