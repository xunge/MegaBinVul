#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

enum bpf_type {
    BPF_TYPE_UNSPEC,
    BPF_TYPE_PROG,
    BPF_TYPE_MAP,
    BPF_TYPE_LINK
};

struct filename {
    const char *name;
};

struct inode {
    void *i_private;
};

struct path {
    struct dentry *dentry;
};

struct dentry {
    struct inode *d_inode;
};

#define ERR_PTR(e) ((void *)(long)(e))
#define LOOKUP_FOLLOW 0
#define MAY_WRITE 0

static inline struct inode *d_backing_inode(struct dentry *dentry) {
    return dentry->d_inode;
}