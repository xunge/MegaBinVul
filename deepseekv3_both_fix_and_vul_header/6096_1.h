#include <stdbool.h>
#include <stdint.h>
#include <linux/types.h>

#define SVM_EXIT_ERR 0xffff
#define UD_VECTOR 6
#define INTERCEPT_CR 0
#define INTERCEPT_EXCEPTION 1
#define INTERCEPT_WORD3 2
#define INTERCEPT_WORD4 3
#define INTERCEPT_WORD5 4
#define EINVAL 22

typedef uint64_t u64;

struct vmcb_control {
    uint64_t exit_code;
    uint64_t exit_code_hi;
    uint64_t exit_info_1;
    uint64_t exit_info_2;
    uint64_t int_ctl;
    uint64_t event_inj;
    uint64_t nested_ctl;
    uint64_t intercepts[5];
};

struct vmcb_save {
    uint64_t rax;
    uint64_t rip;
    uint64_t rsp;
    uint64_t cr0;
    uint64_t cr3;
    uint64_t cr4;
    uint64_t efer;
    uint64_t rflags;
    uint64_t es;
    uint64_t cs;
    uint64_t ss;
    uint64_t ds;
    uint64_t gdtr;
    uint64_t idtr;
};

struct vmcb {
    struct vmcb_save save;
    struct vmcb_control control;
};

struct kvm_vcpu {
    struct {
        uint64_t efer;
        uint64_t cr4;
    } arch;
};

struct kvm_host_map {
    void *hva;
};

struct nested_ctl {
    uint64_t intercepts[5];
};

struct nested_state {
    struct vmcb *hsave;
    bool initialized;
    bool nested_run_pending;
    struct nested_ctl ctl;
};

struct vcpu_svm {
    struct kvm_vcpu vcpu;
    struct vmcb *vmcb;
    struct {
        struct nested_state nested;
    };
};

extern bool npt_enabled;
extern int kvm_vcpu_map(struct kvm_vcpu *vcpu, uint64_t gfn, struct kvm_host_map *map);
extern void kvm_vcpu_unmap(struct kvm_vcpu *vcpu, struct kvm_host_map *map, bool dirty);
extern void kvm_queue_exception(struct kvm_vcpu *vcpu, int vector);
extern void kvm_inject_gp(struct kvm_vcpu *vcpu, int error_code);
extern int kvm_skip_emulated_instruction(struct kvm_vcpu *vcpu);
extern uint64_t kvm_read_cr0(struct kvm_vcpu *vcpu);
extern uint64_t kvm_read_cr3(struct kvm_vcpu *vcpu);
extern uint64_t kvm_get_rflags(struct kvm_vcpu *vcpu);
extern uint64_t kvm_rip_read(struct kvm_vcpu *vcpu);
extern void kvm_clear_exception_queue(struct kvm_vcpu *vcpu);
extern void kvm_clear_interrupt_queue(struct kvm_vcpu *vcpu);
extern void load_nested_vmcb_control(struct vcpu_svm *svm, struct vmcb_control *control);
extern bool nested_vmcb_check_save(struct vcpu_svm *svm, struct vmcb *vmcb);
extern bool nested_vmcb_check_controls(struct nested_ctl *nested);
extern bool nested_vmcb_checks(struct vcpu_svm *svm, struct vmcb *vmcb);
extern void copy_vmcb_control_area(struct vmcb_control *dst, struct vmcb_control *src);
extern bool enter_svm_guest_mode(struct vcpu_svm *svm, uint64_t vmcb12_gpa, struct vmcb *vmcb12);
extern bool nested_svm_vmrun_msrpm(struct vcpu_svm *svm);
extern void nested_svm_vmexit(struct vcpu_svm *svm);
extern bool is_smm(struct kvm_vcpu *vcpu);
extern uint64_t gpa_to_gfn(uint64_t gpa);
extern void trace_kvm_nested_vmrun(uint64_t rip, uint64_t vmcb12_gpa, uint64_t vmcb12_rip, uint64_t int_ctl, uint64_t event_inj, uint64_t nested_ctl);
extern void trace_kvm_nested_intercepts(uint64_t cr0, uint64_t cr1, uint64_t exception, uint64_t word3, uint64_t word4, uint64_t word5);
extern int WARN_ON_ONCE(int condition);