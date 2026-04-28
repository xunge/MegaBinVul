#include <stdint.h>
#include <stddef.h>

typedef uint32_t __be32;

struct svc_rqst;
struct posix_acl;

struct dentry {
    struct inode *d_inode;
};

struct inode {
    struct inode_operations *i_op;
};

struct inode_operations {
    int (*set_acl)(struct inode *, struct posix_acl *, int);
};

struct svc_fh {
    struct dentry *fh_dentry;
};

struct nfsd3_setaclargs {
    struct svc_fh fh;
    struct posix_acl *acl_access;
    struct posix_acl *acl_default;
};

struct nfsd3_attrstat {
    struct svc_fh fh;
};

#define NFSD_MAY_SATTR 0
#define ACL_TYPE_ACCESS 0
#define ACL_TYPE_DEFAULT 0
#define EOPNOTSUPP 0
#define IS_POSIXACL(inode) (0)

#define RETURN_STATUS(status) return (status)

static inline struct inode *d_inode(struct dentry *dentry) { return dentry ? dentry->d_inode : NULL; }

static inline __be32 fh_verify(struct svc_rqst *rqstp, struct svc_fh *fh, int mode, int flags) { return 0; }
static inline struct svc_fh *fh_copy(struct svc_fh *dst, struct svc_fh *src) { return dst; }
static inline int fh_want_write(struct svc_fh *fh) { return 0; }
static inline void fh_drop_write(struct svc_fh *fh) {}
static inline __be32 nfserrno(int err) { return 0; }
static inline void posix_acl_release(struct posix_acl *acl) {}

typedef struct svc_fh svc_fh;