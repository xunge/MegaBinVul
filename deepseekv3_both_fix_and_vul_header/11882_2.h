#include <stdbool.h>
#include <stddef.h>

struct page_info {
    unsigned long count_info;
};

struct hvm_ioreq_page {
    struct page_info *page;
    void *va;
};

struct hvm_ioreq_server {
    struct hvm_ioreq_page bufioreq;
    struct hvm_ioreq_page ioreq;
};

#define _PGC_allocated 0

void unmap_domain_page_global(void *va);
void put_page(struct page_info *page);
void put_page_and_type(struct page_info *page);
int test_and_clear_bit(int nr, volatile unsigned long *addr);