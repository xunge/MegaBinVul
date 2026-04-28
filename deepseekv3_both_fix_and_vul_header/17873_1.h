#include <stdlib.h>

struct nfs_read_data {
    void **pagevec;
    void *page_array[0];
};

extern void *nfs_rdata_mempool;

#define kfree free
#define mempool_free(pool, ptr) free(ptr)