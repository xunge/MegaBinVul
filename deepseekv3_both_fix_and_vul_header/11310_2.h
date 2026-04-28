#include <stdint.h>
#include <stddef.h>

typedef uint32_t ext4_fsblk_t;
typedef uint32_t ext4_group_t;
typedef uint16_t __le16;
typedef uint32_t __le32;
typedef uint16_t __u16;

struct buffer_head {
    // Minimal definition to satisfy compiler
    unsigned long b_blocknr;
};

#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)
#define cpu_to_le16(x) (x)

struct ext4_super_block {
    __le32 s_first_data_block;
    __le32 s_blocks_count_lo;
};

struct ext4_group_desc {
    __le16 bg_flags;
    __le16 bg_checksum;
    __le32 bg_block_bitmap_lo;
    __le32 bg_inode_bitmap_lo;
    __le32 bg_inode_table_lo;
};

struct ext4_sb_info {
    struct ext4_super_block *s_es;
    unsigned long s_groups_count;
    unsigned int s_itb_per_group;
};

struct super_block {
    struct ext4_sb_info *s_fs_info;
    unsigned int s_flags;
    unsigned int s_blocksize_bits;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb)->s_fs_info)
#define EXT4_BLOCKS_PER_GROUP(sb) (1 << (sb)->s_blocksize_bits)
#define EXT4_BG_INODE_ZEROED 0x0001
#define KERN_ERR ""
#define MS_RDONLY 1
#define sb_rdonly(sb) ((sb)->s_flags & MS_RDONLY)

static inline ext4_fsblk_t ext4_block_bitmap(struct super_block *sb,
                        struct ext4_group_desc *bg)
{
    return le32_to_cpu(bg->bg_block_bitmap_lo);
}

static inline ext4_fsblk_t ext4_inode_bitmap(struct super_block *sb,
                        struct ext4_group_desc *bg)
{
    return le32_to_cpu(bg->bg_inode_bitmap_lo);
}

static inline ext4_fsblk_t ext4_inode_table(struct super_block *sb,
                       struct ext4_group_desc *bg)
{
    return le32_to_cpu(bg->bg_inode_table_lo);
}

static inline int ext4_has_feature_flex_bg(struct super_block *sb)
{
    return 0;
}

static inline ext4_fsblk_t ext4_blocks_count(struct ext4_super_block *es)
{
    return le32_to_cpu(es->s_blocks_count_lo);
}

static inline struct ext4_group_desc *ext4_get_group_desc(struct super_block *sb,
                            ext4_group_t block_group,
                            struct buffer_head **bh)
{
    return NULL;
}

static inline void ext4_lock_group(struct super_block *sb, ext4_group_t group)
{
}

static inline void ext4_unlock_group(struct super_block *sb, ext4_group_t group)
{
}

static inline int ext4_group_desc_csum_verify(struct super_block *sb,
                        ext4_group_t group,
                        struct ext4_group_desc *gdp)
{
    return 1;
}

static inline __u16 ext4_group_desc_csum(struct super_block *sb,
                    ext4_group_t group,
                    struct ext4_group_desc *gdp)
{
    return 0;
}

static inline void ext4_msg(struct super_block *sb, const char *prefix,
               const char *fmt, ...)
{
}

static inline void ext4_debug(const char *fmt, ...)
{
}