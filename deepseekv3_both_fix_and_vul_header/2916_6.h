#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef uint8_t u8;

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE - 1))
#define KVM_MAX_MCE_BANKS 32
#define KVM_STEAL_RESERVED_MASK (~((1ULL << 32) - 1))
#define KVM_STEAL_VALID_BITS ((1ULL << 32) - 1)
#define KVM_MSR_ENABLED 1
#define DEBUGCTLMSR_LBR (1ULL << 0)
#define DEBUGCTLMSR_BTF (1ULL << 1)
#define APIC_BASE_MSR 0x800
#define KVM_REQ_CLOCK_UPDATE 8
#define KVM_REQ_STEAL_UPDATE 9
#define MSR_IA32_MC0_CTL 0x400

enum {
    MSR_AMD64_NB_CFG = 0xC001001F,
    MSR_IA32_UCODE_REV = 0x8B,
    MSR_IA32_UCODE_WRITE = 0x79,
    MSR_VM_HSAVE_PA = 0xC0010117,
    MSR_AMD64_PATCH_LOADER = 0xC0010020,
    MSR_AMD64_BU_CFG2 = 0xC001102A,
    MSR_EFER = 0xC0000080,
    MSR_K7_HWCR = 0xC0010015,
    MSR_FAM10H_MMIO_CONF_BASE = 0xC0010058,
    MSR_IA32_DEBUGCTLMSR = 0x1D9,
    MSR_IA32_APICBASE = 0x1B,
    MSR_IA32_TSCDEADLINE = 0x6E0,
    MSR_IA32_TSC_ADJUST = 0x3B,
    MSR_IA32_MISC_ENABLE = 0x1A0,
    MSR_KVM_WALL_CLOCK_NEW = 0x4b564d00,
    MSR_KVM_WALL_CLOCK = 0x11,
    MSR_KVM_SYSTEM_TIME_NEW = 0x4b564d01,
    MSR_KVM_SYSTEM_TIME = 0x12,
    MSR_KVM_ASYNC_PF_EN = 0x4b564d02,
    MSR_KVM_STEAL_TIME = 0x4b564d03,
    MSR_KVM_PV_EOI_EN = 0x4b564d04,
    MSR_IA32_MCG_CTL = 0x17B,
    MSR_IA32_MCG_STATUS = 0x17A,
    MSR_K7_EVNTSEL0 = 0xC0010000,
    MSR_K7_EVNTSEL1 = 0xC0010001,
    MSR_K7_EVNTSEL2 = 0xC0010002,
    MSR_K7_EVNTSEL3 = 0xC0010003,
    MSR_K7_PERFCTR0 = 0xC0010004,
    MSR_K7_PERFCTR1 = 0xC0010005,
    MSR_K7_PERFCTR2 = 0xC0010006,
    MSR_K7_PERFCTR3 = 0xC0010007,
    MSR_P6_PERFCTR0 = 0xC1,
    MSR_P6_PERFCTR1 = 0xC2,
    MSR_P6_EVNTSEL0 = 0x186,
    MSR_P6_EVNTSEL1 = 0x187,
    MSR_K7_CLK_CTL = 0xC001001B,
    HV_X64_MSR_GUEST_OS_ID = 0x40000000,
    HV_X64_MSR_SINT15 = 0x4000002F,
    MSR_IA32_BBL_CR_CTL3 = 0x1E6,
    MSR_AMD64_OSVW_ID_LENGTH = 0xC0010140,
    MSR_AMD64_OSVW_STATUS = 0xC0010141
};

struct kvm_vcpu {
    struct {
        u64 ia32_tsc_adjust_msr;
        u64 ia32_misc_enable_msr;
        u64 time;
        u64 time_offset;
        void *time_page;
        bool pv_time_enabled;
        struct {
            void *stime;
            u64 msr_val;
            u64 last_steal;
        } st;
        struct {
            u64 length;
            u64 status;
        } osvw;
        void *pv_time;
    } arch;
    struct kvm *kvm;
};

struct kvm {
    struct {
        u64 wall_clock;
        struct {
            u64 msr;
        } xen_hvm_config;
    } arch;
    void *lock;
};

struct msr_data {
    u32 index;
    u64 data;
    bool host_initiated;
};

struct pvclock_vcpu_time_info {
    u32 version;
    u32 pad0;
    u64 tsc_timestamp;
    u64 system_time;
    u32 tsc_to_system_mul;
    s8 tsc_shift;
    u8 flags;
    u8 pad[2];
};

struct kvm_x86_ops {
    int (*adjust_tsc_offset)(struct kvm_vcpu *vcpu, u64 adj, bool host);
};

struct task_struct {
    struct {
        u64 run_delay;
    } sched_info;
};

extern struct kvm_x86_ops *kvm_x86_ops;
extern bool ignore_msrs;
extern struct task_struct *current;

int set_efer(struct kvm_vcpu *vcpu, u64 data);
int set_msr_mtrr(struct kvm_vcpu *vcpu, u32 msr, u64 data);
int kvm_x2apic_msr_write(struct kvm_vcpu *vcpu, u32 msr, u64 data);
void kvm_set_apic_base(struct kvm_vcpu *vcpu, u64 data);
void kvm_set_lapic_tscdeadline_msr(struct kvm_vcpu *vcpu, u64 data);
bool guest_cpuid_has_tsc_adjust(struct kvm_vcpu *vcpu);
void kvm_write_wall_clock(struct kvm *kvm, u64 data);
void kvmclock_reset(struct kvm_vcpu *vcpu);
void vcpu_unimpl(struct kvm_vcpu *vcpu, const char *fmt, ...);
void kvm_make_request(int req, struct kvm_vcpu *vcpu);
bool sched_info_on(void);
int kvm_pv_enable_async_pf(struct kvm_vcpu *vcpu, u64 data);
int kvm_gfn_to_hva_cache_init(struct kvm *kvm, void *cache, u64 gpa);
void preempt_disable(void);
void preempt_enable(void);
void accumulate_steal_time(struct kvm_vcpu *vcpu);
void *gfn_to_page(struct kvm *kvm, u64 gfn);
bool is_error_page(void *page);
bool kvm_pmu_msr(struct kvm_vcpu *vcpu, u32 msr);
int kvm_pmu_set_msr(struct kvm_vcpu *vcpu, u32 msr, u64 data);
int xen_hvm_config(struct kvm_vcpu *vcpu, u64 data);
bool guest_cpuid_has_osvw(struct kvm_vcpu *vcpu);
bool kvm_hv_msr_partition_wide(u32 msr);
int set_msr_hyperv_pw(struct kvm_vcpu *vcpu, u32 msr, u64 data);
int set_msr_hyperv(struct kvm_vcpu *vcpu, u32 msr, u64 data);
int set_msr_mce(struct kvm_vcpu *vcpu, u32 msr, u64 data);
int kvm_lapic_enable_pv_eoi(struct kvm_vcpu *vcpu, u64 data);
void mutex_lock(void *lock);
void mutex_unlock(void *lock);
#define unlikely(x) (x)