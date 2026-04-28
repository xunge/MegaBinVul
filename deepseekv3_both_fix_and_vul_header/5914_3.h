#include <stdint.h>
#include <time.h>

typedef int64_t loff_t;
typedef uint32_t ext4_lblk_t;

struct rw_semaphore {
    int dummy;
};

struct inode {
    struct address_space *i_mapping;
    struct super_block *i_sb;
    loff_t i_size;
    unsigned long i_nlink;
    struct timespec i_mtime;
    struct timespec i_ctime;
};

struct super_block {
    unsigned long s_blocksize;
};

struct address_space {};

struct ext4_inode_info {
    unsigned long i_disksize;
    struct rw_semaphore i_data_sem;
};

struct handle_s {};
typedef struct handle_s handle_t;

#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))
#define IS_ERR(x) (0)
#define IS_SYNC(x) (0)
#define EXT_MAX_BLOCKS ((ext4_lblk_t) ~0)
#define EXT_MAX_BLOCK EXT_MAX_BLOCKS
#define EXT4_BLOCK_SIZE_BITS(sb) (9)

static inline void ext4_flush_completed_IO(struct inode *inode) {}
static inline int ext4_writepage_trans_blocks(struct inode *inode) { return 0; }
static inline handle_t *ext4_journal_start(struct inode *inode, int err) { return NULL; }
static inline void ext4_block_truncate_page(handle_t *handle, struct address_space *mapping, loff_t size) {}
static inline int ext4_orphan_add(handle_t *handle, struct inode *inode) { return 0; }
static inline void down_write(struct rw_semaphore *sem) {}
static inline void ext4_ext_invalidate_cache(struct inode *inode) {}
static inline void ext4_discard_preallocations(struct inode *inode) {}
static inline void ext4_mark_inode_dirty(handle_t *handle, struct inode *inode) {}
static inline int ext4_ext_remove_space(struct inode *inode, ext4_lblk_t start, ext4_lblk_t end) { return 0; }
static inline void ext4_handle_sync(handle_t *handle) {}
static inline void up_write(struct rw_semaphore *sem) {}
static inline void ext4_orphan_del(handle_t *handle, struct inode *inode) {}
static inline struct timespec ext4_current_time(struct inode *inode) { struct timespec ts = {0}; return ts; }
static inline void ext4_journal_stop(handle_t *handle) {}