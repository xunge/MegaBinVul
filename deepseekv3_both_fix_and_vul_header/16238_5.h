#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define XEN_GUEST_HANDLE_PARAM(type) void*
#define XEN_GUEST_HANDLE(type) void*

typedef uint32_t mfn_t;
#define INVALID_MFN ((mfn_t)0)
#define mfn_x(x) (x)
#define mfn_eq(a, b) ((uintptr_t)(a) == (uintptr_t)(b))
#define _mfn(x) ((mfn_t)(x))
#define _gfn(x) ((unsigned long)(x))
#define _pfn(x) ((unsigned long)(x))
#define _p(x) ((void*)(x))

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))

#define _PAGE_PRESENT (1U << 0)
#define _PAGE_RW (1U << 1)

struct mmu_update {
    uint64_t ptr;
    uint64_t val;
};
typedef struct mmu_update mmu_update_t;

typedef uint64_t l1_pgentry_t;

typedef uint32_t p2m_type_t;
#define p2m_ram_rw 0
#define p2m_is_paged(x) (0)

typedef struct {
    unsigned long bits[1];
} cpumask_t;

struct cpu_info {
    bool root_pgt_changed;
};

static inline struct cpu_info *get_cpu_info(void) { 
    static struct cpu_info cpu_info;
    return &cpu_info; 
}

struct vcpu {
    struct domain *domain;
    struct {
        struct {
            void *guest_table;
            void *guest_table_user;
            void *old_guest_table;
        } arch;
    };
};

struct domain {
    struct vcpu **vcpu;
    cpumask_t *dirty_cpumask;
    struct {
        struct {
            bool xpti;
        } pv;
    } arch;
};

struct page_info {
    union {
        struct {
            unsigned int type_info;
        } inuse;
    } u;
};

#define P2M_ALLOC 0
#define PGT_l1_page_table 0
#define PGT_l2_page_table 1
#define PGT_l3_page_table 2
#define PGT_l4_page_table 3
#define PGT_writable_page 4
#define PGT_type_mask 0x7
#define PGT_count_mask 0xFF00
#define PGT_pinned (1U << 8)

#define MMU_NORMAL_PT_UPDATE 0
#define MMU_PT_UPDATE_PRESERVE_AD 1
#define MMU_PT_UPDATE_NO_TRANSLATE 2
#define MMU_MACHPHYS_UPDATE 3
#define MMU_UPDATE_PREEMPTED (1U << 31)

#define XSM_MMU_NORMAL_UPDATE (1U << 0)
#define XSM_MMU_UPDATE_READ (1U << 1)
#define XSM_MMU_UPDATE_WRITE (1U << 2)
#define XSM_MMU_MACHPHYS_UPDATE (1U << 3)

#define FLUSH_TLB (1U << 0)
#define FLUSH_ROOT_PGTBL (1U << 1)

#define XSM_TARGET 0
#define __HYPERVISOR_mmu_update 0

#define ERESTART (-1)
#define EFAULT (-2)
#define ESRCH (-3)
#define EINVAL (-4)
#define EOPNOTSUPP (-5)
#define ENOENT (-6)
#define EPERM (-7)
#define ENOSYS (-8)
#define EINTR (-9)

#define XENLOG_WARNING 1

#define unlikely(x) (x)
#define likely(x) (x)

static struct vcpu *current = NULL;
static int calls_to_mmu_update = 0;
static int num_page_updates = 0;
static int writable_mmu_updates = 0;
static cpumask_t *scratch_cpumask;

static inline void gdprintk(int level, const char *fmt, ...) {}

static inline void ASSERT(int condition) {}

static inline void set_xen_guest_handle(void *handle, void *value) {}

static inline void cpumask_copy(cpumask_t *dst, const cpumask_t *src) {
    memcpy(dst, src, sizeof(cpumask_t));
}

static inline void __cpumask_clear_cpu(unsigned int cpu, cpumask_t *dst) {
    dst->bits[0] &= ~(1UL << cpu);
}

static inline bool cpumask_test_cpu(unsigned int cpu, const cpumask_t *cpumask) {
    return (cpumask->bits[0] & (1UL << cpu)) != 0;
}

static inline bool cpumask_empty(const cpumask_t *cpumask) {
    return cpumask->bits[0] == 0;
}

static inline cpumask_t *cpumask_of(unsigned int cpu) {
    static cpumask_t mask;
    mask.bits[0] = 1UL << cpu;
    return &mask;
}

static inline void cpumask_andnot(cpumask_t *dst, const cpumask_t *src1, const cpumask_t *src2) {
    dst->bits[0] = src1->bits[0] & ~src2->bits[0];
}

static inline cpumask_t *per_cpu(cpumask_t **mask, unsigned int cpu) {
    return *mask;
}

static inline void flush_local(unsigned int flags) {}
static inline void flush_mask(cpumask_t *mask, unsigned int flags) {}

static inline int guest_handle_is_null(void *handle) { return handle == NULL; }
static inline int guest_handle_okay(void *handle, unsigned int count) { return 1; }
static inline void guest_handle_add_offset(void **handle, unsigned int offset) {}
static inline int copy_from_guest(void *dst, void *src, unsigned int count) { return 0; }
static inline int __copy_from_guest(void *dst, void *src, unsigned int count) { return 0; }
static inline void copy_to_guest(void *dst, void *src, unsigned int count) {}

static inline int put_old_guest_table(struct vcpu *v) { return 0; }
static inline int hypercall_create_continuation(int op, const char *fmt, ...) { return 0; }
static inline struct domain *rcu_lock_domain_by_id(int id) { return NULL; }
static inline void rcu_unlock_domain(struct domain *d) {}
static inline struct domain *get_pg_owner(uint16_t domid) { return NULL; }
static inline void put_pg_owner(struct domain *d) {}
static inline struct page_info *get_page_from_gfn(struct domain *d, unsigned long gfn, p2m_type_t *t, unsigned int flags) { return NULL; }
static inline void put_page(struct page_info *page) {}
static inline int page_lock(struct page_info *page) { return 1; }
static inline void page_unlock(struct page_info *page) {}
static inline int get_page_type(struct page_info *page, int type) { return 1; }
static inline void put_page_type(struct page_info *page) {}
static inline mfn_t page_to_mfn(struct page_info *page) { return INVALID_MFN; }
static inline void *map_domain_page(mfn_t mfn) { return NULL; }
static inline void unmap_domain_page(void *va) {}
static inline void *pagetable_get_mfn(void *table) { return (void*)0; }
static inline void p2m_mem_paging_populate(struct domain *d, unsigned long gfn) {}
static inline void set_gpfn_from_mfn(unsigned long mfn, unsigned long gpfn) {}
static inline void paging_mark_pfn_dirty(struct domain *d, unsigned long pfn) {}
static inline mfn_t maddr_to_mfn(uint64_t maddr) { return INVALID_MFN; }
static inline int xsm_mmu_update(int target, struct domain *d1, struct domain *d2, struct domain *d3, uint32_t flags) { return 0; }
static inline int hypercall_preempt_check(void) { return 0; }
static inline unsigned int smp_processor_id(void) { return 0; }
static inline int paging_mode_refcounts(struct domain *d) { return 0; }
static inline int paging_mode_translate(struct domain *d) { return 0; }
static inline int get_pte_flags(uint64_t val) { return 0; }
static inline int mod_l1_entry(void *va, uint64_t val, mfn_t mfn, int cmd, struct vcpu *v, struct domain *d) { return 0; }
static inline int mod_l2_entry(void *va, uint64_t val, mfn_t mfn, int preserve, struct vcpu *v) { return 0; }
static inline int mod_l3_entry(void *va, uint64_t val, mfn_t mfn, int preserve, struct vcpu *v) { return 0; }
static inline int mod_l4_entry(void *va, uint64_t val, mfn_t mfn, int preserve, struct vcpu *v) { return 0; }
static inline void paging_write_guest_entry(struct vcpu *v, void *va, uint64_t val, mfn_t mfn) {}
static inline uint64_t l1e_from_intpte(uint64_t val) { return val; }
static inline uint64_t l2e_from_intpte(uint64_t val) { return val; }
static inline uint64_t l3e_from_intpte(uint64_t val) { return val; }
static inline uint64_t l4e_from_intpte(uint64_t val) { return val; }
static inline struct page_info *get_page_from_mfn(mfn_t mfn, struct domain *d) { return NULL; }
static inline void perfc_incr(int counter) { counter++; }
static inline void perfc_add(int counter, int value) { counter += value; }