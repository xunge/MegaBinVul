#include <stdbool.h>

struct kvm_vcpu;
struct kvm_pit;

struct hrtimer {
    // Minimal stub definition
    int dummy;
};

struct mutex {
    // Minimal stub definition
    int dummy;
};

struct kvm_pit {
    struct {
        struct hrtimer timer;
        struct mutex lock;
    } pit_state;
};

struct kvm_vcpu {
    struct {
        struct kvm_pit *vpit;
    } arch;
    struct kvm *kvm;
};

struct kvm {
    struct {
        struct kvm_pit *vpit;
    } arch;
};

#define HRTIMER_MODE_ABS 0

bool kvm_vcpu_is_bsp(struct kvm_vcpu *vcpu);
void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
bool hrtimer_cancel(struct hrtimer *timer);
void hrtimer_start_expires(struct hrtimer *timer, int mode);