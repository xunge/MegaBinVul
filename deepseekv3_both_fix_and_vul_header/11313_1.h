#include <stdint.h>
#include <stdlib.h>

#define EXT4_XATTR_MAGIC 0xEA020000
#define EFSCORRUPTED 117
#define EFSBADCRC 121

struct inode;
struct buffer_head {
    void *b_data;
    uint64_t b_blocknr;
    size_t b_size;
};

struct ext4_xattr_header {
    uint32_t h_magic;
    uint32_t h_blocks;
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

#define cpu_to_le32(x) (x)
#define BHDR(bh) ((struct ext4_xattr_header *)((bh)->b_data))
#define BFIRST(bh) ((struct ext4_xattr_entry *)((bh)->b_data + sizeof(struct ext4_xattr_header)))

static inline int buffer_verified(struct buffer_head *bh) { return 0; }
static inline void set_buffer_verified(struct buffer_head *bh) {}
static inline int ext4_xattr_block_csum_verify(struct inode *inode, struct buffer_head *bh) { return 0; }
static inline int ext4_xattr_check_entries(struct ext4_xattr_entry *entry, void *end, void *start) { return 0; }
static inline void __ext4_error_inode(struct inode *inode, const char *func, unsigned int line, int err, const char *fmt, ...) {}