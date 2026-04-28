#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define BTRFS_DEV_STAT_VALUES_MAX 64
#define BTRFS_DEV_STATS_RESET (1 << 0)
#define ENODEV 19

typedef uint8_t u8;

struct mutex {
    int dummy;
};

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}

struct btrfs_device {
    bool dev_stats_valid;
    unsigned long devid;
};

struct btrfs_fs_devices {
    struct mutex device_list_mutex;
    struct btrfs_device *devices;
};

struct btrfs_fs_info {
    struct btrfs_fs_devices *fs_devices;
};

struct btrfs_ioctl_get_dev_stats {
    unsigned long devid;
    unsigned long nr_items;
    unsigned long values[BTRFS_DEV_STAT_VALUES_MAX];
    unsigned int flags;
};

int btrfs_dev_stat_read(struct btrfs_device *dev, int index);
int btrfs_dev_stat_read_and_reset(struct btrfs_device *dev, int index);
void btrfs_dev_stat_reset(struct btrfs_device *dev, int index);
void btrfs_warn(struct btrfs_fs_info *fs_info, const char *fmt, ...);
struct btrfs_device *btrfs_find_device(struct btrfs_fs_devices *fs_devices,
                    unsigned long devid, const u8 *uuid, const u8 *fsid,
                    ...);