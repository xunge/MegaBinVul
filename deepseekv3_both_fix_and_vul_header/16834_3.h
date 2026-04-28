#include <stdint.h>
#include <stdbool.h>

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define array_index_nospec(index, size) (index)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define X86EMUL_OKAY 0
#define X86EMUL_UNHANDLEABLE 1
#define X86EMUL_EXCEPTION 2
#define likely(x) __builtin_expect(!!(x), 1)
#define ASSERT(cond) ((void)0)

#define MSR_IA32_PLATFORM_ID 0x17
#define MSR_CORE_CAPABILITIES 0xCF
#define MSR_INTEL_CORE_THREAD_COUNT 0x35
#define MSR_INTEL_PLATFORM_INFO 0xCE
#define MSR_ARCH_CAPABILITIES 0x10A
#define MSR_TEST_CTRL 0x33
#define MSR_TSX_FORCE_ABORT 0x10F
#define MSR_TSX_CTRL 0x122
#define MSR_MCU_OPT_CTRL 0x123
#define MSR_RTIT_OUTPUT_BASE 0x560
#define MSR_RTIT_ADDR_B(n) (0x580 + (n))
#define MSR_U_CET 0x1A0
#define MSR_S_CET 0x1A2
#define MSR_PL0_SSP 0x6A4
#define MSR_INTERRUPT_SSP_TABLE 0x6A8
#define MSR_AMD64_LWP_CFG 0xC0000100
#define MSR_AMD64_LWP_CBADDR 0xC0000101
#define MSR_PPIN_CTL 0x4E
#define MSR_PPIN 0x4F
#define MSR_AMD_PPIN_CTL 0xC0000102
#define MSR_AMD_PPIN 0xC0000103
#define MSR_AMD_PATCHLEVEL 0x8B
#define MSR_IA32_UCODE_REV 0x8B
#define MSR_AMD_PATCHLOADER 0xC0010020
#define MSR_IA32_UCODE_WRITE 0x79
#define MSR_SPEC_CTRL 0x48
#define MSR_PRED_CMD 0x49
#define MSR_FLUSH_CMD 0x10B
#define MSR_INTEL_MISC_FEATURES_ENABLES 0x140
#define MSR_IA32_MCG_CAP 0x179
#define MSR_IA32_MCG_CTL 0x17B
#define MSR_IA32_MCx_CTL2(n) (0x280 + (n))
#define MSR_IA32_MCx_CTL(n) (0x400 + (n))
#define MSR_IA32_MCx_MISC(n) (0x404 + (n))
#define MSR_IA32_MCG_EXT_CTL 0x4D0
#define MSR_IA32_PERF_CTL 0x199
#define MSR_PKRS 0x6E0
#define MSR_X2APIC_FIRST 0x800
#define MSR_X2APIC_LAST 0x8FF
#define MSR_IA32_BNDCFGS 0xD90
#define MSR_IA32_XSS 0xDA0
#define MSR_TSC_AUX 0xC0000104
#define MSR_VIRT_SPEC_CTRL 0xC001011F
#define MSR_AMD64_DE_CFG 0xC001102C
#define MSR_AMD64_DR0_ADDRESS_MASK 0xC0011027
#define MSR_AMD64_DR1_ADDRESS_MASK 0xC0011028
#define MSR_AMD64_DR2_ADDRESS_MASK 0xC0011029
#define MSR_AMD64_DR3_ADDRESS_MASK 0xC001102B

#define X86_VENDOR_INTEL 0
#define X86_VENDOR_AMD 1
#define X86_VENDOR_CENTAUR 2
#define X86_VENDOR_HYGON 3

#define PRED_CMD_IBPB (1ULL << 0)
#define PRED_CMD_SBPB (1ULL << 1)
#define FLUSH_CMD_L1D (1ULL << 0)
#define MSR_MISC_FEATURES_CPUID_FAULTING (1ULL << 0)
#define IA32_BNDCFGS_RESERVED (~0x3FFULL)
#define IA32_BNDCFGS_ENABLE (1ULL << 0)
#define X86_XCR0_BNDREGS (1ULL << 3)
#define X86_XCR0_BNDCSR (1ULL << 4)
#define SPEC_CTRL_SSBD (1ULL << 2)
#define DR7_ACTIVE_MASK 0xFFFF

struct vcpu {
    struct domain *domain;
    struct {
        struct vcpu_msrs *msrs;
        uint64_t xcr0_accum;
        uint64_t dr7;
    } arch;
};

struct domain {
    struct {
        const struct cpu_policy *cpu_policy;
    } arch;
};

struct cpu_policy {
    unsigned int x86_vendor;
    struct {
        bool ibrsb;
        bool l1d_flush;
        bool pks;
        bool mpx;
        bool rdpid;
    } feat;
    struct {
        bool ibrs;
        bool ibpb;
        bool sbpb;
        bool virt_ssbd;
        bool dbext;
        bool rdtscp;
    } extd;
    struct {
        bool xsaves;
    } xstate;
    struct {
        bool cpuid_faulting;
    } platform_info;
};

struct vcpu_msrs {
    struct {
        uint64_t raw;
        bool cpuid_faulting;
    } misc_features_enables;
    struct {
        uint64_t raw;
    } xss;
    uint32_t tsc_aux;
    struct {
        uint64_t raw;
    } spec_ctrl;
    struct {
        uint64_t raw;
    } virt_spec_ctrl;
    uint32_t dr_mask[4];
};

extern const struct vcpu *current;
extern bool is_pv_domain(const struct domain *d);
extern bool is_hvm_domain(const struct domain *d);
extern bool is_viridian_domain(const struct domain *d);
extern bool is_cpufreq_controller(const struct domain *d);
extern bool cpu_has_cpuid_faulting;
extern bool cpu_has_amd_ssbd;
extern uint64_t msr_spec_ctrl_valid_bits(const struct cpu_policy *cp);
extern int vmce_wrmsr(uint32_t msr, uint64_t val);
extern int guest_wrmsr_x2apic(struct vcpu *v, uint32_t msr, uint64_t val);
extern int guest_wrmsr_viridian(struct vcpu *v, uint32_t msr, uint64_t val);
extern int guest_wrmsr_xen(struct vcpu *v, uint32_t msr, uint64_t val);
extern void wrmsrl(uint32_t msr, uint64_t val);
extern void wrmsr_tsc_aux(uint32_t val);
extern void amd_set_legacy_ssbd(bool val);
extern uint64_t get_xcr0(void);
extern int handle_xsetbv(uint32_t index, uint64_t val);
extern int wrmsr_safe(uint32_t msr, uint64_t val);
extern int pv_set_reg(struct vcpu *v, uint32_t msr, uint64_t val);
extern int hvm_set_reg(struct vcpu *v, uint32_t msr, uint64_t val);
extern void ctxt_switch_levelling(struct vcpu *v);