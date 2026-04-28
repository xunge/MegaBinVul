#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint64_t gfn_t;

#define MSR_AMD64_NB_CFG 0xc001001f
#define MSR_IA32_UCODE_REV 0x8b
#define MSR_IA32_UCODE_WRITE 0x79
#define MSR_VM_HSAVE_PA 0xc0010117
#define MSR_AMD64_PATCH_LOADER 0xc0010020
#define MSR_AMD64_BU_CFG2 0xc001102a
#define MSR_EFER 0xc0000080
#define MSR_K7_HWCR 0xc0010015
#define MSR_FAM10H_MMIO_CONF_BASE 0xc0010058
#define MSR_IA32_DEBUGCTLMSR 0x1d9
#define MSR_IA32_APICBASE 0x1b
#define APIC_BASE_MSR 0x800
#define MSR_IA32_TSCDEADLINE 0x6e0
#define MSR_IA32_TSC_ADJUST 0x3b
#define MSR_IA32_MISC_ENABLE 0x1a0
#define MSR_KVM_WALL_CLOCK_NEW 0x4b564d00
#define MSR_KVM_WALL_CLOCK 0x11
#define MSR_KVM_SYSTEM_TIME_NEW 0x4b564d01
#define MSR_KVM_SYSTEM_TIME 0x12
#define MSR_KVM_ASYNC_PF_EN 0x4b564d02
#define MSR_KVM_STEAL_TIME 0x4b564d03
#define MSR_KVM_PV_EOI_EN 0x4b564d04
#define MSR_IA32_MCG_CTL 0x17b
#define MSR_IA32_MCG_STATUS 0x17a
#define MSR_IA32_MC0_CTL 0x400
#define MSR_K7_EVNTSEL0 0xc0010000
#define MSR_K7_EVNTSEL1 0xc0010001
#define MSR_K7_EVNTSEL2 0xc0010002
#define MSR_K7_EVNTSEL3 0xc0010003
#define MSR_K7_PERFCTR0 0xc0010004
#define MSR_K7_PERFCTR1 0xc0010005
#define MSR_K7_PERFCTR2 0xc0010006
#define MSR_K7_PERFCTR3 0xc0010007
#define MSR_P6_PERFCTR0 0xc1
#define MSR_P6_PERFCTR1 0xc2
#define MSR_P6_EVNTSEL0 0x186
#define MSR_P6_EVNTSEL1 0x187
#define MSR_K7_CLK_CTL 0xc001001b
#define HV_X64_MSR_GUEST_OS_ID 0x40000000
#define HV_X64_MSR_SINT15 0x4000009f
#define MSR_IA32_BBL_CR_CTL3 0x1c9
#define MSR_AMD64_OSVW_ID_LENGTH 0xc0010140
#define MSR_AMD64_OSVW_STATUS 0xc0010141
#define DEBUGCTLMSR_LBR (1 << 0)
#define DEBUGCTLMSR_BTF (1 << 1)
#define KVM_STEAL_RESERVED_MASK 0xfffffffffff00000
#define KVM_STEAL_VALID_BITS 0x00000000ffffffff
#define KVM_MSR_ENABLED 1
#define KVM_MAX_MCE_BANKS 32
#define PAGE_MASK (~(4096UL - 1))
#define PAGE_SHIFT 12
#define KVM_REQ_CLOCK_UPDATE 8
#define KVM_REQ_STEAL_UPDATE 9

#define unlikely(x) (x)

struct task_struct {
    struct {
        u64 run_delay;
    } sched_info;
};

extern struct task_struct *current;

static inline void preempt_disable(void) {}
static inline void preempt_enable(void) {}

struct mutex {
    // placeholder structure
};

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}

struct kvm_vcpu {
    struct {
        u64 ia32_tsc_adjust_msr;
        u64 ia32_misc_enable_msr;
        u64 time;
        u64 time_offset;
        struct page *time_page;
        struct {
            u64 msr_val;
            u64 last_steal;
            void *stime;
        } st;
        struct {
            u64 length;
            u64 status;
        } osvw;
    } arch;
    struct kvm *kvm;
};

struct msr_data {
    u32 index;
    u64 data;
    bool host_initiated;
};

struct pvclock_vcpu_time_info {
    // placeholder structure
};

struct kvm {
    struct {
        u64 wall_clock;
        struct {
            u64 msr;
        } xen_hvm_config;
    } arch;
    struct mutex lock;
};

struct kvm_x86_ops {
    void (*adjust_tsc_offset)(struct kvm_vcpu *vcpu, u64 adj, bool write);
};

struct page;

extern int set_efer(struct kvm_vcpu *vcpu, u64 data);
extern int set_msr_mtrr(struct kvm_vcpu *vcpu, u32 msr, u64 data);
extern void kvm_set_apic_base(struct kvm_vcpu *vcpu, u64 data);
extern int kvm_x2apic_msr_write(struct kvm_vcpu *vcpu, u32 msr, u64 data);
extern void kvm_set_lapic_tscdeadline_msr(struct kvm_vcpu *vcpu, u64 data);
extern bool guest_cpuid_has_tsc_adjust(struct kvm_vcpu *vcpu);
extern void kvm_write_wall_clock(struct kvm *kvm, u64 data);
extern void kvmclock_reset(struct kvm_vcpu *vcpu);
extern int kvm_pv_enable_async_pf(struct kvm_vcpu *vcpu, u64 data);
extern int kvm_gfn_to_hva_cache_init(struct kvm *kvm, void *cache, u64 gpa);
extern int kvm_lapic_enable_pv_eoi(struct kvm_vcpu *vcpu, u64 data);
extern int set_msr_mce(struct kvm_vcpu *vcpu, u32 msr, u64 data);
extern bool kvm_pmu_msr(struct kvm_vcpu *vcpu, u32 msr);
extern int kvm_pmu_set_msr(struct kvm_vcpu *vcpu, u32 msr, u64 data);
extern bool guest_cpuid_has_osvw(struct kvm_vcpu *vcpu);
extern int xen_hvm_config(struct kvm_vcpu *vcpu, u64 data);
extern int set_msr_hyperv_pw(struct kvm_vcpu *vcpu, u32 msr, u64 data);
extern int set_msr_hyperv(struct kvm_vcpu *vcpu, u32 msr, u64 data);
extern bool kvm_hv_msr_partition_wide(u32 msr);
extern void vcpu_unimpl(struct kvm_vcpu *vcpu, const char *fmt, ...);
extern void kvm_make_request(int req, struct kvm_vcpu *vcpu);
extern void accumulate_steal_time(struct kvm_vcpu *vcpu);
extern struct page *gfn_to_page(struct kvm *kvm, gfn_t gfn);
extern bool is_error_page(struct page *page);

extern struct kvm_x86_ops *kvm_x86_ops;
extern bool ignore_msrs;
extern bool sched_info_on();