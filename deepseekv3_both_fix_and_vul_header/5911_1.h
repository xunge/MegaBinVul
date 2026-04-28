#include <stdint.h>
#include <linux/types.h>

#define EXT4_INODE_EXTENTS 0
#define EXT4_FIEMAP_FLAGS 0
#define FIEMAP_FLAG_XATTR 0
#define EXT_MAX_BLOCKS 0
#define EXT_MAX_BLOCK 0
#define EBADR 0

typedef uint32_t ext4_lblk_t;

struct inode {
    struct super_block *i_sb;
};

struct super_block {
    unsigned long s_blocksize_bits;
};

struct fiemap_extent_info {
    unsigned int fi_flags;
};

int ext4_test_inode_flag(struct inode *inode, int flag);
int generic_block_fiemap(struct inode *inode, struct fiemap_extent_info *fieinfo, __u64 start, __u64 len, void *func);
int fiemap_check_flags(struct fiemap_extent_info *fieinfo, int flags);
int ext4_xattr_fiemap(struct inode *inode, struct fiemap_extent_info *fieinfo);
int ext4_ext_walk_space(struct inode *inode, ext4_lblk_t start_blk, ext4_lblk_t len_blks, void *cb, struct fiemap_extent_info *fieinfo);
void *ext4_ext_fiemap_cb;
void *ext4_get_block;