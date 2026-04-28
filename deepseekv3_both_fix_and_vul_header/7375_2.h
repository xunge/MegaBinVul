#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

typedef uint64_t u64;

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define ENOENT 2
#define ETXTBSY 26

#define BTRFS_ERROR_DEV_MISSING_NOT_FOUND (-1)
#define BTRFS_ERROR_DEV_TGT_REPLACE (-2)
#define BTRFS_ERROR_DEV_ONLY_WRITABLE (-3)

#define BTRFS_DEV_STATE_WRITEABLE (0)
#define BTRFS_DEV_STATE_REPLACE_TGT (1)
#define BTRFS_DEV_STATE_IN_FS_METADATA (2)
#define BTRFS_DEV_STATE_MISSING (3)

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int dummy;
};

struct rcu_string {
    char str[1];
};

struct block_device {
    int dummy;
};

struct super_block {
    int dummy;
};

struct btrfs_device;
struct btrfs_fs_devices;
struct btrfs_fs_info;

struct btrfs_device {
    struct list_head dev_list;
    struct list_head dev_alloc_list;
    unsigned long dev_state;
    u64 devid;
    struct block_device *bdev;
    struct rcu_string *name;
    struct btrfs_fs_devices *fs_devices;
};

struct btrfs_fs_devices {
    struct list_head seed_list;
    struct list_head alloc_list;
    int rw_devices;
    int open_devices;
    int missing_devices;
    int num_devices;
    int total_devices;
    struct mutex device_list_mutex;
};

struct btrfs_fs_info {
    struct btrfs_fs_devices *fs_devices;
    struct mutex chunk_mutex;
    struct super_block *super_copy;
};

extern struct mutex uuid_mutex;

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline void list_del_init(struct list_head *entry) {}
static inline void list_del_rcu(struct list_head *entry) {}
static inline void list_add(struct list_head *new, struct list_head *head) {}
static inline char *rcu_str_deref(struct rcu_string *str) { return str->str; }
static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }
static inline void clear_bit(int nr, volatile unsigned long *addr) {}
static inline void synchronize_rcu(void) {}

static inline int btrfs_num_devices(struct btrfs_fs_info *fs_info) { return 0; }
static inline int btrfs_check_raid_min_devices(struct btrfs_fs_info *fs_info, u64 num) { return 0; }
static inline struct btrfs_device *btrfs_find_device_by_devspec(struct btrfs_fs_info *fs_info, u64 devid, const char *path) { return NULL; }
static inline int btrfs_pinned_by_swapfile(struct btrfs_fs_info *fs_info, struct btrfs_device *device) { return 0; }
static inline void btrfs_warn_in_rcu(struct btrfs_fs_info *fs_info, const char *fmt, ...) {}
static inline int btrfs_shrink_device(struct btrfs_device *device, u64 new_size) { return 0; }
static inline void btrfs_reada_remove_dev(struct btrfs_device *device) {}
static inline int btrfs_rm_dev_item(struct btrfs_device *device) { return 0; }
static inline void btrfs_scrub_cancel_dev(struct btrfs_device *device) {}
static inline void btrfs_assign_next_active_device(struct btrfs_device *device, struct btrfs_device *next) {}
static inline void btrfs_sysfs_remove_device(struct btrfs_device *device) {}
static inline u64 btrfs_super_num_devices(struct super_block *sb) { return 0; }
static inline void btrfs_set_super_num_devices(struct super_block *sb, u64 num) {}
static inline void btrfs_scratch_superblocks(struct btrfs_fs_info *fs_info, struct block_device *bdev, const char *name) {}
static inline void btrfs_close_bdev(struct btrfs_device *device) {}
static inline void btrfs_free_device(struct btrfs_device *device) {}
static inline void close_fs_devices(struct btrfs_fs_devices *fs_devices) {}
static inline void free_fs_devices(struct btrfs_fs_devices *fs_devices) {}
static inline void btrfs_reada_undo_remove_dev(struct btrfs_device *device) {}