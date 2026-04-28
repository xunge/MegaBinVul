#include <stdint.h>
#include <limits.h>

typedef uint32_t u32;
typedef uint16_t u16;

#define IS_LAST_ENTRY(entry) ((entry)->e_name_len == 0 && (entry)->e_value_size == 0 && (entry)->e_value_inum == 0)
#define EXT4_XATTR_NEXT(entry) ((struct ext4_xattr_entry *)((char *)(entry) + sizeof(struct ext4_xattr_entry) + (entry)->e_name_len))
#define EXT4_XATTR_SIZE(size) (((size) + 3) & ~3)
#define le32_to_cpu(x) (x)
#define le16_to_cpu(x) (x)

struct ext4_xattr_entry {
    uint8_t e_name_len;
    uint8_t e_name_index;
    uint16_t e_value_offs;
    uint32_t e_value_inum;
    uint32_t e_value_size;
    char e_name[0];
};

#define EFSCORRUPTED 117