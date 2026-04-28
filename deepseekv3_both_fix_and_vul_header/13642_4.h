#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

struct btrfs_fs_info {
    struct btrfs_fs_devices *fs_devices;
};

struct btrfs_device {
    unsigned long long devid;
    unsigned char uuid[16];
    char *name;
};

struct btrfs_ioctl_dev_info_args {
    unsigned long long devid;
    unsigned long long bytes_used;
    unsigned long long total_bytes;
    unsigned char uuid[16];
    char path[1024];
};

struct btrfs_fs_devices;

#define __user
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)
#define rcu_read_lock()
#define rcu_read_unlock()
#define rcu_str_deref(x) (x)
#define kfree(x) free(x)

static inline void *memdup_user(const void *src, size_t len) { return NULL; }
static inline int copy_to_user(void *dst, const void *src, size_t len) { return 0; }
static inline bool btrfs_is_empty_uuid(const unsigned char *uuid) { return false; }
static inline struct btrfs_device *btrfs_find_device(struct btrfs_fs_devices *fs_devices,
                            unsigned long long devid, const unsigned char *uuid,
                            const unsigned char *fsid, ...) { return NULL; }
static inline unsigned long long btrfs_device_get_bytes_used(struct btrfs_device *dev) { return 0; }
static inline unsigned long long btrfs_device_get_total_bytes(struct btrfs_device *dev) { return 0; }