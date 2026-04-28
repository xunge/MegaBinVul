#include <stdint.h>
#include <stddef.h>

typedef struct handle_t {
    int dummy;
} handle_t;

struct mutex {
    int dummy;
};
#define mutex_lock(m) 
#define mutex_unlock(m) 

struct list_head {
    struct list_head *next, *prev;
};
#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define list_empty(list) (1)
#define list_add(new, head) 

struct ext4_super_block {
    uint32_t s_inodes_count;
    uint32_t s_last_orphan;
};

struct ext4_iloc {
    int dummy;
};

struct ext4_sb_info {
    void *s_journal;
    struct mutex s_orphan_lock;
    struct list_head s_orphan;
    void *s_sbh;
    struct ext4_super_block *s_es;
};

struct super_block {
    struct ext4_sb_info *s_fs_info;
    struct ext4_super_block *s_es;
    void *s_journal;
    struct mutex s_orphan_lock;
    struct list_head s_orphan;
    void *s_sbh;
};

struct inode {
    struct super_block *i_sb;
    unsigned long i_ino;
    unsigned int i_nlink;
    unsigned short i_mode;
};

struct ext4_inode_info {
    struct list_head i_orphan;
    uint32_t i_dtime;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb->s_fs_info))
#define EXT4_I(inode) ((struct ext4_inode_info *)((void*)0))
#define NEXT_ORPHAN(inode) (EXT4_I(inode)->i_dtime)
#define J_ASSERT(assert) 
#define BUFFER_TRACE(bh, msg) 
#define S_ISREG(mode) (((mode) & 0170000) == 0100000)
#define S_ISDIR(mode) (((mode) & 0170000) == 0040000)
#define S_ISLNK(mode) (((mode) & 0170000) == 0120000)
#define le32_to_cpu(x) (x)
#define cpu_to_le32(x) (x)
#define jbd_debug(level, fmt, ...) 
#define ext4_std_error(sb, err) (err)
#define ext4_handle_valid(h) (0)

static inline int ext4_journal_get_write_access(handle_t *handle, void *bh) { return 0; }
static inline int ext4_reserve_inode_write(handle_t *handle, struct inode *inode, struct ext4_iloc *iloc) { return 0; }
static inline int ext4_handle_dirty_super(handle_t *handle, struct super_block *sb) { return 0; }
static inline int ext4_mark_iloc_dirty(handle_t *handle, struct inode *inode, struct ext4_iloc *iloc) { return 0; }