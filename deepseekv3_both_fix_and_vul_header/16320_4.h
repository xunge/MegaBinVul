#include <stdatomic.h>
#include <stddef.h>

struct rw_semaphore {
    atomic_int count;
};

struct hlist_head {
    void *first;
};

struct inode_operations {
};
struct file_operations {
    int (*open)();
};
struct address_space_operations {
};
struct address_space {
    const struct address_space_operations *a_ops;
    struct inode *host;
    unsigned long flags;
    int wb_err;
    atomic_int i_mmap_writable;
    atomic_int nr_thps;
    unsigned int gfp_mask;
    void *private_data;
    unsigned long writeback_index;
};
struct super_block {
    unsigned int s_blocksize_bits;
    const void **s_xattr;
    struct file_system_type *s_type;
};
struct file_system_type {
    int i_lock_key;
    int i_mutex_key;
};
struct inode {
    struct super_block *i_sb;
    unsigned int i_blkbits;
    unsigned long i_flags;
    atomic_uint_fast64_t i_sequence;
    atomic_int i_count;
    const struct inode_operations *i_op;
    const struct file_operations *i_fop;
    unsigned int __i_nlink;
    unsigned int i_opflags;
    struct address_space i_data;
    unsigned int i_uid;
    unsigned int i_gid;
    atomic_int i_writecount;
    long long i_size;
    unsigned int i_write_hint;
    unsigned long i_blocks;
    unsigned int i_bytes;
    unsigned int i_generation;
    void *i_pipe;
    void *i_bdev;
    void *i_cdev;
    const char *i_link;
    unsigned int i_dir_seq;
    unsigned int i_rdev;
    unsigned long dirtied_when;
    unsigned short i_wb_frn_winner;
    unsigned short i_wb_frn_avg_time;
    unsigned short i_wb_frn_history;
    atomic_int i_lock;
    struct rw_semaphore i_rwsem;
    atomic_int i_dio_count;
    void *i_private;
    struct address_space *i_mapping;
    struct hlist_head i_dentry;
    void *i_acl;
    void *i_default_acl;
    unsigned int i_fsnotify_mask;
    void *i_flctx;
};

static const struct inode_operations empty_iops;
static int no_open() { return -1; }
static const struct file_operations no_open_fops = { .open = no_open };
static const struct address_space_operations empty_aops;
static unsigned int nr_inodes;

#define IOP_XATTR (1 << 0)
#define WRITE_LIFE_NOT_SET 0
#define GFP_HIGHUSER_MOVABLE 0
#define ACL_NOT_CACHED NULL
#define ENOMEM 12

static inline void atomic64_set(atomic_uint_fast64_t *v, long long i) { *v = i; }
static inline void atomic_set(atomic_int *v, int i) { *v = i; }
static inline void i_uid_write(struct inode *inode, unsigned int uid) { inode->i_uid = uid; }
static inline void i_gid_write(struct inode *inode, unsigned int gid) { inode->i_gid = gid; }
static inline int security_inode_alloc(struct inode *inode) { return 0; }
static inline void mapping_set_gfp_mask(struct address_space *mapping, unsigned int mask) { mapping->gfp_mask = mask; }
static inline void spin_lock_init(atomic_int *lock) { *lock = 0; }
static inline void lockdep_set_class(atomic_int *lock, int *key) {}
static inline void init_rwsem(struct rw_semaphore *sem) { atomic_init(&sem->count, 1); }
static inline void INIT_HLIST_HEAD(struct hlist_head *h) { h->first = NULL; }
static inline void this_cpu_inc(unsigned int *counter) { (*counter)++; }