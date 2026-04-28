#include <stdbool.h>

#define EACCES 13
#define LAST_BIND 0

struct inode {
    void *d_inode;
};

struct dentry {
    struct inode *d_inode;
};

struct path {
    // dummy path structure
};

struct nameidata {
    struct path path;
    int last_type;
};

struct proc_inode {
    struct {
        int (*proc_get_link)(struct inode *, struct path *);
    } op;
};

#define PROC_I(inode) ((struct proc_inode *)(inode))
#define ERR_PTR(err) ((void *)((long)(err)))

static inline bool proc_fd_access_allowed(struct inode *inode) { return false; }
static inline void path_put(struct path *path) {}