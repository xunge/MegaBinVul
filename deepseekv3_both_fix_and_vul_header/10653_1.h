#include <stdint.h>

#define EXT4_EXT_MAGIC 0xF30A
#define LOG2_EXT2_BLOCK_SIZE(data) ((data)->log2_blksz)

typedef uint16_t grub_uint16_t;
typedef uint32_t grub_uint32_t;
typedef uint64_t grub_disk_addr_t;

struct grub_disk;
typedef struct grub_disk *grub_disk_t;

struct grub_ext2_data {
    grub_disk_t disk;
    int log2_blksz;
};

struct grub_ext4_extent_header {
    grub_uint16_t magic;
    grub_uint16_t entries;
    grub_uint16_t max;
    grub_uint16_t depth;
};

struct grub_ext4_extent_idx {
    grub_uint32_t block;
    grub_uint32_t leaf;
    grub_uint16_t leaf_hi;
    grub_uint16_t unused;
};

static inline uint16_t grub_le_to_cpu16(uint16_t x) { return x; }
static inline uint32_t grub_le_to_cpu32(uint32_t x) { return x; }
static int grub_disk_read(grub_disk_t disk, grub_disk_addr_t sector,
                          grub_disk_addr_t offset, grub_disk_addr_t size,
                          void *buf) { return 0; }