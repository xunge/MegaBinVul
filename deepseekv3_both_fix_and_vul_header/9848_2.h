#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))

#define REQ_WRITE (1 << 0)

#define ENOMEM 12
#define EINVAL 22

#define ERR_PTR(err) ((void *)(long)(err))

struct page {
    unsigned long flags;
};

struct bio_vec {
    struct page *bv_page;
    unsigned int bv_len;
    unsigned int bv_offset;
};

struct bio {
    unsigned short bi_rw;
    struct bio_vec *bi_io_vec;
    int dummy;
};

struct request_queue {
    unsigned int bounce_gfp;
};

struct bio_map_data {
    int nr_pages;
    int iov_count;
    unsigned int gfp_mask;
};

struct rq_map_data {
    unsigned long offset;
    int page_order;
    int nr_entries;
    struct page **pages;
    int null_mapped;
    int from_user;
};

struct sg_iovec {
    void *iov_base;
    size_t iov_len;
};

typedef unsigned int gfp_t;

static inline struct bio_map_data *bio_alloc_map_data(int nr_pages, int iov_count, gfp_t gfp_mask) {
    return malloc(sizeof(struct bio_map_data));
}

static inline struct bio *bio_kmalloc(gfp_t gfp_mask, int nr_pages) {
    return malloc(sizeof(struct bio));
}

static inline struct page *alloc_page(gfp_t gfp_mask) {
    return malloc(sizeof(struct page));
}

static inline int bio_add_pc_page(struct request_queue *q, struct bio *bio, struct page *page, unsigned int bytes, unsigned int offset) {
    return bytes;
}

static inline int __bio_copy_iov(struct bio *bio, struct bio_vec *bvec, struct sg_iovec *iov, int iov_count, int i, int j, int k) {
    return 0;
}

static inline void bio_set_map_data(struct bio_map_data *bmd, struct bio *bio, struct sg_iovec *iov, int iov_count, int flag) {}

#define bio_for_each_segment(bvec, bio, i) for (i = 0; i < 1; i++)

static inline void __free_page(struct page *page) {
    free(page);
}

static inline void bio_put(struct bio *bio) {
    free(bio);
}

static inline void bio_free_map_data(struct bio_map_data *bmd) {
    free(bmd);
}