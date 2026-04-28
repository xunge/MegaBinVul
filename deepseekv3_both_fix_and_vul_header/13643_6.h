#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#define BTRFS_PATH_NAME_MAX 4087
#define SZ_256M (256 * 1024 * 1024)
#define BTRFS_FS_EXCL_OP 0
#define BTRFS_DEV_STATE_WRITEABLE 0
#define BTRFS_DEV_STATE_REPLACE_TGT 0
#define BTRFS_ERROR_DEV_EXCL_RUN_IN_PROGRESS 0
#define CAP_SYS_ADMIN 0
#define EPERM 1
#define ENODEV 2
#define EINVAL 3
#define ERANGE 4
#define EFBIG 5

typedef uint64_t u64;
typedef uint8_t u8;
typedef int bool;
#define true 1
#define false 0

struct file;
struct inode {
    struct super_block *i_sb;
    u64 i_size;
};
struct super_block;
struct btrfs_fs_info {
    unsigned long flags;
    struct btrfs_fs_devices *fs_devices;
    u64 sectorsize;
};
struct btrfs_fs_devices;
struct btrfs_root {
    struct btrfs_root *root;
};
struct btrfs_device {
    u64 devid;
    unsigned long dev_state;
    struct block_device *bdev;
    char *name;
};
struct block_device {
    struct inode *bd_inode;
};
struct btrfs_trans_handle;
struct btrfs_ioctl_vol_args {
    char name[BTRFS_PATH_NAME_MAX + 1];
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define capable(x) 0
#define memdup_user(src, len) NULL
#define kfree(x) 
#define kstrtoull(s, base, res) 0
#define strchr(s, c) NULL
#define strcmp(s1, s2) 0
#define test_and_set_bit(nr, addr) 0
#define clear_bit(nr, addr) 
#define test_bit(nr, addr) 0
#define round_down(x, y) (x)
#define noinline __attribute__((noinline))
#define __user

static inline struct inode *file_inode(struct file *file) { return NULL; }
static inline struct btrfs_fs_info *btrfs_sb(struct super_block *sb) { return NULL; }
static inline struct btrfs_root *BTRFS_I(struct inode *inode) { return NULL; }
static inline int mnt_want_write_file(struct file *file) { return 0; }
static inline void mnt_drop_write_file(struct file *file) {}
static inline void btrfs_info(struct btrfs_fs_info *fs_info, const char *fmt, ...) {}
static inline struct btrfs_device *btrfs_find_device(struct btrfs_fs_devices *fs_devices, u64 devid, u8 *uuid, u8 *fsid, ...) { return NULL; }
static inline u64 memparse(const char *ptr, char **retptr) { return 0; }
static inline u64 btrfs_device_get_total_bytes(struct btrfs_device *device) { return 0; }
static inline void btrfs_info_in_rcu(struct btrfs_fs_info *fs_info, const char *fmt, ...) {}
static inline char *rcu_str_deref(char *str) { return str; }
static inline struct btrfs_trans_handle *btrfs_start_transaction(struct btrfs_root *root, int num_items) { return NULL; }
static inline int btrfs_grow_device(struct btrfs_trans_handle *trans, struct btrfs_device *device, u64 new_size) { return 0; }
static inline int btrfs_commit_transaction(struct btrfs_trans_handle *trans) { return 0; }
static inline int btrfs_shrink_device(struct btrfs_device *device, u64 new_size) { return 0; }