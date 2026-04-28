#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

struct inode;

struct nfs_fh {
    int dummy;
};

struct nfs_server {
    void *client;
};

struct nfs_fattr {
    unsigned int valid;
};

struct nfs4_label {
    size_t len;
    void *label;
};

struct nfs_rpc_ops {
    int dummy;
};

struct nfs4_getattr_arg {
    struct nfs_fh fh;
    u32 *bitmask;
    void *seq_args;
};

struct nfs4_getattr_res {
    struct nfs_fattr *fattr;
    struct nfs4_label *label;
    struct nfs_server *server;
    void *seq_res;
};

struct rpc_message {
    struct nfs_rpc_ops *rpc_proc;
    void *rpc_argp;
    void *rpc_resp;
};

#define NFS_ATTR_FATTR_V4_SECURITY_LABEL (1 << 0)
#define FATTR4_WORD2_SECURITY_LABEL (1 << 0)
#define NFSPROC4_CLNT_GETATTR 0
#define ENOENT 2
#define ERANGE 34

#define NFS_SERVER(inode) ((struct nfs_server *)0)
#define NFS_FH(inode) ((struct nfs_fh){0})

extern struct nfs_rpc_ops nfs4_procedures[];
extern void nfs_fattr_init(struct nfs_fattr *);
extern int nfs4_call_sync(void *, struct nfs_server *, struct rpc_message *, void *, void *, int);