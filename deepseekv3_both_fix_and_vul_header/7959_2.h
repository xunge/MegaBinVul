#include <stddef.h>
#include <sys/types.h>
#include <linux/fs.h>
#include <linux/posix_acl.h>

typedef unsigned int __u32;
typedef __u32 __be32;

#define NFSD_MAY_SATTR 0x1000
#define NFS4_ACL_DIR 0x01
#define EINVAL 22
#define EOPNOTSUPP 95

#define S_ISDIR(mode) ((mode) & 040000)
#define IS_POSIXACL(inode) (1)

struct svc_rqst;
struct svc_fh {
    struct dentry *fh_dentry;
};
struct nfs4_acl;
struct dentry;
struct inode {
    unsigned int i_mode;
    struct inode_operations *i_op;
};
struct inode_operations {
    int (*set_acl)(struct inode *, void *, int);
};
struct posix_acl;

__be32 fh_verify(struct svc_rqst *, struct svc_fh *, int, int);
struct inode *d_inode(struct dentry *);
int nfs4_acl_nfsv4_to_posix(struct nfs4_acl *, struct posix_acl **, struct posix_acl **, unsigned int);
void posix_acl_release(struct posix_acl *);
__be32 nfserr_attrnotsupp;
__be32 nfserrno(int);