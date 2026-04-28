#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define EINVAL 22
#define ENOMEM 12
#define XENLOG_G_ERR ""
#define PAGE_ORDER_4K 0
#define IRQ_UNBOUND 0

typedef unsigned long p2m_type_t;

struct spinlock {
    int lock;
};

struct domain {
    void *shared_info;
    unsigned int nr_pirqs;
    int domain_id;
    struct spinlock event_lock;
};

struct page_info;

static inline struct page_info *virt_to_page(void *virt) { return NULL; }
static inline bool is_hvm_domain(struct domain *d) { return false; }
static inline void hvm_domain_soft_reset(struct domain *d) {}
static inline int domain_pirq_to_emuirq(struct domain *d, unsigned int pirq) { return 0; }
static inline int unmap_domain_pirq_emuirq(struct domain *d, unsigned int pirq) { return 0; }
static inline struct domain *page_get_owner_and_reference(struct page_info *page) { return NULL; }
static inline unsigned long page_to_mfn(struct page_info *page) { return 0; }
static inline unsigned long mfn_to_gmfn(struct domain *d, unsigned long mfn) { return 0; }
static inline unsigned long gfn_x(unsigned long gfn) { return gfn; }
static inline unsigned long mfn_x(unsigned long mfn) { return mfn; }
static inline unsigned long get_gfn_query(struct domain *d, unsigned long gfn, p2m_type_t *p2mt) { return 0; }
static inline struct page_info *alloc_domheap_page(struct domain *d, int flags) { return NULL; }
static inline int guest_physmap_remove_page(struct domain *d, unsigned long gfn, unsigned long mfn, unsigned int order) { return 0; }
static inline int guest_physmap_add_page(struct domain *d, unsigned long gfn, unsigned long mfn, unsigned int order) { return 0; }
static inline void free_domheap_page(struct page_info *page) {}
static inline void put_gfn(struct domain *d, unsigned long gfn) {}
static inline void put_page(struct page_info *page) {}
static inline unsigned long _gfn(unsigned long gfn) { return gfn; }
static inline unsigned long _mfn(unsigned long mfn) { return mfn; }

#define INVALID_GFN (~0UL)
#define ASSERT(cond) do { if (!(cond)) {} } while (0)

void spin_lock(struct spinlock *lock) { (void)lock; }
void spin_unlock(struct spinlock *lock) { (void)lock; }
int printk(const char *fmt, ...) { return 0; }