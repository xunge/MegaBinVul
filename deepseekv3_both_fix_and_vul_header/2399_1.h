#include <stddef.h>

struct gnttab_copy_buf {
    void *virt;
    int have_type;
    void *page;
    int have_grant;
    unsigned int domain;
    union {
        struct {
            unsigned long ref;
        } u;
    } ptr;
    int read_only;
};

void unmap_domain_page(void *virt);
void put_page_type(void *page);
void put_page(void *page);
void release_grant_for_copy(unsigned int domain, unsigned long ref, int read_only);