#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef uint32_t ext4_lblk_t;
#define EXT_MAX_BLOCKS ((ext4_lblk_t)~0)
#define EXT_MAX_BLOCK EXT_MAX_BLOCKS
#define BUG_ON(cond) assert(!(cond))

struct inode;
struct ext4_ext_path {
    int p_depth;
    struct ext4_extent_header *p_hdr;
    struct ext4_extent_idx *p_idx;
};

struct ext4_extent_header {
    uint16_t eh_entries;
    uint16_t eh_max;
    uint16_t eh_depth;
    uint16_t eh_magic;
};

struct ext4_extent_idx {
    uint32_t ei_block;
    uint32_t ei_leaf_lo;
    uint16_t ei_leaf_hi;
    uint16_t ei_unused;
};

#define EXT_LAST_INDEX(hdr) \
    ((struct ext4_extent_idx *)(((char *)((hdr) + 1) + \
    ((hdr)->eh_entries) * sizeof(struct ext4_extent_idx))))

static inline uint32_t le32_to_cpu(uint32_t x) {
    return x;
}