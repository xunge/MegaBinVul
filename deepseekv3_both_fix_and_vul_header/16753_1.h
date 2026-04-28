#include <stdint.h>
#include <errno.h>
#include <stddef.h>

struct inode;
struct dentry;

struct fuse_conn {
    unsigned no_rename2:1;
    unsigned minor;
};

struct fuse_rename2_in {
    uint64_t padding;
};

struct fuse_rename_in {
    uint64_t padding;
};

#define RENAME_NOREPLACE (1 << 0)
#define RENAME_EXCHANGE  (1 << 1)
#define RENAME_WHITEOUT  (1 << 2)

#define FUSE_RENAME2 0
#define FUSE_RENAME 0

#define EINVAL 22
#define ENOSYS 38

static struct fuse_conn *get_fuse_conn(struct inode *inode);
static int fuse_rename_common(struct inode *olddir, struct dentry *oldent,
                             struct inode *newdir, struct dentry *newent,
                             unsigned int flags, int opcode, size_t out_size);