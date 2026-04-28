#include <stdint.h>
#include <pthread.h>
#include <stdbool.h>

typedef uint32_t ext4_lblk_t;

struct inode {
    unsigned long i_ino;
    struct super_block *i_sb;
};

struct super_block {
    void *s_fs_info;
};

struct extent_status {
    ext4_lblk_t es_lblk;
    ext4_lblk_t es_len;
};

struct ext4_sb_info {
    unsigned long s_mount_state;
};

struct ext4_inode_info {
    pthread_rwlock_t i_es_lock;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb)->s_fs_info)
#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))
#define EXT4_FC_REPLAY 0x0001
#define BUG_ON(condition) do { if (condition) {} } while (0)

void trace_ext4_es_remove_extent(struct inode *inode, ext4_lblk_t lblk, ext4_lblk_t len);
void es_debug(const char *fmt, ...);
struct extent_status *__es_alloc_extent(bool);
int __es_remove_extent(struct inode *inode, ext4_lblk_t lblk, ext4_lblk_t end, int *reserved, struct extent_status *es);
void __es_free_extent(struct extent_status *es);
void ext4_es_print_tree(struct inode *inode);
void ext4_da_release_space(struct inode *inode, int reserved);

static inline void write_lock(pthread_rwlock_t *lock) { pthread_rwlock_wrlock(lock); }
static inline void write_unlock(pthread_rwlock_t *lock) { pthread_rwlock_unlock(lock); }