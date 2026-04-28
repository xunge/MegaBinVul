#include <stdint.h>
#include <stdatomic.h>
#include <stdbool.h>

#define KVM_MAX_VCPUS 256
#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))
#define PTR_ERR(x) ((int)(uintptr_t)(x))
#define BUG_ON(cond) ((void)0)
#define smp_wmb() __atomic_thread_fence(__ATOMIC_RELEASE)
#define EINVAL 22
#define EEXIST 17

typedef uint32_t u32;

struct mutex {
    bool locked;
};
void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);

struct kvm {
    struct mutex lock;
    _Atomic int online_vcpus;
    struct kvm_vcpu *vcpus[KVM_MAX_VCPUS];
};

struct preempt_notifier {
    int dummy;
};
struct kvm_preempt_ops {
    int dummy;
};
static struct kvm_preempt_ops kvm_preempt_ops;
struct kvm_vcpu {
    u32 vcpu_id;
    struct preempt_notifier preempt_notifier;
};

static inline int atomic_read(_Atomic int *v) { return atomic_load(v); }
static inline void atomic_inc(_Atomic int *v) { atomic_fetch_add(v, 1); }

void preempt_notifier_init(struct preempt_notifier *pn, struct kvm_preempt_ops *ops);
struct kvm_vcpu *kvm_arch_vcpu_create(struct kvm *kvm, u32 id);
void kvm_arch_vcpu_destroy(struct kvm_vcpu *vcpu);
int kvm_arch_vcpu_setup(struct kvm_vcpu *vcpu);
void kvm_get_kvm(struct kvm *kvm);
void kvm_put_kvm(struct kvm *kvm);
int create_vcpu_fd(struct kvm_vcpu *vcpu);

#define kvm_for_each_vcpu(r, v, kvm) \
    for ((r) = 0, (v) = (kvm)->vcpus[0]; (r) < atomic_read(&(kvm)->online_vcpus); (r)++, (v) = (kvm)->vcpus[(r)])