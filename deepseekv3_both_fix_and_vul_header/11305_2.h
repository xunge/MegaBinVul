#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef uint32_t ext4_group_t;
typedef uint64_t ext4_fsblk_t;

struct buffer_head {
    unsigned long b_state;
    void *b_data;
    void (*b_end_io)(struct buffer_head *bh, int uptodate);
};

struct super_block {
    void *s_fs_info;
};

struct ext4_super_block {
    uint32_t s_first_data_block;
    uint64_t s_blocks_count;
};

struct ext4_group_desc {
    uint16_t bg_flags;
};

struct ext4_sb_info {
    struct ext4_super_block *s_es;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb->s_fs_info))
#define EXT4_BG_BLOCK_UNINIT 0x0001
#define EXT4_GROUP_INFO_BBITMAP_CORRUPT 0x0001

#define EFSCORRUPTED EUCLEAN
#define ENOMEM 12

#define ERR_PTR(err) ((void *)((long)(err)))
#define unlikely(x) (x)

#define BH_BitmapUptodate 0
#define BH_Verified 1

#define REQ_OP_READ 0
#define REQ_META (1 << 0)
#define REQ_PRIO (1 << 1)

#define set_bit(nr, addr) ((*(addr)) |= (1UL << (nr)))
#define test_bit(nr, addr) ((*(addr)) & (1UL << (nr)))

#define set_bitmap_uptodate(bh) set_bit(BH_BitmapUptodate, &(bh)->b_state)
#define bitmap_uptodate(bh) test_bit(BH_BitmapUptodate, &(bh)->b_state)
#define set_buffer_verified(bh) set_bit(BH_Verified, &(bh)->b_state)
#define set_buffer_uptodate(bh) do {} while (0)
#define buffer_uptodate(bh) (1)
#define set_buffer_new(bh) do {} while (0)

static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline uint16_t cpu_to_le16(uint16_t x) { return x; }

void lock_buffer(struct buffer_head *bh) {}
void unlock_buffer(struct buffer_head *bh) {}
void get_bh(struct buffer_head *bh) {}
void put_bh(struct buffer_head *bh) {}

struct ext4_group_desc *ext4_get_group_desc(struct super_block *sb, ext4_group_t block_group, void *null) { return NULL; }
ext4_fsblk_t ext4_block_bitmap(struct super_block *sb, struct ext4_group_desc *desc) { return 0; }
uint64_t ext4_blocks_count(struct ext4_super_block *es) { return 0; }
void ext4_error(struct super_block *sb, const char *fmt, ...) {}
void ext4_mark_group_bitmap_corrupted(struct super_block *sb, ext4_group_t group, int flags) {}
struct buffer_head *sb_getblk(struct super_block *sb, ext4_fsblk_t block) { return NULL; }
void ext4_lock_group(struct super_block *sb, ext4_group_t group) {}
int ext4_init_block_bitmap(struct super_block *sb, struct buffer_head *bh, ext4_group_t group, struct ext4_group_desc *desc) { return 0; }
void ext4_unlock_group(struct super_block *sb, ext4_group_t group) {}
void trace_ext4_read_block_bitmap_load(struct super_block *sb, ext4_group_t group) {}
void ext4_end_bitmap_read(struct buffer_head *bh, int uptodate) {}
void submit_bh(int op, int flags, struct buffer_head *bh) {}
int ext4_validate_block_bitmap(struct super_block *sb, struct ext4_group_desc *desc, ext4_group_t block_group, struct buffer_head *bh) { return 0; }