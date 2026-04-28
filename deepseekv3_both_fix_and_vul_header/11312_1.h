#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

typedef uint8_t __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;
typedef __u32 __le32;

struct ext4_xattr_info;
struct ext4_xattr_search;
struct inode;
struct ext4_xattr_entry;
struct ext4_xattr_header;

#define EXT4_XATTR_SIZE(size) ((size) + 3 & ~3)
#define EXT4_XATTR_LEN(name_len) (sizeof(struct ext4_xattr_entry) + (name_len) + 1)
#define EXT4_XATTR_BLOCK_RESERVE(inode) (1024)
#define EXT4_ZERO_XATTR_VALUE ((void *)-1)
#define IS_LAST_ENTRY(entry) ((entry)->e_name_index == 0 && (entry)->e_name_len == 0 && (entry)->e_value_size == 0)
#define EXT4_XATTR_NEXT(entry) ((struct ext4_xattr_entry *)((char *)(entry) + EXT4_XATTR_LEN((entry)->e_name_len)))
#define ENTRY(ptr) ((struct ext4_xattr_entry *)(ptr))

#define EFSCORRUPTED 117
#define ENOSPC 28

#define cpu_to_le16(x) (x)
#define cpu_to_le32(x) (x)
#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)

struct ext4_xattr_entry {
    __u8    e_name_len;
    __u8    e_name_index;
    __u16   e_value_offs;
    __u32   e_value_inum;
    __u32   e_value_size;
    __u32   e_hash;
    char    e_name[0];
};

struct ext4_xattr_info {
    const char *name;
    const void *value;
    size_t value_len;
    int name_index;
    int in_inode;
};

struct ext4_xattr_search {
    struct ext4_xattr_entry *first;
    void *base;
    void *end;
    struct ext4_xattr_entry *here;
    int not_found;
};

struct inode {
    unsigned long i_ino;
    void *i_sb;
};

typedef void *handle_t;

static void EXT4_ERROR_INODE(struct inode *inode, const char *fmt, ...) {}
static void WARN_ON_ONCE(int condition) {}
static void ext4_warning_inode(struct inode *inode, const char *fmt, ...) {}
static int ext4_has_feature_ea_inode(void *sb) { return 0; }
static int ext4_xattr_inode_iget(struct inode *parent, unsigned long ino, __u32 hash, struct inode **inode) { return 0; }
static int ext4_xattr_inode_alloc_quota(struct inode *inode, size_t len) { return 0; }
static int ext4_xattr_inode_lookup_create(handle_t *handle, struct inode *inode, const void *value, size_t len, struct inode **inode_out) { return 0; }
static int ext4_xattr_inode_dec_ref(handle_t *handle, struct inode *inode) { return 0; }
static void ext4_xattr_inode_free_quota(struct inode *inode, struct inode *ea_inode, size_t len) {}
static __le32 ext4_xattr_inode_get_hash(struct inode *inode) { return 0; }
static __le32 ext4_xattr_hash_entry(const char *name, size_t name_len, __le32 *value, size_t value_count) { return 0; }
static void ext4_xattr_rehash(struct ext4_xattr_header *header) {}
static void iput(struct inode *inode) {}