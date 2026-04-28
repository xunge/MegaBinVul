#include <stdint.h>

struct inode;
struct ext4_extent_header {
    uint16_t eh_magic;
    uint16_t eh_entries;
    uint16_t eh_max;
    uint16_t eh_depth;
    uint32_t eh_generation;
};

typedef struct handle_s handle_t;

#define EXT4_EXT_MAGIC 0xF30A
#define cpu_to_le16(x) (x)
#define ext_inode_hdr(inode) ((struct ext4_extent_header *)((char *)(inode) + 128))
#define ext4_ext_space_root(inode, i) (sizeof(struct ext4_extent_header) + 12 * (i))
#define ext4_mark_inode_dirty(handle, inode)