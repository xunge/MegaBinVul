#include <sys/types.h>
#include <errno.h>

typedef long loff_t;

struct address_space {
    struct inode *host;
};

struct file {
    struct address_space *f_mapping;
};

struct inode;
struct fuse_conn {
    int no_fsync;
};

#define FUSE_FSYNC 1

int get_fuse_conn(struct inode *inode);
int is_bad_inode(struct inode *inode);
void inode_lock(struct inode *inode);
void inode_unlock(struct inode *inode);
int file_write_and_wait_range(struct file *file, loff_t start, loff_t end);
void fuse_sync_writes(struct inode *inode);
int file_check_and_advance_wb_err(struct file *file);
int sync_inode_metadata(struct inode *inode, int wait);
int fuse_fsync_common(struct file *file, loff_t start, loff_t end, int datasync, int opcode);