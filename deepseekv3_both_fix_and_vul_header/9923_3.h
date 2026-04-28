#include <stdbool.h>
#include <sys/types.h>

#define NFS4ACL_MAXPAGES 1
#define NFSPROC4_CLNT_SETACL 0
#define NFS_INO_INVALID_ATTR 0x0004
#define EOPNOTSUPP 95

struct page {
    // minimal page structure definition
    void *data;
};

struct inode {
    // minimal inode structure definition
    unsigned long i_lock;
};

struct nfs_fh {
    // minimal NFS file handle definition
    unsigned char data[64];
    unsigned int size;
};

struct nfs_server {
    // minimal NFS server definition
    int dummy;
};

struct nfs_inode {
    unsigned long cache_validity;
};

struct rpc_procinfo {
    // minimal RPC procedure info definition
    unsigned int p_proc;
};

struct rpc_message {
    const struct rpc_procinfo *rpc_proc;
    void *rpc_argp;
    void *rpc_resp;
};

struct nfs_setaclargs {
    struct nfs_fh fh;
    struct page **acl_pages;
    unsigned int acl_len;
    unsigned int acl_pgbase;
};

struct nfs_setaclres {
    int dummy;
};

#define NFS_SERVER(inode) ((struct nfs_server *)0)
#define NFS_FH(inode) ((struct nfs_fh){0})
#define NFS_I(inode) ((struct nfs_inode *)0)

static inline void spin_lock(unsigned long *lock) { (void)lock; }
static inline void spin_unlock(unsigned long *lock) { (void)lock; }

extern struct rpc_procinfo nfs4_procedures[];
extern int nfs4_call_sync(struct nfs_server *, struct rpc_message *, struct nfs_setaclargs *, struct nfs_setaclres *, int);
extern bool nfs4_server_supports_acls(struct nfs_server *);
extern void nfs_inode_return_delegation(struct inode *);
extern void buf_to_pages(const void *, size_t, struct page **, unsigned int *);
extern void nfs_access_zap_cache(struct inode *);
extern void nfs_zap_acl_cache(struct inode *);