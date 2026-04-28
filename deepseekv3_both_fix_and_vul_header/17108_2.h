#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint32_t __le32;
typedef uint16_t __le16;
typedef uint64_t u64;
typedef unsigned int ext4_group_t;
typedef u64 ext4_fsblk_t;

struct buffer_head {
    unsigned long b_state;
    void (*b_end_io)(struct buffer_head *bh, int uptodate);
    int b_count;
};

struct super_block {
    void *s_fs_info;
};

struct ext4_super_block {
    __le32 s_first_data_block;
};

struct ext4_group_desc {
    __le16 bg_flags;
};

struct ext4_sb_info {
    struct ext4_super_block *s_es;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb)->s_fs_info)
#define EXT4_BG_BLOCK_UNINIT 0x0001
#define REQ_OP_READ 0
#define REQ_META (1 << 0)
#define REQ_PRIO (1 << 1)

#define ERR_PTR(error) ((void *)(intptr_t)(error))
#define PTR_ERR(ptr) ((long)(intptr_t)(ptr))
#define IS_ERR(ptr) ((uintptr_t)(ptr) > (uintptr_t)-1000L)

#define EFSCORRUPTED 117
#define ENOMEM 12

#define le32_to_cpu(x) (x)
#define cpu_to_le16(x) (x)

#define unlikely(x) (x)

#define set_bitmap_uptodate(bh) do { } while (0)
#define set_buffer_uptodate(bh) do { } while (0)
#define set_buffer_verified(bh) do { } while (0)
#define set_buffer_new(bh) do { } while (0)
#define lock_buffer(bh) do { } while (0)
#define unlock_buffer(bh) do { } while (0)
#define get_bh(bh) do { (bh)->b_count++; } while (0)
#define put_bh(bh) do { (bh)->b_count--; } while (0)

static inline struct ext4_group_desc *ext4_get_group_desc(struct super_block *sb,
                                ext4_group_t block_group,
                                struct buffer_head **bh) { return NULL; }
static inline ext4_fsblk_t ext4_block_bitmap(struct super_block *sb,
                        struct ext4_group_desc *desc) { return 0; }
static inline ext4_fsblk_t ext4_blocks_count(struct ext4_super_block *es) { return 0; }
static inline void ext4_error(struct super_block *sb, const char *fmt, ...) { }
static inline struct buffer_head *sb_getblk(struct super_block *sb, ext4_fsblk_t block) { return NULL; }
static inline bool bitmap_uptodate(struct buffer_head *bh) { return false; }
static inline void ext4_lock_group(struct super_block *sb, ext4_group_t group) { }
static inline void ext4_unlock_group(struct super_block *sb, ext4_group_t group) { }
static inline int ext4_init_block_bitmap(struct super_block *sb, struct buffer_head *bh,
                    ext4_group_t group, struct ext4_group_desc *desc) { return 0; }
static inline bool buffer_uptodate(struct buffer_head *bh) { return false; }
static inline void submit_bh(int op, int op_flags, struct buffer_head *bh) { }
static inline void trace_ext4_read_block_bitmap_load(struct super_block *sb, ext4_group_t group) { }
static inline void ext4_end_bitmap_read(struct buffer_head *bh, int uptodate) { }
static inline int ext4_validate_block_bitmap(struct super_block *sb,
                        struct ext4_group_desc *desc,
                        ext4_group_t block_group,
                        struct buffer_head *bh) { return 0; }