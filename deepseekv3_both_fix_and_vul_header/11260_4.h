#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t __u32;
typedef uint8_t __u8;
typedef struct handle_t handle_t;

struct ext4_xattr_entry {
    __u32 e_name_index;
    __u8 e_name_len;
    __u8 e_name[0];
    __u32 e_value_size;
    __u32 e_value_inum;
};

struct ext4_xattr_ibody_header {
    __u32 h_magic;
};

struct ext4_inode {
    __u32 dummy;
};

struct inode {
    void *i_private;
};

#define EXT4_XATTR_INDEX_SYSTEM 0
#define ENOSPC 28

#define le32_to_cpu(x) (x)
#define EXT4_XATTR_LEN(name_len) (((name_len) + 8 + sizeof(__u32) - 1) & ~(sizeof(__u32) - 1))
#define EXT4_XATTR_SIZE(size) (((size) + sizeof(__u32) - 1) & ~(sizeof(__u32) - 1))
#define IS_LAST_ENTRY(entry) ((entry)->e_name_index == 0 && (entry)->e_name_len == 0 && (entry)->e_value_size == 0)
#define EXT4_XATTR_NEXT(entry) ((struct ext4_xattr_entry *)((char *)(entry) + EXT4_XATTR_LEN((entry)->e_name_len) + (entry)->e_value_size))
#define IHDR(inode, raw_inode) ((struct ext4_xattr_ibody_header *)((char *)(raw_inode) + sizeof(struct ext4_inode)))
#define IFIRST(header) ((struct ext4_xattr_entry *)((char *)(header) + sizeof(struct ext4_xattr_ibody_header)))