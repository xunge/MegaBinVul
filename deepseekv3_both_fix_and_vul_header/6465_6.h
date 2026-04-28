#include <stddef.h>
#include <stdint.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))

#define EINVAL 22
#define ENOMEM 12
#define EFAULT 14

#define WRITE 1
#define READ 0

#define BIO_USER_MAPPED (1 << 0)

#define ERR_PTR(err) ((void *)((long)(err)))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)
#define PTR_ERR(ptr) ((long)(ptr))

typedef unsigned int gfp_t;

struct request_queue;
struct bio {
    unsigned short bi_vcnt;
};
struct page;
struct iov_iter {
    int type;
    struct iovec *iov;
    int nr_segs;
    size_t count;
    size_t iov_offset;
};
struct iovec {
    void *iov_base;
    size_t iov_len;
};

#define iov_for_each(iov, iter, iter_ptr) \
    for (struct iov_iter *__iter = &(iter); \
         (iov = (__iter->iov_offset < __iter->iov->iov_len) ? \
          (struct iovec){__iter->iov->iov_base + __iter->iov_offset, \
                         __iter->iov->iov_len - __iter->iov_offset} : \
          (__iter->nr_segs > 1 ? \
           (__iter->iov++, __iter->nr_segs--, __iter->iov_offset = 0, \
            (struct iovec){__iter->iov->iov_base, __iter->iov->iov_len}) : \
           (struct iovec){NULL, 0})), \
         iov.iov_base; \
         iov_iter_advance(__iter, iov.iov_len))

static inline void iov_iter_advance(struct iov_iter *iter, size_t bytes)
{
    iter->iov_offset += bytes;
    iter->count -= bytes;
}

static inline unsigned long offset_in_page(unsigned long uaddr)
{
    return uaddr & (PAGE_SIZE - 1);
}

static inline void put_page(struct page *page) {}
static inline void bio_set_flag(struct bio *bio, unsigned int flag) {}
static inline void bio_get(struct bio *bio) {}
static inline void bio_put(struct bio *bio) {}
static inline struct bio *bio_kmalloc(gfp_t gfp_mask, unsigned int nr_iovecs) { return NULL; }
static inline int bio_add_pc_page(struct request_queue *q, struct bio *bio, struct page *page, unsigned int len, unsigned int offset) { return 0; }
static inline unsigned long queue_dma_alignment(const struct request_queue *q) { return 0; }
static inline int get_user_pages_fast(unsigned long start, int nr_pages, int write, struct page **pages) { return 0; }
static inline void *kcalloc(size_t n, size_t size, gfp_t flags) { return NULL; }
static inline void kfree(const void *objp) {}