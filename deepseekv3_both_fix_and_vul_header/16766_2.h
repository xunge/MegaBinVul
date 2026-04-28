#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>

struct inode;
struct dentry {
    int dummy;
};
struct file {
    unsigned int f_mode;
};
struct fuse_conn {
    int no_create;
};

typedef unsigned short umode_t;

#define FMODE_CREATED 0x1
#define ENOSYS 38
#define O_CREAT 0x40

static struct fuse_conn *get_fuse_conn(struct inode *);
static int d_in_lookup(struct dentry *);
static struct dentry *fuse_lookup(struct inode *, struct dentry *, unsigned int);
static int PTR_ERR(const void *);
static int IS_ERR(const void *);
static int d_really_is_positive(struct dentry *);
static int fuse_create_open(struct inode *, struct dentry *, struct file *, unsigned, umode_t);
static void dput(struct dentry *);
static int fuse_mknod(struct inode *, struct dentry *, umode_t, unsigned int);
static int finish_no_open(struct file *, struct dentry *);