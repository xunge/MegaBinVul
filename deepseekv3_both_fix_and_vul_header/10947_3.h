#include <stdint.h>
#include <string.h>

struct inode {
    struct super_block *i_sb;
};

struct super_block;

struct ext4_iloc;
struct ext4_inode;
struct handle;
typedef struct handle handle_t;

struct ext4_xattr_ibody_header {
    uint32_t h_magic;
};

struct ext4_inode_info {
    unsigned int i_extra_isize;
};

typedef uint32_t __le32;

#define EXT4_GOOD_OLD_INODE_SIZE 128
#define EXT4_INODE_SIZE(sb) (EXT4_GOOD_OLD_INODE_SIZE)
#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))
#define EXT4_ERROR_INODE(inode, fmt, ...)
#define EXT4_STATE_XATTR (1 << 0)
#define EXT4_XATTR_MAGIC 0xEA020000
#define EFSCORRUPTED 117
#define EINVAL 22

#define cpu_to_le32(x) (x)
#define ext4_test_inode_state(inode, flag) (0)
#define ext4_raw_inode(iloc) ((struct ext4_inode *)NULL)
#define IHDR(inode, raw_inode) ((struct ext4_xattr_ibody_header *)NULL)
#define ext4_expand_extra_isize_ea(inode, size, raw_inode, handle) (0)