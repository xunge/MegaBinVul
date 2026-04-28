#include <stdint.h>

typedef uint32_t ext4_lblk_t;
typedef uint64_t u64;
typedef uint32_t u32;

struct inode {
    unsigned long i_ino;
    u64 i_size;
    struct super_block *i_sb;
};

struct super_block {
    unsigned long s_blocksize;
    unsigned char s_blocksize_bits;
};

struct ext4_map_blocks {
    ext4_lblk_t m_lblk;
    unsigned int m_len;
};

struct ext4_ext_path {
    struct ext4_extent *p_ext;
};

struct ext4_extent {
    u32 ee_block;
};

#define EXT4_EXT_MAY_ZEROOUT    0x1
#define EXT4_EXT_MARK_UNINIT2   0x2
#define EXT4_EXT_DATA_VALID2    0x4
#define EXT4_GET_BLOCKS_CONVERT 0x8
#define EXT4_GET_BLOCKS_PRE_IO  0x10

static inline unsigned int ext4_ext_get_actual_len(struct ext4_extent *ex) { return 0; }
static inline int ext_depth(struct inode *inode) { return 0; }
static void ext_debug(const char *fmt, ...) {}

typedef int handle_t;