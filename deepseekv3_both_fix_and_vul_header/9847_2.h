#include <stddef.h>
#include <stdlib.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))

#define EINVAL 22
#define ENOMEM 12
#define EFAULT 14

#define REQ_WRITE (1 << 0)
#define BIO_USER_MAPPED 10

struct page {
    unsigned long flags;
};

struct bio {
    unsigned int bi_rw;
    struct block_device *bi_bdev;
    unsigned long bi_flags;
};

struct request_queue;
struct block_device;

struct sg_iovec {
    void *iov_base;
    size_t iov_len;
};

typedef unsigned int gfp_t;

#define ERR_PTR(err) ((void *)((long)(err)))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)

static inline void *bio_kmalloc(gfp_t gfp_mask, int nr_pages) { return malloc(nr_pages * sizeof(struct page)); }
static inline void bio_put(struct bio *bio) { free(bio); }
static inline void *kcalloc(size_t n, size_t size, gfp_t flags) { return calloc(n, size); }
static inline void kfree(void *p) { free(p); }
static inline int queue_dma_alignment(struct request_queue *q) { return 511; }
static inline int bio_add_pc_page(struct request_queue *q, struct bio *bio, struct page *page, unsigned int len, unsigned int offset) { return len; }
static inline int get_user_pages_fast(unsigned long start, int nr_pages, int write, struct page **pages) { return nr_pages; }
static inline void page_cache_release(struct page *page) {}