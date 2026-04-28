#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t ext4_lblk_t;
typedef uint64_t ext4_fsblk_t;

struct inode {
    unsigned long i_ino;
    void *i_sb;
    void *i_private;
};

struct extent_status {
    ext4_lblk_t es_lblk;
    ext4_lblk_t es_len;
    ext4_fsblk_t es_pblk;
};

struct ext4_sb_info {
    unsigned long s_mount_state;
    unsigned int s_cluster_ratio;
};

struct ext4_inode_info {
    void *i_es_lock;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb))
#define EXT4_I(inode) ((struct ext4_inode_info *)((inode)->i_private))
#define EXT4_FC_REPLAY 0x80000000
#define EXTENT_STATUS_DELAYED 0x01
#define EXTENT_STATUS_WRITTEN 0x02
#define EXTENT_STATUS_UNWRITTEN 0x04
#define ENOMEM 12
#define DELALLOC 1

#define es_debug(fmt, ...)
#define ext4_warning(sb, fmt, ...)
#define WARN_ON(cond)
#define BUG_ON(cond)
#define test_opt(sb, opt) 0
#define write_lock(lock)
#define write_unlock(lock)

static inline void ext4_es_store_pblock_status(struct extent_status *es, ext4_fsblk_t pblk, unsigned int status) {}
static inline void trace_ext4_es_insert_extent(struct inode *inode, struct extent_status *es) {}
static inline void ext4_es_insert_extent_check(struct inode *inode, struct extent_status *es) {}
static inline bool ext4_es_must_keep(struct extent_status *es) { return false; }
static inline void ext4_es_print_tree(struct inode *inode) {}

static struct extent_status *__es_alloc_extent(bool nofail) { return NULL; }
static void __es_free_extent(struct extent_status *es) {}
static int __es_remove_extent(struct inode *inode, ext4_lblk_t lblk, ext4_lblk_t end, void *arg, struct extent_status *es) { return 0; }
static int __es_insert_extent(struct inode *inode, struct extent_status *newes, struct extent_status *es) { return 0; }
static void __revise_pending(struct inode *inode, ext4_lblk_t lblk, ext4_lblk_t len) {}