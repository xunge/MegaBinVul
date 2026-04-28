#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct inode {
    unsigned long i_ino;
    unsigned int i_generation;
    struct list_head i_dentry;
};

struct dentry {
    struct super_block *d_sb;
    struct dentry *d_parent;
    struct inode *d_inode;
    int d_flags;
    struct {
        unsigned int len;
        const char *name;
    } d_name;
    struct list_head d_alias;
};

struct super_block {
    struct dentry *s_root;
};

struct ll_d_hlist_node {
    struct ll_d_hlist_node *next, **pprev;
};

struct fid {
    int f_seq;
    int f_oid;
};

#define LASSERT(cond) ((void)0)
#define CDEBUG(level, fmt, ...) ((void)0)
#define CERROR(fmt, ...) ((void)0)
#define D_INODE 0
#define D_DENTRY 0
#define DFID "%d:%d"
#define PFID(fid) (fid)->f_seq, (fid)->f_oid
#define unlikely(x) (x)

#define ll_d_hlist_for_each_entry(dentry, p, head, member) \
    for (p = (struct ll_d_hlist_node *)(head)->next; \
         p != (struct ll_d_hlist_node *)(head); \
         p = p->next)

void ll_lock_dcache(struct inode *inode);
void ll_unlock_dcache(struct inode *inode);
char *ll_get_fsname(struct super_block *sb, char *buf, int len);
void lustre_dump_dentry(struct dentry *dentry, int level);
void dump_stack(void);
void d_lustre_invalidate(struct dentry *dentry, int flags);
struct fid *ll_inode2fid(struct inode *inode);