#include <stdio.h>

#define KERN_ERR ""

struct ecryptfs_crypt_stat {
    int num_header_bytes_at_front;
};

struct inode;
struct dentry {
    struct inode *d_inode;
};

extern int ecryptfs_write_lower(struct inode *inode, char *virt, int offset, int size);