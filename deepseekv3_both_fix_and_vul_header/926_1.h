#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

struct vcpu {
    struct domain *domain;
    struct {
        struct {
            unsigned long ldt_base;
            unsigned int ldt_ents;
#ifdef CONFIG_PV_LDT_PAGING
            spinlock_t shadow_ldt_lock;
            unsigned int shadow_ldt_mapcnt;
#endif
        } pv;
    } arch;
};

struct domain;
struct page_info;

typedef uint64_t l1_pgentry_t;

#define BUG_ON(condition)
#define unlikely(x) (x)
#define ASSERT(condition)
#define _PAGE_PRESENT (1UL << 0)
#define _PAGE_RW (1UL << 1)
#define P2M_ALLOC 0
#define PGT_seg_desc_page 0
#define PAGE_SHIFT 12

struct vcpu *current;
l1_pgentry_t *pv_ldt_ptes(struct vcpu *);

bool in_irq(void);
l1_pgentry_t guest_get_eff_kern_l1e(unsigned long);
unsigned long l1e_get_flags(l1_pgentry_t);
unsigned long l1e_get_pfn(l1_pgentry_t);
struct page_info *get_page_from_gfn(struct domain *, unsigned long, void *, int);
bool get_page_type(struct page_info *, unsigned int);
void put_page(struct page_info *);
void l1e_add_flags(l1_pgentry_t *, unsigned long);
void l1e_write(l1_pgentry_t *, l1_pgentry_t);

bool is_pv_32bit_domain(struct domain *);