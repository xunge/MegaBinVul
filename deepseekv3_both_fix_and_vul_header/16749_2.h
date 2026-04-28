#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define EIO 5
#define EACCES 13
#define EOPNOTSUPP 95
#define ENOSYS 38
#define XATTR_LIST_MAX 65536
#define FUSE_LISTXATTR 0

struct dentry;
struct inode;

struct fuse_conn {
    bool no_listxattr;
};

struct fuse_mount {
    struct fuse_conn *fc;
};

struct fuse_in_arg {
    size_t size;
    const void *value;
};

struct fuse_out_arg {
    size_t size;
    void *value;
};

struct fuse_args {
    unsigned opcode;
    unsigned nodeid;
    unsigned in_numargs;
    unsigned out_numargs;
    bool out_argvar;
    struct fuse_in_arg in_args[1];
    struct fuse_out_arg out_args[1];
};

struct fuse_getxattr_in {
    size_t size;
};

struct fuse_getxattr_out {
    size_t size;
};

static inline struct inode *d_inode(const struct dentry *dentry) { return NULL; }
static inline struct fuse_mount *get_fuse_mount(struct inode *inode) { return NULL; }
static inline unsigned long get_node_id(struct inode *inode) { return 0; }
static inline int fuse_is_bad(struct inode *inode) { return 0; }
static inline int fuse_allow_current_process(struct fuse_conn *fc) { return 1; }
static inline ssize_t fuse_simple_request(struct fuse_mount *fm, struct fuse_args *args) { return 0; }
static inline ssize_t fuse_verify_xattr_list(char *list, ssize_t size) { return size; }

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define FUSE_ARGS(args) struct fuse_args args = {0}