#include <limits.h>

#define HUGETLBFS_MAGIC 0x958458f6
#define NAME_MAX 255

struct super_block {
    void *s_fs_info;
};

struct dentry {
    struct super_block *d_sb;
    struct inode *d_inode;
};

struct inode;

struct kstatfs {
    long f_type;
    long f_bsize;
    long f_blocks;
    long f_bfree;
    long f_bavail;
    long f_files;
    long f_ffree;
    long f_namelen;
};

struct hugetlbfs_sb_info {
    int stat_lock;
    struct hugetlbfs_spool *spool;
    long max_blocks;
    long free_blocks;
    long max_inodes;
    long free_inodes;
};

struct hugetlbfs_spool {
    int lock;
    long max_hpages;
    long used_hpages;
};

struct hstate {
    unsigned long huge_page_size;
};

#define HUGETLBFS_SB(sb) ((struct hugetlbfs_sb_info *)(sb->s_fs_info))

static inline void spin_lock(int *lock) { (void)lock; }
static inline void spin_unlock(int *lock) { (void)lock; }

static struct hstate *hstate_inode(struct inode *inode) {
    static struct hstate dummy_hstate;
    return &dummy_hstate;
}

static unsigned long huge_page_size(struct hstate *h) {
    return h->huge_page_size;
}