#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef uint64_t mfn_t;
typedef uint64_t l4_pgentry_t;

struct arch_vcpu {
    mfn_t guest_table;
    struct page_info *old_guest_table;
    struct page_info *old_guest_ptpg;
};

struct vcpu {
    struct domain *domain;
    struct arch_vcpu arch;
};

struct domain {
    unsigned long arch_domain;
};

struct page_info {
    // page info fields
};

#define _PAGE_PRESENT    (1ULL << 0)
#define _PAGE_RW         (1ULL << 1)
#define _PAGE_USER       (1ULL << 2)
#define _PAGE_ACCESSED   (1ULL << 5)

#define PRI_mfn "lx"
#define mfn_x(mfn) ((unsigned long)(mfn))
#define mfn_eq(a, b) ((a) == (b))
#define unlikely(x) (x)
#define likely(x) (x)
#define BUG_ON(cond) do { if (cond) for(;;); } while (0)

#define XENLOG_WARNING 1
#define PGT_root_page_table 0

#define VM_ASSIST(d, flag) 0
#define EINTR 4
#define ERESTART 85
#define EINVAL 22

extern struct vcpu *current;

static inline int is_pv_32bit_domain(struct domain *d) { return 0; }
static inline mfn_t pagetable_get_mfn(mfn_t table) { return table; }
static inline l4_pgentry_t *map_domain_page(mfn_t mfn) { return NULL; }
static inline void unmap_domain_page(l4_pgentry_t *p) {}
static inline int mod_l4_entry(l4_pgentry_t *pl4e, l4_pgentry_t new, unsigned long mfn, int pt, struct vcpu *v) { return 0; }
static inline l4_pgentry_t l4e_from_mfn(mfn_t mfn, unsigned long flags) { return 0; }
static inline void invalidate_shadow_ldt(struct vcpu *v, int i) {}
static inline void write_ptbase(struct vcpu *v) {}
static inline int put_old_guest_table(struct vcpu *v) { return 0; }
static inline int paging_mode_refcounts(struct domain *d) { return 0; }
static inline int get_page_from_mfn(mfn_t mfn, struct domain *d) { return 0; }
static inline int get_page_and_type_from_mfn(mfn_t mfn, int type, struct domain *d, int partial, int preemptible) { return 0; }
static inline void fill_ro_mpt(mfn_t mfn) {}
static inline mfn_t pagetable_from_mfn(mfn_t mfn) { return mfn; }
static inline void update_cr3(struct vcpu *v) {}
static inline struct page_info *mfn_to_page(mfn_t mfn) { return NULL; }
static inline void put_page(struct page_info *page) {}
static inline int put_page_and_type_preemptible(struct page_info *page) { return 0; }
static inline void gdprintk(int level, const char *fmt, ...) {}