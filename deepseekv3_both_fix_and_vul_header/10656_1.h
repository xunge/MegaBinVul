#include <stdint.h>
#include <stddef.h>

#define EXT4_EXT_MAGIC 0xF30A
#define EXT2_BLOCK_SIZE(data) (1 << LOG2_EXT2_BLOCK_SIZE(data))

typedef uint32_t grub_uint32_t;
typedef uint64_t grub_disk_addr_t;

struct grub_ext2_data {
    void *disk;
};

struct grub_ext4_extent_header {
    uint16_t magic;
    uint16_t entries;
    uint16_t max;
    uint16_t depth;
};

struct grub_ext4_extent_idx {
    uint32_t block;
    uint32_t leaf;
    uint16_t leaf_hi;
    uint16_t unused;
};

typedef void *grub_properly_aligned_t;

static inline uint16_t grub_cpu_to_le16_compile_time(uint16_t x) { return x; }
static inline uint16_t grub_le_to_cpu16(uint16_t x) { return x; }
static inline uint32_t grub_le_to_cpu32(uint32_t x) { return x; }

extern void *grub_malloc(size_t size);
extern void grub_free(void *ptr);
extern int grub_disk_read(void *disk, uint64_t sector, unsigned offset, unsigned size, void *buf);

#define LOG2_EXT2_BLOCK_SIZE(data) (12)