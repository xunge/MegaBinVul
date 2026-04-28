#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

typedef struct handle_s handle_t;
typedef off_t loff_t;

struct inode {
    loff_t i_size;
    unsigned long i_nlink;
    void *i_private;
};

struct address_space {
    struct inode *host;
};

struct file {
    void *private_data;
};

struct page {
    void *private;
};

#define EXT4_STATE_MAY_INLINE_DATA 0

static inline bool ext4_verity_in_progress(struct inode *inode) { return false; }
static inline void trace_ext4_write_end(struct inode *inode, loff_t pos, unsigned len, unsigned copied) {}
static inline bool ext4_has_inline_data(struct inode *inode) { return false; }
static inline bool ext4_test_inode_state(struct inode *inode, int flag) { return false; }
static inline int ext4_write_inline_data_end(struct inode *inode, loff_t pos, unsigned len, unsigned copied, struct page *page) { return 0; }
static inline unsigned block_write_end(struct file *file, struct address_space *mapping, loff_t pos, unsigned len, unsigned copied, struct page *page, void *fsdata) { return 0; }
static inline int ext4_update_inode_size(struct inode *inode, loff_t new_size) { return 0; }
static inline void unlock_page(struct page *page) {}
static inline void put_page(struct page *page) {}
static inline void pagecache_isize_extended(struct inode *inode, loff_t old_size, loff_t new_size) {}
static inline int ext4_mark_inode_dirty(handle_t *handle, struct inode *inode) { return 0; }
static inline bool ext4_can_truncate(struct inode *inode) { return false; }
static inline void ext4_orphan_add(handle_t *handle, struct inode *inode) {}
static inline int ext4_journal_stop(handle_t *handle) { return 0; }
static inline void ext4_truncate_failed_write(struct inode *inode) {}
static inline void ext4_orphan_del(void *handle, struct inode *inode) {}
static inline handle_t *ext4_journal_current_handle(void) { return NULL; }