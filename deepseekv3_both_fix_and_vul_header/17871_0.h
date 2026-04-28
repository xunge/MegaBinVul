#include <stdlib.h>

struct nfs_write_data {
    struct {
        struct nfs_open_context *context;
    } args;
};

struct nfs_open_context;

void put_nfs_open_context(struct nfs_open_context *context);
void nfs_writedata_free(struct nfs_write_data *wdata);