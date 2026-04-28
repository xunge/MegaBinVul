#include <stdint.h>
#include <stdbool.h>

#define ENOSPC 28
#define EXT4_XATTR_MAGIC 0xEA020000
#define EXT4_STATE_XATTR 0x00000800
#define cpu_to_le32(x) (x)
#define IS_LAST_ENTRY(entry) (0)

typedef struct handle_s handle_t;

struct inode {
    unsigned long i_ino;
};

struct buffer_head {
    void *b_data;
};

struct ext4_xattr_search {
    void *first;
};

struct ext4_xattr_ibody_header {
    uint32_t h_magic;
};

struct ext4_xattr_info;
struct ext4_xattr_ibody_find;

struct ext4_inode_info {
    struct inode vfs_inode;
    unsigned int i_extra_isize;
};

struct ext4_inode {
    uint32_t i_block[15];
};

struct ext4_iloc {
    struct buffer_head *bh;
};

struct ext4_xattr_ibody_find {
    struct ext4_xattr_search s;
    struct ext4_iloc iloc;
};

#define EXT4_GOOD_OLD_INODE_SIZE 128
#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))
#define ext4_raw_inode(iloc) ((struct ext4_inode *)((iloc)->bh->b_data))
#define IHDR(inode, raw_inode) ((struct ext4_xattr_ibody_header *) \
                ((void *)(raw_inode) + EXT4_GOOD_OLD_INODE_SIZE + \
                 EXT4_I(inode)->i_extra_isize))

static inline int ext4_xattr_set_entry(struct ext4_xattr_info *i,
                     struct ext4_xattr_search *s,
                     handle_t *handle,
                     struct inode *inode,
                     bool is_block) {
    return 0;
}

static inline void ext4_set_inode_state(struct inode *inode, unsigned int state) {}
static inline void ext4_clear_inode_state(struct inode *inode, unsigned int state) {}