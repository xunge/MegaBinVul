#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>

typedef uint32_t ext4_lblk_t;
typedef uint64_t __u64;

struct inode {
    unsigned long i_ino;
    unsigned short i_mode;
    unsigned int i_flags;
    unsigned int i_blkbits;
    uint64_t i_size;
    void *i_sb;
};

#define EXT4_EXTENTS_FL 0x00080000
#define EXT_MAX_BLOCK 0xffffffff
#define S_ISUID 0004000
#define S_ISGID 0002000
#define S_IFMT 0170000
#define S_IFREG 0100000
#define S_ISREG(mode) (((mode) & S_IFMT) == S_IFREG)
#define IS_SWAPFILE(inode) (0)
#define EINVAL 22
#define EOPNOTSUPP 95

#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))
struct ext4_inode_info {
    unsigned int i_flags;
};

#define ext4_debug(fmt, ...)