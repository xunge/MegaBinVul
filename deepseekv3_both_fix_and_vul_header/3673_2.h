#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef uint32_t u32;

struct page {
    // Minimal page structure placeholder
};

struct scatterlist {
    // Minimal scatterlist structure placeholder
    struct page *page_link;
    unsigned int offset;
    unsigned int length;
};

struct rd_dev_sg_table {
    struct scatterlist *sg_table;
    u32 rd_sg_count;
};

struct rd_host {
    u32 rd_host_id;
};

struct rd_dev {
    struct rd_dev_sg_table *sg_table_array;
    u32 sg_table_count;
    u32 rd_dev_id;
    struct rd_host *rd_host;
};

#define PAGE_SIZE 4096
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)

static inline struct page *sg_page(struct scatterlist *sg) {
    return sg->page_link;
}

static inline void __free_page(struct page *page) {
    free(page);
}

static inline void kfree(void *p) {
    free(p);
}