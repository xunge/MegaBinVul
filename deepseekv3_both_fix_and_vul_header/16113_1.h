#include <stdint.h>
#include <stdbool.h>

#define X86EMUL_UNHANDLEABLE 0
#define X86EMUL_EXCEPTION 1
#define X86EMUL_OKAY 2

#define TRAP_gp_fault 13

#define MSR_APIC_BASE 0x1B
#define MSR_FS_BASE 0xC0000100
#define MSR_GS_BASE 0xC0000101
#define MSR_SHADOW_GS_BASE 0xC0000102
#define MSR_IA32_TSC 0x10
#define MSR_EFER 0xC0000080
#define MSR_IA32_CR_PAT 0x277
#define MSR_K7_FID_VID_CTL 0xC0010041
#define MSR_K7_FID_VID_STATUS 0xC0010042
#define MSR_K8_PSTATE_LIMIT 0xC0010061
#define MSR_K8_PSTATE_CTRL 0xC0010062
#define MSR_K8_PSTATE_STATUS 0xC0010063
#define MSR_K8_PSTATE0 0xC0010064
#define MSR_K8_PSTATE1 0xC0010065
#define MSR_K8_PSTATE2 0xC0010066
#define MSR_K8_PSTATE3 0xC0010067
#define MSR_K8_PSTATE4 0xC0010068
#define MSR_K8_PSTATE5 0xC0010069
#define MSR_K8_PSTATE6 0xC001006A
#define MSR_K8_PSTATE7 0xC001006B
#define MSR_FAM10H_MMIO_CONF_BASE 0xC0010058
#define MSR_AMD64_NB_CFG 0xC001001F
#define MSR_IA32_MISC_ENABLE 0x1A0
#define MSR_IA32_PERF_CAPABILITIES 0x345
#define MSR_P6_PERFCTR(n) (0xC1 + (n))
#define MSR_P6_EVNTSEL(n) (0x186 + (n))
#define MSR_CORE_PERF_FIXED_CTR0 0x309
#define MSR_CORE_PERF_FIXED_CTR1 0x30A
#define MSR_CORE_PERF_FIXED_CTR2 0x30B
#define MSR_CORE_PERF_FIXED_CTR_CTRL 0x38D
#define MSR_CORE_PERF_GLOBAL_OVF_CTRL 0x390
#define MSR_AMD_FAM15H_EVNTSEL0 0xC0010200
#define MSR_AMD_FAM15H_PERFCTR5 0xC0010205
#define MSR_K7_EVNTSEL0 0xC0010000
#define MSR_K7_PERFCTR3 0xC0010003

#define APIC_BASE_ENABLE (1UL << 11)
#define APIC_DEFAULT_PHYS_BASE 0xFEE00000
#define APIC_BASE_BSP (1UL << 8)
#define XEN_MSR_PAT 0x0007040600070406ULL

#define X86_VENDOR_AMD 0
#define X86_VENDOR_INTEL 1
#define X86_VENDOR_HYGON 2

#define XENLOG_WARNING 0
#define unlikely(x) (x)

struct x86_emulate_ctxt {
    void *regs;
};

struct vcpu {
    struct domain *domain;
    unsigned int vcpu_id;
    struct {
        struct {
            uint64_t gs_base_user;
        } pv;
    } arch;
};

struct domain {
    struct {
        bool vtsc;
    } arch;
};

struct cpuinfo_x86 {
    int x86_vendor;
    int x86;
} boot_cpu_data;

static struct vcpu *current;

static inline uint64_t rdfsbase(void) { return 0; }
static inline uint64_t rdgsbase(void) { return 0; }
static inline uint64_t rdtsc(void) { return 0; }
static inline uint64_t pv_soft_rdtsc(struct vcpu *vcpu, void *regs) { return 0; }
static inline uint64_t guest_efer(const struct domain *d) { return 0; }
static inline bool is_pv_32bit_domain(const struct domain *d) { return false; }
static inline bool is_hwdom_pinned_vcpu(const struct vcpu *v) { return false; }
static inline bool is_cpufreq_controller(const struct domain *d) { return false; }
static inline int guest_rdmsr(struct vcpu *v, unsigned int reg, uint64_t *val) { return 0; }
static inline void x86_emul_hw_exception(int trap, int error, struct x86_emulate_ctxt *ctxt) {}
static inline uint64_t guest_misc_enable(uint64_t val) { return val; }
static inline int rdmsr_safe(unsigned int reg, uint64_t val) { return 0; }
static inline void gdprintk(int level, const char *fmt, ...) {}
static inline int vpmu_do_rdmsr(unsigned int reg, uint64_t *val) { return 0; }
static inline void rdmsrl(unsigned int reg, uint64_t *val) { *val = 0; }