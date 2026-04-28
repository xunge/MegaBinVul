#include <stddef.h>

struct inode {
    void *i_sb;
};

struct ext4_xattr_info {
    int name_index;
    const char *name;
};

struct ext4_xattr_ibody_find {
    struct {
        void *base;
        void *first;
        void *here;
        void *end;
        int not_found;
    } s;
    struct {
        void *raw_inode;
    } iloc;
};

struct ext4_xattr_ibody_header {
    char dummy[12]; // Placeholder for actual header structure
};

struct ext4_inode {
    char dummy[128]; // Placeholder for actual inode structure
};

struct ext4_sb_info {
    unsigned int s_inode_size;
};

struct ext4_inode_info {
    unsigned short i_extra_isize;
};

#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))
#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb))
#define IHDR(inode, raw_inode) ((struct ext4_xattr_ibody_header *)((char *)raw_inode + EXT4_I(inode)->i_extra_isize))
#define IFIRST(header) ((void *)((char *)header + sizeof(struct ext4_xattr_ibody_header)))
#define EXT4_STATE_XATTR (1 << 0)
#define ENODATA 61

struct ext4_inode *ext4_raw_inode(void *iloc);
int ext4_test_inode_state(struct inode *inode, int state);
int xattr_check_inode(struct inode *inode, struct ext4_xattr_ibody_header *header, void *end);
int xattr_find_entry(struct inode *inode, void **here, void *end, int name_index, const char *name, int flags);