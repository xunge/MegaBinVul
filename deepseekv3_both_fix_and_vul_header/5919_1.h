#include <stdint.h>

#define S_ISUID 0004000
#define S_ISGID 0002000
#define S_IMMUTABLE 00010
#define S_APPEND 00020
#define EINVAL 22
#define EPERM 1
#define EOPNOTSUPP 95
#define EXT_MAX_BLOCKS 0xffffffff
#define EXT_MAX_BLOCK EXT_MAX_BLOCKS
#define EXT4_INODE_EXTENTS 0x00080000

typedef uint32_t ext4_lblk_t;
typedef uint64_t ext4_fsblk_t;
typedef uint64_t __u64;
typedef uint32_t __u32;

struct inode {
    unsigned int i_mode;
    unsigned long i_ino;
    void *i_sb;
    unsigned int i_blkbits;
    uint64_t i_size;
};

static inline int ext4_test_inode_flag(struct inode *inode, int flag) { return 0; }
static void ext4_debug(const char *fmt, ...) {}
#define IS_IMMUTABLE(inode) ((inode)->i_mode & S_IMMUTABLE)
#define IS_APPEND(inode) ((inode)->i_mode & S_APPEND)
#define IS_SWAPFILE(inode) (0)