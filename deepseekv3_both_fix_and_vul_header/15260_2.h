#include <stddef.h>

struct nfs4_client {
    struct {
        void *cb_client;
        void *cb_cred;
    } cl_cb_conn;
};

void rpc_shutdown_client(void *clnt);
void put_rpccred(void *cred);