#include <stddef.h>

struct rpc_procinfo {
    int dummy;
};

struct rpc_message {
    struct rpc_procinfo *rpc_proc;
    void *rpc_argp;
    void *rpc_cred;
};

struct rpc_cred {
    int dummy;
};

struct nfs4_cb_conn {
    void *cb_client;
    struct rpc_cred *cb_cred;
};

struct nfs4_client {
    struct nfs4_cb_conn cl_cb_conn;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

enum {
    NFSPROC4_CLNT_CB_NULL,
    RPC_TASK_SOFT
};

extern struct rpc_procinfo nfs4_cb_procedures[];
extern struct rpc_cred *callback_cred;
extern struct rpc_cred *lookup_cb_cred(struct nfs4_cb_conn *);
extern void warn_no_callback_path(struct nfs4_client *, int);
extern void put_nfs4_client(struct nfs4_client *);
extern int rpc_call_async(void *, struct rpc_message *, int, const void *, void *);
extern const void nfsd4_cb_probe_ops;