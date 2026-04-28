#include <stdint.h>
#include <stddef.h>

#define XENLOG_ERR 0
#define SH_type_p2m_table 0
#define PGC_count_mask 0

struct page_info {
    uint64_t count_info;
};

struct domain {
    int domain_id;
    struct {
        struct {
            struct {
                unsigned long total_pages;
                unsigned long p2m_pages;
            } shadow;
            int p2m_alloc_failed;
        } paging;
    } arch;
};

void paging_lock_recursive(struct domain *d);
void paging_unlock(struct domain *d);
unsigned long shadow_min_acceptable_pages(struct domain *d);
void shadow_prealloc(struct domain *d, int type, int count);
unsigned long shadow_alloc(struct domain *d, int type, int flags);
struct page_info *mfn_to_page(unsigned long mfn);
void page_set_owner(struct page_info *pg, struct domain *d);
void *page_get_owner(struct page_info *pg);
void dprintk(int level, const char *fmt, ...);
void ASSERT(int condition);