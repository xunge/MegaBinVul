#include <string.h>

struct nfs_write_data;
struct nfs_direct_req;
struct inode;

#define NFS_ODIRECT_RESCHED_WRITES 0

#define dprintk(fmt, ...) do {} while (0)

struct task_struct {
    int tk_status;
    int tk_pid;
};

struct nfs_write_data {
    struct task_struct task;
    struct nfs_direct_req *req;
    struct inode *inode;
    void *verf;
};

struct nfs_direct_req {
    int flags;
    void *verf;
};

void nfs_direct_write_complete(struct nfs_direct_req *dreq, struct inode *inode);
void nfs_commitdata_release(void *calldata);