#include <stdint.h>
#include <stddef.h>

struct vcpu {
    unsigned int vcpu_id;
    struct domain *domain;
    struct {
        uint64_t xcr0;
        struct {
            uint64_t guest_cr[5];
            uint64_t msr_xss;
        } hvm_vcpu;
    } arch;
};

struct domain {
    struct {
        int x86_vendor;
        struct {
            unsigned int gfn_bits;
        } paging;
    } arch;
};

extern struct vcpu *current;
extern unsigned int hvm_featureset[];
extern unsigned int host_featureset[];
extern unsigned int special_features[];
extern unsigned int xstate_sizes[];
extern unsigned long xstate_align;

#define FEATURESET_1c 0
#define FEATURESET_1d 1
#define FEATURESET_7b0 2
#define FEATURESET_7c0 3
#define FEATURESET_Da1 4
#define FEATURESET_e1c 5
#define FEATURESET_e1d 6
#define FEATURESET_e7d 7
#define FEATURESET_e8b 8

#define X86_FEATURE_APIC 0
#define X86_FEATURE_OSXSAVE 1
#define X86_FEATURE_PCID 2
#define X86_FEATURE_PSE36 3
#define X86_FEATURE_INVPCID 4
#define X86_FEATURE_PKU 5
#define X86_FEATURE_OSPKE 6
#define X86_FEATURE_PAGE1GB 7
#define X86_FEATURE_LM 8
#define X86_FEATURE_PAE 9
#define X86_FEATURE_XSAVES 10

#define X86_CR4_OSXSAVE (1 << 18)
#define X86_CR4_PKE (1 << 22)

#define XSTATE_FP_SSE (1ULL << 0)
#define XSTATE_AREA_MIN_SIZE 576

#define PAGE_SHIFT 12

#define CPUID_COMMON_1D_FEATURES 0

#define X86_VENDOR_AMD 0

#define cpufeat_bit(x) (1u << (x))
#define cpufeat_mask(x) (1u << (x))

#define ROUNDUP(x, align) (((x) + (align) - 1) & ~((align) - 1))

static inline int test_bit(unsigned int nr, const unsigned long *addr) {
    return (addr[nr / (8 * sizeof(long))] >> (nr % (8 * sizeof(long)))) & 1;
}

int cpuid_viridian_leaves(unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int*);
int cpuid_hypervisor_leaves(unsigned int, unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int*);
void domain_cpuid(struct domain*, unsigned int, unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int*);
int hap_enabled(struct domain*);
int hvm_pae_enabled(struct vcpu*);
int hvm_long_mode_enabled(struct vcpu*);
int vlapic_hw_disabled(void*);
void* vcpu_vlapic(struct vcpu*);