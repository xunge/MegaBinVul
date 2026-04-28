#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef unsigned long mfn_t;
typedef unsigned long paddr_t;
typedef unsigned long vaddr_t;

#define XEN_GUEST_HANDLE_PARAM(type) void *
#define XEN_GUEST_HANDLE(type) void *
#define guest_handle_t void *

#define PRI_mfn "lx"
#define mfn_x(mfn) (mfn)

#define unlikely(x) (x)
#define likely(x) (x)

#define BUG_ON(cond) 
#define ASSERT(cond)

#define __HYPERVISOR_mmuext_op 0
#define HYPERVISOR_mmuext_op 0

#define MMU_UPDATE_PREEMPTED (1U << 31)

#define PGT_l1_page_table 0
#define PGT_l2_page_table 1
#define PGT_l3_page_table 2
#define PGT_l4_page_table 3
#define PGT_root_page_table 4
#define PGT_writable_page 5

#define _PGT_pinned 0

#define CONFIG_PAGING_LEVELS 4

#define XSM_TARGET 0
#define XSM_HOOK 0

#define XENLOG_WARNING 0

#define FLUSH_CACHE 0

#define EFAULT 1
#define ESRCH 2
#define EINVAL 3
#define EOPNOTSUPP 4
#define ENOSYS 5
#define EPERM 6
#define EACCES 7
#define EINTR 8
#define ERESTART 9

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

#define PAGE_SIZE 4096

struct mmuext_op {
    unsigned int cmd;
    union {
        struct {
            mfn_t mfn;
            vaddr_t linear_addr;
        } arg1;
        struct {
            mfn_t src_mfn;
            guest_handle_t vcpumask;
            unsigned int nr_ents;
        } arg2;
    };
};

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } u;
    } inuse;
};

struct vcpu {
    struct domain *domain;
    struct arch_vcpu {
        struct page_info *old_guest_table;
        struct page_info *old_guest_ptpg;
        struct page_info *guest_table_user;
        struct {
            unsigned long ldt_base;
            unsigned int ldt_ents;
        } pv_vcpu;
    } arch;
};

typedef struct cpumask {
    unsigned long bits[1];
} cpumask_t;

struct spinlock {
    int lock;
};

struct domain {
    unsigned int domain_id;
    bool is_dying;
    bool is_pv;
    bool is_hvm;
    bool is_32bit_pv;
    cpumask_t *domain_dirty_cpumask;
    struct spinlock page_alloc_lock;
};

typedef enum {
    p2m_ram_rw,
    p2m_invalid,
    p2m_ram_ro,
    p2m_max
} p2m_type_t;

static cpumask_t scratch_cpumask;
static cpumask_t cpu_sibling_mask[1];

#define current ((struct vcpu *)0)
#define this_cpu(var) (&var)

#define perfc_incr(var)
#define perfc_add(var, val)

#define gdprintk(level, fmt, ...)

#define put_old_guest_table(v) 0
#define hypercall_create_continuation(op, fmt, ...) 0
#define guest_handle_is_null(h) 1
#define guest_handle_okay(h, n) 1
#define copy_from_guest(dst, src, n) 0
#define __copy_from_guest(dst, src, n) 0
#define copy_to_guest(dst, src, n) 0
#define get_pg_owner(dom) NULL
#define put_pg_owner(dom)
#define is_pv_domain(d) 0
#define is_hvm_domain(d) 0
#define is_pv_32bit_domain(d) 0
#define paging_mode_refcounts(d) 0
#define paging_mode_translate(d) 0
#define paging_mode_external(d) 0
#define get_page_from_gfn(d, mfn, p2mt, alloc) NULL
#define get_page_type_preemptible(page, type) 0
#define put_page_and_type_preemptible(page) 0
#define put_page_and_type(page)
#define put_page(page)
#define get_page_type(page, type) 0
#define page_to_mfn(page) 0
#define mfn_to_page(mfn) NULL
#define pagetable_get_pfn(table) 0
#define pagetable_from_pfn(pfn) NULL
#define get_page_and_type_from_mfn(mfn, type, d, partial, preemptible) 0
#define zap_ro_mpt(mfn)
#define new_guest_cr3(mfn) 0
#define paging_invlpg(vcpu, addr)
#define vcpumask_to_pcpumask(d, mask, out) 0
#define flush_tlb_local()
#define flush_tlb_mask(mask)
#define flush_tlb_one_mask(mask, addr)
#define flush_mask(mask, type)
#define invalidate_shadow_ldt(vcpu, flags)
#define load_LDT(vcpu)
#define clear_domain_page(mfn)
#define copy_domain_page(dst, src)
#define paging_mark_dirty(d, mfn)
#define cache_flush_permitted(d) 0
#define wbinvd()
#define VM_ASSIST(d, flag) 0
#define xsm_mmuext_op(target, d1, d2) 0
#define xsm_memory_pin_page(hook, d1, d2, page) 0
#define hypercall_preempt_check() 0
#define guest_handle_add_offset(h, o)
#define set_xen_guest_handle(h, p)
#define guest_handle_to_param(h, t) NULL

#define __addr_ok(addr) 1
#define _mfn(mfn) (mfn)

#define for_each_online_cpu(cpu) for ((cpu) = 0; (cpu) < 1; (cpu)++)
#define per_cpu(var, cpu) (var)
#define cpumask_clear(mask)
#define cpumask_intersects(mask1, mask2) 0
#define __cpumask_set_cpu(cpu, mask)

#define spin_lock(lock)
#define spin_unlock(lock)
#define test_and_set_bit(nr, addr) 0
#define test_and_clear_bit(nr, addr) 0