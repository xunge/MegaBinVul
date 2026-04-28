#include <stdbool.h>

typedef unsigned long l3_pgentry_t;

struct page_info;
struct arch_vcpu {
    struct page_info *old_guest_ptpg;
    struct page_info *old_guest_table;
};

struct vcpu {
    struct arch_vcpu arch;
};

extern struct vcpu *current;

#define _PAGE_PRESENT  (1UL << 0)
#define _PAGE_RW       (1UL << 1)
#define _PAGE_PSE      (1UL << 2)

#define L3_PAGETABLE_SHIFT 30
#define PAGE_SHIFT 12

#define unlikely(x) (x)
#define likely(x)   (x)

#define ASSERT(x) ((void)0)

static inline unsigned long l3e_get_flags(l3_pgentry_t l3e);
static inline unsigned long l3e_get_pfn(l3_pgentry_t l3e);
static inline struct page_info *l3e_get_page(l3_pgentry_t l3e);
static inline struct page_info *mfn_to_page(unsigned long mfn);
static inline unsigned long _mfn(unsigned long mfn);
static void put_data_page(struct page_info *pg, int writeable);
static int _put_page_type(struct page_info *pg, bool b, struct page_info *pg2);
static void put_page(struct page_info *pg);