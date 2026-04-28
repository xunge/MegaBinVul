#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef uint32_t __u32;
typedef uint32_t __le32;
typedef uint16_t __le16;
typedef uint8_t __u8;

#define F2FS_NAME_LEN 255
#define F2FS_XATTR_INDEX_ENCRYPTION 0
#define F2FS_XATTR_NAME_ENCRYPTION_CONTEXT "c"
#define XATTR_CREATE 1
#define XATTR_REPLACE 2

#define EINVAL 22
#define ERANGE 34
#define E2BIG 7
#define EEXIST 17
#define ENODATA 61
#define EFSCORRUPTED 117

struct inode {
    unsigned long i_ino;
    unsigned int i_mode;
    struct timespec i_ctime;
    struct {
        void *s_fs_info;
        unsigned long s_blocksize;
    } *i_sb;
};

struct page;
struct f2fs_sb_info;
struct f2fs_inode_info {
    unsigned int i_acl_mode;
};

struct f2fs_xattr_entry {
    __u8 e_name_index;
    __u8 e_name_len;
    __le16 e_value_size;
    char e_name[0];
};

struct f2fs_xattr_header {
    __le32 h_magic;
    __le32 h_refcount;
    __le32 h_blocks;
    __le32 h_checksum;
    __u32 h_reserved[4];
};

#define XATTR_NEXT_ENTRY(entry) ((struct f2fs_xattr_entry *)((char *)(entry) + ENTRY_SIZE(entry)))
#define IS_XATTR_LAST_ENTRY(entry) (*(__u32 *)(entry) == 0)
#define ENTRY_SIZE(entry) (sizeof(struct f2fs_xattr_entry) + (entry)->e_name_len + le16_to_cpu((entry)->e_value_size))
#define MIN_OFFSET(inode) ((unsigned long)((inode)->i_sb->s_blocksize - 1))
#define MAX_VALUE_LEN(inode) ((inode)->i_sb->s_blocksize - sizeof(struct f2fs_xattr_entry) - 1)
#define XATTR_SIZE(inode) (sizeof(struct f2fs_xattr_header) + (inode)->i_sb->s_blocksize)
#define XATTR_ALIGN(size) (((size) + 3) & ~3)

#define S_ISDIR(mode) ((mode) & 0040000)
#define SBI_NEED_FSCK 1
#define SBI_NEED_CP 2
#define FI_ACL_MODE 1

#define F2FS_I_SB(inode) ((struct f2fs_sb_info *)((inode)->i_sb->s_fs_info))
#define F2FS_I(inode) ((struct f2fs_inode_info *)(inode))

static inline __le16 cpu_to_le16(uint16_t x) { return x; }
static inline uint16_t le16_to_cpu(__le16 x) { return x; }
static inline int unlikely(int x) { return x; }

static inline void set_sbi_flag(struct f2fs_sb_info *sbi, int flag) {}
static inline void f2fs_set_encrypted_inode(struct inode *inode) {}
static inline void f2fs_mark_inode_dirty_sync(struct inode *inode, bool flag) {}
static inline bool is_inode_flag_set(struct inode *inode, int flag) { return false; }
static inline void clear_inode_flag(struct inode *inode, int flag) {}
static inline struct timespec current_time(struct inode *inode) { struct timespec ts = {0}; return ts; }
static inline int read_all_xattrs(struct inode *inode, struct page *ipage, void **base_addr) { return 0; }
static inline int write_all_xattrs(struct inode *inode, __u32 hsize, void *base_addr, struct page *ipage) { return 0; }
static inline bool f2fs_xattr_value_same(struct f2fs_xattr_entry *entry, const void *value, size_t size) { return false; }
static inline void f2fs_err(struct f2fs_sb_info *sbi, const char *fmt, ...) {}
static inline void kfree(void *p) { free(p); }
static inline struct f2fs_xattr_entry *__find_xattr(void *base_addr, void *last_base_addr, int index, size_t len, const char *name) { return NULL; }