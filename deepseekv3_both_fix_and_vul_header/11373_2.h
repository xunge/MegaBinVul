#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <errno.h>

#define MSR_IA32_DEBUGCTLMSR 0x1d9
#define MSR_CORE_PERF_GLOBAL_OVF_CTRL 0x390
#define MSR_CORE_PERF_GLOBAL_STATUS 0x38e
#define MSR_IA32_PEBS_ENABLE 0x3f1
#define MSR_IA32_DS_AREA 0x600
#define MSR_CORE_PERF_GLOBAL_CTRL 0x38f
#define MSR_CORE_PERF_FIXED_CTR_CTRL 0x38d

#define IA32_DEBUGCTLMSR_TR (1 << 6)
#define IA32_DEBUGCTLMSR_BTS (1 << 7)
#define IA32_DEBUGCTLMSR_BTINT (1 << 8)
#define IA32_DEBUGCTLMSR_BTS_OFF_OS (1 << 9)
#define IA32_DEBUGCTLMSR_BTS_OFF_USR (1 << 10)

#define MSR_IA32_CMT_EVTSEL_UE_MASK 0x00ffff00
#define MSR_P6_EVNTSEL(n) (0x186 + (n))

#define XENPMU_FEATURE_IPC_ONLY (1 << 0)
#define XENPMU_FEATURE_ARCH_ONLY (1 << 1)
#define XENPMU_FEATURE_INTEL_BTS (1 << 2)

#define VPMU_CPU_HAS_BTS (1 << 0)
#define VPMU_CPU_HAS_DS (1 << 1)
#define VPMU_RUNNING (1 << 2)

#define MSR_TYPE_GLOBAL 1
#define MSR_TYPE_COUNTER 2
#define FIXED_CTR_CTRL_BITS 4
#define ARCH_CNTR_ENABLED (1ULL << 22)
#define ARCH_CTRL_MASK (~((1ULL << 32) - 1))

#define X86_FEATURE_DSCPL 0
#define EINVAL 22

typedef uint64_t u64;
typedef bool bool_t;

struct vcpu {
    // dummy definition
};

struct vpmu_struct {
    void *context;
    void *priv_context;
    // other members
};

struct xen_pmu_intel_ctxt {
    uint64_t global_status;
    uint64_t global_ctrl;
    uint64_t fixed_ctrl;
    uint64_t ds_area;
    // other members
};

struct xen_pmu_cntr_pair {
    uint64_t control;
    // other members
};

extern uint64_t fixed_counters_mask;
extern uint64_t global_ovf_ctrl_mask;
extern uint64_t global_ctrl_mask;
extern uint64_t fixed_ctrl_mask;
extern unsigned int fixed_pmc_cnt;
extern unsigned int arch_pmc_cnt;
extern unsigned int vpmu_features;
extern const char *arch_counters;

static struct vcpu *current;
static struct vcpu_data {
    int features;
} current_cpu_data;

static inline int cpu_has(struct vcpu_data *data, int feature) {
    return data->features & feature;
}

static inline struct vpmu_struct *vcpu_vpmu(struct vcpu *v) {
    return NULL;
}

static inline int vpmu_is_set(struct vpmu_struct *vpmu, int flag) {
    return 0;
}

static inline void vpmu_set(struct vpmu_struct *vpmu, int flag) {}
static inline void vpmu_reset(struct vpmu_struct *vpmu, int flag) {}

static inline int is_hvm_vcpu(struct vcpu *v) {
    return 0;
}

static inline int is_canonical_address(uint64_t addr) {
    return 1;
}

static inline int __addr_ok(uint64_t addr) {
    return 1;
}

static inline void wrmsrl(unsigned int msr, uint64_t val) {}
static inline void rdmsrl(unsigned int msr, uint64_t *val) {}

static inline void vmx_read_guest_msr(struct vcpu *v, unsigned int msr, uint64_t *val) {}
static inline void vmx_write_guest_msr(struct vcpu *v, unsigned int msr, uint64_t val) {}

static inline int core2_vpmu_msr_common_check(unsigned int msr, int *type, int *index) {
    return 0;
}

#define ASSERT(cond) ((void)0)
#define printk(level, fmt, ...) ((void)0)
#define gdprintk(level, fmt, ...) ((void)0)
#define XENLOG_G_WARNING 0
#define XENLOG_INFO 0
#define XENLOG_WARNING 0
#define PRIx64 "lx"

static inline void *vpmu_reg_pointer(struct xen_pmu_intel_ctxt *cxt, const char *name) {
    return NULL;
}