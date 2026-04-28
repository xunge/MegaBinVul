#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct nfs_direct_req {
    struct list_head rewrite_list;
};

struct nfs_write_data {
    struct list_head pages;
    struct page **pagevec;
    unsigned int npages;
};

#define list_empty(head) ((head)->next == (head))
#define list_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
#define list_del(entry) do { \
    (entry)->next->prev = (entry)->prev; \
    (entry)->prev->next = (entry)->next; \
} while (0)

void nfs_direct_release_pages(struct page **pagevec, unsigned int npages);
void nfs_writedata_release(struct nfs_write_data *data);