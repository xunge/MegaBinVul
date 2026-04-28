#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct file {
    void *private_data;
};

struct kvm_vcpu {
    struct {
        void *apic;
        int virtual_tsc_khz;
    } arch;
    void *kvm;
};

struct kvm_lapic_state {
    char data[1024];
};

struct kvm_xsave {
    char data[4096];
};

struct kvm_xcrs {
    char data[256];
};

struct kvm_interrupt {
    int irq;
};

struct kvm_cpuid {
    int entries[32];
};

struct kvm_cpuid2 {
    int entries[32];
};

struct kvm_tpr_access_ctl {
    int enabled;
};

struct kvm_vapic_addr {
    unsigned long vapic_addr;
};

struct kvm_x86_mce {
    uint64_t mcg_cap;
};

struct kvm_vcpu_events {
    int dummy;
};

struct kvm_debugregs {
    int dummy;
};

#define GFP_KERNEL 0
#define EINVAL 1
#define ENOMEM 2
#define EFAULT 3
#define IS_ERR(x) 0
#define PTR_ERR(x) 0

#define KVM_GET_LAPIC 0
#define KVM_SET_LAPIC 1
#define KVM_INTERRUPT 2
#define KVM_NMI 3
#define KVM_SET_CPUID 4
#define KVM_SET_CPUID2 5
#define KVM_GET_CPUID2 6
#define KVM_GET_MSRS 7
#define KVM_SET_MSRS 8
#define KVM_TPR_ACCESS_REPORTING 9
#define KVM_SET_VAPIC_ADDR 10
#define KVM_X86_SETUP_MCE 11
#define KVM_X86_SET_MCE 12
#define KVM_GET_VCPU_EVENTS 13
#define KVM_SET_VCPU_EVENTS 14
#define KVM_GET_DEBUGREGS 15
#define KVM_SET_DEBUGREGS 16
#define KVM_GET_XSAVE 17
#define KVM_SET_XSAVE 18
#define KVM_GET_XCRS 19
#define KVM_SET_XCRS 20
#define KVM_SET_TSC_KHZ 21
#define KVM_GET_TSC_KHZ 22
#define KVM_KVMCLOCK_CTRL 23

typedef uint64_t u64;
typedef uint32_t u32;

#define __user

static void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static void *memdup_user(const void *src, size_t len) {
    void *dst = malloc(len);
    if (dst) memcpy(dst, src, len);
    return dst;
}

static int copy_to_user(void *dst, const void *src, size_t len) {
    memcpy(dst, src, len);
    return 0;
}

static int copy_from_user(void *dst, const void *src, size_t len) {
    memcpy(dst, src, len);
    return 0;
}

static int irqchip_in_kernel(void *kvm) { return 1; }
static int kvm_vcpu_ioctl_get_lapic(void *vcpu, void *lapic) { return 0; }
static int kvm_vcpu_ioctl_set_lapic(void *vcpu, void *lapic) { return 0; }
static int kvm_vcpu_ioctl_interrupt(void *vcpu, void *irq) { return 0; }
static int kvm_vcpu_ioctl_nmi(void *vcpu) { return 0; }
static int kvm_vcpu_ioctl_set_cpuid(void *vcpu, void *cpuid, void *entries) { return 0; }
static int kvm_vcpu_ioctl_set_cpuid2(void *vcpu, void *cpuid, void *entries) { return 0; }
static int kvm_vcpu_ioctl_get_cpuid2(void *vcpu, void *cpuid, void *entries) { return 0; }
static int msr_io(void *vcpu, void *argp, void *func, int write) { return 0; }
static int kvm_get_msr(void *vcpu, void *msr) { return 0; }
static int do_set_msr(void *vcpu, void *msr) { return 0; }
static int vcpu_ioctl_tpr_access_reporting(void *vcpu, void *tac) { return 0; }
static int kvm_lapic_set_vapic_addr(void *vcpu, unsigned long addr) { return 0; }
static int kvm_vcpu_ioctl_x86_setup_mce(void *vcpu, uint64_t mcg_cap) { return 0; }
static int kvm_vcpu_ioctl_x86_set_mce(void *vcpu, void *mce) { return 0; }
static void kvm_vcpu_ioctl_x86_get_vcpu_events(void *vcpu, void *events) {}
static int kvm_vcpu_ioctl_x86_set_vcpu_events(void *vcpu, void *events) { return 0; }
static void kvm_vcpu_ioctl_x86_get_debugregs(void *vcpu, void *dbgregs) {}
static int kvm_vcpu_ioctl_x86_set_debugregs(void *vcpu, void *dbgregs) { return 0; }
static void kvm_vcpu_ioctl_x86_get_xsave(void *vcpu, void *xsave) {}
static int kvm_vcpu_ioctl_x86_set_xsave(void *vcpu, void *xsave) { return 0; }
static void kvm_vcpu_ioctl_x86_get_xcrs(void *vcpu, void *xcrs) {}
static int kvm_vcpu_ioctl_x86_set_xcrs(void *vcpu, void *xcrs) { return 0; }
static void kvm_set_tsc_khz(void *vcpu, uint32_t khz) {}
static int kvm_set_guest_paused(void *vcpu) { return 0; }

static unsigned int kvm_max_guest_tsc_khz = 0;
static unsigned int tsc_khz = 0;

#define kfree free