#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

#define BTRFS_FSID_SIZE 16
#define BTRFS_UUID_SIZE 16

typedef uint64_t u64;
typedef uint8_t u8;

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member));})

struct btrfs_device {
    u64 devid;
    u8 uuid[BTRFS_UUID_SIZE];
    struct list_head dev_list;
};

struct btrfs_fs_devices {
    u8 metadata_uuid[BTRFS_FSID_SIZE];
    struct list_head devices;
    struct btrfs_fs_devices *seed;
};