#include <stddef.h>
#include <errno.h>
#include <fcntl.h>

struct inode {
    struct {
        char *s_id;
    } *i_sb;
    long i_ino;
};

struct dentry {
    struct {
        char *name;
        unsigned int len;
    } d_name;
    void *d_op;
};

struct nameidata {
    unsigned int flags;
    struct {
        struct {
            int flags;
        } open;
    } intent;
};

struct nfs_server {
    unsigned int namelen;
};

struct nfs_client {
    void *dentry_ops;
};

#define dfprintk(facility, format, args...)
#define VFS 0
#define NFS_SERVER(inode) ((struct nfs_server *)0)
#define NFS_PROTO(inode) ((struct nfs_client *)0)
#define is_atomic_open(nd) (0)
#define LOOKUP_EXCL (1 << 0)
#define ERR_PTR(err) ((void*)(long)(err))
#define PTR_ERR(ptr) ((long)(ptr))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)
#define d_instantiate(dentry, inode)
#define ENAMETOOLONG 36
#define ENOENT 2
#define EISDIR 21
#define ENOTDIR 20
#define ELOOP 40

static struct dentry *nfs4_atomic_open(struct inode *dir, struct dentry *dentry, struct nameidata *nd) { return NULL; }
static struct dentry *nfs_lookup(struct inode *dir, struct dentry *dentry, struct nameidata *nd) { return NULL; }