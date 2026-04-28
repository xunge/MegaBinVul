#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define BUG_ON(condition) do { if (condition) abort(); } while (0)
#define EXT_MAX_BLOCKS ((ext4_lblk_t)0xFFFFFFFF)
#define EXT_MAX_BLOCK ((ext4_lblk_t)0xFFFFFFFF)

typedef uint32_t ext4_lblk_t;

struct ext4_extent {
    uint32_t ee_block;
};

struct ext4_extent_idx {
    uint32_t ei_block;
};

struct ext4_extent_header {
};

struct ext4_ext_path {
    int p_depth;
    struct ext4_extent *p_ext;
    struct ext4_extent_idx *p_idx;
    struct ext4_extent_header *p_hdr;
};

#define EXT_LAST_EXTENT(hdr) ((struct ext4_extent *)((hdr) + 1))
#define EXT_LAST_INDEX(hdr) ((struct ext4_extent_idx *)((hdr) + 1))

static inline uint32_t le32_to_cpu(uint32_t x) {
    return x;
}