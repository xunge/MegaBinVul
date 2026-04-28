#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

struct pipe_inode_info;
struct file {
    struct address_space *f_mapping;
    struct dentry *f_dentry;
    unsigned int f_flags;
};
struct address_space {
    struct inode *host;
};
struct inode;
struct dentry;

#define unlikely(x) (x)
#define IS_SYNC(inode) (0)
#define OSYNC_METADATA 0
#define OSYNC_DATA 0

ssize_t __splice_from_pipe(struct pipe_inode_info *pipe, struct file *out, loff_t *ppos, size_t len, unsigned int flags, void *pipe_to_file);
int remove_suid(struct dentry *dentry);
int generic_osync_inode(struct inode *inode, struct address_space *mapping, int flags);

void *pipe_to_file;