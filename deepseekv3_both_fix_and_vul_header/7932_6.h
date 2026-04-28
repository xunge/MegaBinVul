#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef uint64_t u64;
typedef uint32_t u32;

#define ENOTCONN 107
#define EOPNOTSUPP 95
#define EINVAL 22
#define EMSGSIZE 90
#define ENOMEM 12
#define EFAULT 14

#define RDS_MAX_MSG_SIZE (1 << 30)
#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))

#define RDS_RDMA_USE_ONCE 1
#define RDS_RDMA_INVALIDATE 2
#define RDS_RDMA_READWRITE 4

typedef u64 rds_rdma_cookie_t;

struct page {
    unsigned long flags;
};

struct scatterlist {
    struct page *page;
    unsigned int length;
    unsigned int offset;
};

struct rds_iovec {
    u64 addr;
    u64 bytes;
};

struct rds_get_mr_args {
    struct rds_iovec vec;
    u64 cookie_addr;
    int flags;
};

struct rds_transport {
    void *(*get_mr)(struct scatterlist *, unsigned int, void *, u32 *);
};

struct rb_node {
    void *rb_left;
    void *rb_right;
};

struct rds_sock {
    u64 rs_bound_addr;
    struct rds_transport *rs_transport;
    struct rb_node rs_rdma_keys;
    void *rs_rdma_lock;
};

struct rds_mr {
    int r_refcount;
    struct rb_node r_rb_node;
    struct rds_transport *r_trans;
    void *r_sock;
    void *r_trans_private;
    u32 r_key;
    int r_use_once;
    int r_invalidate;
    int r_write;
};

#define GFP_KERNEL 0
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)
#define RB_CLEAR_NODE(node) ((node)->rb_left = NULL, (node)->rb_right = NULL)

static inline void *kcalloc(size_t n, size_t size, int flags) { return calloc(n, size); }
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *p) { free(p); }
static inline void refcount_set(int *ref, int value) { *ref = value; }
static inline void refcount_inc(int *ref) { (*ref)++; }
static inline void sg_init_table(struct scatterlist *sg, unsigned int nents) {}
static inline void sg_set_page(struct scatterlist *sg, struct page *page, unsigned int len, unsigned int offset) {
    sg->page = page;
    sg->length = len;
    sg->offset = offset;
}
static inline struct page *sg_page(struct scatterlist *sg) { return sg->page; }
static inline void put_page(struct page *page) {}
static inline void spin_lock_irqsave(void *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(void *lock, unsigned long flags) {}
static inline void BUG_ON(int condition) { if (condition) abort(); }
static inline void WARN_ON(int condition) { if (condition) fprintf(stderr, "Warning\n"); }
static inline int rds_pages_in_vec(struct rds_iovec *vec) { return 0; }
static inline int rds_pin_pages(u64 addr, unsigned int nr_pages, struct page **pages, int write) { return 0; }
static inline rds_rdma_cookie_t rds_rdma_make_cookie(u32 r_key, u64 offset) { return 0; }
static inline int put_user(u64 val, u64 *addr) { *addr = val; return 0; }
static inline void *rds_mr_tree_walk(struct rb_node *root, u32 key, void *mr) { return NULL; }
static inline void rds_mr_put(struct rds_mr *mr) {}
static inline void rdsdebug(const char *fmt, ...) {}

#define __user