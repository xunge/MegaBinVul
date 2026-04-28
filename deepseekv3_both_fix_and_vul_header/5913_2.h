#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef uint32_t ext4_lblk_t;
typedef int32_t handle_t;

#define EIO 5
#define EXT_MAX_BLOCKS 0xFFFFFFFF

struct inode {
    // minimal stub definition
};

struct ext4_extent {
    uint32_t ee_block;
    uint16_t ee_len;
    uint16_t ee_start_hi;
    uint32_t ee_start_lo;
};

struct ext4_extent_header {
    uint16_t eh_magic;
    uint16_t eh_entries;
    uint16_t eh_max;
    uint16_t eh_depth;
    uint32_t eh_generation;
};

struct ext4_ext_path {
    uint32_t p_block;
    uint32_t p_depth;
    struct ext4_extent *p_ext;
    struct ext4_extent_header *p_hdr;
};

#define EXT4_ERROR_INODE(inode, fmt, ...) 
#define ext_debug(fmt, ...) 
#define EXT4_GET_BLOCKS_PRE_IO 0
#define EXT4_GET_BLOCKS_PUNCH_OUT_EXT 0
#define EXT4_MB_USE_ROOT_BLOCKS 0
#define EXT_MAX_BLOCK 0
#define EXT_FIRST_EXTENT(eh) ((struct ext4_extent *)((eh) + 1))
#define EXT_LAST_EXTENT(eh) (EXT_FIRST_EXTENT(eh) + (eh)->eh_entries - 1)
#define EXT_MAX_EXTENT(eh) (EXT_FIRST_EXTENT(eh) + (eh)->eh_max)

#define unlikely(x) (x)
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)
#define BUG_ON(x) do { if (x) {} } while (0)

#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)
#define cpu_to_le16(x) (x)
#define le16_add_cpu(var, val) do { (*(var)) += (val); } while (0)

#define ext4_ext_is_uninitialized(ex) (0)
#define ext4_ext_get_actual_len(ex) ((ex)->ee_len)
#define ext4_ext_pblock(ex) ((ex)->ee_start_lo)
#define ext4_ext_store_pblock(ex, val) do { (ex)->ee_start_lo = (val); } while (0)
#define ext4_ext_mark_uninitialized(ex) do { } while (0)

#define kfree free

static inline int ext_depth(struct inode *inode) { return 0; }
static inline int ext4_ext_get_access(handle_t *handle, struct inode *inode, struct ext4_ext_path *path) { return 0; }
static inline int ext4_can_extents_be_merged(struct inode *inode, struct ext4_extent *ex1, struct ext4_extent *ex2) { return 0; }
static inline ext4_lblk_t ext4_ext_next_leaf_block(struct inode *inode, struct ext4_ext_path *path) { return 0; }
static inline struct ext4_ext_path *ext4_ext_find_extent(struct inode *inode, ext4_lblk_t block, struct ext4_ext_path *path) { return NULL; }
static inline int ext4_ext_create_new_leaf(handle_t *handle, struct inode *inode, int flags, struct ext4_ext_path *path, struct ext4_extent *newext) { return 0; }
static inline void ext4_ext_try_to_merge(struct inode *inode, struct ext4_ext_path *path, struct ext4_extent *ex) {}
static inline int ext4_ext_correct_indexes(handle_t *handle, struct inode *inode, struct ext4_ext_path *path) { return 0; }
static inline int ext4_ext_dirty(handle_t *handle, struct inode *inode, struct ext4_ext_path *path) { return 0; }
static inline void ext4_ext_drop_refs(struct ext4_ext_path *path) {}
static inline void ext4_ext_invalidate_cache(struct inode *inode) {}