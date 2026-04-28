#include <sys/types.h>
#include <unistd.h>

#define PAGE_SHIFT 12

struct kiocb {
    struct file *ki_filp;
    loff_t ki_pos;
};

struct iov_iter;

struct file {
    void *private_data;
};

struct address_space {
    unsigned long nrpages;
};

struct inode {
    struct address_space *i_mapping;
};

ssize_t generic_write_checks(struct kiocb *iocb, struct iov_iter *from);
ssize_t p9_client_write(void *client, loff_t pos, struct iov_iter *from, int *err);
void invalidate_inode_pages2_range(struct address_space *mapping, unsigned long start, unsigned long end);
void inode_add_bytes(struct inode *inode, loff_t bytes);
void i_size_write(struct inode *inode, loff_t i_size);
loff_t i_size_read(const struct inode *inode);
struct inode *file_inode(struct file *file);