#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct inode;

struct dentry {
    struct inode *d_inode;
    struct list_head d_subdirs;
    struct list_head d_child;
    int d_lock;
};

#define spin_lock(lock) ((void)(lock))
#define spin_unlock(lock) ((void)(lock))
#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != (head); pos = (head)->next)

static void coda_flag_inode(struct inode *inode, int flag);