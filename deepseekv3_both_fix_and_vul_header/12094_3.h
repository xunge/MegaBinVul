#include <stddef.h>
#include <sys/types.h>
#include <stdint.h>

#define PAGE_SIZE 4096
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))

typedef unsigned int iov_iter_extraction_t;

struct page {
    // Minimal page structure definition
};

struct scatterlist {
    struct page *page;
    unsigned int offset;
    unsigned int length;
};

struct sg_table {
    struct scatterlist *sgl;
    unsigned int nents;
    unsigned int orig_nents;
};

#define min(a, b) ((a) < (b) ? (a) : (b))
#define min_t(type, x, y) ({ type __x = (x); type __y = (y); __x < __y ? __x : __y; })

static inline void sg_set_page(struct scatterlist *sg, struct page *page, size_t len, unsigned int offset) {
    sg->page = page;
    sg->length = len;
    sg->offset = offset;
}

static inline struct page *sg_page(struct scatterlist *sg) {
    return sg->page;
}

static inline void put_page(struct page *page) {
    // Placeholder for page reference counting
}

struct iov_iter {
    // Minimal iov_iter structure definition
};

ssize_t iov_iter_extract_pages(struct iov_iter *iter, struct page ***pages, 
                              ssize_t maxsize, unsigned int sg_max,
                              iov_iter_extraction_t extraction_flags, size_t *off);

#define array_size(a, b) ((a) * (b))