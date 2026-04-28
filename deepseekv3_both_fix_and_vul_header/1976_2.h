#include <stddef.h>
#include <sys/types.h>

#define NFS4ACL_MAXPAGES 1
#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define GFP_KERNEL 0
#define ENOMEM 12
#define ERANGE 34
#define NFS4_ACL_LEN_REQUEST 1
#define NFSPROC4_CLNT_GETACL 0

struct page {
    void *data;
};

struct inode {
    unsigned long i_ino;
};

struct nfs_fh {
    unsigned char data[64];
    unsigned int size;
};

struct rpc_clnt {
    void *client;
};

struct nfs_server {
    struct rpc_clnt *client;
};

struct nfs_rpc_ops {
    int dummy;
};

struct nfs_getaclargs {
    struct nfs_fh fh;
    struct page **acl_pages;
    size_t acl_len;
    size_t acl_pgbase;
    struct {
        int dummy;
    } seq_args;
};

struct nfs_getaclres {
    size_t acl_len;
    unsigned int acl_flags;
    size_t acl_data_offset;
    struct page *acl_scratch;
    struct {
        int dummy;
    } seq_res;
};

struct rpc_message {
    const struct nfs_rpc_ops *rpc_proc;
    void *rpc_argp;
    void *rpc_resp;
};

extern struct nfs_rpc_ops nfs4_procedures[];
extern int nfs4_call_sync(struct rpc_clnt *clnt, struct nfs_server *server,
                         struct rpc_message *msg,
                         void *args,
                         void *res,
                         int cache_reply);
extern void nfs4_write_cached_acl(struct inode *inode, void *buf, size_t len);
extern void _copy_from_pages(void *buf, struct page **pages, size_t offset, size_t len);
extern int dprintk(const char *fmt, ...);

static inline struct nfs_server *NFS_SERVER(struct inode *inode) { 
    static struct nfs_server server;
    return &server;
}

static inline struct nfs_fh NFS_FH(struct inode *inode) {
    struct nfs_fh fh;
    return fh;
}

static inline struct page *alloc_page(int gfp) {
    static struct page page;
    return &page;
}

static inline void *page_address(struct page *page) {
    return page->data;
}

static inline void __free_page(struct page *page) {
}