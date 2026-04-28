#include <stdint.h>
#include <stddef.h>

struct rb_node {
    struct rb_node *rb_node;
};

struct super_block {
    void *s_fs_info;
};

struct ext4_sb_info {
    struct rb_node system_blks;
    int s_itb_per_group;
    struct ext4_super_block *s_es;
};

struct ext4_group_desc;
struct ext4_super_block {
    uint32_t s_journal_inum;
};

typedef uint32_t ext4_group_t;

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb->s_fs_info))
#define test_opt(sb, opt) (0)
#define BLOCK_VALIDITY (0)
#define DEBUG (0)

static inline ext4_group_t ext4_get_groups_count(struct super_block *sb) { return 0; }
static inline int ext4_flex_bg_size(struct ext4_sb_info *sbi) { return 0; }
static inline void ext4_release_system_zone(struct super_block *sb) {}
static inline int ext4_bg_has_super(struct super_block *sb, ext4_group_t group) { return 0; }
static inline uint64_t ext4_group_first_block_no(struct super_block *sb, ext4_group_t group) { return 0; }
static inline int ext4_bg_num_gdb(struct super_block *sb, ext4_group_t group) { return 0; }
static inline struct ext4_group_desc *ext4_get_group_desc(struct super_block *sb, ext4_group_t block_group, void *bh) { return NULL; }
static inline uint64_t ext4_block_bitmap(struct super_block *sb, struct ext4_group_desc *gdp) { return 0; }
static inline uint64_t ext4_inode_bitmap(struct super_block *sb, struct ext4_group_desc *gdp) { return 0; }
static inline uint64_t ext4_inode_table(struct super_block *sb, struct ext4_group_desc *gdp) { return 0; }
static inline int ext4_has_feature_journal(struct super_block *sb) { return 0; }
static inline int ext4_protect_reserved_inode(struct super_block *sb, uint32_t ino) { return 0; }
static inline uint32_t le32_to_cpu(uint32_t val) { return val; }
static inline void debug_print_tree(struct ext4_sb_info *sbi) {}
static inline int add_system_zone(struct ext4_sb_info *sbi, uint64_t start_blk, unsigned int count) { return 0; }