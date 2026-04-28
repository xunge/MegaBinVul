#include <fcntl.h>
#include <stddef.h>
#include <sys/types.h>

struct file {
    int f_flags;
};

struct inode {
    struct file_lock *i_flock;
};

struct file_lock {
    off_t fl_start;
    off_t fl_end;
    unsigned char fl_type;
};

struct page;

#define FMODE_WRITE 0
#define F_RDLCK 0
#define OFFSET_MAX (~0ULL)

struct nfs_rpc_ops {
    int (*have_delegation)(struct inode *, int);
};

#define NFS_PROTO(inode) ((struct nfs_rpc_ops *)0)

static int nfs_write_pageuptodate(struct page *page, struct inode *inode);