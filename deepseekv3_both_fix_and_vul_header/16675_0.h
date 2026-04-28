#include <stddef.h>
#include <stdint.h>

struct inode;
struct fuse_inode {
    unsigned long state;
};

#define FUSE_I_BAD 0

static inline struct fuse_inode *get_fuse_inode(struct inode *inode) {
    return (struct fuse_inode *)inode;
}