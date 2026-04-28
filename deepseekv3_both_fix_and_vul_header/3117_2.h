#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sched.h>

struct kvm_vcpu {
    struct {
        int target;
        int pause;
        int last_pcpu;
    } arch;
    struct kvm_run *run;
    sigset_t sigset;
    int sigset_active;
    int mode;
    struct kvm *kvm;
};

struct kvm_run {
    int exit_reason;
};

struct kvm {
    // Placeholder for kvm structure
};

#define IN_GUEST_MODE 1
#define OUTSIDE_GUEST_MODE 0
#define KVM_EXIT_MMIO 2
#define KVM_EXIT_UNKNOWN 0
#define KVM_EXIT_INTR 1
#define unlikely(x) (x)
#define ENOEXEC 8
#define EINTR 4

extern int kvm_vcpu_first_run_init(struct kvm_vcpu *vcpu);
extern int kvm_handle_mmio_return(struct kvm_vcpu *vcpu, struct kvm_run *run);
extern void update_vttbr(struct kvm *kvm);
extern void vcpu_pause(struct kvm_vcpu *vcpu);
extern void kvm_vgic_flush_hwstate(struct kvm_vcpu *vcpu);
extern void kvm_timer_flush_hwstate(struct kvm_vcpu *vcpu);
extern int need_new_vmid_gen(struct kvm *kvm);
extern void kvm_timer_sync_hwstate(struct kvm_vcpu *vcpu);
extern void kvm_vgic_sync_hwstate(struct kvm_vcpu *vcpu);
extern int kvm_call_hyp(void *hyp_fn, struct kvm_vcpu *vcpu);
extern int handle_exit(struct kvm_vcpu *vcpu, struct kvm_run *run, int ret);
extern void kvm_guest_enter(void);
extern void kvm_guest_exit(void);
extern void trace_kvm_entry(unsigned long pc);
extern void trace_kvm_exit(unsigned long pc);
extern unsigned long *vcpu_pc(struct kvm_vcpu *vcpu);

static inline void local_irq_disable(void) {}
static inline void local_irq_enable(void) {}
static inline int signal_pending(pid_t pid) { return 0; }
static inline void cond_resched(void) {}

pid_t current;
int __kvm_vcpu_run;
static inline int smp_processor_id(void) { return 0; }