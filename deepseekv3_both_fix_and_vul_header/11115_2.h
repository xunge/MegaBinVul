#include <stdint.h>
#include <stddef.h>

#define F2FS_MIN_SEGMENTS 9
#define NR_CURSEG_NODE_TYPE 3
#define NR_CURSEG_DATA_TYPE 3
#define KERN_ERR ""

typedef uint32_t __le32;
typedef uint16_t __le16;
typedef uint64_t __le64;
typedef uint32_t __u32;
typedef uint16_t __u16;
typedef uint64_t __u64;
typedef uint64_t block_t;

struct super_block {
    void *dummy;
};

struct f2fs_sb_info {
    struct super_block *sb;
    void *raw_super;
    void *ckpt;
    unsigned int blocks_per_seg;
};

struct f2fs_super_block {
    __le32 segment_count;
    __le32 segment_count_ckpt;
    __le32 segment_count_sit;
    __le32 segment_count_nat;
    __le32 segment_count_ssa;
    __le32 segment_count_main;
    __le32 log_blocks_per_seg;
};

struct f2fs_checkpoint {
    __le32 rsvd_segment_count;
    __le32 overprov_segment_count;
    __le64 user_block_count;
    __le32 cur_node_segno[NR_CURSEG_NODE_TYPE];
    __le16 cur_node_blkoff[NR_CURSEG_NODE_TYPE];
    __le32 cur_data_segno[NR_CURSEG_DATA_TYPE];
    __le16 cur_data_blkoff[NR_CURSEG_DATA_TYPE];
    __le32 sit_ver_bitmap_bytesize;
    __le32 nat_ver_bitmap_bytesize;
};

#define F2FS_RAW_SUPER(sbi) ((struct f2fs_super_block *)((sbi)->raw_super))
#define F2FS_CKPT(sbi) ((struct f2fs_checkpoint *)((sbi)->ckpt))

static inline __u32 le32_to_cpu(__le32 val) { return val; }
static inline __u16 le16_to_cpu(__le16 val) { return val; }
static inline __u64 le64_to_cpu(__le64 val) { return val; }
#define unlikely(x) (x)

int f2fs_msg(struct super_block *sb, const char *level, const char *fmt, ...);
int f2fs_cp_error(struct f2fs_sb_info *sbi);