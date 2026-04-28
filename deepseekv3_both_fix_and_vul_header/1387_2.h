#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t __le32;
typedef uint64_t ext4_fsblk_t;
typedef unsigned int gfp_t;

#define GFP_NOFS 0
#define __GFP_NOFAIL 0
#define __GFP_MOVABLE 0
#define EXT4_FREE_BLOCKS_METADATA 0
#define EXT4_EX_NOFAIL 0
#define EFSCORRUPTED 0
#define ENOMEM 0
#define EXT4_EXT_MAGIC 0

#define likely(x) (x)
#define unlikely(x) (x)

struct super_block {
    unsigned long s_blocksize;
};

struct inode {
    struct super_block *i_sb;
};

struct buffer_head {
    void *b_data;
    unsigned long b_state;
};

struct ext4_extent {
    __le32 ee_block;
};

struct ext4_extent_header {
    __le32 eh_magic;
    __le32 eh_entries;
    __le32 eh_max;
    __le32 eh_depth;
    __le32 eh_generation;
};

struct ext4_extent_idx {
    __le32 ei_block;
    ext4_fsblk_t ei_leaf;
};

struct ext4_ext_path {
    struct ext4_extent_header *p_hdr;
    struct ext4_extent *p_ext;
    struct ext4_extent_idx *p_idx;
};

typedef void *handle_t;

#define EXT_MAX_EXTENT(p) ((struct ext4_extent *)((p) + 1))
#define EXT_FIRST_EXTENT(p) ((struct ext4_extent *)((p) + 1))
#define EXT_FIRST_INDEX(p) ((struct ext4_extent_idx *)((p) + 1))
#define EXT_MAX_INDEX(p) ((struct ext4_extent_idx *)((p) + 1))
#define EXT_LAST_INDEX(p) ((struct ext4_extent_idx *)((p) + 1))
#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)
#define cpu_to_le16(x) (x)
#define le16_add_cpu(p, val) do { *(p) += (val); } while (0)

static inline int buffer_locked(struct buffer_head *bh) { return 0; }
static inline void *kcalloc(size_t n, size_t size, gfp_t flags) { return calloc(n, size); }
static inline void kfree(void *p) { free(p); }
static inline void *sb_getblk_gfp(void *sb, ext4_fsblk_t block, gfp_t gfp) { return NULL; }
static inline void *sb_getblk(void *sb, ext4_fsblk_t block) { return NULL; }
static inline void lock_buffer(struct buffer_head *bh) {}
static inline void unlock_buffer(struct buffer_head *bh) {}
static inline void brelse(struct buffer_head *bh) {}
static inline int ext_depth(struct inode *inode) { return 0; }
static inline ext4_fsblk_t ext4_ext_new_meta_block(handle_t *handle, struct inode *inode, 
    struct ext4_ext_path *path, struct ext4_extent *newext, int *err, unsigned int flags) { return 0; }
static inline int ext4_journal_get_create_access(handle_t *handle, struct buffer_head *bh) { return 0; }
static inline int ext4_handle_dirty_metadata(handle_t *handle, struct inode *inode, struct buffer_head *bh) { return 0; }
static inline int ext4_ext_get_access(handle_t *handle, struct inode *inode, struct ext4_ext_path *path) { return 0; }
static inline int ext4_ext_dirty(handle_t *handle, struct inode *inode, struct ext4_ext_path *path) { return 0; }
static inline int ext4_ext_insert_index(handle_t *handle, struct inode *inode, 
    struct ext4_ext_path *path, __le32 border, ext4_fsblk_t newblock) { return 0; }
static inline void ext4_free_blocks(handle_t *handle, struct inode *inode, 
    void *where, ext4_fsblk_t block, int count, int flags) {}
static inline void ext4_extent_block_csum_set(struct inode *inode, struct ext4_extent_header *eh) {}
static inline void set_buffer_uptodate(struct buffer_head *bh) {}
static inline void ext_debug(struct inode *inode, const char *fmt, ...) {}
static inline void ext4_ext_show_move(struct inode *inode, struct ext4_ext_path *path, ext4_fsblk_t newblock, int depth) {}
static inline void EXT4_ERROR_INODE(struct inode *inode, const char *fmt, ...) {}
static inline int ext4_ext_space_block(struct inode *inode, int check) { return 0; }
static inline int ext4_ext_space_block_idx(struct inode *inode, int check) { return 0; }
static inline struct ext4_extent_header *ext_block_hdr(struct buffer_head *bh) { return NULL; }
static inline void ext4_idx_store_pblock(struct ext4_extent_idx *ix, ext4_fsblk_t pb) {}