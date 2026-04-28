#include <stdint.h>
#include <stddef.h>

typedef unsigned long gfn_t;
typedef unsigned long mfn_t;
typedef unsigned int p2m_type_t;
typedef unsigned int p2m_query_t;

#define gfn_x(gfn) (gfn)
#define p2m_is_paging(type) (0)
#define p2m_is_hostp2m(p2m) (0)
#define p2m_is_shared(type) (0)
#define mfn_valid(mfn) (1)
#define ASSERT(cond) ((void)0)

#define _PAGE_INVALID_BIT (1)
#define _PAGE_PAGED (2)
#define _PAGE_SHARED (3)
#define _PAGE_PRESENT (4)

struct domain {
    struct {
        struct {
            unsigned long gfn_bits;
        } paging;
    } arch;
};

struct p2m_domain {
    struct domain *domain;
};

struct page_info;

struct page_info *get_page_from_gfn_p2m(struct domain *d, struct p2m_domain *p2m, 
                                       unsigned long gfn, p2m_type_t *p2mt, 
                                       void *null, p2m_query_t q);
void put_page(struct page_info *page);
void p2m_mem_paging_populate(struct domain *d, unsigned long gfn);
mfn_t page_to_mfn(struct page_info *page);
void *map_domain_page(mfn_t mfn);