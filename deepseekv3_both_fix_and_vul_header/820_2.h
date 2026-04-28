#include <stdint.h>
#include <stddef.h>

#define current (&dummy_vcpu)

struct vcpu dummy_vcpu;

struct vcpu {
    struct {
        struct {
            unsigned long ctrlreg[8];
            unsigned long fs_base;
            unsigned long gs_base_kernel;
        } pv;
    } arch;
    struct domain *domain;
};

struct domain {
    int is_pv_32bit;
};

struct x86_emulate_ctxt {
    int dummy;
};

struct page_info {
    unsigned long mfn;
};

#define X86_CR0_TS (1UL << 3)
#define X86_CR4_FSGSBASE (1UL << 16)
#define XENLOG_WARNING 1
#define X86EMUL_OKAY 0
#define X86EMUL_RETRY 1
#define X86EMUL_UNHANDLEABLE 2
#define P2M_ALLOC 0
#define ERESTART (-512)

static inline int is_pv_32bit_domain(struct domain *d) { return d->is_pv_32bit; }
static inline unsigned long page_to_mfn(struct page_info *page) { return page->mfn; }

static unsigned long read_cr0(void) { return 0; }
static void gdprintk(int level, const char *fmt, ...) {}
static void do_fpu_taskswitch(int flag) {}
static void arch_set_cr2(struct vcpu *v, unsigned long val) {}
static unsigned long xen_cr3_to_pfn(unsigned long cr3) { return 0; }
static unsigned long compat_cr3_to_pfn(unsigned long cr3) { return 0; }
static struct page_info *get_page_from_gfn(struct domain *d, unsigned long gfn, void *p, int alloc) { return NULL; }
static int new_guest_cr3(unsigned long mfn) { return 0; }
static void put_page(struct page_info *page) {}
static unsigned long pv_fixup_guest_cr4(struct vcpu *v, unsigned long cr4) { return 0; }
static unsigned long pv_make_cr4(struct vcpu *v) { return 0; }
static void write_cr4(unsigned long val) {}
static void ctxt_switch_levelling(struct vcpu *v) {}
static unsigned long __rdfsbase(void) { return 0; }
static unsigned long __rdgsbase(void) { return 0; }