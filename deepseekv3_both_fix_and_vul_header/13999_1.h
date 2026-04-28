#include <stdint.h>
#include <endian.h>

#define F2FS_MIN_SEGMENTS 9
#define NR_CURSEG_NODE_TYPE 3
#define NR_CURSEG_DATA_TYPE 3
#define KERN_ERR 1

struct super_block {
    void *s_fs_info;
};

struct f2fs_sb_info {
    struct super_block *sb;
    unsigned int blocks_per_seg;
};

struct f2fs_super_block {
    uint32_t segment_count;
    uint32_t segment_count_ckpt;
    uint32_t segment_count_sit;
    uint32_t segment_count_nat;
    uint32_t segment_count_ssa;
    uint32_t segment_count_main;
};

struct f2fs_checkpoint {
    uint32_t rsvd_segment_count;
    uint32_t overprov_segment_count;
    uint32_t cur_node_segno[NR_CURSEG_NODE_TYPE];
    uint16_t cur_node_blkoff[NR_CURSEG_NODE_TYPE];
    uint32_t cur_data_segno[NR_CURSEG_DATA_TYPE];
    uint16_t cur_data_blkoff[NR_CURSEG_DATA_TYPE];
};

#define F2FS_RAW_SUPER(sbi) ((struct f2fs_super_block *)(sbi)->sb->s_fs_info)
#define F2FS_CKPT(sbi) ((struct f2fs_checkpoint *)((char *)(sbi)->sb->s_fs_info + sizeof(struct f2fs_super_block)))

#define unlikely(x) (x)
#define le32_to_cpu(x) le32toh(x)
#define le16_to_cpu(x) le16toh(x)

int f2fs_cp_error(struct f2fs_sb_info *sbi);
void f2fs_msg(struct super_block *sb, int level, const char *fmt, ...);