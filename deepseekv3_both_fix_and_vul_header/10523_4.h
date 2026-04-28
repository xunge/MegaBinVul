#include <sys/types.h>
#include <stddef.h>

struct file;
struct page;

struct address_space {
    struct inode *host;
};

struct inode {
    loff_t i_size;
    unsigned int i_nlink;
};

struct handle_t;

#define EXT4_STATE_ORDERED_MODE 0

struct handle_t *ext4_journal_current_handle(void);
int ext4_test_inode_state(struct inode *inode, int mode);
int ext4_jbd2_file_inode(struct handle_t *handle, struct inode *inode);
void unlock_page(struct page *page);
void put_page(struct page *page);
int ext4_has_inline_data(struct inode *inode);
int ext4_write_inline_data_end(struct inode *inode, loff_t pos, unsigned len, unsigned copied, struct page *page);
int block_write_end(struct file *file, struct address_space *mapping, loff_t pos, unsigned len, unsigned copied, struct page *page, void *fsdata);
int ext4_update_inode_size(struct inode *inode, loff_t new_size);
void pagecache_isize_extended(struct inode *inode, loff_t from, loff_t to);
void ext4_mark_inode_dirty(struct handle_t *handle, struct inode *inode);
int ext4_can_truncate(struct inode *inode);
void ext4_orphan_add(struct handle_t *handle, struct inode *inode);
int ext4_journal_stop(struct handle_t *handle);
void ext4_truncate_failed_write(struct inode *inode);
void ext4_orphan_del(void *unused, struct inode *inode);

typedef struct handle_t handle_t;