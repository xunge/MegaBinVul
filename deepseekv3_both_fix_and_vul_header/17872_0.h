#include <stdlib.h>

struct nfs_open_context;
struct nfs_read_data {
    struct nfs_open_context *context;
    struct {
        struct nfs_open_context *context;
    } args;
};

void put_nfs_open_context(struct nfs_open_context *ctx);
void nfs_readdata_free(struct nfs_read_data *rdata);