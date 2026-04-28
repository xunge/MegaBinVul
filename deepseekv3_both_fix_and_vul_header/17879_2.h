#include <stddef.h>

struct rpc_task {
    unsigned int tk_pid;
};

struct nfs_fh {
    unsigned char data[64];
};

struct nfs_fattr {
    unsigned int dummy;
};

struct nfs_writeverf {
    unsigned char data[8];
};

struct nfs_open_context {
    void *cred;
};

struct inode {
    unsigned long dummy;
};

struct nfs_direct_req {
    struct nfs_write_data *commit_data;
    struct inode *inode;
    struct nfs_open_context *ctx;
};

struct nfs_write_data {
    struct rpc_task task;
    struct inode *inode;
    struct {
        struct nfs_fh fh;
        unsigned long offset;
        unsigned int count;
        struct nfs_open_context *context;
    } args;
    struct {
        unsigned int count;
        struct nfs_fattr *fattr;
        struct nfs_writeverf *verf;
    } res;
    struct nfs_fattr fattr;
    struct nfs_writeverf verf;
    void *cred;
};

struct rpc_message {
    void *rpc_argp;
    void *rpc_resp;
    void *rpc_cred;
};

struct rpc_task_setup {
    struct rpc_task *task;
    void *rpc_client;
    struct rpc_message *rpc_message;
    const void *callback_ops;
    void *callback_data;
    void *workqueue;
    unsigned int flags;
};

struct nfs_commit_direct_ops {
    unsigned int dummy;
};

extern struct nfs_commit_direct_ops nfs_commit_direct_ops;
extern void *nfsiod_workqueue;

#define NFS_CLIENT(inode) NULL
#define NFS_FH(inode) (struct nfs_fh){}
#define IS_ERR(ptr) (0)
#define RPC_TASK_ASYNC (1U << 0)
#define dprintk(fmt, ...) 

struct nfs_open_context *get_nfs_open_context(struct nfs_open_context *ctx);
struct rpc_task *rpc_run_task(struct rpc_task_setup *setup);
void rpc_put_task(struct rpc_task *task);

struct nfs_client {
    int (*commit_setup)(struct nfs_write_data *, struct rpc_message *);
};

#define NFS_PROTO(inode) ((struct nfs_client *)NULL)