#include <stdint.h>

typedef uint32_t __u32;
typedef uint16_t __u16;

struct inode {
    uint32_t i_generation;
};

struct iso_inode_info {
    __u32 i_iget5_block;
    __u16 i_iget5_offset;
};

#define ISOFS_I(inode) ((struct iso_inode_info *)(inode))