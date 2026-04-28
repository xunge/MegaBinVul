#include <stdint.h>
#include <stddef.h>

#define XEN_GUEST_HANDLE_PARAM(type) void*
#define PRIx64 "llx"

typedef int32_t domid_t;
typedef uint64_t mfn_t;
typedef uint64_t paddr_t;
typedef uint64_t vaddr_t;
typedef uint32_t p2m_type_t;
typedef uint32_t hvmmem_access_t;

#define DOMID_SELF 0
#define HVM_NR_PARAMS 64
#define SHUTDOWN_MAX 8
#define GB(x) ((x) * 1024 * 1024 * 1024)
#define PAGE_SHIFT 12

#define EFAULT 14
#define EINVAL 22
#define ESRCH 3
#define EPERM 1
#define EAGAIN 11
#define ENOSYS 38
#define ENOENT 2
#define EBUSY 16

struct hvm_ioreq_page {
    void *va;
    void *lock;
    int vp_eport;
};

struct domain {
    domid_t domain_id;
    struct {
        struct {
            struct {
                uint64_t params[HVM_NR_PARAMS];
                struct hvm_ioreq_page ioreq;
                struct hvm_ioreq_page buf_ioreq;
                int is_s3_suspended;
            } hvm_domain;
        } arch;
        struct vcpu **vcpu;
        int max_vcpus;
        int is_dying;
    };
};

struct vcpu {
    struct domain *domain;
    struct {
        struct {
            int xen_port;
            struct {
                int vector;
                int type;
                int error_code;
                int insn_len;
                uint64_t cr2;
            } inject_trap;
        } hvm_vcpu;
    } arch;
};

struct page_info;

struct xen_hvm_param {
    domid_t domid;
    uint32_t index;
    uint64_t value;
};

struct xen_hvm_track_dirty_vram {
    domid_t domid;
    uint64_t first_pfn;
    uint64_t nr;
    void *dirty_bitmap;
};

struct xen_hvm_modified_memory {
    domid_t domid;
    uint64_t first_pfn;
    uint64_t nr;
};

struct xen_hvm_get_mem_type {
    domid_t domid;
    uint64_t pfn;
    uint32_t mem_type;
};

struct xen_hvm_set_mem_type {
    domid_t domid;
    uint64_t first_pfn;
    uint64_t nr;
    uint32_t hvmmem_type;
};

struct xen_hvm_set_mem_access {
    domid_t domid;
    uint64_t first_pfn;
    uint64_t nr;
    hvmmem_access_t hvmmem_access;
};

struct xen_hvm_get_mem_access {
    domid_t domid;
    uint64_t pfn;
    hvmmem_access_t hvmmem_access;
};

struct xen_hvm_pagetable_dying {
    domid_t domid;
    uint64_t gpa;
};

typedef struct {
    uint64_t now;
} xen_hvm_get_time_t;

typedef struct {
    uint32_t event;
    uint32_t extra_bytes;
    uint8_t extra[32];
} xen_hvm_xentrace_t;

typedef struct {
    domid_t domid;
    uint32_t vcpuid;
    uint32_t vector;
    uint32_t type;
    uint32_t error_code;
    uint32_t insn_len;
    uint64_t cr2;
} xen_hvm_inject_trap_t;

typedef struct {
    domid_t domid;
    uint32_t vector;
    uint8_t level;
} xen_hvm_set_pci_intx_level_t;

typedef struct {
    domid_t domid;
    uint8_t isa_irq;
    uint8_t level;
} xen_hvm_set_isa_irq_level_t;

typedef struct {
    domid_t domid;
    uint64_t addr;
    uint32_t data;
    uint8_t vector;
} xen_hvm_inject_msi_t;

typedef struct {
    domid_t domid;
    uint8_t link;
    uint8_t isa_irq;
} xen_hvm_set_pci_link_route_t;

enum {
    HVMOP_set_param = 0,
    HVMOP_get_param,
    HVMOP_set_pci_intx_level,
    HVMOP_set_isa_irq_level,
    HVMOP_inject_msi,
    HVMOP_set_pci_link_route,
    HVMOP_flush_tlbs,
    HVMOP_track_dirty_vram,
    HVMOP_modified_memory,
    HVMOP_get_mem_type,
    HVMOP_set_mem_type,
    HVMOP_set_mem_access,
    HVMOP_get_mem_access,
    HVMOP_pagetable_dying,
    HVMOP_get_time,
    HVMOP_xentrace,
    HVMOP_inject_trap
};

enum {
    HVM_PARAM_IOREQ_PFN = 0,
    HVM_PARAM_BUFIOREQ_PFN,
    HVM_PARAM_CALLBACK_IRQ,
    HVM_PARAM_TIMER_MODE,
    HVM_PARAM_VIRIDIAN,
    HVM_PARAM_IDENT_PT,
    HVM_PARAM_DM_DOMAIN,
    HVM_PARAM_ACPI_S_STATE,
    HVM_PARAM_ACPI_IOPORTS_LOCATION,
    HVM_PARAM_MEMORY_EVENT_CR0,
    HVM_PARAM_MEMORY_EVENT_CR3,
    HVM_PARAM_MEMORY_EVENT_CR4,
    HVM_PARAM_MEMORY_EVENT_INT3,
    HVM_PARAM_MEMORY_EVENT_SINGLE_STEP,
    HVM_PARAM_MEMORY_EVENT_MSR,
    HVM_PARAM_NESTEDHVM,
    HVM_PARAM_BUFIOREQ_EVTCHN,
    HVM_PARAM_TRIPLE_FAULT_REASON
};

enum {
    HVMPTM_one_missed_tick_pending = 1
};

enum {
    HVMMEM_ram_rw = 0,
    HVMMEM_ram_ro,
    HVMMEM_mmio_dm
};

enum {
    HVMPME_onchangeonly = 1
};

enum {
    TRC_GUEST = 0x10000,
    TRC_SUBCLS_SHIFT = 16
};

#define XSM_TARGET 0
#define XSM_PRIV 1

#define current ((struct vcpu *)0)
#define NOW() (0)

#define copy_from_guest(dst, src, count) (0)
#define copy_to_guest(dst, src, count) (0)
#define guest_handle_cast(hnd, type) (hnd)
#define guest_handle_is_null(hnd) (0)

#define rcu_lock_domain_by_any_id(id) ((struct domain *)0)
#define rcu_lock_remote_domain_by_id(id, d) (0)
#define rcu_unlock_domain(d) do {} while (0)
#define has_hvm_container_domain(d) (0)
#define is_pvh_domain(d) (0)
#define is_hvm_domain(d) (0)
#define paging_mode_hap(d) (0)
#define paging_mode_shadow(d) (0)
#define paging_mode_log_dirty(d) (0)
#define shadow_mode_enabled(d) (0)
#define domain_get_maximum_gpfn(d) (0)
#define domain_pause(d) do {} while (0)
#define domain_unpause(d) do {} while (0)
#define domctl_lock_acquire() (1)
#define domctl_lock_release() do {} while (0)
#define for_each_vcpu(d, v) for ((v) = NULL; (v) != NULL; (v) = NULL)
#define spin_lock(l) do {} while (0)
#define spin_unlock(l) do {} while (0)
#define get_ioreq(v) ((struct hvm_ioreq_page *)0)
#define hvm_set_ioreq_page(d, iorp, val) (0)
#define hvm_set_callback_via(d, val) do {} while (0)
#define hvm_latch_shinfo_size(d) do {} while (0)
#define hvm_replace_event_channel(v, val, port) (0)
#define hvm_s3_suspend(d) do {} while (0)
#define hvm_s3_resume(d) do {} while (0)
#define pmtimer_change_ioport(d, val) (0)
#define paging_update_cr3(v) do {} while (0)
#define xsm_hvm_param(type, d, op) (0)
#define xsm_hvm_param_nested(type, d) (0)
#define shadow_track_dirty_vram(d, pfn, nr, bitmap) (0)
#define hap_track_dirty_vram(d, pfn, nr, bitmap) (0)
#define get_page_from_gfn(d, pfn, t, flag) ((struct page_info *)0)
#define paging_mark_dirty(d, mfn) do {} while (0)
#define sh_remove_shadows(v, mfn, count, die) do {} while (0)
#define put_page(p) do {} while (0)
#define get_gfn_query_unlocked(d, pfn, t) do {} while (0)
#define get_gfn_unshare(d, pfn, t) ((mfn_t)0)
#define put_gfn(d, pfn) do {} while (0)
#define p2m_change_type(d, pfn, old, new) (old)
#define p2m_set_mem_access(d, pfn, nr, access) (0)
#define p2m_get_mem_access(d, pfn, access) (0)
#define pagetable_dying(d, gpa) do {} while (0)
#define trace_var(event, cycles, bytes, extra) do {} while (0)
#define hypercall_preempt_check() (0)
#define hypercall_create_continuation(op, fmt, ...) (0)
#define gdprintk(level, fmt, ...) do {} while (0)
#define HVM_DBG_LOG(level, fmt, ...) do {} while (0)

#define p2m_is_mmio(t) (0)
#define p2m_is_readonly(t) (0)
#define p2m_is_ram(t) (0)
#define p2m_is_pod(t) (0)
#define p2m_is_grant(t) (0)
#define p2m_is_paging(t) (0)
#define p2m_is_shared(t) (0)
#define p2m_mem_paging_populate(d, pfn) do {} while (0)

#define cpu_has_svm (0)
#define nestedhvm_vcpu_initialise(v) (0)
#define nestedhvm_vcpu_destroy(v) do {} while (0)

#define p2m_ram_rw 0
#define p2m_ram_ro 1
#define p2m_mmio_dm 2

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

struct hvm_function_table {
    void (*update_guest_cr)(struct vcpu *v, int cr);
} hvm_funcs = {0};

int hvmop_set_pci_intx_level(xen_hvm_set_pci_intx_level_t *arg) { return 0; }
int hvmop_set_isa_irq_level(xen_hvm_set_isa_irq_level_t *arg) { return 0; }
int hvmop_inject_msi(xen_hvm_inject_msi_t *arg) { return 0; }
int hvmop_set_pci_link_route(xen_hvm_set_pci_link_route_t *arg) { return 0; }
int hvmop_flush_tlb_all(void) { return 0; }