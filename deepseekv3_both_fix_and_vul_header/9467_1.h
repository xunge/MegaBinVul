#include <stddef.h>

struct hlist_node {
    struct hlist_node *next;
    struct hlist_node **pprev;
};

struct inode {
    struct hlist_node *i_dentry;
};

struct qstr {
    const char *name;
};

struct lu_fid {
    unsigned long fid_data[4];
};

struct dentry {
    struct inode *d_inode;
    struct hlist_node d_alias;
    struct {
        struct hlist_node d_alias;
    } d_u;
};

#define ll_d_hlist_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

static inline struct lu_fid *ll_inode2fid(struct inode *inode) {
    return (struct lu_fid *)inode;
}

static inline struct dentry *d_lookup(struct dentry *parent, struct qstr *name) {
    return NULL;
}

static inline void dput(struct dentry *dentry) {
}