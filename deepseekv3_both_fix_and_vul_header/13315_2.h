#include <stdint.h>
#include <string.h>

typedef uint32_t __u32;
typedef uint16_t __le16;
typedef uint32_t __le32;

struct inode {
    void *i_sb;
};

struct ext4_iloc;

struct ext4_xattr_ibody_header {
    __u32 h_magic;
};

struct ext4_xattr_entry {
    __u32 e_value_inum;
    __u32 e_value_size;
    __le16 e_value_offs;
    char e_name[0];
};

struct ext4_inode {
    char dummy[128];
};

struct ext4_sb_info {
    unsigned int s_inode_size;
};

struct ext4_inode_info {
    unsigned int i_extra_isize;
    unsigned int i_inline_off;
};

#define EXT4_INODE_HAS_XATTR_SPACE(inode) 0
#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb))
#define EXT4_GOOD_OLD_INODE_SIZE 128
#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))
#define EXT4_STATE_XATTR 0
#define EXT4_XATTR_SYSTEM_DATA ""
#define EXT4_XATTR_ROUND 3
#define EXT4_XATTR_SIZE(size) ((size + EXT4_XATTR_ROUND) & ~EXT4_XATTR_ROUND)
#define EXT4_XATTR_LEN(len) (len)
#define IS_LAST_ENTRY(entry) ((entry)->e_name[0] == 0)
#define EXT4_XATTR_NEXT(entry) ((struct ext4_xattr_entry *)((char *)(entry) + sizeof(struct ext4_xattr_entry)))
#define IHDR(inode, raw_inode) ((struct ext4_xattr_ibody_header *)((char *)(raw_inode) + EXT4_GOOD_OLD_INODE_SIZE + EXT4_I(inode)->i_extra_isize))
#define IFIRST(header) ((struct ext4_xattr_entry *)((header) + 1))

static inline struct ext4_inode *ext4_raw_inode(struct ext4_iloc *iloc) { return NULL; }
static inline int ext4_test_inode_state(struct inode *inode, int state) { return 0; }
static inline size_t le16_to_cpu(__le16 val) { return val; }
static inline size_t le32_to_cpu(__le32 val) { return val; }