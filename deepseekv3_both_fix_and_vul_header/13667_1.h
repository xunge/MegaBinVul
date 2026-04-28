#include <stdlib.h>
#include <stddef.h>

#define PAGE_SIZE 4096
#define GFP_KERNEL 0
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))

struct page {
    // dummy structure
};

struct scatterlist {
    // dummy structure
};

static inline void *kcalloc(size_t n, size_t size, int flags) {
    return calloc(n, size);
}

static inline void sg_init_table(struct scatterlist *sgl, unsigned int nents) {
    // dummy implementation
}

static inline unsigned int sg_nents(struct scatterlist *sgl) {
    return 0; // dummy implementation
}

static inline struct page *alloc_page(int flags) {
    return malloc(sizeof(struct page)); // dummy implementation
}

static inline struct page *sg_page(struct scatterlist *sg) {
    return NULL; // dummy implementation
}

static inline void __free_page(struct page *page) {
    free(page); // dummy implementation
}

static inline void sg_set_page(struct scatterlist *sg, struct page *page,
                             unsigned int len, unsigned int offset) {
    // dummy implementation
}

#define for_each_sg(sglist, sg, nr, __i) \
    for (__i = 0, sg = (sglist); __i < (nr); __i++, sg++)

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))