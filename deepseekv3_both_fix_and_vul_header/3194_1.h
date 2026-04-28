#include <stddef.h>
#include <sys/types.h>

#define NFS4ACL_MAXPAGES 1
#define PAGE_SIZE 4096
#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define GFP_KERNEL 0
#define ENOMEM 12
#define ERANGE 34
#define NFS4_ACL_TRUNC 1

struct page {
    // Minimal page structure definition
};

struct nfs_fh {
    // Minimal NFS file handle definition
};

struct nfs4_sequence_args {
    // Minimal sequence args definition
};

struct nfs4_sequence_res {
    // Minimal sequence res definition
};

struct nfs_server {
    struct rpc_clnt *client;
};

struct rpc_procinfo {
    // Minimal rpc procedure info definition
};

struct rpc_message {
    const struct rpc_procinfo *rpc_proc;
    void *rpc_argp;
    void *rpc_resp;
};

struct nfs_getaclargs {
    struct nfs_fh fh;
    struct page **acl_pages;
    size_t acl_len;
    size_t acl_pgbase;
    struct nfs4_sequence_args seq_args;
};

struct nfs_getaclres {
    size_t acl_len;
    unsigned int acl_flags;
    struct page *acl_scratch;
    unsigned int acl_data_offset;
    struct nfs4_sequence_res seq_res;
};

struct inode {
    // Minimal inode definition
};

#define NFS_FH(inode) ((struct nfs_fh){})
#define NFS_SERVER(inode) ((struct nfs_server*)NULL)

static inline struct page *alloc_page(int flags) { return NULL; }
static inline void __free_page(struct page *page) {}
static inline void _copy_from_pages(void *buf, struct page **pages, unsigned int offset, size_t len) {}
static inline void nfs4_write_cached_acl(struct inode *inode, struct page **pages, unsigned int offset, size_t len) {}
static inline int nfs4_call_sync(struct rpc_clnt *clnt, struct nfs_server *server,
                                struct rpc_message *msg,
                                struct nfs4_sequence_args *args,
                                struct nfs4_sequence_res *res, int cache_reply) { return 0; }

extern const struct rpc_procinfo nfs4_procedures[];
#define NFSPROC4_CLNT_GETACL 0
#define dprintk(fmt, ...)