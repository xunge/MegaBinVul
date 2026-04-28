#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

struct dentry {
    struct inode *d_inode;
};

struct inode {
    mode_t i_mode;
};

struct iattr {
    unsigned int ia_valid;
    mode_t ia_mode;
    struct file *ia_file;
};

struct file {
    // minimal file structure
};

struct fuse_conn {
    unsigned handle_killpriv:1;
    unsigned handle_killpriv_v2:1;
    unsigned posix_acl:1;
};

#define ATTR_FILE          (1 << 0)
#define ATTR_KILL_SUID     (1 << 1) 
#define ATTR_KILL_SGID     (1 << 2)
#define ATTR_MODE          (1 << 3)

static inline struct inode* d_inode(struct dentry *dentry) { return dentry->d_inode; }
static inline struct fuse_conn* get_fuse_conn(struct inode *inode) { return NULL; }
static inline int fuse_allow_current_process(struct fuse_conn *fc) { return 1; }
static inline int fuse_do_getattr(struct inode *inode, void *null, struct file *file) { return 0; }
static inline int fuse_do_setattr(struct dentry *entry, struct iattr *attr, struct file *file) { return 0; }
static inline void forget_all_cached_acls(struct inode *inode) {}
static inline int d_is_dir(struct dentry *entry) { return 0; }
static inline void fuse_invalidate_entry_cache(struct dentry *entry) {}