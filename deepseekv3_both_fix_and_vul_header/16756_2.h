#include <stdatomic.h>
#include <stddef.h>

#define FUSE_UNLINK 0
#define EIO 5
#define EINTR 4

typedef _Atomic long long atomic64_t;

struct inode {
    unsigned long i_ino;
    unsigned int i_nlink;
};

struct dentry {
    struct {
        unsigned int len;
        const char *name;
    } d_name;
    struct inode *d_inode;
};

struct fuse_conn {
    atomic64_t attr_version;
};

struct fuse_mount {
    struct fuse_conn *fc;
};

struct fuse_inode {
    atomic_flag lock;
    atomic64_t attr_version;
};

struct fuse_args {
    unsigned int opcode;
    unsigned long nodeid;
    unsigned int in_numargs;
    struct {
        size_t size;
        const void *value;
    } in_args[1];
};

extern struct fuse_mount *get_fuse_mount(struct inode *);
extern int fuse_is_bad(struct inode *);
extern unsigned long get_node_id(struct inode *);
extern int fuse_simple_request(struct fuse_mount *, struct fuse_args *);
extern struct inode *d_inode(struct dentry *);
extern struct fuse_inode *get_fuse_inode(struct inode *);
extern void drop_nlink(struct inode *);
extern void fuse_invalidate_attr(struct inode *);
extern void fuse_dir_changed(struct inode *);
extern void fuse_invalidate_entry_cache(struct dentry *);
extern void fuse_update_ctime(struct inode *);
extern void fuse_invalidate_entry(struct dentry *);

#define spin_lock(lock) atomic_flag_test_and_set(lock)
#define spin_unlock(lock) atomic_flag_clear(lock)
#define atomic64_inc_return(v) atomic_fetch_add(v, 1) + 1

#define FUSE_ARGS(args) struct fuse_args args = {}