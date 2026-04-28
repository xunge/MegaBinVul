#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int dummy;
};

struct mm_struct {
    int dummy;
};

struct kvm_io_bus {
    int dummy;
};

struct kvm_chardev_ops {
    void *owner;
};

struct kvm {
    struct mm_struct *mm;
    struct list_head vm_list;
    struct kvm_io_bus *buses[1];
    void *mmu_notifier;
    void *mn_memslots_update_rcuwait;
    int mn_active_invalidate_count;
    void *__memslots[1][2];
    void *irq_srcu;
    void *srcu;
};

struct mutex kvm_lock;
struct list_head vm_list;
struct kvm_chardev_ops kvm_chardev_ops;

#define KVM_NR_BUSES 1
#define KVM_ADDRESS_SPACE_NUM 1
#define KVM_EVENT_DESTROY_VM 0
#define CONFIG_MMU_NOTIFIER
#define KVM_ARCH_WANT_MMU_NOTIFIER

void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void list_del(struct list_head *entry);
void WARN_ON(int condition);
void kvm_destroy_pm_notifier(struct kvm *kvm);
void kvm_uevent_notify_change(int event, struct kvm *kvm);
void kvm_destroy_vm_debugfs(struct kvm *kvm);
void kvm_arch_sync_events(struct kvm *kvm);
void kvm_arch_pre_destroy_vm(struct kvm *kvm);
void kvm_free_irq_routing(struct kvm *kvm);
struct kvm_io_bus *kvm_get_bus(struct kvm *kvm, int i);
void kvm_io_bus_destroy(struct kvm_io_bus *bus);
void kvm_coalesced_mmio_free(struct kvm *kvm);
void mmu_notifier_unregister(void *notifier, struct mm_struct *mm);
int rcuwait_active(void *rcuwait);
void kvm_arch_flush_shadow_all(struct kvm *kvm);
void kvm_arch_destroy_vm(struct kvm *kvm);
void kvm_destroy_devices(struct kvm *kvm);
void kvm_free_memslots(struct kvm *kvm, void *slots);
void cleanup_srcu_struct(void *srcu);
void kvm_arch_free_vm(struct kvm *kvm);
void preempt_notifier_dec(void);
void hardware_disable_all(void);
void mmdrop(struct mm_struct *mm);
void module_put(void *module);