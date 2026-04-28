#include <string.h>
#include <stdio.h>

#define NFS4_MAXNAMLEN 255
#define NFDIR 2
#define ENAMETOOLONG 36
#define ENOTDIR 20
#define EREMOTE 66
#define EINVAL 22
#define KERN_ERR ""

struct nfs_server {
    struct nfs_client *nfs_client;
    int fsid;
};
struct nfs_fh {
    unsigned char data[0];
};
struct nfs_fsinfo {
    struct nfs_fattr *fattr;
};
struct nfs_fattr {
    unsigned int type;
    unsigned int valid;
    int fsid;
};
struct qstr {
    const char *name;
    int len;
};
struct nfs_client {
    struct {
        int (*getroot)(struct nfs_server *, struct nfs_fh *, struct nfs_fsinfo *);
        int (*lookupfh)(struct nfs_server *, struct nfs_fh *, struct qstr *, struct nfs_fh *, struct nfs_fattr *);
    } *rpc_ops;
};

static inline void nfs_fattr_init(struct nfs_fattr *fattr) {}
#define dprintk(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define printk(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define NFS_ATTR_FATTR_V4_REFERRAL (1 << 0)