#include <stddef.h>
#include <string.h>

#define EXT4_XATTR_INDEX_SYSTEM 0
#define EXT4_XATTR_SYSTEM_DATA "data"
#define EXT4_MIN_INLINE_DATA_SIZE 0
#define ENODATA 61
#define EXT4_INODE_EXTENTS 1
#define EXT4_INODE_INLINE_DATA 2
#define EXT4_STATE_MAY_INLINE_DATA 3

#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))
#define BUFFER_TRACE(bh, msg)
#define S_ISDIR(mode) (0)
#define S_ISREG(mode) (0)
#define S_ISLNK(mode) (0)

typedef struct handle_t handle_t;

struct inode {
    struct super_block *i_sb;
    unsigned int i_mode;
};

struct buffer_head;
struct super_block;

struct ext4_inode {
    char i_block[60];
};

struct ext4_inode_info {
    unsigned int i_inline_off;
    unsigned int i_inline_size;
    char i_data[1];
    struct inode vfs_inode;
};

struct ext4_iloc {
    struct buffer_head *bh;
    struct ext4_inode raw_inode;
};

struct ext4_xattr_ibody_find {
    struct {
        int not_found;
    } s;
    struct ext4_iloc iloc;
};

struct ext4_xattr_info {
    int name_index;
    const char *name;
    void *value;
    size_t value_len;
};

static inline int ext4_get_inode_loc(struct inode *inode, struct ext4_iloc *iloc) { return 0; }
static inline int ext4_xattr_ibody_find(struct inode *inode, struct ext4_xattr_info *i, struct ext4_xattr_ibody_find *is) { return 0; }
static inline int ext4_journal_get_write_access(handle_t *handle, struct buffer_head *bh) { return 0; }
static inline int ext4_xattr_ibody_inline_set(handle_t *handle, struct inode *inode, struct ext4_xattr_info *i, struct ext4_xattr_ibody_find *is) { return 0; }
static inline struct ext4_inode *ext4_raw_inode(struct ext4_iloc *iloc) { return &iloc->raw_inode; }
static inline int ext4_has_feature_extents(struct super_block *sb) { return 0; }
static inline void ext4_set_inode_flag(struct inode *inode, int flag) {}
static inline void ext4_ext_tree_init(handle_t *handle, struct inode *inode) {}
static inline void ext4_clear_inode_flag(struct inode *inode, int flag) {}
static inline void get_bh(struct buffer_head *bh) {}
static inline int ext4_mark_iloc_dirty(handle_t *handle, struct inode *inode, struct ext4_iloc *iloc) { return 0; }
static inline void ext4_clear_inode_state(struct inode *inode, int state) {}
static inline void brelse(struct buffer_head *bh) {}