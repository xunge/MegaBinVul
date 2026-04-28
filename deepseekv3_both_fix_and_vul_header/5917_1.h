#include <stddef.h>
#include <string.h>

typedef unsigned int ext4_lblk_t;
typedef unsigned long long ext4_fsblk_t;

#define EXT_MAX_BLOCKS 0xffffffff
#define EXT_MAX_BLOCK 0xffffffff
#define EIO 5
#define EXT4_ERROR_INODE(inode, fmt, ...) 
#define EXT4_GET_BLOCKS_PUNCH_OUT_EXT 0
#define EXT4_GET_BLOCKS_PRE_IO 0
#define EXT4_MAXQUOTAS_TRANS_BLOCKS(sb) 0
#define EXT4_BLOCKS_PER_GROUP(sb) 0

struct inode {
    struct super_block *i_sb;
};

struct super_block;
struct buffer_head;

typedef struct handle_t {
    int h_transaction;
} handle_t;

struct ext4_extent {
    ext4_lblk_t ee_block;
    unsigned short ee_len;
    ext4_fsblk_t ee_start_hi;
    ext4_fsblk_t ee_start_lo;
};

struct ext4_extent_header {
    unsigned short eh_entries;
    unsigned short eh_max;
    unsigned short eh_magic;
    unsigned short eh_depth;
};

struct ext4_ext_path {
    struct ext4_extent_header *p_hdr;
    struct buffer_head *p_bh;
    struct ext4_extent *p_ext;
};

struct ext4_map_blocks {
    ext4_fsblk_t m_pblk;
    ext4_lblk_t m_lblk;
    unsigned int m_len;
    unsigned int m_flags;
};

static inline ext4_fsblk_t ext4_ext_pblock(struct ext4_extent *ex) {
    return (ex->ee_start_hi << 32) | ex->ee_start_lo;
}

static inline void ext4_ext_store_pblock(struct ext4_extent *ex, ext4_fsblk_t pb) {
    ex->ee_start_hi = (pb >> 32);
    ex->ee_start_lo = (pb & 0xffffffff);
}

static inline unsigned short ext4_ext_get_actual_len(struct ext4_extent *ex) {
    return ex->ee_len;
}

static inline int ext4_ext_is_uninitialized(struct ext4_extent *ex) {
    return 0;
}

static inline void ext4_ext_mark_uninitialized(struct ext4_extent *ex) {
}

static inline struct ext4_extent_header *ext_block_hdr(struct buffer_head *bh) {
    return NULL;
}

static inline int ext_depth(struct inode *inode) {
    return 0;
}

static inline void le16_add_cpu(unsigned short *var, int val) {
    *var += val;
}

static inline void ext_debug(const char *fmt, ...) {
}

#define EXT_FIRST_EXTENT(eh) ((struct ext4_extent *)((eh) + 1))
#define EXT_LAST_EXTENT(eh) (EXT_FIRST_EXTENT(eh) + (eh)->eh_entries - 1)

static int ext4_ext_truncate_extend_restart(handle_t *handle, struct inode *inode, int credits) {
    return 0;
}

static int ext4_ext_get_access(handle_t *handle, struct inode *inode, struct ext4_ext_path *path) {
    return 0;
}

static int ext4_remove_blocks(handle_t *handle, struct inode *inode, struct ext4_extent *ex, ext4_lblk_t from, ext4_lblk_t to) {
    return 0;
}

static int ext4_ext_dirty(handle_t *handle, struct inode *inode, struct ext4_ext_path *path) {
    return 0;
}

static int ext4_ext_correct_indexes(handle_t *handle, struct inode *inode, struct ext4_ext_path *path) {
    return 0;
}

static int ext4_ext_rm_idx(handle_t *handle, struct inode *inode, struct ext4_ext_path *path) {
    return 0;
}

static int ext4_split_extent(handle_t *handle, struct inode *inode, struct ext4_ext_path *path, struct ext4_map_blocks *map, int flags, int mask) {
    return 0;
}