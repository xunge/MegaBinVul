#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>

struct kvm_run {
    int exit_reason;
};

struct srcu_struct {
    int dummy;
};

struct kvm;
struct kvm_vcpu;

enum kvm_mp_state {
    KVM_MP_STATE_RUNNABLE,
    KVM_MP_STATE_HALTED,
    KVM_MP_STATE_INIT_RECEIVED
};

#define KVM_REQ_UNHALT           0
#define KVM_REQ_PENDING_TIMER    1
#define KVM_EXIT_INTR            2
#define EINTR                    4

struct kvm_vcpu_stat {
    int request_irq_exits;
    int signal_exits;
};

struct kvm_vcpu_arch {
    enum kvm_mp_state mp_state;
    struct {
        bool halted;
    } apf;
    struct {
        bool pv_unhalted;
    } pv;
};

struct kvm_vcpu {
    struct kvm *kvm;
    int srcu_idx;
    struct kvm_vcpu_arch arch;
    struct kvm_run *run;
    struct kvm_vcpu_stat stat;
    unsigned long requests;
};

struct kvm {
    struct srcu_struct srcu;
};

extern int srcu_read_lock(struct srcu_struct *sp);
extern void srcu_read_unlock(struct srcu_struct *sp, int idx);
extern int vapic_enter(struct kvm_vcpu *vcpu);
extern int vcpu_enter_guest(struct kvm_vcpu *vcpu);
extern void kvm_vcpu_block(struct kvm_vcpu *vcpu);
extern int kvm_check_request(int req, struct kvm_vcpu *vcpu);
extern void kvm_apic_accept_events(struct kvm_vcpu *vcpu);
extern void clear_bit(int nr, volatile unsigned long *addr);
extern int kvm_cpu_has_pending_timer(struct kvm_vcpu *vcpu);
extern void kvm_inject_pending_timer_irqs(struct kvm_vcpu *vcpu);
extern int dm_request_for_irq_injection(struct kvm_vcpu *vcpu);
extern void kvm_check_async_pf_completion(struct kvm_vcpu *vcpu);
extern void kvm_resched(struct kvm_vcpu *vcpu);
extern void vapic_exit(struct kvm_vcpu *vcpu);
extern int signal_pending(pid_t pid);
extern int need_resched(void);

static pid_t current;