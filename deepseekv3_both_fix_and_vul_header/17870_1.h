#include <stdlib.h>

struct nfs_write_data {
    void **pagevec;
    void *page_array[0];
};

extern void *nfs_wdata_mempool;

#define kfree free
#define mempool_free(p, pool) free(p)