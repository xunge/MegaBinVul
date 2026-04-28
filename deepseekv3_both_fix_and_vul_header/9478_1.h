#include <stddef.h>

struct inode {
    unsigned long i_ino;
    unsigned int i_generation;
    void *i_dentry;
};

struct dentry {
    struct {
        struct {
            struct dentry *d_alias;
        } d_u;
    };
    struct super_block *d_sb;
    struct dentry *d_parent;
    void *d_inode;
    int d_flags;
    struct {
        int len;
        char *name;
    } d_name;
};

struct super_block {
    struct dentry *s_root;
};

struct ll_d_hlist_node {
    void *node;
};

#define LASSERT(cond) do { } while (0)
#define CDEBUG(level, fmt, ...)
#define CERROR(fmt, ...)
#define D_INODE 0
#define D_DENTRY 0
#define DFID "%d"
#define PFID(fid) 0
#define unlikely(cond) (cond)

struct fid {
    int dummy;
};

static inline struct fid *ll_inode2fid(struct inode *inode) { return NULL; }
static inline const char *ll_get_fsname(struct super_block *sb, char *buf, int len) { return NULL; }
static inline void lustre_dump_dentry(struct dentry *dentry, int flag) {}
static inline void d_lustre_invalidate(struct dentry *dentry, int flag) {}
static inline void ll_lock_dcache(struct inode *inode) {}
static inline void ll_unlock_dcache(struct inode *inode) {}
static inline void dump_stack(void) {}

#define ll_d_hlist_for_each_entry(dentry, p, head, member) \
    for (dentry = NULL; dentry != NULL; dentry = NULL)