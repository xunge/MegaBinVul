#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define X86EMUL_UNHANDLEABLE 0
#define X86EMUL_EXCEPTION 1
#define X86EMUL_OKAY 2

#define TRAP_gp_fault 13

#define MSR_FS_BASE 0xc0000100
#define MSR_GS_BASE 0xc0000101
#define MSR_SHADOW_GS_BASE 0xc0000102
#define MSR_IA32_TSC 0x10
#define MSR_EFER 0xc0000080
#define MSR_K7_FID_VID_CTL 0xc0010041
#define MSR_K7_FID_VID_STATUS 0xc0010042
#define MSR_K8_PSTATE_LIMIT 0xc0010061
#define MSR_K8_PSTATE_CTRL 0xc0010062
#define MSR_K8_PSTATE_STATUS 0xc0010063
#define MSR_K8_PSTATE0 0xc0010064
#define MSR_K8_PSTATE1 0xc0010065
#define MSR_K8_PSTATE2 0xc0010066
#define MSR_K8_PSTATE3 0xc0010067
#define MSR_K8_PSTATE4 0xc0010068
#define MSR_K8_PSTATE5 0xc0010069
#define MSR_K8_PSTATE6 0xc001006a
#define MSR_K8_PSTATE7 0xc001006b
#define MSR_IA32_UCODE_REV 0x8b
#define MSR_AMD_PATCHLEVEL 0x8b
#define MSR_IA32_MISC_ENABLE 0x1a0
#define MSR_IA32_PERF_CAPABILITIES 0x345
#define MSR_P6_PERFCTR(n) (0xc1 + (n))
#define MSR_P6_EVNTSEL(n) (0x186 + (n))
#define MSR_CORE_PERF_FIXED_CTR0 0x309
#define MSR_CORE_PERF_FIXED_CTR1 0x30a
#define MSR_CORE_PERF_FIXED_CTR2 0x30b
#define MSR_CORE_PERF_FIXED_CTR_CTRL 0x38d
#define MSR_CORE_PERF_GLOBAL_OVF_CTRL 0x390
#define MSR_AMD_FAM15H_EVNTSEL0 0xc0010200
#define MSR_AMD_FAM15H_PERFCTR5 0xc0010205
#define MSR_K7_EVNTSEL0 0xc0010000
#define MSR_K7_PERFCTR3 0xc0010003

#define EFER_KNOWN_MASK 0xffffffffffffffff
#define EFER_SVME (1 << 12)
#define EFER_LME (1 << 8)
#define EFER_LMA (1 << 10)
#define EFER_SCE (1 << 0)

#define X86_VENDOR_INTEL 0
#define X86_VENDOR_AMD 1

#define X86_CR4_FSGSBASE (1 << 16)

struct x86_emulate_ctxt {
    void *regs;
};

struct vcpu {
    struct domain *domain;
    struct {
        struct {
            uint64_t fs_base;
            uint64_t gs_base_kernel;
            uint64_t gs_base_user;
        } pv;
    } arch;
};

struct domain {
    struct {
        bool vtsc;
        bool pv_32bit;
    } arch;
};

struct cpuinfo_x86 {
    int x86_vendor;
} boot_cpu_data;

static inline bool is_pv_32bit_domain(const struct domain *d) { return d->arch.pv_32bit; }
static inline bool cpu_has_fsgsbase(void) { return false; }
static inline uint64_t __rdfsbase(void) { return 0; }
static inline uint64_t __rdgsbase(void) { return 0; }
static inline uint64_t rdtsc(void) { return 0; }
static inline uint64_t read_efer(void) { return 0; }
static inline bool is_cpufreq_controller(const struct domain *d) { return false; }
static inline int wrmsr_safe(unsigned int reg, uint64_t val) { return 0; }
static inline void cpuid_eax(unsigned int op) {}
static inline uint64_t guest_misc_enable(uint64_t val) { return val; }
static inline bool vpmu_do_rdmsr(unsigned int reg, uint64_t *val) { return false; }
static inline int vmce_rdmsr(unsigned int reg, uint64_t *val) { return 0; }
static inline int rdmsr_safe(unsigned int reg, uint64_t val) { return 0; }
static inline void x86_emul_hw_exception(int trap, int error_code, struct x86_emulate_ctxt *ctxt) {}
static inline int guest_rdmsr(const struct vcpu *vcpu, unsigned int reg, uint64_t *val) { return 0; }
static inline uint64_t pv_soft_rdtsc(const struct vcpu *vcpu, void *regs) { return 0; }
static inline void rdmsrl(unsigned int reg, uint64_t *val) {}
static inline int unlikely(int x) { return x; }
static inline void BUILD_BUG_ON(int condition) {}
static inline uint64_t read_cr4(void) { return 0; }

extern struct vcpu *current;