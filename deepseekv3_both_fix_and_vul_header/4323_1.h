#include <stddef.h>

#define INIT_PAGE_LIST_HEAD(ptr) do { (ptr)->next = (ptr); (ptr)->prev = (ptr); } while (0)
#define PAGE_SHIFT 12

struct page_list_head {
    struct page_list_head *next;
    struct page_list_head *prev;
};

struct hap_paging {
    struct page_list_head freelist;
};

struct paging {
    struct hap_paging hap;
    unsigned int gfn_bits;
};

struct arch_domain {
    struct paging paging;
};

struct domain {
    struct arch_domain arch;
};

extern unsigned int hap_paddr_bits;
extern void paging_log_dirty_init(struct domain *d,
                                 void (*enable)(struct domain *),
                                 void (*disable)(struct domain *),
                                 void (*clean)(struct domain *));
extern void hap_enable_log_dirty(struct domain *d);
extern void hap_disable_log_dirty(struct domain *d);
extern void hap_clean_dirty_bitmap(struct domain *d);