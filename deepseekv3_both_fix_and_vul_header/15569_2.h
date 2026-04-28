#include <stddef.h>
#include <stdint.h>
#include <errno.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct io_uring_buf_reg {
    uint32_t ring_entries;
};

struct io_uring_buf_ring {
    uint64_t resv[3];
};

struct io_buf_free {
    void *mem;
    struct hlist_node list;
};

struct io_ring_ctx {
    struct hlist_head io_buf_list;
};

struct io_buffer_list {
    void *buf_ring;
    int is_mapped;
    int is_mmap;
};

typedef unsigned int gfp_t;
#define GFP_KERNEL_ACCOUNT 0
#define __GFP_ZERO 0
#define __GFP_NOWARN 0
#define __GFP_COMP 0

static inline void hlist_add_head(struct hlist_node *n, struct hlist_head *h) {}
static inline unsigned int get_order(size_t size) { return 0; }
static inline void *kmalloc(size_t size, gfp_t flags) { return NULL; }
static inline void *io_mem_alloc(size_t size) { return NULL; }
static inline void io_mem_free(void *ptr) {}
static inline unsigned long __get_free_pages(gfp_t gfp_mask, unsigned int order) { return 0; }