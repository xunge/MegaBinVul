#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct page_list_head {
    struct page_list_head *next;
    struct page_list_head *prev;
};

struct arch_domain {
    struct page_list_head relmem_list;
    void *e820_lock;
    struct arch_csw *ctxt_switch;
    void *cpuid;
    void *msr;
    uint32_t emulation_flags;
    void *ioport_caps;
    int x87_fip_width;
    bool msr_relaxed;
};

struct domain {
    int domain_id;
    struct arch_domain arch;
    void *shared_info;
    bool is_dying;
};

struct xen_domctl_createdomain_arch {
    uint32_t emulation_flags;
    unsigned int misc_flags;
};

struct xen_domctl_createdomain {
    struct xen_domctl_createdomain_arch arch;
    unsigned int iommu_opts;
};

struct arch_csw {
    void (*from)(void);
    void (*to)(void);
    void (*tail)(void);
};

#define INIT_PAGE_LIST_HEAD(list) do { (list)->next = (list); (list)->prev = (list); } while (0)
#define ZERO_BLOCK_PTR NULL
#define XEN_X86_EMU_PIT (1U << 0)
#define XEN_X86_EMU_ALL 0xFFFFFFFF
#define MEMF_bits(bits) (0)
#define SHARE_rw (0)
#define TSC_MODE_DEFAULT (0)
#define DOMDYING_dead (0)
#define XEN_X86_MSR_RELAXED (1U << 0)
#define RANGESETF_prettyprint_hex (0)

#define unlikely(x) (x)
#define is_idle_domain(d) (0)
#define is_hardware_domain(d) (0)
#define is_pv_domain(d) (0)
#define is_hvm_domain(d) (0)
#define ASSERT_UNREACHABLE() 
#define printk(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define XENLOG_G_ERR ""
#define XENLOG_G_WARNING ""

static inline void spin_lock_init(void *lock) {}
static inline void *virt_to_page(void *virt) { return virt; }

static bool opt_allow_unsafe;
static struct {
    int dummy;
} boot_cpu_data;
#define AMD_ERRATUM_121 0

static int paging_domain_init(void *d) { return 0; }
static int init_domain_cpuid_policy(void *d) { return 0; }
static int init_domain_msr_policy(void *d) { return 0; }
static void *rangeset_new(void *d, const char *s, int flags) { return NULL; }
static void *alloc_xenheap_pages(int a, int b) { return NULL; }
static void clear_page(void *p) {}
static void share_xen_page_with_guest(void *p, void *d, int flags) {}
static int init_domain_irq_mapping(void *d) { return 0; }
static int iommu_domain_init(void *d, unsigned int opts) { return 0; }
static void psr_domain_init(void *d) {}
static int hvm_domain_initialise(void *d) { return 0; }
static void mapcache_domain_init(void *d) {}
static int pv_domain_initialise(void *d) { return 0; }
static int tsc_set_info(void *d, int mode, int a, int b, int c) { return 0; }
static void pit_init(void *d, int khz) {}
static void domain_cpu_policy_changed(void *d) {}
static void psr_domain_free(void *d) {}
static void iommu_domain_destroy(void *d) {}
static void cleanup_domain_irq_mapping(void *d) {}
static void free_xenheap_page(void *p) {}
static void xfree(void *p) {}
static void paging_final_teardown(void *d) {}
static void free_perdomain_mappings(void *d) {}
static int emulation_flags_ok(void *d, uint32_t flags) { return 1; }
static int cpu_has_amd_erratum(void *data, int erratum) { return 0; }
static int cpu_has_fpu_sel = 0;
static int cpu_khz = 0;

void paravirt_ctxt_switch_from(void) {}
void paravirt_ctxt_switch_to(void) {}
void idle_loop(void) {}

#define EINVAL 22
#define EPERM 1
#define EOPNOTSUPP 95
#define ENOMEM 12