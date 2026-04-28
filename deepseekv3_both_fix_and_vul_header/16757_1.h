#include <stdint.h>
#include <string.h>
#include <sys/stat.h>

typedef uint64_t u64;

struct inode {
    unsigned int i_mode;
};

struct kstat;
struct file {
    void *private_data;
};

struct fuse_mount {
    void *fc;
};

struct fuse_file {
    u64 fh;
};

struct fuse_getattr_in {
    u64 getattr_flags;
    u64 fh;
};

struct fuse_attr_out {
    struct {
        unsigned int mode;
    } attr;
};

struct fuse_args {
    int opcode;
    u64 nodeid;
    int in_numargs;
    struct {
        size_t size;
        void *value;
    } in_args[1];
    int out_numargs;
    struct {
        size_t size;
        void *value;
    } out_args[1];
};

#define FUSE_GETATTR 3
#define FUSE_GETATTR_FH (1 << 0)
#define EIO 5

#define FUSE_ARGS(name) struct fuse_args name

static inline u64 fuse_get_attr_version(void *fc) { return 0; }
static inline struct fuse_mount *get_fuse_mount(struct inode *inode) { return NULL; }
static inline int fuse_simple_request(struct fuse_mount *fm, struct fuse_args *args) { return 0; }
static inline int fuse_invalid_attr(void *attr) { return 0; }
static inline void make_bad_inode(struct inode *inode) {}
static inline void fuse_change_attributes(struct inode *inode, void *attr, int timeout, u64 version) {}
static inline int attr_timeout(struct fuse_attr_out *outarg) { return 0; }
static inline void fuse_fillattr(struct inode *inode, void *attr, struct kstat *stat) {}
static inline u64 get_node_id(struct inode *inode) { return 0; }