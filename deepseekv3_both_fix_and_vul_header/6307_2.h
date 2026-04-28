#include <stddef.h>
#include <stdint.h>

struct buffer_head;

struct inode {
    void *i_sb;
    // Other inode fields would be needed in a real implementation
};

struct page {
    // Page structure members would be needed in a real implementation
};

struct ext4_iloc {
    struct buffer_head *bh;
    unsigned long offset;
};

#define unlikely(x) (x)
#define BUG_ON(condition) ((void)0)
#define PageUptodate(page) (0)
#define SetPageUptodate(page) ((void)0)
#define ClearPageDirty(page) ((void)0)

typedef int64_t loff_t;

int ext4_get_inode_loc(struct inode *inode, struct ext4_iloc *iloc);
void ext4_std_error(void *sb, int err);
void ext4_write_lock_xattr(struct inode *inode, int *no_expand);
int ext4_has_inline_data(struct inode *inode);
void ext4_write_inline_data(struct inode *inode, struct ext4_iloc *iloc, void *kaddr, loff_t pos, unsigned len);
void ext4_write_unlock_xattr(struct inode *inode, int *no_expand);
void brelse(struct buffer_head *bh);
void mark_inode_dirty(struct inode *inode);
void *kmap_atomic(struct page *page);
void kunmap_atomic(void *addr);