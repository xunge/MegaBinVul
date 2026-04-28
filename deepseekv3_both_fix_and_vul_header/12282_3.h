#include <stddef.h>

#define AIO_RING_MAGIC 0xa10a10a1
#define SB_I_NOEXEC 0x00001000
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)

struct dentry;
struct super_block {
    unsigned long s_iflags;
};
struct file_system_type;

struct dentry_operations {
    char *(*d_dname)(struct dentry *, char *, int);
};

static char *simple_dname(struct dentry *dentry, char *buffer, int buflen) {
    return buffer;
}

static struct dentry *mount_pseudo(struct file_system_type *fs_type, const char *name,
                                 void *data, const struct dentry_operations *ops,
                                 unsigned long magic) {
    return (struct dentry *)0;
}

struct dentry {
    struct super_block *d_sb;
};