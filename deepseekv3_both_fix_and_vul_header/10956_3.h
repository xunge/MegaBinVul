#include <stdbool.h>
#include <stddef.h>

#define EAGAIN 11
#define DATA 0

struct inode;
struct file;
struct page;
struct address_space;

struct address_space {
    struct inode *host;
};

struct page {
    struct address_space *mapping;
};

static inline struct address_space *page_file_mapping(struct page *page)
{
    return page->mapping;
}

int f2fs_has_inline_data(struct inode *inode);
int f2fs_read_inline_data(struct inode *inode, struct page *page);
int f2fs_mpage_readpages(struct address_space *mapping, void *arg, struct page *page, int count, bool flag);
void trace_f2fs_readpage(struct page *page, int type);