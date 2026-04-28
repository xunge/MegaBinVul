#include <stdlib.h>

struct domain {
    struct xenoprof *xenoprof;
};

struct xenoprof {
    void *rawbuf;
    unsigned int npages;
    void *vcpu;
};

static inline int get_order_from_pages(unsigned int pages) {
    return 0;
}

void free_xenheap_pages(void *addr, int order);
void xfree(void *ptr);