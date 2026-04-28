#include <stddef.h>

struct kvm {
    int srcu;
};

struct kvm_memslots;
struct kvm_memory_slot {
    unsigned long base_gfn;
    unsigned long npages;
};

#define kvm_memslots(kvm) ((struct kvm_memslots *)NULL)
#define kvm_for_each_memslot(memslot, slots) for ((memslot) = NULL; (memslot) != NULL; (memslot) = NULL)
#define srcu_read_lock(ptr) (0)
#define srcu_read_unlock(ptr, idx) ((void)0)

static void kvm_iommu_put_pages(struct kvm *kvm, unsigned long base_gfn, unsigned long npages) {}