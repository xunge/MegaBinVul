#include <stdint.h>

typedef uint32_t __be32;
typedef uint64_t u64;

struct dentry {
    struct inode *d_inode;
};

struct inode {
    u64 i_ino;
};

struct svc_export {
    struct {
        struct dentry *dentry;
    } ex_path;
};

struct svc_fh {
    struct dentry *fh_dentry;
    struct svc_export *fh_export;
};

struct nfsd3_readdirres {
    struct svc_fh fh;
};

#define nfserr_noent 0
#define IS_ERR(x) (0)
#define d_mountpoint(x) (0)
#define dget_parent(x) (x)
#define dget(x) (x)
#define dput(x) 
#define lookup_positive_unlocked(a,b,c) (0)
#define isdotent(a,b) (0)

__be32 fh_compose(struct svc_fh *fhp, struct svc_export *exp, struct dentry *dchild, struct svc_fh *fh);