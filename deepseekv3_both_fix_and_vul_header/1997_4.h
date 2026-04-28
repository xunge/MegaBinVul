#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include <limits.h>

#define FUSE_IOCTL_MAX_IOV 256
#define FUSE_MAX_PAGES_PER_REQ 32
#define PAGE_SIZE 4096
#define FUSE_IOCTL 1

struct file {
    void *private_data;
};

struct fuse_file {
    struct fuse_conn *fc;
    unsigned long fh;
    unsigned long nodeid;
};

struct fuse_conn {
    // minimal definition
};

struct fuse_req_header {
    int opcode;
    unsigned long nodeid;
    int error;
};

struct fuse_req {
    struct {
        struct fuse_req_header h;
        int numargs;
        struct {
            size_t size;
            void *value;
        } args[2];
        int argpages;
    } in;
    struct {
        int numargs;
        struct {
            size_t size;
            void *value;
        } args[2];
        int argpages;
        int argvar;
        struct fuse_req_header h;
    } out;
    struct page *pages[FUSE_MAX_PAGES_PER_REQ];
    int num_pages;
};

struct page {
    // minimal definition
};

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct fuse_ioctl_in {
    unsigned long fh;
    unsigned int cmd;
    unsigned long arg;
    unsigned int flags;
    size_t in_size;
    size_t out_size;
};

struct fuse_ioctl_out {
    long result;
    unsigned int flags;
    unsigned int in_iovs;
    unsigned int out_iovs;
};

#define GFP_KERNEL 0
#define __GFP_HIGHMEM 0
#define KM_USER0 0

#define _IOC_SIZE(nr) ((nr) >> 16)
#define _IOC_DIR(nr) ((nr) >> 8)
#define _IOC_WRITE 1U
#define _IOC_READ 2U

#define FUSE_IOCTL_UNRESTRICTED (1 << 0)
#define FUSE_IOCTL_RETRY (1 << 1)
#define FUSE_IOCTL_COMPAT (1 << 2)

#define ENOMEM 12
#define EIO 5

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

static inline size_t iov_length(const struct iovec *iov, unsigned long nr_segs)
{
    size_t len = 0;
    while (nr_segs-- > 0)
        len += (iov++)->iov_len;
    return len;
}

#define max_t(type, x, y) ({ type __x = (x); type __y = (y); __x > __y ? __x : __y; })
#define max(x, y) ((x) > (y) ? (x) : (y))
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *p) { free(p); }
static inline struct page *alloc_page(int flags) { return malloc(sizeof(struct page)); }
static inline void __free_page(struct page *page) { free(page); }
static inline void *page_address(struct page *page) { return page; }
static inline void *kmap_atomic(struct page *page, int type) { return page; }
static inline void kunmap_atomic(void *addr, int type) {}

static inline struct fuse_req *fuse_get_req(struct fuse_conn *fc) { return NULL; }
static inline void fuse_put_request(struct fuse_conn *fc, struct fuse_req *req) {}
static inline void fuse_request_send(struct fuse_conn *fc, struct fuse_req *req) {}
static inline int fuse_ioctl_copy_user(struct page **pages, struct iovec *iov, 
                                     unsigned int iovs, size_t size, bool to_user) { return 0; }
static inline int fuse_copy_ioctl_iovec(void *dst, void *src, size_t transferred,
                                      unsigned int iovs, bool compat) { return 0; }

#define __user