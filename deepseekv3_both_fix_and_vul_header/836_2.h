#include <stdint.h>
#include <stddef.h>

struct vcpu {
    struct {
        struct {
            unsigned long ctrlreg[8];
        } pv;
    } arch;
    struct domain *domain;
};

struct domain;
struct x86_emulate_ctxt;
struct page_info;

#define X86_CR0_TS (1UL << 3)
#define X86EMUL_OKAY 0
#define X86EMUL_RETRY 1
#define X86EMUL_UNHANDLEABLE 2
#define XENLOG_WARNING 1
#define P2M_ALLOC 0
#define ERESTART (-1)

extern struct vcpu *current;
extern unsigned long read_cr0(void);
extern void do_fpu_taskswitch(int);
extern void arch_set_cr2(struct vcpu *, unsigned long);
extern unsigned long xen_cr3_to_pfn(unsigned long);
extern unsigned long compat_cr3_to_pfn(unsigned long);
extern struct page_info *get_page_from_gfn(struct domain *, unsigned long, void *, int);
extern int new_guest_cr3(unsigned long);
extern void put_page(struct page_info *);
extern unsigned long pv_guest_cr4_fixup(struct vcpu *, unsigned long);
extern unsigned long pv_guest_cr4_to_real_cr4(struct vcpu *);
extern void write_cr4(unsigned long);
extern void ctxt_switch_levelling(struct vcpu *);
extern void gdprintk(int, const char *, ...);
extern int is_pv_32bit_domain(struct domain *);
extern unsigned long page_to_mfn(struct page_info *);