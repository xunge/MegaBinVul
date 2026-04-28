#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint64_t u64;

#define WARN_ON_ONCE(condition) do { \
    if (condition) printf("Warning: %s\n", #condition); \
} while (0)

#define unlikely(x) (x)

#define VM_INSTRUCTION_ERROR 0x4400
#define GUEST_PHYSICAL_ADDRESS 0x2400

#define KERN_WARNING "<4>"

static inline int printk(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int ret = vprintf(fmt, args);
    va_end(args);
    return ret;
}

static inline u16 array_index_nospec(u16 index, u16 size) {
    return index < size ? index : 0;
}

typedef enum {
    EXIT_FASTPATH_NONE
} fastpath_t;

struct kvm_vcpu {
    int vcpu_id;
    struct {
        int vcpu_id;
        long long last_vmentry_cpu;
        unsigned long exit_qualification;
        bool nmi_pending;
    } arch;
    struct {
        int exit_reason;
        struct {
            unsigned long hardware_entry_failure_reason;
            long long cpu;
        } fail_entry;
        struct {
            unsigned int suberror;
            unsigned int ndata;
            unsigned long data[4];
        } internal;
    } *run;
};

typedef union vmx_exit_reason {
    struct {
        u32 basic : 16;
        u32 reserved16 : 1;
        u32 reserved17 : 1;
        u32 reserved18 : 1;
        u32 reserved19 : 1;
        u32 reserved20 : 1;
        u32 reserved21 : 1;
        u32 reserved22 : 1;
        u32 reserved23 : 1;
        u32 reserved24 : 1;
        u32 reserved25 : 1;
        u32 failed_vmentry : 1;
    };
    u32 full;
} vmx_exit_reason;

struct vcpu_vmx {
    vmx_exit_reason exit_reason;
    u32 idt_vectoring_info;
    bool emulation_required;
    bool fail;
    struct {
        bool nested_run_pending;
    } nested;
    struct loaded_vmcs {
        bool soft_vnmi_blocked;
        long long vnmi_blocked_time;
    } *loaded_vmcs;
};

#define VECTORING_INFO_VALID_MASK 0x80000000
#define EXIT_REASON_PML_FULL 62
#define EXIT_REASON_EXCEPTION_NMI 0
#define EXIT_REASON_EPT_VIOLATION 48
#define EXIT_REASON_APIC_ACCESS 44
#define EXIT_REASON_TASK_SWITCH 43
#define EXIT_REASON_EPT_MISCONFIG 49
#define EXIT_REASON_MSR_WRITE 42
#define EXIT_REASON_PREEMPTION_TIMER 52
#define EXIT_REASON_INTERRUPT_WINDOW 7
#define EXIT_REASON_EXTERNAL_INTERRUPT 1
#define EXIT_REASON_HLT 12
#define KVM_EXIT_FAIL_ENTRY 2
#define KVM_EXIT_INTERNAL_ERROR 3
#define KVM_INTERNAL_ERROR_DELIVERY_EV 1
#define KVM_INTERNAL_ERROR_UNEXPECTED_EXIT_REASON 2

extern bool enable_pml;
extern bool enable_vnmi;
extern unsigned int kvm_vmx_max_exit_handlers;
extern int (*kvm_vmx_exit_handlers[])(struct kvm_vcpu *vcpu);

static inline struct vcpu_vmx *to_vmx(struct kvm_vcpu *vcpu) { return (struct vcpu_vmx *)0; }
static inline bool is_guest_mode(struct kvm_vcpu *vcpu) { return false; }
static inline void vmx_flush_pml_buffer(struct kvm_vcpu *vcpu) {}
static inline int handle_invalid_guest_state(struct kvm_vcpu *vcpu) { return 0; }
static inline void nested_mark_vmcs12_pages_dirty(struct kvm_vcpu *vcpu) {}
static inline bool nested_vmx_reflect_vmexit(struct kvm_vcpu *vcpu) { return false; }
static inline void dump_vmcs(void) {}
static inline u32 vmcs_read32(u32 field) { return 0; }
static inline u64 vmcs_read64(u32 field) { return 0; }
static inline bool vmx_interrupt_blocked(struct kvm_vcpu *vcpu) { return false; }
static inline int kvm_emulate_wrmsr(struct kvm_vcpu *vcpu) { return 0; }
static inline int handle_preemption_timer(struct kvm_vcpu *vcpu) { return 0; }
static inline int handle_interrupt_window(struct kvm_vcpu *vcpu) { return 0; }
static inline int handle_external_interrupt(struct kvm_vcpu *vcpu) { return 0; }
static inline int kvm_emulate_halt(struct kvm_vcpu *vcpu) { return 0; }
static inline int handle_ept_misconfig(struct kvm_vcpu *vcpu) { return 0; }
static inline void vcpu_unimpl(struct kvm_vcpu *vcpu, const char *fmt, ...) {}