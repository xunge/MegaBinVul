#include <stdint.h>
#include <stddef.h>

#define XEN_GUEST_HANDLE_PARAM(t) t*
#define unlikely(x) (x)
#define likely(x) (x)
#define PAGE_SHIFT 12
#define PAGE_MASK (~(PAGE_SIZE-1))
#define PAGE_SIZE 4096
#define _PAGE_PRESENT (1UL<<0)
#define _PAGE_RW (1UL<<1)

typedef unsigned int uint;
typedef uint32_t p2m_type_t;
typedef uint32_t p2m_query_t;

struct mmu_update {
    unsigned long ptr;
    unsigned long val;
};
typedef struct mmu_update mmu_update_t;

struct vcpu {
    struct domain *domain;
    struct {
        void *old_guest_table;
    } arch;
    struct vcpu **vcpu;
};
struct domain {
    struct vcpu **vcpu;
};
struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};
struct domain_mmap_cache {
    int dummy;
};

#define MMU_UPDATE_PREEMPTED (1U<<31)
#define MMU_NORMAL_PT_UPDATE 0
#define MMU_PT_UPDATE_PRESERVE_AD 1
#define MMU_MACHPHYS_UPDATE 2

#define PGT_l1_page_table 0
#define PGT_l2_page_table 1  
#define PGT_l3_page_table 2
#define PGT_l4_page_table 3
#define PGT_writable_page 4
#define PGT_type_mask 0x7

#define XSM_MMU_NORMAL_UPDATE (1<<0)
#define XSM_MMU_UPDATE_READ (1<<1)
#define XSM_MMU_UPDATE_WRITE (1<<2)
#define XSM_MMU_MACHPHYS_UPDATE (1<<3)

#define XSM_TARGET 0

#define ERESTART (-512)
#define EFAULT (-14)
#define EINVAL (-22)
#define ESRCH (-3)
#define EOPNOTSUPP (-95)
#define ENOENT (-2)
#define ENOMEM (-12)
#define ENOSYS (-38)
#define EINTR (-4)

#define ASSERT(x) ((void)0)
#define MEM_LOG(fmt, ...) ((void)0)

static inline int guest_handle_is_null(void *h) { return h == NULL; }
static inline int guest_handle_okay(void *h, unsigned int n) { return 1; }
static inline int copy_from_guest(void *dst, void *src, unsigned int n) { return 0; }
static inline int __copy_from_guest(void *dst, void *src, unsigned int n) { return 0; }
static inline void guest_handle_add_offset(void *h, unsigned int n) {}
static inline void set_xen_guest_handle(void *h, void *p) {}

struct vcpu *current;

static inline unsigned long get_pte_flags(unsigned long val) { return val & 0xfff; }
static inline unsigned long l1e_get_flags(unsigned long l1e) { return l1e & 0xfff; }
static inline unsigned long l1e_get_pfn(unsigned long l1e) { return l1e >> 12; }
typedef unsigned long l1_pgentry_t;
static inline l1_pgentry_t l1e_from_intpte(unsigned long val) { return val; }
static inline l1_pgentry_t l2e_from_intpte(unsigned long val) { return val; }
static inline l1_pgentry_t l3e_from_intpte(unsigned long val) { return val; }
static inline l1_pgentry_t l4e_from_intpte(unsigned long val) { return val; }
static inline unsigned long page_to_mfn(struct page_info *page) { return 0; }
static inline unsigned long _mfn(unsigned long mfn) { return mfn; }

static inline int paging_mode_refcounts(struct domain *d) { return 0; }
static inline int paging_mode_translate(struct domain *d) { return 0; }
static inline int p2m_is_paged(p2m_type_t t) { return 0; }
static inline int p2m_is_shared(p2m_type_t t) { return 0; }
static inline void p2m_mem_paging_populate(struct domain *d, unsigned long gfn) {}
static inline void paging_mark_dirty(struct domain *d, unsigned long mfn) {}
static inline int paging_write_guest_entry(struct vcpu *v, void *va, unsigned long val, unsigned long mfn) { return 0; }

static inline struct page_info *get_page_from_gfn(struct domain *d, unsigned long gfn, p2m_type_t *t, p2m_query_t q) { return NULL; }
static inline struct page_info *get_page_from_pagenr(unsigned long mfn, struct domain *d) { return NULL; }
static inline struct page_info *mfn_to_page(unsigned long mfn) { return NULL; }
static inline void put_page(struct page_info *page) {}
static inline int page_lock(struct page_info *page) { return 0; }
static inline void page_unlock(struct page_info *page) {}
static inline int get_page_type(struct page_info *page, unsigned int type) { return 0; }
static inline void put_page_type(struct page_info *page) {}

static inline struct domain *rcu_lock_domain_by_id(int id) { return NULL; }
static inline void rcu_unlock_domain(struct domain *d) {}
static inline struct domain *get_pg_owner(uint16_t id) { return NULL; }
static inline void put_pg_owner(struct domain *d) {}

static inline void domain_mmap_cache_init(struct domain_mmap_cache *cache) {}
static inline void domain_mmap_cache_destroy(struct domain_mmap_cache *cache) {}
static inline void *map_domain_page_with_cache(unsigned long mfn, struct domain_mmap_cache *cache) { return NULL; }
static inline void unmap_domain_page_with_cache(void *va, struct domain_mmap_cache *cache) {}

static inline int xsm_mmu_update(int target, struct domain *d1, struct domain *d2, struct domain *d3, uint32_t flags) { return 0; }

static inline int put_old_guest_table(struct vcpu *v) { return 0; }
static inline int hypercall_preempt_check(void) { return 0; }
static inline int hypercall_create_continuation(int op, const char *fmt, ...) { return 0; }
#define __HYPERVISOR_mmu_update 0

static inline void perfc_incr(int counter) {}
static inline void perfc_add(int counter, int val) {}

static int calls_to_mmu_update;
static int writable_mmu_updates;
static int num_page_updates;

static inline void set_gpfn_from_mfn(unsigned long mfn, unsigned long gpfn) {}

static inline int mod_l1_entry(void *va, l1_pgentry_t l1e, unsigned long mfn, int preserve_ad, struct vcpu *v, struct domain *d) { return 0; }
static inline int mod_l2_entry(void *va, l1_pgentry_t l2e, unsigned long mfn, int preserve_ad, struct vcpu *v) { return 0; }
static inline int mod_l3_entry(void *va, l1_pgentry_t l3e, unsigned long mfn, int preserve_ad, struct vcpu *v) { return 0; }
static inline int mod_l4_entry(void *va, l1_pgentry_t l4e, unsigned long mfn, int preserve_ad, struct vcpu *v) { return 0; }

#define P2M_ALLOC 0
#define P2M_UNSHARE 1
#define p2m_ram_rw 0
#define p2m_ram_paging_in 1