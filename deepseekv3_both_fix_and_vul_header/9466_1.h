#include <stddef.h>
#include <string.h>

struct ll_d_hlist_node {
    struct ll_d_hlist_node *next;
    struct ll_d_hlist_node **pprev;
};

struct dentry {
    unsigned int d_flags;
    struct dentry *d_parent;
    struct {
        unsigned int hash;
        unsigned int len;
        const char *name;
    } d_name;
    struct {
        struct ll_d_hlist_node *d_alias;
    } d_u;
    int d_lock;
};

struct inode {
    struct ll_d_hlist_node i_dentry;
};

#define DCACHE_DISCONNECTED 0x00000002
#define LASSERT(cond) do { } while (0)

static inline int ll_d_hlist_empty(const struct ll_d_hlist_node *h) { return 0; }
static inline void ll_lock_dcache(struct inode *inode) { }
static inline void ll_unlock_dcache(struct inode *inode) { }
static inline void spin_lock(int *lock) { }
static inline void spin_unlock(int *lock) { }
static inline void dget_dlock(struct dentry *dentry) { }

#define ll_d_hlist_for_each_entry(pos, p, head, member) \
    for (p = (head)->next; p; p = p->next)