#include <stdint.h>
#include <stdio.h>

#define F2FS_SUPER_MAGIC 0xF2F52010
#define F2FS_BLKSIZE 4096
#define PAGE_SIZE 4096
#define F2FS_MAX_LOG_SECTOR_SIZE 12
#define F2FS_MIN_LOG_SECTOR_SIZE 9
#define F2FS_MAX_SEGMENT 0x100000
#define F2FS_MIN_SEGMENTS 9
#define F2FS_MAX_EXTENSION 64
#define F2FS_CP_PACKS 2
#define F2FS_SUPER_OFFSET 1024
#define KERN_INFO 0

typedef uint32_t block_t;
typedef uint32_t __le32;

struct buffer_head {
    unsigned char *b_data;
};

struct super_block {
    int dummy;
};

struct f2fs_sb_info {
    struct super_block *sb;
};

struct f2fs_super_block {
    __le32 magic;
    __le32 log_blocksize;
    __le32 log_blocks_per_seg;
    __le32 log_sectorsize;
    __le32 log_sectors_per_block;
    __le32 segment_count;
    __le32 segs_per_sec;
    __le32 secs_per_zone;
    __le32 section_count;
    __le32 block_count;
    __le32 extension_count;
    uint8_t hot_ext_count;
    __le32 cp_payload;
    __le32 node_ino;
    __le32 meta_ino;
    __le32 root_ino;
};

static inline uint32_t le32_to_cpu(__le32 val) {
    return val;
}

static void f2fs_msg(struct super_block *sb, int level, const char *fmt, ...) {}