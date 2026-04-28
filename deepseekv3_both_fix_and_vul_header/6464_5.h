#include <stddef.h>
#include <stdint.h>

#define PAGE_SIZE 4096
#define PAGE_SHIFT 12
#define WRITE 0
#define EINVAL 22
#define ENOMEM 12
#define EFAULT 14
#define BIO_USER_MAPPED (1 << 0)

#define ERR_PTR(err) ((void *)(long)(err))
#define unlikely(x) (x)

typedef unsigned int gfp_t;

struct page;
struct bio_vec {
    struct page *bv_page;
    unsigned int bv_len;
    unsigned int bv_offset;
};

struct bio {
    unsigned short bi_vcnt;
    struct bio_vec *bi_io_vec;
    unsigned long bi_flags;
};

struct request_queue {
    unsigned int dma_alignment;
};

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct iov_iter {
    int type;
    const struct iovec *iov;
    int iov_count;
    size_t iov_offset;
};

static inline unsigned int queue_dma_alignment(const struct request_queue *q)
{
    return q->dma_alignment;
}

static inline void bio_set_flag(struct bio *bio, unsigned long flag)
{
    bio->bi_flags |= flag;
}

static inline void bio_get(struct bio *bio) {}
static inline void bio_put(struct bio *bio) {}

static inline int bio_add_pc_page(struct request_queue *q, struct bio *bio,
                struct page *page, unsigned int len, unsigned int offset)
{
    return 0;
}

static inline struct bio *bio_kmalloc(gfp_t gfp_mask, unsigned int nr_iovecs)
{
    return NULL;
}

static inline int get_user_pages_fast(unsigned long start, int nr_pages,
                    int write, struct page **pages)
{
    return 0;
}

static inline void put_page(struct page *page) {}
static inline void kfree(void *p) {}
static inline void *kcalloc(size_t n, size_t size, gfp_t flags) { return NULL; }

static inline size_t offset_in_page(unsigned long uaddr)
{
    return uaddr & (PAGE_SIZE - 1);
}

#define iov_for_each(iov, iter, data) \
    for (const struct iovec *__iov = (data).iov; (iov = *__iov), iov.iov_base; __iov++)

#define bio_for_each_segment_all(bvl, bio, i) \
    for (i = 0, bvl = bio->bi_io_vec; i < bio->bi_vcnt; i++, bvl++)