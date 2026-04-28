#include <stdbool.h>
#include <stdint.h>

#define X86_CR4_PCIDE (1UL << 17)
#define X86_CR4_TSD   (1UL << 2)
#define X86_CR4_PGE   (1UL << 7)

struct vcpu {
    struct {
        unsigned long cr3;
    } arch;
    struct domain *domain;
};

struct domain {
    struct {
        struct {
            bool xpti;
        } pv;
    } arch;
};

struct cpu_info {
    bool root_pgt_changed;
    unsigned long pv_cr3;
    bool use_pv_cr3;
    unsigned long xen_cr3;
};

extern struct cpu_info *get_cpu_info(void);
extern unsigned long read_cr4(void);
extern bool is_pv_vcpu(struct vcpu *v);
extern bool is_idle_vcpu(struct vcpu *v);
extern unsigned long pv_guest_cr4_to_real_cr4(struct vcpu *v);
extern unsigned long __pa(void *ptr);
extern unsigned long get_pcid_bits(struct vcpu *v, bool b);
extern void switch_cr3_cr4(unsigned long cr3, unsigned long cr4);
extern unsigned long mmu_cr4_features;
extern void *root_pgt;
#define this_cpu(ptr) (ptr)
#define ASSERT(cond) ((void)0)