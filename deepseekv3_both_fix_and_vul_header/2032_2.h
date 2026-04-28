#include <stdint.h>
#include <stdlib.h>
#include <stdatomic.h>

typedef uint32_t ext4_group_t;

struct super_block {
    void *s_fs_info;
    unsigned int s_blocksize_bits;
    unsigned int s_inode_size_bits;
};

struct ext4_super_block {
    uint16_t s_log_groups_per_flex;
    uint16_t s_reserved_gdt_blocks;
};

struct ext4_sb_info {
    uint16_t s_log_groups_per_flex;
    struct ext4_super_block *s_es;
    ext4_group_t s_groups_count;
    struct flex_groups *s_flex_groups;
};

struct ext4_group_desc {
    uint16_t bg_free_inodes_count;
    uint16_t bg_free_blocks_count;
    uint16_t bg_used_dirs_count;
};

struct flex_groups {
    atomic_int free_inodes;
    atomic_int free_clusters;
    atomic_int used_dirs;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb)->s_fs_info)
#define le16_to_cpu(x) (x)
#define EXT4_DESC_PER_BLOCK_BITS(sb) ((sb)->s_blocksize_bits + 3 - (sb)->s_inode_size_bits)
#define GFP_KERNEL 0
#define KERN_ERR 0

static inline void atomic_add(int i, atomic_int *v) {
    atomic_fetch_add(v, i);
}

static inline ext4_group_t ext4_flex_group(struct ext4_sb_info *sbi, ext4_group_t group) {
    return group >> sbi->s_log_groups_per_flex;
}

static inline int ext4_free_inodes_count(struct super_block *sb, struct ext4_group_desc *gdp) {
    return le16_to_cpu(gdp->bg_free_inodes_count);
}

static inline int ext4_free_group_clusters(struct super_block *sb, struct ext4_group_desc *gdp) {
    return le16_to_cpu(gdp->bg_free_blocks_count);
}

static inline int ext4_used_dirs_count(struct super_block *sb, struct ext4_group_desc *gdp) {
    return le16_to_cpu(gdp->bg_used_dirs_count);
}

static inline void *ext4_kvzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static inline struct ext4_group_desc *ext4_get_group_desc(struct super_block *sb, ext4_group_t block_group, void **bh) {
    return NULL;
}

static inline void ext4_msg(struct super_block *sb, const char *prefix, const char *fmt, ...) {}