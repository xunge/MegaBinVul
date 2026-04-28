#include <stdint.h>
#include <string.h>
#include <errno.h>

typedef unsigned int ext4_group_t;
typedef uint64_t ext4_fsblk_t;

struct buffer_head {
    void *b_data;
    unsigned long b_state;
    void (*b_end_io)(struct buffer_head *bh);
};

struct super_block {
    unsigned long s_blocksize;
    void *s_fs_info;
};

struct ext4_super_block {
    uint32_t s_first_data_block;
    uint32_t s_inodes_per_group;
    uint64_t s_blocks_count;
};

struct ext4_group_desc {
    uint16_t bg_flags;
};

struct ext4_sb_info {
    struct ext4_super_block *s_es;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb)->s_fs_info)
#define EXT4_INODES_PER_GROUP(sb) (EXT4_SB(sb)->s_es->s_inodes_per_group)
#define EXT4_GROUP_INFO_IBITMAP_CORRUPT 1
#define EXT4_BG_INODE_UNINIT 0x0001

#define ERR_PTR(err) ((void *)(long)(err))
#define ENOMEM 12
#define EIO 5
#define EFSCORRUPTED 117

#define unlikely(x) (x)
#define le32_to_cpu(x) (x)
#define cpu_to_le16(x) (x)

static inline void lock_buffer(struct buffer_head *bh) {}
static inline void unlock_buffer(struct buffer_head *bh) {}
static inline int bitmap_uptodate(struct buffer_head *bh) { return 0; }
static inline void set_bitmap_uptodate(struct buffer_head *bh) {}
static inline int buffer_uptodate(struct buffer_head *bh) { return 0; }
static inline void set_buffer_uptodate(struct buffer_head *bh) {}
static inline void set_buffer_verified(struct buffer_head *bh) {}
static inline void get_bh(struct buffer_head *bh) {}
static inline void put_bh(struct buffer_head *bh) {}
static inline void wait_on_buffer(struct buffer_head *bh) {}

#define REQ_OP_READ 0
#define REQ_META (1 << 0)
#define REQ_PRIO (1 << 1)

static inline void submit_bh(int op, int flags, struct buffer_head *bh) {}
static inline void ext4_end_bitmap_read(struct buffer_head *bh) {}
static inline void ext4_error(struct super_block *sb, const char *fmt, ...) {}
static inline void ext4_mark_group_bitmap_corrupted(struct super_block *sb, ext4_group_t group, int flag) {}
static inline void ext4_lock_group(struct super_block *sb, ext4_group_t group) {}
static inline void ext4_unlock_group(struct super_block *sb, ext4_group_t group) {}
static inline void ext4_mark_bitmap_end(unsigned long inodes, unsigned long blocksize, void *data) {}
static inline int ext4_validate_inode_bitmap(struct super_block *sb, struct ext4_group_desc *desc, ext4_group_t block_group, struct buffer_head *bh) { return 0; }

static inline struct ext4_group_desc *ext4_get_group_desc(struct super_block *sb, ext4_group_t block_group, int *err) { return NULL; }
static inline ext4_fsblk_t ext4_inode_bitmap(struct super_block *sb, struct ext4_group_desc *desc) { return 0; }
static inline uint64_t ext4_blocks_count(struct ext4_super_block *es) { return 0; }
static inline struct buffer_head *sb_getblk(struct super_block *sb, ext4_fsblk_t block) { return NULL; }