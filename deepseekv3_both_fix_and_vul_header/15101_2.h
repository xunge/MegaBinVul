#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint64_t u64;

#define CONFIG_X86_64 1

#define MSR_EFER 0xC0000080
#define MSR_FS_BASE 0xC0000100
#define MSR_GS_BASE 0xC0000101
#define MSR_IA32_SYSENTER_CS 0x174
#define MSR_IA32_SYSENTER_EIP 0x176
#define MSR_IA32_SYSENTER_ESP 0x175
#define MSR_IA32_TIME_STAMP_COUNTER 0x10
#define MSR_P6_PERFCTR0 0xC1
#define MSR_P6_PERFCTR1 0xC2
#define MSR_P6_EVNTSEL0 0x186
#define MSR_P6_EVNTSEL1 0x187
#define MSR_IA32_CR_PAT 0x277

#define VM_ENTRY_LOAD_IA32_PAT (1 << 14)
#define GUEST_FS_BASE 0x00006800
#define GUEST_GS_BASE 0x00006802
#define GUEST_SYSENTER_CS 0x0000482A
#define GUEST_SYSENTER_EIP 0x0000681E
#define GUEST_SYSENTER_ESP 0x00006820
#define GUEST_IA32_PAT 0x00002804

struct kvm_vcpu {
    struct {
        u64 pat;
    } arch;
};

struct vcpu_vmx;
struct kvm_msr_entry {
    u64 data;
};

struct vmcs_config {
    u32 vmentry_ctrl;
} vmcs_config;

static inline struct vcpu_vmx *to_vmx(struct kvm_vcpu *vcpu) { return NULL; }
static inline void vmx_load_host_state(struct vcpu_vmx *vmx) {}
static inline void vmcs_writel(u32 field, u64 value) {}
static inline void vmcs_write32(u32 field, u32 value) {}
static inline void vmcs_write64(u32 field, u64 value) {}
static inline void rdtscll(u64 *tsc) {}
static inline void guest_write_tsc(u64 guest_tsc, u64 host_tsc) {}
static inline void pr_unimpl(struct kvm_vcpu *vcpu, const char *fmt, ...) {}
static inline struct kvm_msr_entry *find_msr_entry(struct vcpu_vmx *vmx, u32 msr_index) { return NULL; }
static inline int kvm_set_msr_common(struct kvm_vcpu *vcpu, u32 msr_index, u64 data) { return 0; }