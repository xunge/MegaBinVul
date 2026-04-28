#include <stdint.h>

#define EXT4_GOOD_OLD_INODE_SIZE 128
#define KERN_INFO 0

struct super_block;
struct ext4_sb_info {
    struct ext4_super_block *s_es;
    unsigned int s_inode_size;
    unsigned int s_want_extra_isize;
};
struct ext4_super_block {
    uint16_t s_want_extra_isize;
    uint16_t s_min_extra_isize;
};
struct ext4_inode {
    // inode fields would go here
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb))
static inline int ext4_has_feature_extra_isize(struct super_block *sb) { return 0; }
static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline void ext4_msg(struct super_block *sb, int level, const char *fmt, ...) {}