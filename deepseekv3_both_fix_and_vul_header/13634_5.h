#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint64_t u64;

struct extent_map_tree {
    int lock;
};

struct btrfs_fs_info {
    struct {
        struct extent_map_tree map_tree;
    } mapping_tree;
    struct btrfs_fs_devices *fs_devices;
};

struct extent_map {
    u64 start;
    u64 len;
    struct map_lookup *map_lookup;
};

struct map_lookup {
    u64 type;
    int num_stripes;
    int verified_stripes;
    struct {
        struct btrfs_device *dev;
        u64 physical;
    } stripes[];
};

struct btrfs_device {
    u64 devid;
    u64 disk_total_bytes;
};

struct btrfs_fs_devices {
    struct btrfs_fs_devices *seed;
};

#define EUCLEAN 117

static inline void read_lock(int *lock) {}
static inline void read_unlock(int *lock) {}
static inline struct extent_map *lookup_extent_mapping(struct extent_map_tree *tree, u64 start, int len) { return NULL; }
static inline void btrfs_err(struct btrfs_fs_info *fs_info, const char *fmt, ...) {}
static inline u64 calc_stripe_length(u64 type, u64 len, int num_stripes) { return 0; }
static inline struct btrfs_device *btrfs_find_device(struct btrfs_fs_devices *fs_devices, u64 devid, void *a, void *b, ...) { return NULL; }
static inline struct btrfs_device *find_device(struct btrfs_fs_devices *fs_devices, u64 devid, void *a) { return NULL; }
static inline void free_extent_map(struct extent_map *em) {}