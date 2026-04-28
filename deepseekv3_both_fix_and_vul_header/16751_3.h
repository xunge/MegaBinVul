#include <stddef.h>
#include <stdint.h>

typedef uint64_t u64;

struct file {
    struct {
        struct dentry *dentry;
    } f_path;
};

struct fuse_entry_out {
    u64 nodeid;
    u64 generation;
    struct {
        unsigned int mode;
    } attr;
};

struct fuse_dirent {
    char *name;
    unsigned int namelen;
};

struct fuse_direntplus {
    struct fuse_entry_out entry_out;
    struct fuse_dirent dirent;
};

struct qstr {
    const char *name;
    unsigned int len;
    unsigned int hash;
};

struct dentry;
struct inode {
    unsigned int i_mode;
    void *i_sb;
};

struct fuse_conn {
    int readdirplus_auto;
};

struct fuse_inode {
    int nlookup;
    void *lock;
    unsigned long state;
};

struct wait_queue_head {
    int dummy;
};

#define QSTR_INIT(name, len) { (name), (len), 0 }
#define DECLARE_WAIT_QUEUE_HEAD_ONSTACK(name) struct wait_queue_head name = {0}
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)
#define PTR_ERR(ptr) ((long)(ptr))
#define ERR_PTR(error) ((void *)(long)(error))
#define S_IFMT 0170000
#define EIO 5
#define ENOMEM 12
#define FUSE_I_INIT_RDPLUS 0

static inline int invalid_nodeid(u64 nodeid) { return 0; }
static inline int fuse_invalid_attr(void *attr) { return 0; }
static inline struct fuse_conn *get_fuse_conn(struct inode *inode) { return NULL; }
static inline int d_in_lookup(struct dentry *dentry) { return 0; }
static inline void d_invalidate(struct dentry *dentry) {}
static inline void dput(struct dentry *dentry) {}
static inline int is_bad_inode(struct inode *inode) { return 0; }
static inline struct fuse_inode *get_fuse_inode(struct inode *inode) { return NULL; }
static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline void forget_all_cached_acls(struct inode *inode) {}
static inline void fuse_change_attributes(struct inode *inode, void *attr, int timeout, u64 version) {}
static inline struct inode *fuse_iget(void *sb, u64 nodeid, u64 generation, void *attr, int timeout, u64 version) { return NULL; }
static inline struct dentry *d_splice_alias(struct inode *inode, struct dentry *dentry) { return NULL; }
static inline void d_lookup_done(struct dentry *dentry) {}
static inline void set_bit(int nr, void *addr) {}
static inline void fuse_change_entry_timeout(struct dentry *dentry, struct fuse_entry_out *o) {}
static inline unsigned int full_name_hash(struct dentry *parent, const char *name, unsigned int len) { return 0; }
static inline struct dentry *d_lookup(struct dentry *parent, struct qstr *name) { return NULL; }
static inline struct dentry *d_alloc_parallel(struct dentry *parent, struct qstr *name, struct wait_queue_head *wq) { return NULL; }
static inline struct inode *d_inode(struct dentry *dentry) { return NULL; }
static inline u64 get_node_id(struct inode *inode) { return 0; }
static inline int entry_attr_timeout(struct fuse_entry_out *o) { return 0; }