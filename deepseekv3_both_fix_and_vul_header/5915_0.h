#include <stdint.h>

#define EXT_MAX_BLOCKS ((ext4_lblk_t)~0)
#define EXT_MAX_BLOCK EXT_MAX_BLOCKS

typedef uint32_t ext4_lblk_t;

struct inode;
struct ext4_extent {
    uint32_t ee_block;
    uint16_t ee_len;
};
struct ext4_ext_path {
    struct ext4_extent *p_ext;
};

static inline ext4_lblk_t le32_to_cpu(uint32_t x) { return x; }
static inline uint16_t cpu_to_le16(uint16_t x) { return x; }
static inline unsigned int ext4_ext_get_actual_len(struct ext4_extent *ext) { return ext->ee_len; }
static inline unsigned int ext_depth(struct inode *inode) { return 0; }
static inline ext4_lblk_t ext4_ext_next_allocated_block(struct ext4_ext_path *path) { return 0; }