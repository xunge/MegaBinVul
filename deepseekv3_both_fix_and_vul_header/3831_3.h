#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <stddef.h>

typedef uint32_t __be32;
typedef uint32_t __u32;
typedef unsigned short umode_t;

#define ATTR_MODE (1 << 0)
#define NFSD_MAY_CREATE 0x20
#define S_IALLUGO 07777
#define EINVAL 22

#define KERN_WARNING "<3>"
#define WARN_ONCE(cond, fmt, ...)
#define unlikely(x) (x)
#define IS_ERR(x) 0
#define PTR_ERR(x) 0

struct svc_rqst;
struct svc_fh {
    struct dentry *fh_dentry;
    void *fh_export;
    bool fh_locked;
};
struct iattr {
    unsigned int ia_valid;
    umode_t ia_mode;
};
struct dentry {
    struct dentry *d_parent;
    struct {
        char *name;
        unsigned int len;
    } d_name;
};
struct inode;

static inline struct inode *d_inode(const struct dentry *dentry) { return NULL; }
static inline struct dentry *dget(struct dentry *dentry) { return NULL; }
static inline int d_unhashed(const struct dentry *dentry) { return 0; }
static inline int d_is_negative(const struct dentry *dentry) { return 0; }
static inline void dput(struct dentry *dentry) {}

static __be32 nfserr_io = 0;
static __be32 nfserr_serverfault = 0;

static __be32 nfsd_permission(struct svc_rqst *rqstp, void *export, struct dentry *dentry, int mask) { return 0; }
static int vfs_create(struct inode *dir, struct dentry *dentry, umode_t mode, bool excl) { return 0; }
static void nfsd_check_ignore_resizing(struct iattr *iap) {}
static int vfs_mkdir(struct inode *dir, struct dentry *dentry, umode_t mode) { return 0; }
static struct dentry *lookup_one_len(const char *name, struct dentry *base, unsigned len) { return NULL; }
static int vfs_mknod(struct inode *dir, struct dentry *dentry, umode_t mode, dev_t dev) { return 0; }
static __be32 nfsd_create_setattr(struct svc_rqst *rqstp, struct svc_fh *fhp, struct iattr *iap) { return 0; }
static int commit_metadata(struct svc_fh *fhp) { return 0; }
static __be32 nfserrno(int err) { return 0; }
static __be32 fh_update(struct svc_fh *fhp) { return 0; }
static int printk(const char *fmt, ...) { return 0; }