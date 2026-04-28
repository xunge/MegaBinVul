#include <stddef.h>

struct nfs_read_data;
struct nfs_direct_req {
    int lock;
    int error;
    size_t count;
};

struct nfs_read_data {
    struct nfs_direct_req *req;
    struct {
        int tk_status;
    } task;
    struct {
        size_t count;
    } res;
    struct {
        unsigned int pgbase;
    } args;
    void **pagevec;
    unsigned int npages;
};

static void nfs_direct_dirty_pages(void **pagevec, unsigned int pgbase, size_t count);
static void nfs_direct_release_pages(void **pagevec, unsigned int npages);
static int put_dreq(struct nfs_direct_req *dreq);
static void nfs_direct_complete(struct nfs_direct_req *dreq);
static void nfs_readdata_release(void *calldata);