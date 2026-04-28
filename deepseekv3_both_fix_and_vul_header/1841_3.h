#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

typedef struct {
    volatile int counter;
} atomic64_t;

typedef struct {
    volatile int lock;
} spinlock_t;

struct super_block {
    struct the_nilfs *s_fs_info;
};

struct the_nilfs {
    spinlock_t ns_next_gen_lock;
    uint64_t ns_next_generation;
};

struct inode {
    struct super_block *i_sb;
    void *i_mapping;
    ino_t i_ino;
    struct timespec i_mtime;
    struct timespec i_atime;
    struct timespec i_ctime;
    unsigned long i_state;
    unsigned int i_flags;
    unsigned long i_generation;
};

struct nilfs_inode_info {
    unsigned long i_state;
    struct nilfs_root *i_root;
    struct buffer_head *i_bh;
    void *i_bmap;
    unsigned int i_flags;
    unsigned long i_dir_start_lookup;
};

struct nilfs_root {
    void *ifile;
    atomic64_t inodes_count;
};

struct buffer_head {};

#define NILFS_USER_INO 0
#define NILFS_I_NEW 0
#define NILFS_I_BMAP 0
#define NILFS_FL_INHERITED 0
#define __GFP_FS 0
#define I_NEW 0

#define BIT(nr) (1UL << (nr))
#define unlikely(x) (x)
#define ENOMEM 12
#define EIO 5

typedef uint32_t umode_t;
typedef uint64_t ino_t;

struct init_user_ns {};

static struct init_user_ns init_user_ns;

#define NILFS_I(inode) ((struct nilfs_inode_info *)(inode))

static inline struct inode *new_inode(struct super_block *sb) { return NULL; }
static inline void mapping_set_gfp_mask(void *mapping, unsigned long gfp_mask) {}
static inline unsigned long mapping_gfp_constraint(void *mapping, unsigned long gfp_mask) { return 0; }
static inline int nilfs_ifile_create_inode(void *ifile, ino_t *ino, struct buffer_head **bh) { return 0; }
static inline void brelse(struct buffer_head *bh) {}
static inline void nilfs_warn(struct super_block *sb, const char *fmt, ...) {}
static inline void nilfs_info(struct super_block *sb, const char *fmt, ...) {}
static inline void atomic64_inc(atomic64_t *v) { v->counter++; }
static inline void inode_init_owner(struct init_user_ns *ns, struct inode *inode, struct inode *dir, umode_t mode) {}
static inline struct timespec current_time(struct inode *inode) { struct timespec ts = {0}; return ts; }
static inline int nilfs_bmap_read(void *bmap, void *data) { return 0; }
static inline void set_bit(int nr, volatile unsigned long *addr) { *addr |= (1UL << nr); }
static inline unsigned int nilfs_mask_flags(umode_t mode, unsigned int flags) { return 0; }
static inline void nilfs_set_inode_flags(struct inode *inode) {}
static inline void spin_lock(spinlock_t *lock) { while(__sync_lock_test_and_set(&lock->lock, 1)); }
static inline void spin_unlock(spinlock_t *lock) { __sync_lock_release(&lock->lock); }
static inline int nilfs_insert_inode_locked(struct inode *inode, struct nilfs_root *root, ino_t ino) { return 0; }
static inline int nilfs_init_acl(struct inode *inode, struct inode *dir) { return 0; }
static inline void clear_nlink(struct inode *inode) {}
static inline void unlock_new_inode(struct inode *inode) {}
static inline void iput(struct inode *inode) {}
static inline void make_bad_inode(struct inode *inode) {}
static inline void *ERR_PTR(long error) { return (void *)error; }