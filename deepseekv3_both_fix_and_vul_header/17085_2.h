#include <stdlib.h>
#include <stdint.h>

#define F2FS_RAW_SUPER(sbi) ((struct f2fs_super_block *)((sbi)->raw_super))
#define F2FS_CKPT(sbi) ((struct f2fs_checkpoint *)((sbi)->ckpt))

#define GFP_KERNEL 0
#define ENOMEM 12

#define DEF_RECLAIM_PREFREE_SEGMENTS 5
#define DEF_MAX_RECLAIM_PREFREE_SEGMENTS 16
#define DEF_MIN_IPU_UTIL 10
#define DEF_MIN_FSYNC_BLOCKS 8
#define DEF_MIN_HOT_BLOCKS 16
#define DEF_BATCHED_TRIM_SECTIONS 32

#define F2FS_IPU_FSYNC 0
#define LFS 0
#define FLUSH_MERGE 0

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct f2fs_sb_info {
    struct f2fs_super_block *raw_super;
    struct f2fs_checkpoint *ckpt;
    struct f2fs_sm_info *sm_info;
    struct super_block *sb;
};

struct f2fs_super_block {
    uint32_t segment0_blkaddr;
    uint32_t main_blkaddr;
    uint32_t segment_count;
    uint32_t segment_count_main;
    uint32_t ssa_blkaddr;
};

struct f2fs_checkpoint {
    uint32_t rsvd_segment_count;
    uint32_t overprov_segment_count;
};

struct f2fs_sm_info {
    uint32_t seg0_blkaddr;
    uint32_t main_blkaddr;
    uint32_t segment_count;
    uint32_t reserved_segments;
    uint32_t ovp_segments;
    uint32_t main_segments;
    uint32_t ssa_blkaddr;
    uint32_t rec_prefree_segments;
    uint32_t ipu_policy;
    uint32_t min_ipu_util;
    uint32_t min_fsync_blocks;
    uint32_t min_hot_blocks;
    uint32_t trim_sections;
    struct list_head sit_entry_set;
};

static inline uint32_t le32_to_cpu(uint32_t val) { return val; }
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

int test_opt(struct f2fs_sb_info *sbi, int opt);
int f2fs_readonly(struct super_block *sb);
int create_flush_cmd_control(struct f2fs_sb_info *sbi);
int create_discard_cmd_control(struct f2fs_sb_info *sbi);
int build_sit_info(struct f2fs_sb_info *sbi);
int build_free_segmap(struct f2fs_sb_info *sbi);
int build_curseg(struct f2fs_sb_info *sbi);
void build_sit_entries(struct f2fs_sb_info *sbi);
void init_free_segmap(struct f2fs_sb_info *sbi);
int build_dirty_segmap(struct f2fs_sb_info *sbi);
void init_min_max_mtime(struct f2fs_sb_info *sbi);