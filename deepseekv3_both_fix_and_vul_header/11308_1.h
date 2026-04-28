#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define noinline_for_stack
#define BUG_ON(condition) do { if (condition) abort(); } while(0)
#define IS_ERR(ptr) ((uintptr_t)(ptr) > (uintptr_t)-1000L)
#define PTR_ERR(ptr) ((intptr_t)(ptr))
#define BUFFER_TRACE(bh, msg)
#define cpu_to_le16(x) (x)
#define EXT4_BG_BLOCK_UNINIT 0x0001
#define AGGRESSIVE_CHECK
#define AC_STATUS_FOUND 1
#define EXT4_MB_DELALLOC_RESERVED 0x0001
#define EIO 5
#define EFSCORRUPTED 117

typedef uint64_t ext4_fsblk_t;
typedef uint32_t ext4_group_t;
typedef uint16_t ext4_grpblk_t;
typedef uint16_t __le16;

struct buffer_head {
    void *b_data;
};

struct super_block {
    void *s_fs_info;
};

struct ext4_sb_info {
    unsigned long s_cluster_bits;
    unsigned long s_log_groups_per_flex;
    struct {
        int counter;
    } s_freeclusters_counter;
    struct {
        int counter;
    } s_dirtyclusters_counter;
    struct {
        struct {
            long counter;
        } free_clusters;
    } *s_flex_groups;
};

struct ext4_group_desc {
    __le16 bg_flags;
};

struct ext4_free_extent {
    ext4_group_t fe_group;
    ext4_grpblk_t fe_start;
    ext4_grpblk_t fe_len;
};

struct ext4_allocation_context {
    struct super_block *ac_sb;
    int ac_status;
    struct ext4_free_extent ac_b_ex;
    unsigned int ac_flags;
};

typedef struct {} handle_t;

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb)->s_fs_info)
#define EXT4_C2B(sbi, clusters) ((clusters) << (sbi)->s_cluster_bits)

static inline void ext4_lock_group(struct super_block *sb, ext4_group_t group) {}
static inline void ext4_unlock_group(struct super_block *sb, ext4_group_t group) {}
static inline void ext4_set_bits(void *addr, ext4_grpblk_t start, ext4_grpblk_t len) {}
static inline int mb_test_bit(ext4_grpblk_t bit, void *addr) { return 0; }
static inline void percpu_counter_sub(struct { int counter; } *counter, int amount) {}
static inline void atomic64_sub(long i, struct { long counter; } *v) {}
static inline void brelse(struct buffer_head *bh) {}

static inline ext4_fsblk_t ext4_grp_offs_to_block(struct super_block *sb,
                        struct ext4_free_extent *ex) { return 0; }
static inline int ext4_data_block_valid(struct ext4_sb_info *sbi,
                       ext4_fsblk_t blk, int len) { return 1; }
static inline void ext4_free_group_clusters_set(struct super_block *sb,
                       struct ext4_group_desc *gdp, int val) {}
static inline int ext4_free_group_clusters(struct super_block *sb,
                      struct ext4_group_desc *gdp) { return 0; }
static inline int ext4_free_clusters_after_init(struct super_block *sb,
                           ext4_group_t group,
                           struct ext4_group_desc *gdp) { return 0; }
static inline void ext4_block_bitmap_csum_set(struct super_block *sb,
                         ext4_group_t group,
                         struct ext4_group_desc *gdp,
                         struct buffer_head *bh) {}
static inline void ext4_group_desc_csum_set(struct super_block *sb,
                       ext4_group_t group,
                       struct ext4_group_desc *gdp) {}
static inline ext4_group_t ext4_flex_group(struct ext4_sb_info *sbi,
                      ext4_group_t group) { return 0; }
static inline struct buffer_head *ext4_read_block_bitmap(struct super_block *sb,
                            ext4_group_t group) { return NULL; }
static inline struct ext4_group_desc *ext4_get_group_desc(struct super_block *sb,
                             ext4_group_t group,
                             struct buffer_head **bh) { return NULL; }
static inline int ext4_journal_get_write_access(handle_t *handle,
                       struct buffer_head *bh) { return 0; }
static inline int ext4_handle_dirty_metadata(handle_t *handle,
                       void *inode,
                       struct buffer_head *bh) { return 0; }