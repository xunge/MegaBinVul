#include <stdint.h>
#include <stddef.h>

#define F2FS_SUPER_MAGIC 0xF2F52010
#define F2FS_BLKSIZE 4096
#define F2FS_MAX_LOG_SECTOR_SIZE 12
#define F2FS_MIN_LOG_SECTOR_SIZE 9
#define F2FS_MAX_SEGMENT 1024
#define F2FS_SUPER_OFFSET 1024
#define PAGE_SIZE 4096
#define KERN_INFO 0

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
    __le32 node_ino;
    __le32 meta_ino;
    __le32 root_ino;
    __le32 segment_count;
};

static inline uint32_t le32_to_cpu(__le32 val) {
    return val;
}

static inline int sanity_check_area_boundary(struct f2fs_sb_info *sbi, struct buffer_head *bh) {
    return 0;
}

static inline void f2fs_msg(struct super_block *sb, int level, const char *fmt, ...) {}