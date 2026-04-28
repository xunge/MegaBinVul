#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef unsigned long cpumask_t;
typedef unsigned long spinlock_t;

#define XEN_GUEST_HANDLE_PARAM(type) void*
#define XEN_GUEST_HANDLE(type) void*
#define guest_handle_t void*

typedef unsigned long mfn_t;
typedef unsigned long pfn_t;

#define unlikely(x) (x)
#define likely(x) (x)
#define __HYPERVISOR_mmuext_op 0
#define HYPERVISOR_mmuext_op 0
#define __HYPERVISOR_arch_0 0
#define HYPERVISOR_arch_0 0

#define EFAULT 1
#define ESRCH 2
#define EINVAL 3
#define EOPNOTSUPP 4
#define ERESTART 5
#define EPERM 6
#define EACCES 7
#define ENOSYS 8
#define EINTR 9

#define MMU_UPDATE_PREEMPTED 0x80000000
#define MMUEXT_PIN_L1_TABLE 0
#define MMUEXT_PIN_L2_TABLE 1
#define MMUEXT_PIN_L3_TABLE 2
#define MMUEXT_PIN_L4_TABLE 3
#define MMUEXT_UNPIN_TABLE 4
#define MMUEXT_NEW_BASEPTR 5
#define MMUEXT_NEW_USER_BASEPTR 6
#define MMUEXT_TLB_FLUSH_LOCAL 7
#define MMUEXT_INVLPG_LOCAL 8
#define MMUEXT_TLB_FLUSH_MULTI 9
#define MMUEXT_INVLPG_MULTI 10
#define MMUEXT_TLB_FLUSH_ALL 11
#define MMUEXT_INVLPG_ALL 12
#define MMUEXT_FLUSH_CACHE 13
#define MMUEXT_FLUSH_CACHE_GLOBAL 14
#define MMUEXT_SET_LDT 15
#define MMUEXT_CLEAR_PAGE 16
#define MMUEXT_COPY_PAGE 17
#define MMUEXT_MARK_SUPER 18
#define MMUEXT_UNMARK_SUPER 19

#define PGT_l1_page_table 0
#define PGT_l2_page_table 1
#define PGT_l3_page_table 2
#define PGT_l4_page_table 3
#define PGT_root_page_table 4
#define PGT_writable_page 5
#define _PGT_pinned 0
#define P2M_ALLOC 0

#define CONFIG_PAGING_LEVELS 4
#define PAGE_SIZE 4096
#define L1_PAGETABLE_ENTRIES 512

#define XSM_TARGET 0
#define XSM_HOOK 0
#define XSM_OTHER 0

#define FLUSH_CACHE 1
#define m2p_strict 0

struct mmuext_op {
    unsigned int cmd;
    union {
        struct {
            mfn_t mfn;
            unsigned long linear_addr;
        } arg1;
        struct {
            mfn_t src_mfn;
            mfn_t dst_mfn;
            guest_handle_t vcpumask;
            unsigned long nr_ents;
        } arg2;
    };
};

struct vcpu {
    struct domain *domain;
    struct {
        struct page_info *old_guest_table;
        struct page_info *guest_table_user;
        struct {
            unsigned long ldt_base;
            unsigned long ldt_ents;
        } pv_vcpu;
    } arch;
};

struct domain {
    int is_dying;
    bool is_pv;
    cpumask_t *domain_dirty_cpumask;
    spinlock_t page_alloc_lock;
};

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

static int calls_to_mmuext_op;
static int num_mmuext_ops;
static int opt_allow_superpage;

static struct vcpu *current;
static cpumask_t pmask;
static cpumask_t mask;
static const void *const_void;

static inline bool guest_handle_is_null(XEN_GUEST_HANDLE_PARAM(void) h) { return false; }
static inline bool guest_handle_okay(XEN_GUEST_HANDLE_PARAM(void) h, unsigned int n) { return true; }
static inline void guest_handle_add_offset(XEN_GUEST_HANDLE_PARAM(void) h, unsigned int n) { }
static inline int copy_from_guest(void *dst, XEN_GUEST_HANDLE_PARAM(void) src, unsigned int n) { return 0; }
static inline int __copy_from_guest(void *dst, XEN_GUEST_HANDLE_PARAM(void) src, unsigned int n) { return 0; }
static inline int copy_to_guest(XEN_GUEST_HANDLE_PARAM(void) dst, const void *src, unsigned int n) { return 0; }
static inline int vcpumask_to_pcpumask(struct domain *d, const void *src, cpumask_t *dst) { return 0; }
static inline int guest_handle_to_param(guest_handle_t h, const void *p) { return 0; }

static inline int put_old_guest_table(struct vcpu *v) { return 0; }
static inline long hypercall_create_continuation(unsigned int op, const char *fmt, ...) { return 0; }
static inline struct domain *get_pg_owner(unsigned int domid) { return NULL; }
static inline void put_pg_owner(struct domain *d) { }
static inline bool is_pv_domain(struct domain *d) { return false; }
static inline bool is_pv_32bit_domain(struct domain *d) { return false; }
static inline int xsm_mmuext_op(int hook, struct domain *d1, struct domain *d2) { return 0; }
static inline int xsm_memory_pin_page(int hook, struct domain *d1, struct domain *d2, struct page_info *pg) { return 0; }
static inline void perfc_incr(int counter) { }
static inline void perfc_add(int counter, int val) { }
static inline bool has_hvm_container_domain(struct domain *d) { return false; }
static inline bool paging_mode_refcounts(struct domain *d) { return false; }
static inline bool paging_mode_translate(struct domain *d) { return false; }
static inline bool paging_mode_enabled(struct domain *d) { return false; }
static inline bool paging_mode_external(struct domain *d) { return false; }
static inline struct page_info *get_page_from_gfn(struct domain *d, mfn_t mfn, pfn_t *pfn, int flags) { return NULL; }
static inline struct page_info *get_page_from_pagenr(mfn_t mfn, struct domain *d) { return NULL; }
static inline int get_page_type(struct page_info *pg, unsigned long type) { return 0; }
static inline int get_page_type_preemptible(struct page_info *pg, unsigned long type) { return 0; }
static inline int get_page_and_type_from_pagenr(mfn_t mfn, unsigned long type, struct domain *d, int partial, int preemptible) { return 0; }
static inline void put_page(struct page_info *pg) { }
static inline void put_page_and_type(struct page_info *pg) { }
static inline int put_page_and_type_preemptible(struct page_info *pg) { return 0; }
static inline mfn_t page_to_mfn(struct page_info *pg) { return 0; }
static inline void paging_mark_dirty(struct domain *d, mfn_t mfn) { }
static inline int new_guest_cr3(mfn_t mfn) { return 0; }
static inline void zap_ro_mpt(mfn_t mfn) { }
static inline void invalidate_shadow_ldt(struct vcpu *v, int i) { }
static inline void load_LDT(struct vcpu *v) { }
static inline void clear_domain_page(mfn_t mfn) { }
static inline void copy_domain_page(mfn_t dst, mfn_t src) { }
static inline int mark_superpage(void *spg, struct domain *d) { return 0; }
static inline int unmark_superpage(void *spg) { return 0; }
static inline void flush_tlb_local(void) { }
static inline void flush_tlb_one_local(unsigned long addr) { }
static inline void flush_tlb_mask(cpumask_t *mask) { }
static inline void flush_tlb_one_mask(cpumask_t *mask, unsigned long addr) { }
static inline int paging_invlpg(struct vcpu *v, unsigned long addr) { return 0; }
static inline bool cache_flush_permitted(struct domain *d) { return false; }
static inline void wbinvd(void) { }
static inline void flush_mask(cpumask_t *mask, int flags) { }
static inline bool __addr_ok(unsigned long addr) { return true; }
static inline bool VM_ASSIST(struct domain *d, int flag) { return false; }
static inline struct page_info *mfn_to_page(mfn_t mfn) { return NULL; }
static inline void *mfn_to_spage(mfn_t mfn) { return NULL; }
static inline void *pagetable_from_pfn(pfn_t pfn) { return NULL; }
static inline pfn_t pagetable_get_pfn(void *pt) { return 0; }
static inline void MEM_LOG(const char *fmt, ...) { }
static inline void BUG_ON(int cond) { }
static inline void set_xen_guest_handle(XEN_GUEST_HANDLE_PARAM(void) h, void *p) { }
static inline int hypercall_preempt_check(void) { return 0; }
static inline mfn_t _mfn(mfn_t mfn) { return mfn; }
static inline int test_and_set_bit(int nr, volatile unsigned long *addr) { return 0; }
static inline int test_and_clear_bit(int nr, volatile unsigned long *addr) { return 0; }

#define for_each_online_cpu(cpu) for ((cpu) = 0; (cpu) < 1; (cpu)++)
#define per_cpu(var, cpu) var
#define cpumask_clear(mask) do { } while (0)
#define cpumask_intersects(m1, m2) false
#define __cpumask_set_cpu(cpu, mask) do { } while (0)
#define spin_lock(lock) do { } while (0)
#define spin_unlock(lock) do { } while (0)
#define ASSERT(cond) do { } while (0)