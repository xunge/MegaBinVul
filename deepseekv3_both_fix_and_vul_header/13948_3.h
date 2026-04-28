#include <stdint.h>
#include <stddef.h>

#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)

typedef uint32_t __u32;

struct qstr {
    const char *name;
};

struct path {
    void *dentry;
};

struct dentry {
    unsigned int d_flags;
    void *d_inode;
    struct qstr d_name;
    void *d_parent;
};

struct inode {
    __u32 i_fsnotify_mask;
};

struct name_snapshot {
    const char *name;
};

#define DCACHE_FSNOTIFY_PARENT_WATCHED 0x00000001
#define FS_EVENT_ON_CHILD 0x00000002
#define FSNOTIFY_EVENT_PATH 0
#define FSNOTIFY_EVENT_INODE 1

static inline struct dentry *dget_parent(struct dentry *dentry) { return dentry; }
static inline void dput(struct dentry *dentry) {}
static inline int fsnotify_inode_watches_children(struct inode *inode) { return 0; }
static inline void __fsnotify_update_child_dentry_flags(struct inode *inode) {}
static inline int fsnotify(struct inode *inode, __u32 mask, const void *data, int type, const char *name, int cookie) { return 0; }
static inline void take_dentry_name_snapshot(struct name_snapshot *name, struct dentry *dentry) {}
static inline void release_dentry_name_snapshot(struct name_snapshot *name) {}