#include <stdbool.h>

struct inode {
    struct address_space *host;
};

struct address_space {
    struct inode *host;
};

struct page {
    struct address_space *mapping;
};

#define DATA 0

#define PageUptodate(page) (0)
#define SetPageUptodate(page) 
#define PageSwapCache(page) (0)
#define PageDirty(page) (0)

#define IS_ATOMIC_WRITTEN_PAGE(page) (0)

static inline struct address_space *page_file_mapping(struct page *page) { return page->mapping; }

int __set_page_dirty_nobuffers(struct page *page);
void trace_f2fs_set_page_dirty(struct page *page, int type);
bool f2fs_is_atomic_file(struct inode *inode);
bool f2fs_is_commit_atomic_write(struct inode *inode);
void f2fs_register_inmem_page(struct inode *inode, struct page *page);
void f2fs_update_dirty_page(struct inode *inode, struct page *page);