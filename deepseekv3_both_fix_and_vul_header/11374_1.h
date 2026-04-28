#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

#define X86EMUL_OKAY 0
#define X86EMUL_EXCEPTION 1
#define X86EMUL_RETRY 2
#define XENLOG_ERR 1
#define DBG_LEVEL_MSR 0
#define HVM_DBG_LOG(level, fmt, ...) 

#define GUEST_SYSENTER_CS 0x4824
#define GUEST_SYSENTER_ESP 0x4828
#define GUEST_SYSENTER_EIP 0x482C
#define GUEST_FS_BASE 0x6000
#define GUEST_GS_BASE 0x6008
#define GUEST_IA32_DEBUGCTL 0x1C06

#define ERESTART 512

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

struct vcpu {
    struct {
        struct {
            uint64_t star;
            uint64_t lstar;
            uint64_t cstar;
            uint64_t sfmask;
            uint64_t lbr_flags;
        } hvm_vmx;
    } arch;
    struct domain *domain;
};

struct domain {
    struct {
        struct cpuid_policy *cpuid;
    } arch;
};

struct cpuid_policy {
    struct {
        unsigned int rtm;
    } feat;
};

struct cpu_info {
    int x86;
};

struct lbr_info {
    unsigned int base;
    unsigned int count;
};

#define MSR_IA32_SYSENTER_CS 0x174
#define MSR_IA32_SYSENTER_ESP 0x175
#define MSR_IA32_SYSENTER_EIP 0x176
#define MSR_FS_BASE 0xC0000100
#define MSR_GS_BASE 0xC0000101
#define MSR_SHADOW_GS_BASE 0xC0000102
#define MSR_STAR 0xC0000081
#define MSR_LSTAR 0xC0000082
#define MSR_CSTAR 0xC0000083
#define MSR_SYSCALL_MASK 0xC0000084
#define MSR_IA32_DEBUGCTLMSR 0x1D9
#define MSR_IA32_FEATURE_CONTROL 0x3A
#define MSR_IA32_VMX_BASIC 0x480
#define MSR_IA32_VMX_VMFUNC 0x491

#define IA32_DEBUGCTLMSR_LBR (1 << 0)
#define IA32_DEBUGCTLMSR_BTF (1 << 1)
#define IA32_DEBUGCTLMSR_TR (1 << 6)
#define IA32_DEBUGCTLMSR_BTS (1 << 7)
#define IA32_DEBUGCTLMSR_BTINT (1 << 8)
#define IA32_DEBUGCTLMSR_BTS_OFF_OS (1 << 9)
#define IA32_DEBUGCTLMSR_BTS_OFF_USR (1 << 10)
#define IA32_DEBUGCTLMSR_RTM (1 << 11)

#define LBR_MSRS_INSERTED (1 << 0)
#define LBR_FIXUP_TSX (1 << 1)
#define LBR_FIXUP_BDF14 (1 << 2)

#define X86_FEATURE_RTM (1 << 11)
#define X86_FEATURE_DSCPL (1 << 12)

#define VMX_MSR_RW (1 << 0)

static struct vcpu *current;
static int lbr_tsx_fixup_needed;
static int bdw_erratum_bdf14_fixup_needed;
static struct cpu_info current_cpu_data;

static inline int is_canonical_address(uint64_t addr) { return 1; }
static inline void __vmwrite(uint64_t field, uint64_t val) {}
static inline void wrgsshadow(uint64_t val) {}
static inline void wrmsrl(uint32_t msr, uint64_t val) {}
static inline int vpmu_do_wrmsr(uint32_t msr, uint64_t val, uint64_t supported) { return 0; }
static inline int passive_domain_do_wrmsr(uint32_t msr, uint64_t val) { return 0; }
static inline int wrmsr_viridian_regs(uint32_t msr, uint64_t val) { return 0; }
static inline int vmx_write_guest_msr(struct vcpu *v, uint32_t msr, uint64_t val) { return 0; }
static inline int is_last_branch_msr(uint32_t msr) { return 0; }
static inline int wrmsr_hypervisor_regs(uint32_t msr, uint64_t val) { return 0; }
static inline int rdmsr_safe(uint32_t msr, uint64_t *val) { return 0; }
static inline const struct lbr_info *last_branch_msr_get(void) { return NULL; }
static inline int vmx_add_guest_msr(struct vcpu *v, uint32_t msr, int flags) { return 0; }
static inline void vmx_clear_msr_intercept(struct vcpu *v, uint32_t msr, int flags) {}
static inline void gprintk(int level, const char *fmt, ...) {}
static inline void domain_crash(struct domain *d) {}
static inline int boot_cpu_has(int feature) { return 0; }
static inline struct vcpu *vcpu_vpmu(struct vcpu *v) { return v; }
static inline int vpmu_is_set(struct vcpu *v, int flag) { return 0; }
static inline int cpu_has(struct cpu_info *data, int feature) { return 0; }

#define VPMU_CPU_HAS_BTS 0
#define MSR_P6_PERFCTR(n) (0xC1 + (n))
#define MSR_P6_EVNTSEL(n) (0x186 + (n))
#define MSR_CORE_PERF_FIXED_CTR0 0x309
#define MSR_CORE_PERF_FIXED_CTR1 0x30A
#define MSR_CORE_PERF_FIXED_CTR2 0x30B
#define MSR_CORE_PERF_FIXED_CTR_CTRL 0x38D
#define MSR_CORE_PERF_GLOBAL_OVF_CTRL 0x390
#define MSR_IA32_PEBS_ENABLE 0x3F1
#define MSR_IA32_DS_AREA 0x600