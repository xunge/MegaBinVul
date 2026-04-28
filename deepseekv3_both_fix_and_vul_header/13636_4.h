#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define FMODE_READ 0x1
#define ENOENT 2
#define METADATA_UUID (1 << 0)

typedef uint64_t u64;
typedef uint8_t u8;

struct btrfs_device;
struct block_device;

struct buffer_head {
    void *b_data;
};

struct btrfs_dev_item {
    u64 devid;
    u8 uuid[16];
};

struct btrfs_super_block {
    struct btrfs_dev_item dev_item;
    u8 fsid[16];
    u8 metadata_uuid[16];
};

struct btrfs_fs_info {
    void *bdev_holder;
    struct btrfs_fs_devices *fs_devices;
};

struct btrfs_fs_devices;

static inline u64 btrfs_stack_device_id(struct btrfs_dev_item *dev_item) {
    return dev_item->devid;
}

#define ERR_PTR(err) ((void*)((long)(err)))

static int btrfs_get_bdev_and_sb(const char *path, int mode, void *holder, int flags,
                                struct block_device **bdev, struct buffer_head **bh) {
    return 0;
}

static int btrfs_fs_incompat(struct btrfs_fs_info *fs_info, int flag) {
    return 0;
}

static struct btrfs_device *btrfs_find_device(struct btrfs_fs_devices *fs_devices,
                                             u64 devid, u8 *uuid, u8 *fsid, ...) {
    return NULL;
}

static void brelse(struct buffer_head *bh) {}

static void blkdev_put(struct block_device *bdev, int mode) {}