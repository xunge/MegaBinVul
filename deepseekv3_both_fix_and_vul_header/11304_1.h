#include <stddef.h>
#include <stdint.h>

typedef uint32_t ext4_group_t;
typedef uint16_t __le16;

struct super_block {
    void *s_fs_info;
};

struct ext4_sb_info {
    ext4_group_t s_groups_count;
};

struct ext4_group_desc {
    __le16 bg_flags;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb)->s_fs_info)
#define EXT4_BG_INODE_ZEROED 0x0001

static inline __le16 cpu_to_le16(uint16_t val) { return val; }
static inline struct ext4_group_desc *ext4_get_group_desc(struct super_block *sb, ext4_group_t group, void *ignored) { return NULL; }