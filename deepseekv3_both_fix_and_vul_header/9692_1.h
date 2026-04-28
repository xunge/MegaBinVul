#include <stdint.h>
#include <sys/types.h>

#define S_ISUID 0004000
#define S_ISGID 0002000
#define S_IMMUTABLE 00010
#define S_APPEND 00020
#define EINVAL 22
#define EPERM 1
#define EOPNOTSUPP 95
#define EXT_MAX_BLOCK 0xffffffff
#define EXT4_INODE_EXTENTS 0x00080000

#define IS_IMMUTABLE(inode) ((inode)->i_flags & S_IMMUTABLE)
#define IS_APPEND(inode) ((inode)->i_flags & S_APPEND)
#define IS_SWAPFILE(inode) (0)

struct inode {
    unsigned short i_mode;
    unsigned long i_ino;
    struct super_block *i_sb;
    unsigned int i_flags;
    unsigned int i_blkbits;
    loff_t i_size;
};

struct super_block {
};

typedef uint32_t ext4_lblk_t;
typedef uint64_t __u64;

static inline int ext4_test_inode_flag(struct inode *inode, int flag) {
    return 0;
}

static inline void ext4_debug(const char *fmt, ...) {
}