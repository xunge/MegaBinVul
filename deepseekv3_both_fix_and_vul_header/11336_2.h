#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef unsigned int handle_t;

struct ext4_xattr_info {
    const char *name;
    const void *value;
    size_t value_len;
};

struct ext4_xattr_entry {
    uint8_t e_name_len;
    uint8_t e_name_index;
    uint16_t e_value_offs;
    uint32_t e_value_block;
    uint32_t e_value_size;
    uint32_t e_hash;
    char e_name[0];
};

struct ext4_xattr_search {
    struct ext4_xattr_entry *first;
};

struct buffer_head;
struct ext4_iloc {
    struct buffer_head *bh;
    unsigned long offset;
};

struct ext4_xattr_ibody_find {
    struct ext4_xattr_search s;
    struct ext4_iloc iloc;
};

struct ext4_xattr_ibody_header {
    uint32_t h_magic;
};

struct ext4_inode_info {
    unsigned int i_extra_isize;
};

struct inode {
    struct ext4_inode_info *i_private;
};

#define EXT4_XATTR_MAGIC 0xEA020000
#define EXT4_XATTR_LEN(len) ((len) + sizeof(struct ext4_xattr_entry))
#define EXT4_XATTR_SIZE(size) (size)
#define EXT4_STATE_XATTR (1 << 0)

#define ENOSPC 28

#define cpu_to_le32(x) (x)
#define le32_to_cpu(x) (x)

#define IS_LAST_ENTRY(entry) (0)

#define EXT4_I(inode) ((struct ext4_inode_info *)(inode->i_private))
#define IHDR(inode, raw_inode) ((struct ext4_xattr_ibody_header *)(raw_inode))

static inline void *ext4_raw_inode(struct ext4_iloc *iloc) {
    return (void *)iloc->offset;
}

static inline bool ext4_has_inline_data(struct inode *inode) {
    return false;
}

static inline int ext4_try_to_evict_inline_data(handle_t *handle, 
                struct inode *inode, size_t needed) {
    return 0;
}

static inline int ext4_xattr_ibody_find(struct inode *inode,
                struct ext4_xattr_info *i, struct ext4_xattr_ibody_find *is) {
    return 0;
}

static inline int ext4_xattr_set_entry(struct ext4_xattr_info *i,
                struct ext4_xattr_search *s, handle_t *handle,
                struct inode *inode, bool is_block) {
    return 0;
}

static inline void ext4_set_inode_state(struct inode *inode, unsigned int state) {
}

static inline void ext4_clear_inode_state(struct inode *inode, unsigned int state) {
}