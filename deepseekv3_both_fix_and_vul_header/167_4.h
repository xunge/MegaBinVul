#include <stdint.h>
#include <string.h>

typedef uint64_t ext4_fsblk_t;
typedef uint32_t __le32;
typedef uint16_t __le16;

struct ext4_extent_header {
    __le16 eh_magic;
    __le16 eh_entries;
    __le16 eh_max;
    __le16 eh_depth;
};

struct ext4_extent_idx {
    __le32 ei_block;
    __le32 ei_leaf_lo;
    __le16 ei_leaf_hi;
    __le16 ei_unused;
};

struct ext4_extent {
    __le32 ee_block;
    __le16 ee_len;
    __le16 ee_start_hi;
    __le32 ee_start_lo;
};

struct ext4_super_block {
    __le32 s_first_data_block;
    void *s_es;
};

struct ext4_sb_info {
    struct ext4_super_block *s_es;
};

struct inode {
    struct super_block *i_sb;
    void *i_data;
};

struct super_block {
    unsigned long s_blocksize;
    struct ext4_sb_info *s_fs_info;
};

struct buffer_head {
    char *b_data;
    void *b_state;
};

typedef struct handle_t handle_t;

#define EXT4_EXT_MAGIC 0xF30A
#define EXT4_MB_HINT_TRY_GOAL 0x01
#define GFP_NOFS 0
#define __GFP_MOVABLE 0
#define ENOMEM 12

#define EXT4_SB(sb) ((sb)->s_fs_info)
#define EXT4_I(inode) ((struct inode *)(inode))
#define EXT_FIRST_INDEX(hdr) ((struct ext4_extent_idx *)((hdr) + 1))
#define EXT_FIRST_EXTENT(hdr) ((struct ext4_extent *)((hdr) + 1))
#define ext_inode_hdr(inode) ((struct ext4_extent_header *)EXT4_I(inode)->i_data)
#define ext_block_hdr(bh) ((struct ext4_extent_header *)(bh)->b_data)

static inline int ext_depth(struct inode *inode) { return 0; }
static inline ext4_fsblk_t ext4_idx_pblock(struct ext4_extent_idx *ix) { return 0; }
static inline ext4_fsblk_t ext4_inode_to_goal_block(struct inode *inode) { return 0; }
static inline ext4_fsblk_t ext4_new_meta_blocks(handle_t *handle, struct inode *inode,
                       ext4_fsblk_t goal, unsigned int flags,
                       unsigned long *count, int *errp) { return 0; }
static inline struct buffer_head *sb_getblk_gfp(struct super_block *sb, ext4_fsblk_t block, int gfp) { return NULL; }
static inline void lock_buffer(struct buffer_head *bh) {}
static inline int ext4_journal_get_create_access(handle_t *handle, struct buffer_head *bh) { return 0; }
static inline void unlock_buffer(struct buffer_head *bh) {}
static inline void ext4_extent_block_csum_set(struct inode *inode, struct ext4_extent_header *eh) {}
static inline void set_buffer_uptodate(struct buffer_head *bh) {}
static inline int ext4_handle_dirty_metadata(handle_t *handle, struct inode *inode,
                       struct buffer_head *bh) { return 0; }
static inline void ext4_idx_store_pblock(struct ext4_extent_idx *ix, ext4_fsblk_t block) {}
static inline void ext4_mark_inode_dirty(handle_t *handle, struct inode *inode) {}
static inline void brelse(struct buffer_head *bh) {}
static inline unsigned short ext4_ext_space_block(struct inode *inode, int num) { return 0; }
static inline unsigned short ext4_ext_space_block_idx(struct inode *inode, int num) { return 0; }
static inline unsigned short ext4_ext_space_root_idx(struct inode *inode, int num) { return 0; }
static inline void ext_debug(const char *fmt, ...) {}
static inline void le16_add_cpu(__le16 *var, int val) {}

#define unlikely(x) (x)
#define le32_to_cpu(x) (x)
#define le16_to_cpu(x) (x)
#define cpu_to_le16(x) (x)
#define cpu_to_le32(x) (x)