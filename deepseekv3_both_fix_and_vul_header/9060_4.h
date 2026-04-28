#include <stdint.h>
#include <pthread.h>

typedef uint32_t __u32;

struct list_head {
    struct list_head *next, *prev;
};

struct inode {
    unsigned long i_ino;
    void *i_sb;
};

typedef struct handle_t {
    int dummy;
} handle_t;

struct ext4_inode_info {
    struct list_head i_orphan;
    unsigned long i_ino;
    __u32 i_dtime;
    struct inode vfs_inode;
};

struct ext4_sb_info {
    struct list_head s_orphan;
    void *s_journal;
    unsigned long s_mount_state;
    pthread_mutex_t s_orphan_lock;
    void *s_sbh;
    struct {
        __u32 s_last_orphan;
    } *s_es;
};

struct ext4_iloc {
    void *bh;
};

#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))
#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb))
#define NEXT_ORPHAN(inode) (EXT4_I(inode)->i_dtime)
#define EXT4_ORPHAN_FS 0x0004

#define jbd_debug(level, fmt, ...)
#define BUFFER_TRACE(bh, msg)
#define list_empty(list) ((list)->next == (list))
#define list_del_init(list) do { (list)->next = (list); (list)->prev = (list); } while (0)
#define cpu_to_le32(x) (x)
#define list_entry(ptr, type, member) ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

static inline int ext4_reserve_inode_write(handle_t *handle, struct inode *inode, struct ext4_iloc *iloc) { return 0; }
static inline int ext4_journal_get_write_access(handle_t *handle, void *sbh) { return 0; }
static inline int ext4_handle_dirty_super(handle_t *handle, void *sb) { return 0; }
static inline int ext4_mark_iloc_dirty(handle_t *handle, struct inode *inode, struct ext4_iloc *iloc) { return 0; }
static inline void ext4_std_error(void *sb, int err) {}
static inline void mutex_lock(pthread_mutex_t *lock) {}
static inline void mutex_unlock(pthread_mutex_t *lock) {}
static inline void brelse(void *bh) {}