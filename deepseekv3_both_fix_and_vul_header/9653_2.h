#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

struct posix_acl {
    int dummy;
};

struct dentry {
    struct inode *d_inode;
};

struct inode {
    int dummy;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

static struct posix_acl *posix_acl_from_xattr(const void *value, size_t size) {
    return NULL;
}

static int btrfs_set_acl(void *a, struct inode *b, struct posix_acl *c, int d) {
    return 0;
}

static void posix_acl_release(struct posix_acl *acl) {
}