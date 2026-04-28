#include <stdbool.h>
#include <stddef.h>

typedef unsigned int ext4_lblk_t;
typedef unsigned long ext4_fsblk_t;

struct inode {
    unsigned long i_ino;
    struct super_block *i_sb;
    void *i_private;
};

struct super_block {
    void *s_fs_info;
};

struct rw_semaphore {
    // Minimal definition for compilation
    int dummy;
};

struct extent_status {
    ext4_lblk_t es_lblk;
    ext4_lblk_t es_len;
    ext4_fsblk_t es_pblk;
};

struct ext4_sb_info {
    unsigned long s_mount_state;
};

struct ext4_inode_info {
    struct rw_semaphore i_es_lock;
};

#define EXTENT_STATUS_DELAYED 0x1
#define EXT4_FC_REPLAY 0x1
#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb)->s_fs_info)
#define EXT4_I(inode) ((struct ext4_inode_info *)(inode)->i_private)

static inline void write_lock(struct rw_semaphore *lock) { (void)lock; }
static inline void write_unlock(struct rw_semaphore *lock) { (void)lock; }

void ext4_es_store_pblock_status(struct extent_status *es, ext4_fsblk_t pb, unsigned int status);
void es_debug(const char *fmt, ...);
void trace_ext4_es_insert_delayed_block(struct inode *inode, struct extent_status *es, bool allocated);
void ext4_es_insert_extent_check(struct inode *inode, struct extent_status *es);
struct extent_status *__es_alloc_extent(bool);
int __es_remove_extent(struct inode *inode, ext4_lblk_t lblk, ext4_lblk_t end, struct extent_status *left, struct extent_status *right);
int __es_insert_extent(struct inode *inode, struct extent_status *newes, struct extent_status *prealloc);
void __insert_pending(struct inode *inode, ext4_lblk_t lblk);
void __es_free_extent(struct extent_status *es);
void ext4_es_print_tree(struct inode *inode);
void ext4_print_pending_tree(struct inode *inode);