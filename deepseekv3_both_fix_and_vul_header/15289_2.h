#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t ext4_group_t;

struct super_block {
    void *s_fs_info;
};

struct ext4_super_block {
    uint32_t s_log_groups_per_flex;
    uint16_t s_reserved_gdt_blocks;
};

struct ext4_sb_info {
    struct ext4_super_block *s_es;
    uint32_t s_log_groups_per_flex;
    ext4_group_t s_groups_count;
    struct flex_groups *s_flex_groups;
};

struct ext4_group_desc {
    uint16_t bg_free_inodes_count;
    uint16_t bg_free_blocks_count;
    uint16_t bg_used_dirs_count;
};

struct flex_groups {
    int free_inodes;
    int free_blocks;
    int used_dirs;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb->s_fs_info))
#define GFP_KERNEL 0
#define KERN_ERR 0
#define le16_to_cpu(x) (x)
#define EXT4_DESC_PER_BLOCK_BITS(sb) (0)

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void *vmalloc(size_t size) { return malloc(size); }
static inline void ext4_msg(struct super_block *sb, int level, const char *fmt, ...) {}
static inline ext4_group_t ext4_flex_group(struct ext4_sb_info *sbi, int i) { return 0; }
static inline struct ext4_group_desc *ext4_get_group_desc(struct super_block *sb, ext4_group_t group, int *err) { return NULL; }
static inline int ext4_free_inodes_count(struct super_block *sb, struct ext4_group_desc *gdp) { return gdp->bg_free_inodes_count; }
static inline int ext4_free_blks_count(struct super_block *sb, struct ext4_group_desc *gdp) { return gdp->bg_free_blocks_count; }
static inline int ext4_used_dirs_count(struct super_block *sb, struct ext4_group_desc *gdp) { return gdp->bg_used_dirs_count; }
static inline void atomic_add(int i, int *v) { *v += i; }