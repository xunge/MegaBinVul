#include <string.h>

typedef unsigned int ext4_group_t;
typedef unsigned long long ext4_fsblk_t;

struct super_block {
    unsigned int s_blocksize;
    void *s_fs_info;
};

struct buffer_head {
    void *b_data;
    unsigned int b_size;
    int b_state;
};

struct ext4_sb_info {
    unsigned int s_itb_per_group;
    unsigned int s_cluster_bits;
};

struct ext4_group_desc {
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb)->s_fs_info)
#define J_ASSERT_BH(bh, cond) 
#define EXT4_B2C(sbi, blk) ((blk) >> (sbi)->s_cluster_bits)
#define EXT4_GROUP_INFO_BBITMAP_CORRUPT 1
#define EXT4_GROUP_INFO_IBITMAP_CORRUPT 2
#define EFSBADCRC 1
#define EFSCORRUPTED 2

static inline int buffer_locked(struct buffer_head *bh) { return bh->b_state & 1; }
static inline int ext4_group_desc_csum_verify(struct super_block *sb, ext4_group_t group, struct ext4_group_desc *gdp) { return 0; }
static inline void ext4_mark_group_bitmap_corrupted(struct super_block *sb, ext4_group_t group, unsigned int flags) {}
static inline unsigned int ext4_num_base_meta_clusters(struct super_block *sb, ext4_group_t block_group) { return 0; }
static inline ext4_fsblk_t ext4_group_first_block_no(struct super_block *sb, ext4_group_t block_group) { return 0; }
static inline int ext4_has_feature_flex_bg(struct super_block *sb) { return 0; }
static inline ext4_fsblk_t ext4_block_bitmap(struct super_block *sb, struct ext4_group_desc *gdp) { return 0; }
static inline int ext4_block_in_group(struct super_block *sb, ext4_fsblk_t block, ext4_group_t block_group) { return 0; }
static inline ext4_fsblk_t ext4_inode_bitmap(struct super_block *sb, struct ext4_group_desc *gdp) { return 0; }
static inline ext4_fsblk_t ext4_inode_table(struct super_block *sb, struct ext4_group_desc *gdp) { return 0; }
static inline void ext4_set_bit(unsigned int nr, void *addr) {}
static inline unsigned int num_clusters_in_group(struct super_block *sb, ext4_group_t block_group) { return 0; }
static inline void ext4_mark_bitmap_end(unsigned int start_bit, unsigned int end_bit, void *bitmap) {}