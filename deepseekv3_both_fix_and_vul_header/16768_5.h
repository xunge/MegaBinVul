#include <stddef.h>
#include <stdint.h>

typedef uint64_t u64;

struct inode {
    unsigned long i_ino;
    unsigned int i_mode;
    unsigned int i_flags;
    unsigned long i_state;
    unsigned int i_generation;
    struct fuse_inode *i_private;
};

struct super_block {};
struct fuse_attr {
    unsigned int mode;
    unsigned int flags;
};
struct fuse_conn {
    unsigned int auto_submounts;
    unsigned int writeback_cache;
};
struct fuse_inode {
    void* lock;
    unsigned long nodeid;
    unsigned int nlookup;
};

#define FUSE_ATTR_SUBMOUNT (1 << 0)
#define S_IFMT 00170000
#define S_ISDIR(mode) (((mode) & S_IFMT) == 0040000)
#define S_ISREG(mode) (((mode) & S_IFMT) == 0100000)
#define S_AUTOMOUNT 0x00001000
#define S_NOATIME 0x00040000
#define S_NOCMTIME 0x00080000
#define I_NEW 0x00000080

static inline void spin_lock(void* lock) {}
static inline void spin_unlock(void* lock) {}

static inline struct fuse_conn* get_fuse_conn_super(struct super_block* sb) { return NULL; }
static inline struct inode* new_inode(struct super_block* sb) { return NULL; }
static inline void fuse_init_inode(struct inode* inode, struct fuse_attr* attr) {}
static inline struct fuse_inode* get_fuse_inode(struct inode* inode) { return inode ? inode->i_private : NULL; }
static inline int fuse_inode_eq(struct inode* inode, void* data) { return 0; }
static inline int fuse_inode_set(struct inode* inode, void* data) { return 0; }
static inline struct inode* iget5_locked(struct super_block* sb, unsigned long ino,
                                       int (*test)(struct inode*, void*),
                                       int (*set)(struct inode*, void*),
                                       void* data) { return NULL; }
static inline void unlock_new_inode(struct inode* inode) {}
static inline void make_bad_inode(struct inode* inode) {}
static inline void iput(struct inode* inode) {}
static inline void fuse_change_attributes(struct inode* inode, struct fuse_attr* attr,
                                        u64 attr_valid, u64 attr_version) {}