#include <stddef.h>

#define LASSERT(cond) do { } while (0)
#define CDEBUG(level, fmt, ...) do { } while (0)
#define CERROR(fmt, ...) do { } while (0)
#define D_INODE 0
#define D_DENTRY 0
#define DFID ""
#define PFID(fid) ""
#define unlikely(x) (x)

struct hlist_node {
    struct hlist_node *next, **pprev;
};
struct hlist_head {
    struct hlist_node *first;
};

struct ll_d_hlist_node {
    struct hlist_node node;
};

#define ll_d_hlist_for_each_entry(pos, p, head, member) \
    for (p = (struct ll_d_hlist_node*)(head)->first; p && ({ \
        pos = (typeof(*pos)*)((char*)p - offsetof(typeof(*pos), member.node)); 1; \
    }); p = (struct ll_d_hlist_node*)p->node.next)

struct qstr {
    unsigned int len;
    const char *name;
};

struct super_block;
struct dentry;
struct inode {
    unsigned long i_ino;
    unsigned int i_generation;
    struct hlist_head i_dentry;
};

struct dentry {
    struct qstr d_name;
    struct dentry *d_parent;
    struct inode *d_inode;
    struct super_block *d_sb;
    unsigned int d_flags;
    struct ll_d_hlist_node d_alias;
    struct {
        struct ll_d_hlist_node d_alias;
    } d_u;
};

struct super_block {
    struct dentry *s_root;
};

static inline void ll_lock_dcache(struct inode *inode) {}
static inline void ll_unlock_dcache(struct inode *inode) {}
static inline const char *ll_get_fsname(struct super_block *sb, char *buf, int len) { return ""; }
static inline void *ll_inode2fid(struct inode *inode) { return NULL; }
static inline void lustre_dump_dentry(struct dentry *dentry, int flag) {}
static inline void d_lustre_invalidate(struct dentry *dentry, int flag) {}
static inline void dump_stack(void) {}