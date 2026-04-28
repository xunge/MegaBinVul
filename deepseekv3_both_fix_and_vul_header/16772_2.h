#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdint.h>

#define EIO 5
#define ENOSYS 38
#define FUSE_FLUSH 0

typedef int fl_owner_t;
typedef uint64_t u64;

struct file {
    void *private_data;
    struct address_space *f_mapping;
};

struct inode;
struct address_space;

struct fuse_file {
    unsigned int fh;
};

struct fuse_conn {
    bool no_flush;
    bool writeback_cache;
};

struct fuse_mount {
    struct fuse_conn *fc;
};

struct fuse_flush_in {
    unsigned int fh;
    u64 lock_owner;
};

struct fuse_in_arg {
    unsigned int size;
    const void *value;
};

struct fuse_args {
    unsigned int opcode;
    unsigned int nodeid;
    unsigned int in_numargs;
    struct fuse_in_arg in_args[1];
    bool force;
};

#define FUSE_ARGS(args) struct fuse_args args = {}

static inline struct inode *file_inode(struct file *file) { return NULL; }
static inline struct fuse_mount *get_fuse_mount(struct inode *inode) { return NULL; }
static inline int is_bad_inode(struct inode *inode) { return 0; }
static inline int write_inode_now(struct inode *inode, int sync) { return 0; }
static inline void inode_lock(struct inode *inode) {}
static inline void inode_unlock(struct inode *inode) {}
static inline void fuse_sync_writes(struct inode *inode) {}
static inline int filemap_check_errors(struct address_space *mapping) { return 0; }
static inline u64 fuse_lock_owner_id(struct fuse_conn *fc, fl_owner_t id) { return 0; }
static inline u64 get_node_id(struct inode *inode) { return 0; }
static inline int fuse_simple_request(struct fuse_mount *fm, struct fuse_args *args) { return 0; }
static inline void fuse_invalidate_attr(struct inode *inode) {}