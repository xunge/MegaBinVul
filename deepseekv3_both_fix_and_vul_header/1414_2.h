#include <stdlib.h>
#include <stddef.h>

struct pid;

struct kvm_dirty_ring {
    // Minimal dummy definition to make it a complete type
    int dummy;  
};

struct kvm_vcpu {
    struct kvm_dirty_ring dirty_ring;
    struct pid *pid;
    void *run;
};

extern void kvm_dirty_ring_free(struct kvm_dirty_ring *ring);
extern void kvm_arch_vcpu_destroy(struct kvm_vcpu *vcpu);
extern void put_pid(struct pid *pid);
extern void *rcu_dereference_protected(void *p, int lock);
extern void free_page(unsigned long page);
extern void kmem_cache_free(void *cache, void *obj);
extern void *kvm_vcpu_cache;