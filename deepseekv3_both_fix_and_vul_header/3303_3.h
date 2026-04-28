#include <stdint.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t u32;

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))
#define PTR_ERR(x) ((int)(uintptr_t)(x))
#define BUG_ON(x) if (x) {}
#define KVM_MAX_VCPUS 256
#define EINVAL 22
#define EEXIST 17

struct mutex {
    int dummy;
};
#define mutex_lock(x) {}
#define mutex_unlock(x) {}

struct preempt_notifier {
    int dummy;
};
struct kvm_preempt_ops {
    int dummy;
};
#define preempt_notifier_init(x, y) {}

#define smp_wmb() __atomic_thread_fence(__ATOMIC_RELEASE)
#define atomic_read(v) atomic_load(v)
#define atomic_inc(v) atomic_fetch_add(v, 1)

struct kvm_vcpu {
    int vcpu_id;
    struct preempt_notifier preempt_notifier;
};
struct kvm {
    struct mutex lock;
    _Atomic int online_vcpus;
    struct kvm_vcpu* vcpus[KVM_MAX_VCPUS];
};

#define kvm_for_each_vcpu(r, v, kvm) for (r = 0, v = NULL; r < 0; r++)

static struct kvm_vcpu* kvm_arch_vcpu_create(struct kvm* kvm, u32 id) { return NULL; }
static int kvm_arch_vcpu_setup(struct kvm_vcpu* vcpu) { return 0; }
static bool kvm_vcpu_compatible(struct kvm_vcpu* vcpu) { return true; }
static void kvm_get_kvm(struct kvm* kvm) {}
static void kvm_put_kvm(struct kvm* kvm) {}
static int create_vcpu_fd(struct kvm_vcpu* vcpu) { return 0; }
static void kvm_arch_vcpu_postcreate(struct kvm_vcpu* vcpu) {}
static void kvm_arch_vcpu_destroy(struct kvm_vcpu* vcpu) {}