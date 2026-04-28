#include <stddef.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

typedef int errcode_t;
typedef unsigned int dgrp_t;
typedef uint64_t blk64_t;
typedef uint32_t __u32;

#define EXT2_ET_MAGIC_EXT2FS_FILSYS 0
#define EXT2_ET_NO_MEMORY 0
#define EXT2_VALID_FS 0
#define EXT3_FEATURE_INCOMPAT_RECOVER 0
#define EXT3_FEATURE_INCOMPAT_JOURNAL_DEV 0
#define EXT2_FEATURE_INCOMPAT_META_BG 0
#define EXT2_FLAG_MASTER_SB_ONLY 0
#define EXT2_FLAG_SUPER_ONLY 0
#define EXT2_FLAG_DIRTY 0
#define EXT2_FLAG_FLUSH_NO_SYNC 0
#define WORDS_BIGENDIAN 0
#define SUPERBLOCK_SIZE 1024
#define SUPERBLOCK_OFFSET 1024
#define EXT2_DESC_PER_BLOCK(x) ((x)->s_blocksize / sizeof(struct ext2_group_desc))

struct ext2_super_block {
    __u32 s_state;
    __u32 s_feature_incompat;
    __u32 s_wtime;
    __u32 s_block_group_nr;
    __u32 s_first_meta_bg;
    __u32 s_blocksize;
};

struct ext2_group_desc {
};

struct ext2fs_numeric_progress_struct {
};

typedef struct ext2_filsys *ext2_filsys;

struct ext2_filsys {
    struct ext2_super_block *super;
    time_t now;
    unsigned long blocksize;
    unsigned long desc_blocks;
    unsigned long group_desc_count;
    unsigned long flags;
    void *group_desc;
    void *io;
    errcode_t (*write_bitmaps)(ext2_filsys);
};

#define EXT2_CHECK_MAGIC(x, y)

errcode_t ext2fs_get_mem(size_t size, void *ptr);
errcode_t ext2fs_get_array(size_t num, size_t size, void *ptr);
void ext2fs_swap_group_desc2(ext2_filsys fs, struct ext2_group_desc *gdp);
void ext2fs_swap_super(struct ext2_super_block *super);
void ext2fs_free_mem(void *ptr);
void ext2fs_numeric_progress_init(ext2_filsys fs, struct ext2fs_numeric_progress_struct *progress, void *arg, unsigned long max);
void ext2fs_numeric_progress_update(ext2_filsys fs, struct ext2fs_numeric_progress_struct *progress, unsigned long val);
void ext2fs_numeric_progress_close(ext2_filsys fs, struct ext2fs_numeric_progress_struct *progress, void *arg);
void ext2fs_super_and_bgd_loc2(ext2_filsys fs, dgrp_t group, blk64_t *super_blk, blk64_t *old_desc_blk, blk64_t *new_desc_blk, int flags);
errcode_t write_backup_super(ext2_filsys fs, dgrp_t group, blk64_t super_blk, struct ext2_super_block *super_shadow);
errcode_t io_channel_write_blk64(void *io, blk64_t block, int count, void *data);
errcode_t io_channel_flush(void *io);
errcode_t write_primary_superblock(ext2_filsys fs, struct ext2_super_block *super_shadow);
struct ext2_group_desc *ext2fs_group_desc(ext2_filsys fs, void *group_desc, dgrp_t group);