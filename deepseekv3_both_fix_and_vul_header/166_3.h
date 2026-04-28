#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t ext4_fsblk_t;
typedef uint32_t __le32;
typedef uint16_t __le16;

struct buffer_head {
    void *b_data;
};

struct super_block {
    unsigned long s_blocksize;
};

struct inode {
    struct super_block *i_sb;
};

typedef struct {} handle_t;

struct ext4_extent_header {
    __le16  eh_magic;
    __le16  eh_entries;
    __le16  eh_max;
    __le16  eh_depth;
};

struct ext4_extent {
    __le32  ee_block;
    __le16  ee_len;
    __le16  ee_start_hi;
    __le32  ee_start_lo;
};

struct ext4_extent_idx {
    __le32  ei_block;
    __le32  ei_leaf_lo;
    __le16  ei_leaf_hi;
    uint16_t ei_unused;
};

struct ext4_ext_path {
    struct ext4_extent_header *p_hdr;
    struct ext4_extent        *p_ext;
    struct ext4_extent_idx    *p_idx;
    struct buffer_head        *p_bh;
};

#define EXT4_EXT_MAGIC      0xf30a
#define EXT_MAX_EXTENT(hdr) ((struct ext4_extent *)((char *)(hdr) + sizeof(struct ext4_extent_header)))
#define EXT_FIRST_EXTENT(hdr) ((struct ext4_extent *)((char *)(hdr) + sizeof(struct ext4_extent_header)))
#define EXT_MAX_INDEX(hdr) ((struct ext4_extent_idx *)((char *)(hdr) + sizeof(struct ext4_extent_header)))
#define EXT_FIRST_INDEX(hdr) ((struct ext4_extent_idx *)((char *)(hdr) + sizeof(struct ext4_extent_header)))
#define EXT_LAST_INDEX(hdr) (EXT_FIRST_INDEX(hdr) + (hdr)->eh_entries - 1)

#define GFP_NOFS    0
#define __GFP_MOVABLE 0

#define EXT4_ERROR_INODE(inode, fmt, ...)
#define ext_debug(fmt, ...)
#define ext4_ext_show_move(inode, path, newblock, depth)
#define ext4_ext_new_meta_block(handle, inode, path, newext, err, flags) 0
#define ext4_ext_get_access(handle, inode, path) 0
#define ext4_ext_dirty(handle, inode, path) 0
#define ext4_ext_insert_index(handle, inode, path, border, newblock) 0
#define ext4_ext_space_block(inode, flags) 0
#define ext4_ext_space_block_idx(inode, flags) 0
#define ext4_extent_block_csum_set(inode, eh)
#define ext4_handle_dirty_metadata(handle, inode, bh) 0
#define ext4_journal_get_create_access(handle, bh) 0
#define ext4_free_blocks(handle, inode, bh, block, count, flags)

#define EFSCORRUPTED 1
#define ENOMEM 2

#define unlikely(x) (x)

static inline int ext_depth(struct inode *inode) { return 0; }
static inline struct ext4_extent_header *ext_block_hdr(struct buffer_head *bh) { return NULL; }
static inline void ext4_idx_store_pblock(struct ext4_extent_idx *ix, ext4_fsblk_t pb) {}
static inline void *kcalloc(size_t n, size_t size, int flags) { return calloc(n, size); }
static inline void kfree(const void *objp) { free((void *)objp); }
static inline struct buffer_head *sb_getblk_gfp(struct super_block *sb, ext4_fsblk_t block, int gfp) { return malloc(sizeof(struct buffer_head)); }
static inline struct buffer_head *sb_getblk(struct super_block *sb, ext4_fsblk_t block) { return malloc(sizeof(struct buffer_head)); }
static inline void lock_buffer(struct buffer_head *bh) {}
static inline void unlock_buffer(struct buffer_head *bh) {}
static inline void set_buffer_uptodate(struct buffer_head *bh) {}
static inline void brelse(struct buffer_head *bh) { free(bh); }
static inline int buffer_locked(struct buffer_head *bh) { return 0; }
static inline uint16_t le16_to_cpu(__le16 val) { return val; }
static inline __le16 cpu_to_le16(uint16_t val) { return val; }
static inline uint32_t le32_to_cpu(__le32 val) { return val; }
static inline void le16_add_cpu(__le16 *p, int val) { *p += val; }