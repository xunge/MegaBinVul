#include <stdint.h>
#include <pthread.h>

typedef struct handle_t handle_t;
typedef uint32_t __u32;

struct list_head {
    struct list_head *prev;
    struct list_head *next;
};

struct inode {
    unsigned long i_ino;
    struct super_block *i_sb;
};

struct ext4_super_block {
    uint32_t s_last_orphan;
};

struct buffer_head {
    int dummy;
};

struct journal_s {
    int dummy;
};

struct super_block {
    int dummy;
};

struct ext4_inode_info {
    struct inode vfs_inode;
    struct list_head i_orphan;
    uint32_t i_dtime;
};

struct ext4_sb_info {
    pthread_mutex_t s_orphan_lock;
    struct buffer_head *s_sbh;
    struct ext4_super_block *s_es;
    struct list_head s_orphan;
    struct journal_s *s_journal;
};

struct ext4_iloc {
    struct buffer_head *bh;
};

#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))
#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb))
#define NEXT_ORPHAN(inode) (EXT4_I(inode)->i_dtime)
#define jbd_debug(level, fmt, ...)
#define BUFFER_TRACE(bh, msg)
#define cpu_to_le32(x) (x)

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

static inline void list_del_init(struct list_head *entry) {
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
    entry->next = entry->prev = entry;
}

static inline void mutex_lock(pthread_mutex_t *mutex) {
    pthread_mutex_lock(mutex);
}

static inline void mutex_unlock(pthread_mutex_t *mutex) {
    pthread_mutex_unlock(mutex);
}

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))

static inline int ext4_handle_valid(handle_t *handle) { return 0; }
static inline int ext4_reserve_inode_write(handle_t *handle, struct inode *inode, struct ext4_iloc *iloc) { return 0; }
static inline int ext4_journal_get_write_access(handle_t *handle, struct buffer_head *bh) { return 0; }
static inline int ext4_handle_dirty_super(handle_t *handle, struct super_block *sb) { return 0; }
static inline int ext4_mark_iloc_dirty(handle_t *handle, struct inode *inode, struct ext4_iloc *iloc) { return 0; }
static inline void ext4_std_error(struct super_block *sb, int err) {}
static inline void brelse(struct buffer_head *bh) {}