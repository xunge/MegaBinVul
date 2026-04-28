#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>

#define NFS4ACL_MAXPAGES 1
#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define ENOMEM 12
#define ERANGE 34
#define GFP_KERNEL 0
#define NFSPROC4_CLNT_GETACL 0
#define NFS4_ACL_LEN_REQUEST 0x0001

struct page {
    void *data;
};

struct inode;
struct nfs_fh {
    int dummy;
};

struct nfs_getaclargs {
    struct nfs_fh fh;
    struct page **acl_pages;
    size_t acl_len;
    struct page *acl_scratch;
    unsigned int acl_pgbase;
    void *seq_args;
};

struct nfs_getaclres {
    size_t acl_len;
    unsigned int acl_flags;
    unsigned int acl_data_offset;
    void *seq_res;
};

struct rpc_message {
    void *rpc_proc;
    void *rpc_argp;
    void *rpc_resp;
};

struct rpc_procinfo {
    int dummy;
};

struct nfs_server {
    void *client;
};

struct rpc_clnt;

#define NFS_FH(inode) ((struct nfs_fh){0})
#define NFS_SERVER(inode) ((struct nfs_server *)NULL)
#define dprintk(fmt, ...) do {} while (0)

extern struct rpc_procinfo nfs4_procedures[];
extern void nfs4_write_cached_acl(struct inode *inode, void *buf, size_t len);
extern int nfs4_call_sync(struct rpc_clnt *clnt, struct nfs_server *server,
                         struct rpc_message *msg, void *arg, void *res, int cache_reply);
extern void _copy_from_pages(void *buf, struct page **pages, unsigned int offset, unsigned int len);
extern struct page *alloc_page(int flags);
extern void __free_page(struct page *page);
extern void *page_address(struct page *page);