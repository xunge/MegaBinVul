#include <errno.h>

struct inode;
struct file;
struct address_space;

struct page {
    struct address_space *mapping;
};

struct address_space {
    struct inode *host;
};

#define EIO 5

int is_bad_inode(struct inode *);
int fuse_do_readpage(struct file *, struct page *);
void fuse_invalidate_atime(struct inode *);
void unlock_page(struct page *);