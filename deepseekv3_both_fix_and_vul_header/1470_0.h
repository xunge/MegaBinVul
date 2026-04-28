#include <stdbool.h>

struct kvm_vcpu {
    struct {
        bool l1tf_flush_l1d;
        bool at_instruction_boundary;
    } arch;
    struct {
        int request_irq_exits;
    } stat;
    struct {
        int exit_reason;
    } *run;
};

#define KVM_REQ_UNBLOCK 0
#define KVM_EXIT_IRQ_WINDOW_OPEN 0

int kvm_vcpu_running(struct kvm_vcpu *vcpu);
int vcpu_enter_guest(struct kvm_vcpu *vcpu);
int vcpu_block(struct kvm_vcpu *vcpu);
void kvm_clear_request(int req, struct kvm_vcpu *vcpu);
bool kvm_xen_has_pending_events(struct kvm_vcpu *vcpu);
void kvm_xen_inject_pending_events(struct kvm_vcpu *vcpu);
bool kvm_cpu_has_pending_timer(struct kvm_vcpu *vcpu);
void kvm_inject_pending_timer_irqs(struct kvm_vcpu *vcpu);
bool dm_request_for_irq_injection(struct kvm_vcpu *vcpu);
bool kvm_vcpu_ready_for_interrupt_injection(struct kvm_vcpu *vcpu);
bool __xfer_to_guest_mode_work_pending(void);
void kvm_vcpu_srcu_read_unlock(struct kvm_vcpu *vcpu);
int xfer_to_guest_mode_handle_work(struct kvm_vcpu *vcpu);
void kvm_vcpu_srcu_read_lock(struct kvm_vcpu *vcpu);