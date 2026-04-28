#include <stddef.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

struct address_space {
    struct address_space_operations *a_ops;
    struct backing_dev_info *backing_dev_info;
};

struct inode {
    unsigned int i_mode;
    uid_t i_uid;
    gid_t i_gid;
    unsigned long i_blocks;
    struct address_space *i_mapping;
    time_t i_atime;
    time_t i_mtime;
    time_t i_ctime;
    unsigned int i_generation;
    const struct inode_operations *i_op;
    const struct file_operations *i_fop;
    loff_t i_size;
    unsigned int i_nlink;
};

struct super_block {
    void *s_fs_info;
};

struct shmem_inode_info {
    struct inode vfs_inode;
    void *lock;
    void *swaplist;
    struct shared_policy *policy;
};

struct shared_policy;
struct mempolicy;
struct address_space_operations;
struct inode_operations;
struct file_operations;
struct backing_dev_info;
struct shmem_sb_info;

struct task_struct {
    uid_t fsuid;
    gid_t fsgid;
};

extern struct task_struct *current;
extern struct backing_dev_info shmem_backing_dev_info;
extern struct address_space_operations shmem_aops;
extern struct inode_operations shmem_special_inode_operations;
extern struct inode_operations shmem_inode_operations;
extern struct file_operations shmem_file_operations;
extern struct inode_operations shmem_dir_inode_operations;
extern struct file_operations simple_dir_operations;

#define SHMEM_SB(sb) ((struct shmem_sb_info *)(sb)->s_fs_info)
#define SHMEM_I(inode) ((struct shmem_inode_info *)((void*)(inode) - offsetof(struct shmem_inode_info, vfs_inode)))
#define BOGO_DIRENT_SIZE 20
#define CURRENT_TIME (time(NULL))
#define S_IFMT 00170000
#define S_IFREG 0100000
#define S_IFDIR 0040000
#define S_IFLNK 0120000

static inline void spin_lock_init(void *lock) {}
static inline void INIT_LIST_HEAD(void *list) {}
static inline void inc_nlink(struct inode *inode) { inode->i_nlink++; }
static inline time_t get_seconds(void) { return time(NULL); }

extern int shmem_reserve_inode(struct super_block *sb);
extern void shmem_free_inode(struct super_block *sb);
extern struct inode *new_inode(struct super_block *sb);
extern void init_special_inode(struct inode *inode, int mode, dev_t dev);
extern void mpol_shared_policy_init(struct shared_policy *sp, struct mempolicy *mpol);
extern struct mempolicy *shmem_get_sbmpol(struct shmem_sb_info *sbinfo);