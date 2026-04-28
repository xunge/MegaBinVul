#include <stdint.h>
#include <string.h>

typedef uint32_t ext4_lblk_t;
typedef uint64_t ext4_fsblk_t;
typedef void *handle_t;

struct inode {
    unsigned long i_ino;
};

struct ext4_ext_path {
    struct ext4_extent *p_ext;
    int p_depth;
};

struct ext4_extent {
    uint32_t ee_block;
    uint16_t ee_len;
    uint16_t ee_start_hi;
    uint32_t ee_start_lo;
};

#define EXT4_EXT_DATA_VALID1 0x01
#define EXT4_EXT_DATA_VALID2 0x02
#define EXT4_EXT_MARK_UNINIT1 0x04
#define EXT4_EXT_MARK_UNINIT2 0x08
#define EXT4_GET_BLOCKS_PRE_IO 0x10
#define EXT4_EXT_MAY_ZEROOUT 0x20
#define ENOSPC (-28)

#define BUG_ON(condition) ((void)0)
#define ext_debug(fmt, ...) ((void)0)
#define ext4_ext_show_leaf(inode, path) ((void)0)
#define ext_depth(inode) (0)
#define ext4_ext_get_actual_len(ex) ((ex)->ee_len)
#define ext4_ext_pblock(ex) ((ext4_fsblk_t)((ex)->ee_start_lo))
#define ext4_ext_mark_uninitialized(ex) ((void)0)
#define ext4_ext_mark_initialized(ex) ((void)0)
#define ext4_ext_store_pblock(ex, block) ((ex)->ee_start_lo = (uint32_t)(block))
#define le32_to_cpu(x) (x)
#define le16_to_cpu(x) (x)
#define cpu_to_le32(x) (x)
#define cpu_to_le16(x) (x)

static int ext4_ext_get_access(handle_t *handle, struct inode *inode, struct ext4_ext_path *path) { return 0; }
static int ext4_ext_try_to_merge(handle_t *handle, struct inode *inode, struct ext4_ext_path *path, struct ext4_extent *ex) { return 0; }
static int ext4_ext_dirty(handle_t *handle, struct inode *inode, struct ext4_ext_path *path) { return 0; }
static int ext4_ext_insert_extent(handle_t *handle, struct inode *inode, struct ext4_ext_path *path, struct ext4_extent *newex, int flags) { return 0; }
static int ext4_ext_zeroout(struct inode *inode, struct ext4_extent *ex) { return 0; }