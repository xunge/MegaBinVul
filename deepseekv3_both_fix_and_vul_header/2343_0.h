#include <stdbool.h>
#include <stddef.h>

typedef unsigned long l4_pgentry_t;
typedef unsigned long mfn_t;

struct page_info;
struct arch_vcpu {
    struct page_info *old_guest_ptpg;
    struct page_info *old_guest_table;
};

struct vcpu {
    struct arch_vcpu arch;
};

extern struct vcpu *current;

#define _PAGE_PRESENT (1UL << 0)
#define unlikely(x) (x)
#define likely(x) (x)
#define ASSERT(x) ((void)0)

static inline unsigned long l4e_get_flags(l4_pgentry_t l4e);
static inline unsigned long l4e_get_pfn(l4_pgentry_t l4e);
static inline struct page_info *l4e_get_page(l4_pgentry_t l4e);
static inline mfn_t _mfn(unsigned long pfn);
static inline struct page_info *mfn_to_page(mfn_t mfn);
static int _put_page_type(struct page_info *pg, bool b, struct page_info *page);
static void put_page(struct page_info *pg);