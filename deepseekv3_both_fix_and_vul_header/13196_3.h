#include <stddef.h>

#define TRANS_STATE_COMMIT_DOING 0
#define BTRFS_FS_QUOTA_ENABLED 0
#define BTRFS_QGROUP_STATUS_FLAG_ON (1 << 0)

struct list_head {
    struct list_head *next, *prev;
};

struct btrfs_trans_handle {
    struct btrfs_fs_info *fs_info;
    struct {
        int state;
    } *transaction;
};

struct btrfs_fs_info {
    struct list_head dirty_qgroups;
    void *quota_root;
    unsigned long flags;
    unsigned long qgroup_flags;
    struct list_head qgroup_lock;
    struct list_head qgroup_ioctl_lock;
};

struct btrfs_qgroup {
    struct list_head dirty;
};

static inline void spin_lock(struct list_head *lock) {}
static inline void spin_unlock(struct list_head *lock) {}
static inline int list_empty(const struct list_head *head) { return 0; }
#define list_first_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
static inline void list_del_init(struct list_head *entry) {}
static inline int test_bit(int nr, const unsigned long *addr) { return 0; }
static inline void lockdep_assert_held(struct list_head *lock) {}

extern int update_qgroup_info_item(struct btrfs_trans_handle *trans, struct btrfs_qgroup *qgroup);
extern int update_qgroup_limit_item(struct btrfs_trans_handle *trans, struct btrfs_qgroup *qgroup);
extern void qgroup_mark_inconsistent(struct btrfs_fs_info *fs_info);
extern int update_qgroup_status_item(struct btrfs_trans_handle *trans);