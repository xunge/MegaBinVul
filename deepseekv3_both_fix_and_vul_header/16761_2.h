#include <stdbool.h>
#include <stddef.h>

struct inode {
    unsigned long i_ino;
    void *i_sb;
};

struct dentry {
    struct inode *d_inode;
    char d_name[256];
};

struct fuse_entry_out {
    unsigned long nodeid;
    unsigned long generation;
    unsigned long entry_valid;
    unsigned long attr_valid;
    unsigned long entry_valid_nsec;
    unsigned long attr_valid_nsec;
    struct {
        unsigned long mode;
        unsigned long nlink;
        unsigned long uid;
        unsigned long gid;
        unsigned long rdev;
        unsigned long size;
        unsigned long blocks;
        unsigned long atime;
        unsigned long mtime;
        unsigned long ctime;
        unsigned long atimensec;
        unsigned long mtimensec;
        unsigned long ctimensec;
    } attr;
};

#define ENOENT 2
#define EIO 5
#define FUSE_ROOT_ID 1

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000)
#define PTR_ERR(x) ((long)(x))
#define ERR_PTR(x) ((void *)(long)(x))

static inline bool fuse_lock_inode(struct inode *inode) { return false; }
static inline int fuse_lookup_name(void *sb, unsigned long nodeid, char *name, 
                                 struct fuse_entry_out *outarg, struct inode **inode) { return 0; }
static inline void fuse_unlock_inode(struct inode *inode, bool locked) {}
static inline struct dentry *d_splice_alias(struct inode *inode, struct dentry *dentry) { return NULL; }
static inline void fuse_change_entry_timeout(struct dentry *dentry, struct fuse_entry_out *outarg) {}
static inline void fuse_invalidate_entry_cache(struct dentry *dentry) {}
static inline void fuse_advise_use_readdirplus(struct inode *dir) {}
static inline void iput(struct inode *inode) {}
static inline unsigned long get_node_id(struct inode *inode) { return 0; }