#include <stdint.h>
#include <inttypes.h>

typedef uint64_t l1_pgentry_t;

#define PRIpte "016" PRIx64

#define _PAGE_PRESENT    (1ULL<<0)
#define _PAGE_RW         (1ULL<<1)
#define _PAGE_AVAIL      (1ULL<<9)
#define PAGE_CACHE_ATTRS (0x7f0ULL)

#define PGT_l1_page_table 1
#define PGT_type_mask     0x7f

#define GNTST_general_error 1
#define XENLOG_WARNING      1
#define XENLOG_ERR          2

struct vcpu {
    struct domain *domain;
};

struct domain;

struct page_info {
    union {
        struct {
            uint32_t type_info;
        } inuse;
    } u;
};

extern struct vcpu *current;
extern void gdprintk(int level, const char *fmt, ...);
extern l1_pgentry_t *guest_map_l1e(unsigned long addr, unsigned long *gl1mfn);
extern void guest_unmap_l1e(l1_pgentry_t *pl1e);
extern int get_page_from_mfn(unsigned long mfn, struct domain *d);
extern struct page_info *mfn_to_page(unsigned long mfn);
extern int page_lock(struct page_info *page);
extern void page_unlock(struct page_info *page);
extern void put_page(struct page_info *page);
extern unsigned long l1e_get_pfn(l1_pgentry_t l1e);
extern unsigned long l1e_get_flags(l1_pgentry_t l1e);
extern uint64_t l1e_get_intpte(l1_pgentry_t l1e);
extern l1_pgentry_t l1e_from_pfn(unsigned long pfn, unsigned long flags);
#define UPDATE_ENTRY(l1, pl1e, ol1e, nl1e, gl1mfn, v, arg) 0
#define unlikely(x) (x)
#define _mfn(x) (x)