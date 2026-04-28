#include <stdint.h>
#include <stddef.h>

typedef uint64_t ext4_fsblk_t;
typedef uint32_t ext4_group_t;

struct super_block {
    void *s_fs_info;
    unsigned long s_blocks_per_group;
    unsigned long s_feature_incompat;
    int s_rdonly;
};

struct ext4_sb_info {
    struct ext4_super_block *s_es;
    ext4_group_t s_groups_count;
    unsigned int s_itb_per_group;
};

struct ext4_super_block {
    uint32_t s_first_data_block;
    uint32_t s_blocks_count_lo;
};

struct ext4_group_desc {
    uint32_t bg_block_bitmap_lo;
    uint32_t bg_inode_bitmap_lo;
    uint32_t bg_inode_table_lo;
    uint16_t bg_flags;
    uint16_t bg_checksum;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb)->s_fs_info)
#define EXT4_BLOCKS_PER_GROUP(sb) ((sb)->s_blocks_per_group)
#define EXT4_FEATURE_INCOMPAT_FLEX_BG 0x0200
#define EXT4_BG_INODE_ZEROED 0x0001
#define KERN_ERR ""

static inline int ext4_has_feature_flex_bg(struct super_block *sb)
{
    return (sb->s_feature_incompat & EXT4_FEATURE_INCOMPAT_FLEX_BG) != 0;
}

static inline ext4_fsblk_t ext4_block_bitmap(struct super_block *sb,
                    struct ext4_group_desc *bg)
{
    return bg->bg_block_bitmap_lo;
}

static inline ext4_fsblk_t ext4_inode_bitmap(struct super_block *sb,
                    struct ext4_group_desc *bg)
{
    return bg->bg_inode_bitmap_lo;
}

static inline ext4_fsblk_t ext4_inode_table(struct super_block *sb,
                       struct ext4_group_desc *bg)
{
    return bg->bg_inode_table_lo;
}

static inline ext4_fsblk_t ext4_blocks_count(struct ext4_super_block *es)
{
    return es->s_blocks_count_lo;
}

static inline struct ext4_group_desc *ext4_get_group_desc(struct super_block *sb,
                            ext4_group_t block_group,
                            void **bh)
{
    return NULL;
}

static inline void ext4_lock_group(struct super_block *sb, ext4_group_t group) {}
static inline void ext4_unlock_group(struct super_block *sb, ext4_group_t group) {}

static inline int ext4_group_desc_csum_verify(struct super_block *sb,
                        ext4_group_t group,
                        struct ext4_group_desc *gdp)
{
    return 1;
}

static inline uint16_t ext4_group_desc_csum(struct super_block *sb,
                      ext4_group_t group,
                      struct ext4_group_desc *gdp)
{
    return 0;
}

static inline int sb_rdonly(struct super_block *sb)
{
    return sb->s_rdonly;
}

static inline void ext4_msg(struct super_block *sb, const char *prefix,
               const char *fmt, ...) {}

static inline void ext4_debug(const char *fmt, ...) {}