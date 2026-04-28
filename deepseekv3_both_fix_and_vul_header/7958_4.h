#include <stdint.h>
#include <stddef.h>

typedef uint32_t __be32;

struct inode {
    struct inode_operations *i_op;
};

struct inode_operations {
    int (*set_acl)(struct inode *, void *, int);
};

struct dentry {
    struct inode *d_inode;
};

struct svc_fh {
    struct dentry *fh_dentry;
};

struct svc_rqst;
struct nfsd3_setaclargs {
    struct svc_fh fh;
    void *acl_access;
    void *acl_default;
};
struct nfsd_attrstat {
    struct svc_fh fh;
    void *stat;
};
struct posix_acl;

#define SVCFH_fmt(fh) ""
#define dprintk(fmt, ...) 
#define IS_POSIXACL(inode) (0)
#define NFSD_MAY_SATTR (0)
#define ACL_TYPE_ACCESS (0)
#define ACL_TYPE_DEFAULT (0)
#define EOPNOTSUPP 95

static inline struct inode *d_inode(struct dentry *dentry) { return dentry ? dentry->d_inode : NULL; }
static inline __be32 fh_verify(struct svc_rqst *rqstp, struct svc_fh *fh, int mode, int flags) { return 0; }
static inline struct svc_fh *fh_copy(struct svc_fh *dst, const struct svc_fh *src) { return dst; }
static inline int fh_want_write(struct svc_fh *fh) { return 0; }
static inline void fh_drop_write(struct svc_fh *fh) {}
static inline __be32 fh_getattr(struct svc_fh *fh, void *stat) { return 0; }
static inline __be32 nfserrno(int err) { return 0; }
static inline void posix_acl_release(struct posix_acl *acl) {}

/* Fix for 'svc_fh' type usage */
typedef struct svc_fh svc_fh;