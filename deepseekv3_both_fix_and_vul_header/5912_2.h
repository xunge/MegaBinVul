#include <stdint.h>
#include <stdlib.h>

typedef uint32_t ext4_lblk_t;
typedef uint64_t ext4_fsblk_t;
typedef uint32_t __le32;
typedef uint16_t __le16;

typedef int (*ext_prepare_callback)(void *, void *, void *, void *, void *);

#define EXT_MAX_BLOCKS     ((ext4_lblk_t)~0)
#define EXT_MAX_BLOCK      EXT_MAX_BLOCKS
#define EXT4_ERROR_INODE(inode, fmt, ...) do {} while (0)
#define BUG_ON(cond) do { if (cond) abort(); } while (0)
#define IS_ERR(ptr) (0)
#define PTR_ERR(ptr) (0)
#define unlikely(cond) (cond)
#define le32_to_cpu(x) (x)
#define down_read(sem) do {} while (0)
#define up_read(sem) do {} while (0)
#define kfree(ptr) free(ptr)

struct ext4_ext_path {
    void *p_hdr;
    void *p_ext;
};

struct ext4_ext_cache {
    ext4_fsblk_t ec_start;
    ext4_lblk_t ec_block;
    unsigned short ec_len;
};

struct ext4_extent {
    __le32 ee_block;
    __le16 ee_len;
    __le16 ee_start_hi;
    __le32 ee_start_lo;
};

struct ext4_inode_info {
    void *i_data_sem;
};

#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))

static inline int ext_depth(void *inode) { return 0; }
static inline ext4_lblk_t ext4_ext_next_allocated_block(void *path) { return 0; }
static inline unsigned short ext4_ext_get_actual_len(void *ex) { return 0; }
static inline ext4_fsblk_t ext4_ext_pblock(void *ex) { return 0; }
static inline void ext4_ext_drop_refs(void *path) {}
static inline void *ext4_ext_find_extent(void *inode, ext4_lblk_t block, void *path) { return NULL; }

#define EXT_REPEAT 1
#define EXT_BREAK 2
#define EIO 5