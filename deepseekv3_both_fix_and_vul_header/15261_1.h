#include <stddef.h>

struct rpc_procinfo {
    int dummy;
};

struct rpc_message {
    struct rpc_procinfo *rpc_proc;
    void *rpc_argp;
    void *rpc_cred;
};

struct nfs4_cb_conn {
    struct rpc_clnt *cb_client;
    void *cb_cred;
};

struct nfs4_client {
    struct nfs4_cb_conn cl_cb_conn;
};

struct nfs4_delegation {
    struct nfs4_client *dl_client;
    int dl_retries;
};

struct rpc_task_ops {
    int dummy;
};

extern struct rpc_procinfo nfs4_cb_procedures[];
extern void *callback_cred;
extern const struct rpc_task_ops nfsd4_cb_recall_ops;

enum {
    NFSPROC4_CLNT_CB_RECALL,
};

#define RPC_TASK_SOFT 0

void put_nfs4_client(struct nfs4_client *clp);
void nfs4_put_delegation(struct nfs4_delegation *dp);
int rpc_call_async(struct rpc_clnt *clnt, struct rpc_message *msg, int flags,
                   const struct rpc_task_ops *ops, void *data);