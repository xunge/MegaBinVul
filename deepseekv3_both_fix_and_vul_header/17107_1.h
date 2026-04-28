#include <stdint.h>

typedef uint32_t ext4_grpblk_t;
typedef uint64_t ext4_fsblk_t;
typedef uint32_t ext4_group_t;

struct super_block {
    unsigned long s_blocksize;
    void *s_fs_info;
};

struct buffer_head {
    unsigned char *b_data;
};

struct ext4_sb_info {
    unsigned int s_itb_per_group;
};

struct ext4_group_desc {
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb->s_fs_info))
#define EXT4_B2C(sbi, blk) ((blk) * 8)
#define ext4_has_feature_flex_bg(sb) (0)

static inline ext4_fsblk_t ext4_group_first_block_no(struct super_block *sb, ext4_group_t group) { return 0; }
static inline ext4_fsblk_t ext4_block_bitmap(struct super_block *sb, struct ext4_group_desc *desc) { return 0; }
static inline ext4_fsblk_t ext4_inode_bitmap(struct super_block *sb, struct ext4_group_desc *desc) { return 0; }
static inline ext4_fsblk_t ext4_inode_table(struct super_block *sb, struct ext4_group_desc *desc) { return 0; }
static inline int ext4_test_bit(int nr, void *addr) { return 0; }
static inline ext4_grpblk_t ext4_find_next_zero_bit(void *addr, ext4_grpblk_t size, ext4_grpblk_t offset) { return 0; }