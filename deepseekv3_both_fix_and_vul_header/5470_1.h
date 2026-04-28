#include <stddef.h>
#include <time.h>
#include <string.h>

typedef int errcode_t;
typedef unsigned int dgrp_t;
typedef unsigned long long blk64_t;
typedef unsigned int __u32;

#define EXT2_ET_MAGIC_EXT2FS_FILSYS 0
#define EXT2_ET_NO_MEMORY 0
#define SUPERBLOCK_SIZE 1024
#define EXT2_VALID_FS 0x0001
#define EXT3_FEATURE_INCOMPAT_RECOVER 0x0004
#define EXT3_FEATURE_INCOMPAT_JOURNAL_DEV 0x0008
#define EXT2_FEATURE_INCOMPAT_META_BG 0x0010
#define EXT2_FLAG_MASTER_SB_ONLY 0x0001
#define EXT2_FLAG_SUPER_ONLY 0x0002
#define EXT2_FLAG_DIRTY 0x0004
#define EXT2_FLAG_FLUSH_NO_SYNC 0x0008
#define WORDS_BIGENDIAN 0
#define EXT2_DESC_PER_BLOCK(s) (1)

struct ext2_super_block {
    unsigned long s_state;
    __u32 s_feature_incompat;
    unsigned long s_wtime;
    unsigned int s_block_group_nr;
    unsigned int s_first_meta_bg;
};

struct ext2_group_desc {
};

struct ext2fs_numeric_progress_struct {
};

typedef struct ext2_filsys {
    struct ext2_super_block *super;
    struct ext2_group_desc *group_desc;
    unsigned long now;
    unsigned long flags;
    unsigned long blocksize;
    unsigned long desc_blocks;
    unsigned long group_desc_count;
    void *io;
    errcode_t (*write_bitmaps)(struct ext2_filsys *);
} *ext2_filsys;

#define EXT2_CHECK_MAGIC(a, b)

static errcode_t ext2fs_get_mem(size_t size, void *ptr) { return 0; }
static errcode_t ext2fs_get_array(size_t count, size_t size, void *ptr) { return 0; }
static errcode_t ext2fs_free_mem(void *ptr) { return 0; }
static struct ext2_group_desc *ext2fs_group_desc(ext2_filsys fs, void *gd, dgrp_t group) { return NULL; }
static void ext2fs_swap_group_desc2(ext2_filsys fs, struct ext2_group_desc *gdp) {}
static void ext2fs_swap_super(struct ext2_super_block *super) {}
static errcode_t write_backup_super(ext2_filsys fs, dgrp_t group, blk64_t blk, struct ext2_super_block *super) { return 0; }
static errcode_t io_channel_write_blk64(void *io, blk64_t blk, int count, char *buf) { return 0; }
static errcode_t io_channel_flush(void *io) { return 0; }
static errcode_t write_primary_superblock(ext2_filsys fs, struct ext2_super_block *super) { return 0; }
static void ext2fs_numeric_progress_init(ext2_filsys fs, struct ext2fs_numeric_progress_struct *progress, void *arg, int max) {}
static void ext2fs_numeric_progress_update(ext2_filsys fs, struct ext2fs_numeric_progress_struct *progress, int val) {}
static void ext2fs_numeric_progress_close(ext2_filsys fs, struct ext2fs_numeric_progress_struct *progress, void *arg) {}
static void ext2fs_super_and_bgd_loc2(ext2_filsys fs, dgrp_t group, blk64_t *super_blk, blk64_t *old_desc_blk, blk64_t *new_desc_blk, int flags) {}