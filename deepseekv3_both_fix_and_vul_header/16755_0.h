#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <linux/fs.h>
#include <linux/fuse.h>

typedef uint64_t u64;

struct inode {
    unsigned long i_ino;
};

struct dentry {
    struct {
        unsigned int len;
        const char *name;
    } d_name;
};

struct fuse_mount {
    struct inode *inode;
};

struct fuse_args {
    int opcode;
    u64 nodeid;
    unsigned in_numargs;
    struct {
        size_t size;
        const void *value;
    } in_args[1];
};

#define FUSE_ARGS(name) struct fuse_args name = {0}
#define FUSE_RMDIR 0
#define EINTR 4
#define EIO 5

static inline int fuse_is_bad(struct inode *inode) { return 0; }
static inline struct fuse_mount *get_fuse_mount(struct inode *inode) { return NULL; }
static inline u64 get_node_id(struct inode *inode) { return 0; }
static inline int fuse_simple_request(struct fuse_mount *fm, struct fuse_args *args) { return 0; }
static inline void clear_nlink(struct inode *inode) {}
static inline struct inode *d_inode(const struct dentry *dentry) { return NULL; }
static inline void fuse_dir_changed(struct inode *dir) {}
static inline void fuse_invalidate_entry_cache(struct dentry *entry) {}
static inline void fuse_invalidate_entry(struct dentry *entry) {}