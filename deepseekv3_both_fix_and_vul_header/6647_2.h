#include <stddef.h>
#include <limits.h>

struct rds_rdma_args {
    unsigned long local_vec_addr;
    unsigned int nr_local;
};

struct rds_iovec {
    unsigned long addr;
    size_t bytes;
};

struct scatterlist {
    unsigned long page_link;
    unsigned int offset;
    unsigned int length;
};

#define PAGE_SHIFT 12
#define EINVAL 22
#define EFAULT 14
#define __user

extern int copy_from_user(void *to, const void *from, unsigned long n);
extern unsigned int rds_pages_in_vec(struct rds_iovec *vec);