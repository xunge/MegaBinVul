#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

typedef int errcode_t;
typedef uint32_t __u32;
typedef uint16_t __u16;
typedef uint64_t blk64_t;
typedef unsigned int dgrp_t;

#define EXT2_ET_MAGIC_IO_MANAGER 0x1234
#define EXT2_ET_MAGIC_EXT2FS_FILSYS 0x5678
#define EXT2_ET_MAGIC_E2IMAGE 0x9ABC
#define EXT2_SUPER_MAGIC 0xEF53
#define EXT2_LIB_CURRENT_REV 1
#define EXT2_MIN_BLOCK_LOG_SIZE 10
#define EXT2_MAX_BLOCK_LOG_SIZE 16
#define EXT2_GOOD_OLD_INODE_SIZE 128
#define SUPERBLOCK_SIZE 1024
#define SUPERBLOCK_OFFSET 1024
#define WORDS_BIGENDIAN 0

#define EXT2_ET_INVALID_ARGUMENT 1
#define EXT2_ET_BAD_MAGIC 2
#define EXT2_ET_REV_TOO_HIGH 3
#define EXT2_ET_UNSUPP_FEATURE 4
#define EXT2_ET_RO_UNSUPP_FEATURE 5
#define EXT2_ET_CORRUPT_SUPERBLOCK 6
#define EXT2_ET_CANT_USE_LEGACY_BITMAPS 7
#define EXT2_ET_UNEXPECTED_BLOCK_SIZE 8
#define EXT2_ET_UNIMPLEMENTED 9

#define EXT2_FLAG_RW 0x01
#define EXT2_FLAG_EXCLUSIVE 0x02
#define EXT2_FLAG_DIRECT_IO 0x04
#define EXT2_FLAG_MASTER_SB_ONLY 0x08
#define EXT2_FLAG_IMAGE_FILE 0x10
#define EXT2_FLAG_SWAP_BYTES 0x20
#define EXT2_FLAG_FORCE 0x40
#define EXT2_FLAG_SOFTSUPP_FEATURES 0x80
#define EXT2_FLAG_JOURNAL_DEV_OK 0x100
#define EXT2_FLAG_64BITS 0x200
#define EXT2_FLAG_NOFREE_ON_ERROR 0x400
#define EXT2_FLAG_SKIP_MMP 0x800

#define EXT2_LIB_FEATURE_INCOMPAT_SUPP 0
#define EXT2_LIB_FEATURE_RO_COMPAT_SUPP 0
#define EXT2_FEATURE_INCOMPAT_META_BG 0x10
#define EXT3_FEATURE_INCOMPAT_JOURNAL_DEV 0x08
#define EXT4_FEATURE_RO_COMPAT_BIGALLOC 0x20
#define EXT4_FEATURE_RO_COMPAT_GDT_CSUM 0x40
#define EXT4_FEATURE_INCOMPAT_MMP 0x100

#define IO_FLAG_RW 0x01
#define IO_FLAG_EXCLUSIVE 0x02
#define IO_FLAG_DIRECT_IO 0x04

#define EXT2_BG_BLOCK_UNINIT 0x0001
#define EXT2_BG_INODE_UNINIT 0x0002

struct ext2_super_block {
    __u32 s_magic;
    __u32 s_rev_level;
    __u32 s_feature_incompat;
    __u32 s_feature_ro_compat;
    __u32 s_first_data_block;
    __u32 s_log_block_size;
    __u32 s_log_cluster_size;
    __u32 s_blocks_count;
    __u32 s_inodes_count;
    __u32 s_first_meta_bg;
    __u32 s_raid_stride;
    __u32 s_inode_size;
    __u32 s_inodes_per_group;
    __u32 s_blocks_per_group;
    __u32 s_clusters_per_group;
    __u32 s_desc_per_block;
};

struct ext2_group_desc {
    __u32 bg_block_bitmap;
    __u32 bg_inode_bitmap;
    __u32 bg_inode_table;
    __u16 bg_free_blocks_count;
    __u16 bg_free_inodes_count;
    __u16 bg_used_dirs_count;
    __u16 bg_flags;
    __u32 bg_reserved[2];
};

struct ext2_image_hdr {
    __u32 magic_number;
    __u32 fs_blocksize;
};

struct io_channel {
    void *app_data;
    errcode_t (*open)(const char *, int, struct io_channel **);
    errcode_t (*set_options)(struct io_channel *, const char *);
    errcode_t (*read_blk)(struct io_channel *, blk64_t, int, void *);
    errcode_t (*read_blk64)(struct io_channel *, blk64_t, int, void *);
    errcode_t (*set_blksize)(struct io_channel *, int);
    errcode_t (*alloc_buf)(struct io_channel *, int, void **);
};

typedef struct io_channel *io_manager;

struct struct_ext2_filsys {
    __u32 magic;
    int flags;
    int umask;
    char *device_name;
    struct io_channel *io;
    struct io_channel *image_io;
    struct ext2_super_block *super;
    struct ext2_super_block *orig_super;
    struct ext2_image_hdr *image_header;
    void *group_desc;
    __u32 blocksize;
    __u32 fragsize;
    __u32 cluster_ratio_bits;
    __u32 inode_blocks_per_group;
    __u32 group_desc_count;
    __u32 desc_blocks;
    __u32 stride;
};

typedef struct struct_ext2_filsys *ext2_filsys;

#define EXT2_CHECK_MAGIC(ptr, magic) do { } while(0)
#define EXT2_HAS_RO_COMPAT_FEATURE(sb, mask) ((sb)->s_feature_ro_compat & (mask))
#define EXT2_INODE_SIZE(sb) ((sb)->s_inode_size)
#define EXT2_BLOCK_SIZE(sb) (1 << ((sb)->s_log_block_size + 10))
#define EXT2_INODES_PER_GROUP(sb) ((sb)->s_inodes_per_group)
#define EXT2_BLOCKS_PER_GROUP(sb) ((sb)->s_blocks_per_group)
#define EXT2_CLUSTERS_PER_GROUP(sb) ((sb)->s_clusters_per_group)
#define EXT2_DESC_PER_BLOCK(sb) ((sb)->s_desc_per_block)
#define EXT2_MAX_BLOCKS_PER_GROUP(sb) ((sb)->s_blocks_per_group)
#define EXT2_MAX_INODES_PER_GROUP(sb) ((sb)->s_inodes_per_group)

extern errcode_t ext2fs_get_mem(size_t size, void *ptr);
extern errcode_t ext2fs_free(void *ptr);
extern errcode_t ext2fs_get_array(size_t num, size_t size, void *ptr);
extern uint64_t ext2fs_div64_ceil(uint64_t a, uint32_t b);
extern uint32_t ext2fs_div_ceil(uint32_t a, uint32_t b);
extern errcode_t ext2fs_swap_super(struct ext2_super_block *sb);
extern errcode_t ext2fs_swap_group_desc2(ext2_filsys fs, struct ext2_group_desc *gdp);
extern errcode_t ext2fs_group_desc_csum_set(ext2_filsys fs, dgrp_t group);
extern errcode_t ext2fs_mark_super_dirty(ext2_filsys fs);
extern errcode_t ext2fs_mmp_start(ext2_filsys fs);
extern errcode_t ext2fs_mmp_stop(ext2_filsys fs);
extern errcode_t io_channel_set_options(struct io_channel *io, const char *options);
extern errcode_t io_channel_read_blk(struct io_channel *io, blk64_t block, int count, void *data);
extern errcode_t io_channel_read_blk64(struct io_channel *io, blk64_t block, int count, void *data);
extern errcode_t io_channel_set_blksize(struct io_channel *io, int blksize);
extern errcode_t io_channel_alloc_buf(struct io_channel *io, int count, void **buf);
extern errcode_t ext2fs_bg_flags_clear(ext2_filsys fs, dgrp_t group, __u16 flags);
extern errcode_t ext2fs_bg_itable_unused_set(ext2_filsys fs, dgrp_t group, __u16 unused);
extern struct ext2_group_desc *ext2fs_group_desc(ext2_filsys fs, void *group_desc, dgrp_t group);
extern blk64_t ext2fs_descriptor_block_loc2(ext2_filsys fs, blk64_t group_block, dgrp_t group);
extern uint64_t ext2fs_blocks_count(struct ext2_super_block *sb);