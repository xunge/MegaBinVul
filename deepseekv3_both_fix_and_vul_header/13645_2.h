#include <stdint.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <string.h>

#define BTRFS_STRIPE_LEN 65536
#define SCRUB_MAX_PAGES_PER_BLOCK 16
#define PAGE_SIZE 4096

#define EINVAL 22
#define ENODEV 19
#define EROFS 30
#define EIO 5
#define EINPROGRESS 115

typedef uint64_t u64;

struct btrfs_scrub_progress {
    int dummy;
};

struct btrfs_fs_info;
struct btrfs_device;
struct scrub_ctx;

enum {
    BTRFS_DEV_STATE_MISSING,
    BTRFS_DEV_STATE_WRITEABLE,
    BTRFS_DEV_STATE_IN_FS_METADATA,
    BTRFS_DEV_STATE_REPLACE_TGT
};

struct mutex {
    int dummy;
};

struct rw_semaphore {
    int dummy;
};

struct wait_queue_head {
    int dummy;
};

struct btrfs_fs_devices {
    struct mutex device_list_mutex;
};

struct btrfs_dev_replace {
    struct rw_semaphore rwsem;
};

struct btrfs_fs_info {
    int nodesize;
    int sectorsize;
    struct btrfs_fs_devices *fs_devices;
    struct btrfs_dev_replace dev_replace;
    struct mutex scrub_lock;
    atomic_int scrubs_running;
    struct wait_queue_head scrub_pause_wait;
    bool closing;
};

struct btrfs_device {
    u64 devid;
    struct scrub_ctx *scrub_ctx;
    unsigned long dev_state;
    char *name;
};

struct scrub_ctx {
    int readonly;
    struct btrfs_scrub_progress stat;
    struct wait_queue_head list_wait;
    atomic_int bios_in_flight;
    atomic_int workers_pending;
};

#define IS_ERR(x) ((x) == NULL)
#define PTR_ERR(x) (-1)