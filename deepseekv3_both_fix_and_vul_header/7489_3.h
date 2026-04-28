#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <stdint.h>

typedef long ssize_t;

struct cachefiles_volume {
    struct dentry *dentry;
    struct cachefiles_vcookie *vcookie;
    struct cachefiles_cache *cache;
};

struct cachefiles_vcookie {
    unsigned int coherency_len;
    const void *coherency;
};

struct cachefiles_vol_xattr {
    uint32_t reserved;
    char data[0];
};

struct cachefiles_xattr {
    char data[0];
};

struct cachefiles_cache;
struct dentry {
    struct inode *d_inode;
};
struct inode {
    unsigned long i_ino;
};
struct user_namespace;

enum cachefiles_coherency_trace {
    cachefiles_coherency_vol_check_xattr,
    cachefiles_coherency_vol_check_resv,
    cachefiles_coherency_vol_check_cmp,
    cachefiles_coherency_vol_check_ok
};

#define GFP_KERNEL 0
#define ENOMEM 12
#define ESTALE 116
#define EIO 5

#define cpu_to_be32(x) (x)

extern const char cachefiles_xattr_cache[];
extern struct user_namespace init_user_ns;
extern int cachefiles_trace_getxattr_error;

void *kmalloc(size_t size, int flags);
void kfree(const void *objp);
ssize_t vfs_getxattr(struct user_namespace *ns, struct dentry *dentry, const char *name, void *value, size_t size);
ssize_t cachefiles_inject_read_error(void);
void trace_cachefiles_vfs_error(void *obj, struct inode *inode, ssize_t error, int trace);
void trace_cachefiles_vol_coherency(struct cachefiles_volume *volume, unsigned long ino, enum cachefiles_coherency_trace why);
void cachefiles_io_error(struct cachefiles_cache *cache, const char *fmt, ...);
void _enter(const char *fmt, ...);
void _leave(const char *fmt, ...);
struct inode *d_inode(const struct dentry *dentry);