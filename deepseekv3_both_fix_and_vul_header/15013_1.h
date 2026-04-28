#include <stddef.h>
#include <stdio.h>

#define PAGE_SHIFT 12

struct page {
    int count;
    unsigned long flags;
};

unsigned long page_to_pfn(struct page *page);
void *__va(unsigned long physaddr);
int page_count(struct page *page);
int printk(const char *format, ...);