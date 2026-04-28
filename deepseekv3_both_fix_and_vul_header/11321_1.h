#include <stdint.h>
#include <string.h>

typedef uint32_t __u32;
typedef uint64_t ext4_fsblk_t;
typedef unsigned int ext4_group_t;

struct buffer_head {
    unsigned long b_data;
    unsigned long b_size;
    int (*b_end_io)(struct buffer_head *bh, int uptodate);
    int b_uptodate;
};

struct super_block {
    void *s_fs_info;
};

struct inode {
    unsigned long i_ino;
    struct super_block *i_sb;
};

struct ext4_group_desc {
};

struct ext4_iloc {
    struct buffer_head *bh;
    ext4_group_t block_group;
    unsigned long offset;
};

struct ext4_super_block {
    __u32 s_inodes_count;
};

struct ext4_sb_info {
    struct ext4_super_block *s_es;
    unsigned int s_inodes_per_group;
    unsigned int s_inodes_per_block;
    unsigned int s_inode_size;
    __u32 s_inode_readahead_blks;
};

#define EXT4_ROOT_INO 2
#define EFSCORRUPTED 117
#define EIO 5
#define ENOMEM 12

#define le32_to_cpu(x) (x)
#define unlikely(x) (x)
#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb)->s_fs_info)
#define EXT4_INODES_PER_GROUP(sb) (EXT4_SB(sb)->s_inodes_per_group)
#define EXT4_INODE_SIZE(sb) (EXT4_SB(sb)->s_inode_size)
#define ext4_has_group_desc_csum(sb) (0)
#define ext4_itable_unused_count(sb, gdp) (0)

#define REQ_OP_READ 0
#define REQ_META (1 << 3)
#define REQ_PRIO (1 << 4)

static inline struct buffer_head *sb_getblk(struct super_block *sb, ext4_fsblk_t block) { return NULL; }
static inline int buffer_uptodate(struct buffer_head *bh) { return bh->b_uptodate; }
static inline void set_buffer_uptodate(struct buffer_head *bh) { bh->b_uptodate = 1; }
static inline int buffer_write_io_error(struct buffer_head *bh) { return 0; }
static inline void lock_buffer(struct buffer_head *bh) {}
static inline void unlock_buffer(struct buffer_head *bh) {}
static inline void brelse(struct buffer_head *bh) {}
static inline void get_bh(struct buffer_head *bh) {}
static inline void submit_bh(int op, int flags, struct buffer_head *bh) {}
static inline void wait_on_buffer(struct buffer_head *bh) {}
static inline void sb_breadahead(struct super_block *sb, ext4_fsblk_t block) {}
static inline struct ext4_group_desc *ext4_get_group_desc(struct super_block *sb,
                    ext4_group_t block_group, struct buffer_head **bh) { return NULL; }
static inline ext4_fsblk_t ext4_inode_table(struct super_block *sb,
                    struct ext4_group_desc *gdp) { return 0; }
static inline ext4_fsblk_t ext4_inode_bitmap(struct super_block *sb,
                    struct ext4_group_desc *gdp) { return 0; }
static inline int ext4_test_bit(int nr, void *addr) { return 0; }
static inline void trace_ext4_load_inode(struct inode *inode) {}
static inline int end_buffer_read_sync(struct buffer_head *bh, int uptodate) { return 0; }
#define EXT4_ERROR_INODE_BLOCK(inode, block, msg)