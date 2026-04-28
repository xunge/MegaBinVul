#include <stdint.h>
#include <stddef.h>

typedef uint32_t ext4_lblk_t;
typedef uint32_t __le32;

struct inode {
    unsigned long i_ino;
};

struct ext4_map_blocks {
    ext4_lblk_t m_lblk;
    unsigned int m_len;
};

struct ext4_ext_path {
    int p_depth;
    struct ext4_extent *p_ext;
};

struct ext4_extent {
    __le32 ee_block;
    uint16_t ee_len;
};

typedef struct {} handle_t;

#define EXT4_GET_BLOCKS_CONVERT 0
#define PTR_ERR(x) ((long)(x))
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))

static inline uint32_t le32_to_cpu(__le32 x) { return x; }

static int ext_depth(struct inode *inode) { return 0; }
static unsigned int ext4_ext_get_actual_len(struct ext4_extent *ex) { return 0; }
static void ext_debug(const char *fmt, ...) {}
static int ext4_split_unwritten_extents(handle_t *handle, struct inode *inode, struct ext4_map_blocks *map, struct ext4_ext_path *path, int flags) { return 0; }
static void ext4_ext_drop_refs(struct ext4_ext_path *path) {}
static struct ext4_ext_path *ext4_ext_find_extent(struct inode *inode, ext4_lblk_t lblk, struct ext4_ext_path *path) { return NULL; }
static int ext4_ext_get_access(handle_t *handle, struct inode *inode, struct ext4_ext_path *path) { return 0; }
static void ext4_ext_mark_initialized(struct ext4_extent *ex) {}
static void ext4_ext_try_to_merge(handle_t *handle, struct inode *inode, struct ext4_ext_path *path, struct ext4_extent *ex) {}
static int ext4_ext_dirty(handle_t *handle, struct inode *inode, struct ext4_ext_path *path) { return 0; }
static void ext4_ext_show_leaf(struct inode *inode, struct ext4_ext_path *path) {}