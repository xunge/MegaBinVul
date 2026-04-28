#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define HV_X64_MSR_SCONTROL 0x00000001
#define HV_X64_MSR_SVERSION 0x00000002
#define HV_X64_MSR_SIEFP 0x00000003
#define HV_X64_MSR_SIMP 0x00000004
#define HV_X64_MSR_EOM 0x00000005
#define HV_X64_MSR_SINT0 0x00000006
#define HV_X64_MSR_SINT15 0x00000015

#define HV_SYNIC_SIEFP_ENABLE (1ULL << 0)
#define HV_SYNIC_SIMP_ENABLE (1ULL << 0)
#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))

typedef uint32_t u32;
typedef uint64_t u64;

struct kvm_vcpu_hv_synic {
    bool active;
    bool dont_zero_synic_pages;
    u64 control;
    u64 version;
    u64 evt_page;
    u64 msg_page;
    u64 sint[16];
};

struct kvm_vcpu {
    int vcpu_id;
    struct kvm *kvm;
};

struct kvm {
    // minimal definition needed for compilation
};

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

static inline struct kvm_vcpu *hv_synic_to_vcpu(struct kvm_vcpu_hv_synic *synic) { return NULL; }
static void synic_exit(struct kvm_vcpu_hv_synic *synic, u32 msr) {}
static int synic_set_sint(struct kvm_vcpu_hv_synic *synic, int sint, u64 data, bool host) { return 0; }
static void kvm_hv_notify_acked_sint(struct kvm_vcpu *vcpu, int sint) {}
static int kvm_clear_guest(struct kvm *kvm, u64 gpa, unsigned long size) { return 0; }