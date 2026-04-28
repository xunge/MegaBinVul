#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define RD_MAX_ALLOCATION_SIZE 4096
#define RDF_NULLIO 0x01
#define PAGE_SIZE 4096
#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22

typedef uint32_t u32;

struct scatterlist {
    unsigned long length;
    void *page_link;
};

struct page {
    unsigned long flags;
};

struct rd_dev_sg_table {
    struct scatterlist *sg_table;
    unsigned int rd_sg_count;
    unsigned int page_start_offset;
    unsigned int page_end_offset;
};

struct rd_dev {
    unsigned int rd_page_count;
    unsigned int rd_flags;
    struct rd_dev_sg_table *sg_table_array;
    unsigned int sg_table_count;
    struct {
        unsigned int rd_host_id;
    } *rd_host;
    unsigned int rd_dev_id;
};

#define pr_err(fmt, ...) 
#define pr_debug(fmt, ...) 

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *p) { free(p); }
static inline void sg_init_table(struct scatterlist *sg, unsigned int n) { memset(sg, 0, n * sizeof(*sg)); }
static inline void sg_assign_page(struct scatterlist *sg, struct page *page) { sg->page_link = (void *)page; }
static inline struct page *alloc_pages(int flags, unsigned int order) { return (struct page *)malloc(PAGE_SIZE); }