#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef uint32_t umode_t;
typedef uint64_t u64;

struct dentry {
    struct inode *d_inode;
    const char *d_name;
};

struct inode {
    umode_t i_mode;
    unsigned long i_ino;
};

struct fuse_mount {
    void *fc;
};

struct fuse_inode {
    int lock;
    unsigned long nlookup;
    unsigned long state;
};

struct fuse_entry_out {
    uint64_t nodeid;
    struct {
        umode_t mode;
        uint32_t flags;
    } attr;
};

struct fuse_args {
    int dummy;
} args;

struct fuse_forget_link {
    int dummy;
};

#define LOOKUP_EXCL 0x01
#define LOOKUP_REVAL 0x02
#define LOOKUP_RCU 0x04
#define FUSE_ATTR_SUBMOUNT (1 << 0)
#define S_IFMT 0170000
#define FUSE_I_INIT_RDPLUS 0

#define ECHILD 10
#define ENOMEM 12
#define ENOENT 2

#define IS_AUTOMOUNT(inode) (0)

static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline bool test_bit(int nr, const volatile unsigned long *addr) { return false; }
static inline bool test_and_clear_bit(int nr, volatile unsigned long *addr) { return false; }

static inline struct inode *d_inode_rcu(const struct dentry *dentry) { return NULL; }
static inline struct inode *d_inode(const struct dentry *dentry) { return NULL; }
static inline int is_bad_inode(struct inode *inode) { return 0; }
static inline int time_before64(u64 a, u64 b) { return 0; }
static inline u64 fuse_dentry_time(struct dentry *entry) { return 0; }
static inline u64 get_jiffies_64(void) { return 0; }
static inline void FUSE_ARGS(struct fuse_args args) {}
static inline struct fuse_mount *get_fuse_mount(struct inode *inode) { return NULL; }
static inline struct fuse_forget_link *fuse_alloc_forget(void) { return NULL; }
static inline u64 fuse_get_attr_version(void *fc) { return 0; }
static inline struct dentry *dget_parent(struct dentry *entry) { return NULL; }
static inline u64 get_node_id(struct inode *inode) { return 0; }
static inline void fuse_lookup_init(void *fc, struct fuse_args *args, u64 nodeid, const char **name, struct fuse_entry_out *outarg) {}
static inline int fuse_simple_request(struct fuse_mount *fm, struct fuse_args *args) { return 0; }
static inline void dput(struct dentry *dentry) {}
static inline struct fuse_inode *get_fuse_inode(struct inode *inode) { return NULL; }
static inline void fuse_queue_forget(void *fc, struct fuse_forget_link *forget, u64 nodeid, int nlookup) {}
static inline void kfree(void *ptr) {}
static inline int fuse_invalid_attr(void *attr) { return 0; }
static inline void forget_all_cached_acls(struct inode *inode) {}
static inline void fuse_change_attributes(struct inode *inode, void *attr, u64 timeout, u64 attr_version) {}
static inline u64 entry_attr_timeout(struct fuse_entry_out *outarg) { return 0; }
static inline void fuse_change_entry_timeout(struct dentry *entry, struct fuse_entry_out *outarg) {}
static inline void fuse_advise_use_readdirplus(struct inode *inode) {}