#include <stdint.h>

typedef uint32_t ext4_lblk_t;
typedef void* handle_t;

struct inode {
    // dummy definition
};

struct ext4_ext_path {
    struct ext4_extent *p_ext;
};

struct ext4_map_blocks {
    ext4_lblk_t m_lblk;
    unsigned int m_len;
};

struct ext4_extent {
    uint32_t ee_block;
    uint16_t ee_len;
};

#define EXT4_EXT_MAY_ZEROOUT        0x1
#define EXT4_EXT_MARK_UNINIT1       0x2
#define EXT4_EXT_MARK_UNINIT2       0x4
#define EXT4_EXT_DATA_VALID1        0x8
#define EXT4_EXT_DATA_VALID2        0x10
#define EXT4_GET_BLOCKS_PRE_IO      0x20

#define IS_ERR(x) ((uintptr_t)(x) >= (uintptr_t)-4095)
#define PTR_ERR(x) ((intptr_t)(x))

static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline unsigned int ext4_ext_get_actual_len(struct ext4_extent *ex) { return ex->ee_len; }
static inline int ext4_ext_is_uninitialized(struct ext4_extent *ex) { return 0; }
static inline int ext_depth(struct inode *inode) { return 0; }
static inline void ext4_ext_drop_refs(struct ext4_ext_path *path) {}
static inline struct ext4_ext_path *ext4_ext_find_extent(struct inode *inode, ext4_lblk_t lblk, struct ext4_ext_path *path) { return path; }
static inline void ext4_ext_show_leaf(struct inode *inode, struct ext4_ext_path *path) {}
static inline int ext4_split_extent_at(handle_t *handle, struct inode *inode, struct ext4_ext_path *path, ext4_lblk_t lblk, int split_flag, int flags) { return 0; }