#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef uint64_t u64;

struct btrfs_fs_info {
    struct btrfs_fs_devices *fs_devices;
};

struct btrfs_device {
    struct scrub_ctx *scrub_ctx;
};

struct btrfs_scrub_progress {
    char data[64];
};

struct scrub_ctx {
    struct btrfs_scrub_progress stat;
};

struct btrfs_fs_devices {
    int device_list_mutex;
};

#define ENOTCONN 107
#define ENODEV 19

static inline void mutex_lock(int *mutex) { (void)mutex; }
static inline void mutex_unlock(int *mutex) { (void)mutex; }
static inline struct btrfs_device *btrfs_find_device(struct btrfs_fs_devices *fs_devices,
                                                   u64 devid, void *a, void *b, ...)
{
    (void)fs_devices; (void)devid; (void)a; (void)b;
    return 0;
}