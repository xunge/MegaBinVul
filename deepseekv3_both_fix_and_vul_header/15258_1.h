struct rpc_cred;
struct auth_cred {
    int machine_cred;
};
struct rpc_clnt {
    struct rpc_auth *cl_auth;
};
struct nfs4_cb_conn {
    struct rpc_clnt *cb_client;
};
struct rpc_auth {
    struct rpc_authops *au_ops;
};
struct rpc_authops {
    struct rpc_cred *(*lookup_cred)(struct rpc_auth *, struct auth_cred *, int);
};
#define RPCAUTH_LOOKUP_NEW 0