#include <stddef.h>
#include <errno.h>
#include <sys/types.h>

#define EXT4_HT_INODE 1
#define AOP_FLAG_NOFS 1
#define ENOSPC 28
#define ENOMEM 12

struct address_space;
struct page;
struct buffer_head;
struct inode {
    void *i_sb;
};

struct ext4_iloc {
    struct buffer_head *bh;
};

struct ext4_inode_info {
    void *xattr_sem;
};

typedef void *handle_t;

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000)
#define PTR_ERR(x) ((long)(x))
#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))
#define PageUptodate(page) (1)