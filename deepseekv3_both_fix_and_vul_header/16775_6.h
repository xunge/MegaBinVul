#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct inode {
    int dummy;
};
struct file {
    unsigned int f_flags;
};
struct fuse_mount {
    struct fuse_conn *fc;
};
struct fuse_conn {
    bool atomic_o_trunc;
    bool writeback_cache;
};
struct rw_semaphore {
    int dummy;
};
struct fuse_inode {
    struct rw_semaphore i_mmap_sem;
};

#define EIO 5
#define O_TRUNC 01000
#define FUSE_IS_DAX(i) (0)

static inline struct fuse_inode *get_fuse_inode(struct inode *inode) { return (struct fuse_inode *)inode; }
static inline struct fuse_mount *get_fuse_mount(struct inode *inode) { return (struct fuse_mount *)inode; }
static inline unsigned long get_node_id(struct inode *inode) { return 0; }
static inline bool fuse_is_bad(struct inode *inode) { return false; }
static inline int generic_file_open(struct inode *inode, struct file *file) { return 0; }
static inline void inode_lock(struct inode *inode) {}
static inline void inode_unlock(struct inode *inode) {}
static inline void fuse_set_nowrite(struct inode *inode) {}
static inline void fuse_release_nowrite(struct inode *inode) {}
static inline void down_write(struct rw_semaphore *sem) {}
static inline void up_write(struct rw_semaphore *sem) {}
static inline int fuse_dax_break_layouts(struct inode *inode, loff_t start, loff_t end) { return 0; }
static inline int fuse_do_open(struct fuse_mount *fm, unsigned long nodeid, struct file *file, bool isdir) { return 0; }
static inline void fuse_finish_open(struct inode *inode, struct file *file) {}