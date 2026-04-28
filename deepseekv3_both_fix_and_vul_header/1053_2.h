#include <stddef.h>
#include <fcntl.h>
#include <errno.h>

#define EOPENSTALE (-1000)
#define ATTR_OPEN (1 << 0)
#define ATTR_SIZE (1 << 1)

struct inode {
    void *i_mapping;
};

struct file {
    unsigned int f_flags;
    int f_mode;
};

struct dentry;
struct nfs_open_context;

struct iattr {
    unsigned int ia_valid;
    off_t ia_size;
};

struct nfs_protocol {
    struct inode *(*open_context)(struct inode *, struct nfs_open_context *, unsigned int, struct iattr *, void *);
};

#define NFS_PROTO(dir) ((struct nfs_protocol *)0)

struct nfs_open_context *alloc_nfs_open_context(struct dentry *, int, struct file *);
void put_nfs_open_context(struct nfs_open_context *);
void nfs_file_set_open_context(struct file *, struct nfs_open_context *);
void nfs_fscache_open_file(struct inode *, struct file *);
int nfs_check_flags(unsigned int);
int nfs_open(struct inode *, struct file *);
struct dentry *file_dentry(struct file *);
struct dentry *dget_parent(struct dentry *);
struct inode *d_inode(struct dentry *);
void dput(struct dentry *);
void d_drop(struct dentry *);
int IS_ERR(const void *);
long PTR_ERR(const void *);
void filemap_write_and_wait(void *);
void dprintk(const char *, ...);