#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct inode {
    void *i_sb;
};

struct btrfs_fs_info {
    void *qgroup_ioctl_lock;
};

struct btrfs_root;
struct btrfs_trans_handle;

struct btrfs_inode {
    struct btrfs_root *root;
};

#define BTRFS_I(inode) ((struct btrfs_inode *)(inode))
#define CAP_SYS_ADMIN 0
#define EPERM 1
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define __user

struct btrfs_ioctl_qgroup_assign_args {
    unsigned long long assign;
    unsigned long long src;
    unsigned long long dst;
};

static inline void *memdup_user(const void __user *src, size_t len) {
    void *p = malloc(len);
    if (p) memcpy(p, src, len);
    return p;
}

static inline int capable(int cap) { return 0; }
static inline int mnt_want_write_file(void *file) { return 0; }
static inline void mnt_drop_write_file(void *file) {}
static inline struct inode *file_inode(void *file) { return NULL; }
static inline struct btrfs_fs_info *btrfs_sb(void *sb) { return NULL; }
static inline struct btrfs_trans_handle *btrfs_join_transaction(struct btrfs_root *root) { return NULL; }
static inline int btrfs_add_qgroup_relation(struct btrfs_trans_handle *trans, unsigned long long src, unsigned long long dst) { return 0; }
static inline int btrfs_del_qgroup_relation(struct btrfs_trans_handle *trans, unsigned long long src, unsigned long long dst) { return 0; }
static inline int btrfs_run_qgroups(struct btrfs_trans_handle *trans) { return 0; }
static inline void btrfs_handle_fs_error(struct btrfs_fs_info *fs_info, int err, const char *msg) {}
static inline int btrfs_end_transaction(struct btrfs_trans_handle *trans) { return 0; }
static inline void mutex_lock(void *lock) {}
static inline void mutex_unlock(void *lock) {}
static inline void kfree(void *p) { free(p); }